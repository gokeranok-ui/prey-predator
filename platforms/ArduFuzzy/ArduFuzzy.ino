#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// For Arduino DUE Native USB Port
#if defined(ARDUINO_SAM_DUE)
#define SerialPort SerialUSB
#else
#define SerialPort Serial
#endif

extern "C" {
/* Performance: Disable printf from MATLAB-generated code */
/* This must be defined BEFORE including any MATLAB headers */
#ifndef FUZZY_DEBUG
#define FUZZY_DEBUG 0
#endif

#include "src/runtime/fuzzy_runner.h"
#include "src/runtime/fis_virtual_fs.h"
}

static FILE s_stdout_stream;
static bool s_waiting_for_second = false;
static double s_pending_first = 0.0;

/* Statistical latency (same FoMs as STM32 harness) */
#define LATENCY_WARMUP_SAMPLES   100
#define LATENCY_SAMPLE_COUNT     10000

typedef struct {
    uint32_t avg;
    uint32_t p50;
    uint32_t p95;
    uint32_t max;
    uint32_t stdev;
    uint32_t jitter;
    float ips;
} latency_stats_t;

/* Static: 40 KB — must not live on the Due stack */
static uint32_t s_latencies_us[LATENCY_SAMPLE_COUNT];

static int cmp_u32(const void *a, const void *b)
{
    uint32_t x = *static_cast<const uint32_t *>(a);
    uint32_t y = *static_cast<const uint32_t *>(b);
    return (x > y) - (x < y);
}

static latency_stats_t compute_latency_stats(uint32_t *lat_us, size_t n)
{
    latency_stats_t stats = {0};
    if (n == 0U) {
        return stats;
    }

    uint64_t sum = 0ULL;
    uint64_t sum2 = 0ULL;
    for (size_t i = 0U; i < n; ++i) {
        sum += lat_us[i];
        sum2 += static_cast<uint64_t>(lat_us[i]) * static_cast<uint64_t>(lat_us[i]);
    }
    stats.avg = static_cast<uint32_t>(sum / n);

    qsort(lat_us, n, sizeof(uint32_t), cmp_u32);
    stats.p50 = lat_us[static_cast<size_t>(0.50 * static_cast<double>(n - 1U))];
    stats.p95 = lat_us[static_cast<size_t>(0.95 * static_cast<double>(n - 1U))];
    stats.max = lat_us[n - 1U];

    double mean = static_cast<double>(sum) / static_cast<double>(n);
    double var = (static_cast<double>(sum2) / static_cast<double>(n)) - (mean * mean);
    stats.stdev = (var > 0.0) ? static_cast<uint32_t>(sqrt(var)) : 0U;
    stats.jitter = stats.p95 - stats.p50;
    stats.ips = (stats.avg > 0U) ? (1000000.0f / static_cast<float>(stats.avg)) : 0.0f;
    return stats;
}

static void dual_println(const char *msg)
{
    Serial.println(msg);
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.println(msg);
#endif
}

/* Performance: Disable printf output when FUZZY_DEBUG is 0 */
#ifndef FUZZY_DEBUG
#define FUZZY_DEBUG 0
#endif

#if defined(__AVR__)
static int serial_putchar(char c, FILE *stream)
{
    (void)stream;
#if FUZZY_DEBUG
    if (c == '\n') {
        Serial.write('\r');
    }
    Serial.write(static_cast<uint8_t>(c));
#endif
    /* When FUZZY_DEBUG=0, do nothing - this prevents MATLAB printf from slowing down execution */
    return 0;
}

