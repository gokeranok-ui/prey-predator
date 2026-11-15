/* fis_virtual_fs.c */
#include "fis_virtual_fs.h"

#define FIS_MEMFILE_ENABLE_OVERRIDES
#include "memfile.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

#if defined(__AVR__)
#include <avr/pgmspace.h>
#endif

#include "opkene_data.h"

extern const uint8_t g_tipper_fis_blob[];
extern const unsigned int g_tipper_fis_blob_len;

#define FIS_MAX_INPUTS   8U
#define FIS_MAX_OUTPUTS  4U

static int mode_is_read_only(const char *mode);
static int load_fis_from_blob(void);
static const uint8_t *get_fis_buffer(size_t *length);
static void clear_fis_metadata(void);
static void parse_fis_metadata(void);

static uint8_t *s_fis_data    = NULL;
static size_t   s_fis_length  = 0U;
static char     s_loaded_name[64] = {0};
static char     s_loaded_path[128] = {0};
static uint32_t s_input_count  = 0U;
static uint32_t s_output_count = 0U;
static char     s_input_names[FIS_MAX_INPUTS][32];
static char     s_output_names[FIS_MAX_OUTPUTS][32];
static const char *s_default_fis_name = "tipper.fis";
static int s_loaded_from_sd = 0;

static void clear_fis_metadata(void)
{
    s_input_count = 0U;
    s_output_count = 0U;
    for (uint32_t i = 0; i < FIS_MAX_INPUTS; ++i) {
        s_input_names[i][0] = '\0';
    }
    for (uint32_t i = 0; i < FIS_MAX_OUTPUTS; ++i) {
        s_output_names[i][0] = '\0';
    }
}

static const uint8_t *get_fis_buffer(size_t *length)
{
    if (length != NULL) {
        *length = s_fis_length;
    }
    return s_fis_data;
}

void fis_virtual_fs_init(void)
{
    memfile_table_init();
}

void fis_virtual_fs_reset(void)
{
    for (int idx = 0; idx < 20; ++idx) {
        FILE *stream = eml_openfiles[idx];
        if ((stream != NULL) && memfile_is_managed(stream)) {
            fis_mem_fclose(stream);
            eml_openfiles[idx] = NULL;
            eml_autoflush[idx] = false;
        }
    }

    if (s_fis_data != NULL) {
        free(s_fis_data);
        s_fis_data = NULL;
    }
    s_fis_length = 0U;
    s_loaded_name[0] = '\0';
    s_loaded_path[0] = '\0';
    clear_fis_metadata();

    memfile_table_init();
}

FILE *fis_virtual_fs_open_blob(void)
{
    size_t length = 0U;
    const uint8_t *buffer = get_fis_buffer(&length);
    if ((buffer == NULL) || (length == 0U)) {
        printf("fis_virtual_fs_open_blob: ERROR - no FIS data available\r\n");
        return NULL;
    }

    FILE *stream = memfile_acquire_slot(-1);
    if (stream != NULL) {
        memfile_attach(stream, buffer, length);
    }
    return stream;
}

void fis_virtual_fs_close_blob(FILE *stream)
{
    if ((stream != NULL) && memfile_is_managed(stream)) {
        fis_mem_fclose(stream);
    }
}

