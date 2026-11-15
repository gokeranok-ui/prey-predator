/*
 * File: packageAndSetDataType.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <math.h>
#include <stdio.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "packageAndSetDataType.h"
#include "applyMamdaniImplicationMethod.h"
#include "opkene_emxutil.h"
#include "char.h"
#include "strcmp.h"
#include "opkene_rtwutil.h"

/* Function Declarations */
static void makeHomogenousMF(const h_emxArray_struct_T *in, f_emxArray_struct_T *
  out);

/* Function Definitions */

/*
 * Arguments    : const h_emxArray_struct_T *in
 *                f_emxArray_struct_T *out
 * Return Type  : void
 */
static void makeHomogenousMF(const h_emxArray_struct_T *in, f_emxArray_struct_T *
  out)
{
  e_struct_T mfStruct;
  f_struct_T varStruct;
  int i57;
  int outsize_idx_1;
  double maxNumMF;
  double maxMFTypeLength;
  double maxMFParamLength;
  emxArray_real_T *r29;
  int i58;
  int b_outsize_idx_1;
  int mfID;
  int loop_ub;
  int b_loop_ub;
  int loop_ub_tmp;
  emxInitStruct_struct_T1(&mfStruct);
  emxInitStruct_struct_T(&varStruct);
  i57 = mfStruct.type->size[0] * mfStruct.type->size[1];
  mfStruct.type->size[0] = 1;
  mfStruct.type->size[1] = 1;
  emxEnsureCapacity_char_T(mfStruct.type, i57);
  mfStruct.type->data[0] = '\x00';
  mfStruct.origTypeLength = 0.0;
  i57 = mfStruct.params->size[0] * mfStruct.params->size[1];
  mfStruct.params->size[0] = 1;
  mfStruct.params->size[1] = 1;
  emxEnsureCapacity_real_T(mfStruct.params, i57);
  mfStruct.params->data[0] = 0.0;
  mfStruct.origParamLength = 0.0;
  i57 = varStruct.mf->size[0] * varStruct.mf->size[1];
  varStruct.mf->size[0] = 1;
  varStruct.mf->size[1] = 1;
  emxEnsureCapacity_struct_T1(varStruct.mf, i57);
  emxCopyStruct_struct_T1(&varStruct.mf->data[0], &mfStruct);
  varStruct.origNumMF = 0.0;
  outsize_idx_1 = in->size[1];
  i57 = out->size[0] * out->size[1];
  out->size[0] = 1;
  out->size[1] = outsize_idx_1;
  emxEnsureCapacity_struct_T(out, i57);
  for (i57 = 0; i57 < outsize_idx_1; i57++) {
    emxCopyStruct_struct_T(&out->data[i57], &varStruct);
  }

  emxFreeStruct_struct_T1(&varStruct);
  maxNumMF = 0.0;
  maxMFTypeLength = 0.0;
  maxMFParamLength = 0.0;
  i57 = in->size[1];
  printf("makeHomogenousMF: starting loop (numVars=%d)\r\n", i57);
  for (outsize_idx_1 = 0; outsize_idx_1 < i57; outsize_idx_1++) {
    printf("makeHomogenousMF: variable %d: origNumMF=%.0f, mf->size[1]=%d, mf->allocatedSize=%d\r\n",
           outsize_idx_1, in->data[outsize_idx_1].origNumMF,
           (int)(in->data[outsize_idx_1].mf ? (in->data[outsize_idx_1].mf->size[0] * in->data[outsize_idx_1].mf->size[1]) : 0),
           (int)(in->data[outsize_idx_1].mf ? in->data[outsize_idx_1].mf->allocatedSize : 0));
    if (maxNumMF < in->data[outsize_idx_1].origNumMF) {
      maxNumMF = in->data[outsize_idx_1].origNumMF;
    }

    i58 = (int)in->data[outsize_idx_1].origNumMF;
    for (mfID = 0; mfID < i58; mfID++) {
      if (maxMFTypeLength < in->data[outsize_idx_1].mf->data[mfID].
          origTypeLength) {
        maxMFTypeLength = in->data[outsize_idx_1].mf->data[mfID].origTypeLength;
      }

      if (maxMFParamLength < in->data[outsize_idx_1].mf->data[mfID].
          origParamLength) {
        maxMFParamLength = in->data[outsize_idx_1].mf->data[mfID].
          origParamLength;
      }
    }
  }

  i57 = in->size[1];
  emxInit_real_T(&r29, 2);
  printf("makeHomogenousMF: maxNumMF=%.0f, b_outsize_idx_1=%d\r\n", maxNumMF, (int)maxNumMF);
  if (0 <= i57 - 1) {
    b_outsize_idx_1 = (int)maxNumMF;
    loop_ub = b_outsize_idx_1 - 1;
  }
  printf("makeHomogenousMF: setting mf->size[1]=%d for all variables\r\n", b_outsize_idx_1);

  for (outsize_idx_1 = 0; outsize_idx_1 < i57; outsize_idx_1++) {
    out->data[outsize_idx_1].origNumMF = in->data[outsize_idx_1].origNumMF;
    i58 = out->data[outsize_idx_1].mf->size[0] * out->data[outsize_idx_1]
      .mf->size[1];
    out->data[outsize_idx_1].mf->size[0] = 1;
    out->data[outsize_idx_1].mf->size[1] = b_outsize_idx_1;
    emxEnsureCapacity_struct_T1(out->data[outsize_idx_1].mf, i58);
    for (i58 = 0; i58 <= loop_ub; i58++) {
      emxCopyStruct_struct_T1(&out->data[outsize_idx_1].mf->data[i58], &mfStruct);
    }

    for (mfID = 0; mfID < b_outsize_idx_1; mfID++) {
      i58 = r29->size[0] * r29->size[1];
      r29->size[0] = 1;
      b_loop_ub = (int)maxMFTypeLength;
      r29->size[1] = b_loop_ub;
      emxEnsureCapacity_real_T(r29, i58);
      for (i58 = 0; i58 < b_loop_ub; i58++) {
        r29->data[i58] = 0.0;
      }

      c_char(r29, out->data[outsize_idx_1].mf->data[mfID].type);
      loop_ub_tmp = (int)maxMFParamLength;
      b_loop_ub = loop_ub_tmp - 1;
      i58 = out->data[outsize_idx_1].mf->data[mfID].params->size[0] * out->
        data[outsize_idx_1].mf->data[mfID].params->size[1];
      out->data[outsize_idx_1].mf->data[mfID].params->size[0] = 1;
      out->data[outsize_idx_1].mf->data[mfID].params->size[1] = loop_ub_tmp;
      emxEnsureCapacity_real_T(out->data[outsize_idx_1].mf->data[mfID].params,
        i58);
      for (i58 = 0; i58 <= b_loop_ub; i58++) {
        out->data[outsize_idx_1].mf->data[mfID].params->data[i58] = 0.0;
      }

      out->data[outsize_idx_1].mf->data[mfID].origTypeLength = 0.0;
      out->data[outsize_idx_1].mf->data[mfID].origParamLength = 0.0;
      if (1.0 + (double)mfID <= out->data[outsize_idx_1].origNumMF) {
        i58 = out->data[outsize_idx_1].mf->data[mfID].type->size[0] * out->
          data[outsize_idx_1].mf->data[mfID].type->size[1];
        out->data[outsize_idx_1].mf->data[mfID].type->size[0] = 1;
        out->data[outsize_idx_1].mf->data[mfID].type->size[1] = in->
          data[outsize_idx_1].mf->data[mfID].type->size[1];
        emxEnsureCapacity_char_T(out->data[outsize_idx_1].mf->data[mfID].type,
          i58);
        b_loop_ub = in->data[outsize_idx_1].mf->data[mfID].type->size[0] *
          in->data[outsize_idx_1].mf->data[mfID].type->size[1];
        for (i58 = 0; i58 < b_loop_ub; i58++) {
          out->data[outsize_idx_1].mf->data[mfID].type->data[i58] = in->
            data[outsize_idx_1].mf->data[mfID].type->data[i58];
        }

        out->data[outsize_idx_1].mf->data[mfID].origTypeLength = in->
          data[outsize_idx_1].mf->data[mfID].origTypeLength;
        i58 = out->data[outsize_idx_1].mf->data[mfID].params->size[0] *
          out->data[outsize_idx_1].mf->data[mfID].params->size[1];
        out->data[outsize_idx_1].mf->data[mfID].params->size[0] = 1;
        out->data[outsize_idx_1].mf->data[mfID].params->size[1] = in->
          data[outsize_idx_1].mf->data[mfID].params->size[1];
        emxEnsureCapacity_real_T(out->data[outsize_idx_1].mf->data[mfID].params,
          i58);
        b_loop_ub = in->data[outsize_idx_1].mf->data[mfID].params->size[0] *
          in->data[outsize_idx_1].mf->data[mfID].params->size[1];
        for (i58 = 0; i58 < b_loop_ub; i58++) {
          out->data[outsize_idx_1].mf->data[mfID].params->data[i58] = in->
            data[outsize_idx_1].mf->data[mfID].params->data[i58];
        }

        out->data[outsize_idx_1].mf->data[mfID].origParamLength = in->
          data[outsize_idx_1].mf->data[mfID].origParamLength;
      }
    }
  }

  emxFree_real_T(&r29);
  emxFreeStruct_struct_T(&mfStruct);
}