static void setup_stdio_redirect(void)
{
    fdev_setup_stream(&s_stdout_stream, serial_putchar, nullptr, _FDEV_SETUP_WRITE);
    stdout = &s_stdout_stream;
    stderr = &s_stdout_stream;
}
#else
/* For ARM (DUE), create a no-op putchar function */
static int serial_putchar_arm(char c, FILE *stream)
{
    (void)stream;
#if FUZZY_DEBUG
    if (c == '\n') {
        Serial.write('\r');
    }
    Serial.write(static_cast<uint8_t>(c));
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.write(static_cast<uint8_t>(c));
#endif
#endif
    /* When FUZZY_DEBUG=0, do nothing - prevents MATLAB printf from slowing execution */
    return 0;
}

static void setup_stdio_redirect(void)
{
    /* For ARM (DUE), we cannot override _write() due to linker conflicts with syscalls_sam3.c */
    /* printf() calls from MATLAB code will go through Serial, causing I/O overhead */
    /* This is a known limitation - see ARDUINO_DUE_PRINTF_LIMITATION.md */
    s_stdout_stream = *stdout;
}
#endif

static U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

static void render_oled(const char *status, double m1, double m2, double out, bool has_result)
{
    char line1[20];
    char line2[20];
    char line3[20];

    snprintf(line1, sizeof(line1), "m1: %5.2f", m1);
    snprintf(line2, sizeof(line2), "m2: %5.2f", m2);
    if (has_result) {
        snprintf(line3, sizeof(line3), "out:%6.3f", out);
    } else {
        strncpy(line3, status, sizeof(line3) - 1U);
        line3[sizeof(line3) - 1U] = '\0';
    }

    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_6x12_tf);
    u8g2.drawStr(0, 12, "Arduino Fuzzy CLI");
    u8g2.drawStr(0, 28, line1);
    u8g2.drawStr(0, 40, line2);
    u8g2.drawStr(0, 56, line3);
    u8g2.sendBuffer();
}

static bool parse_inputs(const char *line, double *m1, double *m2)
{
    if ((line == nullptr) || (m1 == nullptr) || (m2 == nullptr)) {
        return false;
    }

    char *endptr1 = nullptr;
    double first = strtod(line, &endptr1);
    if (endptr1 == line) {
        return false;
    }
    while (*endptr1 == ' ' || *endptr1 == '\t') {
        ++endptr1;
    }
    char *endptr2 = nullptr;
    double second = strtod(endptr1, &endptr2);
    if (endptr2 == endptr1) {
        return false;
    }

    *m1 = first;
    *m2 = second;
    return true;
}

static bool parse_single_value(const char *line, double *value)
{
    if ((line == nullptr) || (value == nullptr)) {
        return false;
    }
    char *endptr = nullptr;
    double v = strtod(line, &endptr);
    if (endptr == line) {
        return false;
    }
    *value = v;
    return true;
}

