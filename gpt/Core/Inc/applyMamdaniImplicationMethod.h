/*
 * File: applyMamdaniImplicationMethod.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

#ifndef APPLYMAMDANIIMPLICATIONMETHOD_H
#define APPLYMAMDANIIMPLICATIONMETHOD_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "opkene_types.h"

/* Function Declarations */
extern void applyMamdaniImplicationMethod(const emxArray_real_T
  *antecedentOutputs, const emxArray_uint8_T *fis_impMethod, const
  emxArray_real_T *fis_consequent, int fis_numOutputs, int fis_numRules, const
  emxArray_int32_T *fis_numCumOutputMFs, const int fis_orrSize[2], const
  emxArray_real_T *varargin_1, emxArray_real_T *consequentOutputs);

#endif

/*
 * File trailer for applyMamdaniImplicationMethod.h
 *
 * [EOF]
 */
