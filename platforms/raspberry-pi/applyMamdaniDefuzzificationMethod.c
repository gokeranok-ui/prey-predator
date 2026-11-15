/*
 * File: applyMamdaniDefuzzificationMethod.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "applyMamdaniDefuzzificationMethod.h"
#include "minOrMax.h"
#include "opkene_emxutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *outputSamplePoints
 *                double sumAntecedentOutputs
 *                const emxArray_real_T *aggregatedOutputs
 *                const emxArray_real_T *fis_outputRange
 *                int fis_numOutputs
 *                emxArray_real_T *defuzzifiedOutputs
 * Return Type  : void
 */
void c_applyMamdaniDefuzzificationMe(const emxArray_real_T *outputSamplePoints,
                                     double sumAntecedentOutputs,
                                     const emxArray_real_T *aggregatedOutputs,
                                     const emxArray_real_T *fis_outputRange,
                                     int fis_numOutputs,
                                     emxArray_real_T *defuzzifiedOutputs)
{
  const double *aggregatedOutputs_data;
  const double *fis_outputRange_data;
  const double *outputSamplePoints_data;
  double *defuzzifiedOutputs_data;
  int b_i;
  int i;
  int outputID;
  unsigned int u;
  fis_outputRange_data = fis_outputRange->data;
  aggregatedOutputs_data = aggregatedOutputs->data;
  outputSamplePoints_data = outputSamplePoints->data;
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
      double x_data[51];
      double area;
      double y;
      int n;
      int x_size;
      n = outputSamplePoints->size[1];
      x_size = outputSamplePoints->size[1];
      for (b_i = 0; b_i < n; b_i++) {
        x_data[b_i] =
            outputSamplePoints_data[outputID +
                                    outputSamplePoints->size[0] * b_i];
      }
      y = 0.0;
      area = 0.0;
      n = x_size - 1;
      for (b_i = 0; b_i <= n; b_i++) {
        area +=
            aggregatedOutputs_data[b_i + aggregatedOutputs->size[0] * outputID];
      }
      if (area == 0.0) {
        defuzzifiedOutputs_data[outputID] =
            (x_data[0] + x_data[x_size - 1]) / 2.0;
      } else {
        for (b_i = 0; b_i <= n; b_i++) {
          y += x_data[b_i] *
               aggregatedOutputs_data[b_i +
                                      aggregatedOutputs->size[0] * outputID];
        }
        defuzzifiedOutputs_data[outputID] = y * (1.0 / area);
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *outputSamplePoints
 *                double sumAntecedentOutputs
 *                const emxArray_real_T *aggregatedOutputs
 *                const emxArray_real_T *fis_outputRange
 *                int fis_numOutputs
 *                emxArray_real_T *defuzzifiedOutputs
 * Return Type  : void
 */
void d_applyMamdaniDefuzzificationMe(const emxArray_real_T *outputSamplePoints,
                                     double sumAntecedentOutputs,
                                     const emxArray_real_T *aggregatedOutputs,
                                     const emxArray_real_T *fis_outputRange,
                                     int fis_numOutputs,
                                     emxArray_real_T *defuzzifiedOutputs)
{
  emxArray_real_T c_aggregatedOutputs_data;
  double b_aggregatedOutputs_data[51];
  const double *aggregatedOutputs_data;
  const double *fis_outputRange_data;
  const double *outputSamplePoints_data;
  double *defuzzifiedOutputs_data;
  int aggregatedOutputs_size;
  int b_i;
  int i;
  int outputID;
  unsigned int u;
  fis_outputRange_data = fis_outputRange->data;
  aggregatedOutputs_data = aggregatedOutputs->data;
  outputSamplePoints_data = outputSamplePoints->data;
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
      double x_data[51];
      double area;
      int halfAreaID;
      int x_size;
      halfAreaID = outputSamplePoints->size[1];
      x_size = outputSamplePoints->size[1];
      for (b_i = 0; b_i < halfAreaID; b_i++) {
        x_data[b_i] =
            outputSamplePoints_data[outputID +
                                    outputSamplePoints->size[0] * b_i];
      }
      halfAreaID = aggregatedOutputs->size[0];
      aggregatedOutputs_size = aggregatedOutputs->size[0];
      for (b_i = 0; b_i < halfAreaID; b_i++) {
        b_aggregatedOutputs_data[b_i] =
            aggregatedOutputs_data[b_i + aggregatedOutputs->size[0] * outputID];
      }
      c_aggregatedOutputs_data.data = &b_aggregatedOutputs_data[0];
      c_aggregatedOutputs_data.size = &aggregatedOutputs_size;
      c_aggregatedOutputs_data.allocatedSize = 51;
      c_aggregatedOutputs_data.numDimensions = 1;
      c_aggregatedOutputs_data.canFreeData = false;
      area = b_sum(&c_aggregatedOutputs_data);
      if (area == 0.0) {
        defuzzifiedOutputs_data[outputID] =
            (x_data[0] + x_data[x_size - 1]) / 2.0;
      } else {
        double halfArea;
        boolean_T exitg1;
        halfArea = area / 2.0;
        halfAreaID = 0;
        area = 0.0;
        b_i = 0;
        exitg1 = false;
        while ((!exitg1) && (b_i <= x_size - 1)) {
          area += aggregatedOutputs_data[b_i +
                                         aggregatedOutputs->size[0] * outputID];
          if (area >= halfArea) {
            halfAreaID = b_i;
            exitg1 = true;
          } else {
            b_i++;
          }
        }
        defuzzifiedOutputs_data[outputID] = x_data[halfAreaID];
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *outputSamplePoints
 *                double sumAntecedentOutputs
 *                const emxArray_real_T *aggregatedOutputs
 *                const emxArray_real_T *fis_outputRange
 *                int fis_numOutputs
 *                emxArray_real_T *defuzzifiedOutputs
 * Return Type  : void
 */
void e_applyMamdaniDefuzzificationMe(const emxArray_real_T *outputSamplePoints,
                                     double sumAntecedentOutputs,
                                     const emxArray_real_T *aggregatedOutputs,
                                     const emxArray_real_T *fis_outputRange,
                                     int fis_numOutputs,
                                     emxArray_real_T *defuzzifiedOutputs)
{
  emxArray_real_T b_maxValueInX_data;
  double maxValueInX_data[51];
  const double *aggregatedOutputs_data;
  const double *fis_outputRange_data;
  const double *outputSamplePoints_data;
  double *defuzzifiedOutputs_data;
  int i;
  int i1;
  int loop_ub;
  int maxValueInX_size;
  int outputID;
  unsigned int u;
  signed char maxValueIdsInX_data[51];
  fis_outputRange_data = fis_outputRange->data;
  aggregatedOutputs_data = aggregatedOutputs->data;
  outputSamplePoints_data = outputSamplePoints->data;
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
      double x_data[51];
      double maxMFValue;
      double sumMaxValueIdsInX;
      double sumMaxValueInX;
      int x_size;
      loop_ub = outputSamplePoints->size[1];
      x_size = outputSamplePoints->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        x_data[i1] = outputSamplePoints_data[outputID +
                                             outputSamplePoints->size[0] * i1];
      }
      loop_ub = aggregatedOutputs->size[0];
      maxValueInX_size = aggregatedOutputs->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        maxValueInX_data[i1] =
            aggregatedOutputs_data[i1 + aggregatedOutputs->size[0] * outputID];
      }
      b_maxValueInX_data.data = &maxValueInX_data[0];
      b_maxValueInX_data.size = &maxValueInX_size;
      b_maxValueInX_data.allocatedSize = 51;
      b_maxValueInX_data.numDimensions = 1;
      b_maxValueInX_data.canFreeData = false;
      maxMFValue = maximum(&b_maxValueInX_data);
      maxValueInX_size = x_size;
      if (x_size - 1 >= 0) {
        memset(&maxValueInX_data[0], 0, (unsigned int)x_size * sizeof(double));
      }
      if (x_size - 1 >= 0) {
        memset(&maxValueIdsInX_data[0], 0,
               (unsigned int)x_size * sizeof(signed char));
      }
      sumMaxValueInX = 0.0;
      sumMaxValueIdsInX = 0.0;
      i1 = aggregatedOutputs->size[0];
      for (loop_ub = 0; loop_ub < i1; loop_ub++) {
        if (aggregatedOutputs_data[loop_ub + aggregatedOutputs->size[0] *
                                                 outputID] == maxMFValue) {
          maxValueInX_data[loop_ub] = x_data[loop_ub];
          maxValueIdsInX_data[loop_ub] = 1;
        }
        sumMaxValueInX += maxValueInX_data[loop_ub];
        sumMaxValueIdsInX += (double)maxValueIdsInX_data[loop_ub];
      }
      defuzzifiedOutputs_data[outputID] =
          sumMaxValueInX * (1.0 / sumMaxValueIdsInX);
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *outputSamplePoints
 *                double sumAntecedentOutputs
 *                const emxArray_real_T *aggregatedOutputs
 *                const emxArray_real_T *fis_outputRange
 *                int fis_numOutputs
 *                emxArray_real_T *defuzzifiedOutputs
 * Return Type  : void
 */
void f_applyMamdaniDefuzzificationMe(const emxArray_real_T *outputSamplePoints,
                                     double sumAntecedentOutputs,
                                     const emxArray_real_T *aggregatedOutputs,
                                     const emxArray_real_T *fis_outputRange,
                                     int fis_numOutputs,
                                     emxArray_real_T *defuzzifiedOutputs)
{
  const double *aggregatedOutputs_data;
  const double *fis_outputRange_data;
  const double *outputSamplePoints_data;
  double *defuzzifiedOutputs_data;
  int i;
  int i1;
  int loop_ub;
  int outputID;
  unsigned int u;
  fis_outputRange_data = fis_outputRange->data;
  aggregatedOutputs_data = aggregatedOutputs->data;
  outputSamplePoints_data = outputSamplePoints->data;
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
      double b_aggregatedOutputs_data[51];
      double x_data[51];
      double maxMFValue;
      double refX;
      double refX_tmp;
      int aggregatedOutputs_size;
      loop_ub = outputSamplePoints->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        x_data[i1] = outputSamplePoints_data[outputID +
                                             outputSamplePoints->size[0] * i1];
      }
      loop_ub = aggregatedOutputs->size[0];
      aggregatedOutputs_size = aggregatedOutputs->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_aggregatedOutputs_data[i1] =
            aggregatedOutputs_data[i1 + aggregatedOutputs->size[0] * outputID];
      }
      maxMFValue =
          b_maximum(b_aggregatedOutputs_data, aggregatedOutputs_size, &loop_ub);
      refX_tmp = x_data[loop_ub - 1];
      refX = fabs(refX_tmp);
      defuzzifiedOutputs_data[outputID] = refX_tmp;
      i1 = aggregatedOutputs->size[0];
      for (loop_ub = 0; loop_ub < i1; loop_ub++) {
        if (aggregatedOutputs_data[loop_ub + aggregatedOutputs->size[0] *
                                                 outputID] == maxMFValue) {
          double d;
          refX_tmp = x_data[loop_ub];
          d = fabs(refX_tmp);
          if (d < refX) {
            refX = d;
            defuzzifiedOutputs_data[outputID] = refX_tmp;
          }
        }
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *outputSamplePoints
 *                double sumAntecedentOutputs
 *                const emxArray_real_T *aggregatedOutputs
 *                const emxArray_real_T *fis_outputRange
 *                int fis_numOutputs
 *                emxArray_real_T *defuzzifiedOutputs
 * Return Type  : void
 */
void g_applyMamdaniDefuzzificationMe(const emxArray_real_T *outputSamplePoints,
                                     double sumAntecedentOutputs,
                                     const emxArray_real_T *aggregatedOutputs,
                                     const emxArray_real_T *fis_outputRange,
                                     int fis_numOutputs,
                                     emxArray_real_T *defuzzifiedOutputs)
{
  const double *aggregatedOutputs_data;
  const double *fis_outputRange_data;
  const double *outputSamplePoints_data;
  double *defuzzifiedOutputs_data;
  int i;
  int i1;
  int loop_ub;
  int outputID;
  unsigned int u;
  fis_outputRange_data = fis_outputRange->data;
  aggregatedOutputs_data = aggregatedOutputs->data;
  outputSamplePoints_data = outputSamplePoints->data;
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
      double b_aggregatedOutputs_data[51];
      double x_data[51];
      double maxMFValue;
      double refX;
      double refX_tmp;
      int aggregatedOutputs_size;
      loop_ub = outputSamplePoints->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        x_data[i1] = outputSamplePoints_data[outputID +
                                             outputSamplePoints->size[0] * i1];
      }
      loop_ub = aggregatedOutputs->size[0];
      aggregatedOutputs_size = aggregatedOutputs->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_aggregatedOutputs_data[i1] =
            aggregatedOutputs_data[i1 + aggregatedOutputs->size[0] * outputID];
      }
      maxMFValue =
          b_maximum(b_aggregatedOutputs_data, aggregatedOutputs_size, &loop_ub);
      refX_tmp = x_data[loop_ub - 1];
      refX = fabs(refX_tmp);
      defuzzifiedOutputs_data[outputID] = refX_tmp;
      i1 = aggregatedOutputs->size[0];
      for (loop_ub = 0; loop_ub < i1; loop_ub++) {
        if (aggregatedOutputs_data[loop_ub + aggregatedOutputs->size[0] *
                                                 outputID] == maxMFValue) {
          double d;
          refX_tmp = x_data[loop_ub];
          d = fabs(refX_tmp);
          if (d > refX) {
            refX = d;
            defuzzifiedOutputs_data[outputID] = refX_tmp;
          }
        }
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *outputSamplePoints
 *                double sumAntecedentOutputs
 *                const emxArray_real_T *aggregatedOutputs
 *                const emxArray_real_T *fis_outputRange
 *                int fis_numOutputs
 *                emxArray_real_T *defuzzifiedOutputs
 * Return Type  : void
 */
void h_applyMamdaniDefuzzificationMe(const emxArray_real_T *outputSamplePoints,
                                     double sumAntecedentOutputs,
                                     const emxArray_real_T *aggregatedOutputs,
                                     const emxArray_real_T *fis_outputRange,
                                     int fis_numOutputs,
                                     emxArray_real_T *defuzzifiedOutputs)
{
  double Y_data[51];
  double vn1_data[51];
  const double *aggregatedOutputs_data;
  const double *fis_outputRange_data;
  const double *outputSamplePoints_data;
  double *defuzzifiedOutputs_data;
  int i;
  int i1;
  int k;
  int loop_ub;
  int outputID;
  unsigned int u;
  fis_outputRange_data = fis_outputRange->data;
  aggregatedOutputs_data = aggregatedOutputs->data;
  outputSamplePoints_data = outputSamplePoints->data;
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
      double b_outputSamplePoints_data[2601];
      int Y_size_idx_1;
      int pvt;
      loop_ub = aggregatedOutputs->size[0];
      if (aggregatedOutputs->size[0] == 1) {
        Y_size_idx_1 = 1;
        Y_data[0] =
            1.0 / aggregatedOutputs_data[aggregatedOutputs->size[0] * outputID];
      } else {
        double smax;
        double tol_tmp;
        signed char jpvt_data[51];
        Y_size_idx_1 = aggregatedOutputs->size[0];
        for (k = 0; k < loop_ub; k++) {
          tol_tmp =
              aggregatedOutputs_data[k + aggregatedOutputs->size[0] * outputID];
          Y_data[k] = tol_tmp;
          jpvt_data[k] = (signed char)(k + 1);
          vn1_data[k] = fabs(tol_tmp);
        }
        pvt = 0;
        smax = vn1_data[0];
        for (k = 2; k <= loop_ub; k++) {
          tol_tmp = vn1_data[k - 1];
          if (tol_tmp > smax) {
            pvt = k - 1;
            smax = tol_tmp;
          }
        }
        if (pvt + 1 != 1) {
          Y_data[0] = Y_data[pvt];
          jpvt_data[0] = jpvt_data[pvt];
        }
        pvt = 0;
        tol_tmp = fabs(Y_data[0]);
        if (!(tol_tmp <=
              2.2204460492503131E-15 * (double)Y_size_idx_1 * tol_tmp)) {
          pvt = 1;
        }
        if (Y_size_idx_1 - 1 >= 0) {
          memset(&vn1_data[0], 0, (unsigned int)Y_size_idx_1 * sizeof(double));
        }
        if (pvt - 1 >= 0) {
          vn1_data[jpvt_data[0] - 1] = 1.0;
        }
        for (loop_ub = pvt; loop_ub >= 1; loop_ub--) {
          vn1_data[jpvt_data[0] - 1] /= Y_data[0];
        }
        if (Y_size_idx_1 - 1 >= 0) {
          memcpy(&Y_data[0], &vn1_data[0],
                 (unsigned int)Y_size_idx_1 * sizeof(double));
        }
      }
      pvt = outputSamplePoints->size[1];
      for (k = 0; k < Y_size_idx_1; k++) {
        loop_ub = outputSamplePoints->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_outputSamplePoints_data[i1 + pvt * k] =
              outputSamplePoints_data[outputID +
                                      outputSamplePoints->size[0] * i1] *
              Y_data[k];
        }
      }
      defuzzifiedOutputs_data[outputID] = b_outputSamplePoints_data[0];
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *outputSamplePoints
 *                double sumAntecedentOutputs
 *                const emxArray_real_T *fis_outputRange
 *                int fis_numOutputs
 *                emxArray_real_T *defuzzifiedOutputs
 * Return Type  : void
 */
void i_applyMamdaniDefuzzificationMe(const emxArray_real_T *outputSamplePoints,
                                     double sumAntecedentOutputs,
                                     const emxArray_real_T *fis_outputRange,
                                     int fis_numOutputs,
                                     emxArray_real_T *defuzzifiedOutputs)
{
  const double *fis_outputRange_data;
  const double *outputSamplePoints_data;
  double *defuzzifiedOutputs_data;
  int i;
  int outputID;
  unsigned int u;
  fis_outputRange_data = fis_outputRange->data;
  outputSamplePoints_data = outputSamplePoints->data;
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
      defuzzifiedOutputs_data[outputID] = outputSamplePoints_data[outputID];
    }
  }
}

/*
 * File trailer for applyMamdaniDefuzzificationMethod.c
 *
 * [EOF]
 */
