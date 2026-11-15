/*
 * File: applySugenoImplicationMethod.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

#ifndef APPLYSUGENOIMPLICATIONMETHOD_H
#define APPLYSUGENOIMPLICATIONMETHOD_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "opkene_types.h"

/* Function Declarations */
extern void applySugenoImplicationMethod(const emxArray_real_T *inputs, const
  emxArray_real_T *antecedentOutputs, const d_emxArray_struct_T *fis_outputMF,
  const emxArray_real_T *fis_consequent, int fis_numOutputs, int fis_numRules,
  const emxArray_int32_T *fis_numOutputMFs, const emxArray_int32_T
  *fis_numCumOutputMFs, const int fis_orrSize[2], emxArray_real_T
  *consequentOutputs, emxArray_real_T *unscaledOutputs);
extern void b_applySugenoImplicationMethod(double inputs, const emxArray_real_T *
  antecedentOutputs, const d_emxArray_struct_T *fis_outputMF, const
  emxArray_real_T *fis_consequent, int fis_numOutputs, int fis_numRules, const
  emxArray_int32_T *fis_numOutputMFs, const emxArray_int32_T
  *fis_numCumOutputMFs, const int fis_orrSize[2], emxArray_real_T
  *consequentOutputs, emxArray_real_T *unscaledOutputs);

#endif

/*
 * File trailer for applySugenoImplicationMethod.h
 *
 * [EOF]
 */
