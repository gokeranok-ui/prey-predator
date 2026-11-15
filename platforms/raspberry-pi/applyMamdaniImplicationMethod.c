/*
 * File: applyMamdaniImplicationMethod.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "applyMamdaniImplicationMethod.h"
#include "isequal.h"
#include "opkene_emxutil.h"
#include "opkene_rtwutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

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
                                   const emxArray_uint8_T *fis_impMethod,
                                   const emxArray_real_T *fis_consequent,
                                   int fis_numOutputs, int fis_numRules,
                                   const emxArray_int32_T *fis_numCumOutputMFs,
                                   const int fis_orrSize[2],
                                   const emxArray_real_T *varargin_1,
                                   emxArray_real_T *consequentOutputs)
{
  static const unsigned char uv[3] = {109U, 105U, 110U};
  const double *antecedentOutputs_data;
  const double *fis_consequent_data;
  const double *varargin_1_data;
  double *consequentOutputs_data;
  const int *fis_numCumOutputMFs_data;
  int i;
  int i3;
  int outputID;
  int q1;
  int ruleID;
  varargin_1_data = varargin_1->data;
  fis_numCumOutputMFs_data = fis_numCumOutputMFs->data;
  fis_consequent_data = fis_consequent->data;
  antecedentOutputs_data = antecedentOutputs->data;
  if (g_isequal(fis_impMethod, uv)) {
    unsigned int u;
    i = consequentOutputs->size[0] * consequentOutputs->size[1];
    consequentOutputs->size[0] = fis_orrSize[0];
    consequentOutputs->size[1] = fis_orrSize[1];
    emxEnsureCapacity_real_T(consequentOutputs, i);
    consequentOutputs_data = consequentOutputs->data;
    u = (unsigned int)fis_numOutputs;
    if ((unsigned int)fis_numOutputs > 2147483647UL) {
      u = 2147483647UL;
    }
    i = (int)u;
    for (outputID = 0; outputID < i; outputID++) {
      long long i1;
      int i2;
      i1 = (long long)outputID * fis_numRules;
      if (i1 > 2147483647LL) {
        i1 = 2147483647LL;
      } else if (i1 < -2147483648LL) {
        i1 = -2147483648LL;
      }
      u = (unsigned int)fis_numRules;
      if ((unsigned int)fis_numRules > 2147483647UL) {
        u = 2147483647UL;
      }
      i2 = (int)u;
      for (ruleID = 0; ruleID < i2; ruleID++) {
        double x_idx_1;
        int qY;
        x_idx_1 = rt_roundd_snf(fabs(
            fis_consequent_data[ruleID + fis_consequent->size[0] * outputID]));
        if (x_idx_1 < 2.147483648E+9) {
          q1 = (int)x_idx_1;
        } else if (x_idx_1 >= 2.147483648E+9) {
          q1 = MAX_int32_T;
        } else {
          q1 = 0;
        }
        if (((int)i1 < 0) && (ruleID + 1 < MIN_int32_T - (int)i1)) {
          qY = MIN_int32_T;
        } else if (((int)i1 > 0) && (ruleID + 1 > MAX_int32_T - (int)i1)) {
          qY = MAX_int32_T;
        } else {
          qY = ((int)i1 + ruleID) + 1;
        }
        if (q1 == 0) {
          int loop_ub;
          loop_ub = consequentOutputs->size[0];
          for (i3 = 0; i3 < loop_ub; i3++) {
            consequentOutputs_data[i3 + consequentOutputs->size[0] * (qY - 1)] =
                0.0;
          }
        } else {
          int loop_ub;
          i3 = fis_numCumOutputMFs_data[outputID];
          if (i3 <= MIN_int32_T) {
            loop_ub = MAX_int32_T;
          } else {
            loop_ub = -i3;
          }
          if (fis_numCumOutputMFs_data[outputID] >= 0) {
            loop_ub = fis_numCumOutputMFs_data[outputID];
          }
          if ((loop_ub < 0) && (q1 < MIN_int32_T - loop_ub)) {
            loop_ub = MIN_int32_T;
          } else if ((loop_ub > 0) && (q1 > MAX_int32_T - loop_ub)) {
            loop_ub = MAX_int32_T;
          } else {
            loop_ub += q1;
          }
          for (q1 = 0; q1 < 51; q1++) {
            consequentOutputs_data[q1 + consequentOutputs->size[0] * (qY - 1)] =
                varargin_1_data[(loop_ub + varargin_1->size[0] * q1) - 1];
            if (fis_consequent_data[ruleID +
                                    fis_consequent->size[0] * outputID] < 0.0) {
              x_idx_1 =
                  1.0 - consequentOutputs_data[q1 + consequentOutputs->size[0] *
                                                        (qY - 1)];
              if (x_idx_1 > 0.0) {
                consequentOutputs_data[q1 + consequentOutputs->size[0] *
                                                (qY - 1)] = x_idx_1;
              } else {
                consequentOutputs_data[q1 + consequentOutputs->size[0] *
                                                (qY - 1)] = 0.0;
              }
            }
            x_idx_1 = consequentOutputs_data[q1 + consequentOutputs->size[0] *
                                                      (qY - 1)];
            if ((x_idx_1 > antecedentOutputs_data[ruleID]) ||
                (rtIsNaN(x_idx_1) &&
                 (!rtIsNaN(antecedentOutputs_data[ruleID])))) {
              consequentOutputs_data[q1 +
                                     consequentOutputs->size[0] * (qY - 1)] =
                  antecedentOutputs_data[ruleID];
            } else {
              consequentOutputs_data[q1 + consequentOutputs->size[0] *
                                              (qY - 1)] = x_idx_1;
            }
          }
        }
      }
    }
  } else if (k_isequal(fis_impMethod)) {
    unsigned int u;
    i = consequentOutputs->size[0] * consequentOutputs->size[1];
    consequentOutputs->size[0] = fis_orrSize[0];
    consequentOutputs->size[1] = fis_orrSize[1];
    emxEnsureCapacity_real_T(consequentOutputs, i);
    consequentOutputs_data = consequentOutputs->data;
    u = (unsigned int)fis_numOutputs;
    if ((unsigned int)fis_numOutputs > 2147483647UL) {
      u = 2147483647UL;
    }
    i = (int)u;
    for (outputID = 0; outputID < i; outputID++) {
      long long i1;
      int i2;
      i1 = (long long)outputID * fis_numRules;
      if (i1 > 2147483647LL) {
        i1 = 2147483647LL;
      } else if (i1 < -2147483648LL) {
        i1 = -2147483648LL;
      }
      u = (unsigned int)fis_numRules;
      if ((unsigned int)fis_numRules > 2147483647UL) {
        u = 2147483647UL;
      }
      i2 = (int)u;
      for (ruleID = 0; ruleID < i2; ruleID++) {
        double x_idx_1;
        int qY;
        x_idx_1 = rt_roundd_snf(fabs(
            fis_consequent_data[ruleID + fis_consequent->size[0] * outputID]));
        if (x_idx_1 < 2.147483648E+9) {
          q1 = (int)x_idx_1;
        } else if (x_idx_1 >= 2.147483648E+9) {
          q1 = MAX_int32_T;
        } else {
          q1 = 0;
        }
        if (((int)i1 < 0) && (ruleID + 1 < MIN_int32_T - (int)i1)) {
          qY = MIN_int32_T;
        } else if (((int)i1 > 0) && (ruleID + 1 > MAX_int32_T - (int)i1)) {
          qY = MAX_int32_T;
        } else {
          qY = ((int)i1 + ruleID) + 1;
        }
        if (q1 == 0) {
          int loop_ub;
          loop_ub = consequentOutputs->size[0];
          for (i3 = 0; i3 < loop_ub; i3++) {
            consequentOutputs_data[i3 + consequentOutputs->size[0] * (qY - 1)] =
                0.0;
          }
        } else {
          int loop_ub;
          i3 = fis_numCumOutputMFs_data[outputID];
          if (i3 <= MIN_int32_T) {
            loop_ub = MAX_int32_T;
          } else {
            loop_ub = -i3;
          }
          if (fis_numCumOutputMFs_data[outputID] >= 0) {
            loop_ub = fis_numCumOutputMFs_data[outputID];
          }
          if ((loop_ub < 0) && (q1 < MIN_int32_T - loop_ub)) {
            loop_ub = MIN_int32_T;
          } else if ((loop_ub > 0) && (q1 > MAX_int32_T - loop_ub)) {
            loop_ub = MAX_int32_T;
          } else {
            loop_ub += q1;
          }
          for (q1 = 0; q1 < 51; q1++) {
            consequentOutputs_data[q1 + consequentOutputs->size[0] * (qY - 1)] =
                varargin_1_data[(loop_ub + varargin_1->size[0] * q1) - 1];
            if (fis_consequent_data[ruleID +
                                    fis_consequent->size[0] * outputID] < 0.0) {
              x_idx_1 =
                  1.0 - consequentOutputs_data[q1 + consequentOutputs->size[0] *
                                                        (qY - 1)];
              if (x_idx_1 > 0.0) {
                consequentOutputs_data[q1 + consequentOutputs->size[0] *
                                                (qY - 1)] = x_idx_1;
              } else {
                consequentOutputs_data[q1 + consequentOutputs->size[0] *
                                                (qY - 1)] = 0.0;
              }
            }
            consequentOutputs_data[q1 +
                                   consequentOutputs->size[0] * (qY - 1)] *=
                antecedentOutputs_data[ruleID];
          }
        }
      }
    }
  } else {
    int loop_ub;
    i = consequentOutputs->size[0] * consequentOutputs->size[1];
    consequentOutputs->size[0] = fis_orrSize[0];
    consequentOutputs->size[1] = fis_orrSize[1];
    emxEnsureCapacity_real_T(consequentOutputs, i);
    consequentOutputs_data = consequentOutputs->data;
    loop_ub = fis_orrSize[0] * fis_orrSize[1];
    for (i = 0; i < loop_ub; i++) {
      consequentOutputs_data[i] = 0.0;
    }
    exit(0);
  }
}

/*
 * File trailer for applyMamdaniImplicationMethod.c
 *
 * [EOF]
 */