FILE *fis_virtual_fs_cfopen(const char *filename, const char *mode, int slot_index)
{
    printf("fis_virtual_fs_cfopen: called with filename='%s', mode='%s', slot=%d\r\n", 
           filename ? filename : "(NULL)", mode ? mode : "(NULL)", slot_index);
    
    if ((filename == NULL) || (mode == NULL)) {
        printf("fis_virtual_fs_cfopen: NULL filename or mode\r\n");
        return NULL;
    }

    if (!mode_is_read_only(mode)) {
        printf("fis_virtual_fs_cfopen: mode '%s' is not read-only\r\n", mode);
        return NULL;
    }

    if (!load_fis_from_blob()) {
        printf("fis_virtual_fs_cfopen: ERROR - embedded blob unavailable\r\n");
        return NULL;
    }

    size_t length = 0U;
    const uint8_t *buffer = get_fis_buffer(&length);
    if ((buffer == NULL) || (length == 0U)) {
        printf("fis_virtual_fs_cfopen: ERROR - buffer not available\r\n");
        return NULL;
    }

    printf("fis_virtual_fs_cfopen: filename matches! Acquiring slot...\r\n");
    int requested_slot = ((slot_index >= 0) && (slot_index < 20)) ? slot_index : -1;
    FILE *stream = memfile_acquire_slot(requested_slot);
    if (stream == NULL) {
        printf("fis_virtual_fs_cfopen: ERROR - memfile_acquire_slot failed!\r\n");
        return NULL;
    }

    printf("fis_virtual_fs_cfopen: attaching SD blob (len=%u)\r\n", (unsigned int)length);
    memfile_attach(stream, buffer, length);
    printf("fis_virtual_fs_cfopen: success!\r\n");
    return stream;
}

static int mode_is_read_only(const char *mode)
{
    if ((mode == NULL) || (mode[0] == '\0')) {
        return 0;
    }

    switch (mode[0]) {
    case 'r':
    case 'R':
        return 1;

    default:
        return 0;
    }
}

static int load_fis_from_blob(void)
{
    if ((g_tipper_fis_blob == NULL) || (g_tipper_fis_blob_len == 0U)) {
        return 0;
    }

    size_t alloc_size = (size_t)g_tipper_fis_blob_len + 1U;
    uint8_t *buffer = (uint8_t *)malloc(alloc_size);
    if (buffer == NULL) {
        printf("fis_virtual_fs: malloc(%u) failed for embedded blob\r\n", (unsigned int)alloc_size);
        return 0;
    }

#if defined(__AVR__)
    memcpy_P(buffer, g_tipper_fis_blob, (size_t)g_tipper_fis_blob_len);
#else
    memcpy(buffer, g_tipper_fis_blob, (size_t)g_tipper_fis_blob_len);
#endif
    buffer[g_tipper_fis_blob_len] = '\0';

    if (s_fis_data != NULL) {
        free(s_fis_data);
    }
    s_fis_data = buffer;
    s_fis_length = (size_t)g_tipper_fis_blob_len;
    strncpy(s_loaded_name, s_default_fis_name, sizeof(s_loaded_name) - 1U);
    s_loaded_name[sizeof(s_loaded_name) - 1U] = '\0';
    s_loaded_path[0] = '\0';

    // Parse metadata - this might hang if there's an issue
    parse_fis_metadata();
    
    printf("fis_virtual_fs: loaded %u bytes from embedded blob '%s'\r\n",
           (unsigned int)s_fis_length, s_default_fis_name);
    s_loaded_from_sd = 0;
    return 1;
}

