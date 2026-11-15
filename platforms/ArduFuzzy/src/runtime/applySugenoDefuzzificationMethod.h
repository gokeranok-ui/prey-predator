/*
 * File: applySugenoDefuzzificationMethod.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

#ifndef APPLYSUGENODEFUZZIFICATIONMETHOD_H
#define APPLYSUGENODEFUZZIFICATIONMETHOD_H

/* Include Files */
#include "opkene_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void c_applySugenoDefuzzificationMet(double sumAntecedentOutputs,
                                     const emxArray_real_T *aggregatedOutputs,
                                     const emxArray_real_T *fis_outputRange,
                                     int fis_numOutputs,
                                     emxArray_real_T *defuzzifiedOutputs);

void d_applySugenoDefuzzificationMet(double sumAntecedentOutputs,
                                     const emxArray_real_T *aggregatedOutputs,
                                     const emxArray_real_T *fis_outputRange,
                                     int fis_numOutputs,
                                     emxArray_real_T *defuzzifiedOutputs);

void e_applySugenoDefuzzificationMet(double sumAntecedentOutputs,
                                     const emxArray_real_T *aggregatedOutputs,
                                     const emxArray_real_T *fis_outputRange,
                                     int fis_numOutputs,
                                     emxArray_real_T *defuzzifiedOutputs);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for applySugenoDefuzzificationMethod.h
 *
 * [EOF]
 */
