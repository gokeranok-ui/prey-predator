/* fis_virtual_fs.c */
#include "fis_virtual_fs.h"

#define FIS_MEMFILE_ENABLE_OVERRIDES
#include "memfile.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

#include "fatfs.h"
#include "opkene_data.h"

#define FIS_MAX_INPUTS   8U
#define FIS_MAX_OUTPUTS  4U

static int mode_is_read_only(const char *mode);
static int load_fis_from_sd(const char *filename);
static const uint8_t *get_fis_buffer(size_t *length);
static void clear_fis_metadata(void);
static void parse_fis_metadata(void);
static int has_fis_extension(const char *name);
static const char *basename_from_path(const char *path);

static uint8_t *s_fis_data    = NULL;
static size_t   s_fis_length  = 0U;
static char     s_loaded_name[64] = {0};
static char     s_loaded_path[128] = {0};
static uint32_t s_input_count  = 0U;
static uint32_t s_output_count = 0U;
static char     s_input_names[FIS_MAX_INPUTS][32];
static char     s_output_names[FIS_MAX_OUTPUTS][32];

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

    if (!load_fis_from_sd(filename)) {
        printf("fis_virtual_fs_cfopen: ERROR - failed to load '%s' from SD card\r\n", filename);
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

static const char *basename_from_path(const char *path)
{
    if (path == NULL) {
        return NULL;
    }
    const char *base = path;
    const char *slash = strrchr(path, '/');
    const char *backslash = strrchr(path, '\\');
    const char *colon = strrchr(path, ':');
    if (slash != NULL && slash >= base) {
        base = slash + 1;
    }
    if (backslash != NULL && backslash >= base) {
        base = backslash + 1;
    }
    if (colon != NULL && colon >= base) {
        base = colon + 1;
    }
    return (*base != '\0') ? base : path;
}

static int has_fis_extension(const char *name)
{
    if (name == NULL) {
        return 0;
    }
    const char *dot = strrchr(name, '.');
    if (dot == NULL) {
        return 0;
    }
    char c1 = (char)tolower((unsigned char)dot[1]);
    char c2 = (char)tolower((unsigned char)dot[2]);
    char c3 = (char)tolower((unsigned char)dot[3]);
    return (c1 == 'f' && c2 == 'i' && c3 == 's' && (dot[4] == '\0' || dot[4] == '\r' || dot[4] == '\n'));
}

static int load_fis_from_sd(const char *filename)
{
    if ((filename == NULL) || (filename[0] == '\0')) {
        return 0;
    }

    const char *base = basename_from_path(filename);
    if ((s_fis_data != NULL) && (strcmp(base, s_loaded_name) == 0)) {
        return 1;
    }

    char full_path[sizeof(s_loaded_path)];
    if ((strchr(filename, ':') != NULL) || (strchr(filename, '/') != NULL) || (strchr(filename, '\\') != NULL)) {
        strncpy(full_path, filename, sizeof(full_path) - 1U);
        full_path[sizeof(full_path) - 1U] = '\0';
    } else {
        if (SDPath[0] != '\0') {
            snprintf(full_path, sizeof(full_path), "%s%s", SDPath, filename);
        } else {
            snprintf(full_path, sizeof(full_path), "%s", filename);
        }
    }

    FIL file;
    FRESULT res = f_open(&file, full_path, FA_READ);
    if (res != FR_OK) {
        printf("fis_virtual_fs: f_open('%s') failed (res=%d)\r\n", full_path, (int)res);
        return 0;
    }

    size_t length = (size_t)f_size(&file);
    if (length == 0U) {
        printf("fis_virtual_fs: file '%s' size is zero\r\n", full_path);
        f_close(&file);
        return 0;
    }

    uint8_t *buffer = (uint8_t *)malloc(length + 1U);
    if (buffer == NULL) {
        printf("fis_virtual_fs: malloc(%u) failed\r\n", (unsigned int)(length + 1U));
        f_close(&file);
        return 0;
    }

    UINT bytes_read = 0U;
    res = f_read(&file, buffer, (UINT)length, &bytes_read);
    f_close(&file);
    if ((res != FR_OK) || (bytes_read != (UINT)length)) {
        printf("fis_virtual_fs: f_read('%s') failed (res=%d, read=%u/%u)\r\n",
               full_path, (int)res, (unsigned int)bytes_read, (unsigned int)length);
        free(buffer);
        return 0;
    }

    buffer[length] = '\0';

    if (s_fis_data != NULL) {
        free(s_fis_data);
    }
    s_fis_data = buffer;
    s_fis_length = length;
    strncpy(s_loaded_name, base, sizeof(s_loaded_name) - 1U);
    s_loaded_name[sizeof(s_loaded_name) - 1U] = '\0';
    strncpy(s_loaded_path, full_path, sizeof(s_loaded_path) - 1U);
    s_loaded_path[sizeof(s_loaded_path) - 1U] = '\0';

    parse_fis_metadata();

    printf("fis_virtual_fs: loaded %u bytes from '%s'\r\n", (unsigned int)length, full_path);
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

    while (s_input_count < FIS_MAX_INPUTS) {
        const char *marker = strstr(cursor, "[Input");
        if (marker == NULL) {
            break;
        }
        const char *section_end = strstr(marker + 6, "\n[");
        if (section_end == NULL) {
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
    while (s_output_count < FIS_MAX_OUTPUTS) {
        const char *marker = strstr(cursor, "[Output");
        if (marker == NULL) {
            break;
        }
        const char *section_end = strstr(marker + 7, "\n[");
        if (section_end == NULL) {
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

    DIR dir;
    FILINFO fno;
#if defined(FF_USE_LFN) && FF_USE_LFN
    char lfn[FF_MAX_LFN + 1];
    fno.lfname = lfn;
    fno.lfsize = sizeof(lfn);
#endif

    const char *root = (SDPath[0] != '\0') ? SDPath : "/";
    FRESULT res = f_opendir(&dir, root);
    if (res != FR_OK) {
        printf("fis_virtual_fs: f_opendir('%s') failed (res=%d)\r\n", root, (int)res);
        return 0;
    }

    int found = 0;
    while (1) {
        res = f_readdir(&dir, &fno);
        if (res != FR_OK || fno.fname[0] == 0) {
            break;
        }
        const char *name = fno.fname;
#if defined(FF_USE_LFN) && FF_USE_LFN
        if (fno.lfname[0] != '\0') {
            name = fno.lfname;
        }
#endif
        if (name == NULL) {
            continue;
        }
        if (fno.fattrib & AM_DIR) {
            continue;
        }
        if (has_fis_extension(name)) {
            strncpy(out_name, name, buffer_len - 1U);
            out_name[buffer_len - 1U] = '\0';
            found = 1;
            break;
        }
    }

    f_closedir(&dir);
    return found;
}

int fis_virtual_fs_load_file(const char *filename)
{
    return load_fis_from_sd(filename);
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
