/* memfile.h */
#ifndef MEMFILE_H_
#define MEMFILE_H_

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include "rtwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    const uint8_t *buffer;
    size_t         length;
    size_t         position;
    boolean_T      in_use;
} FISMemFile;

void    memfile_table_init(void);
FILE   *memfile_acquire_slot(int slot);
FILE   *memfile_get_slot(int slot);
void    memfile_release_slot(int slot);
void    memfile_attach(FILE *stream, const uint8_t *buffer, size_t length);
boolean_T memfile_is_managed(const FILE *stream);

size_t  fis_mem_fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
int     fis_mem_feof(const FILE *stream);
int     fis_mem_fclose(FILE *stream);
int     fis_mem_fseek(FILE *stream, long offset, int origin);
long    fis_mem_ftell(const FILE *stream);

#ifdef __cplusplus
}
#endif

#ifdef FIS_MEMFILE_ENABLE_OVERRIDES
#define fread  fis_mem_fread
#define feof   fis_mem_feof
#define fclose fis_mem_fclose
#define fseek  fis_mem_fseek
#define ftell  fis_mem_ftell
#endif

#endif /* MEMFILE_H_ */
