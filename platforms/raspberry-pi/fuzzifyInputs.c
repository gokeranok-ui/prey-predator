/*
 * File: fuzzifyInputs.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "fuzzifyInputs.h"
#include "evaluateCommonMembershipFcn.h"
#include "opkene_rtwutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double inputs
 *                const emxArray_real_T *fis_antecedent
 *                const emxArray_real_T *fis_connection
 *                int fis_numRules
 *                const emxArray_int32_T *fis_numInputMFs
 *                const emxArray_int32_T *fis_numCumInputMFs
 *                const emxArray_cell_wrap_0 *varargin_1
 *                emxArray_real_T *varargin_2
 *                emxArray_real_T *varargin_3
 * Return Type  : void
 */
void b_fuzzifyInputs(double inputs, const emxArray_real_T *fis_antecedent,
                     const emxArray_real_T *fis_connection, int fis_numRules,
                     const emxArray_int32_T *fis_numInputMFs,
                     const emxArray_int32_T *fis_numCumInputMFs,
                     const emxArray_cell_wrap_0 *varargin_1,
                     emxArray_real_T *varargin_2, emxArray_real_T *varargin_3)
{
  const cell_wrap_0 *varargin_1_data;
  const double *fis_antecedent_data;
  const double *fis_connection_data;
  double *varargin_2_data;
  double *varargin_3_data;
  const int *fis_numCumInputMFs_data;
  const int *fis_numInputMFs_data;
  int inputID;
  int mfID;
  int numMFs;
  int q0;
  int qY;
  unsigned int u;
  varargin_3_data = varargin_3->data;
  varargin_2_data = varargin_2->data;
  varargin_1_data = varargin_1->data;
  fis_numCumInputMFs_data = fis_numCumInputMFs->data;
  fis_numInputMFs_data = fis_numInputMFs->data;
  fis_connection_data = fis_connection->data;
  fis_antecedent_data = fis_antecedent->data;
  numMFs = fis_numInputMFs_data[0];
  for (inputID = 0; inputID < 1; inputID++) {
    for (mfID = 0; mfID < numMFs; mfID++) {
      q0 = fis_numCumInputMFs_data[0];
      if ((q0 < 0) && (mfID + 1 < MIN_int32_T - q0)) {
        qY = MIN_int32_T;
      } else if ((q0 > 0) && (mfID + 1 > MAX_int32_T - q0)) {
        qY = MAX_int32_T;
      } else {
        qY = (q0 + mfID) + 1;
      }
      varargin_2_data[qY - 1] = evaluateCommonMembershipFcn(
          varargin_1_data[0].f1->data[mfID].type, inputs,
          varargin_1_data[0].f1->data[mfID].params);
    }
  }
  u = (unsigned int)fis_numRules;
  if ((unsigned int)fis_numRules > 2147483647UL) {
    u = 2147483647UL;
  }
  inputID = (int)u;
  for (mfID = 0; mfID < inputID; mfID++) {
    double d;
    d = rt_roundd_snf(fabs(fis_antecedent_data[mfID]));
    if (d < 2.147483648E+9) {
      qY = (int)d;
    } else if (d >= 2.147483648E+9) {
      qY = MAX_int32_T;
    } else {
      qY = 0;
    }
    if (qY == 0) {
      varargin_3_data[mfID] = (fis_connection_data[mfID] == 1.0);
    } else {
      numMFs = fis_numCumInputMFs_data[0];
      if (numMFs <= MIN_int32_T) {
        numMFs = MAX_int32_T;
      } else {
        numMFs = -numMFs;
      }
      if (fis_numCumInputMFs_data[0] < 0) {
        q0 = numMFs;
      } else {
        q0 = fis_numCumInputMFs_data[0];
      }
      if ((q0 < 0) && (qY < MIN_int32_T - q0)) {
        qY = MIN_int32_T;
      } else if ((q0 > 0) && (qY > MAX_int32_T - q0)) {
        qY = MAX_int32_T;
      } else {
        qY += q0;
      }
      d = varargin_2_data[qY - 1];
      varargin_3_data[mfID] = d;
      if (fis_antecedent_data[mfID] < 0.0) {
        d = 1.0 - d;
        varargin_3_data[mfID] = d;
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *inputs
 *                const emxArray_real_T *fis_antecedent
 *                const emxArray_real_T *fis_connection
 *                int fis_numInputs
 *                int fis_numRules
 *                const emxArray_int32_T *fis_numInputMFs
 *                const emxArray_int32_T *fis_numCumInputMFs
 *                const emxArray_cell_wrap_0 *varargin_1
 *                emxArray_real_T *varargin_2
 *                emxArray_real_T *varargin_3
 * Return Type  : void
 */
void fuzzifyInputs(const emxArray_real_T *inputs,
                   const emxArray_real_T *fis_antecedent,
                   const emxArray_real_T *fis_connection, int fis_numInputs,
                   int fis_numRules, const emxArray_int32_T *fis_numInputMFs,
                   const emxArray_int32_T *fis_numCumInputMFs,
                   const emxArray_cell_wrap_0 *varargin_1,
                   emxArray_real_T *varargin_2, emxArray_real_T *varargin_3)
{
  const cell_wrap_0 *varargin_1_data;
  const double *fis_antecedent_data;
  const double *fis_connection_data;
  const double *inputs_data;
  double *varargin_2_data;
  double *varargin_3_data;
  const int *fis_numCumInputMFs_data;
  const int *fis_numInputMFs_data;
  int i;
  int inputID;
  int mfID;
  int numMFs;
  int q0;
  int ruleID;
  unsigned int u;
  varargin_3_data = varargin_3->data;
  varargin_2_data = varargin_2->data;
  varargin_1_data = varargin_1->data;
  fis_numCumInputMFs_data = fis_numCumInputMFs->data;
  fis_numInputMFs_data = fis_numInputMFs->data;
  fis_connection_data = fis_connection->data;
  fis_antecedent_data = fis_antecedent->data;
  inputs_data = inputs->data;
  u = (unsigned int)fis_numInputs;
  if ((unsigned int)fis_numInputs > 2147483647UL) {
    u = 2147483647UL;
  }
  i = (int)u;
  for (inputID = 0; inputID < i; inputID++) {
    numMFs = fis_numInputMFs_data[inputID];
    for (mfID = 0; mfID < numMFs; mfID++) {
      q0 = fis_numCumInputMFs_data[inputID];
      if ((q0 < 0) && (mfID + 1 < MIN_int32_T - q0)) {
        q0 = MIN_int32_T;
      } else if ((q0 > 0) && (mfID + 1 > MAX_int32_T - q0)) {
        q0 = MAX_int32_T;
      } else {
        q0 = (q0 + mfID) + 1;
      }
      varargin_2_data[q0 - 1] = evaluateCommonMembershipFcn(
          varargin_1_data[inputID].f1->data[mfID].type, inputs_data[inputID],
          varargin_1_data[inputID].f1->data[mfID].params);
    }
  }
  u = (unsigned int)fis_numRules;
  if ((unsigned int)fis_numRules > 2147483647UL) {
    u = 2147483647UL;
  }
  i = (int)u;
  for (ruleID = 0; ruleID < i; ruleID++) {
    int i1;
    u = (unsigned int)fis_numInputs;
    if ((unsigned int)fis_numInputs > 2147483647UL) {
      u = 2147483647UL;
    }
    i1 = (int)u;
    for (inputID = 0; inputID < i1; inputID++) {
      double d;
      double d1;
      d = fis_antecedent_data[ruleID + fis_antecedent->size[0] * inputID];
      d1 = rt_roundd_snf(fabs(d));
      if (d1 < 2.147483648E+9) {
        mfID = (int)d1;
      } else if (d1 >= 2.147483648E+9) {
        mfID = MAX_int32_T;
      } else {
        mfID = 0;
      }
      if (mfID == 0) {
        varargin_3_data[ruleID + varargin_3->size[0] * inputID] =
            (fis_connection_data[ruleID] == 1.0);
      } else {
        numMFs = fis_numCumInputMFs_data[inputID];
        if (numMFs <= MIN_int32_T) {
          numMFs = MAX_int32_T;
        } else {
          numMFs = -numMFs;
        }
        if (fis_numCumInputMFs_data[inputID] < 0) {
          q0 = numMFs;
        } else {
          q0 = fis_numCumInputMFs_data[inputID];
        }
        if ((q0 < 0) && (mfID < MIN_int32_T - q0)) {
          q0 = MIN_int32_T;
        } else if ((q0 > 0) && (mfID > MAX_int32_T - q0)) {
          q0 = MAX_int32_T;
        } else {
          q0 += mfID;
        }
        d1 = varargin_2_data[q0 - 1];
        varargin_3_data[ruleID + varargin_3->size[0] * inputID] = d1;
        if (d < 0.0) {
          d1 = 1.0 - d1;
          varargin_3_data[ruleID + varargin_3->size[0] * inputID] = d1;
        }
      }
    }
  }
}

/*
 * File trailer for fuzzifyInputs.c
 *
 * [EOF]
 */
