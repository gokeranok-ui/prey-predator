/*
 * File: applySugenoDefuzzificationMethod.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "applySugenoDefuzzificationMethod.h"
#include "opkene_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : double sumAntecedentOutputs
 *                const emxArray_real_T *aggregatedOutputs
 *                const emxArray_real_T *fis_outputRange
 *                int fis_numOutputs
 *                emxArray_real_T *defuzzifiedOutputs
 * Return Type  : void
 */
void c_applySugenoDefuzzificationMet(double sumAntecedentOutputs, const
  emxArray_real_T *aggregatedOutputs, const emxArray_real_T *fis_outputRange,
  int fis_numOutputs, emxArray_real_T *defuzzifiedOutputs)
{
  int outputID;
  double x_idx_0;
  double x_idx_1;
  outputID = defuzzifiedOutputs->size[0];
  defuzzifiedOutputs->size[0] = fis_numOutputs;
  emxEnsureCapacity_real_T(defuzzifiedOutputs, outputID);
  for (outputID = 0; outputID < fis_numOutputs; outputID++) {
    if (sumAntecedentOutputs == 0.0) {
      defuzzifiedOutputs->data[outputID] = (fis_outputRange->data[outputID] +
        fis_outputRange->data[outputID + fis_outputRange->size[0]]) / 2.0;
    } else if (sumAntecedentOutputs == 0.0) {
      x_idx_0 = aggregatedOutputs->data[outputID];
      x_idx_1 = aggregatedOutputs->data[outputID];
      defuzzifiedOutputs->data[outputID] = (x_idx_0 + x_idx_1) / 2.0;
    } else {
      defuzzifiedOutputs->data[outputID] = aggregatedOutputs->data[outputID] *
        sumAntecedentOutputs * (1.0 / sumAntecedentOutputs);
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
void d_applySugenoDefuzzificationMet(double sumAntecedentOutputs, const
  emxArray_real_T *aggregatedOutputs, const emxArray_real_T *fis_outputRange,
  int fis_numOutputs, emxArray_real_T *defuzzifiedOutputs)
{
  int outputID;
  double x_idx_0;
  double x_idx_1;
  outputID = defuzzifiedOutputs->size[0];
  defuzzifiedOutputs->size[0] = fis_numOutputs;
  emxEnsureCapacity_real_T(defuzzifiedOutputs, outputID);
  for (outputID = 0; outputID < fis_numOutputs; outputID++) {
    if (sumAntecedentOutputs == 0.0) {
      defuzzifiedOutputs->data[outputID] = (fis_outputRange->data[outputID] +
        fis_outputRange->data[outputID + fis_outputRange->size[0]]) / 2.0;
    } else if (sumAntecedentOutputs == 0.0) {
      x_idx_0 = aggregatedOutputs->data[outputID];
      x_idx_1 = aggregatedOutputs->data[outputID];
      defuzzifiedOutputs->data[outputID] = (x_idx_0 + x_idx_1) / 2.0;
    } else {
      defuzzifiedOutputs->data[outputID] = aggregatedOutputs->data[outputID];
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
void e_applySugenoDefuzzificationMet(double sumAntecedentOutputs, const
  emxArray_real_T *aggregatedOutputs, const emxArray_real_T *fis_outputRange,
  int fis_numOutputs, emxArray_real_T *defuzzifiedOutputs)
{
  int outputID;
  double maxValueInX;
  int maxValueIdsInX;
  outputID = defuzzifiedOutputs->size[0];
  defuzzifiedOutputs->size[0] = fis_numOutputs;
  emxEnsureCapacity_real_T(defuzzifiedOutputs, outputID);
  for (outputID = 0; outputID < fis_numOutputs; outputID++) {
    if (sumAntecedentOutputs == 0.0) {
      defuzzifiedOutputs->data[outputID] = (fis_outputRange->data[outputID] +
        fis_outputRange->data[outputID + fis_outputRange->size[0]]) / 2.0;
    } else {
      maxValueInX = 0.0;
      maxValueIdsInX = 0;
      if (sumAntecedentOutputs == sumAntecedentOutputs) {
        maxValueInX = aggregatedOutputs->data[outputID];
        maxValueIdsInX = 1;
      }

      defuzzifiedOutputs->data[outputID] = maxValueInX * (1.0 / (double)
        maxValueIdsInX);
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
void f_applySugenoDefuzzificationMet(double sumAntecedentOutputs, const
  emxArray_real_T *aggregatedOutputs, const emxArray_real_T *fis_outputRange,
  int fis_numOutputs, emxArray_real_T *defuzzifiedOutputs)
{
  int outputID;
  outputID = defuzzifiedOutputs->size[0];
  defuzzifiedOutputs->size[0] = fis_numOutputs;
  emxEnsureCapacity_real_T(defuzzifiedOutputs, outputID);
  for (outputID = 0; outputID < fis_numOutputs; outputID++) {
    if (sumAntecedentOutputs == 0.0) {
      defuzzifiedOutputs->data[outputID] = (fis_outputRange->data[outputID] +
        fis_outputRange->data[outputID + fis_outputRange->size[0]]) / 2.0;
    } else {
      defuzzifiedOutputs->data[outputID] = aggregatedOutputs->data[outputID];
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
void g_applySugenoDefuzzificationMet(double sumAntecedentOutputs, const
  emxArray_real_T *aggregatedOutputs, const emxArray_real_T *fis_outputRange,
  int fis_numOutputs, emxArray_real_T *defuzzifiedOutputs)
{
  int outputID;
  outputID = defuzzifiedOutputs->size[0];
  defuzzifiedOutputs->size[0] = fis_numOutputs;
  emxEnsureCapacity_real_T(defuzzifiedOutputs, outputID);
  for (outputID = 0; outputID < fis_numOutputs; outputID++) {
    if (sumAntecedentOutputs == 0.0) {
      defuzzifiedOutputs->data[outputID] = (fis_outputRange->data[outputID] +
        fis_outputRange->data[outputID + fis_outputRange->size[0]]) / 2.0;
    } else {
      defuzzifiedOutputs->data[outputID] = aggregatedOutputs->data[outputID] *
        (1.0 / sumAntecedentOutputs);
    }
  }
}

/*
 * File trailer for applySugenoDefuzzificationMethod.c
 *
 * [EOF]
 */
