#ifndef FUZZY_RUNNER_H
#define FUZZY_RUNNER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void  fuzzy_runner_set_fis_filename(const char *filename);
void  fuzzy_runner_configure(uint32_t inputs, uint32_t outputs);
void  fuzzy_runner_init(void);
void  fuzzy_runner_deinit(void);
float fuzzy_runner_execute(const float *inputs, uint32_t input_count,
                           float *outputs, uint32_t max_outputs);
float fuzzy_run(float in_speed_error, float in_speed_delta); /* legacy helper */
const char *fuzzy_runner_get_fis_name(void);
void  fuzzy_runner_get_dimensions(uint32_t *inputs, uint32_t *outputs);

#ifdef __cplusplus
}
#endif

#endif /* FUZZY_RUNNER_H */