static void parse_fis_metadata(void)
{
    clear_fis_metadata();
    if ((s_fis_data == NULL) || (s_fis_length == 0U)) {
        return;
    }

    const char *text = (const char *)s_fis_data;
    const char *end  = text + s_fis_length;
    const char *cursor = text;
    int loop_count = 0; // Safety counter

    while (s_input_count < FIS_MAX_INPUTS) {
        if (++loop_count > 100) { // Prevent infinite loop
            break;
        }
        const char *marker = strstr(cursor, "[Input");
        if (marker == NULL) {
            break;
        }
        if (marker >= end) { // Safety check
            break;
        }
        const char *section_end = strstr(marker + 6, "\n[");
        if (section_end == NULL) {
            section_end = end;
        }
        if (section_end > end) { // Safety check
            section_end = end;
        }
        const char *name_key = strstr(marker, "Name=");
        char name_buffer[32] = {0};
        if (name_key != NULL && name_key < section_end) {
            name_key += 5;
            while ((*name_key == ' ') || (*name_key == '\t')) {
                name_key++;
            }
            char quote = 0;
            if (*name_key == '\'' || *name_key == '"') {
                quote = *name_key;
                name_key++;
            }
            size_t idx = 0U;
            while ((name_key < section_end) && (*name_key != '\0') &&
                   (*name_key != '\r') && (*name_key != '\n') &&
                   ((quote == 0) || (*name_key != quote))) {
                if (idx + 1U < sizeof(name_buffer)) {
                    name_buffer[idx++] = *name_key;
                }
                name_key++;
            }
            name_buffer[idx] = '\0';
        }
        if (name_buffer[0] == '\0') {
            snprintf(name_buffer, sizeof(name_buffer), "Input %lu", (unsigned long)(s_input_count + 1U));
        }
        strncpy(s_input_names[s_input_count], name_buffer, sizeof(s_input_names[0]) - 1U);
        s_input_names[s_input_count][sizeof(s_input_names[0]) - 1U] = '\0';
        s_input_count++;
        cursor = section_end;
    }

    cursor = text;
    loop_count = 0; // Reset safety counter
    while (s_output_count < FIS_MAX_OUTPUTS) {
        if (++loop_count > 100) { // Prevent infinite loop
            break;
        }
        const char *marker = strstr(cursor, "[Output");
        if (marker == NULL) {
            break;
        }
        if (marker >= end) { // Safety check
            break;
        }
        const char *section_end = strstr(marker + 7, "\n[");
        if (section_end == NULL) {
            section_end = end;
        }
        if (section_end > end) { // Safety check
            section_end = end;
        }
        const char *name_key = strstr(marker, "Name=");
        char name_buffer[32] = {0};
        if (name_key != NULL && name_key < section_end) {
            name_key += 5;
            while ((*name_key == ' ') || (*name_key == '\t')) {
                name_key++;
            }
            char quote = 0;
            if (*name_key == '\'' || *name_key == '"') {
                quote = *name_key;
                name_key++;
            }
            size_t idx = 0U;
            while ((name_key < section_end) && (*name_key != '\0') &&
                   (*name_key != '\r') && (*name_key != '\n') &&
                   ((quote == 0) || (*name_key != quote))) {
                if (idx + 1U < sizeof(name_buffer)) {
                    name_buffer[idx++] = *name_key;
                }
                name_key++;
            }
            name_buffer[idx] = '\0';
        }
        if (name_buffer[0] == '\0') {
            snprintf(name_buffer, sizeof(name_buffer), "Output %lu", (unsigned long)(s_output_count + 1U));
        }
        strncpy(s_output_names[s_output_count], name_buffer, sizeof(s_output_names[0]) - 1U);
        s_output_names[s_output_count][sizeof(s_output_names[0]) - 1U] = '\0';
        s_output_count++;
        cursor = section_end;
    }
}

int fis_virtual_fs_find_first_fis(char *out_name, size_t buffer_len)
{
    if ((out_name == NULL) || (buffer_len == 0U)) {
        return 0;
    }

    strncpy(out_name, s_default_fis_name, buffer_len - 1U);
    out_name[buffer_len - 1U] = '\0';
    return load_fis_from_blob();
}

int fis_virtual_fs_load_file(const char *filename)
{
    (void)filename;
    return load_fis_from_blob();
}

const uint8_t *fis_virtual_fs_get_data(size_t *length)
{
    return get_fis_buffer(length);
}

const char *fis_virtual_fs_get_loaded_filename(void)
{
    return (s_loaded_name[0] != '\0') ? s_loaded_name : NULL;
}

uint32_t fis_virtual_fs_get_input_count(void)
{
    return s_input_count;
}

uint32_t fis_virtual_fs_get_output_count(void)
{
    return s_output_count;
}

const char *fis_virtual_fs_get_input_name(uint32_t index)
{
    if (index >= s_input_count || index >= FIS_MAX_INPUTS) {
        return NULL;
    }
    return (s_input_names[index][0] != '\0') ? s_input_names[index] : NULL;
}

const char *fis_virtual_fs_get_output_name(uint32_t index)
{
    if (index >= s_output_count || index >= FIS_MAX_OUTPUTS) {
        return NULL;
    }
    return (s_output_names[index][0] != '\0') ? s_output_names[index] : NULL;
}

int fis_virtual_fs_last_load_from_sd(void)
{
    return s_loaded_from_sd;
}
