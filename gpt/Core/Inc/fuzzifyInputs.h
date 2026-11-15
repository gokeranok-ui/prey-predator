/*
 * File: fuzzifyInputs.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

#ifndef FUZZIFYINPUTS_H
#define FUZZIFYINPUTS_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "opkene_types.h"

/* Function Declarations */
extern void b_fuzzifyInputs(double inputs, const emxArray_real_T *fis_antecedent,
  const emxArray_real_T *fis_connection, int fis_numRules, const
  emxArray_int32_T *fis_numInputMFs, const emxArray_int32_T *fis_numCumInputMFs,
  const emxArray_cell_wrap_0 *varargin_1, emxArray_real_T *varargin_2,
  emxArray_real_T *varargin_3);
extern void fuzzifyInputs(const emxArray_real_T *inputs, const emxArray_real_T
  *fis_antecedent, const emxArray_real_T *fis_connection, int fis_numInputs, int
  fis_numRules, const emxArray_int32_T *fis_numInputMFs, const emxArray_int32_T *
  fis_numCumInputMFs, const emxArray_cell_wrap_0 *varargin_1, emxArray_real_T
  *varargin_2, emxArray_real_T *varargin_3);

#endif

/*
 * File trailer for fuzzifyInputs.h
 *
 * [EOF]
 */
