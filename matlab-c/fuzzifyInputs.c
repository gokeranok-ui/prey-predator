/*
 * File: fuzzifyInputs.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "fuzzifyInputs.h"
#include "applyMamdaniImplicationMethod.h"
#include "evaluateCommonMembershipFcn.h"
#include "opkene_rtwutil.h"

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
void b_fuzzifyInputs(double inputs, const emxArray_real_T *fis_antecedent, const
                     emxArray_real_T *fis_connection, int fis_numRules, const
                     emxArray_int32_T *fis_numInputMFs, const emxArray_int32_T
                     *fis_numCumInputMFs, const emxArray_cell_wrap_0 *varargin_1,
                     emxArray_real_T *varargin_2, emxArray_real_T *varargin_3)
{
  int inputID;
  int numMFs;
  int mfID;
  double d15;
  int q0;
  int q1;
  for (inputID = 0; inputID < 1; inputID++) {
    numMFs = fis_numInputMFs->data[0];
    for (mfID = 0; mfID < numMFs; mfID++) {
      q0 = fis_numCumInputMFs->data[0];
      q1 = mfID + 1;
      if ((q0 < 0) && (q1 < MIN_int32_T - q0)) {
        q0 = MIN_int32_T;
      } else if ((q0 > 0) && (q1 > MAX_int32_T - q0)) {
        q0 = MAX_int32_T;
      } else {
        q0 += q1;
      }

      varargin_2->data[q0 - 1] = evaluateCommonMembershipFcn(varargin_1->data[0]
        .f1->data[mfID].type, inputs, varargin_1->data[0].f1->data[mfID].params);
    }
  }

  for (inputID = 0; inputID < fis_numRules; inputID++) {
    d15 = rt_roundd_snf(fabs(fis_antecedent->data[inputID]));
    if (d15 < 2.147483648E+9) {
      q1 = (int)d15;
    } else if (d15 >= 2.147483648E+9) {
      q1 = MAX_int32_T;
    } else {
      q1 = 0;
    }

    if (q1 == 0) {
      varargin_3->data[inputID] = (fis_connection->data[inputID] == 1.0);
    } else {
      q0 = fis_numCumInputMFs->data[0];
      if (q0 <= MIN_int32_T) {
        q0 = MAX_int32_T;
      } else {
        q0 = -q0;
      }

      if (fis_numCumInputMFs->data[0] < 0) {
      } else {
        q0 = fis_numCumInputMFs->data[0];
      }

      if ((q0 < 0) && (q1 < MIN_int32_T - q0)) {
        q0 = MIN_int32_T;
      } else if ((q0 > 0) && (q1 > MAX_int32_T - q0)) {
        q0 = MAX_int32_T;
      } else {
        q0 += q1;
      }

      varargin_3->data[inputID] = varargin_2->data[q0 - 1];
      if (fis_antecedent->data[inputID] < 0.0) {
        varargin_3->data[inputID] = 1.0 - varargin_3->data[inputID];
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
void fuzzifyInputs(const emxArray_real_T *inputs, const emxArray_real_T
                   *fis_antecedent, const emxArray_real_T *fis_connection, int
                   fis_numInputs, int fis_numRules, const emxArray_int32_T
                   *fis_numInputMFs, const emxArray_int32_T *fis_numCumInputMFs,
                   const emxArray_cell_wrap_0 *varargin_1, emxArray_real_T
                   *varargin_2, emxArray_real_T *varargin_3)
{
  int inputID;
  int numMFs;
  int mfID;
  int q0;
  double d14;
  int q1;
  for (inputID = 0; inputID < fis_numInputs; inputID++) {
    numMFs = fis_numInputMFs->data[inputID];
    for (mfID = 0; mfID < numMFs; mfID++) {
      q0 = fis_numCumInputMFs->data[inputID];
      q1 = mfID + 1;
      if ((q0 < 0) && (q1 < MIN_int32_T - q0)) {
        q0 = MIN_int32_T;
      } else if ((q0 > 0) && (q1 > MAX_int32_T - q0)) {
        q0 = MAX_int32_T;
      } else {
        q0 += q1;
      }

      varargin_2->data[q0 - 1] = evaluateCommonMembershipFcn(varargin_1->
        data[inputID].f1->data[mfID].type, inputs->data[inputID],
        varargin_1->data[inputID].f1->data[mfID].params);
    }
  }

  for (numMFs = 0; numMFs < fis_numRules; numMFs++) {
    for (inputID = 0; inputID < fis_numInputs; inputID++) {
      d14 = rt_roundd_snf(fabs(fis_antecedent->data[numMFs +
        fis_antecedent->size[0] * inputID]));
      if (d14 < 2.147483648E+9) {
        q1 = (int)d14;
      } else if (d14 >= 2.147483648E+9) {
        q1 = MAX_int32_T;
      } else {
        q1 = 0;
      }

      if (q1 == 0) {
        varargin_3->data[numMFs + varargin_3->size[0] * inputID] =
          (fis_connection->data[numMFs] == 1.0);
      } else {
        q0 = fis_numCumInputMFs->data[inputID];
        if (q0 <= MIN_int32_T) {
          q0 = MAX_int32_T;
        } else {
          q0 = -q0;
        }

        if (fis_numCumInputMFs->data[inputID] < 0) {
        } else {
          q0 = fis_numCumInputMFs->data[inputID];
        }

        if ((q0 < 0) && (q1 < MIN_int32_T - q0)) {
          q0 = MIN_int32_T;
        } else if ((q0 > 0) && (q1 > MAX_int32_T - q0)) {
          q0 = MAX_int32_T;
        } else {
          q0 += q1;
        }

        varargin_3->data[numMFs + varargin_3->size[0] * inputID] =
          varargin_2->data[q0 - 1];
        if (fis_antecedent->data[numMFs + fis_antecedent->size[0] * inputID] <
            0.0) {
          varargin_3->data[numMFs + varargin_3->size[0] * inputID] = 1.0 -
            varargin_3->data[numMFs + varargin_3->size[0] * inputID];
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
