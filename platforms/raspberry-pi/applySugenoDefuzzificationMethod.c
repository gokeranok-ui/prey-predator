/*
 * File: applySugenoDefuzzificationMethod.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "applySugenoDefuzzificationMethod.h"
#include "opkene_emxutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double sumAntecedentOutputs
 *                const emxArray_real_T *aggregatedOutputs
 *                const emxArray_real_T *fis_outputRange
 *                int fis_numOutputs
 *                emxArray_real_T *defuzzifiedOutputs
 * Return Type  : void
 */
void c_applySugenoDefuzzificationMet(double sumAntecedentOutputs,
                                     const emxArray_real_T *aggregatedOutputs,
                                     const emxArray_real_T *fis_outputRange,
                                     int fis_numOutputs,
                                     emxArray_real_T *defuzzifiedOutputs)
{
  const double *aggregatedOutputs_data;
  const double *fis_outputRange_data;
  double *defuzzifiedOutputs_data;
  int i;
  int outputID;
  unsigned int u;
  fis_outputRange_data = fis_outputRange->data;
  aggregatedOutputs_data = aggregatedOutputs->data;
  i = defuzzifiedOutputs->size[0];
  defuzzifiedOutputs->size[0] = fis_numOutputs;
  emxEnsureCapacity_real_T(defuzzifiedOutputs, i);
  defuzzifiedOutputs_data = defuzzifiedOutputs->data;
  u = (unsigned int)fis_numOutputs;
  if ((unsigned int)fis_numOutputs > 2147483647UL) {
    u = 2147483647UL;
  }
  i = (int)u;
  for (outputID = 0; outputID < i; outputID++) {
    if (sumAntecedentOutputs == 0.0) {
      defuzzifiedOutputs_data[outputID] =
          (fis_outputRange_data[outputID] +
           fis_outputRange_data[outputID + fis_outputRange->size[0]]) /
          2.0;
    } else if (sumAntecedentOutputs == 0.0) {
      defuzzifiedOutputs_data[outputID] = (aggregatedOutputs_data[outputID] +
                                           aggregatedOutputs_data[outputID]) /
                                          2.0;
    } else {
      defuzzifiedOutputs_data[outputID] = aggregatedOutputs_data[outputID] *
                                          sumAntecedentOutputs *
                                          (1.0 / sumAntecedentOutputs);
    }
  }
}

/*
 * Arguments    : double sumAntecedentOutputs
 *                const emxArray_real_T *aggregatedOutputs
 *                const emxArray_real_T *fis_outputRange
 *                int fis_numOutputs
 *                emxArray_real_T *defuzzifiedOutputs
 * Return Type  : void
 */
void d_applySugenoDefuzzificationMet(double sumAntecedentOutputs,
                                     const emxArray_real_T *aggregatedOutputs,
                                     const emxArray_real_T *fis_outputRange,
                                     int fis_numOutputs,
                                     emxArray_real_T *defuzzifiedOutputs)
{
  const double *aggregatedOutputs_data;
  const double *fis_outputRange_data;
  double *defuzzifiedOutputs_data;
  int i;
  int outputID;
  unsigned int u;
  fis_outputRange_data = fis_outputRange->data;
  aggregatedOutputs_data = aggregatedOutputs->data;
  i = defuzzifiedOutputs->size[0];
  defuzzifiedOutputs->size[0] = fis_numOutputs;
  emxEnsureCapacity_real_T(defuzzifiedOutputs, i);
  defuzzifiedOutputs_data = defuzzifiedOutputs->data;
  u = (unsigned int)fis_numOutputs;
  if ((unsigned int)fis_numOutputs > 2147483647UL) {
    u = 2147483647UL;
  }
  i = (int)u;
  for (outputID = 0; outputID < i; outputID++) {
    if (sumAntecedentOutputs == 0.0) {
      defuzzifiedOutputs_data[outputID] =
          (fis_outputRange_data[outputID] +
           fis_outputRange_data[outputID + fis_outputRange->size[0]]) /
          2.0;
    } else if (sumAntecedentOutputs == 0.0) {
      defuzzifiedOutputs_data[outputID] = (aggregatedOutputs_data[outputID] +
                                           aggregatedOutputs_data[outputID]) /
                                          2.0;
    } else {
      defuzzifiedOutputs_data[outputID] = aggregatedOutputs_data[outputID];
    }
  }
}

/*
 * Arguments    : double sumAntecedentOutputs
 *                const emxArray_real_T *aggregatedOutputs
 *                const emxArray_real_T *fis_outputRange
 *                int fis_numOutputs
 *                emxArray_real_T *defuzzifiedOutputs
 * Return Type  : void
 */
void e_applySugenoDefuzzificationMet(double sumAntecedentOutputs,
                                     const emxArray_real_T *aggregatedOutputs,
                                     const emxArray_real_T *fis_outputRange,
                                     int fis_numOutputs,
                                     emxArray_real_T *defuzzifiedOutputs)
{
  const double *aggregatedOutputs_data;
  const double *fis_outputRange_data;
  double *defuzzifiedOutputs_data;
  int i;
  int outputID;
  unsigned int u;
  fis_outputRange_data = fis_outputRange->data;
  aggregatedOutputs_data = aggregatedOutputs->data;
  i = defuzzifiedOutputs->size[0];
  defuzzifiedOutputs->size[0] = fis_numOutputs;
  emxEnsureCapacity_real_T(defuzzifiedOutputs, i);
  defuzzifiedOutputs_data = defuzzifiedOutputs->data;
  u = (unsigned int)fis_numOutputs;
  if ((unsigned int)fis_numOutputs > 2147483647UL) {
    u = 2147483647UL;
  }
  i = (int)u;
  for (outputID = 0; outputID < i; outputID++) {
    if (sumAntecedentOutputs == 0.0) {
      defuzzifiedOutputs_data[outputID] =
          (fis_outputRange_data[outputID] +
           fis_outputRange_data[outputID + fis_outputRange->size[0]]) /
          2.0;
    } else {
      double maxValueInX;
      int maxValueIdsInX;
      maxValueInX = 0.0;
      maxValueIdsInX = 0;
      if (sumAntecedentOutputs == sumAntecedentOutputs) {
        maxValueInX = aggregatedOutputs_data[outputID];
        maxValueIdsInX = 1;
      }
      defuzzifiedOutputs_data[outputID] =
          maxValueInX * (1.0 / (double)maxValueIdsInX);
    }
  }
}

/*
 * File trailer for applySugenoDefuzzificationMethod.c
 *
 * [EOF]
 */
