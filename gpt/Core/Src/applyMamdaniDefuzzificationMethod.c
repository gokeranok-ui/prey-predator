/*
 * File: applyMamdaniDefuzzificationMethod.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include <math.h>
#include "opkene.h"
#include "applyMamdaniDefuzzificationMethod.h"
#include "sum.h"
#include "opkene_emxutil.h"
#include "mrdivide_helper.h"

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
  double sumAntecedentOutputs, const emxArray_real_T *aggregatedOutputs, const
  emxArray_real_T *fis_outputRange, int fis_numOutputs, emxArray_real_T
  *defuzzifiedOutputs)
{
  int i77;
  int outputID;
  double y;
  int loop_ub;
  int aggregatedOutputs_size[1];
  emxArray_real_T aggregatedOutputs_data;
  double b_aggregatedOutputs_data[51];
  double area;
  i77 = defuzzifiedOutputs->size[0];
  defuzzifiedOutputs->size[0] = fis_numOutputs;
  emxEnsureCapacity_real_T(defuzzifiedOutputs, i77);
  for (outputID = 0; outputID < fis_numOutputs; outputID++) {
    if (sumAntecedentOutputs == 0.0) {
      defuzzifiedOutputs->data[outputID] = (fis_outputRange->data[outputID] +
        fis_outputRange->data[outputID + fis_outputRange->size[0]]) / 2.0;
    } else {
      y = 0.0;
      loop_ub = aggregatedOutputs->size[0];
      aggregatedOutputs_size[0] = loop_ub;
      for (i77 = 0; i77 < loop_ub; i77++) {
        b_aggregatedOutputs_data[i77] = aggregatedOutputs->data[i77 +
          aggregatedOutputs->size[0] * outputID];
      }

      aggregatedOutputs_data.data = &b_aggregatedOutputs_data[0];
      aggregatedOutputs_data.size = &aggregatedOutputs_size[0];
      aggregatedOutputs_data.allocatedSize = 51;
      aggregatedOutputs_data.numDimensions = 1;
      aggregatedOutputs_data.canFreeData = false;
      area = b_sum(&aggregatedOutputs_data);
      if (area == 0.0) {
        i77 = outputSamplePoints->size[1];
        y = outputSamplePoints->data[outputID];
        area = outputSamplePoints->data[outputID + outputSamplePoints->size[0] *
          (i77 - 1)];
        defuzzifiedOutputs->data[outputID] = (y + area) / 2.0;
      } else {
        i77 = outputSamplePoints->size[1];
        for (loop_ub = 0; loop_ub < i77; loop_ub++) {
          y += outputSamplePoints->data[outputID + outputSamplePoints->size[0] *
            loop_ub] * aggregatedOutputs->data[loop_ub + aggregatedOutputs->
            size[0] * outputID];
        }

        defuzzifiedOutputs->data[outputID] = y * (1.0 / area);
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
  double sumAntecedentOutputs, const emxArray_real_T *aggregatedOutputs, const
  emxArray_real_T *fis_outputRange, int fis_numOutputs, emxArray_real_T
  *defuzzifiedOutputs)
{
  int i78;
  int outputID;
  int halfAreaID;
  int aggregatedOutputs_size[1];
  emxArray_real_T aggregatedOutputs_data;
  double b_aggregatedOutputs_data[51];
  double area;
  double halfArea;
  int i;
  int exitg1;
  i78 = defuzzifiedOutputs->size[0];
  defuzzifiedOutputs->size[0] = fis_numOutputs;
  emxEnsureCapacity_real_T(defuzzifiedOutputs, i78);
  for (outputID = 0; outputID < fis_numOutputs; outputID++) {
    if (sumAntecedentOutputs == 0.0) {
      defuzzifiedOutputs->data[outputID] = (fis_outputRange->data[outputID] +
        fis_outputRange->data[outputID + fis_outputRange->size[0]]) / 2.0;
    } else {
      halfAreaID = aggregatedOutputs->size[0];
      aggregatedOutputs_size[0] = halfAreaID;
      for (i78 = 0; i78 < halfAreaID; i78++) {
        b_aggregatedOutputs_data[i78] = aggregatedOutputs->data[i78 +
          aggregatedOutputs->size[0] * outputID];
      }

      aggregatedOutputs_data.data = &b_aggregatedOutputs_data[0];
      aggregatedOutputs_data.size = &aggregatedOutputs_size[0];
      aggregatedOutputs_data.allocatedSize = 51;
      aggregatedOutputs_data.numDimensions = 1;
      aggregatedOutputs_data.canFreeData = false;
      area = b_sum(&aggregatedOutputs_data);
      if (area == 0.0) {
        i78 = outputSamplePoints->size[1];
        area = outputSamplePoints->data[outputID];
        halfArea = outputSamplePoints->data[outputID + outputSamplePoints->size
          [0] * (i78 - 1)];
        defuzzifiedOutputs->data[outputID] = (area + halfArea) / 2.0;
      } else {
        halfArea = area / 2.0;
        halfAreaID = 0;
        area = 0.0;
        i = 0;
        do {
          exitg1 = 0;
          i78 = outputSamplePoints->size[1] - 1;
          if (i <= i78) {
            area += aggregatedOutputs->data[i + aggregatedOutputs->size[0] *
              outputID];
            if (area >= halfArea) {
              halfAreaID = i;
              exitg1 = 1;
            } else {
              i++;
            }
          } else {
            exitg1 = 1;
          }
        } while (exitg1 == 0);

        defuzzifiedOutputs->data[outputID] = outputSamplePoints->data[outputID +
          outputSamplePoints->size[0] * halfAreaID];
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
  double sumAntecedentOutputs, const emxArray_real_T *aggregatedOutputs, const
  emxArray_real_T *fis_outputRange, int fis_numOutputs, emxArray_real_T
  *defuzzifiedOutputs)
{
  int i79;
  int outputID;
  int loop_ub;
  double membershipValueOfX_data[51];
  int idx;
  int k;
  double maxMFValue;
  int exitg1;
  signed char unnamed_idx_1;
  double sumMaxValueInX;
  double maxValueInX_data[51];
  signed char maxValueIdsInX_data[51];
  double sumMaxValueIdsInX;
  double b_maxValueInX_data;
  i79 = defuzzifiedOutputs->size[0];
  defuzzifiedOutputs->size[0] = fis_numOutputs;
  emxEnsureCapacity_real_T(defuzzifiedOutputs, i79);
  for (outputID = 0; outputID < fis_numOutputs; outputID++) {
    if (sumAntecedentOutputs == 0.0) {
      defuzzifiedOutputs->data[outputID] = (fis_outputRange->data[outputID] +
        fis_outputRange->data[outputID + fis_outputRange->size[0]]) / 2.0;
    } else {
      loop_ub = aggregatedOutputs->size[0];
      for (i79 = 0; i79 < loop_ub; i79++) {
        membershipValueOfX_data[i79] = aggregatedOutputs->data[i79 +
          aggregatedOutputs->size[0] * outputID];
      }

      i79 = aggregatedOutputs->size[0];
      loop_ub = aggregatedOutputs->size[0];
      if (loop_ub <= 2) {
        i79 = aggregatedOutputs->size[0];
        if (i79 == 1) {
          maxMFValue = membershipValueOfX_data[0];
        } else if ((membershipValueOfX_data[0] < membershipValueOfX_data[1]) ||
                   (rtIsNaN(membershipValueOfX_data[0]) && (!rtIsNaN
                     (membershipValueOfX_data[1])))) {
          maxMFValue = membershipValueOfX_data[1];
        } else {
          maxMFValue = membershipValueOfX_data[0];
        }
      } else {
        if (!rtIsNaN(membershipValueOfX_data[0])) {
          idx = 1;
        } else {
          idx = 0;
          k = 2;
          do {
            exitg1 = 0;
            loop_ub = aggregatedOutputs->size[0];
            if (k <= loop_ub) {
              if (!rtIsNaN(membershipValueOfX_data[k - 1])) {
                idx = k;
                exitg1 = 1;
              } else {
                k++;
              }
            } else {
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (idx == 0) {
          maxMFValue = membershipValueOfX_data[0];
        } else {
          maxMFValue = membershipValueOfX_data[idx - 1];
          loop_ub = idx + 1;
          for (k = loop_ub; k <= i79; k++) {
            sumMaxValueInX = membershipValueOfX_data[k - 1];
            if (maxMFValue < sumMaxValueInX) {
              maxMFValue = sumMaxValueInX;
            }
          }
        }
      }

      loop_ub = outputSamplePoints->size[1];
      unnamed_idx_1 = (signed char)loop_ub;
      if (0 <= unnamed_idx_1 - 1) {
        memset(&maxValueInX_data[0], 0, (unsigned int)(unnamed_idx_1 * (int)
                sizeof(double)));
      }

      loop_ub = outputSamplePoints->size[1];
      unnamed_idx_1 = (signed char)loop_ub;
      if (0 <= unnamed_idx_1 - 1) {
        memset(&maxValueIdsInX_data[0], 0, (unsigned int)(unnamed_idx_1 * (int)
                sizeof(signed char)));
      }

      sumMaxValueInX = 0.0;
      sumMaxValueIdsInX = 0.0;
      i79 = aggregatedOutputs->size[0];
      for (loop_ub = 0; loop_ub < i79; loop_ub++) {
        unnamed_idx_1 = maxValueIdsInX_data[loop_ub];
        b_maxValueInX_data = maxValueInX_data[loop_ub];
        if (aggregatedOutputs->data[loop_ub + aggregatedOutputs->size[0] *
            outputID] == maxMFValue) {
          b_maxValueInX_data = outputSamplePoints->data[outputID +
            outputSamplePoints->size[0] * loop_ub];
          unnamed_idx_1 = 1;
        }

        sumMaxValueInX += b_maxValueInX_data;
        sumMaxValueIdsInX += (double)unnamed_idx_1;
        maxValueInX_data[loop_ub] = b_maxValueInX_data;
        maxValueIdsInX_data[loop_ub] = unnamed_idx_1;
      }

      defuzzifiedOutputs->data[outputID] = sumMaxValueInX * (1.0 /
        sumMaxValueIdsInX);
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
  double sumAntecedentOutputs, const emxArray_real_T *aggregatedOutputs, const
  emxArray_real_T *fis_outputRange, int fis_numOutputs, emxArray_real_T
  *defuzzifiedOutputs)
{
  int i80;
  int outputID;
  int loop_ub;
  double membershipValueOfX_data[51];
  int idx;
  int k;
  double maxMFValue;
  int exitg1;
  double d8;
  double y_data[51];
  double refX;
  boolean_T exitg2;
  i80 = defuzzifiedOutputs->size[0];
  defuzzifiedOutputs->size[0] = fis_numOutputs;
  emxEnsureCapacity_real_T(defuzzifiedOutputs, i80);
  for (outputID = 0; outputID < fis_numOutputs; outputID++) {
    if (sumAntecedentOutputs == 0.0) {
      defuzzifiedOutputs->data[outputID] = (fis_outputRange->data[outputID] +
        fis_outputRange->data[outputID + fis_outputRange->size[0]]) / 2.0;
    } else {
      loop_ub = aggregatedOutputs->size[0];
      for (i80 = 0; i80 < loop_ub; i80++) {
        membershipValueOfX_data[i80] = aggregatedOutputs->data[i80 +
          aggregatedOutputs->size[0] * outputID];
      }

      i80 = aggregatedOutputs->size[0];
      loop_ub = aggregatedOutputs->size[0];
      if (loop_ub <= 2) {
        i80 = aggregatedOutputs->size[0];
        if (i80 == 1) {
          maxMFValue = membershipValueOfX_data[0];
        } else if ((membershipValueOfX_data[0] < membershipValueOfX_data[1]) ||
                   (rtIsNaN(membershipValueOfX_data[0]) && (!rtIsNaN
                     (membershipValueOfX_data[1])))) {
          maxMFValue = membershipValueOfX_data[1];
        } else {
          maxMFValue = membershipValueOfX_data[0];
        }
      } else {
        if (!rtIsNaN(membershipValueOfX_data[0])) {
          idx = 1;
        } else {
          idx = 0;
          k = 2;
          do {
            exitg1 = 0;
            loop_ub = aggregatedOutputs->size[0];
            if (k <= loop_ub) {
              if (!rtIsNaN(membershipValueOfX_data[k - 1])) {
                idx = k;
                exitg1 = 1;
              } else {
                k++;
              }
            } else {
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (idx == 0) {
          maxMFValue = membershipValueOfX_data[0];
        } else {
          maxMFValue = membershipValueOfX_data[idx - 1];
          loop_ub = idx + 1;
          for (k = loop_ub; k <= i80; k++) {
            d8 = membershipValueOfX_data[k - 1];
            if (maxMFValue < d8) {
              maxMFValue = d8;
            }
          }
        }
      }

      i80 = outputSamplePoints->size[1];
      loop_ub = outputSamplePoints->size[1];
      for (k = 0; k < i80; k++) {
        y_data[k] = fabs(outputSamplePoints->data[outputID +
                         outputSamplePoints->size[0] * k]);
      }

      i80 = (signed char)loop_ub;
      if ((signed char)loop_ub <= 2) {
        if ((signed char)loop_ub == 1) {
          refX = y_data[0];
          idx = 1;
        } else if ((y_data[0] < y_data[1]) || (rtIsNaN(y_data[0]) && (!rtIsNaN
                     (y_data[1])))) {
          refX = y_data[1];
          idx = 2;
        } else {
          refX = y_data[0];
          idx = 1;
        }
      } else {
        if (!rtIsNaN(y_data[0])) {
          idx = 1;
        } else {
          idx = 0;
          k = 2;
          exitg2 = false;
          while ((!exitg2) && (k <= (signed char)loop_ub)) {
            if (!rtIsNaN(y_data[k - 1])) {
              idx = k;
              exitg2 = true;
            } else {
              k++;
            }
          }
        }

        if (idx == 0) {
          refX = y_data[0];
          idx = 1;
        } else {
          refX = y_data[idx - 1];
          loop_ub = idx + 1;
          for (k = loop_ub; k <= i80; k++) {
            d8 = y_data[k - 1];
            if (refX < d8) {
              refX = d8;
              idx = k;
            }
          }
        }
      }

      defuzzifiedOutputs->data[outputID] = outputSamplePoints->data[outputID +
        outputSamplePoints->size[0] * (idx - 1)];
      i80 = aggregatedOutputs->size[0];
      for (loop_ub = 0; loop_ub < i80; loop_ub++) {
        if ((aggregatedOutputs->data[loop_ub + aggregatedOutputs->size[0] *
             outputID] == maxMFValue) && (fabs(outputSamplePoints->data[outputID
              + outputSamplePoints->size[0] * loop_ub]) < refX)) {
          refX = fabs(outputSamplePoints->data[outputID +
                      outputSamplePoints->size[0] * loop_ub]);
          defuzzifiedOutputs->data[outputID] = outputSamplePoints->data[outputID
            + outputSamplePoints->size[0] * loop_ub];
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
  double sumAntecedentOutputs, const emxArray_real_T *aggregatedOutputs, const
  emxArray_real_T *fis_outputRange, int fis_numOutputs, emxArray_real_T
  *defuzzifiedOutputs)
{
  int i81;
  int outputID;
  int loop_ub;
  double membershipValueOfX_data[51];
  int idx;
  int k;
  double maxMFValue;
  int exitg1;
  double d9;
  double y_data[51];
  double refX;
  boolean_T exitg2;
  i81 = defuzzifiedOutputs->size[0];
  defuzzifiedOutputs->size[0] = fis_numOutputs;
  emxEnsureCapacity_real_T(defuzzifiedOutputs, i81);
  for (outputID = 0; outputID < fis_numOutputs; outputID++) {
    if (sumAntecedentOutputs == 0.0) {
      defuzzifiedOutputs->data[outputID] = (fis_outputRange->data[outputID] +
        fis_outputRange->data[outputID + fis_outputRange->size[0]]) / 2.0;
    } else {
      loop_ub = aggregatedOutputs->size[0];
      for (i81 = 0; i81 < loop_ub; i81++) {
        membershipValueOfX_data[i81] = aggregatedOutputs->data[i81 +
          aggregatedOutputs->size[0] * outputID];
      }

      i81 = aggregatedOutputs->size[0];
      loop_ub = aggregatedOutputs->size[0];
      if (loop_ub <= 2) {
        i81 = aggregatedOutputs->size[0];
        if (i81 == 1) {
          maxMFValue = membershipValueOfX_data[0];
        } else if ((membershipValueOfX_data[0] < membershipValueOfX_data[1]) ||
                   (rtIsNaN(membershipValueOfX_data[0]) && (!rtIsNaN
                     (membershipValueOfX_data[1])))) {
          maxMFValue = membershipValueOfX_data[1];
        } else {
          maxMFValue = membershipValueOfX_data[0];
        }
      } else {
        if (!rtIsNaN(membershipValueOfX_data[0])) {
          idx = 1;
        } else {
          idx = 0;
          k = 2;
          do {
            exitg1 = 0;
            loop_ub = aggregatedOutputs->size[0];
            if (k <= loop_ub) {
              if (!rtIsNaN(membershipValueOfX_data[k - 1])) {
                idx = k;
                exitg1 = 1;
              } else {
                k++;
              }
            } else {
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (idx == 0) {
          maxMFValue = membershipValueOfX_data[0];
        } else {
          maxMFValue = membershipValueOfX_data[idx - 1];
          loop_ub = idx + 1;
          for (k = loop_ub; k <= i81; k++) {
            d9 = membershipValueOfX_data[k - 1];
            if (maxMFValue < d9) {
              maxMFValue = d9;
            }
          }
        }
      }

      i81 = outputSamplePoints->size[1];
      loop_ub = outputSamplePoints->size[1];
      for (k = 0; k < i81; k++) {
        y_data[k] = fabs(outputSamplePoints->data[outputID +
                         outputSamplePoints->size[0] * k]);
      }

      i81 = (signed char)loop_ub;
      if ((signed char)loop_ub <= 2) {
        if ((signed char)loop_ub == 1) {
          refX = y_data[0];
          idx = 1;
        } else if ((y_data[0] > y_data[1]) || (rtIsNaN(y_data[0]) && (!rtIsNaN
                     (y_data[1])))) {
          refX = y_data[1];
          idx = 2;
        } else {
          refX = y_data[0];
          idx = 1;
        }
      } else {
        if (!rtIsNaN(y_data[0])) {
          idx = 1;
        } else {
          idx = 0;
          k = 2;
          exitg2 = false;
          while ((!exitg2) && (k <= (signed char)loop_ub)) {
            if (!rtIsNaN(y_data[k - 1])) {
              idx = k;
              exitg2 = true;
            } else {
              k++;
            }
          }
        }

        if (idx == 0) {
          refX = y_data[0];
          idx = 1;
        } else {
          refX = y_data[idx - 1];
          loop_ub = idx + 1;
          for (k = loop_ub; k <= i81; k++) {
            d9 = y_data[k - 1];
            if (refX > d9) {
              refX = d9;
              idx = k;
            }
          }
        }
      }

      defuzzifiedOutputs->data[outputID] = outputSamplePoints->data[outputID +
        outputSamplePoints->size[0] * (idx - 1)];
      i81 = aggregatedOutputs->size[0];
      for (loop_ub = 0; loop_ub < i81; loop_ub++) {
        if ((aggregatedOutputs->data[loop_ub + aggregatedOutputs->size[0] *
             outputID] == maxMFValue) && (fabs(outputSamplePoints->data[outputID
              + outputSamplePoints->size[0] * loop_ub]) > refX)) {
          refX = fabs(outputSamplePoints->data[outputID +
                      outputSamplePoints->size[0] * loop_ub]);
          defuzzifiedOutputs->data[outputID] = outputSamplePoints->data[outputID
            + outputSamplePoints->size[0] * loop_ub];
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
  double sumAntecedentOutputs, const emxArray_real_T *aggregatedOutputs, const
  emxArray_real_T *fis_outputRange, int fis_numOutputs, emxArray_real_T
  *defuzzifiedOutputs)
{
  int i82;
  int outputID;
  int loop_ub;
  int aggregatedOutputs_size[1];
  double aggregatedOutputs_data[51];
  double tmp_data[51];
  int tmp_size[2];
  i82 = defuzzifiedOutputs->size[0];
  defuzzifiedOutputs->size[0] = fis_numOutputs;
  emxEnsureCapacity_real_T(defuzzifiedOutputs, i82);
  for (outputID = 0; outputID < fis_numOutputs; outputID++) {
    if (sumAntecedentOutputs == 0.0) {
      defuzzifiedOutputs->data[outputID] = (fis_outputRange->data[outputID] +
        fis_outputRange->data[outputID + fis_outputRange->size[0]]) / 2.0;
    } else {
      loop_ub = aggregatedOutputs->size[0];
      aggregatedOutputs_size[0] = loop_ub;
      for (i82 = 0; i82 < loop_ub; i82++) {
        aggregatedOutputs_data[i82] = aggregatedOutputs->data[i82 +
          aggregatedOutputs->size[0] * outputID];
      }

      mrdivide_helper(aggregatedOutputs_data, aggregatedOutputs_size, tmp_data,
                      tmp_size);
      defuzzifiedOutputs->data[outputID] = outputSamplePoints->data[outputID] *
        tmp_data[0];
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
  double sumAntecedentOutputs, const emxArray_real_T *fis_outputRange, int
  fis_numOutputs, emxArray_real_T *defuzzifiedOutputs)
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
      defuzzifiedOutputs->data[outputID] = outputSamplePoints->data[outputID];
    }
  }
}

/*
 * File trailer for applyMamdaniDefuzzificationMethod.c
 *
 * [EOF]
 */