/*
 * Arguments    : const emxArray_char_T *fisin_type
 *                const emxArray_char_T *fisin_andMethod
 *                const emxArray_char_T *fisin_orMethod
 *                const emxArray_char_T *fisin_defuzzMethod
 *                const emxArray_char_T *fisin_impMethod
 *                const emxArray_char_T *fisin_aggMethod
 *                const h_emxArray_struct_T *fisin_input
 *                const h_emxArray_struct_T *fisin_output
 *                const b_emxArray_struct_T *fisin_rule
 *                j_struct_T *fisout
 * Return Type  : void
 */
void packageData(const emxArray_char_T *fisin_type, const emxArray_char_T
                 *fisin_andMethod, const emxArray_char_T *fisin_orMethod, const
                 emxArray_char_T *fisin_defuzzMethod, const emxArray_char_T
                 *fisin_impMethod, const emxArray_char_T *fisin_aggMethod, const
                 h_emxArray_struct_T *fisin_input, const h_emxArray_struct_T
                 *fisin_output, const b_emxArray_struct_T *fisin_rule,
                 j_struct_T *fisout)
{
  int i55;
  int loop_ub;
  emxArray_real_T *numInputMFs;
  int i56;
  emxArray_real_T *numOutputMFs;
  int ruleID;
  emxArray_real_T *x;
  double d1;
  double y[51];
  double delta1;
  double delta2;
  i55 = fisout->type->size[0] * fisout->type->size[1];
  fisout->type->size[0] = 1;
  fisout->type->size[1] = fisin_type->size[1];
  emxEnsureCapacity_char_T(fisout->type, i55);
  loop_ub = fisin_type->size[0] * fisin_type->size[1];
  for (i55 = 0; i55 < loop_ub; i55++) {
    fisout->type->data[i55] = fisin_type->data[i55];
  }

  i55 = fisout->andMethod->size[0] * fisout->andMethod->size[1];
  fisout->andMethod->size[0] = 1;
  fisout->andMethod->size[1] = fisin_andMethod->size[1];
  emxEnsureCapacity_char_T(fisout->andMethod, i55);
  loop_ub = fisin_andMethod->size[0] * fisin_andMethod->size[1];
  for (i55 = 0; i55 < loop_ub; i55++) {
    fisout->andMethod->data[i55] = fisin_andMethod->data[i55];
  }

  i55 = fisout->orMethod->size[0] * fisout->orMethod->size[1];
  fisout->orMethod->size[0] = 1;
  fisout->orMethod->size[1] = fisin_orMethod->size[1];
  emxEnsureCapacity_char_T(fisout->orMethod, i55);
  loop_ub = fisin_orMethod->size[0] * fisin_orMethod->size[1];
  for (i55 = 0; i55 < loop_ub; i55++) {
    fisout->orMethod->data[i55] = fisin_orMethod->data[i55];
  }

  i55 = fisout->defuzzMethod->size[0] * fisout->defuzzMethod->size[1];
  fisout->defuzzMethod->size[0] = 1;
  fisout->defuzzMethod->size[1] = fisin_defuzzMethod->size[1];
  emxEnsureCapacity_char_T(fisout->defuzzMethod, i55);
  loop_ub = fisin_defuzzMethod->size[0] * fisin_defuzzMethod->size[1];
  for (i55 = 0; i55 < loop_ub; i55++) {
    fisout->defuzzMethod->data[i55] = fisin_defuzzMethod->data[i55];
  }

  i55 = fisout->impMethod->size[0] * fisout->impMethod->size[1];
  fisout->impMethod->size[0] = 1;
  fisout->impMethod->size[1] = fisin_impMethod->size[1];
  emxEnsureCapacity_char_T(fisout->impMethod, i55);
  loop_ub = fisin_impMethod->size[0] * fisin_impMethod->size[1];
  for (i55 = 0; i55 < loop_ub; i55++) {
    fisout->impMethod->data[i55] = fisin_impMethod->data[i55];
  }

  i55 = fisout->aggMethod->size[0] * fisout->aggMethod->size[1];
  fisout->aggMethod->size[0] = 1;
  fisout->aggMethod->size[1] = fisin_aggMethod->size[1];
  emxEnsureCapacity_char_T(fisout->aggMethod, i55);
  loop_ub = fisin_aggMethod->size[0] * fisin_aggMethod->size[1];
  for (i55 = 0; i55 < loop_ub; i55++) {
    fisout->aggMethod->data[i55] = fisin_aggMethod->data[i55];
  }

  makeHomogenousMF(fisin_input, fisout->inputMF);
  makeHomogenousMF(fisin_output, fisout->outputMF);
  i55 = fisout->inputRange->size[0] * fisout->inputRange->size[1];
  fisout->inputRange->size[0] = fisin_input->size[1];
  fisout->inputRange->size[1] = 2;
  emxEnsureCapacity_real_T(fisout->inputRange, i55);
  loop_ub = fisin_input->size[1] << 1;
  for (i55 = 0; i55 < loop_ub; i55++) {
    fisout->inputRange->data[i55] = 0.0;
  }

  i55 = fisin_input->size[1];
  for (loop_ub = 0; loop_ub < i55; loop_ub++) {
    fisout->inputRange->data[loop_ub] = fisin_input->data[loop_ub].range[0];
    fisout->inputRange->data[loop_ub + fisout->inputRange->size[0]] =
      fisin_input->data[loop_ub].range[1];
  }

  i55 = fisout->outputRange->size[0] * fisout->outputRange->size[1];
  fisout->outputRange->size[0] = fisin_output->size[1];
  fisout->outputRange->size[1] = 2;
  emxEnsureCapacity_real_T(fisout->outputRange, i55);
  loop_ub = fisin_output->size[1] << 1;
  for (i55 = 0; i55 < loop_ub; i55++) {
    fisout->outputRange->data[i55] = 0.0;
  }

  i55 = fisin_output->size[1];
  for (loop_ub = 0; loop_ub < i55; loop_ub++) {
    fisout->outputRange->data[loop_ub] = fisin_output->data[loop_ub].range[0];
    fisout->outputRange->data[loop_ub + fisout->outputRange->size[0]] =
      fisin_output->data[loop_ub].range[1];
  }

  emxInit_real_T(&numInputMFs, 2);
  i55 = fisin_input->size[1];
  i56 = numInputMFs->size[0] * numInputMFs->size[1];
  numInputMFs->size[0] = 1;
  numInputMFs->size[1] = fisin_input->size[1];
  emxEnsureCapacity_real_T(numInputMFs, i56);
  for (loop_ub = 0; loop_ub < i55; loop_ub++) {
    numInputMFs->data[loop_ub] = fisin_input->data[loop_ub].origNumMF;
  }

  emxInit_real_T(&numOutputMFs, 2);
  i55 = fisin_output->size[1];
  i56 = numOutputMFs->size[0] * numOutputMFs->size[1];
  numOutputMFs->size[0] = 1;
  numOutputMFs->size[1] = fisin_output->size[1];
  emxEnsureCapacity_real_T(numOutputMFs, i56);
  for (loop_ub = 0; loop_ub < i55; loop_ub++) {
    numOutputMFs->data[loop_ub] = fisin_output->data[loop_ub].origNumMF;
  }

  i55 = fisout->antecedent->size[0] * fisout->antecedent->size[1];
  fisout->antecedent->size[0] = fisin_rule->size[1];
  fisout->antecedent->size[1] = fisin_input->size[1];
  emxEnsureCapacity_real_T(fisout->antecedent, i55);
  loop_ub = fisin_rule->size[1] * fisin_input->size[1];
  for (i55 = 0; i55 < loop_ub; i55++) {
    fisout->antecedent->data[i55] = 0.0;
  }

  i55 = fisin_rule->size[1];
  for (ruleID = 0; ruleID < i55; ruleID++) {
    loop_ub = fisin_rule->data[ruleID].antecedent->size[1];
    for (i56 = 0; i56 < loop_ub; i56++) {
      fisout->antecedent->data[ruleID + fisout->antecedent->size[0] * i56] =
        fisin_rule->data[ruleID].antecedent->data[i56];
    }
  }

  i55 = fisout->consequent->size[0] * fisout->consequent->size[1];
  fisout->consequent->size[0] = fisin_rule->size[1];
  fisout->consequent->size[1] = fisin_output->size[1];
  emxEnsureCapacity_real_T(fisout->consequent, i55);
  loop_ub = fisin_rule->size[1] * fisin_output->size[1];
  for (i55 = 0; i55 < loop_ub; i55++) {
    fisout->consequent->data[i55] = 0.0;
  }

  i55 = fisin_rule->size[1];
  for (ruleID = 0; ruleID < i55; ruleID++) {
    loop_ub = fisin_rule->data[ruleID].consequent->size[1];
    for (i56 = 0; i56 < loop_ub; i56++) {
      double raw_value = fisin_rule->data[ruleID].consequent->data[i56];
      printf("packageData: raw consequent[rule %d][out %d] = %.0f\r\n",
             ruleID + 1, i56 + 1, raw_value);
      fisout->consequent->data[ruleID + fisout->consequent->size[0] * i56] =
        raw_value;
    }
  }

  printf("packageData: consequent matrix (rules=%d, outputs=%d)\r\n",
         fisout->consequent->size[0], fisout->consequent->size[1]);
  for (ruleID = 0; ruleID < fisout->consequent->size[0]; ruleID++) {
    for (i56 = 0; i56 < fisout->consequent->size[1]; i56++) {
      double stored = fisout->consequent->data[ruleID +
                        fisout->consequent->size[0] * i56];
      printf("  consequent[rule %d][out %d] = %.0f\r\n",
             ruleID + 1, i56 + 1, stored);
    }
  }

  i55 = fisout->connection->size[0] * fisout->connection->size[1];
  fisout->connection->size[0] = 1;
  fisout->connection->size[1] = fisin_rule->size[1];
  emxEnsureCapacity_real_T(fisout->connection, i55);
  loop_ub = fisin_rule->size[1];
  for (i55 = 0; i55 < loop_ub; i55++) {
    fisout->connection->data[i55] = 0.0;
  }

  i55 = fisin_rule->size[1];
  for (ruleID = 0; ruleID < i55; ruleID++) {
    fisout->connection->data[ruleID] = fisin_rule->data[ruleID].connection;
  }

  i55 = fisout->weight->size[0] * fisout->weight->size[1];
  fisout->weight->size[0] = 1;
  fisout->weight->size[1] = fisin_rule->size[1];
  emxEnsureCapacity_real_T(fisout->weight, i55);
  loop_ub = fisin_rule->size[1];
  for (i55 = 0; i55 < loop_ub; i55++) {
    fisout->weight->data[i55] = 0.0;
  }

  i55 = fisin_rule->size[1];
  for (ruleID = 0; ruleID < i55; ruleID++) {
    fisout->weight->data[ruleID] = fisin_rule->data[ruleID].weight;
  }

  fisout->numSamples = 51.0;
  fisout->numInputs = fisin_input->size[1];
  fisout->numOutputs = fisin_output->size[1];
  fisout->numRules = fisin_rule->size[1];
  i55 = fisout->numInputMFs->size[0] * fisout->numInputMFs->size[1];
  fisout->numInputMFs->size[0] = 1;
  fisout->numInputMFs->size[1] = numInputMFs->size[1];
  emxEnsureCapacity_real_T(fisout->numInputMFs, i55);
  loop_ub = numInputMFs->size[0] * numInputMFs->size[1];
  for (i55 = 0; i55 < loop_ub; i55++) {
    fisout->numInputMFs->data[i55] = numInputMFs->data[i55];
  }

  emxInit_real_T(&x, 2);
  i55 = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = numInputMFs->size[1];
  emxEnsureCapacity_real_T(x, i55);
  loop_ub = numInputMFs->size[0] * numInputMFs->size[1];
  for (i55 = 0; i55 < loop_ub; i55++) {
    x->data[i55] = numInputMFs->data[i55];
  }

  if ((numInputMFs->size[1] != 0) && (numInputMFs->size[1] != 1)) {
    i55 = numInputMFs->size[1];
    for (loop_ub = 0; loop_ub <= i55 - 2; loop_ub++) {
      x->data[loop_ub + 1] += x->data[loop_ub];
    }
  }

  i55 = fisout->numCumInputMFs->size[0] * fisout->numCumInputMFs->size[1];
  fisout->numCumInputMFs->size[0] = 1;
  fisout->numCumInputMFs->size[1] = x->size[1];
  emxEnsureCapacity_real_T(fisout->numCumInputMFs, i55);
  loop_ub = x->size[0] * x->size[1];
  for (i55 = 0; i55 < loop_ub; i55++) {
    fisout->numCumInputMFs->data[i55] = x->data[i55] - numInputMFs->data[i55];
  }

  emxFree_real_T(&numInputMFs);
  i55 = fisout->numOutputMFs->size[0] * fisout->numOutputMFs->size[1];
  fisout->numOutputMFs->size[0] = 1;
  fisout->numOutputMFs->size[1] = numOutputMFs->size[1];
  emxEnsureCapacity_real_T(fisout->numOutputMFs, i55);
  loop_ub = numOutputMFs->size[0] * numOutputMFs->size[1];
  for (i55 = 0; i55 < loop_ub; i55++) {
    fisout->numOutputMFs->data[i55] = numOutputMFs->data[i55];
  }

  i55 = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = numOutputMFs->size[1];
  emxEnsureCapacity_real_T(x, i55);
  loop_ub = numOutputMFs->size[0] * numOutputMFs->size[1];
  for (i55 = 0; i55 < loop_ub; i55++) {
    x->data[i55] = numOutputMFs->data[i55];
  }

  if ((numOutputMFs->size[1] != 0) && (numOutputMFs->size[1] != 1)) {
    i55 = numOutputMFs->size[1];
    for (loop_ub = 0; loop_ub <= i55 - 2; loop_ub++) {
      x->data[loop_ub + 1] += x->data[loop_ub];
    }
  }

  i55 = fisout->numCumOutputMFs->size[0] * fisout->numCumOutputMFs->size[1];
  fisout->numCumOutputMFs->size[0] = 1;
  fisout->numCumOutputMFs->size[1] = x->size[1];
  emxEnsureCapacity_real_T(fisout->numCumOutputMFs, i55);
  loop_ub = x->size[0] * x->size[1];
  for (i55 = 0; i55 < loop_ub; i55++) {
    fisout->numCumOutputMFs->data[i55] = x->data[i55] - numOutputMFs->data[i55];
  }

  emxFree_real_T(&x);
  emxFree_real_T(&numOutputMFs);
  if (e_strcmp(fisin_type)) {
    i55 = fisout->outputSamplePoints->size[0] * fisout->outputSamplePoints->
      size[1];
    fisout->outputSamplePoints->size[0] = fisin_output->size[1];
    fisout->outputSamplePoints->size[1] = 51;
    emxEnsureCapacity_real_T(fisout->outputSamplePoints, i55);
    loop_ub = fisin_output->size[1] * 51;
    for (i55 = 0; i55 < loop_ub; i55++) {
      fisout->outputSamplePoints->data[i55] = 0.0;
    }

    i55 = fisin_output->size[1];
    for (ruleID = 0; ruleID < i55; ruleID++) {
      d1 = fisin_output->data[ruleID].range[0];
      y[50] = fisin_output->data[ruleID].range[1];
      y[0] = fisin_output->data[ruleID].range[0];
      if (((fisin_output->data[ruleID].range[0] < 0.0) != (fisin_output->
            data[ruleID].range[1] < 0.0)) && ((fabs(fisin_output->data[ruleID].
             range[0]) > 8.9884656743115785E+307) || (fabs(fisin_output->
             data[ruleID].range[1]) > 8.9884656743115785E+307))) {
        delta1 = fisin_output->data[ruleID].range[0] / 50.0;
        delta2 = fisin_output->data[ruleID].range[1] / 50.0;
        for (loop_ub = 0; loop_ub < 49; loop_ub++) {
          y[loop_ub + 1] = (d1 + delta2 * (1.0 + (double)loop_ub)) - delta1 *
            (1.0 + (double)loop_ub);
        }
      } else {
        delta1 = (fisin_output->data[ruleID].range[1] - fisin_output->
                  data[ruleID].range[0]) / 50.0;
        for (loop_ub = 0; loop_ub < 49; loop_ub++) {
          y[loop_ub + 1] = d1 + (1.0 + (double)loop_ub) * delta1;
        }
      }

      for (i56 = 0; i56 < 51; i56++) {
        fisout->outputSamplePoints->data[ruleID + fisout->
          outputSamplePoints->size[0] * i56] = y[i56];
      }
    }

    fisout->orrSize[0] = 51.0;
    fisout->orrSize[1] = (double)fisin_rule->size[1] * (double)
      fisin_output->size[1];
    fisout->aggSize[0] = 51.0;
    fisout->aggSize[1] = fisin_output->size[1];
  } else {
    i55 = fisout->outputSamplePoints->size[0] * fisout->outputSamplePoints->
      size[1];
    fisout->outputSamplePoints->size[0] = 1;
    fisout->outputSamplePoints->size[1] = 1;
    emxEnsureCapacity_real_T(fisout->outputSamplePoints, i55);
    fisout->outputSamplePoints->data[0] = 0.0;
    fisout->orrSize[0] = (unsigned int)fisin_rule->size[1];
    fisout->orrSize[1] = (unsigned int)fisin_output->size[1];
    fisout->aggSize[0] = 1.0;
    fisout->aggSize[1] = fisin_output->size[1];
  }
}