static void handle_line(const char *line)
{
    double m1 = 0.0;
    double m2 = 0.0;
    if (line == nullptr || line[0] == '\0') {
        return;
    }

    if (s_waiting_for_second) {
        if (parse_single_value(line, &m2)) {
            m1 = s_pending_first;
            s_waiting_for_second = false;
        } else if (parse_inputs(line, &m1, &m2)) {
            s_waiting_for_second = false;
        } else {
            Serial.println("Still need the second number for m2. Please enter it now.");
            Serial.flush();
#if defined(ARDUINO_SAM_DUE)
            SerialUSB.println("Still need the second number for m2. Please enter it now.");
            SerialUSB.flush();
#endif
            render_oled("Need m2", s_pending_first, 0.0, 0.0, false);
            return;
        }
    } else if (!parse_inputs(line, &m1, &m2)) {
        if (parse_single_value(line, &m1)) {
            s_waiting_for_second = true;
            s_pending_first = m1;
            Serial.print("Received m1 = ");
            Serial.print(m1, 3);
            Serial.println(". Please enter the second value m2.");
            Serial.flush();
#if defined(ARDUINO_SAM_DUE)
            SerialUSB.print("Received m1 = ");
            SerialUSB.print(m1, 3);
            SerialUSB.println(". Please enter the second value m2.");
            SerialUSB.flush();
#endif
            render_oled("Need m2", m1, 0.0, 0.0, false);
            return;
        }
        Serial.println("Invalid input. Please enter two numbers, e.g. \"5 8\".");
        Serial.flush();
#if defined(ARDUINO_SAM_DUE)
        SerialUSB.println("Invalid input. Please enter two numbers, e.g. \"5 8\".");
        SerialUSB.flush();
#endif
        render_oled("Input error", 0.0, 0.0, 0.0, false);
        return;
    }

    // LED pattern: 1 blink = parsed successfully
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    
    float inputs[2];
    inputs[0] = static_cast<float>(m1);
    inputs[1] = static_cast<float>(m2);

    // Try immediate output without buffering
    char num_buf[64];
    snprintf(num_buf, sizeof(num_buf), "DEBUG: Parsed inputs: %.2f %.2f\r\n", m1, m2);
    Serial.write(num_buf);
    Serial.flush();
    
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.write(num_buf);
    SerialUSB.flush();
#endif
    
    // LED pattern: 2 blinks = about to call fuzzy runner
    blink_led(2, 100);
    
    Serial.write("DEBUG: Calling fuzzy_runner_execute...\r\n");
    Serial.flush();
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.write("DEBUG: Calling fuzzy_runner_execute...\r\n");
    SerialUSB.flush();
#endif
    
    // LED pattern: 3 blinks = calling fuzzy runner (this might hang)
    blink_led(3, 100);

    float outputs[1] = {0.0f};
    float output = 0.0f;

    dual_println("Warming up...");
    Serial.flush();
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.flush();
#endif
    for (int i = 0; i < LATENCY_WARMUP_SAMPLES; ++i) {
        output = fuzzy_runner_execute(inputs, 2U, outputs, 1U);
    }

    char msg[96];
    snprintf(msg, sizeof(msg),
             "Collecting %d samples for statistical analysis...",
             LATENCY_SAMPLE_COUNT);
    dual_println(msg);
    Serial.flush();
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.flush();
#endif

    for (int i = 0; i < LATENCY_SAMPLE_COUNT; ++i) {
        unsigned long start_us = micros();
        output = fuzzy_runner_execute(inputs, 2U, outputs, 1U);
        unsigned long end_us = micros();
        s_latencies_us[i] = static_cast<uint32_t>(end_us - start_us);

        if (((i + 1) % 1000) == 0) {
            snprintf(msg, sizeof(msg), "Progress: %d/%d samples",
                     i + 1, LATENCY_SAMPLE_COUNT);
            dual_println(msg);
            Serial.flush();
#if defined(ARDUINO_SAM_DUE)
            SerialUSB.flush();
#endif
        }
    }

    latency_stats_t stats = compute_latency_stats(s_latencies_us, LATENCY_SAMPLE_COUNT);

    // LED pattern: 4 blinks = fuzzy runner returned
    blink_led(4, 100);

    Serial.write("DEBUG: fuzzy_runner_execute returned!\r\n");
    Serial.flush();
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.write("DEBUG: fuzzy_runner_execute returned!\r\n");
    SerialUSB.flush();
#endif

    Serial.print("Inputs  : ");
    Serial.print(m1);
    Serial.print(" ");
    Serial.println(m2);
    Serial.print("Output  : ");
    Serial.println(output, 6);
    Serial.print("FIS file: ");
    Serial.println(fuzzy_runner_get_fis_name());
    Serial.println("=== Latency Statistics (10,000 samples) ===");
    Serial.print("  Average:  ");
    Serial.print(stats.avg);
    Serial.print(" us (");
    Serial.print(stats.avg / 1000.0f, 3);
    Serial.println(" ms)");
    Serial.print("  Median (p50): ");
    Serial.print(stats.p50);
    Serial.print(" us (");
    Serial.print(stats.p50 / 1000.0f, 3);
    Serial.println(" ms)");
    Serial.print("  95th percentile (p95): ");
    Serial.print(stats.p95);
    Serial.print(" us (");
    Serial.print(stats.p95 / 1000.0f, 3);
    Serial.println(" ms)");
    Serial.print("  Maximum (WCE): ");
    Serial.print(stats.max);
    Serial.print(" us (");
    Serial.print(stats.max / 1000.0f, 3);
    Serial.println(" ms)");
    Serial.print("  Standard deviation: ");
    Serial.print(stats.stdev);
    Serial.println(" us");
    Serial.print("  Jitter (p95-p50): ");
    Serial.print(stats.jitter);
    Serial.println(" us");
    Serial.print("  Throughput: ");
    Serial.print(stats.ips, 2);
    Serial.println(" inferences/sec");
    Serial.println("==========================================");
    Serial.println();
    Serial.flush();
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.print("Inputs  : ");
    SerialUSB.print(m1);
    SerialUSB.print(" ");
    SerialUSB.println(m2);
    SerialUSB.print("Output  : ");
    SerialUSB.println(output, 6);
    SerialUSB.print("FIS file: ");
    SerialUSB.println(fuzzy_runner_get_fis_name());
    SerialUSB.println("=== Latency Statistics (10,000 samples) ===");
    SerialUSB.print("  Average:  ");
    SerialUSB.print(stats.avg);
    SerialUSB.print(" us (");
    SerialUSB.print(stats.avg / 1000.0f, 3);
    SerialUSB.println(" ms)");
    SerialUSB.print("  Median (p50): ");
    SerialUSB.print(stats.p50);
    SerialUSB.print(" us (");
    SerialUSB.print(stats.p50 / 1000.0f, 3);
    SerialUSB.println(" ms)");
    SerialUSB.print("  95th percentile (p95): ");
    SerialUSB.print(stats.p95);
    SerialUSB.print(" us (");
    SerialUSB.print(stats.p95 / 1000.0f, 3);
    SerialUSB.println(" ms)");
    SerialUSB.print("  Maximum (WCE): ");
    SerialUSB.print(stats.max);
    SerialUSB.print(" us (");
    SerialUSB.print(stats.max / 1000.0f, 3);
    SerialUSB.println(" ms)");
    SerialUSB.print("  Standard deviation: ");
    SerialUSB.print(stats.stdev);
    SerialUSB.println(" us");
    SerialUSB.print("  Jitter (p95-p50): ");
    SerialUSB.print(stats.jitter);
    SerialUSB.println(" us");
    SerialUSB.print("  Throughput: ");
    SerialUSB.print(stats.ips, 2);
    SerialUSB.println(" inferences/sec");
    SerialUSB.println("==========================================");
    SerialUSB.println();
    SerialUSB.flush();
#endif
    render_oled("Result", m1, m2, output, true);
}

