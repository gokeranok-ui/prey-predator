/*
 * File: applyMamdaniImplicationMethod.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "applyMamdaniImplicationMethod.h"
#include "opkene_emxutil.h"
#include "isequal.h"
#include "opkene_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *antecedentOutputs
 *                const emxArray_uint8_T *fis_impMethod
 *                const emxArray_real_T *fis_consequent
 *                int fis_numOutputs
 *                int fis_numRules
 *                const emxArray_int32_T *fis_numCumOutputMFs
 *                const int fis_orrSize[2]
 *                const emxArray_real_T *varargin_1
 *                emxArray_real_T *consequentOutputs
 * Return Type  : void
 */
void applyMamdaniImplicationMethod(const emxArray_real_T *antecedentOutputs,
  const emxArray_uint8_T *fis_impMethod, const emxArray_real_T *fis_consequent,
  int fis_numOutputs, int fis_numRules, const emxArray_int32_T
  *fis_numCumOutputMFs, const int fis_orrSize[2], const emxArray_real_T
  *varargin_1, emxArray_real_T *consequentOutputs)
{
  static const unsigned char uv48[3] = { 109U, 105U, 110U };

  static const unsigned char uv49[4] = { 112U, 114U, 111U, 100U };

  int i74;
  int outputID;
  int loop_ub;
  long long i75;
  int indexOffset;
  int ruleID;
  double b_varargin_1;
  int q1;
  int ruleOutputIndex;
  int sampleID;
  double d6;
  if (h_isequal(fis_impMethod, uv48)) {
    i74 = consequentOutputs->size[0] * consequentOutputs->size[1];
    consequentOutputs->size[0] = fis_orrSize[0];
    consequentOutputs->size[1] = fis_orrSize[1];
    emxEnsureCapacity_real_T(consequentOutputs, i74);
    for (outputID = 0; outputID < fis_numOutputs; outputID++) {
      loop_ub = outputID + 1;
      if (loop_ub < -2147483647) {
        loop_ub = MIN_int32_T;
      } else {
        loop_ub--;
      }

      i75 = (long long)loop_ub * fis_numRules;
      if (i75 > 2147483647LL) {
        i75 = 2147483647LL;
      } else {
        if (i75 < -2147483648LL) {
          i75 = -2147483648LL;
        }
      }

      indexOffset = (int)i75;
      for (ruleID = 0; ruleID < fis_numRules; ruleID++) {
        b_varargin_1 = rt_roundd_snf(fabs(fis_consequent->data[ruleID +
          fis_consequent->size[0] * outputID]));
        if (b_varargin_1 < 2.147483648E+9) {
          q1 = (int)b_varargin_1;
        } else if (b_varargin_1 >= 2.147483648E+9) {
          q1 = MAX_int32_T;
        } else {
          q1 = 0;
        }

        loop_ub = ruleID + 1;
        if ((indexOffset < 0) && (loop_ub < MIN_int32_T - indexOffset)) {
          loop_ub = MIN_int32_T;
        } else if ((indexOffset > 0) && (loop_ub > MAX_int32_T - indexOffset)) {
          loop_ub = MAX_int32_T;
        } else {
          loop_ub += indexOffset;
        }

        ruleOutputIndex = loop_ub - 1;
        if (q1 == 0) {
          loop_ub = consequentOutputs->size[0];
          for (i74 = 0; i74 < loop_ub; i74++) {
            consequentOutputs->data[i74 + consequentOutputs->size[0] *
              ruleOutputIndex] = 0.0;
          }
        } else {
          for (sampleID = 0; sampleID < 51; sampleID++) {
            i74 = fis_numCumOutputMFs->data[outputID];
            if (i74 <= MIN_int32_T) {
              loop_ub = MAX_int32_T;
            } else {
              loop_ub = -i74;
            }

            if (fis_numCumOutputMFs->data[outputID] < 0) {
            } else {
              loop_ub = fis_numCumOutputMFs->data[outputID];
            }

            if ((loop_ub < 0) && (q1 < MIN_int32_T - loop_ub)) {
              loop_ub = MIN_int32_T;
            } else if ((loop_ub > 0) && (q1 > MAX_int32_T - loop_ub)) {
              loop_ub = MAX_int32_T;
            } else {
              loop_ub += q1;
            }

            consequentOutputs->data[sampleID + consequentOutputs->size[0] *
              ruleOutputIndex] = varargin_1->data[(loop_ub + varargin_1->size[0]
              * sampleID) - 1];
            if (fis_consequent->data[ruleID + fis_consequent->size[0] * outputID]
                < 0.0) {
              b_varargin_1 = 1.0 - consequentOutputs->data[sampleID +
                consequentOutputs->size[0] * ruleOutputIndex];
              if (0.0 < b_varargin_1) {
                consequentOutputs->data[sampleID + consequentOutputs->size[0] *
                  ruleOutputIndex] = b_varargin_1;
              } else {
                consequentOutputs->data[sampleID + consequentOutputs->size[0] *
                  ruleOutputIndex] = 0.0;
              }
            }

            b_varargin_1 = consequentOutputs->data[sampleID +
              consequentOutputs->size[0] * ruleOutputIndex];
            d6 = antecedentOutputs->data[ruleID];
            if ((b_varargin_1 > d6) || (rtIsNaN(b_varargin_1) && (!rtIsNaN(d6))))
            {
              consequentOutputs->data[sampleID + consequentOutputs->size[0] *
                ruleOutputIndex] = d6;
            } else {
              consequentOutputs->data[sampleID + consequentOutputs->size[0] *
                ruleOutputIndex] = b_varargin_1;
            }
          }
        }
      }
    }
  } else if (i_isequal(fis_impMethod, uv49)) {
    i74 = consequentOutputs->size[0] * consequentOutputs->size[1];
    consequentOutputs->size[0] = fis_orrSize[0];
    consequentOutputs->size[1] = fis_orrSize[1];
    emxEnsureCapacity_real_T(consequentOutputs, i74);
    for (outputID = 0; outputID < fis_numOutputs; outputID++) {
      loop_ub = outputID + 1;
      if (loop_ub < -2147483647) {
        loop_ub = MIN_int32_T;
      } else {
        loop_ub--;
      }

      i75 = (long long)loop_ub * fis_numRules;
      if (i75 > 2147483647LL) {
        i75 = 2147483647LL;
      } else {
        if (i75 < -2147483648LL) {
          i75 = -2147483648LL;
        }
      }

      indexOffset = (int)i75;
      for (ruleID = 0; ruleID < fis_numRules; ruleID++) {
        b_varargin_1 = rt_roundd_snf(fabs(fis_consequent->data[ruleID +
          fis_consequent->size[0] * outputID]));
        if (b_varargin_1 < 2.147483648E+9) {
          q1 = (int)b_varargin_1;
        } else if (b_varargin_1 >= 2.147483648E+9) {
          q1 = MAX_int32_T;
        } else {
          q1 = 0;
        }

        loop_ub = ruleID + 1;
        if ((indexOffset < 0) && (loop_ub < MIN_int32_T - indexOffset)) {
          loop_ub = MIN_int32_T;
        } else if ((indexOffset > 0) && (loop_ub > MAX_int32_T - indexOffset)) {
          loop_ub = MAX_int32_T;
        } else {
          loop_ub += indexOffset;
        }

        ruleOutputIndex = loop_ub - 1;
        if (q1 == 0) {
          loop_ub = consequentOutputs->size[0];
          for (i74 = 0; i74 < loop_ub; i74++) {
            consequentOutputs->data[i74 + consequentOutputs->size[0] *
              ruleOutputIndex] = 0.0;
          }
        } else {
          for (sampleID = 0; sampleID < 51; sampleID++) {
            i74 = fis_numCumOutputMFs->data[outputID];
            if (i74 <= MIN_int32_T) {
              loop_ub = MAX_int32_T;
            } else {
              loop_ub = -i74;
            }

            if (fis_numCumOutputMFs->data[outputID] < 0) {
            } else {
              loop_ub = fis_numCumOutputMFs->data[outputID];
            }

            if ((loop_ub < 0) && (q1 < MIN_int32_T - loop_ub)) {
              loop_ub = MIN_int32_T;
            } else if ((loop_ub > 0) && (q1 > MAX_int32_T - loop_ub)) {
              loop_ub = MAX_int32_T;
            } else {
              loop_ub += q1;
            }

            consequentOutputs->data[sampleID + consequentOutputs->size[0] *
              ruleOutputIndex] = varargin_1->data[(loop_ub + varargin_1->size[0]
              * sampleID) - 1];
            if (fis_consequent->data[ruleID + fis_consequent->size[0] * outputID]
                < 0.0) {
              b_varargin_1 = 1.0 - consequentOutputs->data[sampleID +
                consequentOutputs->size[0] * ruleOutputIndex];
              if (0.0 < b_varargin_1) {
                consequentOutputs->data[sampleID + consequentOutputs->size[0] *
                  ruleOutputIndex] = b_varargin_1;
              } else {
                consequentOutputs->data[sampleID + consequentOutputs->size[0] *
                  ruleOutputIndex] = 0.0;
              }
            }

            b_varargin_1 = consequentOutputs->data[sampleID +
              consequentOutputs->size[0] * ruleOutputIndex];
            d6 = antecedentOutputs->data[ruleID];
            consequentOutputs->data[sampleID + consequentOutputs->size[0] *
              ruleOutputIndex] = b_varargin_1 * d6;
          }
        }
      }
    }
  } else {
    i74 = consequentOutputs->size[0] * consequentOutputs->size[1];
    consequentOutputs->size[0] = fis_orrSize[0];
    consequentOutputs->size[1] = fis_orrSize[1];
    emxEnsureCapacity_real_T(consequentOutputs, i74);
    loop_ub = fis_orrSize[0] * fis_orrSize[1];
    for (i74 = 0; i74 < loop_ub; i74++) {
      consequentOutputs->data[i74] = 0.0;
    }

    exit(0);
  }
}

/*
 * File trailer for applyMamdaniImplicationMethod.c
 *
 * [EOF]
 */
