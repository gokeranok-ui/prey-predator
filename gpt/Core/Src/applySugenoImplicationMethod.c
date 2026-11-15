/*
 * File: applySugenoImplicationMethod.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "applySugenoImplicationMethod.h"
#include "opkene_emxutil.h"
#include "applyMamdaniImplicationMethod.h"
#include "isequal.h"
#include "extractVarMF.h"
#include "sum.h"
#include "opkene_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *inputs
 *                const emxArray_real_T *antecedentOutputs
 *                const d_emxArray_struct_T *fis_outputMF
 *                const emxArray_real_T *fis_consequent
 *                int fis_numOutputs
 *                int fis_numRules
 *                const emxArray_int32_T *fis_numOutputMFs
 *                const emxArray_int32_T *fis_numCumOutputMFs
 *                const int fis_orrSize[2]
 *                emxArray_real_T *consequentOutputs
 *                emxArray_real_T *unscaledOutputs
 * Return Type  : void
 */
void applySugenoImplicationMethod(const emxArray_real_T *inputs, const
  emxArray_real_T *antecedentOutputs, const d_emxArray_struct_T *fis_outputMF,
  const emxArray_real_T *fis_consequent, int fis_numOutputs, int fis_numRules,
  const emxArray_int32_T *fis_numOutputMFs, const emxArray_int32_T
  *fis_numCumOutputMFs, const int fis_orrSize[2], emxArray_real_T
  *consequentOutputs, emxArray_real_T *unscaledOutputs)
{
  int q0;
  int loop_ub_tmp;
  emxArray_real_T *outputMFCache;
  double y;
  emxArray_cell_wrap_0 *outVarMF;
  int outputID;
  int numMFs;
  int mfID;
  static const unsigned char uv53[8] = { 99U, 111U, 110U, 115U, 116U, 97U, 110U,
    116U };

  int q1;
  q0 = consequentOutputs->size[0] * consequentOutputs->size[1];
  consequentOutputs->size[0] = fis_orrSize[0];
  consequentOutputs->size[1] = fis_orrSize[1];
  emxEnsureCapacity_real_T(consequentOutputs, q0);
  loop_ub_tmp = fis_orrSize[0] * fis_orrSize[1];
  for (q0 = 0; q0 < loop_ub_tmp; q0++) {
    consequentOutputs->data[q0] = 0.0;
  }

  q0 = unscaledOutputs->size[0] * unscaledOutputs->size[1];
  unscaledOutputs->size[0] = fis_orrSize[0];
  unscaledOutputs->size[1] = fis_orrSize[1];
  emxEnsureCapacity_real_T(unscaledOutputs, q0);
  for (q0 = 0; q0 < loop_ub_tmp; q0++) {
    unscaledOutputs->data[q0] = 0.0;
  }

  emxInit_real_T(&outputMFCache, 1);
  y = sum(fis_numOutputMFs);
  q0 = outputMFCache->size[0];
  loop_ub_tmp = (int)y;
  outputMFCache->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(outputMFCache, q0);
  for (q0 = 0; q0 < loop_ub_tmp; q0++) {
    outputMFCache->data[q0] = 0.0;
  }

  emxInit_cell_wrap_0(&outVarMF, 2);
  extractVarMF(fis_outputMF, outVarMF);
  for (outputID = 0; outputID < fis_numOutputs; outputID++) {
    numMFs = fis_numOutputMFs->data[outputID];
    for (mfID = 0; mfID < numMFs; mfID++) {
      if (f_isequal(outVarMF->data[outputID].f1->data[mfID].type, uv53)) {
        q0 = fis_numCumOutputMFs->data[outputID];
        q1 = mfID + 1;
        if ((q0 < 0) && (q1 < MIN_int32_T - q0)) {
          q0 = MIN_int32_T;
        } else if ((q0 > 0) && (q1 > MAX_int32_T - q0)) {
          q0 = MAX_int32_T;
        } else {
          q0 += q1;
        }

        outputMFCache->data[q0 - 1] = outVarMF->data[outputID].f1->data[mfID].
          params->data[0];
      } else {
        y = 0.0;
        q0 = inputs->size[1];
        for (loop_ub_tmp = 0; loop_ub_tmp < q0; loop_ub_tmp++) {
          y += inputs->data[loop_ub_tmp] * outVarMF->data[outputID].f1->
            data[mfID].params->data[loop_ub_tmp];
        }

        q0 = fis_numCumOutputMFs->data[outputID];
        q1 = mfID + 1;
        if ((q0 < 0) && (q1 < MIN_int32_T - q0)) {
          q0 = MIN_int32_T;
        } else if ((q0 > 0) && (q1 > MAX_int32_T - q0)) {
          q0 = MAX_int32_T;
        } else {
          q0 += q1;
        }

        outputMFCache->data[q0 - 1] = y + outVarMF->data[outputID].f1->data[mfID]
          .params->data[inputs->size[1]];
      }
    }
  }

  emxFree_cell_wrap_0(&outVarMF);
  for (loop_ub_tmp = 0; loop_ub_tmp < fis_numRules; loop_ub_tmp++) {
    for (outputID = 0; outputID < fis_numOutputs; outputID++) {
      y = rt_roundd_snf(fis_consequent->data[loop_ub_tmp + fis_consequent->size
                        [0] * outputID]);
      if (y < 2.147483648E+9) {
        if (y >= -2.147483648E+9) {
          q1 = (int)y;
        } else {
          q1 = MIN_int32_T;
        }
      } else if (y >= 2.147483648E+9) {
        q1 = MAX_int32_T;
      } else {
        q1 = 0;
      }

      if (q1 != 0) {
        q0 = fis_numCumOutputMFs->data[outputID];
        if ((q0 < 0) && (q1 < MIN_int32_T - q0)) {
          q0 = MIN_int32_T;
        } else if ((q0 > 0) && (q1 > MAX_int32_T - q0)) {
          q0 = MAX_int32_T;
        } else {
          q0 += q1;
        }

        unscaledOutputs->data[loop_ub_tmp + unscaledOutputs->size[0] * outputID]
          = outputMFCache->data[q0 - 1];
        q0 = fis_numCumOutputMFs->data[outputID];
        if ((q0 < 0) && (q1 < MIN_int32_T - q0)) {
          q0 = MIN_int32_T;
        } else if ((q0 > 0) && (q1 > MAX_int32_T - q0)) {
          q0 = MAX_int32_T;
        } else {
          q0 += q1;
        }

        consequentOutputs->data[loop_ub_tmp + consequentOutputs->size[0] *
          outputID] = outputMFCache->data[q0 - 1] * antecedentOutputs->
          data[loop_ub_tmp];
      }
    }
  }

  emxFree_real_T(&outputMFCache);
}

