/* memfile.c */
#include "memfile.h"
#include <string.h>
#include <stdio.h>

#define MEMFILE_TABLE_SIZE 20

static FISMemFile g_memTable[MEMFILE_TABLE_SIZE];

static FISMemFile *to_memfile(FILE *stream)
{
    return (FISMemFile *)stream;
}

static void reset_entry(FISMemFile *entry)
{
    if (entry == NULL) {
        return;
    }

    entry->buffer   = NULL;
    entry->length   = 0U;
    entry->position = 0U;
    entry->in_use   = false;
}

void memfile_table_init(void)
{
    for (int i = 0; i < MEMFILE_TABLE_SIZE; ++i) {
        reset_entry(&g_memTable[i]);
    }
}

FILE *memfile_acquire_slot(int slot)
{
    if ((slot >= 0) && (slot < MEMFILE_TABLE_SIZE)) {
        FISMemFile *ctx = &g_memTable[slot];
        reset_entry(ctx);
        ctx->in_use = true;
        return (FILE *)ctx;
    }

    for (int i = 0; i < MEMFILE_TABLE_SIZE; ++i) {
        if (!g_memTable[i].in_use) {
            FISMemFile *ctx = &g_memTable[i];
            reset_entry(ctx);
            ctx->in_use = true;
            return (FILE *)ctx;
        }
    }

    return NULL;
}

FILE *memfile_get_slot(int slot)
{
    if ((slot < 0) || (slot >= MEMFILE_TABLE_SIZE)) {
        return NULL;
    }

    if (!g_memTable[slot].in_use) {
        return NULL;
    }

    return (FILE *)&g_memTable[slot];
}

void memfile_release_slot(int slot)
{
    if ((slot >= 0) && (slot < MEMFILE_TABLE_SIZE)) {
        reset_entry(&g_memTable[slot]);
    }
}

void memfile_attach(FILE *stream, const uint8_t *buffer, size_t length)
{
    FISMemFile *ctx = to_memfile(stream);
    if (ctx == NULL) {
        return;
    }

    ctx->buffer   = buffer;
    ctx->length   = (buffer != NULL) ? length : 0U;
    ctx->position = 0U;
    ctx->in_use   = true;
}

boolean_T memfile_is_managed(const FILE *stream)
{
    if (stream == NULL) {
        return false;
    }

    const FISMemFile *ctx = (const FISMemFile *)stream;
    return (ctx >= &g_memTable[0]) && (ctx < &g_memTable[MEMFILE_TABLE_SIZE]);
}

size_t fis_mem_fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    static unsigned int read_count = 0;
    static size_t last_position = 0;
    static unsigned int same_pos_count = 0;
    FISMemFile *ctx = to_memfile(stream);
    if ((ptr == NULL) || (ctx == NULL) || !ctx->in_use || (size == 0U) || (nmemb == 0U)) {
        printf("fis_mem_fread: invalid parameters\r\n");
        return 0U;
    }

    size_t requested = size * nmemb;
    if (ctx->position >= ctx->length) {
        printf("fis_mem_fread: EOF reached (pos=%u, len=%u, total reads=%u)\r\n", 
               (unsigned)ctx->position, (unsigned)ctx->length, read_count);
        return 0U;
    }

    /* Detect if we're stuck reading the same position repeatedly */
    if (ctx->position == last_position && ctx->position >= ctx->length - 1) {
        same_pos_count++;
        if (same_pos_count > 100) {
            printf("fis_mem_fread: WARNING - stuck reading same position %u (count=%u)\r\n", 
                   (unsigned)ctx->position, same_pos_count);
        }
    } else {
        same_pos_count = 0;
        last_position = ctx->position;
    }

    size_t remaining = ctx->length - ctx->position;
    if (requested > remaining) {
        requested = remaining;
    }

    /* Reduced verbosity - only print every 5000 reads or on first/last read */
    read_count++;
    if (read_count == 1 || read_count % 5000 == 0 || ctx->position + requested >= ctx->length) {
        printf("fis_mem_fread: reading %u bytes (pos=%u/%u, reads=%u)\r\n", 
               (unsigned)requested, (unsigned)ctx->position, (unsigned)ctx->length, read_count);
    }
    
    memcpy(ptr, &ctx->buffer[ctx->position], requested);
    ctx->position += requested;

    size_t result = size ? (requested / size) : 0U;
    
    if (read_count == 1 || read_count % 5000 == 0 || ctx->position >= ctx->length) {
        printf("fis_mem_fread: read %u items, new pos=%u (total reads=%u)\r\n", 
               (unsigned)result, (unsigned)ctx->position, read_count);
    }
    
    return result;
}

int fis_mem_feof(const FILE *stream)
{
    static unsigned int feof_count = 0;
    const FISMemFile *ctx = (const FISMemFile *)stream;
    if ((ctx == NULL) || !ctx->in_use) {
        return 1;
    }

    feof_count++;
    int result = (ctx->position >= ctx->length) ? 1 : 0;
    if (feof_count == 1 || feof_count % 1000 == 0) {
        printf("fis_mem_feof: pos=%u/%u, eof=%d (calls=%u)\r\n", 
               (unsigned)ctx->position, (unsigned)ctx->length, result, feof_count);
    }
    return result;
}

int fis_mem_fclose(FILE *stream)
{
    FISMemFile *ctx = to_memfile(stream);
    if (ctx == NULL) {
        return 0;
    }

    printf("fis_mem_fclose: closing file (pos=%u/%u)\r\n", 
           (unsigned)ctx->position, (unsigned)ctx->length);
    reset_entry(ctx);
    return 0;
}

static int compute_target_position(FISMemFile *ctx, long offset, int origin, size_t *target)
{
    size_t base = 0U;

    switch (origin) {
    case SEEK_SET:
        base = 0U;
        break;
    case SEEK_CUR:
        base = ctx->position;
        break;
    case SEEK_END:
        base = ctx->length;
        break;
    default:
        return 0;
    }

    long raw = (long)base + offset;
    if (raw < 0L) {
        return 0;
    }

    size_t candidate = (size_t)raw;
    if (candidate > ctx->length) {
        return 0;
    }

    *target = candidate;
    return 1;
}

int fis_mem_fseek(FILE *stream, long offset, int origin)
{
    static unsigned int seek_count = 0;
    FISMemFile *ctx = to_memfile(stream);
    if (ctx == NULL || !ctx->in_use) {
        return -1;
    }

    size_t target = 0U;
    if (!compute_target_position(ctx, offset, origin, &target)) {
        return -1;
    }

    seek_count++;
    if (seek_count == 1 || seek_count % 500 == 0) {
        printf("fis_mem_fseek: seeking to pos=%u (offset=%ld, origin=%d, seeks=%u)\r\n", 
               (unsigned)target, offset, origin, seek_count);
    }

    ctx->position = target;
    return 0;
}

long fis_mem_ftell(const FILE *stream)
{
    const FISMemFile *ctx = (const FISMemFile *)stream;
    if ((ctx == NULL) || !ctx->in_use) {
        return -1L;
    }

    return (long)ctx->position;
}