/*
 * Arguments    : const f_emxArray_struct_T *in
 *                d_emxArray_struct_T *out
 * Return Type  : void
 */
void setMFDataType(const f_emxArray_struct_T *in, d_emxArray_struct_T *out)
{
  printf("setMFDataType: function started\r\n");
  emxArray_real_T *r30;
  int i59;
  int outsize_idx_1;
  c_struct_T mfStruct;
  d_struct_T varStruct;
  int varID;
  double d4;
  int i60;
  int mfID;
  int i61;
  printf("setMFDataType: initializing r30 array\r\n");
  emxInit_real_T(&r30, 2);
  printf("setMFDataType: r30 initialized\r\n");
  printf("setMFDataType: calculating r30 size\r\n");
  i59 = r30->size[0] * r30->size[1];
  printf("setMFDataType: r30 size calculated (i59=%d)\r\n", i59);
  printf("setMFDataType: setting r30->size[0] = 1\r\n");
  r30->size[0] = 1;
  printf("setMFDataType: checking in pointer\r\n");
  if (in == NULL) {
    printf("setMFDataType: ERROR - in is NULL!\r\n");
    return;
  }
  printf("setMFDataType: checking in->data\r\n");
  if (in->data == NULL) {
    printf("setMFDataType: ERROR - in->data is NULL!\r\n");
    return;
  }
  printf("setMFDataType: checking in->data[0].mf\r\n");
  if (in->data[0].mf == NULL) {
    printf("setMFDataType: ERROR - in->data[0].mf is NULL!\r\n");
    return;
  }
  printf("setMFDataType: checking in->data[0].mf->data\r\n");
  if (in->data[0].mf->data == NULL) {
    printf("setMFDataType: ERROR - in->data[0].mf->data is NULL!\r\n");
    return;
  }
  printf("setMFDataType: checking in->data[0].mf->data[0].type\r\n");
  if (in->data[0].mf->data[0].type == NULL) {
    printf("setMFDataType: ERROR - in->data[0].mf->data[0].type is NULL!\r\n");
    return;
  }
  printf("setMFDataType: accessing in->data[0].mf->data[0].type->size[1]\r\n");
  r30->size[1] = in->data[0].mf->data[0].type->size[1];
  printf("setMFDataType: accessed type size[1]=%d\r\n", (int)in->data[0].mf->data[0].type->size[1]);
  printf("setMFDataType: ensuring capacity for r30 (size=%d)\r\n", (int)in->data[0].mf->data[0].type->size[1]);
  emxEnsureCapacity_real_T(r30, i59);
  printf("setMFDataType: capacity ensured for r30\r\n");
  outsize_idx_1 = in->data[0].mf->data[0].type->size[1];
  printf("setMFDataType: zeroing r30 array (size=%d)\r\n", outsize_idx_1);
  for (i59 = 0; i59 < outsize_idx_1; i59++) {
    r30->data[i59] = 0.0;
  }
  printf("setMFDataType: r30 array zeroed\r\n");
  printf("setMFDataType: initializing mfStruct\r\n");

  emxInitStruct_struct_T3(&mfStruct);
  printf("setMFDataType: mfStruct initialized\r\n");
  printf("setMFDataType: calling c_char\r\n");
  c_char(r30, mfStruct.type);
  printf("setMFDataType: c_char completed\r\n");
  mfStruct.origTypeLength = 0;
  i59 = mfStruct.params->size[0] * mfStruct.params->size[1];
  mfStruct.params->size[0] = 1;
  mfStruct.params->size[1] = in->data[0].mf->data[0].params->size[1];
  printf("setMFDataType: ensuring capacity for mfStruct.params (size=%d)\r\n", (int)in->data[0].mf->data[0].params->size[1]);
  emxEnsureCapacity_real_T(mfStruct.params, i59);
  outsize_idx_1 = in->data[0].mf->data[0].params->size[1];
  printf("setMFDataType: freeing r30\r\n");
  emxFree_real_T(&r30);
  printf("setMFDataType: zeroing mfStruct.params (size=%d)\r\n", outsize_idx_1);
  for (i59 = 0; i59 < outsize_idx_1; i59++) {
    mfStruct.params->data[i59] = 0.0;
  }
  printf("setMFDataType: mfStruct.params zeroed\r\n");
  printf("setMFDataType: initializing varStruct\r\n");

  emxInitStruct_struct_T2(&varStruct);
  printf("setMFDataType: varStruct initialized\r\n");
  mfStruct.origParamLength = 0;
  outsize_idx_1 = in->data[0].mf->size[1];
  printf("setMFDataType: ensuring capacity for varStruct.mf (size=%d)\r\n", outsize_idx_1);
  i59 = varStruct.mf->size[0] * varStruct.mf->size[1];
  varStruct.mf->size[0] = 1;
  varStruct.mf->size[1] = outsize_idx_1;
  emxEnsureCapacity_struct_T3(varStruct.mf, i59);
  printf("setMFDataType: copying mfStruct to varStruct.mf (loop_ub=%d)\r\n", outsize_idx_1);
  for (i59 = 0; i59 < outsize_idx_1; i59++) {
    emxCopyStruct_struct_T3(&varStruct.mf->data[i59], &mfStruct);
  }
  printf("setMFDataType: mfStruct copied to varStruct.mf\r\n");
  printf("setMFDataType: freeing mfStruct\r\n");

  emxFreeStruct_struct_T2(&mfStruct);
  varStruct.origNumMF = 0;
  outsize_idx_1 = in->size[1];
  printf("setMFDataType: ensuring capacity for output (size=%d)\r\n", outsize_idx_1);
  i59 = out->size[0] * out->size[1];
  out->size[0] = 1;
  out->size[1] = outsize_idx_1;
  emxEnsureCapacity_struct_T2(out, i59);
  printf("setMFDataType: copying varStruct to output (loop_ub=%d)\r\n", outsize_idx_1);
  for (i59 = 0; i59 < outsize_idx_1; i59++) {
    emxCopyStruct_struct_T2(&out->data[i59], &varStruct);
  }
  printf("setMFDataType: varStruct copied to output\r\n");
  printf("setMFDataType: freeing varStruct\r\n");

  emxFreeStruct_struct_T3(&varStruct);
  printf("setMFDataType: varStruct freed\r\n");
  i59 = in->size[1];
  printf("setMFDataType: starting variable loop (numVars=%d)\r\n", i59);
  for (varID = 0; varID < i59; varID++) {
    printf("setMFDataType: processing variable %d/%d\r\n", varID + 1, i59);
    d4 = rt_roundd_snf(in->data[varID].origNumMF);
    if (d4 < 2.147483648E+9) {
      if (d4 >= -2.147483648E+9) {
        i60 = (int)d4;
      } else {
        i60 = MIN_int32_T;
      }
    } else if (d4 >= 2.147483648E+9) {
      i60 = MAX_int32_T;
    } else {
      i60 = 0;
    }

    out->data[varID].origNumMF = i60;
    i60 = in->data[0].mf->size[1];
    printf("setMFDataType: starting MF loop for variable %d (numMFs=%d)\r\n", varID + 1, i60);
    for (mfID = 0; mfID < i60; mfID++) {
      if (mfID == 0 || mfID % 10 == 0) {
        printf("setMFDataType: processing MF %d/%d for variable %d\r\n", mfID + 1, i60, varID + 1);
      }
      i61 = out->data[varID].mf->data[mfID].type->size[0] * out->data[varID].
        mf->data[mfID].type->size[1];
      out->data[varID].mf->data[mfID].type->size[0] = 1;
      out->data[varID].mf->data[mfID].type->size[1] = in->data[varID].mf->
        data[mfID].type->size[1];
      emxEnsureCapacity_char_T(out->data[varID].mf->data[mfID].type, i61);
      outsize_idx_1 = in->data[varID].mf->data[mfID].type->size[0] * in->
        data[varID].mf->data[mfID].type->size[1];
      for (i61 = 0; i61 < outsize_idx_1; i61++) {
        out->data[varID].mf->data[mfID].type->data[i61] = in->data[varID]
          .mf->data[mfID].type->data[i61];
      }

      i61 = out->data[varID].mf->data[mfID].params->size[0] * out->data[varID].
        mf->data[mfID].params->size[1];
      out->data[varID].mf->data[mfID].params->size[0] = 1;
      out->data[varID].mf->data[mfID].params->size[1] = in->data[varID].mf->
        data[mfID].params->size[1];
      emxEnsureCapacity_real_T(out->data[varID].mf->data[mfID].params, i61);
      outsize_idx_1 = in->data[varID].mf->data[mfID].params->size[0] * in->
        data[varID].mf->data[mfID].params->size[1];
      for (i61 = 0; i61 < outsize_idx_1; i61++) {
        out->data[varID].mf->data[mfID].params->data[i61] = in->data[varID]
          .mf->data[mfID].params->data[i61];
      }

      d4 = rt_roundd_snf(in->data[varID].mf->data[mfID].origTypeLength);
      if (d4 < 2.147483648E+9) {
        if (d4 >= -2.147483648E+9) {
          i61 = (int)d4;
        } else {
          i61 = MIN_int32_T;
        }
      } else if (d4 >= 2.147483648E+9) {
        i61 = MAX_int32_T;
      } else {
        i61 = 0;
      }

      out->data[varID].mf->data[mfID].origTypeLength = i61;
      d4 = rt_roundd_snf(in->data[varID].mf->data[mfID].origParamLength);
      if (d4 < 2.147483648E+9) {
        if (d4 >= -2.147483648E+9) {
          i61 = (int)d4;
        } else {
          i61 = MIN_int32_T;
        }
      } else if (d4 >= 2.147483648E+9) {
        i61 = MAX_int32_T;
      } else {
        i61 = 0;
      }

      out->data[varID].mf->data[mfID].origParamLength = i61;
    }
    printf("setMFDataType: completed variable %d\r\n", varID + 1);
  }
  printf("setMFDataType: function completed\r\n");
}

/*
 * File trailer for packageAndSetDataType.c
 *
 * [EOF]
 */
