/*
 * File: applyMamdaniAggregationMethod.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "applyMamdaniAggregationMethod.h"
#include "isequal.h"
#include "opkene_emxutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *consequentOutputs
 *                const emxArray_uint8_T *fis_aggMethod
 *                int fis_numOutputs
 *                int fis_numRules
 *                const int fis_aggSize[2]
 *                emxArray_real_T *aggregatedOutputs
 * Return Type  : void
 */
void applyMamdaniAggregationMethod(const emxArray_real_T *consequentOutputs,
                                   const emxArray_uint8_T *fis_aggMethod,
                                   int fis_numOutputs, int fis_numRules,
                                   const int fis_aggSize[2],
                                   emxArray_real_T *aggregatedOutputs)
{
  static const unsigned char uv1[6] = {112U, 114U, 111U, 98U, 111U, 114U};
  static const unsigned char uv[3] = {109U, 97U, 120U};
  static const unsigned char uv2[3] = {115U, 117U, 109U};
  const double *consequentOutputs_data;
  double *aggregatedOutputs_data;
  int i;
  int id;
  int outputID;
  int sampleID;
  consequentOutputs_data = consequentOutputs->data;
  if (g_isequal(fis_aggMethod, uv)) {
    unsigned int u;
    i = aggregatedOutputs->size[0] * aggregatedOutputs->size[1];
    aggregatedOutputs->size[0] = fis_aggSize[0];
    aggregatedOutputs->size[1] = fis_aggSize[1];
    emxEnsureCapacity_real_T(aggregatedOutputs, i);
    aggregatedOutputs_data = aggregatedOutputs->data;
    u = (unsigned int)fis_numOutputs;
    if ((unsigned int)fis_numOutputs > 2147483647UL) {
      u = 2147483647UL;
    }
    i = (int)u;
    for (outputID = 0; outputID < i; outputID++) {
      long long i1;
      int b_qY;
      int loop_ub;
      int qY;
      i1 = (long long)outputID * fis_numRules;
      if (i1 > 2147483647LL) {
        i1 = 2147483647LL;
      } else if (i1 < -2147483648LL) {
        i1 = -2147483648LL;
      }
      if ((int)i1 > 2147483646) {
        loop_ub = MAX_int32_T;
      } else {
        loop_ub = (int)i1 + 1;
      }
      if (((int)i1 < 0) && (fis_numRules < MIN_int32_T - (int)i1)) {
        qY = MIN_int32_T;
      } else if (((int)i1 > 0) && (fis_numRules > MAX_int32_T - (int)i1)) {
        qY = MAX_int32_T;
      } else {
        qY = (int)i1 + fis_numRules;
      }
      if (loop_ub > 2147483646) {
        b_qY = MAX_int32_T;
      } else {
        b_qY = loop_ub + 1;
      }
      for (sampleID = 0; sampleID < 51; sampleID++) {
        double aggVal;
        aggVal = consequentOutputs_data[sampleID + consequentOutputs->size[0] *
                                                       (loop_ub - 1)];
        for (id = b_qY; id <= qY; id++) {
          double x_idx_1;
          x_idx_1 =
              consequentOutputs_data[sampleID +
                                     consequentOutputs->size[0] * (id - 1)];
          if ((aggVal < x_idx_1) || (rtIsNaN(aggVal) && (!rtIsNaN(x_idx_1)))) {
            aggVal = x_idx_1;
          }
        }
        aggregatedOutputs_data[sampleID +
                               aggregatedOutputs->size[0] * outputID] = aggVal;
      }
    }
  } else if (h_isequal(fis_aggMethod, uv1)) {
    unsigned int u;
    i = aggregatedOutputs->size[0] * aggregatedOutputs->size[1];
    aggregatedOutputs->size[0] = fis_aggSize[0];
    aggregatedOutputs->size[1] = fis_aggSize[1];
    emxEnsureCapacity_real_T(aggregatedOutputs, i);
    aggregatedOutputs_data = aggregatedOutputs->data;
    u = (unsigned int)fis_numOutputs;
    if ((unsigned int)fis_numOutputs > 2147483647UL) {
      u = 2147483647UL;
    }
    i = (int)u;
    for (outputID = 0; outputID < i; outputID++) {
      long long i1;
      int b_qY;
      int loop_ub;
      int qY;
      i1 = (long long)outputID * fis_numRules;
      if (i1 > 2147483647LL) {
        i1 = 2147483647LL;
      } else if (i1 < -2147483648LL) {
        i1 = -2147483648LL;
      }
      if ((int)i1 > 2147483646) {
        loop_ub = MAX_int32_T;
      } else {
        loop_ub = (int)i1 + 1;
      }
      if (((int)i1 < 0) && (fis_numRules < MIN_int32_T - (int)i1)) {
        qY = MIN_int32_T;
      } else if (((int)i1 > 0) && (fis_numRules > MAX_int32_T - (int)i1)) {
        qY = MAX_int32_T;
      } else {
        qY = (int)i1 + fis_numRules;
      }
      if (loop_ub > 2147483646) {
        b_qY = MAX_int32_T;
      } else {
        b_qY = loop_ub + 1;
      }
      for (sampleID = 0; sampleID < 51; sampleID++) {
        double aggVal;
        aggVal = consequentOutputs_data[sampleID + consequentOutputs->size[0] *
                                                       (loop_ub - 1)];
        for (id = b_qY; id <= qY; id++) {
          double x_idx_1;
          x_idx_1 =
              consequentOutputs_data[sampleID +
                                     consequentOutputs->size[0] * (id - 1)];
          aggVal = (aggVal + x_idx_1) - aggVal * x_idx_1;
        }
        aggregatedOutputs_data[sampleID +
                               aggregatedOutputs->size[0] * outputID] = aggVal;
      }
    }
  } else if (g_isequal(fis_aggMethod, uv2)) {
    unsigned int u;
    i = aggregatedOutputs->size[0] * aggregatedOutputs->size[1];
    aggregatedOutputs->size[0] = fis_aggSize[0];
    aggregatedOutputs->size[1] = fis_aggSize[1];
    emxEnsureCapacity_real_T(aggregatedOutputs, i);
    aggregatedOutputs_data = aggregatedOutputs->data;
    u = (unsigned int)fis_numOutputs;
    if ((unsigned int)fis_numOutputs > 2147483647UL) {
      u = 2147483647UL;
    }
    i = (int)u;
    for (outputID = 0; outputID < i; outputID++) {
      long long i1;
      int b_qY;
      int loop_ub;
      int qY;
      i1 = (long long)outputID * fis_numRules;
      if (i1 > 2147483647LL) {
        i1 = 2147483647LL;
      } else if (i1 < -2147483648LL) {
        i1 = -2147483648LL;
      }
      if ((int)i1 > 2147483646) {
        loop_ub = MAX_int32_T;
      } else {
        loop_ub = (int)i1 + 1;
      }
      if (((int)i1 < 0) && (fis_numRules < MIN_int32_T - (int)i1)) {
        qY = MIN_int32_T;
      } else if (((int)i1 > 0) && (fis_numRules > MAX_int32_T - (int)i1)) {
        qY = MAX_int32_T;
      } else {
        qY = (int)i1 + fis_numRules;
      }
      if (loop_ub > 2147483646) {
        b_qY = MAX_int32_T;
      } else {
        b_qY = loop_ub + 1;
      }
      for (sampleID = 0; sampleID < 51; sampleID++) {
        double aggVal;
        aggVal = consequentOutputs_data[sampleID + consequentOutputs->size[0] *
                                                       (loop_ub - 1)];
        for (id = b_qY; id <= qY; id++) {
          aggVal +=
              consequentOutputs_data[sampleID +
                                     consequentOutputs->size[0] * (id - 1)];
        }
        aggregatedOutputs_data[sampleID +
                               aggregatedOutputs->size[0] * outputID] = aggVal;
      }
    }
  } else {
    int loop_ub;
    i = aggregatedOutputs->size[0] * aggregatedOutputs->size[1];
    aggregatedOutputs->size[0] = fis_aggSize[0];
    aggregatedOutputs->size[1] = fis_aggSize[1];
    emxEnsureCapacity_real_T(aggregatedOutputs, i);
    aggregatedOutputs_data = aggregatedOutputs->data;
    loop_ub = fis_aggSize[0] * fis_aggSize[1];
    for (i = 0; i < loop_ub; i++) {
      aggregatedOutputs_data[i] = 0.0;
    }
    exit(0);
  }
}

/*
 * File trailer for applyMamdaniAggregationMethod.c
 *
 * [EOF]
 */