// LED blink pattern: quick blink = step, long blink = error
static void blink_led(int count, int duration_ms)
{
    for (int i = 0; i < count; i++) {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(duration_ms);
        digitalWrite(LED_BUILTIN, LOW);
        delay(duration_ms);
    }
}

void setup()
{
    // LED test - pin 13 on DUE
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    
    // Blink pattern: 3 quick = starting
    blink_led(3, 200);
    delay(500);
    
    // Initialize Serial - try both Serial and SerialUSB
    Serial.begin(115200);
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.begin(115200);
    // Don't wait - just start
    delay(2000); // Give USB time to enumerate
#else
    delay(250);
#endif

    // Try to send output on both ports
    Serial.println("\r\n\r\n=== Arduino Fuzzy CLI Starting ===");
    Serial.flush();
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.println("\r\n\r\n=== Arduino Fuzzy CLI Starting (USB) ===");
    SerialUSB.flush();
#endif
    delay(100);
    
    // Blink pattern: 2 quick = Serial initialized
    blink_led(2, 200);
    delay(500);
    
    setup_stdio_redirect();
    
    Serial.println("Initializing I2C and OLED...");
    Serial.flush();
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.println("Initializing I2C and OLED...");
    SerialUSB.flush();
#endif
    
    // Initialize I2C
    Wire.begin();
    
    // Scan I2C bus for devices
    Serial.println("Scanning I2C bus...");
    Serial.flush();
    byte error, address;
    int nDevices = 0;
    for(address = 1; address < 127; address++) {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();
        if (error == 0) {
            Serial.print("I2C device found at address 0x");
            if (address < 16) Serial.print("0");
            Serial.println(address, HEX);
            Serial.flush();
            nDevices++;
        }
    }
    if (nDevices == 0) {
        Serial.println("No I2C devices found! Check connections:");
        Serial.println("  - SDA to pin 20 (DUE) or SDA pin");
        Serial.println("  - SCL to pin 21 (DUE) or SCL pin");
        Serial.println("  - VCC to 3.3V (DUE uses 3.3V, not 5V!)");
        Serial.println("  - GND to GND");
        Serial.flush();
    } else {
        Serial.print("Found ");
        Serial.print(nDevices);
        Serial.println(" I2C device(s)");
        Serial.flush();
    }
    
    // Try to initialize OLED
    Serial.println("Initializing OLED...");
    Serial.flush();
    u8g2.begin();
    
    // Test OLED display
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_6x12_tf);
    u8g2.drawStr(0, 12, "OLED Test");
    u8g2.drawStr(0, 28, "If you see this,");
    u8g2.drawStr(0, 40, "OLED is working!");
    u8g2.sendBuffer();
    delay(1000); // Show test message for 1 second
    
    render_oled("Loading...", 0.0, 0.0, 0.0, false);

    // Blink pattern: 1 quick = I2C/OLED done
    blink_led(1, 200);
    delay(500);

    Serial.println("Loading FIS file...");
    Serial.flush();
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.println("Loading FIS file...");
    SerialUSB.flush();
