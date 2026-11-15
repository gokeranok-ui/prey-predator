/* USER CODE BEGIN Header */
/**
  ****
  * @file    : main.c
  * @brief   : Main program body
  ****
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *     www.st.com/SLA0044
  *
  ****
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>  // For sqrt() in statistics computation
#include "core_cm4.h"  // For DWT cycle counter
#include "fuzzy_runner.h"
#include "fis_virtual_fs.h"
#include "printf_override.h"  // For printf suppression during fuzzy execution
#include "stm32469i_discovery_lcd.h"
#include "fatfs.h"
#include "bsp_driver_sd.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define LCD_WIDTH               OTM8009A_480X800_WIDTH
#define LCD_HEIGHT              OTM8009A_480X800_HEIGHT
#define LCD_FRAMEBUFFER_ADDR    LCD_FB_START_ADDRESS
#define LCD_MARGIN_X            16U
#define LCD_MARGIN_Y            16U
#define LCD_LINE_HEIGHT         32U
#define LCD_BYTES_PER_PIXEL     4U
#define MAX_FIS_INPUTS          8U
#define MAX_FIS_OUTPUTS         4U
#define SD_POLL_TIMEOUT         5000U
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CRC_HandleTypeDef hcrc;
DMA2D_HandleTypeDef hdma2d;
DSI_HandleTypeDef hdsi;
I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;
LTDC_HandleTypeDef hltdc;
QSPI_HandleTypeDef hqspi;
SAI_HandleTypeDef hsai_BlockA1;
SD_HandleTypeDef hsd;
TIM_HandleTypeDef htim1;
UART_HandleTypeDef huart3;
UART_HandleTypeDef huart6;
SDRAM_HandleTypeDef hsdram1;

/* USER CODE BEGIN PV */
static uint32_t     g_fis_inputs       = 0U;
static uint32_t     g_fis_outputs      = 0U;
static const char  *g_fis_name         = NULL;
static char         g_loaded_filename[64] = {0};
static char         g_input_names[MAX_FIS_INPUTS][32];
static char         g_output_names[MAX_FIS_OUTPUTS][32];

static void LCD_Setup(void);
static void LCD_DrawSplash(void);
static void LCD_ShowLoadedMessage(const char *message);
static void LCD_UpdateDisplay(const float *inputs, uint32_t input_count,
                              const float *outputs, uint32_t output_count);
static void LCD_Flush(void);
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CRC_Init(void);
static void MX_DMA2D_Init(void);
static void MX_DSIHOST_DSI_Init(void);
static void MX_FMC_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2C2_Init(void);
static void MX_LTDC_Init(void);
static void MX_QUADSPI_Init(void);
static void MX_SAI1_Init(void);
static void MX_SDIO_SD_Init(void);
static void MX_TIM1_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_USART6_UART_Init(void);

/* USER CODE BEGIN PFP */
static void SD_Card_Mount(void);
static void SD_VerifyFISFile(const char *filename);
static void LCD_Setup(void);
static void LCD_DrawSplash(void);
static void LCD_ShowLoadedMessage(const char *message);
static void LCD_UpdateDisplay(const float *inputs, uint32_t input_count,
                              const float *outputs, uint32_t output_count);
static void LCD_Flush(void);
static void UART_ReadLine(char *buffer, size_t length);
static float UART_ReadFloat(const char *prompt);
static int  SD_ReadSector(uint32_t sector, uint8_t *buffer, uint32_t length);

/* Statistics computation for latency distribution */
typedef struct {
  uint32_t avg;
  uint32_t p50;
  uint32_t p95;
  uint32_t max;
  uint32_t stdev;
  uint32_t jitter;
  float ips;
} latency_stats_t;

static int cmp_u32(const void* a, const void* b) {
  uint32_t x = *(const uint32_t*)a;
  uint32_t y = *(const uint32_t*)b;
  return (x > y) - (x < y);
}

