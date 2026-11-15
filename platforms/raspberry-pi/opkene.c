/*
 * File: opkene.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "opkene.h"
#include "evaluateFIS.h"
#include "getFISCodeGenerationData.h"
#include "opkene_data.h"
#include "opkene_emxutil.h"
#include "opkene_initialize.h"
#include "opkene_rtwutil.h"
#include "opkene_types.h"
#include "packageAndSetDataType.h"
#include "rt_nonfinite.h"
#include <math.h>

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
  static const char cv[7] = {'m', 'a', 'm', 'd', 'a', 'n', 'i'};
  b_emxArray_struct_T *fis_input;
  b_emxArray_struct_T *fis_output;
  b_struct_T *fis_input_data;
  b_struct_T *fis_output_data;
  c_emxArray_struct_T *fis_rule;
  c_struct_T *fis_rule_data;
  emxArray_char_T *expl_temp;
  emxArray_char_T *fis_aggMethod;
  emxArray_char_T *fis_andMethod;
  emxArray_char_T *fis_defuzzMethod;
  emxArray_char_T *fis_impMethod;
  emxArray_char_T *fis_orMethod;
  emxArray_char_T *fis_type;
  emxArray_real_T *b_x;
  emxArray_real_T *numInputMFs;
  emxArray_real_T *numOutputMFs;
  emxArray_real_T *r;
  g_emxArray_struct_T *r2;
  i_struct_T b_expl_temp;
  const double *x_data;
  double d2scaled;
  double delta1;
  double *numInputMFs_data;
  double *numOutputMFs_data;
  double *r1;
  double *y_data;
  int exitg1;
  unsigned int fis_aggSize_idx_1;
  int i;
  int i1;
  int id;
  int loop_ub;
  int varID;
  char *fis_aggMethod_data;
  char *fis_andMethod_data;
  char *fis_defuzzMethod_data;
  char *fis_impMethod_data;
  char *fis_orMethod_data;
  char *fis_type_data;
  boolean_T b_bool;
  if (!isInitialized_opkene) {
    opkene_initialize();
  }
  x_data = x->data;
  emxInit_char_T(&fis_type, 2);
  emxInit_char_T(&fis_andMethod, 2);
  emxInit_char_T(&fis_orMethod, 2);
  emxInit_char_T(&fis_defuzzMethod, 2);
  emxInit_char_T(&fis_impMethod, 2);
  emxInit_char_T(&fis_aggMethod, 2);
  emxInit_struct_T(&fis_input);
  emxInit_struct_T(&fis_output);
  emxInit_struct_T1(&fis_rule);
  emxInit_char_T(&expl_temp, 2);
  getFISCodeGenerationData(fileName, expl_temp, fis_type, fis_andMethod,
                           fis_orMethod, fis_defuzzMethod, fis_impMethod,
                           fis_aggMethod, fis_input, fis_output, fis_rule);
  fis_rule_data = fis_rule->data;
  fis_output_data = fis_output->data;
  fis_input_data = fis_input->data;
  fis_aggMethod_data = fis_aggMethod->data;
  fis_impMethod_data = fis_impMethod->data;
  fis_defuzzMethod_data = fis_defuzzMethod->data;
  fis_orMethod_data = fis_orMethod->data;
  fis_andMethod_data = fis_andMethod->data;
  fis_type_data = fis_type->data;
  emxFree_char_T(&expl_temp);
  emxInitStruct_struct_T(&b_expl_temp);
  i = b_expl_temp.inputRange->size[0] * b_expl_temp.inputRange->size[1];
  b_expl_temp.inputRange->size[0] = fis_input->size[1];
  b_expl_temp.inputRange->size[1] = 2;
  emxEnsureCapacity_real_T(b_expl_temp.inputRange, i);
  loop_ub = fis_input->size[1] << 1;
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.inputRange->data[i] = 0.0;
  }
  i = fis_input->size[1];
  for (varID = 0; varID < i; varID++) {
    b_expl_temp.inputRange->data[varID] = fis_input_data[varID].range[0];
    b_expl_temp.inputRange->data[varID + b_expl_temp.inputRange->size[0]] =
        fis_input_data[varID].range[1];
  }
  i = b_expl_temp.outputRange->size[0] * b_expl_temp.outputRange->size[1];
  b_expl_temp.outputRange->size[0] = fis_output->size[1];
  b_expl_temp.outputRange->size[1] = 2;
  emxEnsureCapacity_real_T(b_expl_temp.outputRange, i);
  loop_ub = fis_output->size[1] << 1;
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.outputRange->data[i] = 0.0;
  }
  i = fis_output->size[1];
  for (varID = 0; varID < i; varID++) {
    b_expl_temp.outputRange->data[varID] = fis_output_data[varID].range[0];
    b_expl_temp.outputRange->data[varID + b_expl_temp.outputRange->size[0]] =
        fis_output_data[varID].range[1];
  }
  emxInit_real_T(&numInputMFs, 2);
  i = numInputMFs->size[0] * numInputMFs->size[1];
  numInputMFs->size[0] = 1;
  numInputMFs->size[1] = fis_input->size[1];
  emxEnsureCapacity_real_T(numInputMFs, i);
  numInputMFs_data = numInputMFs->data;
  i = fis_input->size[1];
  for (id = 0; id < i; id++) {
    numInputMFs_data[id] = fis_input_data[id].origNumMF;
  }
  emxInit_real_T(&numOutputMFs, 2);
  i = numOutputMFs->size[0] * numOutputMFs->size[1];
  numOutputMFs->size[0] = 1;
  numOutputMFs->size[1] = fis_output->size[1];
  emxEnsureCapacity_real_T(numOutputMFs, i);
  numOutputMFs_data = numOutputMFs->data;
  i = fis_output->size[1];
  for (id = 0; id < i; id++) {
    numOutputMFs_data[id] = fis_output_data[id].origNumMF;
  }
  i = b_expl_temp.antecedent->size[0] * b_expl_temp.antecedent->size[1];
  b_expl_temp.antecedent->size[0] = fis_rule->size[1];
  b_expl_temp.antecedent->size[1] = fis_input->size[1];
  emxEnsureCapacity_real_T(b_expl_temp.antecedent, i);
  loop_ub = fis_rule->size[1] * fis_input->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.antecedent->data[i] = 0.0;
  }
  i = fis_rule->size[1];
  for (varID = 0; varID < i; varID++) {
    loop_ub = fis_rule_data[varID].antecedent->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_expl_temp.antecedent
          ->data[varID + b_expl_temp.antecedent->size[0] * i1] =
          fis_rule_data[varID].antecedent->data[i1];
    }
  }
  i = b_expl_temp.consequent->size[0] * b_expl_temp.consequent->size[1];
  b_expl_temp.consequent->size[0] = fis_rule->size[1];
  b_expl_temp.consequent->size[1] = fis_output->size[1];
  emxEnsureCapacity_real_T(b_expl_temp.consequent, i);
  loop_ub = fis_rule->size[1] * fis_output->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.consequent->data[i] = 0.0;
  }
  i = fis_rule->size[1];
  i1 = b_expl_temp.connection->size[0] * b_expl_temp.connection->size[1];
  b_expl_temp.connection->size[0] = 1;
  b_expl_temp.connection->size[1] = fis_rule->size[1];
  emxEnsureCapacity_real_T(b_expl_temp.connection, i1);
  i1 = b_expl_temp.weight->size[0] * b_expl_temp.weight->size[1];
  b_expl_temp.weight->size[0] = 1;
  b_expl_temp.weight->size[1] = fis_rule->size[1];
  emxEnsureCapacity_real_T(b_expl_temp.weight, i1);
  for (varID = 0; varID < i; varID++) {
    loop_ub = fis_rule_data[varID].consequent->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_expl_temp.consequent
          ->data[varID + b_expl_temp.consequent->size[0] * i1] =
          fis_rule_data[varID].consequent->data[i1];
    }
    b_expl_temp.connection->data[varID] = fis_rule_data[varID].connection;
    b_expl_temp.weight->data[varID] = fis_rule_data[varID].weight;
  }
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = numInputMFs->size[1];
  emxEnsureCapacity_real_T(y, i);
  y_data = y->data;
  loop_ub = numInputMFs->size[1];
  for (i = 0; i < loop_ub; i++) {
    y_data[i] = numInputMFs_data[i];
  }
  if ((numInputMFs->size[1] != 0) && (numInputMFs->size[1] != 1)) {
    i = numInputMFs->size[1];
    for (loop_ub = 0; loop_ub <= i - 2; loop_ub++) {
      y_data[loop_ub + 1] += y_data[loop_ub];
    }
  }
  emxInit_real_T(&r, 2);
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = numOutputMFs->size[1];
  emxEnsureCapacity_real_T(r, i);
  r1 = r->data;
  loop_ub = numOutputMFs->size[1];
  for (i = 0; i < loop_ub; i++) {
    r1[i] = numOutputMFs_data[i];
  }
  if ((numOutputMFs->size[1] != 0) && (numOutputMFs->size[1] != 1)) {
    i = numOutputMFs->size[1];
    for (loop_ub = 0; loop_ub <= i - 2; loop_ub++) {
      r1[loop_ub + 1] += r1[loop_ub];
    }
  }
  b_bool = false;
  if (fis_type->size[1] == 7) {
    varID = 0;
    do {
      exitg1 = 0;
      if (varID < 7) {
        if (fis_type_data[varID] != cv[varID]) {
          exitg1 = 1;
        } else {
          varID++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (b_bool) {
    i = b_expl_temp.outputSamplePoints->size[0] *
        b_expl_temp.outputSamplePoints->size[1];
    b_expl_temp.outputSamplePoints->size[0] = fis_output->size[1];
    b_expl_temp.outputSamplePoints->size[1] = 51;
    emxEnsureCapacity_real_T(b_expl_temp.outputSamplePoints, i);
    loop_ub = fis_output->size[1] * 51;
    for (i = 0; i < loop_ub; i++) {
      b_expl_temp.outputSamplePoints->data[i] = 0.0;
    }
    i = fis_output->size[1];
    for (varID = 0; varID < i; varID++) {
      double b_y[51];
      d2scaled = fis_output_data[varID].range[0];
      b_y[50] = fis_output_data[varID].range[1];
      b_y[0] = fis_output_data[varID].range[0];
      if (fis_output_data[varID].range[0] == -fis_output_data[varID].range[1]) {
        d2scaled = fis_output_data[varID].range[1] / 50.0;
        for (loop_ub = 0; loop_ub < 49; loop_ub++) {
          b_y[loop_ub + 1] = (2.0 * ((double)loop_ub + 2.0) - 52.0) * d2scaled;
        }
        b_y[25] = 0.0;
      } else if (((fis_output_data[varID].range[0] < 0.0) !=
                  (fis_output_data[varID].range[1] < 0.0)) &&
                 ((fabs(fis_output_data[varID].range[0]) >
                   8.9884656743115785E+307) ||
                  (fabs(fis_output_data[varID].range[1]) >
                   8.9884656743115785E+307))) {
        double delta2;
        delta1 = fis_output_data[varID].range[0] / 50.0;
        delta2 = fis_output_data[varID].range[1] / 50.0;
        for (loop_ub = 0; loop_ub < 49; loop_ub++) {
          b_y[loop_ub + 1] = (d2scaled + delta2 * ((double)loop_ub + 1.0)) -
                             delta1 * ((double)loop_ub + 1.0);
        }
      } else {
        delta1 = (fis_output_data[varID].range[1] -
                  fis_output_data[varID].range[0]) /
                 50.0;
        for (loop_ub = 0; loop_ub < 49; loop_ub++) {
          b_y[loop_ub + 1] = d2scaled + ((double)loop_ub + 1.0) * delta1;
        }
      }
      for (i1 = 0; i1 < 51; i1++) {
        b_expl_temp.outputSamplePoints
            ->data[varID + b_expl_temp.outputSamplePoints->size[0] * i1] =
            b_y[i1];
      }
    }
  } else {
    i = b_expl_temp.outputSamplePoints->size[0] *
        b_expl_temp.outputSamplePoints->size[1];
    b_expl_temp.outputSamplePoints->size[0] = 1;
    b_expl_temp.outputSamplePoints->size[1] = 1;
    emxEnsureCapacity_real_T(b_expl_temp.outputSamplePoints, i);
    b_expl_temp.outputSamplePoints->data[0] = 0.0;
  }
  b_bool = false;
  if (fis_type->size[1] == 7) {
    varID = 0;
    do {
      exitg1 = 0;
      if (varID < 7) {
        if (fis_type_data[varID] != cv[varID]) {
          exitg1 = 1;
        } else {
          varID++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (b_bool) {
    varID = 51;
    d2scaled = (double)fis_rule->size[1] * (double)fis_output->size[1];
    id = 51;
    fis_aggSize_idx_1 = (unsigned int)fis_output->size[1];
  } else {
    varID = fis_rule->size[1];
    d2scaled = fis_output->size[1];
    id = 1;
    fis_aggSize_idx_1 = (unsigned int)fis_output->size[1];
  }
  i = b_expl_temp.type->size[0] * b_expl_temp.type->size[1];
  b_expl_temp.type->size[0] = 1;
  b_expl_temp.type->size[1] = fis_type->size[1];
  emxEnsureCapacity_uint8_T(b_expl_temp.type, i);
  loop_ub = fis_type->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.type->data[i] = (unsigned char)fis_type_data[i];
  }
  emxFree_char_T(&fis_type);
  i = b_expl_temp.andMethod->size[0] * b_expl_temp.andMethod->size[1];
  b_expl_temp.andMethod->size[0] = 1;
  b_expl_temp.andMethod->size[1] = fis_andMethod->size[1];
  emxEnsureCapacity_uint8_T(b_expl_temp.andMethod, i);
  loop_ub = fis_andMethod->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.andMethod->data[i] = (unsigned char)fis_andMethod_data[i];
  }
  emxFree_char_T(&fis_andMethod);
  i = b_expl_temp.orMethod->size[0] * b_expl_temp.orMethod->size[1];
  b_expl_temp.orMethod->size[0] = 1;
  b_expl_temp.orMethod->size[1] = fis_orMethod->size[1];
  emxEnsureCapacity_uint8_T(b_expl_temp.orMethod, i);
  loop_ub = fis_orMethod->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.orMethod->data[i] = (unsigned char)fis_orMethod_data[i];
  }
  emxFree_char_T(&fis_orMethod);
  i = b_expl_temp.defuzzMethod->size[0] * b_expl_temp.defuzzMethod->size[1];
  b_expl_temp.defuzzMethod->size[0] = 1;
  b_expl_temp.defuzzMethod->size[1] = fis_defuzzMethod->size[1];
  emxEnsureCapacity_uint8_T(b_expl_temp.defuzzMethod, i);
  loop_ub = fis_defuzzMethod->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.defuzzMethod->data[i] = (unsigned char)fis_defuzzMethod_data[i];
  }
  emxFree_char_T(&fis_defuzzMethod);
  i = b_expl_temp.impMethod->size[0] * b_expl_temp.impMethod->size[1];
  b_expl_temp.impMethod->size[0] = 1;
  b_expl_temp.impMethod->size[1] = fis_impMethod->size[1];
  emxEnsureCapacity_uint8_T(b_expl_temp.impMethod, i);
  loop_ub = fis_impMethod->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.impMethod->data[i] = (unsigned char)fis_impMethod_data[i];
  }
  emxFree_char_T(&fis_impMethod);
  i = b_expl_temp.aggMethod->size[0] * b_expl_temp.aggMethod->size[1];
  b_expl_temp.aggMethod->size[0] = 1;
  b_expl_temp.aggMethod->size[1] = fis_aggMethod->size[1];
  emxEnsureCapacity_uint8_T(b_expl_temp.aggMethod, i);
  loop_ub = fis_aggMethod->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.aggMethod->data[i] = (unsigned char)fis_aggMethod_data[i];
  }
  emxFree_char_T(&fis_aggMethod);
  emxInit_struct_T3(&r2);
  makeHomogenousMF(fis_input, r2);
  setMFDataType(r2, b_expl_temp.inputMF);
  makeHomogenousMF(fis_output, r2);
  setMFDataType(r2, b_expl_temp.outputMF);
  emxFree_struct_T5(&r2);
  i = b_expl_temp.numInputMFs->size[0] * b_expl_temp.numInputMFs->size[1];
  b_expl_temp.numInputMFs->size[0] = 1;
  b_expl_temp.numInputMFs->size[1] = numInputMFs->size[1];
  emxEnsureCapacity_int32_T(b_expl_temp.numInputMFs, i);
  loop_ub = numInputMFs->size[1];
  for (i = 0; i < loop_ub; i++) {
    delta1 = rt_roundd_snf(numInputMFs_data[i]);
    if (delta1 < 2.147483648E+9) {
      if (delta1 >= -2.147483648E+9) {
        i1 = (int)delta1;
      } else {
        i1 = MIN_int32_T;
      }
    } else if (delta1 >= 2.147483648E+9) {
      i1 = MAX_int32_T;
    } else {
      i1 = 0;
    }
    b_expl_temp.numInputMFs->data[i] = i1;
  }
  if (y->size[1] == numInputMFs->size[1]) {
    i = b_expl_temp.numCumInputMFs->size[0] *
        b_expl_temp.numCumInputMFs->size[1];
    b_expl_temp.numCumInputMFs->size[0] = 1;
    b_expl_temp.numCumInputMFs->size[1] = y->size[1];
    emxEnsureCapacity_int32_T(b_expl_temp.numCumInputMFs, i);
    loop_ub = y->size[1];
    for (i = 0; i < loop_ub; i++) {
      delta1 = rt_roundd_snf(y_data[i] - numInputMFs_data[i]);
      if (delta1 < 2.147483648E+9) {
        if (delta1 >= -2.147483648E+9) {
          i1 = (int)delta1;
        } else {
          i1 = MIN_int32_T;
        }
      } else if (delta1 >= 2.147483648E+9) {
        i1 = MAX_int32_T;
      } else {
        i1 = 0;
      }
      b_expl_temp.numCumInputMFs->data[i] = i1;
    }
  } else {
    b_binary_expand_op(&b_expl_temp, y, numInputMFs);
  }
  i = b_expl_temp.numOutputMFs->size[0] * b_expl_temp.numOutputMFs->size[1];
  b_expl_temp.numOutputMFs->size[0] = 1;
  b_expl_temp.numOutputMFs->size[1] = numOutputMFs->size[1];
  emxEnsureCapacity_int32_T(b_expl_temp.numOutputMFs, i);
  loop_ub = numOutputMFs->size[1];
  for (i = 0; i < loop_ub; i++) {
    delta1 = rt_roundd_snf(numOutputMFs_data[i]);
    if (delta1 < 2.147483648E+9) {
      if (delta1 >= -2.147483648E+9) {
        i1 = (int)delta1;
      } else {
        i1 = MIN_int32_T;
      }
    } else if (delta1 >= 2.147483648E+9) {
      i1 = MAX_int32_T;
    } else {
      i1 = 0;
    }
    b_expl_temp.numOutputMFs->data[i] = i1;
  }
  if (r->size[1] == numOutputMFs->size[1]) {
    i = b_expl_temp.numCumOutputMFs->size[0] *
        b_expl_temp.numCumOutputMFs->size[1];
    b_expl_temp.numCumOutputMFs->size[0] = 1;
    b_expl_temp.numCumOutputMFs->size[1] = r->size[1];
    emxEnsureCapacity_int32_T(b_expl_temp.numCumOutputMFs, i);
    loop_ub = r->size[1];
    for (i = 0; i < loop_ub; i++) {
      delta1 = rt_roundd_snf(r1[i] - numOutputMFs_data[i]);
      if (delta1 < 2.147483648E+9) {
        if (delta1 >= -2.147483648E+9) {
          i1 = (int)delta1;
        } else {
          i1 = MIN_int32_T;
        }
      } else if (delta1 >= 2.147483648E+9) {
        i1 = MAX_int32_T;
      } else {
        i1 = 0;
      }
      b_expl_temp.numCumOutputMFs->data[i] = i1;
    }
  } else {
    binary_expand_op(&b_expl_temp, r, numOutputMFs);
  }
  emxFree_real_T(&r);
  emxFree_real_T(&numOutputMFs);
  b_expl_temp.orrSize[0] = varID;
  b_expl_temp.aggSize[0] = id;
  if (d2scaled < 2.147483648E+9) {
    i = (int)d2scaled;
  } else {
    i = MAX_int32_T;
  }
  b_expl_temp.orrSize[1] = i;
  b_expl_temp.aggSize[1] = (int)fis_aggSize_idx_1;
  if (x->size[1] == 1) {
    i = numInputMFs->size[0] * numInputMFs->size[1];
    numInputMFs->size[0] = 1;
    numInputMFs->size[1] = fis_input->size[1];
    emxEnsureCapacity_real_T(numInputMFs, i);
    numInputMFs_data = numInputMFs->data;
    loop_ub = fis_input->size[1];
    for (i = 0; i < loop_ub; i++) {
      numInputMFs_data[i] = x_data[0];
    }
    b_expl_temp.numRules = fis_rule->size[1];
    b_expl_temp.numOutputs = fis_output->size[1];
    b_expl_temp.numInputs = fis_input->size[1];
    evaluateFIS(numInputMFs, &b_expl_temp, y);
  } else {
    emxInit_real_T(&b_x, 1);
    if ((fis_input->size[1] == 1) && (x->size[1] != 1)) {
      b_expl_temp.numRules = fis_rule->size[1];
      b_expl_temp.numOutputs = fis_output->size[1];
      b_expl_temp.numInputs = 1;
      i = b_x->size[0];
      b_x->size[0] = x->size[1];
      emxEnsureCapacity_real_T(b_x, i);
      numInputMFs_data = b_x->data;
      loop_ub = x->size[1];
      for (i = 0; i < loop_ub; i++) {
        numInputMFs_data[i] = x_data[i];
      }
      b_evaluateFIS(b_x, &b_expl_temp, y);
    } else {
      b_expl_temp.numRules = fis_rule->size[1];
      b_expl_temp.numOutputs = fis_output->size[1];
      b_expl_temp.numInputs = fis_input->size[1];
      evaluateFIS(x, &b_expl_temp, y);
    }
    emxFree_real_T(&b_x);
  }
  emxFreeStruct_struct_T3(&b_expl_temp);
  emxFree_real_T(&numInputMFs);
  emxFree_struct_T2(&fis_rule);
  emxFree_struct_T(&fis_output);
  emxFree_struct_T(&fis_input);
}

/*
 * File trailer for opkene.c
 *
 * [EOF]
 */
