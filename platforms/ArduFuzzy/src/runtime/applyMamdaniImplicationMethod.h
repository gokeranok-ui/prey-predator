/*
 * File: applyMamdaniImplicationMethod.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

#ifndef APPLYMAMDANIIMPLICATIONMETHOD_H
#define APPLYMAMDANIIMPLICATIONMETHOD_H

/* Include Files */
#include "opkene_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void applyMamdaniImplicationMethod(const emxArray_real_T *antecedentOutputs,
                                   const emxArray_uint8_T *fis_impMethod,
                                   const emxArray_real_T *fis_consequent,
                                   int fis_numOutputs, int fis_numRules,
                                   const emxArray_int32_T *fis_numCumOutputMFs,
                                   const int fis_orrSize[2],
                                   const emxArray_real_T *varargin_1,
                                   emxArray_real_T *consequentOutputs);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for applyMamdaniImplicationMethod.h
 *
 * [EOF]
 */
