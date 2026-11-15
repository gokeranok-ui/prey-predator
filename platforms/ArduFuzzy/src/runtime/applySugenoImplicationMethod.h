/*
 * File: applySugenoImplicationMethod.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

#ifndef APPLYSUGENOIMPLICATIONMETHOD_H
#define APPLYSUGENOIMPLICATIONMETHOD_H

/* Include Files */
#include "opkene_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void applySugenoImplicationMethod(
    const emxArray_real_T *inputs, const emxArray_real_T *antecedentOutputs,
    const e_emxArray_struct_T *fis_outputMF,
    const emxArray_real_T *fis_consequent, int fis_numOutputs, int fis_numRules,
    const emxArray_int32_T *fis_numOutputMFs,
    const emxArray_int32_T *fis_numCumOutputMFs, const int fis_orrSize[2],
    emxArray_real_T *consequentOutputs, emxArray_real_T *unscaledOutputs);

void b_applySugenoImplicationMethod(
    double inputs, const emxArray_real_T *antecedentOutputs,
    const e_emxArray_struct_T *fis_outputMF,
    const emxArray_real_T *fis_consequent, int fis_numOutputs, int fis_numRules,
    const emxArray_int32_T *fis_numOutputMFs,
    const emxArray_int32_T *fis_numCumOutputMFs, const int fis_orrSize[2],
    emxArray_real_T *consequentOutputs, emxArray_real_T *unscaledOutputs);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for applySugenoImplicationMethod.h
 *
 * [EOF]
 */
