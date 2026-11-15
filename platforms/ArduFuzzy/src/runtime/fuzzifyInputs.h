/*
 * File: fuzzifyInputs.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

#ifndef FUZZIFYINPUTS_H
#define FUZZIFYINPUTS_H

/* Include Files */
#include "opkene_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_fuzzifyInputs(double inputs, const emxArray_real_T *fis_antecedent,
                     const emxArray_real_T *fis_connection, int fis_numRules,
                     const emxArray_int32_T *fis_numInputMFs,
                     const emxArray_int32_T *fis_numCumInputMFs,
                     const emxArray_cell_wrap_0 *varargin_1,
                     emxArray_real_T *varargin_2, emxArray_real_T *varargin_3);

void fuzzifyInputs(const emxArray_real_T *inputs,
                   const emxArray_real_T *fis_antecedent,
                   const emxArray_real_T *fis_connection, int fis_numInputs,
                   int fis_numRules, const emxArray_int32_T *fis_numInputMFs,
                   const emxArray_int32_T *fis_numCumInputMFs,
                   const emxArray_cell_wrap_0 *varargin_1,
                   emxArray_real_T *varargin_2, emxArray_real_T *varargin_3);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for fuzzifyInputs.h
 *
 * [EOF]
 */