#endif
    delay(100);
    
    Serial.println("Step 1: Initializing FIS virtual FS...");
    Serial.flush();
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.println("Step 1: Initializing FIS virtual FS...");
    SerialUSB.flush();
#endif
    fis_virtual_fs_init();
    delay(100);
    
    // Blink pattern: 4 quick = FIS init done
    blink_led(4, 150);
    delay(500);
    
    Serial.println("Step 2: Loading embedded blob...");
    Serial.flush();
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.println("Step 2: Loading embedded blob...");
    SerialUSB.flush();
#endif
    delay(100);
    
    int load_result = fis_virtual_fs_load_file("tipper.fis");
    
    Serial.print("Step 3: Load result = ");
    Serial.println(load_result);
    Serial.flush();
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.print("Step 3: Load result = ");
    SerialUSB.println(load_result);
    SerialUSB.flush();
#endif
    delay(100);
    
    if (!load_result) {
        render_oled("FIS load err", 0.0, 0.0, 0.0, false);
        Serial.println("ERROR: Failed to load embedded tipper.fis");
        Serial.flush();
#if defined(ARDUINO_SAM_DUE)
        SerialUSB.println("ERROR: Failed to load embedded tipper.fis");
        SerialUSB.flush();
#endif
        // Error pattern: long blinks
        while (true) {
            blink_led(1, 1000);
            delay(1000);
        }
    }

    // Blink pattern: 5 quick = FIS loaded
    blink_led(5, 150);
    delay(500);

    Serial.println("Step 4: FIS loaded successfully!");
    Serial.flush();
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.println("Step 4: FIS loaded successfully!");
    SerialUSB.flush();
#endif
    delay(100);
    
    Serial.println("Step 5: Initializing fuzzy runner...");
    Serial.flush();
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.println("Step 5: Initializing fuzzy runner...");
    SerialUSB.flush();
