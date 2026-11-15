#include "fuzzy_runner.h"

#include "fis_virtual_fs.h"

#include "opkene.h"
#include "opkene_emxAPI.h"
#include "opkene_initialize.h"
#include "opkene_terminate.h"
#include "opkene_types.h"

#include <stdint.h>
#include <string.h>
#include <stdio.h>

static int                  s_ready       = 0;
static emxArray_char_T     *s_file_name   = NULL;
static char                 s_fis_filename[64] = "tipper.fis";
static uint32_t             s_num_inputs  = 2U;
static uint32_t             s_num_outputs = 1U;

void fuzzy_runner_set_fis_filename(const char *filename)
{
    if ((filename != NULL) && (filename[0] != '\0')) {
        strncpy(s_fis_filename, filename, sizeof(s_fis_filename) - 1U);
        s_fis_filename[sizeof(s_fis_filename) - 1U] = '\0';
    }
}

void fuzzy_runner_configure(uint32_t inputs, uint32_t outputs)
{
    if (inputs == 0U) {
        inputs = 1U;
    }
    if (outputs == 0U) {
        outputs = 1U;
    }
    s_num_inputs = inputs;
    s_num_outputs = outputs;
}

static emxArray_char_T *create_filename_emx(const char *path)
{
    const size_t len = strlen(path);
    int dims[2] = {1, (int)len};

    emxArray_char_T *arr = emxCreateND_char_T(2, dims);
    for (size_t i = 0; i < len; ++i) {
        arr->data[i] = (signed char)path[i];
    }
    return arr;
}

static emxArray_real_T *create_input_emx(const float *values, uint32_t count)
{
    uint32_t required = s_num_inputs > 0U ? s_num_inputs : 1U;
    int dims[2] = {1, (int)required};
    emxArray_real_T *arr = emxCreateND_real_T(2, dims);
    if (arr == NULL) {
        return NULL;
    }

    for (uint32_t i = 0U; i < required; ++i) {
        real_T value = 0.0;
        if (values != NULL && i < count) {
            value = (real_T)values[i];
        }
        arr->data[i] = value;
    }
    return arr;
}

static emxArray_real_T *create_output_emx(void)
{
    uint32_t outputs = s_num_outputs > 0U ? s_num_outputs : 1U;
    int dims[2] = {1, (int)outputs};
    return emxCreateND_real_T(2, dims);
}

void fuzzy_runner_init(void)
{
    if (s_ready) {
        return;
    }

    opkene_initialize();
#if defined(FUZZY_DEBUG)
    printf("[DBG] opkene_initialize done\r\n");
#endif

    s_file_name = create_filename_emx(s_fis_filename);
    if (s_file_name == NULL) {
        printf("fuzzy_runner_init: ERROR - create_filename_emx failed!\r\n");
        return;
    }
#if defined(FUZZY_DEBUG)
    printf("[DBG] s_file_name allocated\r\n");
#endif

    s_ready = 1;
}

float fuzzy_runner_execute(const float *inputs, uint32_t input_count,
                           float *outputs, uint32_t max_outputs)
{
    if (!s_ready) {
        fuzzy_runner_init();
    }

    if (!s_ready) {
        return 0.0f;
    }

    emxArray_real_T *inputs_arr  = create_input_emx(inputs, input_count);
    emxArray_real_T *outputs_arr = create_output_emx();
    #if defined(FUZZY_DEBUG)
    printf("[DBG] emx arrays created\r\n");
    #endif
    if ((inputs_arr == NULL) || (outputs_arr == NULL)) {
        printf("fuzzy_runner_execute: ERROR - array creation failed!\r\n");
        if (inputs_arr != NULL) {
            emxDestroyArray_real_T(inputs_arr);
        }
        if (outputs_arr != NULL) {
            emxDestroyArray_real_T(outputs_arr);
        }
        return 0.0f;
    }

    #if defined(FUZZY_DEBUG)
    printf("[DBG] calling opkene()\r\n");
    #endif
    opkene(s_file_name, inputs_arr, outputs_arr);
    #if defined(FUZZY_DEBUG)
    printf("[DBG] opkene() returned\r\n");
    #endif
    uint32_t produced = (uint32_t)outputs_arr->size[1];

    float first_output = 0.0f;
    if (produced > 0U) {
        first_output = (float)outputs_arr->data[0];
    }

    if ((outputs != NULL) && (max_outputs > 0U)) {
        uint32_t copy = (produced < max_outputs) ? produced : max_outputs;
        for (uint32_t i = 0U; i < copy; ++i) {
            outputs[i] = (float)outputs_arr->data[i];
        }
    }

    emxDestroyArray_real_T(outputs_arr);
    emxDestroyArray_real_T(inputs_arr);

    return first_output;
}

float fuzzy_run(float in_speed_error, float in_speed_delta)
{
    float values[2] = {in_speed_error, in_speed_delta};
    return fuzzy_runner_execute(values, 2U, NULL, 0U);
}

const char *fuzzy_runner_get_fis_name(void)
{
    return s_fis_filename;
}

void fuzzy_runner_get_dimensions(uint32_t *inputs, uint32_t *outputs)
{
    if (inputs != NULL) {
        *inputs = s_num_inputs;
    }
    if (outputs != NULL) {
        *outputs = s_num_outputs;
    }
}

void fuzzy_runner_deinit(void)
{
    if (!s_ready) {
        return;
    }

    emxDestroyArray_char_T(s_file_name);
    s_file_name  = NULL;

    opkene_terminate();

    s_ready = 0;
}
