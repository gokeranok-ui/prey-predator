/* fis_virtual_fs.h */
#ifndef FIS_VIRTUAL_FS_H_
#define FIS_VIRTUAL_FS_H_

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include "rtwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

struct emxArray_char_T;

void  fis_virtual_fs_init(void);
void  fis_virtual_fs_reset(void);
FILE *fis_virtual_fs_open_blob(void);
void  fis_virtual_fs_close_blob(FILE *stream);
FILE *fis_virtual_fs_cfopen(const char *filename, const char *mode, int slot_index);

int          fis_virtual_fs_find_first_fis(char *out_name, size_t buffer_len);
int          fis_virtual_fs_load_file(const char *filename);
const uint8_t *fis_virtual_fs_get_data(size_t *length);
const char   *fis_virtual_fs_get_loaded_filename(void);
uint32_t      fis_virtual_fs_get_input_count(void);
uint32_t      fis_virtual_fs_get_output_count(void);
const char   *fis_virtual_fs_get_input_name(uint32_t index);
const char   *fis_virtual_fs_get_output_name(uint32_t index);

#ifdef __cplusplus
}
#endif

#endif /* FIS_VIRTUAL_FS_H_ */
