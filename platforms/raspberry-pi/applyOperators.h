/*
 * File: applyOperators.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

#ifndef APPLYOPERATORS_H
#define APPLYOPERATORS_H

/* Include Files */
#include "opkene_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double applyOperators(const emxArray_real_T *fuzzifiedInputs,
                      const emxArray_uint8_T *fis_andMethod,
                      const emxArray_uint8_T *fis_orMethod,
                      const emxArray_real_T *fis_connection,
                      const emxArray_real_T *fis_weight, int fis_numInputs,
                      int fis_numRules, emxArray_real_T *varargin_1,
                      emxArray_real_T *varargin_2);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for applyOperators.h
 *
 * [EOF]
 */
