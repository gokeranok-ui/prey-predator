/*
 * File: applyMamdaniAggregationMethod.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

#ifndef APPLYMAMDANIAGGREGATIONMETHOD_H
#define APPLYMAMDANIAGGREGATIONMETHOD_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "opkene_types.h"

/* Function Declarations */
extern void applyMamdaniAggregationMethod(const emxArray_real_T
  *consequentOutputs, const emxArray_uint8_T *fis_aggMethod, int fis_numOutputs,
  int fis_numRules, const int fis_aggSize[2], emxArray_real_T *aggregatedOutputs);

#endif

/*
 * File trailer for applyMamdaniAggregationMethod.h
 *
 * [EOF]
 */
