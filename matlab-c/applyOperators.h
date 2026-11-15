/*
 * File: applyOperators.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

#ifndef APPLYOPERATORS_H
#define APPLYOPERATORS_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "opkene_types.h"

/* Function Declarations */
extern double applyOperators(const emxArray_real_T *fuzzifiedInputs, const
  emxArray_uint8_T *fis_andMethod, const emxArray_uint8_T *fis_orMethod, const
  emxArray_real_T *fis_connection, const emxArray_real_T *fis_weight, int
  fis_numInputs, int fis_numRules, emxArray_real_T *varargin_1, emxArray_real_T *
  varargin_2);

#endif

/*
 * File trailer for applyOperators.h
 *
 * [EOF]
 */