static latency_stats_t compute_latency_stats(uint32_t* lat_us, size_t n) {
  latency_stats_t stats = {0};
  if (n == 0) return stats;
  
  /* Compute average and variance */
  uint64_t sum = 0;
  uint64_t sum2 = 0;
  for (size_t i = 0; i < n; i++) {
    sum += lat_us[i];
    sum2 += (uint64_t)lat_us[i] * (uint64_t)lat_us[i];
  }
  stats.avg = (uint32_t)(sum / n);
  
  /* Sort for percentiles */
  qsort(lat_us, n, sizeof(uint32_t), cmp_u32);
  stats.p50 = lat_us[(size_t)(0.50 * (n - 1))];
  stats.p95 = lat_us[(size_t)(0.95 * (n - 1))];
  stats.max = lat_us[n - 1];
  
  /* Compute standard deviation */
  double mean = (double)sum / n;
  double var = ((double)sum2 / n) - (mean * mean);
  stats.stdev = (var > 0.0) ? (uint32_t)sqrt(var) : 0U;
  
  /* Jitter = p95 - p50 */
  stats.jitter = stats.p95 - stats.p50;
  
  /* IPS = 1,000,000 / avg_us (inferences per second) */
  if (stats.avg > 0) {
    stats.ips = 1000000.0f / (float)stats.avg;
  } else {
    stats.ips = 0.0f;
  }
  
  return stats;
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int __io_putchar(int ch)
{
  HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
  return ch;
}

static void LCD_Setup(void)
{
  if (BSP_LCD_InitEx(LCD_ORIENTATION_PORTRAIT) != LCD_OK)
  {
    printf("LCD_Setup: BSP_LCD_Init failed\r\n");
    return;
  }

  BSP_LCD_LayerDefaultInit(0, LCD_FRAMEBUFFER_ADDR);
  BSP_LCD_SelectLayer(0);
  BSP_LCD_SetLayerVisible(0, ENABLE);
  BSP_LCD_SetLayerVisible(1, DISABLE);
  BSP_LCD_DisplayOn();
  BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  BSP_LCD_SetFont(&Font24);

  /* Latch LCD backlight (active high) */
  HAL_GPIO_WritePin(LCD_BL_CTRL_GPIO_Port, LCD_BL_CTRL_Pin, GPIO_PIN_SET);

  BSP_LCD_Clear(LCD_COLOR_BLACK);
  LCD_Flush();
}

static void LCD_DrawLine(uint32_t *yPos, const char *text)
{
  if (text == NULL)
  {
    return;
  }

  BSP_LCD_DisplayStringAt(LCD_MARGIN_X, *yPos, (uint8_t *)text, LEFT_MODE);
  *yPos += LCD_LINE_HEIGHT;
}

static void LCD_DrawSplash(void)
{
  char line[64];
  uint32_t y = LCD_MARGIN_Y;

  BSP_LCD_Clear(LCD_COLOR_BLACK);

  LCD_DrawLine(&y, "Fuzzy Inference Demo");

  const char *display_name = (g_loaded_filename[0] != '\0') ? g_loaded_filename :
                             (g_fis_name != NULL ? g_fis_name : "unknown");
  snprintf(line, sizeof(line), "FIS: %s", display_name);
  LCD_DrawLine(&y, line);

  snprintf(line, sizeof(line), "System: %lux%lu",
           (unsigned long)g_fis_inputs,
           (unsigned long)g_fis_outputs);
  LCD_DrawLine(&y, line);

  LCD_DrawLine(&y, "Enter inputs via UART");
  LCD_DrawLine(&y, "and press Enter.");
  LCD_Flush();
}

static void LCD_ShowLoadedMessage(const char *message)
{
  char line[64];
  uint32_t y = LCD_MARGIN_Y;

  BSP_LCD_Clear(LCD_COLOR_BLACK);

  LCD_DrawLine(&y, "Fuzzy Inference Demo");
  const char *display_name = (g_loaded_filename[0] != '\0') ? g_loaded_filename :
                             (g_fis_name != NULL ? g_fis_name : "unknown");
  snprintf(line, sizeof(line), "FIS: %s", display_name);
  LCD_DrawLine(&y, line);
  if (message != NULL) {
    LCD_DrawLine(&y, message);
  }
  LCD_Flush();
}

static void LCD_UpdateDisplay(const float *inputs, uint32_t input_count,
                              const float *outputs, uint32_t output_count)
{
  char line[64];
  uint32_t y = LCD_MARGIN_Y;

  if (inputs == NULL)
  {
    return;
  }

  BSP_LCD_Clear(LCD_COLOR_BLACK);

  LCD_DrawLine(&y, "Fuzzy Inference Demo");

  const char *display_name = (g_loaded_filename[0] != '\0') ? g_loaded_filename :
                             (g_fis_name != NULL ? g_fis_name : "unknown");
  snprintf(line, sizeof(line), "FIS: %s", display_name);
  LCD_DrawLine(&y, line);

  snprintf(line, sizeof(line), "System: %lux%lu",
           (unsigned long)g_fis_inputs,
           (unsigned long)g_fis_outputs);
  LCD_DrawLine(&y, line);

  for (uint32_t i = 0U; (i < input_count) && (i < MAX_FIS_INPUTS); ++i)
  {
    snprintf(line, sizeof(line), "%s: %.2f", g_input_names[i], inputs[i]);
    LCD_DrawLine(&y, line);
  }

  if (outputs != NULL)
  {
    for (uint32_t i = 0U; (i < output_count) && (i < MAX_FIS_OUTPUTS); ++i)
    {
      const char *out_name = (g_output_names[i][0] != '\0') ?
                              g_output_names[i] : "Output";
      snprintf(line, sizeof(line), "%s : %.2f", out_name, outputs[i]);
      LCD_DrawLine(&y, line);
    }
  }

  LCD_Flush();
}

static void LCD_Flush(void)
{
#if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
  uint32_t addr = LCD_FRAMEBUFFER_ADDR & ~0x1FU; /* 32-byte aligned */
  uint32_t size = LCD_WIDTH * LCD_HEIGHT * LCD_BYTES_PER_PIXEL;
  size = (size + 31U) & ~0x1FU;
  SCB_CleanDCache_by_Addr((uint32_t *)addr, size);
#endif
  if (HAL_DSI_Refresh(&hdsi) != HAL_OK)
  {
    printf("LCD_Flush: HAL_DSI_Refresh failed\r\n");
  }
}

static int SD_ReadSector(uint32_t sector, uint8_t *buffer, uint32_t length)
{
  if ((buffer == NULL) || (length == 0U) || ((length % 512U) != 0U))
  {
    return -1;
  }

  uint32_t block_count = length / 512U;
  if (BSP_SD_ReadBlocks((uint32_t *)buffer, sector, block_count, SD_POLL_TIMEOUT) != MSD_OK)
  {
    return -1;
  }

  while (BSP_SD_GetCardState() != (uint8_t)SD_TRANSFER_OK)
  {
    /* Busy wait */
  }

  return 0;
}

static void SD_Card_Mount(void)
{
  uint8_t detected = BSP_SD_IsDetected();
  printf("SD_Card_Mount: BSP_SD_IsDetected() = %u\r\n", detected);
  if (detected == SD_NOT_PRESENT)
  {
    printf("SD_Card_Mount: card not detected by BSP\r\n");
    return;
  }

  printf("SD_Card_Mount: calling BSP_SD_Init()\r\n");
  if (BSP_SD_Init() != MSD_OK)
  {
    printf("SD_Card_Mount: BSP_SD_Init failed\r\n");
    return;
  }

  BSP_SD_CardInfo CardInfo;
  BSP_SD_GetCardInfo(&CardInfo);
  printf("SD_Card_Mount: CardType=%lu, BlockNbr=%lu, BlockSize=%lu\r\n",
         (unsigned long)CardInfo.CardType,
         (unsigned long)CardInfo.BlockNbr,
         (unsigned long)CardInfo.BlockSize);

  printf("SD_Card_Mount: mounting filesystem (path='%s')\r\n", SDPath);
  SDFatFS.fs_type = 0;
  FRESULT res = f_mount(&SDFatFS, SDPath, 1);
  if (res == FR_OK)
  {
    printf("SD_Card_Mount: mounted at '%s'\r\n", SDPath);
  }
  else
  {
    printf("SD_Card_Mount: f_mount failed (res=%d)\r\n", (int)res);
    if (res == FR_NO_FILESYSTEM)
    {
      printf("Suggestion: format the card as FAT32 and ensure the partition is primary.\r\n");
#if 1
      printf("SD_Card_Mount: dumping first 64 bytes of sector 0:\r\n");
      uint8_t sector[512];
      if (SD_ReadSector(0U, sector, sizeof(sector)) == 0)
      {
        for (int i = 0; i < 64; i += 16)
        {
          printf("  %02X %02X %02X %02X  %02X %02X %02X %02X  %02X %02X %02X %02X  %02X %02X %02X %02X\r\n",
                 sector[i], sector[i+1], sector[i+2], sector[i+3],
                 sector[i+4], sector[i+5], sector[i+6], sector[i+7],
                 sector[i+8], sector[i+9], sector[i+10], sector[i+11],
                 sector[i+12], sector[i+13], sector[i+14], sector[i+15]);
        }
      }
      else
      {
        printf("SD_Card_Mount: SD_ReadSector failed\r\n");
      }
#endif
    }
  }
}

static void SD_VerifyFISFile(const char *filename)
{
  if ((filename == NULL) || (filename[0] == '\0'))
  {
    return;
  }

  char full_path[64];
  if ((strchr(filename, ':') != NULL) || (strchr(filename, '/') != NULL) || (strchr(filename, '\\') != NULL))
  {
    strncpy(full_path, filename, sizeof(full_path) - 1U);
    full_path[sizeof(full_path) - 1U] = '\0';
  }
  else if (SDPath[0] != '\0')
  {
    snprintf(full_path, sizeof(full_path), "%s%s", SDPath, filename);
  }
  else
  {
    snprintf(full_path, sizeof(full_path), "%s", filename);
  }

  FILINFO info;
  FRESULT res = f_stat(full_path, &info);
  if (res == FR_OK)
  {
    printf("SD_VerifyFISFile: '%s' size=%lu bytes\r\n",
           full_path, (unsigned long)info.fsize);
  }
  else
  {
    printf("SD_VerifyFISFile: WARNING - f_stat('%s') failed (res=%d)\r\n",
           full_path, (int)res);
  }
}

static void UART_ReadLine(char *buffer, size_t length)
{
  if ((buffer == NULL) || (length == 0U))
  {
    return;
  }

  size_t idx = 0U;
  while (1)
  {
    uint8_t ch = 0;
    HAL_UART_Receive(&huart3, &ch, 1U, HAL_MAX_DELAY);

    if ((ch == '\r') || (ch == '\n'))
    {
      uint8_t newline[2] = {'\r', '\n'};
      HAL_UART_Transmit(&huart3, newline, 2U, HAL_MAX_DELAY);
      break;
    }
    else if ((ch == '\b') || (ch == 127U))
    {
      if (idx > 0U)
      {
        idx--;
        uint8_t bs[3] = {'\b', ' ', '\b'};
        HAL_UART_Transmit(&huart3, bs, 3U, HAL_MAX_DELAY);
      }
    }
    else
    {
      if (idx + 1U < length)
      {
        buffer[idx++] = (char)ch;
      }
      HAL_UART_Transmit(&huart3, &ch, 1U, HAL_MAX_DELAY);
    }
  }

  buffer[idx] = '\0';
}

static float UART_ReadFloat(const char *prompt)
{
  char line[64];
  if (prompt != NULL)
  {
    printf("%s", prompt);
  }
  UART_ReadLine(line, sizeof(line));

  char *endptr = NULL;
  float value = strtof(line, &endptr);
  if (endptr == line)
  {
    value = 0.0f;
  }
  return value;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CRC_Init();
  MX_DMA2D_Init();
  MX_DSIHOST_DSI_Init();
  MX_FMC_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_LTDC_Init();
  MX_QUADSPI_Init();
  MX_SAI1_Init();
  MX_SDIO_SD_Init();
  MX_TIM1_Init();
  MX_USART3_UART_Init();
  MX_USART6_UART_Init();

  /* USER CODE BEGIN 2 */
  MX_FATFS_Init();
  SD_Card_Mount();

  char fis_filename[64] = {0};
  if (!fis_virtual_fs_find_first_fis(fis_filename, sizeof(fis_filename))) {
    printf("ERROR: no .fis file found on SD card root\r\n");
    LCD_Setup();
    LCD_ShowLoadedMessage("No .fis file found on SD card!");
    while (1) {
      HAL_Delay(1000);
    }
  }

  printf("SD card: found FIS file '%s'\r\n", fis_filename);
  if (!fis_virtual_fs_load_file(fis_filename)) {
    printf("ERROR: failed to load '%s'\r\n", fis_filename);
    LCD_Setup();
    LCD_ShowLoadedMessage("Failed to load FIS file.");
    while (1) {
      HAL_Delay(1000);
    }
  }

  SD_VerifyFISFile(fis_filename);

  strncpy(g_loaded_filename, fis_filename, sizeof(g_loaded_filename) - 1U);
  g_loaded_filename[sizeof(g_loaded_filename) - 1U] = '\0';

  uint32_t detected_inputs  = fis_virtual_fs_get_input_count();
  uint32_t detected_outputs = fis_virtual_fs_get_output_count();
  if (detected_inputs == 0U) {
    detected_inputs = 2U;
  }
  if (detected_outputs == 0U) {
    detected_outputs = 1U;
  }
  if (detected_inputs > MAX_FIS_INPUTS) {
    detected_inputs = MAX_FIS_INPUTS;
  }
  if (detected_outputs > MAX_FIS_OUTPUTS) {
    detected_outputs = MAX_FIS_OUTPUTS;
  }

  for (uint32_t i = 0U; i < detected_inputs; ++i) {
    const char *name = fis_virtual_fs_get_input_name(i);
    if (name == NULL || name[0] == '\0') {
      snprintf(g_input_names[i], sizeof(g_input_names[i]), "Input %lu", (unsigned long)(i + 1U));
    } else {
      strncpy(g_input_names[i], name, sizeof(g_input_names[i]) - 1U);
      g_input_names[i][sizeof(g_input_names[i]) - 1U] = '\0';
    }
  }

  for (uint32_t i = 0U; i < detected_outputs; ++i) {
    const char *name = fis_virtual_fs_get_output_name(i);
    if (name == NULL || name[0] == '\0') {
      snprintf(g_output_names[i], sizeof(g_output_names[i]), "Output %lu", (unsigned long)(i + 1U));
    } else {
      strncpy(g_output_names[i], name, sizeof(g_output_names[i]) - 1U);
      g_output_names[i][sizeof(g_output_names[i]) - 1U] = '\0';
    }
  }

  fuzzy_runner_set_fis_filename(fis_filename);
  fuzzy_runner_configure(detected_inputs, detected_outputs);

  /* Test UART directly first */
  const char *test_msg = "UART Test OK\r\n";
  HAL_UART_Transmit(&huart3, (uint8_t *)test_msg, strlen(test_msg), HAL_MAX_DELAY);
  
  /* Small delay to ensure UART is ready */
  HAL_Delay(100);
  
  /* Test printf */
  printf("System started\r\n");
  
  printf("Starting fuzzy_runner_init()...\r\n");
  fuzzy_runner_init();
  printf("fuzzy_runner_init() completed\r\n");
  
  // Initialize DWT cycle counter for performance measurement
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
  DWT->CYCCNT = 0;

  fuzzy_runner_get_dimensions(&g_fis_inputs, &g_fis_outputs);
  g_fis_name = fuzzy_runner_get_fis_name();
  if (g_fis_inputs == 0U) {
    g_fis_inputs = 1U;
  }
  if (g_fis_inputs > MAX_FIS_INPUTS) {
    g_fis_inputs = MAX_FIS_INPUTS;
  }
  if (g_fis_outputs == 0U) {
    g_fis_outputs = 1U;
  }
  if (g_fis_outputs > MAX_FIS_OUTPUTS) {
    g_fis_outputs = MAX_FIS_OUTPUTS;
  }

  for (uint32_t i = 0U; i < g_fis_inputs; ++i) {
    if (g_input_names[i][0] == '\0') {
      snprintf(g_input_names[i], sizeof(g_input_names[i]), "Input %lu", (unsigned long)(i + 1U));
    }
  }
  for (uint32_t i = 0U; i < g_fis_outputs; ++i) {
    if (g_output_names[i][0] == '\0') {
      snprintf(g_output_names[i], sizeof(g_output_names[i]), "Output %lu", (unsigned long)(i + 1U));
    }
  }
  if (g_loaded_filename[0] == '\0' && g_fis_name != NULL) {
    strncpy(g_loaded_filename, g_fis_name, sizeof(g_loaded_filename) - 1U);
    g_loaded_filename[sizeof(g_loaded_filename) - 1U] = '\0';
  }

  LCD_Setup();
  LCD_ShowLoadedMessage("FIS file loaded successfully.");
  HAL_Delay(1500);
  LCD_DrawSplash();
  /* USER CODE END 2 */

  printf("FIS ready: expecting %lu input value(s).\r\n", (unsigned long)g_fis_inputs);
  printf("Enter values (space-separated, e.g. '1300 1500' or one per line).\r\n");
  printf("Note: Debug prints disabled for performance measurement.\r\n");

  while (1)
  {
    float input_values[MAX_FIS_INPUTS] = {0.0f};
    float output_values[MAX_FIS_OUTPUTS] = {0.0f};

    /* Read a line that may contain one or more values */
    char line[128];
    printf("Enter input(s): ");
    UART_ReadLine(line, sizeof(line));
    
    /* Parse all values from the line */
    char *line_ptr = line;
    uint32_t values_read = 0U;
    
    for (uint32_t i = 0U; i < g_fis_inputs; ++i)
    {
      /* Skip whitespace */
      while (*line_ptr == ' ' || *line_ptr == '\t')
      {
        line_ptr++;
      }
      
      if (*line_ptr == '\0')
      {
        /* No more values in line, prompt for remaining */
        char prompt[80];
        snprintf(prompt, sizeof(prompt), "%s (input %lu): ", g_input_names[i], (unsigned long)(i + 1U));
        input_values[i] = UART_ReadFloat(prompt);
        values_read++;
      }
      else
      {
        /* Parse value from current position */
        char *endptr = NULL;
        float value = strtof(line_ptr, &endptr);
        if (endptr == line_ptr)
        {
          /* Failed to parse, use 0.0 */
          value = 0.0f;
        }
        input_values[i] = value;
        line_ptr = endptr;  // Move to next value
        values_read++;
      }
    }
    
    /* Display parsed inputs */
    printf("Inputs: ");
    for (uint32_t i = 0U; i < g_fis_inputs; ++i)
    {
      printf("%s=%.1f ", g_input_names[i], input_values[i]);
    }
    printf("\r\n");

    // Measure execution time using DWT cycle counter (already initialized in main())
    extern uint32_t SystemCoreClock;
    
    // Warm-up pass to prime caches
    printf("Warming up...\r\n");
    for (int i = 0; i < 100; i++) {
      printf_override_set_suppress(true);
      fuzzy_runner_execute(input_values, g_fis_inputs, output_values, g_fis_outputs);
      printf_override_set_suppress(false);
    }
    
    // Collect 10,000 samples for statistical analysis
    printf("Collecting 10,000 samples for statistical analysis...\r\n");
    uint32_t latencies[10000];
    
    for (int i = 0; i < 10000; i++) {
      // Disable printf during fuzzy execution to prevent MATLAB debug output from slowing timing
      printf_override_set_suppress(true);
      
      uint32_t start_cycles = DWT->CYCCNT;
      fuzzy_runner_execute(input_values, g_fis_inputs,
                           output_values, g_fis_outputs);
      uint32_t end_cycles = DWT->CYCCNT;
      
      // Re-enable printf for result display (but we won't print in the loop)
      printf_override_set_suppress(false);
      
      uint32_t elapsed_cycles = end_cycles - start_cycles;
      latencies[i] = (uint32_t)((uint64_t)elapsed_cycles * 1000000ULL / SystemCoreClock);
      
      // Progress indicator every 1000 samples
      if ((i + 1) % 1000 == 0) {
        printf("Progress: %d/10000 samples\r\n", i + 1);
      }
    }
    
    // Compute statistics (this will sort the array)
    latency_stats_t stats = compute_latency_stats(latencies, 10000);

    printf("FIS result(s):\r\n");
    for (uint32_t i = 0U; i < g_fis_outputs; ++i)
    {
      printf("  %s = %.6f\r\n", g_output_names[i], output_values[i]);
    }
    
    printf("=== Latency Statistics (10,000 samples) ===\r\n");
    printf("  Average:  %lu us (%.3f ms)\r\n", stats.avg, stats.avg / 1000.0f);
    printf("  Median (p50): %lu us (%.3f ms)\r\n", stats.p50, stats.p50 / 1000.0f);
    printf("  95th percentile (p95): %lu us (%.3f ms)\r\n", stats.p95, stats.p95 / 1000.0f);
    printf("  Maximum (WCE): %lu us (%.3f ms)\r\n", stats.max, stats.max / 1000.0f);
    printf("  Standard deviation: %lu us\r\n", stats.stdev);
    printf("  Jitter (p95-p50): %lu us\r\n", stats.jitter);
    printf("  Throughput: %.2f inferences/sec\r\n", stats.ips);
    printf("==========================================\r\n");

    LCD_UpdateDisplay(input_values, g_fis_inputs,
                      output_values, g_fis_outputs);
    HAL_Delay(1500);
  }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 6;
  RCC_OscInitStruct.PLL.PLLR = 6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode 
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SAI_PLLSAI|RCC_PERIPHCLK_SDIO
                              |RCC_PERIPHCLK_CLK48|RCC_PERIPHCLK_LTDC;
  PeriphClkInitStruct.PLLSAI.PLLSAIN = 144;
  PeriphClkInitStruct.PLLSAI.PLLSAIR = 2;
  PeriphClkInitStruct.PLLSAI.PLLSAIQ = 2;
  PeriphClkInitStruct.PLLSAI.PLLSAIP = RCC_PLLSAIP_DIV6;
  PeriphClkInitStruct.PLLSAIDivQ = 1;
  PeriphClkInitStruct.PLLSAIDivR = RCC_PLLSAIDIVR_4;
  PeriphClkInitStruct.Clk48ClockSelection = RCC_CLK48CLKSOURCE_PLLSAIP;
  PeriphClkInitStruct.SdioClockSelection = RCC_SDIOCLKSOURCE_CLK48;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

/**
  * @brief DMA2D Initialization Function
  * @param None
  * @retval None
  */
static void MX_DMA2D_Init(void)
{

  /* USER CODE BEGIN DMA2D_Init 0 */

  /* USER CODE END DMA2D_Init 0 */

  /* USER CODE BEGIN DMA2D_Init 1 */

  /* USER CODE END DMA2D_Init 1 */
  hdma2d.Instance = DMA2D;
  hdma2d.Init.Mode = DMA2D_M2M;
  hdma2d.Init.ColorMode = DMA2D_OUTPUT_ARGB8888;
  hdma2d.Init.OutputOffset = 0;
  hdma2d.LayerCfg[1].InputOffset = 0;
  hdma2d.LayerCfg[1].InputColorMode = DMA2D_INPUT_ARGB8888;
  hdma2d.LayerCfg[1].AlphaMode = DMA2D_NO_MODIF_ALPHA;
  hdma2d.LayerCfg[1].InputAlpha = 0;
  if (HAL_DMA2D_Init(&hdma2d) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DMA2D_ConfigLayer(&hdma2d, 1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DMA2D_Init 2 */

  /* USER CODE END DMA2D_Init 2 */

}

/**
  * @brief DSIHOST Initialization Function
  * @param None
  * @retval None
  */
static void MX_DSIHOST_DSI_Init(void)
{

  /* USER CODE BEGIN DSIHOST_Init 0 */

  /* USER CODE END DSIHOST_Init 0 */

  DSI_PLLInitTypeDef PLLInit = {0};
  DSI_HOST_TimeoutTypeDef HostTimeouts = {0};
  DSI_PHY_TimerTypeDef PhyTimings = {0};
  DSI_LPCmdTypeDef LPCmd = {0};
  DSI_CmdCfgTypeDef CmdCfg = {0};

  /* USER CODE BEGIN DSIHOST_Init 1 */

  /* USER CODE END DSIHOST_Init 1 */
  hdsi.Instance = DSI;
  hdsi.Init.AutomaticClockLaneControl = DSI_AUTO_CLK_LANE_CTRL_DISABLE;
  hdsi.Init.TXEscapeCkdiv = 4;
  hdsi.Init.NumberOfLanes = DSI_TWO_DATA_LANES;
  PLLInit.PLLNDIV = 125;
  PLLInit.PLLIDF = DSI_PLL_IN_DIV2;
  PLLInit.PLLODF = DSI_PLL_OUT_DIV1;
  if (HAL_DSI_Init(&hdsi, &PLLInit) != HAL_OK)
  {
    Error_Handler();
  }
  HostTimeouts.TimeoutCkdiv = 1;
  HostTimeouts.HighSpeedTransmissionTimeout = 0;
  HostTimeouts.LowPowerReceptionTimeout = 0;
  HostTimeouts.HighSpeedReadTimeout = 0;
  HostTimeouts.LowPowerReadTimeout = 0;
  HostTimeouts.HighSpeedWriteTimeout = 0;
  HostTimeouts.HighSpeedWritePrespMode = DSI_HS_PM_DISABLE;
  HostTimeouts.LowPowerWriteTimeout = 0;
  HostTimeouts.BTATimeout = 0;
  if (HAL_DSI_ConfigHostTimeouts(&hdsi, &HostTimeouts) != HAL_OK)
  {
    Error_Handler();
  }
  PhyTimings.ClockLaneHS2LPTime = 28;
  PhyTimings.ClockLaneLP2HSTime = 33;
  PhyTimings.DataLaneHS2LPTime = 15;
  PhyTimings.DataLaneLP2HSTime = 25;
  PhyTimings.DataLaneMaxReadTime = 0;
  PhyTimings.StopWaitTime = 10;
  if (HAL_DSI_ConfigPhyTimer(&hdsi, &PhyTimings) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DSI_ConfigFlowControl(&hdsi, DSI_FLOW_CONTROL_BTA) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DSI_SetLowPowerRXFilter(&hdsi, 10000) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DSI_ConfigErrorMonitor(&hdsi, HAL_DSI_ERROR_NONE) != HAL_OK)
  {
    Error_Handler();
  }
  LPCmd.LPGenShortWriteNoP = DSI_LP_GSW0P_ENABLE;
  LPCmd.LPGenShortWriteOneP = DSI_LP_GSW1P_ENABLE;
  LPCmd.LPGenShortWriteTwoP = DSI_LP_GSW2P_ENABLE;
  LPCmd.LPGenShortReadNoP = DSI_LP_GSR0P_ENABLE;
  LPCmd.LPGenShortReadOneP = DSI_LP_GSR1P_ENABLE;
  LPCmd.LPGenShortReadTwoP = DSI_LP_GSR2P_ENABLE;
  LPCmd.LPGenLongWrite = DSI_LP_GLW_ENABLE;
  LPCmd.LPDcsShortWriteNoP = DSI_LP_DSW0P_ENABLE;
  LPCmd.LPDcsShortWriteOneP = DSI_LP_DSW1P_ENABLE;
  LPCmd.LPDcsShortReadNoP = DSI_LP_DSR0P_ENABLE;
  LPCmd.LPDcsLongWrite = DSI_LP_DLW_ENABLE;
  LPCmd.LPMaxReadPacket = DSI_LP_MRDP_ENABLE;
  LPCmd.AcknowledgeRequest = DSI_ACKNOWLEDGE_DISABLE;
  if (HAL_DSI_ConfigCommand(&hdsi, &LPCmd) != HAL_OK)
  {
    Error_Handler();
  }
  CmdCfg.VirtualChannelID = 0;
  CmdCfg.ColorCoding = DSI_RGB888;
  CmdCfg.CommandSize = OTM8009A_480X800_WIDTH;
  CmdCfg.TearingEffectSource = DSI_TE_EXTERNAL;
  CmdCfg.TearingEffectPolarity = DSI_TE_RISING_EDGE;
  CmdCfg.HSPolarity = DSI_HSYNC_ACTIVE_LOW;
  CmdCfg.VSPolarity = DSI_VSYNC_ACTIVE_LOW;
  CmdCfg.DEPolarity = DSI_DATA_ENABLE_ACTIVE_HIGH;
  CmdCfg.VSyncPol = DSI_VSYNC_FALLING;
  CmdCfg.AutomaticRefresh = DSI_AR_ENABLE;
  CmdCfg.TEAcknowledgeRequest = DSI_TE_ACKNOWLEDGE_ENABLE;
  if (HAL_DSI_ConfigAdaptedCommandMode(&hdsi, &CmdCfg) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DSI_SetGenericVCID(&hdsi, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DSIHOST_Init 2 */

  /* USER CODE END DSIHOST_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief LTDC Initialization Function
  * @param None
  * @retval None
  */
static void MX_LTDC_Init(void)
{

  /* USER CODE BEGIN LTDC_Init 0 */

  /* USER CODE END LTDC_Init 0 */

  LTDC_LayerCfgTypeDef pLayerCfg = {0};
  const uint32_t hsync  = OTM8009A_480X800_HSYNC;
  const uint32_t vsync  = OTM8009A_480X800_VSYNC;
  const uint32_t hbp    = OTM8009A_480X800_HBP;
  const uint32_t vbp    = OTM8009A_480X800_VBP;
  const uint32_t hfp    = OTM8009A_480X800_HFP;
  const uint32_t vfp    = OTM8009A_480X800_VFP;
  const uint32_t width  = OTM8009A_480X800_WIDTH;
  const uint32_t height = OTM8009A_480X800_HEIGHT;

  /* USER CODE BEGIN LTDC_Init 1 */

  /* USER CODE END LTDC_Init 1 */
  hltdc.Instance = LTDC;
  hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
  hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
  hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
  hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;

  hltdc.Init.HorizontalSync = hsync - 1U;
  hltdc.Init.VerticalSync = vsync - 1U;
  hltdc.Init.AccumulatedHBP = (hsync + hbp - 1U);
  hltdc.Init.AccumulatedVBP = (vsync + vbp - 1U);
  hltdc.Init.AccumulatedActiveW = (width + hsync + hbp - 1U);
  hltdc.Init.AccumulatedActiveH = (height + vsync + vbp - 1U);
  hltdc.Init.TotalWidth = (width + hsync + hbp + hfp - 1U);
  hltdc.Init.TotalHeigh = (height + vsync + vbp + vfp - 1U);
  hltdc.Init.Backcolor.Blue = 0;
  hltdc.Init.Backcolor.Green = 0;
  hltdc.Init.Backcolor.Red = 0;
  if (HAL_LTDC_Init(&hltdc) != HAL_OK)
  {
    Error_Handler();
  }
  pLayerCfg.WindowX0 = 0;
  pLayerCfg.WindowX1 = width;
  pLayerCfg.WindowY0 = 0;
  pLayerCfg.WindowY1 = height;
  pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_ARGB8888;
  pLayerCfg.Alpha = 255;
  pLayerCfg.Alpha0 = 0;
  pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_PAxCA;
  pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_PAxCA;
  pLayerCfg.FBStartAdress = LCD_FRAMEBUFFER_ADDR;
  pLayerCfg.ImageWidth = width;
  pLayerCfg.ImageHeight = height;
  pLayerCfg.Backcolor.Blue = 0;
  pLayerCfg.Backcolor.Green = 0;
  pLayerCfg.Backcolor.Red = 0;
  if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN LTDC_Init 2 */

  /* USER CODE END LTDC_Init 2 */

}

/**
  * @brief QUADSPI Initialization Function
  * @param None
  * @retval None
  */
static void MX_QUADSPI_Init(void)
{

  /* USER CODE BEGIN QUADSPI_Init 0 */

  /* USER CODE END QUADSPI_Init 0 */

  /* USER CODE BEGIN QUADSPI_Init 1 */

  /* USER CODE END QUADSPI_Init 1 */
  /* QUADSPI parameter configuration*/
  hqspi.Instance = QUADSPI;
  hqspi.Init.ClockPrescaler = 255;
  hqspi.Init.FifoThreshold = 1;
  hqspi.Init.SampleShifting = QSPI_SAMPLE_SHIFTING_NONE;
  hqspi.Init.FlashSize = 1;
  hqspi.Init.ChipSelectHighTime = QSPI_CS_HIGH_TIME_1_CYCLE;
  hqspi.Init.ClockMode = QSPI_CLOCK_MODE_0;
  hqspi.Init.FlashID = QSPI_FLASH_ID_1;
  hqspi.Init.DualFlash = QSPI_DUALFLASH_DISABLE;
  if (HAL_QSPI_Init(&hqspi) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN QUADSPI_Init 2 */

  /* USER CODE END QUADSPI_Init 2 */

}

/**
  * @brief SAI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SAI1_Init(void)
{

  /* USER CODE BEGIN SAI1_Init 0 */

  /* USER CODE END SAI1_Init 0 */

  /* USER CODE BEGIN SAI1_Init 1 */

  /* USER CODE END SAI1_Init 1 */
  hsai_BlockA1.Instance = SAI1_Block_A;
  hsai_BlockA1.Init.Protocol = SAI_FREE_PROTOCOL;
  hsai_BlockA1.Init.AudioMode = SAI_MODEMASTER_TX;
  hsai_BlockA1.Init.DataSize = SAI_DATASIZE_8;
  hsai_BlockA1.Init.FirstBit = SAI_FIRSTBIT_MSB;
  hsai_BlockA1.Init.ClockStrobing = SAI_CLOCKSTROBING_FALLINGEDGE;
  hsai_BlockA1.Init.Synchro = SAI_ASYNCHRONOUS;
  hsai_BlockA1.Init.OutputDrive = SAI_OUTPUTDRIVE_DISABLE;
  hsai_BlockA1.Init.NoDivider = SAI_MASTERDIVIDER_ENABLE;
  hsai_BlockA1.Init.FIFOThreshold = SAI_FIFOTHRESHOLD_EMPTY;
  hsai_BlockA1.Init.ClockSource = SAI_CLKSOURCE_PLLSAI;
  hsai_BlockA1.Init.AudioFrequency = SAI_AUDIO_FREQUENCY_192K;
  hsai_BlockA1.Init.SynchroExt = SAI_SYNCEXT_DISABLE;
  hsai_BlockA1.Init.MonoStereoMode = SAI_STEREOMODE;
  hsai_BlockA1.Init.CompandingMode = SAI_NOCOMPANDING;
  hsai_BlockA1.Init.TriState = SAI_OUTPUT_NOTRELEASED;
  hsai_BlockA1.FrameInit.FrameLength = 8;
  hsai_BlockA1.FrameInit.ActiveFrameLength = 1;
  hsai_BlockA1.FrameInit.FSDefinition = SAI_FS_STARTFRAME;
  hsai_BlockA1.FrameInit.FSPolarity = SAI_FS_ACTIVE_LOW;
  hsai_BlockA1.FrameInit.FSOffset = SAI_FS_FIRSTBIT;
  hsai_BlockA1.SlotInit.FirstBitOffset = 0;
  hsai_BlockA1.SlotInit.SlotSize = SAI_SLOTSIZE_DATASIZE;
  hsai_BlockA1.SlotInit.SlotNumber = 1;
  hsai_BlockA1.SlotInit.SlotActive = 0x00000000;
  if (HAL_SAI_Init(&hsai_BlockA1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SAI1_Init 2 */

  /* USER CODE END SAI1_Init 2 */

}

/**
  * @brief SDIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_SDIO_SD_Init(void)
{

  /* USER CODE BEGIN SDIO_Init 0 */

  /* USER CODE END SDIO_Init 0 */

  /* USER CODE BEGIN SDIO_Init 1 */

  /* USER CODE END SDIO_Init 1 */
  hsd.Instance = SDIO;
  hsd.Init.ClockEdge = SDIO_CLOCK_EDGE_RISING;
  hsd.Init.ClockBypass = SDIO_CLOCK_BYPASS_DISABLE;
  hsd.Init.ClockPowerSave = SDIO_CLOCK_POWER_SAVE_DISABLE;
  hsd.Init.BusWide = SDIO_BUS_WIDE_1B;
  hsd.Init.HardwareFlowControl = SDIO_HARDWARE_FLOW_CONTROL_DISABLE;
  hsd.Init.ClockDiv = 4; /* 48 MHz / (ClockDiv + 2) = 8 MHz safe for polling mode */
  /* USER CODE BEGIN SDIO_Init 2 */

  /* USER CODE END SDIO_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 0;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief USART6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART6_UART_Init(void)
{

  /* USER CODE BEGIN USART6_Init 0 */

  /* USER CODE END USART6_Init 0 */

  /* USER CODE BEGIN USART6_Init 1 */

  /* USER CODE END USART6_Init 1 */
  huart6.Instance = USART6;
  huart6.Init.BaudRate = 115200;
  huart6.Init.WordLength = UART_WORDLENGTH_8B;
  huart6.Init.StopBits = UART_STOPBITS_1;
  huart6.Init.Parity = UART_PARITY_NONE;
  huart6.Init.Mode = UART_MODE_TX_RX;
  huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart6.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart6) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART6_Init 2 */

  /* USER CODE END USART6_Init 2 */

}

/* FMC initialization function */
static void MX_FMC_Init(void)
{

  /* USER CODE BEGIN FMC_Init 0 */

  /* USER CODE END FMC_Init 0 */

  FMC_SDRAM_TimingTypeDef SdramTiming = {0};

  /* USER CODE BEGIN FMC_Init 1 */

  /* USER CODE END FMC_Init 1 */

  /** Perform the SDRAM1 memory initialization sequence
  */
  hsdram1.Instance = FMC_SDRAM_DEVICE;
  /* hsdram1.Init */
  hsdram1.Init.SDBank = FMC_SDRAM_BANK1;
  hsdram1.Init.ColumnBitsNumber = FMC_SDRAM_COLUMN_BITS_NUM_8;
  hsdram1.Init.RowBitsNumber = FMC_SDRAM_ROW_BITS_NUM_12;
  hsdram1.Init.MemoryDataWidth = FMC_SDRAM_MEM_BUS_WIDTH_32;
  hsdram1.Init.InternalBankNumber = FMC_SDRAM_INTERN_BANKS_NUM_4;
  hsdram1.Init.CASLatency = FMC_SDRAM_CAS_LATENCY_3;
  hsdram1.Init.WriteProtection = FMC_SDRAM_WRITE_PROTECTION_DISABLE;
  hsdram1.Init.SDClockPeriod = FMC_SDRAM_CLOCK_PERIOD_2;
  hsdram1.Init.ReadBurst = FMC_SDRAM_RBURST_ENABLE;
  hsdram1.Init.ReadPipeDelay = FMC_SDRAM_RPIPE_DELAY_0;
  /* SdramTiming */
  SdramTiming.LoadToActiveDelay = 2;
  SdramTiming.ExitSelfRefreshDelay = 7;
  SdramTiming.SelfRefreshTime = 4;
  SdramTiming.RowCycleDelay = 7;
  SdramTiming.WriteRecoveryTime = 3;
  SdramTiming.RPDelay = 2;
  SdramTiming.RCDDelay = 2;

  if (HAL_SDRAM_Init(&hsdram1, &SdramTiming) != HAL_OK)
  {
    Error_Handler( );
  }

  /* USER CODE BEGIN FMC_Init 2 */

  /* USER CODE END FMC_Init 2 */
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOK_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOJ_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, SPKR_HP_Pin|AUDIO_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, LED3_Pin|LED2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, OTG_FS1_PowerSwitchOn_Pin|EXT_RESET_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOH, GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LCD_BL_CTRL_GPIO_Port, LCD_BL_CTRL_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : SPKR_HP_Pin AUDIO_RST_Pin */
  GPIO_InitStruct.Pin = SPKR_HP_Pin|AUDIO_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : I2S3_CK_Pin */
  GPIO_InitStruct.Pin = I2S3_CK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
  HAL_GPIO_Init(I2S3_CK_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : OTG_FS1_OverCurrent_Pin */
  GPIO_InitStruct.Pin = OTG_FS1_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(OTG_FS1_OverCurrent_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED3_Pin LED2_Pin */
  GPIO_InitStruct.Pin = LED3_Pin|LED2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : LED4_Pin */
  GPIO_InitStruct.Pin = LED4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED4_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED1_Pin */
  GPIO_InitStruct.Pin = LED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : OTG_FS1_PowerSwitchOn_Pin EXT_RESET_Pin */
  GPIO_InitStruct.Pin = OTG_FS1_PowerSwitchOn_Pin|EXT_RESET_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : MIC_CK_Pin */
  GPIO_InitStruct.Pin = MIC_CK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
  HAL_GPIO_Init(MIC_CK_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : uSD_Detect_Pin */
  GPIO_InitStruct.Pin = uSD_Detect_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(uSD_Detect_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LCD_INT_Pin */
  GPIO_InitStruct.Pin = LCD_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(LCD_INT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PH7 */
  GPIO_InitStruct.Pin = GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /*Configure GPIO pin : LCD_BL_CTRL_Pin */
  GPIO_InitStruct.Pin = LCD_BL_CTRL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LCD_BL_CTRL_GPIO_Port, &GPIO_InitStruct);

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM6)
  {
    HAL_IncTick();
  }
}

void Error_Handler(void)
{
  /* User can add custom error handling here */
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
  /* Report assert parameters here if needed */
}
#endif /* USE_FULL_ASSERT */

/**** (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
