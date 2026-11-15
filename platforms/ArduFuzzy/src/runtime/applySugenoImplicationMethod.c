/*
 * File: applySugenoImplicationMethod.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "applySugenoImplicationMethod.h"
#include "extractVarMF.h"
#include "isequal.h"
#include "opkene_emxutil.h"
#include "opkene_rtwutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"
#include "sum.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *inputs
 *                const emxArray_real_T *antecedentOutputs
 *                const e_emxArray_struct_T *fis_outputMF
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
void applySugenoImplicationMethod(
    const emxArray_real_T *inputs, const emxArray_real_T *antecedentOutputs,
    const e_emxArray_struct_T *fis_outputMF,
    const emxArray_real_T *fis_consequent, int fis_numOutputs, int fis_numRules,
    const emxArray_int32_T *fis_numOutputMFs,
    const emxArray_int32_T *fis_numCumOutputMFs, const int fis_orrSize[2],
    emxArray_real_T *consequentOutputs, emxArray_real_T *unscaledOutputs)
{
  static const unsigned char uv[8] = {99U,  111U, 110U, 115U,
                                      116U, 97U,  110U, 116U};
  cell_wrap_0 *outVarMF_data;
  emxArray_cell_wrap_0 *outVarMF;
  emxArray_real_T *outputMFCache;
  const double *antecedentOutputs_data;
  const double *fis_consequent_data;
  const double *inputs_data;
  double y;
  double *consequentOutputs_data;
  double *outputMFCache_data;
  double *unscaledOutputs_data;
  const int *fis_numCumOutputMFs_data;
  const int *fis_numOutputMFs_data;
  int b_i;
  int i;
  int i1;
  int mfID;
  int numMFs;
  int outputID;
  unsigned int u;
  fis_numCumOutputMFs_data = fis_numCumOutputMFs->data;
  fis_numOutputMFs_data = fis_numOutputMFs->data;
  fis_consequent_data = fis_consequent->data;
  antecedentOutputs_data = antecedentOutputs->data;
  inputs_data = inputs->data;
  i = consequentOutputs->size[0] * consequentOutputs->size[1];
  consequentOutputs->size[0] = fis_orrSize[0];
  consequentOutputs->size[1] = fis_orrSize[1];
  emxEnsureCapacity_real_T(consequentOutputs, i);
  consequentOutputs_data = consequentOutputs->data;
  numMFs = fis_orrSize[0] * fis_orrSize[1];
  for (i = 0; i < numMFs; i++) {
    consequentOutputs_data[i] = 0.0;
  }
  i = unscaledOutputs->size[0] * unscaledOutputs->size[1];
  unscaledOutputs->size[0] = fis_orrSize[0];
  unscaledOutputs->size[1] = fis_orrSize[1];
  emxEnsureCapacity_real_T(unscaledOutputs, i);
  unscaledOutputs_data = unscaledOutputs->data;
  for (i = 0; i < numMFs; i++) {
    unscaledOutputs_data[i] = 0.0;
  }
  emxInit_real_T(&outputMFCache, 1);
  numMFs = (int)sum(fis_numOutputMFs);
  i = outputMFCache->size[0];
  outputMFCache->size[0] = (int)sum(fis_numOutputMFs);
  emxEnsureCapacity_real_T(outputMFCache, i);
  outputMFCache_data = outputMFCache->data;
  for (i = 0; i < numMFs; i++) {
    outputMFCache_data[i] = 0.0;
  }
  emxInit_cell_wrap_0(&outVarMF);
  extractVarMF(fis_outputMF, outVarMF);
  outVarMF_data = outVarMF->data;
  u = (unsigned int)fis_numOutputs;
  if ((unsigned int)fis_numOutputs > 2147483647UL) {
    u = 2147483647UL;
  }
  i = (int)u;
  for (outputID = 0; outputID < i; outputID++) {
    numMFs = fis_numOutputMFs_data[outputID];
    for (mfID = 0; mfID < numMFs; mfID++) {
      if (f_isequal(outVarMF_data[outputID].f1->data[mfID].type, uv)) {
        b_i = fis_numCumOutputMFs_data[outputID];
        if ((b_i < 0) && (mfID + 1 < MIN_int32_T - b_i)) {
          b_i = MIN_int32_T;
        } else if ((b_i > 0) && (mfID + 1 > MAX_int32_T - b_i)) {
          b_i = MAX_int32_T;
        } else {
          b_i = (b_i + mfID) + 1;
        }
        outputMFCache_data[b_i - 1] =
            outVarMF_data[outputID].f1->data[mfID].params->data[0];
      } else {
        y = 0.0;
        i1 = inputs->size[1];
        for (b_i = 0; b_i < i1; b_i++) {
          y += inputs_data[b_i] *
               outVarMF_data[outputID].f1->data[mfID].params->data[b_i];
        }
        b_i = fis_numCumOutputMFs_data[outputID];
        if ((b_i < 0) && (mfID + 1 < MIN_int32_T - b_i)) {
          b_i = MIN_int32_T;
        } else if ((b_i > 0) && (mfID + 1 > MAX_int32_T - b_i)) {
          b_i = MAX_int32_T;
        } else {
          b_i = (b_i + mfID) + 1;
        }
        outputMFCache_data[b_i - 1] = y + outVarMF_data[outputID]
                                              .f1->data[mfID]
                                              .params->data[inputs->size[1]];
      }
    }
  }
  emxFree_cell_wrap_0(&outVarMF);
  u = (unsigned int)fis_numRules;
  if ((unsigned int)fis_numRules > 2147483647UL) {
    u = 2147483647UL;
  }
  i = (int)u;
  for (mfID = 0; mfID < i; mfID++) {
    u = (unsigned int)fis_numOutputs;
    if ((unsigned int)fis_numOutputs > 2147483647UL) {
      u = 2147483647UL;
    }
    i1 = (int)u;
    for (outputID = 0; outputID < i1; outputID++) {
      y = rt_roundd_snf(
          fis_consequent_data[mfID + fis_consequent->size[0] * outputID]);
      if (y < 2.147483648E+9) {
        if (y >= -2.147483648E+9) {
          numMFs = (int)y;
        } else {
          numMFs = MIN_int32_T;
        }
      } else if (y >= 2.147483648E+9) {
        numMFs = MAX_int32_T;
      } else {
        numMFs = 0;
      }
      if (numMFs != 0) {
        b_i = fis_numCumOutputMFs_data[outputID];
        if ((b_i < 0) && (numMFs < MIN_int32_T - b_i)) {
          numMFs = MIN_int32_T;
          b_i = MIN_int32_T;
        } else if ((b_i > 0) && (numMFs > MAX_int32_T - b_i)) {
          numMFs = MAX_int32_T;
          b_i = MAX_int32_T;
        } else {
          numMFs += b_i;
          b_i = numMFs;
        }
        unscaledOutputs_data[mfID + unscaledOutputs->size[0] * outputID] =
            outputMFCache_data[numMFs - 1];
        consequentOutputs_data[mfID + consequentOutputs->size[0] * outputID] =
            outputMFCache_data[b_i - 1] * antecedentOutputs_data[mfID];
      }
    }
  }
  emxFree_real_T(&outputMFCache);
}

/*
 * Arguments    : double inputs
 *                const emxArray_real_T *antecedentOutputs
 *                const e_emxArray_struct_T *fis_outputMF
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
void b_applySugenoImplicationMethod(
    double inputs, const emxArray_real_T *antecedentOutputs,
    const e_emxArray_struct_T *fis_outputMF,
    const emxArray_real_T *fis_consequent, int fis_numOutputs, int fis_numRules,
    const emxArray_int32_T *fis_numOutputMFs,
    const emxArray_int32_T *fis_numCumOutputMFs, const int fis_orrSize[2],
    emxArray_real_T *consequentOutputs, emxArray_real_T *unscaledOutputs)
{
  static const unsigned char uv[8] = {99U,  111U, 110U, 115U,
                                      116U, 97U,  110U, 116U};
  cell_wrap_0 *outVarMF_data;
  emxArray_cell_wrap_0 *outVarMF;
  emxArray_real_T *outputMFCache;
  const double *antecedentOutputs_data;
  const double *fis_consequent_data;
  double *consequentOutputs_data;
  double *outputMFCache_data;
  double *unscaledOutputs_data;
  const int *fis_numCumOutputMFs_data;
  const int *fis_numOutputMFs_data;
  int i;
  int mfID;
  int numMFs;
  int outputID;
  int q0;
  int ruleID;
  unsigned int u;
  fis_numCumOutputMFs_data = fis_numCumOutputMFs->data;
  fis_numOutputMFs_data = fis_numOutputMFs->data;
  fis_consequent_data = fis_consequent->data;
  antecedentOutputs_data = antecedentOutputs->data;
  i = consequentOutputs->size[0] * consequentOutputs->size[1];
  consequentOutputs->size[0] = fis_orrSize[0];
  consequentOutputs->size[1] = fis_orrSize[1];
  emxEnsureCapacity_real_T(consequentOutputs, i);
  consequentOutputs_data = consequentOutputs->data;
  numMFs = fis_orrSize[0] * fis_orrSize[1];
  for (i = 0; i < numMFs; i++) {
    consequentOutputs_data[i] = 0.0;
  }
  i = unscaledOutputs->size[0] * unscaledOutputs->size[1];
  unscaledOutputs->size[0] = fis_orrSize[0];
  unscaledOutputs->size[1] = fis_orrSize[1];
  emxEnsureCapacity_real_T(unscaledOutputs, i);
  unscaledOutputs_data = unscaledOutputs->data;
  for (i = 0; i < numMFs; i++) {
    unscaledOutputs_data[i] = 0.0;
  }
  emxInit_real_T(&outputMFCache, 1);
  numMFs = (int)sum(fis_numOutputMFs);
  i = outputMFCache->size[0];
  outputMFCache->size[0] = (int)sum(fis_numOutputMFs);
  emxEnsureCapacity_real_T(outputMFCache, i);
  outputMFCache_data = outputMFCache->data;
  for (i = 0; i < numMFs; i++) {
    outputMFCache_data[i] = 0.0;
  }
  emxInit_cell_wrap_0(&outVarMF);
  extractVarMF(fis_outputMF, outVarMF);
  outVarMF_data = outVarMF->data;
  u = (unsigned int)fis_numOutputs;
  if ((unsigned int)fis_numOutputs > 2147483647UL) {
    u = 2147483647UL;
  }
  i = (int)u;
  for (outputID = 0; outputID < i; outputID++) {
    numMFs = fis_numOutputMFs_data[outputID];
    for (mfID = 0; mfID < numMFs; mfID++) {
      if (f_isequal(outVarMF_data[outputID].f1->data[mfID].type, uv)) {
        q0 = fis_numCumOutputMFs_data[outputID];
        if ((q0 < 0) && (mfID + 1 < MIN_int32_T - q0)) {
          q0 = MIN_int32_T;
        } else if ((q0 > 0) && (mfID + 1 > MAX_int32_T - q0)) {
          q0 = MAX_int32_T;
        } else {
          q0 = (q0 + mfID) + 1;
        }
        outputMFCache_data[q0 - 1] =
            outVarMF_data[outputID].f1->data[mfID].params->data[0];
      } else {
        q0 = fis_numCumOutputMFs_data[outputID];
        if ((q0 < 0) && (mfID + 1 < MIN_int32_T - q0)) {
          q0 = MIN_int32_T;
        } else if ((q0 > 0) && (mfID + 1 > MAX_int32_T - q0)) {
          q0 = MAX_int32_T;
        } else {
          q0 = (q0 + mfID) + 1;
        }
        outputMFCache_data[q0 - 1] =
            inputs * outVarMF_data[outputID].f1->data[mfID].params->data[0] +
            outVarMF_data[outputID].f1->data[mfID].params->data[1];
      }
    }
  }
  emxFree_cell_wrap_0(&outVarMF);
  u = (unsigned int)fis_numRules;
  if ((unsigned int)fis_numRules > 2147483647UL) {
    u = 2147483647UL;
  }
  i = (int)u;
  for (ruleID = 0; ruleID < i; ruleID++) {
    u = (unsigned int)fis_numOutputs;
    if ((unsigned int)fis_numOutputs > 2147483647UL) {
      u = 2147483647UL;
    }
    mfID = (int)u;
    for (outputID = 0; outputID < mfID; outputID++) {
      double d;
      d = rt_roundd_snf(
          fis_consequent_data[ruleID + fis_consequent->size[0] * outputID]);
      if (d < 2.147483648E+9) {
        if (d >= -2.147483648E+9) {
          numMFs = (int)d;
        } else {
          numMFs = MIN_int32_T;
        }
      } else if (d >= 2.147483648E+9) {
        numMFs = MAX_int32_T;
      } else {
        numMFs = 0;
      }
      if (numMFs != 0) {
        q0 = fis_numCumOutputMFs_data[outputID];
        if ((q0 < 0) && (numMFs < MIN_int32_T - q0)) {
          numMFs = MIN_int32_T;
          q0 = MIN_int32_T;
        } else if ((q0 > 0) && (numMFs > MAX_int32_T - q0)) {
          numMFs = MAX_int32_T;
          q0 = MAX_int32_T;
        } else {
          numMFs += q0;
          q0 = numMFs;
        }
        unscaledOutputs_data[ruleID + unscaledOutputs->size[0] * outputID] =
            outputMFCache_data[numMFs - 1];
        consequentOutputs_data[ruleID + consequentOutputs->size[0] * outputID] =
            outputMFCache_data[q0 - 1] * antecedentOutputs_data[ruleID];
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
