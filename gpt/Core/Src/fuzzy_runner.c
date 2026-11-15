#include "fuzzy_runner.h"

#include "fis_virtual_fs.h"
#include "memfile.h"

#include "opkene.h"
#include "opkene_emxAPI.h"
#include "opkene_initialize.h"
#include "opkene_terminate.h"
#include "opkene_types.h"

#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define FIS_SLOT   0

/* Performance measurement: Disable debug prints to get accurate timing */
/* Set to 1 to enable debug output, 0 to disable (for performance testing) */
#ifndef FUZZY_DEBUG
#define FUZZY_DEBUG 0
#endif

#if FUZZY_DEBUG
#define FUZZY_PRINTF(...) printf(__VA_ARGS__)
#define FUZZY_FFLUSH() fflush(stdout)
#else
#define FUZZY_PRINTF(...) ((void)0)
#define FUZZY_FFLUSH() ((void)0)
#endif

static int                  s_ready       = 0;
static FILE                *s_fis_stream  = NULL;
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
        FUZZY_PRINTF("fuzzy_runner_init: already ready\r\n");
        return;
    }

    FUZZY_PRINTF("fuzzy_runner_init: step 1 - memfile_table_init()\r\n");
    /* hook the embedded .fis blob into the virtual FS */
    memfile_table_init();
    
    FUZZY_PRINTF("fuzzy_runner_init: step 2 - memfile_acquire_slot()\r\n");
    s_fis_stream = memfile_acquire_slot(FIS_SLOT);
    if (s_fis_stream == NULL) {
        FUZZY_PRINTF("fuzzy_runner_init: ERROR - memfile_acquire_slot failed!\r\n");
        return;
    }
    
    FUZZY_PRINTF("fuzzy_runner_init: step 3 - memfile_attach()\r\n");
    size_t blob_length = 0U;
    const uint8_t *blob = fis_virtual_fs_get_data(&blob_length);
    if ((blob == NULL) || (blob_length == 0U)) {
        FUZZY_PRINTF("fuzzy_runner_init: ERROR - fis data not loaded\r\n");
        memfile_release_slot(FIS_SLOT);
        s_fis_stream = NULL;
        return;
    }
    memfile_attach(s_fis_stream, blob, blob_length);

    FUZZY_PRINTF("fuzzy_runner_init: step 4 - opkene_initialize()\r\n");
    /* MATLAB runtime boot */
    opkene_initialize();
    FUZZY_PRINTF("fuzzy_runner_init: step 5 - opkene_initialize() completed\r\n");

    FUZZY_PRINTF("fuzzy_runner_init: step 6 - create_filename_emx()\r\n");
    /* cache objects that can be reused across calls */
    s_file_name = create_filename_emx(s_fis_filename);
    if (s_file_name == NULL) {
        FUZZY_PRINTF("fuzzy_runner_init: ERROR - create_filename_emx failed!\r\n");
        return;
    }

    s_ready = 1;
    FUZZY_PRINTF("fuzzy_runner_init: step 7 - initialization complete\r\n");
}

float fuzzy_runner_execute(const float *inputs, uint32_t input_count,
                           float *outputs, uint32_t max_outputs)
{
    if (!s_ready) {
        FUZZY_PRINTF("fuzzy_runner_execute: not ready, calling init\r\n");
        fuzzy_runner_init();
    }

    if (!s_ready) {
        return 0.0f;
    }

    FUZZY_PRINTF("fuzzy_runner_execute: creating input arrays (requested=%lu, expected=%lu)\r\n",
           (unsigned long)input_count, (unsigned long)s_num_inputs);
    emxArray_real_T *inputs_arr  = create_input_emx(inputs, input_count);
    emxArray_real_T *outputs_arr = create_output_emx();
    if ((inputs_arr == NULL) || (outputs_arr == NULL)) {
        FUZZY_PRINTF("fuzzy_runner_execute: ERROR - array creation failed!\r\n");
        if (inputs_arr != NULL) {
            emxDestroyArray_real_T(inputs_arr);
        }
        if (outputs_arr != NULL) {
            emxDestroyArray_real_T(outputs_arr);
        }
        return 0.0f;
    }

    FUZZY_PRINTF("fuzzy_runner_execute: calling opkene()\r\n");
    FUZZY_FFLUSH(); // Force output before calling opkene (only if debug enabled)
    opkene(s_file_name, inputs_arr, outputs_arr);
    FUZZY_PRINTF("fuzzy_runner_execute: opkene() completed\r\n");
    FUZZY_FFLUSH();

    uint32_t produced = (uint32_t)outputs_arr->size[1];
    FUZZY_PRINTF("fuzzy_runner_execute: outputs size=%u\r\n", (unsigned int)produced);

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

    FUZZY_PRINTF("fuzzy_runner_execute: returning result %.3f\r\n", first_output);
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

    memfile_release_slot(FIS_SLOT);
    s_fis_stream = NULL;

    s_ready = 0;
}
