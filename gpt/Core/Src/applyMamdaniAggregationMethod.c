/*
 * File: applyMamdaniAggregationMethod.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "applyMamdaniAggregationMethod.h"
#include "opkene_emxutil.h"
#include "isequal.h"

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
  const emxArray_uint8_T *fis_aggMethod, int fis_numOutputs, int fis_numRules,
  const int fis_aggSize[2], emxArray_real_T *aggregatedOutputs)
{
  static const unsigned char uv50[3] = { 109U, 97U, 120U };

  static const unsigned char uv51[6] = { 112U, 114U, 111U, 98U, 111U, 114U };

  int q0;
  static const unsigned char uv52[3] = { 115U, 117U, 109U };

  int outputID;
  int indexOffset;
  int qY;
  long long i76;
  int sampleID;
  double aggVal;
  int id;
  double d7;
  if (h_isequal(fis_aggMethod, uv50)) {
    q0 = aggregatedOutputs->size[0] * aggregatedOutputs->size[1];
    aggregatedOutputs->size[0] = fis_aggSize[0];
    aggregatedOutputs->size[1] = fis_aggSize[1];
    emxEnsureCapacity_real_T(aggregatedOutputs, q0);
    for (outputID = 0; outputID < fis_numOutputs; outputID++) {
      q0 = outputID + 1;
      if (q0 < -2147483647) {
        qY = MIN_int32_T;
      } else {
        qY = q0 - 1;
      }

      i76 = (long long)qY * fis_numRules;
      if (i76 > 2147483647LL) {
        i76 = 2147483647LL;
      } else {
        if (i76 < -2147483648LL) {
          i76 = -2147483648LL;
        }
      }

      indexOffset = (int)i76;
      if (indexOffset > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY = indexOffset + 1;
      }

      if ((indexOffset < 0) && (fis_numRules < MIN_int32_T - indexOffset)) {
        q0 = MIN_int32_T;
      } else if ((indexOffset > 0) && (fis_numRules > MAX_int32_T - indexOffset))
      {
        q0 = MAX_int32_T;
      } else {
        q0 = indexOffset + fis_numRules;
      }

      if (qY > 2147483646) {
        indexOffset = MAX_int32_T;
      } else {
        indexOffset = qY + 1;
      }

      for (sampleID = 0; sampleID < 51; sampleID++) {
        aggVal = consequentOutputs->data[sampleID + consequentOutputs->size[0] *
          (qY - 1)];
        for (id = indexOffset; id <= q0; id++) {
          d7 = consequentOutputs->data[sampleID + consequentOutputs->size[0] *
            (id - 1)];
          if ((aggVal < d7) || (rtIsNaN(aggVal) && (!rtIsNaN(d7)))) {
            aggVal = d7;
          }
        }

        aggregatedOutputs->data[sampleID + aggregatedOutputs->size[0] * outputID]
          = aggVal;
      }
    }
  } else if (j_isequal(fis_aggMethod, uv51)) {
    q0 = aggregatedOutputs->size[0] * aggregatedOutputs->size[1];
    aggregatedOutputs->size[0] = fis_aggSize[0];
    aggregatedOutputs->size[1] = fis_aggSize[1];
    emxEnsureCapacity_real_T(aggregatedOutputs, q0);
    for (outputID = 0; outputID < fis_numOutputs; outputID++) {
      q0 = outputID + 1;
      if (q0 < -2147483647) {
        qY = MIN_int32_T;
      } else {
        qY = q0 - 1;
      }

      i76 = (long long)qY * fis_numRules;
      if (i76 > 2147483647LL) {
        i76 = 2147483647LL;
      } else {
        if (i76 < -2147483648LL) {
          i76 = -2147483648LL;
        }
      }

      indexOffset = (int)i76;
      if (indexOffset > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY = indexOffset + 1;
      }

      if ((indexOffset < 0) && (fis_numRules < MIN_int32_T - indexOffset)) {
        q0 = MIN_int32_T;
      } else if ((indexOffset > 0) && (fis_numRules > MAX_int32_T - indexOffset))
      {
        q0 = MAX_int32_T;
      } else {
        q0 = indexOffset + fis_numRules;
      }

      if (qY > 2147483646) {
        indexOffset = MAX_int32_T;
      } else {
        indexOffset = qY + 1;
      }

      for (sampleID = 0; sampleID < 51; sampleID++) {
        aggVal = consequentOutputs->data[sampleID + consequentOutputs->size[0] *
          (qY - 1)];
        for (id = indexOffset; id <= q0; id++) {
          d7 = consequentOutputs->data[sampleID + consequentOutputs->size[0] *
            (id - 1)];
          aggVal = (aggVal + d7) - aggVal * d7;
        }

        aggregatedOutputs->data[sampleID + aggregatedOutputs->size[0] * outputID]
          = aggVal;
      }
    }
  } else if (h_isequal(fis_aggMethod, uv52)) {
    q0 = aggregatedOutputs->size[0] * aggregatedOutputs->size[1];
    aggregatedOutputs->size[0] = fis_aggSize[0];
    aggregatedOutputs->size[1] = fis_aggSize[1];
    emxEnsureCapacity_real_T(aggregatedOutputs, q0);
    for (outputID = 0; outputID < fis_numOutputs; outputID++) {
      q0 = outputID + 1;
      if (q0 < -2147483647) {
        qY = MIN_int32_T;
      } else {
        qY = q0 - 1;
      }

      i76 = (long long)qY * fis_numRules;
      if (i76 > 2147483647LL) {
        i76 = 2147483647LL;
      } else {
        if (i76 < -2147483648LL) {
          i76 = -2147483648LL;
        }
      }

      indexOffset = (int)i76;
      if (indexOffset > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY = indexOffset + 1;
      }

      if ((indexOffset < 0) && (fis_numRules < MIN_int32_T - indexOffset)) {
        q0 = MIN_int32_T;
      } else if ((indexOffset > 0) && (fis_numRules > MAX_int32_T - indexOffset))
      {
        q0 = MAX_int32_T;
      } else {
        q0 = indexOffset + fis_numRules;
      }

      if (qY > 2147483646) {
        indexOffset = MAX_int32_T;
      } else {
        indexOffset = qY + 1;
      }

      for (sampleID = 0; sampleID < 51; sampleID++) {
        aggVal = consequentOutputs->data[sampleID + consequentOutputs->size[0] *
          (qY - 1)];
        for (id = indexOffset; id <= q0; id++) {
          d7 = consequentOutputs->data[sampleID + consequentOutputs->size[0] *
            (id - 1)];
          aggVal += d7;
        }

        aggregatedOutputs->data[sampleID + aggregatedOutputs->size[0] * outputID]
          = aggVal;
      }
    }
  } else {
    q0 = aggregatedOutputs->size[0] * aggregatedOutputs->size[1];
    aggregatedOutputs->size[0] = fis_aggSize[0];
    aggregatedOutputs->size[1] = fis_aggSize[1];
    emxEnsureCapacity_real_T(aggregatedOutputs, q0);
    indexOffset = fis_aggSize[0] * fis_aggSize[1];
    for (q0 = 0; q0 < indexOffset; q0++) {
      aggregatedOutputs->data[q0] = 0.0;
    }

    exit(0);
  }
}

/*
 * File trailer for applyMamdaniAggregationMethod.c
 *
 * [EOF]
 */
