/*
 * File: opkene.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "opkene_emxutil.h"
#include "evaluateFIS.h"
#include "applyMamdaniImplicationMethod.h"
#include "packageAndSetDataType.h"
#include "getFISCodeGenerationData.h"
#include "opkene_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_char_T *fileName
 *                const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void opkene(const emxArray_char_T *fileName, const emxArray_real_T *x,
            emxArray_real_T *y)
{
  emxArray_char_T *fis_type;
  emxArray_char_T *fis_andMethod;
  emxArray_char_T *fis_orMethod;
  emxArray_char_T *fis_defuzzMethod;
  emxArray_char_T *fis_impMethod;
  emxArray_char_T *fis_aggMethod;
  h_emxArray_struct_T *fis_input;
  h_emxArray_struct_T *fis_output;
  b_emxArray_struct_T *fis_rule;
  emxArray_char_T *b_fis_type;
  emxArray_char_T *expl_temp;
  j_struct_T b_expl_temp;
  int i0;
  int loop_ub;
  emxArray_char_T *b_fis_andMethod;
  emxArray_char_T *b_fis_orMethod;
  emxArray_char_T *b_fis_defuzzMethod;
  emxArray_char_T *b_fis_impMethod;
  emxArray_char_T *b_fis_aggMethod;
  f_emxArray_struct_T *fis_inputMF;
  f_emxArray_struct_T *fis_outputMF;
  emxArray_real_T *fis_inputRange;
  emxArray_real_T *fis_outputRange;
  emxArray_real_T *fis_antecedent;
  emxArray_real_T *fis_consequent;
  emxArray_real_T *fis_connection;
  emxArray_real_T *fis_weight;
  emxArray_real_T *fis_numInputMFs;
  double fis_numInputs;
  double fis_numOutputs;
  double fis_numRules;
  emxArray_real_T *inputValues;
  emxArray_real_T *fis_numOutputMFs;
  emxArray_real_T *fis_numCumOutputMFs;
  emxArray_real_T *fis_outputSamplePoints;
  double fis_orrSize_idx_0;
  double fis_aggSize_idx_0;
  double fis_orrSize_idx_1;
  double fis_aggSize_idx_1;
  emxArray_uint8_T *fish_type;
  emxArray_uint8_T *fish_andMethod;
  emxArray_uint8_T *fish_orMethod;
  emxArray_uint8_T *fish_defuzzMethod;
  emxArray_uint8_T *fish_impMethod;
  emxArray_uint8_T *fish_aggMethod;
  d_emxArray_struct_T *fish_inputMF;
  d_emxArray_struct_T *fish_outputMF;
  emxArray_int32_T *fish_numInputMFs;
  int fish_numInputs;
  int fish_numOutputs;
  int fish_numRules;
  emxArray_int32_T *fish_numCumInputMFs;
  int fish_aggSize_idx_0;
  emxArray_int32_T *fish_numOutputMFs;
  emxArray_int32_T *fish_numCumOutputMFs;
  int fish_orrSize_idx_1;
  int fish_aggSize_idx_1;
  i_struct_T c_expl_temp;
  emxArray_real_T *b_x;
  emxInit_char_T(&fis_type, 2);
  emxInit_char_T(&fis_andMethod, 2);
  emxInit_char_T(&fis_orMethod, 2);
  emxInit_char_T(&fis_defuzzMethod, 2);
  emxInit_char_T(&fis_impMethod, 2);
  emxInit_char_T(&fis_aggMethod, 2);
  emxInit_struct_T2(&fis_input, 2);
  emxInit_struct_T2(&fis_output, 2);
  emxInit_struct_T3(&fis_rule, 2);
  emxInit_char_T(&b_fis_type, 2);
  emxInit_char_T(&expl_temp, 2);
  emxInitStruct_struct_T5(&b_expl_temp);
  getFISCodeGenerationData(fileName, expl_temp, fis_type, fis_andMethod,
    fis_orMethod, fis_defuzzMethod, fis_impMethod, fis_aggMethod, fis_input,
    fis_output, fis_rule);
  packageData(fis_type, fis_andMethod, fis_orMethod, fis_defuzzMethod,
              fis_impMethod, fis_aggMethod, fis_input, fis_output, fis_rule,
              &b_expl_temp);
  i0 = b_fis_type->size[0] * b_fis_type->size[1];
  b_fis_type->size[0] = 1;
  b_fis_type->size[1] = b_expl_temp.type->size[1];
  emxEnsureCapacity_char_T(b_fis_type, i0);
  loop_ub = b_expl_temp.type->size[0] * b_expl_temp.type->size[1];
  emxFree_char_T(&expl_temp);
  emxFree_struct_T4(&fis_rule);
  emxFree_struct_T2(&fis_output);
  emxFree_struct_T2(&fis_input);
  emxFree_char_T(&fis_aggMethod);
  emxFree_char_T(&fis_impMethod);
  emxFree_char_T(&fis_defuzzMethod);
  emxFree_char_T(&fis_orMethod);
  emxFree_char_T(&fis_andMethod);
  emxFree_char_T(&fis_type);
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_fis_type->data[i0] = b_expl_temp.type->data[i0];
  }

  emxInit_char_T(&b_fis_andMethod, 2);
  i0 = b_fis_andMethod->size[0] * b_fis_andMethod->size[1];
  b_fis_andMethod->size[0] = 1;
  b_fis_andMethod->size[1] = b_expl_temp.andMethod->size[1];
  emxEnsureCapacity_char_T(b_fis_andMethod, i0);
  loop_ub = b_expl_temp.andMethod->size[0] * b_expl_temp.andMethod->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_fis_andMethod->data[i0] = b_expl_temp.andMethod->data[i0];
  }

  emxInit_char_T(&b_fis_orMethod, 2);
  i0 = b_fis_orMethod->size[0] * b_fis_orMethod->size[1];
  b_fis_orMethod->size[0] = 1;
  b_fis_orMethod->size[1] = b_expl_temp.orMethod->size[1];
  emxEnsureCapacity_char_T(b_fis_orMethod, i0);
  loop_ub = b_expl_temp.orMethod->size[0] * b_expl_temp.orMethod->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_fis_orMethod->data[i0] = b_expl_temp.orMethod->data[i0];
  }

  emxInit_char_T(&b_fis_defuzzMethod, 2);
  i0 = b_fis_defuzzMethod->size[0] * b_fis_defuzzMethod->size[1];
  b_fis_defuzzMethod->size[0] = 1;
  b_fis_defuzzMethod->size[1] = b_expl_temp.defuzzMethod->size[1];
  emxEnsureCapacity_char_T(b_fis_defuzzMethod, i0);
  loop_ub = b_expl_temp.defuzzMethod->size[0] * b_expl_temp.defuzzMethod->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_fis_defuzzMethod->data[i0] = b_expl_temp.defuzzMethod->data[i0];
  }

  emxInit_char_T(&b_fis_impMethod, 2);
  i0 = b_fis_impMethod->size[0] * b_fis_impMethod->size[1];
  b_fis_impMethod->size[0] = 1;
  b_fis_impMethod->size[1] = b_expl_temp.impMethod->size[1];
  emxEnsureCapacity_char_T(b_fis_impMethod, i0);
  loop_ub = b_expl_temp.impMethod->size[0] * b_expl_temp.impMethod->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_fis_impMethod->data[i0] = b_expl_temp.impMethod->data[i0];
  }

  emxInit_char_T(&b_fis_aggMethod, 2);
  i0 = b_fis_aggMethod->size[0] * b_fis_aggMethod->size[1];
  b_fis_aggMethod->size[0] = 1;
  b_fis_aggMethod->size[1] = b_expl_temp.aggMethod->size[1];
  emxEnsureCapacity_char_T(b_fis_aggMethod, i0);
  loop_ub = b_expl_temp.aggMethod->size[0] * b_expl_temp.aggMethod->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_fis_aggMethod->data[i0] = b_expl_temp.aggMethod->data[i0];
  }

  emxInit_struct_T5(&fis_inputMF, 2);
  i0 = fis_inputMF->size[0] * fis_inputMF->size[1];
  fis_inputMF->size[0] = 1;
  fis_inputMF->size[1] = b_expl_temp.inputMF->size[1];
  emxEnsureCapacity_struct_T(fis_inputMF, i0);
  loop_ub = b_expl_temp.inputMF->size[0] * b_expl_temp.inputMF->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    emxCopyStruct_struct_T(&fis_inputMF->data[i0], &b_expl_temp.inputMF->data[i0]);
  }

  emxInit_struct_T5(&fis_outputMF, 2);
  i0 = fis_outputMF->size[0] * fis_outputMF->size[1];
  fis_outputMF->size[0] = 1;
  fis_outputMF->size[1] = b_expl_temp.outputMF->size[1];
  emxEnsureCapacity_struct_T(fis_outputMF, i0);
  loop_ub = b_expl_temp.outputMF->size[0] * b_expl_temp.outputMF->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    emxCopyStruct_struct_T(&fis_outputMF->data[i0], &b_expl_temp.outputMF->
      data[i0]);
  }

  emxInit_real_T(&fis_inputRange, 2);
  i0 = fis_inputRange->size[0] * fis_inputRange->size[1];
  fis_inputRange->size[0] = b_expl_temp.inputRange->size[0];
  fis_inputRange->size[1] = 2;
  emxEnsureCapacity_real_T(fis_inputRange, i0);
  loop_ub = b_expl_temp.inputRange->size[0] * b_expl_temp.inputRange->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fis_inputRange->data[i0] = b_expl_temp.inputRange->data[i0];
  }

  emxInit_real_T(&fis_outputRange, 2);
  i0 = fis_outputRange->size[0] * fis_outputRange->size[1];
  fis_outputRange->size[0] = b_expl_temp.outputRange->size[0];
  fis_outputRange->size[1] = 2;
  emxEnsureCapacity_real_T(fis_outputRange, i0);
  loop_ub = b_expl_temp.outputRange->size[0] * b_expl_temp.outputRange->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fis_outputRange->data[i0] = b_expl_temp.outputRange->data[i0];
  }

  emxInit_real_T(&fis_antecedent, 2);
  i0 = fis_antecedent->size[0] * fis_antecedent->size[1];
  fis_antecedent->size[0] = b_expl_temp.antecedent->size[0];
  fis_antecedent->size[1] = b_expl_temp.antecedent->size[1];
  emxEnsureCapacity_real_T(fis_antecedent, i0);
  loop_ub = b_expl_temp.antecedent->size[0] * b_expl_temp.antecedent->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fis_antecedent->data[i0] = b_expl_temp.antecedent->data[i0];
  }

  emxInit_real_T(&fis_consequent, 2);
  i0 = fis_consequent->size[0] * fis_consequent->size[1];
  fis_consequent->size[0] = b_expl_temp.consequent->size[0];
  fis_consequent->size[1] = b_expl_temp.consequent->size[1];
  emxEnsureCapacity_real_T(fis_consequent, i0);
  loop_ub = b_expl_temp.consequent->size[0] * b_expl_temp.consequent->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fis_consequent->data[i0] = b_expl_temp.consequent->data[i0];
  }

  emxInit_real_T(&fis_connection, 2);
  i0 = fis_connection->size[0] * fis_connection->size[1];
  fis_connection->size[0] = 1;
  fis_connection->size[1] = b_expl_temp.connection->size[1];
  emxEnsureCapacity_real_T(fis_connection, i0);
  loop_ub = b_expl_temp.connection->size[0] * b_expl_temp.connection->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fis_connection->data[i0] = b_expl_temp.connection->data[i0];
  }

  emxInit_real_T(&fis_weight, 2);
  i0 = fis_weight->size[0] * fis_weight->size[1];
  fis_weight->size[0] = 1;
  fis_weight->size[1] = b_expl_temp.weight->size[1];
  emxEnsureCapacity_real_T(fis_weight, i0);
  loop_ub = b_expl_temp.weight->size[0] * b_expl_temp.weight->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fis_weight->data[i0] = b_expl_temp.weight->data[i0];
  }

  emxInit_real_T(&fis_numInputMFs, 2);
  fis_numInputs = b_expl_temp.numInputs;
  fis_numOutputs = b_expl_temp.numOutputs;
  fis_numRules = b_expl_temp.numRules;
  i0 = fis_numInputMFs->size[0] * fis_numInputMFs->size[1];
  fis_numInputMFs->size[0] = 1;
  fis_numInputMFs->size[1] = b_expl_temp.numInputMFs->size[1];
  emxEnsureCapacity_real_T(fis_numInputMFs, i0);
  loop_ub = b_expl_temp.numInputMFs->size[0] * b_expl_temp.numInputMFs->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fis_numInputMFs->data[i0] = b_expl_temp.numInputMFs->data[i0];
  }

  emxInit_real_T(&inputValues, 2);
  i0 = inputValues->size[0] * inputValues->size[1];
  inputValues->size[0] = 1;
  inputValues->size[1] = b_expl_temp.numCumInputMFs->size[1];
  emxEnsureCapacity_real_T(inputValues, i0);
  loop_ub = b_expl_temp.numCumInputMFs->size[0] *
    b_expl_temp.numCumInputMFs->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    inputValues->data[i0] = b_expl_temp.numCumInputMFs->data[i0];
  }

  emxInit_real_T(&fis_numOutputMFs, 2);
  i0 = fis_numOutputMFs->size[0] * fis_numOutputMFs->size[1];
  fis_numOutputMFs->size[0] = 1;
  fis_numOutputMFs->size[1] = b_expl_temp.numOutputMFs->size[1];
  emxEnsureCapacity_real_T(fis_numOutputMFs, i0);
  loop_ub = b_expl_temp.numOutputMFs->size[0] * b_expl_temp.numOutputMFs->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fis_numOutputMFs->data[i0] = b_expl_temp.numOutputMFs->data[i0];
  }

  emxInit_real_T(&fis_numCumOutputMFs, 2);
  i0 = fis_numCumOutputMFs->size[0] * fis_numCumOutputMFs->size[1];
  fis_numCumOutputMFs->size[0] = 1;
  fis_numCumOutputMFs->size[1] = b_expl_temp.numCumOutputMFs->size[1];
  emxEnsureCapacity_real_T(fis_numCumOutputMFs, i0);
  loop_ub = b_expl_temp.numCumOutputMFs->size[0] *
    b_expl_temp.numCumOutputMFs->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fis_numCumOutputMFs->data[i0] = b_expl_temp.numCumOutputMFs->data[i0];
  }

  emxInit_real_T(&fis_outputSamplePoints, 2);
  i0 = fis_outputSamplePoints->size[0] * fis_outputSamplePoints->size[1];
  fis_outputSamplePoints->size[0] = b_expl_temp.outputSamplePoints->size[0];
  fis_outputSamplePoints->size[1] = b_expl_temp.outputSamplePoints->size[1];
  emxEnsureCapacity_real_T(fis_outputSamplePoints, i0);
  loop_ub = b_expl_temp.outputSamplePoints->size[0] *
    b_expl_temp.outputSamplePoints->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fis_outputSamplePoints->data[i0] = b_expl_temp.outputSamplePoints->data[i0];
  }

  fis_orrSize_idx_0 = b_expl_temp.orrSize[0];
  fis_aggSize_idx_0 = b_expl_temp.aggSize[0];
  fis_orrSize_idx_1 = b_expl_temp.orrSize[1];
  fis_aggSize_idx_1 = b_expl_temp.aggSize[1];
  emxFreeStruct_struct_T8(&b_expl_temp);
  emxInit_uint8_T(&fish_type, 2);
  i0 = fish_type->size[0] * fish_type->size[1];
  fish_type->size[0] = 1;
  fish_type->size[1] = b_fis_type->size[1];
  emxEnsureCapacity_uint8_T(fish_type, i0);
  loop_ub = b_fis_type->size[0] * b_fis_type->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fish_type->data[i0] = (unsigned char)b_fis_type->data[i0];
  }

  emxFree_char_T(&b_fis_type);
  emxInit_uint8_T(&fish_andMethod, 2);
  i0 = fish_andMethod->size[0] * fish_andMethod->size[1];
  fish_andMethod->size[0] = 1;
  fish_andMethod->size[1] = b_fis_andMethod->size[1];
  emxEnsureCapacity_uint8_T(fish_andMethod, i0);
  loop_ub = b_fis_andMethod->size[0] * b_fis_andMethod->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fish_andMethod->data[i0] = (unsigned char)b_fis_andMethod->data[i0];
  }

  emxFree_char_T(&b_fis_andMethod);
  emxInit_uint8_T(&fish_orMethod, 2);
  i0 = fish_orMethod->size[0] * fish_orMethod->size[1];
  fish_orMethod->size[0] = 1;
  fish_orMethod->size[1] = b_fis_orMethod->size[1];
  emxEnsureCapacity_uint8_T(fish_orMethod, i0);
  loop_ub = b_fis_orMethod->size[0] * b_fis_orMethod->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fish_orMethod->data[i0] = (unsigned char)b_fis_orMethod->data[i0];
  }

  emxFree_char_T(&b_fis_orMethod);
  emxInit_uint8_T(&fish_defuzzMethod, 2);
  i0 = fish_defuzzMethod->size[0] * fish_defuzzMethod->size[1];
  fish_defuzzMethod->size[0] = 1;
  fish_defuzzMethod->size[1] = b_fis_defuzzMethod->size[1];
  emxEnsureCapacity_uint8_T(fish_defuzzMethod, i0);
  loop_ub = b_fis_defuzzMethod->size[0] * b_fis_defuzzMethod->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fish_defuzzMethod->data[i0] = (unsigned char)b_fis_defuzzMethod->data[i0];
  }

  emxFree_char_T(&b_fis_defuzzMethod);
  emxInit_uint8_T(&fish_impMethod, 2);
  i0 = fish_impMethod->size[0] * fish_impMethod->size[1];
  fish_impMethod->size[0] = 1;
  fish_impMethod->size[1] = b_fis_impMethod->size[1];
  emxEnsureCapacity_uint8_T(fish_impMethod, i0);
  loop_ub = b_fis_impMethod->size[0] * b_fis_impMethod->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fish_impMethod->data[i0] = (unsigned char)b_fis_impMethod->data[i0];
  }

  emxFree_char_T(&b_fis_impMethod);
  emxInit_uint8_T(&fish_aggMethod, 2);
  i0 = fish_aggMethod->size[0] * fish_aggMethod->size[1];
  fish_aggMethod->size[0] = 1;
  fish_aggMethod->size[1] = b_fis_aggMethod->size[1];
  emxEnsureCapacity_uint8_T(fish_aggMethod, i0);
  loop_ub = b_fis_aggMethod->size[0] * b_fis_aggMethod->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fish_aggMethod->data[i0] = (unsigned char)b_fis_aggMethod->data[i0];
  }

  emxFree_char_T(&b_fis_aggMethod);
  emxInit_struct_T4(&fish_inputMF, 2);
  emxInit_struct_T4(&fish_outputMF, 2);
  emxInit_int32_T(&fish_numInputMFs, 2);
  setMFDataType(fis_inputMF, fish_inputMF);
  setMFDataType(fis_outputMF, fish_outputMF);
  fis_numInputs = rt_roundd_snf(fis_numInputs);
  if (fis_numInputs < 2.147483648E+9) {
    if (fis_numInputs >= -2.147483648E+9) {
      fish_numInputs = (int)fis_numInputs;
    } else {
      fish_numInputs = MIN_int32_T;
    }
  } else if (fis_numInputs >= 2.147483648E+9) {
    fish_numInputs = MAX_int32_T;
  } else {
    fish_numInputs = 0;
  }

  fis_numInputs = rt_roundd_snf(fis_numOutputs);
  if (fis_numInputs < 2.147483648E+9) {
    if (fis_numInputs >= -2.147483648E+9) {
      fish_numOutputs = (int)fis_numInputs;
    } else {
      fish_numOutputs = MIN_int32_T;
    }
  } else if (fis_numInputs >= 2.147483648E+9) {
    fish_numOutputs = MAX_int32_T;
  } else {
    fish_numOutputs = 0;
  }

  fis_numInputs = rt_roundd_snf(fis_numRules);
  if (fis_numInputs < 2.147483648E+9) {
    if (fis_numInputs >= -2.147483648E+9) {
      fish_numRules = (int)fis_numInputs;
    } else {
      fish_numRules = MIN_int32_T;
    }
  } else if (fis_numInputs >= 2.147483648E+9) {
    fish_numRules = MAX_int32_T;
  } else {
    fish_numRules = 0;
  }

  i0 = fish_numInputMFs->size[0] * fish_numInputMFs->size[1];
  fish_numInputMFs->size[0] = 1;
  fish_numInputMFs->size[1] = fis_numInputMFs->size[1];
  emxEnsureCapacity_int32_T(fish_numInputMFs, i0);
  loop_ub = fis_numInputMFs->size[0] * fis_numInputMFs->size[1];
  emxFree_struct_T6(&fis_outputMF);
  emxFree_struct_T6(&fis_inputMF);
  for (i0 = 0; i0 < loop_ub; i0++) {
    fis_numInputs = rt_roundd_snf(fis_numInputMFs->data[i0]);
    if (fis_numInputs < 2.147483648E+9) {
      if (fis_numInputs >= -2.147483648E+9) {
        fish_aggSize_idx_0 = (int)fis_numInputs;
      } else {
        fish_aggSize_idx_0 = MIN_int32_T;
      }
    } else if (fis_numInputs >= 2.147483648E+9) {
      fish_aggSize_idx_0 = MAX_int32_T;
    } else {
      fish_aggSize_idx_0 = 0;
    }

    fish_numInputMFs->data[i0] = fish_aggSize_idx_0;
  }

  emxInit_int32_T(&fish_numCumInputMFs, 2);
  i0 = fish_numCumInputMFs->size[0] * fish_numCumInputMFs->size[1];
  fish_numCumInputMFs->size[0] = 1;
  fish_numCumInputMFs->size[1] = inputValues->size[1];
  emxEnsureCapacity_int32_T(fish_numCumInputMFs, i0);
  loop_ub = inputValues->size[0] * inputValues->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fis_numInputs = rt_roundd_snf(inputValues->data[i0]);
    if (fis_numInputs < 2.147483648E+9) {
      if (fis_numInputs >= -2.147483648E+9) {
        fish_aggSize_idx_0 = (int)fis_numInputs;
      } else {
        fish_aggSize_idx_0 = MIN_int32_T;
      }
    } else if (fis_numInputs >= 2.147483648E+9) {
      fish_aggSize_idx_0 = MAX_int32_T;
    } else {
      fish_aggSize_idx_0 = 0;
    }

    fish_numCumInputMFs->data[i0] = fish_aggSize_idx_0;
  }

  emxInit_int32_T(&fish_numOutputMFs, 2);
  i0 = fish_numOutputMFs->size[0] * fish_numOutputMFs->size[1];
  fish_numOutputMFs->size[0] = 1;
  fish_numOutputMFs->size[1] = fis_numOutputMFs->size[1];
  emxEnsureCapacity_int32_T(fish_numOutputMFs, i0);
  loop_ub = fis_numOutputMFs->size[0] * fis_numOutputMFs->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fis_numInputs = rt_roundd_snf(fis_numOutputMFs->data[i0]);
    if (fis_numInputs < 2.147483648E+9) {
      if (fis_numInputs >= -2.147483648E+9) {
        fish_aggSize_idx_0 = (int)fis_numInputs;
      } else {
        fish_aggSize_idx_0 = MIN_int32_T;
      }
    } else if (fis_numInputs >= 2.147483648E+9) {
      fish_aggSize_idx_0 = MAX_int32_T;
    } else {
      fish_aggSize_idx_0 = 0;
    }

    fish_numOutputMFs->data[i0] = fish_aggSize_idx_0;
  }

  emxFree_real_T(&fis_numOutputMFs);
  emxInit_int32_T(&fish_numCumOutputMFs, 2);
  i0 = fish_numCumOutputMFs->size[0] * fish_numCumOutputMFs->size[1];
  fish_numCumOutputMFs->size[0] = 1;
  fish_numCumOutputMFs->size[1] = fis_numCumOutputMFs->size[1];
  emxEnsureCapacity_int32_T(fish_numCumOutputMFs, i0);
  loop_ub = fis_numCumOutputMFs->size[0] * fis_numCumOutputMFs->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    fis_numInputs = rt_roundd_snf(fis_numCumOutputMFs->data[i0]);
    if (fis_numInputs < 2.147483648E+9) {
      if (fis_numInputs >= -2.147483648E+9) {
        fish_aggSize_idx_0 = (int)fis_numInputs;
      } else {
        fish_aggSize_idx_0 = MIN_int32_T;
      }
    } else if (fis_numInputs >= 2.147483648E+9) {
      fish_aggSize_idx_0 = MAX_int32_T;
    } else {
      fish_aggSize_idx_0 = 0;
    }

    fish_numCumOutputMFs->data[i0] = fish_aggSize_idx_0;
  }

  emxFree_real_T(&fis_numCumOutputMFs);
  fis_numInputs = rt_roundd_snf(fis_orrSize_idx_0);
  if (fis_numInputs < 2.147483648E+9) {
    if (fis_numInputs >= -2.147483648E+9) {
      loop_ub = (int)fis_numInputs;
    } else {
      loop_ub = MIN_int32_T;
    }
  } else if (fis_numInputs >= 2.147483648E+9) {
    loop_ub = MAX_int32_T;
  } else {
    loop_ub = 0;
  }

  fis_numInputs = rt_roundd_snf(fis_aggSize_idx_0);
  if (fis_numInputs < 2.147483648E+9) {
    if (fis_numInputs >= -2.147483648E+9) {
      fish_aggSize_idx_0 = (int)fis_numInputs;
    } else {
      fish_aggSize_idx_0 = MIN_int32_T;
    }
  } else if (fis_numInputs >= 2.147483648E+9) {
    fish_aggSize_idx_0 = MAX_int32_T;
  } else {
    fish_aggSize_idx_0 = 0;
  }

  fis_numInputs = rt_roundd_snf(fis_orrSize_idx_1);
  if (fis_numInputs < 2.147483648E+9) {
    if (fis_numInputs >= -2.147483648E+9) {
      fish_orrSize_idx_1 = (int)fis_numInputs;
    } else {
      fish_orrSize_idx_1 = MIN_int32_T;
    }
  } else if (fis_numInputs >= 2.147483648E+9) {
    fish_orrSize_idx_1 = MAX_int32_T;
  } else {
    fish_orrSize_idx_1 = 0;
  }

  fis_numInputs = rt_roundd_snf(fis_aggSize_idx_1);
  if (fis_numInputs < 2.147483648E+9) {
    if (fis_numInputs >= -2.147483648E+9) {
      fish_aggSize_idx_1 = (int)fis_numInputs;
    } else {
      fish_aggSize_idx_1 = MIN_int32_T;
    }
  } else if (fis_numInputs >= 2.147483648E+9) {
    fish_aggSize_idx_1 = MAX_int32_T;
  } else {
    fish_aggSize_idx_1 = 0;
  }

  emxInitStruct_struct_T4(&c_expl_temp);
  if (x->size[1] == 1) {
    i0 = inputValues->size[0] * inputValues->size[1];
    inputValues->size[0] = 1;
    inputValues->size[1] = fish_numInputs;
    emxEnsureCapacity_real_T(inputValues, i0);
    for (i0 = 0; i0 < fish_numInputs; i0++) {
      inputValues->data[i0] = x->data[0];
    }

    c_expl_temp.aggSize[0] = fish_aggSize_idx_0;
    c_expl_temp.orrSize[0] = loop_ub;
    c_expl_temp.aggSize[1] = fish_aggSize_idx_1;
    c_expl_temp.orrSize[1] = fish_orrSize_idx_1;
    i0 = c_expl_temp.outputSamplePoints->size[0] *
      c_expl_temp.outputSamplePoints->size[1];
    c_expl_temp.outputSamplePoints->size[0] = fis_outputSamplePoints->size[0];
    c_expl_temp.outputSamplePoints->size[1] = fis_outputSamplePoints->size[1];
    emxEnsureCapacity_real_T(c_expl_temp.outputSamplePoints, i0);
    loop_ub = fis_outputSamplePoints->size[0] * fis_outputSamplePoints->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.outputSamplePoints->data[i0] = fis_outputSamplePoints->data[i0];
    }

    i0 = c_expl_temp.numCumOutputMFs->size[0] *
      c_expl_temp.numCumOutputMFs->size[1];
    c_expl_temp.numCumOutputMFs->size[0] = 1;
    c_expl_temp.numCumOutputMFs->size[1] = fish_numCumOutputMFs->size[1];
    emxEnsureCapacity_int32_T(c_expl_temp.numCumOutputMFs, i0);
    loop_ub = fish_numCumOutputMFs->size[0] * fish_numCumOutputMFs->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.numCumOutputMFs->data[i0] = fish_numCumOutputMFs->data[i0];
    }

    i0 = c_expl_temp.numOutputMFs->size[0] * c_expl_temp.numOutputMFs->size[1];
    c_expl_temp.numOutputMFs->size[0] = 1;
    c_expl_temp.numOutputMFs->size[1] = fish_numOutputMFs->size[1];
    emxEnsureCapacity_int32_T(c_expl_temp.numOutputMFs, i0);
    loop_ub = fish_numOutputMFs->size[0] * fish_numOutputMFs->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.numOutputMFs->data[i0] = fish_numOutputMFs->data[i0];
    }

    i0 = c_expl_temp.numCumInputMFs->size[0] * c_expl_temp.numCumInputMFs->size
      [1];
    c_expl_temp.numCumInputMFs->size[0] = 1;
    c_expl_temp.numCumInputMFs->size[1] = fish_numCumInputMFs->size[1];
    emxEnsureCapacity_int32_T(c_expl_temp.numCumInputMFs, i0);
    loop_ub = fish_numCumInputMFs->size[0] * fish_numCumInputMFs->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.numCumInputMFs->data[i0] = fish_numCumInputMFs->data[i0];
    }

    i0 = c_expl_temp.numInputMFs->size[0] * c_expl_temp.numInputMFs->size[1];
    c_expl_temp.numInputMFs->size[0] = 1;
    c_expl_temp.numInputMFs->size[1] = fish_numInputMFs->size[1];
    emxEnsureCapacity_int32_T(c_expl_temp.numInputMFs, i0);
    loop_ub = fish_numInputMFs->size[0] * fish_numInputMFs->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.numInputMFs->data[i0] = fish_numInputMFs->data[i0];
    }

    c_expl_temp.numRules = fish_numRules;
    c_expl_temp.numOutputs = fish_numOutputs;
    c_expl_temp.numInputs = fish_numInputs;
    c_expl_temp.numSamples = 51;
    i0 = c_expl_temp.weight->size[0] * c_expl_temp.weight->size[1];
    c_expl_temp.weight->size[0] = 1;
    c_expl_temp.weight->size[1] = fis_weight->size[1];
    emxEnsureCapacity_real_T(c_expl_temp.weight, i0);
    loop_ub = fis_weight->size[0] * fis_weight->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.weight->data[i0] = fis_weight->data[i0];
    }

    i0 = c_expl_temp.connection->size[0] * c_expl_temp.connection->size[1];
    c_expl_temp.connection->size[0] = 1;
    c_expl_temp.connection->size[1] = fis_connection->size[1];
    emxEnsureCapacity_real_T(c_expl_temp.connection, i0);
    loop_ub = fis_connection->size[0] * fis_connection->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.connection->data[i0] = fis_connection->data[i0];
    }

    i0 = c_expl_temp.consequent->size[0] * c_expl_temp.consequent->size[1];
    c_expl_temp.consequent->size[0] = fis_consequent->size[0];
    c_expl_temp.consequent->size[1] = fis_consequent->size[1];
    emxEnsureCapacity_real_T(c_expl_temp.consequent, i0);
    loop_ub = fis_consequent->size[0] * fis_consequent->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.consequent->data[i0] = fis_consequent->data[i0];
    }

    i0 = c_expl_temp.antecedent->size[0] * c_expl_temp.antecedent->size[1];
    c_expl_temp.antecedent->size[0] = fis_antecedent->size[0];
    c_expl_temp.antecedent->size[1] = fis_antecedent->size[1];
    emxEnsureCapacity_real_T(c_expl_temp.antecedent, i0);
    loop_ub = fis_antecedent->size[0] * fis_antecedent->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.antecedent->data[i0] = fis_antecedent->data[i0];
    }

    i0 = c_expl_temp.outputMF->size[0] * c_expl_temp.outputMF->size[1];
    c_expl_temp.outputMF->size[0] = 1;
    c_expl_temp.outputMF->size[1] = fish_outputMF->size[1];
    emxEnsureCapacity_struct_T2(c_expl_temp.outputMF, i0);
    loop_ub = fish_outputMF->size[0] * fish_outputMF->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      emxCopyStruct_struct_T2(&c_expl_temp.outputMF->data[i0],
        &fish_outputMF->data[i0]);
    }

    i0 = c_expl_temp.inputMF->size[0] * c_expl_temp.inputMF->size[1];
    c_expl_temp.inputMF->size[0] = 1;
    c_expl_temp.inputMF->size[1] = fish_inputMF->size[1];
    emxEnsureCapacity_struct_T2(c_expl_temp.inputMF, i0);
    loop_ub = fish_inputMF->size[0] * fish_inputMF->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      emxCopyStruct_struct_T2(&c_expl_temp.inputMF->data[i0],
        &fish_inputMF->data[i0]);
    }

    i0 = c_expl_temp.outputRange->size[0] * c_expl_temp.outputRange->size[1];
    c_expl_temp.outputRange->size[0] = fis_outputRange->size[0];
    c_expl_temp.outputRange->size[1] = 2;
    emxEnsureCapacity_real_T(c_expl_temp.outputRange, i0);
    loop_ub = fis_outputRange->size[0] * fis_outputRange->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.outputRange->data[i0] = fis_outputRange->data[i0];
    }

    i0 = c_expl_temp.inputRange->size[0] * c_expl_temp.inputRange->size[1];
    c_expl_temp.inputRange->size[0] = fis_inputRange->size[0];
    c_expl_temp.inputRange->size[1] = 2;
    emxEnsureCapacity_real_T(c_expl_temp.inputRange, i0);
    loop_ub = fis_inputRange->size[0] * fis_inputRange->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.inputRange->data[i0] = fis_inputRange->data[i0];
    }

    i0 = c_expl_temp.aggMethod->size[0] * c_expl_temp.aggMethod->size[1];
    c_expl_temp.aggMethod->size[0] = 1;
    c_expl_temp.aggMethod->size[1] = fish_aggMethod->size[1];
    emxEnsureCapacity_uint8_T(c_expl_temp.aggMethod, i0);
    loop_ub = fish_aggMethod->size[0] * fish_aggMethod->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.aggMethod->data[i0] = fish_aggMethod->data[i0];
    }

    i0 = c_expl_temp.impMethod->size[0] * c_expl_temp.impMethod->size[1];
    c_expl_temp.impMethod->size[0] = 1;
    c_expl_temp.impMethod->size[1] = fish_impMethod->size[1];
    emxEnsureCapacity_uint8_T(c_expl_temp.impMethod, i0);
    loop_ub = fish_impMethod->size[0] * fish_impMethod->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.impMethod->data[i0] = fish_impMethod->data[i0];
    }

    i0 = c_expl_temp.defuzzMethod->size[0] * c_expl_temp.defuzzMethod->size[1];
    c_expl_temp.defuzzMethod->size[0] = 1;
    c_expl_temp.defuzzMethod->size[1] = fish_defuzzMethod->size[1];
    emxEnsureCapacity_uint8_T(c_expl_temp.defuzzMethod, i0);
    loop_ub = fish_defuzzMethod->size[0] * fish_defuzzMethod->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.defuzzMethod->data[i0] = fish_defuzzMethod->data[i0];
    }

    i0 = c_expl_temp.orMethod->size[0] * c_expl_temp.orMethod->size[1];
    c_expl_temp.orMethod->size[0] = 1;
    c_expl_temp.orMethod->size[1] = fish_orMethod->size[1];
    emxEnsureCapacity_uint8_T(c_expl_temp.orMethod, i0);
    loop_ub = fish_orMethod->size[0] * fish_orMethod->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.orMethod->data[i0] = fish_orMethod->data[i0];
    }

    i0 = c_expl_temp.andMethod->size[0] * c_expl_temp.andMethod->size[1];
    c_expl_temp.andMethod->size[0] = 1;
    c_expl_temp.andMethod->size[1] = fish_andMethod->size[1];
    emxEnsureCapacity_uint8_T(c_expl_temp.andMethod, i0);
    loop_ub = fish_andMethod->size[0] * fish_andMethod->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.andMethod->data[i0] = fish_andMethod->data[i0];
    }

    i0 = c_expl_temp.type->size[0] * c_expl_temp.type->size[1];
    c_expl_temp.type->size[0] = 1;
    c_expl_temp.type->size[1] = fish_type->size[1];
    emxEnsureCapacity_uint8_T(c_expl_temp.type, i0);
    loop_ub = fish_type->size[0] * fish_type->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_expl_temp.type->data[i0] = fish_type->data[i0];
    }

    evaluateFIS(inputValues, &c_expl_temp, fis_numInputMFs);
    i0 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = fis_numInputMFs->size[1];
    emxEnsureCapacity_real_T(y, i0);
    loop_ub = fis_numInputMFs->size[0] * fis_numInputMFs->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      y->data[i0] = fis_numInputMFs->data[i0];
    }
  } else {
    emxInit_real_T(&b_x, 1);
    if ((1 == fish_numInputs) && (x->size[1] != 1)) {
      c_expl_temp.aggSize[0] = fish_aggSize_idx_0;
      c_expl_temp.orrSize[0] = loop_ub;
      c_expl_temp.aggSize[1] = fish_aggSize_idx_1;
      c_expl_temp.orrSize[1] = fish_orrSize_idx_1;
      i0 = c_expl_temp.outputSamplePoints->size[0] *
        c_expl_temp.outputSamplePoints->size[1];
      c_expl_temp.outputSamplePoints->size[0] = fis_outputSamplePoints->size[0];
      c_expl_temp.outputSamplePoints->size[1] = fis_outputSamplePoints->size[1];
      emxEnsureCapacity_real_T(c_expl_temp.outputSamplePoints, i0);
      loop_ub = fis_outputSamplePoints->size[0] * fis_outputSamplePoints->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.outputSamplePoints->data[i0] = fis_outputSamplePoints->
          data[i0];
      }

      i0 = c_expl_temp.numCumOutputMFs->size[0] *
        c_expl_temp.numCumOutputMFs->size[1];
      c_expl_temp.numCumOutputMFs->size[0] = 1;
      c_expl_temp.numCumOutputMFs->size[1] = fish_numCumOutputMFs->size[1];
      emxEnsureCapacity_int32_T(c_expl_temp.numCumOutputMFs, i0);
      loop_ub = fish_numCumOutputMFs->size[0] * fish_numCumOutputMFs->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.numCumOutputMFs->data[i0] = fish_numCumOutputMFs->data[i0];
      }

      i0 = c_expl_temp.numOutputMFs->size[0] * c_expl_temp.numOutputMFs->size[1];
      c_expl_temp.numOutputMFs->size[0] = 1;
      c_expl_temp.numOutputMFs->size[1] = fish_numOutputMFs->size[1];
      emxEnsureCapacity_int32_T(c_expl_temp.numOutputMFs, i0);
      loop_ub = fish_numOutputMFs->size[0] * fish_numOutputMFs->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.numOutputMFs->data[i0] = fish_numOutputMFs->data[i0];
      }

      i0 = c_expl_temp.numCumInputMFs->size[0] *
        c_expl_temp.numCumInputMFs->size[1];
      c_expl_temp.numCumInputMFs->size[0] = 1;
      c_expl_temp.numCumInputMFs->size[1] = fish_numCumInputMFs->size[1];
      emxEnsureCapacity_int32_T(c_expl_temp.numCumInputMFs, i0);
      loop_ub = fish_numCumInputMFs->size[0] * fish_numCumInputMFs->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.numCumInputMFs->data[i0] = fish_numCumInputMFs->data[i0];
      }

      i0 = c_expl_temp.numInputMFs->size[0] * c_expl_temp.numInputMFs->size[1];
      c_expl_temp.numInputMFs->size[0] = 1;
      c_expl_temp.numInputMFs->size[1] = fish_numInputMFs->size[1];
      emxEnsureCapacity_int32_T(c_expl_temp.numInputMFs, i0);
      loop_ub = fish_numInputMFs->size[0] * fish_numInputMFs->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.numInputMFs->data[i0] = fish_numInputMFs->data[i0];
      }

      c_expl_temp.numRules = fish_numRules;
      c_expl_temp.numOutputs = fish_numOutputs;
      c_expl_temp.numInputs = 1;
      c_expl_temp.numSamples = 51;
      i0 = c_expl_temp.weight->size[0] * c_expl_temp.weight->size[1];
      c_expl_temp.weight->size[0] = 1;
      c_expl_temp.weight->size[1] = fis_weight->size[1];
      emxEnsureCapacity_real_T(c_expl_temp.weight, i0);
      loop_ub = fis_weight->size[0] * fis_weight->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.weight->data[i0] = fis_weight->data[i0];
      }

      i0 = c_expl_temp.connection->size[0] * c_expl_temp.connection->size[1];
      c_expl_temp.connection->size[0] = 1;
      c_expl_temp.connection->size[1] = fis_connection->size[1];
      emxEnsureCapacity_real_T(c_expl_temp.connection, i0);
      loop_ub = fis_connection->size[0] * fis_connection->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.connection->data[i0] = fis_connection->data[i0];
      }

      i0 = c_expl_temp.consequent->size[0] * c_expl_temp.consequent->size[1];
      c_expl_temp.consequent->size[0] = fis_consequent->size[0];
      c_expl_temp.consequent->size[1] = fis_consequent->size[1];
      emxEnsureCapacity_real_T(c_expl_temp.consequent, i0);
      loop_ub = fis_consequent->size[0] * fis_consequent->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.consequent->data[i0] = fis_consequent->data[i0];
      }

      i0 = c_expl_temp.antecedent->size[0] * c_expl_temp.antecedent->size[1];
      c_expl_temp.antecedent->size[0] = fis_antecedent->size[0];
      c_expl_temp.antecedent->size[1] = fis_antecedent->size[1];
      emxEnsureCapacity_real_T(c_expl_temp.antecedent, i0);
      loop_ub = fis_antecedent->size[0] * fis_antecedent->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.antecedent->data[i0] = fis_antecedent->data[i0];
      }

      i0 = c_expl_temp.outputMF->size[0] * c_expl_temp.outputMF->size[1];
      c_expl_temp.outputMF->size[0] = 1;
      c_expl_temp.outputMF->size[1] = fish_outputMF->size[1];
      emxEnsureCapacity_struct_T2(c_expl_temp.outputMF, i0);
      loop_ub = fish_outputMF->size[0] * fish_outputMF->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        emxCopyStruct_struct_T2(&c_expl_temp.outputMF->data[i0],
          &fish_outputMF->data[i0]);
      }

      i0 = c_expl_temp.inputMF->size[0] * c_expl_temp.inputMF->size[1];
      c_expl_temp.inputMF->size[0] = 1;
      c_expl_temp.inputMF->size[1] = fish_inputMF->size[1];
      emxEnsureCapacity_struct_T2(c_expl_temp.inputMF, i0);
      loop_ub = fish_inputMF->size[0] * fish_inputMF->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        emxCopyStruct_struct_T2(&c_expl_temp.inputMF->data[i0],
          &fish_inputMF->data[i0]);
      }

      i0 = c_expl_temp.outputRange->size[0] * c_expl_temp.outputRange->size[1];
      c_expl_temp.outputRange->size[0] = fis_outputRange->size[0];
      c_expl_temp.outputRange->size[1] = 2;
      emxEnsureCapacity_real_T(c_expl_temp.outputRange, i0);
      loop_ub = fis_outputRange->size[0] * fis_outputRange->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.outputRange->data[i0] = fis_outputRange->data[i0];
      }

      i0 = c_expl_temp.inputRange->size[0] * c_expl_temp.inputRange->size[1];
      c_expl_temp.inputRange->size[0] = fis_inputRange->size[0];
      c_expl_temp.inputRange->size[1] = 2;
      emxEnsureCapacity_real_T(c_expl_temp.inputRange, i0);
      loop_ub = fis_inputRange->size[0] * fis_inputRange->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.inputRange->data[i0] = fis_inputRange->data[i0];
      }

      i0 = c_expl_temp.aggMethod->size[0] * c_expl_temp.aggMethod->size[1];
      c_expl_temp.aggMethod->size[0] = 1;
      c_expl_temp.aggMethod->size[1] = fish_aggMethod->size[1];
      emxEnsureCapacity_uint8_T(c_expl_temp.aggMethod, i0);
      loop_ub = fish_aggMethod->size[0] * fish_aggMethod->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.aggMethod->data[i0] = fish_aggMethod->data[i0];
      }

      i0 = c_expl_temp.impMethod->size[0] * c_expl_temp.impMethod->size[1];
      c_expl_temp.impMethod->size[0] = 1;
      c_expl_temp.impMethod->size[1] = fish_impMethod->size[1];
      emxEnsureCapacity_uint8_T(c_expl_temp.impMethod, i0);
      loop_ub = fish_impMethod->size[0] * fish_impMethod->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.impMethod->data[i0] = fish_impMethod->data[i0];
      }

      i0 = c_expl_temp.defuzzMethod->size[0] * c_expl_temp.defuzzMethod->size[1];
      c_expl_temp.defuzzMethod->size[0] = 1;
      c_expl_temp.defuzzMethod->size[1] = fish_defuzzMethod->size[1];
      emxEnsureCapacity_uint8_T(c_expl_temp.defuzzMethod, i0);
      loop_ub = fish_defuzzMethod->size[0] * fish_defuzzMethod->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.defuzzMethod->data[i0] = fish_defuzzMethod->data[i0];
      }

      i0 = c_expl_temp.orMethod->size[0] * c_expl_temp.orMethod->size[1];
      c_expl_temp.orMethod->size[0] = 1;
      c_expl_temp.orMethod->size[1] = fish_orMethod->size[1];
      emxEnsureCapacity_uint8_T(c_expl_temp.orMethod, i0);
      loop_ub = fish_orMethod->size[0] * fish_orMethod->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.orMethod->data[i0] = fish_orMethod->data[i0];
      }

      i0 = c_expl_temp.andMethod->size[0] * c_expl_temp.andMethod->size[1];
      c_expl_temp.andMethod->size[0] = 1;
      c_expl_temp.andMethod->size[1] = fish_andMethod->size[1];
      emxEnsureCapacity_uint8_T(c_expl_temp.andMethod, i0);
      loop_ub = fish_andMethod->size[0] * fish_andMethod->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.andMethod->data[i0] = fish_andMethod->data[i0];
      }

      i0 = c_expl_temp.type->size[0] * c_expl_temp.type->size[1];
      c_expl_temp.type->size[0] = 1;
      c_expl_temp.type->size[1] = fish_type->size[1];
      emxEnsureCapacity_uint8_T(c_expl_temp.type, i0);
      loop_ub = fish_type->size[0] * fish_type->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.type->data[i0] = fish_type->data[i0];
      }

      i0 = b_x->size[0];
      b_x->size[0] = x->size[1];
      emxEnsureCapacity_real_T(b_x, i0);
      loop_ub = x->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_x->data[i0] = x->data[i0];
      }

      b_evaluateFIS(b_x, &c_expl_temp, y);
    } else {
      c_expl_temp.aggSize[0] = fish_aggSize_idx_0;
      c_expl_temp.orrSize[0] = loop_ub;
      c_expl_temp.aggSize[1] = fish_aggSize_idx_1;
      c_expl_temp.orrSize[1] = fish_orrSize_idx_1;
      i0 = c_expl_temp.outputSamplePoints->size[0] *
        c_expl_temp.outputSamplePoints->size[1];
      c_expl_temp.outputSamplePoints->size[0] = fis_outputSamplePoints->size[0];
      c_expl_temp.outputSamplePoints->size[1] = fis_outputSamplePoints->size[1];
      emxEnsureCapacity_real_T(c_expl_temp.outputSamplePoints, i0);
      loop_ub = fis_outputSamplePoints->size[0] * fis_outputSamplePoints->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.outputSamplePoints->data[i0] = fis_outputSamplePoints->
          data[i0];
      }

      i0 = c_expl_temp.numCumOutputMFs->size[0] *
        c_expl_temp.numCumOutputMFs->size[1];
      c_expl_temp.numCumOutputMFs->size[0] = 1;
      c_expl_temp.numCumOutputMFs->size[1] = fish_numCumOutputMFs->size[1];
      emxEnsureCapacity_int32_T(c_expl_temp.numCumOutputMFs, i0);
      loop_ub = fish_numCumOutputMFs->size[0] * fish_numCumOutputMFs->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.numCumOutputMFs->data[i0] = fish_numCumOutputMFs->data[i0];
      }

      i0 = c_expl_temp.numOutputMFs->size[0] * c_expl_temp.numOutputMFs->size[1];
      c_expl_temp.numOutputMFs->size[0] = 1;
      c_expl_temp.numOutputMFs->size[1] = fish_numOutputMFs->size[1];
      emxEnsureCapacity_int32_T(c_expl_temp.numOutputMFs, i0);
      loop_ub = fish_numOutputMFs->size[0] * fish_numOutputMFs->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.numOutputMFs->data[i0] = fish_numOutputMFs->data[i0];
      }

      i0 = c_expl_temp.numCumInputMFs->size[0] *
        c_expl_temp.numCumInputMFs->size[1];
      c_expl_temp.numCumInputMFs->size[0] = 1;
      c_expl_temp.numCumInputMFs->size[1] = fish_numCumInputMFs->size[1];
      emxEnsureCapacity_int32_T(c_expl_temp.numCumInputMFs, i0);
      loop_ub = fish_numCumInputMFs->size[0] * fish_numCumInputMFs->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.numCumInputMFs->data[i0] = fish_numCumInputMFs->data[i0];
      }

      i0 = c_expl_temp.numInputMFs->size[0] * c_expl_temp.numInputMFs->size[1];
      c_expl_temp.numInputMFs->size[0] = 1;
      c_expl_temp.numInputMFs->size[1] = fish_numInputMFs->size[1];
      emxEnsureCapacity_int32_T(c_expl_temp.numInputMFs, i0);
      loop_ub = fish_numInputMFs->size[0] * fish_numInputMFs->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.numInputMFs->data[i0] = fish_numInputMFs->data[i0];
      }

      c_expl_temp.numRules = fish_numRules;
      c_expl_temp.numOutputs = fish_numOutputs;
      c_expl_temp.numInputs = fish_numInputs;
      c_expl_temp.numSamples = 51;
      i0 = c_expl_temp.weight->size[0] * c_expl_temp.weight->size[1];
      c_expl_temp.weight->size[0] = 1;
      c_expl_temp.weight->size[1] = fis_weight->size[1];
      emxEnsureCapacity_real_T(c_expl_temp.weight, i0);
      loop_ub = fis_weight->size[0] * fis_weight->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.weight->data[i0] = fis_weight->data[i0];
      }

      i0 = c_expl_temp.connection->size[0] * c_expl_temp.connection->size[1];
      c_expl_temp.connection->size[0] = 1;
      c_expl_temp.connection->size[1] = fis_connection->size[1];
      emxEnsureCapacity_real_T(c_expl_temp.connection, i0);
      loop_ub = fis_connection->size[0] * fis_connection->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.connection->data[i0] = fis_connection->data[i0];
      }

      i0 = c_expl_temp.consequent->size[0] * c_expl_temp.consequent->size[1];
      c_expl_temp.consequent->size[0] = fis_consequent->size[0];
      c_expl_temp.consequent->size[1] = fis_consequent->size[1];
      emxEnsureCapacity_real_T(c_expl_temp.consequent, i0);
      loop_ub = fis_consequent->size[0] * fis_consequent->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.consequent->data[i0] = fis_consequent->data[i0];
      }

      i0 = c_expl_temp.antecedent->size[0] * c_expl_temp.antecedent->size[1];
      c_expl_temp.antecedent->size[0] = fis_antecedent->size[0];
      c_expl_temp.antecedent->size[1] = fis_antecedent->size[1];
      emxEnsureCapacity_real_T(c_expl_temp.antecedent, i0);
      loop_ub = fis_antecedent->size[0] * fis_antecedent->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.antecedent->data[i0] = fis_antecedent->data[i0];
      }

      i0 = c_expl_temp.outputMF->size[0] * c_expl_temp.outputMF->size[1];
      c_expl_temp.outputMF->size[0] = 1;
      c_expl_temp.outputMF->size[1] = fish_outputMF->size[1];
      emxEnsureCapacity_struct_T2(c_expl_temp.outputMF, i0);
      loop_ub = fish_outputMF->size[0] * fish_outputMF->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        emxCopyStruct_struct_T2(&c_expl_temp.outputMF->data[i0],
          &fish_outputMF->data[i0]);
      }

      i0 = c_expl_temp.inputMF->size[0] * c_expl_temp.inputMF->size[1];
      c_expl_temp.inputMF->size[0] = 1;
      c_expl_temp.inputMF->size[1] = fish_inputMF->size[1];
      emxEnsureCapacity_struct_T2(c_expl_temp.inputMF, i0);
      loop_ub = fish_inputMF->size[0] * fish_inputMF->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        emxCopyStruct_struct_T2(&c_expl_temp.inputMF->data[i0],
          &fish_inputMF->data[i0]);
      }

      i0 = c_expl_temp.outputRange->size[0] * c_expl_temp.outputRange->size[1];
      c_expl_temp.outputRange->size[0] = fis_outputRange->size[0];
      c_expl_temp.outputRange->size[1] = 2;
      emxEnsureCapacity_real_T(c_expl_temp.outputRange, i0);
      loop_ub = fis_outputRange->size[0] * fis_outputRange->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.outputRange->data[i0] = fis_outputRange->data[i0];
      }

      i0 = c_expl_temp.inputRange->size[0] * c_expl_temp.inputRange->size[1];
      c_expl_temp.inputRange->size[0] = fis_inputRange->size[0];
      c_expl_temp.inputRange->size[1] = 2;
      emxEnsureCapacity_real_T(c_expl_temp.inputRange, i0);
      loop_ub = fis_inputRange->size[0] * fis_inputRange->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.inputRange->data[i0] = fis_inputRange->data[i0];
      }

      i0 = c_expl_temp.aggMethod->size[0] * c_expl_temp.aggMethod->size[1];
      c_expl_temp.aggMethod->size[0] = 1;
      c_expl_temp.aggMethod->size[1] = fish_aggMethod->size[1];
      emxEnsureCapacity_uint8_T(c_expl_temp.aggMethod, i0);
      loop_ub = fish_aggMethod->size[0] * fish_aggMethod->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.aggMethod->data[i0] = fish_aggMethod->data[i0];
      }

      i0 = c_expl_temp.impMethod->size[0] * c_expl_temp.impMethod->size[1];
      c_expl_temp.impMethod->size[0] = 1;
      c_expl_temp.impMethod->size[1] = fish_impMethod->size[1];
      emxEnsureCapacity_uint8_T(c_expl_temp.impMethod, i0);
      loop_ub = fish_impMethod->size[0] * fish_impMethod->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.impMethod->data[i0] = fish_impMethod->data[i0];
      }

      i0 = c_expl_temp.defuzzMethod->size[0] * c_expl_temp.defuzzMethod->size[1];
      c_expl_temp.defuzzMethod->size[0] = 1;
      c_expl_temp.defuzzMethod->size[1] = fish_defuzzMethod->size[1];
      emxEnsureCapacity_uint8_T(c_expl_temp.defuzzMethod, i0);
      loop_ub = fish_defuzzMethod->size[0] * fish_defuzzMethod->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.defuzzMethod->data[i0] = fish_defuzzMethod->data[i0];
      }

      i0 = c_expl_temp.orMethod->size[0] * c_expl_temp.orMethod->size[1];
      c_expl_temp.orMethod->size[0] = 1;
      c_expl_temp.orMethod->size[1] = fish_orMethod->size[1];
      emxEnsureCapacity_uint8_T(c_expl_temp.orMethod, i0);
      loop_ub = fish_orMethod->size[0] * fish_orMethod->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.orMethod->data[i0] = fish_orMethod->data[i0];
      }

      i0 = c_expl_temp.andMethod->size[0] * c_expl_temp.andMethod->size[1];
      c_expl_temp.andMethod->size[0] = 1;
      c_expl_temp.andMethod->size[1] = fish_andMethod->size[1];
      emxEnsureCapacity_uint8_T(c_expl_temp.andMethod, i0);
      loop_ub = fish_andMethod->size[0] * fish_andMethod->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.andMethod->data[i0] = fish_andMethod->data[i0];
      }

      i0 = c_expl_temp.type->size[0] * c_expl_temp.type->size[1];
      c_expl_temp.type->size[0] = 1;
      c_expl_temp.type->size[1] = fish_type->size[1];
      emxEnsureCapacity_uint8_T(c_expl_temp.type, i0);
      loop_ub = fish_type->size[0] * fish_type->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_expl_temp.type->data[i0] = fish_type->data[i0];
      }

      evaluateFIS(x, &c_expl_temp, fis_numInputMFs);
      i0 = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = fis_numInputMFs->size[1];
      emxEnsureCapacity_real_T(y, i0);
      loop_ub = fis_numInputMFs->size[0] * fis_numInputMFs->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        y->data[i0] = fis_numInputMFs->data[i0];
      }
    }

    emxFree_real_T(&b_x);
  }

  emxFreeStruct_struct_T7(&c_expl_temp);
  emxFree_real_T(&fis_outputSamplePoints);
  emxFree_real_T(&fis_numInputMFs);
  emxFree_real_T(&fis_weight);
  emxFree_real_T(&fis_connection);
  emxFree_real_T(&fis_consequent);
  emxFree_real_T(&fis_antecedent);
  emxFree_real_T(&fis_outputRange);
  emxFree_real_T(&fis_inputRange);
  emxFree_real_T(&inputValues);
  emxFree_int32_T(&fish_numCumOutputMFs);
  emxFree_int32_T(&fish_numOutputMFs);
  emxFree_int32_T(&fish_numCumInputMFs);
  emxFree_int32_T(&fish_numInputMFs);
  emxFree_struct_T5(&fish_outputMF);
  emxFree_struct_T5(&fish_inputMF);
  emxFree_uint8_T(&fish_aggMethod);
  emxFree_uint8_T(&fish_impMethod);
  emxFree_uint8_T(&fish_defuzzMethod);
  emxFree_uint8_T(&fish_orMethod);
  emxFree_uint8_T(&fish_andMethod);
  emxFree_uint8_T(&fish_type);
}

/*
 * File trailer for opkene.c
 *
 * [EOF]
 */