/*
 * Arguments    : double inputs
 *                const emxArray_real_T *antecedentOutputs
 *                const d_emxArray_struct_T *fis_outputMF
 *                const emxArray_real_T *fis_consequent
 *                int fis_numOutputs
 *                int fis_numRules
 *                const emxArray_int32_T *fis_numOutputMFs
 *                const emxArray_int32_T *fis_numCumOutputMFs
 *                const int fis_orrSize[2]
 *                emxArray_real_T *consequentOutputs
 *                emxArray_real_T *unscaledOutputs
 * Return Type  : void
 */
void b_applySugenoImplicationMethod(double inputs, const emxArray_real_T
  *antecedentOutputs, const d_emxArray_struct_T *fis_outputMF, const
  emxArray_real_T *fis_consequent, int fis_numOutputs, int fis_numRules, const
  emxArray_int32_T *fis_numOutputMFs, const emxArray_int32_T
  *fis_numCumOutputMFs, const int fis_orrSize[2], emxArray_real_T
  *consequentOutputs, emxArray_real_T *unscaledOutputs)
{
  int mfID;
  int numMFs;
  emxArray_real_T *outputMFCache;
  double d11;
  emxArray_cell_wrap_0 *outVarMF;
  int outputID;
  int q0;
  int q1;
  static const unsigned char uv61[8] = { 99U, 111U, 110U, 115U, 116U, 97U, 110U,
    116U };

  mfID = consequentOutputs->size[0] * consequentOutputs->size[1];
  consequentOutputs->size[0] = fis_orrSize[0];
  consequentOutputs->size[1] = fis_orrSize[1];
  emxEnsureCapacity_real_T(consequentOutputs, mfID);
  numMFs = fis_orrSize[0] * fis_orrSize[1];
  for (mfID = 0; mfID < numMFs; mfID++) {
    consequentOutputs->data[mfID] = 0.0;
  }

  mfID = unscaledOutputs->size[0] * unscaledOutputs->size[1];
  unscaledOutputs->size[0] = fis_orrSize[0];
  unscaledOutputs->size[1] = fis_orrSize[1];
  emxEnsureCapacity_real_T(unscaledOutputs, mfID);
  for (mfID = 0; mfID < numMFs; mfID++) {
    unscaledOutputs->data[mfID] = 0.0;
  }

  emxInit_real_T(&outputMFCache, 1);
  d11 = sum(fis_numOutputMFs);
  mfID = outputMFCache->size[0];
  numMFs = (int)d11;
  outputMFCache->size[0] = numMFs;
  emxEnsureCapacity_real_T(outputMFCache, mfID);
  for (mfID = 0; mfID < numMFs; mfID++) {
    outputMFCache->data[mfID] = 0.0;
  }

  emxInit_cell_wrap_0(&outVarMF, 2);
  extractVarMF(fis_outputMF, outVarMF);
  for (outputID = 0; outputID < fis_numOutputs; outputID++) {
    numMFs = fis_numOutputMFs->data[outputID];
    for (mfID = 0; mfID < numMFs; mfID++) {
      q0 = fis_numCumOutputMFs->data[outputID];
      q1 = mfID + 1;
      if ((q0 < 0) && (q1 < MIN_int32_T - q0)) {
        q0 = MIN_int32_T;
      } else if ((q0 > 0) && (q1 > MAX_int32_T - q0)) {
        q0 = MAX_int32_T;
      } else {
        q0 += q1;
      }

      if (f_isequal(outVarMF->data[outputID].f1->data[mfID].type, uv61)) {
        outputMFCache->data[q0 - 1] = outVarMF->data[outputID].f1->data[mfID].
          params->data[0];
      } else {
        outputMFCache->data[q0 - 1] = inputs * outVarMF->data[outputID].f1->
          data[mfID].params->data[0] + outVarMF->data[outputID].f1->data[mfID].
          params->data[1];
      }
    }
  }

  emxFree_cell_wrap_0(&outVarMF);
  for (numMFs = 0; numMFs < fis_numRules; numMFs++) {
    for (outputID = 0; outputID < fis_numOutputs; outputID++) {
      d11 = rt_roundd_snf(fis_consequent->data[numMFs + fis_consequent->size[0] *
                          outputID]);
      if (d11 < 2.147483648E+9) {
        if (d11 >= -2.147483648E+9) {
          q1 = (int)d11;
        } else {
          q1 = MIN_int32_T;
        }
      } else if (d11 >= 2.147483648E+9) {
        q1 = MAX_int32_T;
      } else {
        q1 = 0;
      }

      if (q1 != 0) {
        q0 = fis_numCumOutputMFs->data[outputID];
        if ((q0 < 0) && (q1 < MIN_int32_T - q0)) {
          q0 = MIN_int32_T;
        } else if ((q0 > 0) && (q1 > MAX_int32_T - q0)) {
          q0 = MAX_int32_T;
        } else {
          q0 += q1;
        }

        unscaledOutputs->data[numMFs + unscaledOutputs->size[0] * outputID] =
          outputMFCache->data[q0 - 1];
        q0 = fis_numCumOutputMFs->data[outputID];
        if ((q0 < 0) && (q1 < MIN_int32_T - q0)) {
          q0 = MIN_int32_T;
        } else if ((q0 > 0) && (q1 > MAX_int32_T - q0)) {
          q0 = MAX_int32_T;
        } else {
          q0 += q1;
        }

        consequentOutputs->data[numMFs + consequentOutputs->size[0] * outputID] =
          outputMFCache->data[q0 - 1] * antecedentOutputs->data[numMFs];
      }
    }
  }

  emxFree_real_T(&outputMFCache);
}

/*
 * File trailer for applySugenoImplicationMethod.c
 *
 * [EOF]
 */
