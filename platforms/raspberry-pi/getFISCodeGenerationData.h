/*
 * File: getFISCodeGenerationData.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

#ifndef GETFISCODEGENERATIONDATA_H
#define GETFISCODEGENERATIONDATA_H

/* Include Files */
#include "opkene_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void getFISCodeGenerationData(
    const emxArray_char_T *name, emxArray_char_T *fis_name,
    emxArray_char_T *fis_type, emxArray_char_T *fis_andMethod,
    emxArray_char_T *fis_orMethod, emxArray_char_T *fis_defuzzMethod,
    emxArray_char_T *fis_impMethod, emxArray_char_T *fis_aggMethod,
    b_emxArray_struct_T *fis_input, b_emxArray_struct_T *fis_output,
    c_emxArray_struct_T *fis_rule);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for getFISCodeGenerationData.h
 *
 * [EOF]
 */
