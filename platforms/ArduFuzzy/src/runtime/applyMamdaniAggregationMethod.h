/*
 * File: applyMamdaniAggregationMethod.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

#ifndef APPLYMAMDANIAGGREGATIONMETHOD_H
#define APPLYMAMDANIAGGREGATIONMETHOD_H

/* Include Files */
#include "opkene_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void applyMamdaniAggregationMethod(const emxArray_real_T *consequentOutputs,
                                   const emxArray_uint8_T *fis_aggMethod,
                                   int fis_numOutputs, int fis_numRules,
                                   const int fis_aggSize[2],
                                   emxArray_real_T *aggregatedOutputs);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for applyMamdaniAggregationMethod.h
 *
 * [EOF]
 */