#endif
    delay(100);
    
    fuzzy_runner_init();

    // Blink pattern: 6 quick = fuzzy runner ready
    blink_led(6, 150);
    delay(500);

    render_oled("Ready", 0.0, 0.0, 0.0, false);
    Serial.println("\r\n=== Arduino fuzzy CLI ready ===");
    Serial.println("Enter two numbers (e.g. \"3 7\") and press Enter.");
    Serial.println("Each run collects 10,000 timed samples (may take a few minutes).");
    Serial.println("The result will appear here and on the OLED.");
    Serial.print("\r\nm1 m2 > ");
    Serial.flush();
#if defined(ARDUINO_SAM_DUE)
    SerialUSB.println("\r\n=== Arduino fuzzy CLI ready ===");
    SerialUSB.println("Enter two numbers (e.g. \"3 7\") and press Enter.");
    SerialUSB.println("Each run collects 10,000 timed samples (may take a few minutes).");
    SerialUSB.println("The result will appear here and on the OLED.");
    SerialUSB.print("\r\nm1 m2 > ");
    SerialUSB.flush();
#endif
    
    // Final pattern: 2 long blinks = ready
    blink_led(2, 500);
    digitalWrite(LED_BUILTIN, LOW); // Turn off LED when ready
}

void loop()
{
    static char line_buffer[64];
    static size_t line_length = 0U;
    static unsigned long last_prompt_ms = 0UL;
    static bool idle_prompt_printed = false;

    // Check both Serial ports
    while (Serial.available() > 0 || 
#if defined(ARDUINO_SAM_DUE)
           SerialUSB.available() > 0
#else
           false
#endif
           ) {
        char c;
        if (Serial.available() > 0) {
            c = static_cast<char>(Serial.read());
        }
#if defined(ARDUINO_SAM_DUE)
        else if (SerialUSB.available() > 0) {
            c = static_cast<char>(SerialUSB.read());
        }
#endif
        idle_prompt_printed = false;
        if (c == '\r') {
            continue;
        }
        if (c == '\n') {
            line_buffer[line_length] = '\0';
            
            // Immediate output using write() instead of print() for faster output
            Serial.write("DEBUG: Received line: [");
            Serial.write(line_buffer, line_length);
            Serial.write("] (len=");
            char len_buf[10];
            itoa(line_length, len_buf, 10);
            Serial.write(len_buf);
            Serial.write(")\r\n");
            Serial.flush();
            
#if defined(ARDUINO_SAM_DUE)
            SerialUSB.write("DEBUG: Received line: [");
            SerialUSB.write(line_buffer, line_length);
            SerialUSB.write("] (len=");
            itoa(line_length, len_buf, 10);
            SerialUSB.write(len_buf);
            SerialUSB.write(")\r\n");
            SerialUSB.flush();
#endif
            
            // LED pattern: quick blink = received input
            digitalWrite(LED_BUILTIN, HIGH);
            delay(50);
            digitalWrite(LED_BUILTIN, LOW);
            delay(50);
            
            handle_line(line_buffer);
            line_length = 0U;
            Serial.print("m1 m2 > ");
            Serial.flush();
#if defined(ARDUINO_SAM_DUE)
            SerialUSB.print("m1 m2 > ");
            SerialUSB.flush();
#endif
            last_prompt_ms = millis();
            continue;
        }
        if (line_length + 1U < sizeof(line_buffer)) {
            line_buffer[line_length++] = c;
        }
    }

    if ((line_length == 0U) && !idle_prompt_printed &&
        (millis() - last_prompt_ms > 2000UL)) {
        Serial.print("\r\nm1 m2 > ");
        Serial.flush();
#if defined(ARDUINO_SAM_DUE)
        SerialUSB.print("\r\nm1 m2 > ");
        SerialUSB.flush();
#endif
        last_prompt_ms = millis();
        idle_prompt_printed = true;
    }
}

