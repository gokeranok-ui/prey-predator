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
    FISMemFile *ctx = to_memfile(stream);
    if ((ptr == NULL) || (ctx == NULL) || !ctx->in_use || size == 0U || nmemb == 0U) {
        return 0U;
    }

    size_t requested = size * nmemb;
    if (ctx->position >= ctx->length) {
        return 0U;
    }

    size_t remaining = ctx->length - ctx->position;
    if (requested > remaining) {
        requested = remaining;
    }

    memcpy(ptr, &ctx->buffer[ctx->position], requested);
    ctx->position += requested;
    return size ? (requested / size) : 0U;
}

int fis_mem_feof(const FILE *stream)
{
    const FISMemFile *ctx = (const FISMemFile *)stream;
    if ((ctx == NULL) || !ctx->in_use) {
        return 1;
    }
    return (ctx->position >= ctx->length) ? 1 : 0;
}

int fis_mem_fclose(FILE *stream)
{
    FISMemFile *ctx = to_memfile(stream);
    if (ctx == NULL) {
        return 0;
    }
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
    FISMemFile *ctx = to_memfile(stream);
    if (ctx == NULL || !ctx->in_use) {
        return -1;
    }

    size_t target = 0U;
    if (!compute_target_position(ctx, offset, origin, &target)) {
        return -1;
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
