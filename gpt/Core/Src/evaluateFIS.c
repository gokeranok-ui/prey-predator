/*
 * File: evaluateFIS.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <stdio.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "evaluateFIS.h"
#include "opkene_emxutil.h"
#include "applyMamdaniDefuzzificationMethod.h"
#include "applyMamdaniAggregationMethod.h"
#include "applyMamdaniImplicationMethod.h"
#include "applySugenoDefuzzificationMethod.h"
#include "applySugenoAggregationMethod.h"
#include "applySugenoImplicationMethod.h"
#include "strcmp.h"
#include "char.h"
#include "applyOperators.h"
#include "fuzzifyInputs.h"
#include "sum.h"
#include "extractVarMF.h"
#include "createMamdaniOutputMFCache.h"
#include "isequal.h"

/* Function Declarations */
static void b_initVariables(const emxArray_uint8_T *fis_type, const
  d_emxArray_struct_T *fis_outputMF, int fis_numOutputs, int fis_numRules, const
  emxArray_int32_T *fis_numOutputMFs, const emxArray_int32_T
  *fis_numCumOutputMFs, const emxArray_real_T *fis_outputSamplePoints, const int
  fis_orrSize[2], const int fis_aggSize[2], const emxArray_real_T *inputs,
  emxArray_real_T *y, emxArray_real_T *irr, emxArray_real_T *orr,
  emxArray_real_T *arr, emxArray_real_T *rfs, emxArray_real_T *unImpSugRuleOut,
  emxArray_real_T *outputMFCache, double *numInputDataSets);
static void initVariables(const emxArray_uint8_T *fis_type, const
  d_emxArray_struct_T *fis_outputMF, int fis_numInputs, int fis_numOutputs, int
  fis_numRules, const emxArray_int32_T *fis_numOutputMFs, const emxArray_int32_T
  *fis_numCumOutputMFs, const emxArray_real_T *fis_outputSamplePoints, const int
  fis_orrSize[2], const int fis_aggSize[2], emxArray_real_T *y, emxArray_real_T *
  irr, emxArray_real_T *orr, emxArray_real_T *arr, emxArray_real_T *rfs,
  emxArray_real_T *unImpSugRuleOut, emxArray_real_T *outputMFCache);

/* Function Definitions */

/*
 * Arguments    : const emxArray_uint8_T *fis_type
 *                const d_emxArray_struct_T *fis_outputMF
 *                int fis_numOutputs
 *                int fis_numRules
 *                const emxArray_int32_T *fis_numOutputMFs
 *                const emxArray_int32_T *fis_numCumOutputMFs
 *                const emxArray_real_T *fis_outputSamplePoints
 *                const int fis_orrSize[2]
 *                const int fis_aggSize[2]
 *                const emxArray_real_T *inputs
 *                emxArray_real_T *y
 *                emxArray_real_T *irr
 *                emxArray_real_T *orr
 *                emxArray_real_T *arr
 *                emxArray_real_T *rfs
 *                emxArray_real_T *unImpSugRuleOut
 *                emxArray_real_T *outputMFCache
 *                double *numInputDataSets
 * Return Type  : void
 */
static void b_initVariables(const emxArray_uint8_T *fis_type, const
  d_emxArray_struct_T *fis_outputMF, int fis_numOutputs, int fis_numRules, const
  emxArray_int32_T *fis_numOutputMFs, const emxArray_int32_T
  *fis_numCumOutputMFs, const emxArray_real_T *fis_outputSamplePoints, const int
  fis_orrSize[2], const int fis_aggSize[2], const emxArray_real_T *inputs,
  emxArray_real_T *y, emxArray_real_T *irr, emxArray_real_T *orr,
  emxArray_real_T *arr, emxArray_real_T *rfs, emxArray_real_T *unImpSugRuleOut,
  emxArray_real_T *outputMFCache, double *numInputDataSets)
{
  emxArray_char_T *r38;
  int b_numInputDataSets;
  int i85;
  emxArray_real_T *r39;
  int loop_ub;
  emxInit_char_T(&r38, 2);
  b_numInputDataSets = inputs->size[0];
  i85 = y->size[0] * y->size[1];
  y->size[0] = inputs->size[0];
  y->size[1] = fis_numOutputs;
  emxEnsureCapacity_real_T(y, i85);
  i85 = irr->size[0] * irr->size[1];
  irr->size[0] = fis_numRules;
  irr->size[1] = 1;
  emxEnsureCapacity_real_T(irr, i85);
  i85 = orr->size[0] * orr->size[1];
  orr->size[0] = fis_orrSize[0];
  orr->size[1] = fis_orrSize[1];
  emxEnsureCapacity_real_T(orr, i85);
  i85 = arr->size[0] * arr->size[1];
  arr->size[0] = fis_aggSize[0];
  arr->size[1] = fis_aggSize[1];
  emxEnsureCapacity_real_T(arr, i85);
  i85 = rfs->size[0];
  rfs->size[0] = fis_numRules;
  emxEnsureCapacity_real_T(rfs, i85);
  b_char(fis_type, r38);
  if (e_strcmp(r38)) {
    emxInit_real_T(&r39, 2);
    createMamdaniOutputMFCache(fis_outputMF, fis_numOutputs, fis_numOutputMFs,
      fis_numCumOutputMFs, fis_outputSamplePoints, r39);
    i85 = outputMFCache->size[0] * outputMFCache->size[1];
    outputMFCache->size[0] = r39->size[0];
    outputMFCache->size[1] = 51;
    emxEnsureCapacity_real_T(outputMFCache, i85);
    loop_ub = r39->size[0] * r39->size[1];
    for (i85 = 0; i85 < loop_ub; i85++) {
      outputMFCache->data[i85] = r39->data[i85];
    }

    emxFree_real_T(&r39);
    i85 = unImpSugRuleOut->size[0] * unImpSugRuleOut->size[1];
    unImpSugRuleOut->size[0] = 1;
    unImpSugRuleOut->size[1] = 1;
    emxEnsureCapacity_real_T(unImpSugRuleOut, i85);
    unImpSugRuleOut->data[0] = 0.0;
  } else {
    i85 = outputMFCache->size[0] * outputMFCache->size[1];
    outputMFCache->size[0] = 1;
    outputMFCache->size[1] = 1;
    emxEnsureCapacity_real_T(outputMFCache, i85);
    outputMFCache->data[0] = 0.0;
    i85 = unImpSugRuleOut->size[0] * unImpSugRuleOut->size[1];
    unImpSugRuleOut->size[0] = fis_orrSize[0];
    unImpSugRuleOut->size[1] = fis_orrSize[1];
    emxEnsureCapacity_real_T(unImpSugRuleOut, i85);
  }

  emxFree_char_T(&r38);
  *numInputDataSets = b_numInputDataSets;
}

/*
 * Arguments    : const emxArray_uint8_T *fis_type
 *                const d_emxArray_struct_T *fis_outputMF
 *                int fis_numInputs
 *                int fis_numOutputs
 *                int fis_numRules
 *                const emxArray_int32_T *fis_numOutputMFs
 *                const emxArray_int32_T *fis_numCumOutputMFs
 *                const emxArray_real_T *fis_outputSamplePoints
 *                const int fis_orrSize[2]
 *                const int fis_aggSize[2]
 *                emxArray_real_T *y
 *                emxArray_real_T *irr
 *                emxArray_real_T *orr
 *                emxArray_real_T *arr
 *                emxArray_real_T *rfs
 *                emxArray_real_T *unImpSugRuleOut
 *                emxArray_real_T *outputMFCache
 * Return Type  : void
 */
static void initVariables(const emxArray_uint8_T *fis_type, const
  d_emxArray_struct_T *fis_outputMF, int fis_numInputs, int fis_numOutputs, int
  fis_numRules, const emxArray_int32_T *fis_numOutputMFs, const emxArray_int32_T
  *fis_numCumOutputMFs, const emxArray_real_T *fis_outputSamplePoints, const int
  fis_orrSize[2], const int fis_aggSize[2], emxArray_real_T *y, emxArray_real_T *
  irr, emxArray_real_T *orr, emxArray_real_T *arr, emxArray_real_T *rfs,
  emxArray_real_T *unImpSugRuleOut, emxArray_real_T *outputMFCache)
{
  emxArray_char_T *r33;
  int i63;
  emxArray_real_T *r34;
  int loop_ub;
  emxInit_char_T(&r33, 2);
  i63 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = fis_numOutputs;
  emxEnsureCapacity_real_T(y, i63);
  i63 = irr->size[0] * irr->size[1];
  irr->size[0] = fis_numRules;
  irr->size[1] = fis_numInputs;
  emxEnsureCapacity_real_T(irr, i63);
  i63 = orr->size[0] * orr->size[1];
  orr->size[0] = fis_orrSize[0];
  orr->size[1] = fis_orrSize[1];
  emxEnsureCapacity_real_T(orr, i63);
  i63 = arr->size[0] * arr->size[1];
  arr->size[0] = fis_aggSize[0];
  arr->size[1] = fis_aggSize[1];
  emxEnsureCapacity_real_T(arr, i63);
  i63 = rfs->size[0];
  rfs->size[0] = fis_numRules;
  emxEnsureCapacity_real_T(rfs, i63);
  b_char(fis_type, r33);
  if (e_strcmp(r33)) {
    emxInit_real_T(&r34, 2);
    createMamdaniOutputMFCache(fis_outputMF, fis_numOutputs, fis_numOutputMFs,
      fis_numCumOutputMFs, fis_outputSamplePoints, r34);
    i63 = outputMFCache->size[0] * outputMFCache->size[1];
    outputMFCache->size[0] = r34->size[0];
    outputMFCache->size[1] = 51;
    emxEnsureCapacity_real_T(outputMFCache, i63);
    loop_ub = r34->size[0] * r34->size[1];
    for (i63 = 0; i63 < loop_ub; i63++) {
      outputMFCache->data[i63] = r34->data[i63];
    }

    emxFree_real_T(&r34);
    i63 = unImpSugRuleOut->size[0] * unImpSugRuleOut->size[1];
    unImpSugRuleOut->size[0] = 1;
    unImpSugRuleOut->size[1] = 1;
    emxEnsureCapacity_real_T(unImpSugRuleOut, i63);
    unImpSugRuleOut->data[0] = 0.0;
  } else {
    i63 = outputMFCache->size[0] * outputMFCache->size[1];
    outputMFCache->size[0] = 1;
    outputMFCache->size[1] = 1;
    emxEnsureCapacity_real_T(outputMFCache, i63);
    outputMFCache->data[0] = 0.0;
    i63 = unImpSugRuleOut->size[0] * unImpSugRuleOut->size[1];
    unImpSugRuleOut->size[0] = fis_orrSize[0];
    unImpSugRuleOut->size[1] = fis_orrSize[1];
    emxEnsureCapacity_real_T(unImpSugRuleOut, i63);
  }

  emxFree_char_T(&r33);
}

/*
 * Arguments    : const emxArray_real_T *inputs
 *                const i_struct_T *fis
 *                emxArray_real_T *y
 * Return Type  : void
 */
void b_evaluateFIS(const emxArray_real_T *inputs, const i_struct_T *fis,
                   emxArray_real_T *y)
{
  emxArray_cell_wrap_0 *inVarMF;
  emxArray_real_T *inputMFCache;
  emxArray_real_T *irr;
  emxArray_real_T *orr;
  emxArray_real_T *arr;
  emxArray_real_T *w;
  emxArray_real_T *unImpSugRuleOut;
  emxArray_real_T *outputMFCache;
  emxArray_real_T *b_arr;
  emxArray_real_T *r35;
  emxArray_char_T *r36;
  emxArray_real_T *r37;
  static const unsigned char uv54[8] = { 99U, 101U, 110U, 116U, 114U, 111U, 105U,
    100U };

  static const unsigned char uv55[8] = { 98U, 105U, 115U, 101U, 99U, 116U, 111U,
    114U };

  double numInputDataSets;
  static const unsigned char uv56[3] = { 109U, 111U, 109U };

  static const unsigned char uv57[3] = { 115U, 111U, 109U };

  double d10;
  static const unsigned char uv58[3] = { 108U, 111U, 109U };

  int i83;
  static const unsigned char uv59[6] = { 119U, 116U, 97U, 118U, 101U, 114U };

  static const unsigned char uv60[5] = { 119U, 116U, 115U, 117U, 109U };

  double irrOfOneRule_data[1];
  int i;
  emxArray_real_T *b_fis;
  int i84;
  int loop_ub;
  int arr_idx_1;
  emxInit_cell_wrap_0(&inVarMF, 2);
  emxInit_real_T(&inputMFCache, 2);
  emxInit_real_T(&irr, 2);
  emxInit_real_T(&orr, 2);
  emxInit_real_T(&arr, 2);
  emxInit_real_T(&w, 1);
  emxInit_real_T(&unImpSugRuleOut, 2);
  emxInit_real_T(&outputMFCache, 2);
  emxInit_real_T(&b_arr, 2);
  emxInit_real_T(&r35, 1);
  emxInit_char_T(&r36, 2);
  emxInit_real_T(&r37, 2);
  if (isequal(fis->defuzzMethod, uv54)) {
    b_initVariables(fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
                    fis->numOutputMFs, fis->numCumOutputMFs,
                    fis->outputSamplePoints, fis->orrSize, fis->aggSize, inputs,
                    y, irr, orr, arr, w, unImpSugRuleOut, outputMFCache,
                    &numInputDataSets);
    extractVarMF(fis->inputMF, inVarMF);
    d10 = sum(fis->numInputMFs);
    i83 = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)d10;
    emxEnsureCapacity_real_T(inputMFCache, i83);
    irrOfOneRule_data[0] = 0.0;
    i83 = (int)numInputDataSets;
    for (i = 0; i < i83; i++) {
      b_fuzzifyInputs(inputs->data[i], fis->antecedent, fis->connection,
                      fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                      inVarMF, inputMFCache, irr);
      i84 = r35->size[0];
      r35->size[0] = 1;
      emxEnsureCapacity_real_T(r35, i84);
      r35->data[0] = irrOfOneRule_data[0];
      numInputDataSets = applyOperators(irr, fis->andMethod, fis->orMethod,
        fis->connection, fis->weight, fis->numInputs, fis->numRules, w, r35);
      loop_ub = r35->size[0];
      for (i84 = 0; i84 < loop_ub; i84++) {
        irrOfOneRule_data[i84] = r35->data[i84];
      }

      b_char(fis->type, r36);
      if (e_strcmp(r36)) {
        applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
          fis->numOutputs, fis->numRules, fis->numCumOutputMFs, fis->orrSize,
          outputMFCache, orr);
        applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
          fis->numRules, fis->aggSize, b_arr);
        i84 = arr->size[0] * arr->size[1];
        arr->size[0] = b_arr->size[0];
        arr->size[1] = b_arr->size[1];
        emxEnsureCapacity_real_T(arr, i84);
        c_applyMamdaniDefuzzificationMe(fis->outputSamplePoints,
          numInputDataSets, b_arr, fis->outputRange, fis->numOutputs, r35);
        loop_ub = r35->size[0];
        for (i84 = 0; i84 < loop_ub; i84++) {
          y->data[i + y->size[0] * i84] = r35->data[i84];
        }
      } else {
        b_applySugenoImplicationMethod(inputs->data[i], w, fis->outputMF,
          fis->consequent, fis->numOutputs, fis->numRules, fis->numOutputMFs,
          fis->numCumOutputMFs, fis->orrSize, orr, unImpSugRuleOut);
        applySugenoAggregationMethod(orr, r37);
        loop_ub = arr->size[0];
        arr_idx_1 = arr->size[1];
        i84 = arr->size[0] * arr->size[1];
        arr->size[0] = loop_ub;
        arr->size[1] = arr_idx_1;
        emxEnsureCapacity_real_T(arr, i84);
        loop_ub *= arr_idx_1;
        for (i84 = 0; i84 < loop_ub; i84++) {
          arr->data[i84] = r37->data[i84];
        }

        c_applySugenoDefuzzificationMet(numInputDataSets, arr, fis->outputRange,
          fis->numOutputs, r35);
        loop_ub = r35->size[0];
        for (i84 = 0; i84 < loop_ub; i84++) {
          y->data[i + y->size[0] * i84] = r35->data[i84];
        }
      }
    }
  } else if (isequal(fis->defuzzMethod, uv55)) {
    b_initVariables(fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
                    fis->numOutputMFs, fis->numCumOutputMFs,
                    fis->outputSamplePoints, fis->orrSize, fis->aggSize, inputs,
                    y, irr, orr, arr, w, unImpSugRuleOut, outputMFCache,
                    &numInputDataSets);
    extractVarMF(fis->inputMF, inVarMF);
    d10 = sum(fis->numInputMFs);
    i83 = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)d10;
    emxEnsureCapacity_real_T(inputMFCache, i83);
    irrOfOneRule_data[0] = 0.0;
    i83 = (int)numInputDataSets;
    for (i = 0; i < i83; i++) {
      b_fuzzifyInputs(inputs->data[i], fis->antecedent, fis->connection,
                      fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                      inVarMF, inputMFCache, irr);
      i84 = r35->size[0];
      r35->size[0] = 1;
      emxEnsureCapacity_real_T(r35, i84);
      r35->data[0] = irrOfOneRule_data[0];
      numInputDataSets = applyOperators(irr, fis->andMethod, fis->orMethod,
        fis->connection, fis->weight, fis->numInputs, fis->numRules, w, r35);
      loop_ub = r35->size[0];
      for (i84 = 0; i84 < loop_ub; i84++) {
        irrOfOneRule_data[i84] = r35->data[i84];
      }

      b_char(fis->type, r36);
      if (e_strcmp(r36)) {
        applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
          fis->numOutputs, fis->numRules, fis->numCumOutputMFs, fis->orrSize,
          outputMFCache, orr);
        applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
          fis->numRules, fis->aggSize, b_arr);
        i84 = arr->size[0] * arr->size[1];
        arr->size[0] = b_arr->size[0];
        arr->size[1] = b_arr->size[1];
        emxEnsureCapacity_real_T(arr, i84);
        d_applyMamdaniDefuzzificationMe(fis->outputSamplePoints,
          numInputDataSets, b_arr, fis->outputRange, fis->numOutputs, r35);
        loop_ub = r35->size[0];
        for (i84 = 0; i84 < loop_ub; i84++) {
          y->data[i + y->size[0] * i84] = r35->data[i84];
        }
      } else {
        b_applySugenoImplicationMethod(inputs->data[i], w, fis->outputMF,
          fis->consequent, fis->numOutputs, fis->numRules, fis->numOutputMFs,
          fis->numCumOutputMFs, fis->orrSize, orr, unImpSugRuleOut);
        applySugenoAggregationMethod(orr, r37);
        loop_ub = arr->size[0];
        arr_idx_1 = arr->size[1];
        i84 = arr->size[0] * arr->size[1];
        arr->size[0] = loop_ub;
        arr->size[1] = arr_idx_1;
        emxEnsureCapacity_real_T(arr, i84);
        loop_ub *= arr_idx_1;
        for (i84 = 0; i84 < loop_ub; i84++) {
          arr->data[i84] = r37->data[i84];
        }

        d_applySugenoDefuzzificationMet(numInputDataSets, arr, fis->outputRange,
          fis->numOutputs, r35);
        loop_ub = r35->size[0];
        for (i84 = 0; i84 < loop_ub; i84++) {
          y->data[i + y->size[0] * i84] = r35->data[i84];
        }
      }
    }
  } else if (h_isequal(fis->defuzzMethod, uv56)) {
    b_initVariables(fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
                    fis->numOutputMFs, fis->numCumOutputMFs,
                    fis->outputSamplePoints, fis->orrSize, fis->aggSize, inputs,
                    y, irr, orr, arr, w, unImpSugRuleOut, outputMFCache,
                    &numInputDataSets);
    extractVarMF(fis->inputMF, inVarMF);
    d10 = sum(fis->numInputMFs);
    i83 = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)d10;
    emxEnsureCapacity_real_T(inputMFCache, i83);
    irrOfOneRule_data[0] = 0.0;
    i83 = (int)numInputDataSets;
    for (i = 0; i < i83; i++) {
      b_fuzzifyInputs(inputs->data[i], fis->antecedent, fis->connection,
                      fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                      inVarMF, inputMFCache, irr);
      i84 = r35->size[0];
      r35->size[0] = 1;
      emxEnsureCapacity_real_T(r35, i84);
      r35->data[0] = irrOfOneRule_data[0];
      numInputDataSets = applyOperators(irr, fis->andMethod, fis->orMethod,
        fis->connection, fis->weight, fis->numInputs, fis->numRules, w, r35);
      loop_ub = r35->size[0];
      for (i84 = 0; i84 < loop_ub; i84++) {
        irrOfOneRule_data[i84] = r35->data[i84];
      }

      b_char(fis->type, r36);
      if (e_strcmp(r36)) {
        applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
          fis->numOutputs, fis->numRules, fis->numCumOutputMFs, fis->orrSize,
          outputMFCache, orr);
        applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
          fis->numRules, fis->aggSize, b_arr);
        i84 = arr->size[0] * arr->size[1];
        arr->size[0] = b_arr->size[0];
        arr->size[1] = b_arr->size[1];
        emxEnsureCapacity_real_T(arr, i84);
        e_applyMamdaniDefuzzificationMe(fis->outputSamplePoints,
          numInputDataSets, b_arr, fis->outputRange, fis->numOutputs, r35);
        loop_ub = r35->size[0];
        for (i84 = 0; i84 < loop_ub; i84++) {
          y->data[i + y->size[0] * i84] = r35->data[i84];
        }
      } else {
        b_applySugenoImplicationMethod(inputs->data[i], w, fis->outputMF,
          fis->consequent, fis->numOutputs, fis->numRules, fis->numOutputMFs,
          fis->numCumOutputMFs, fis->orrSize, orr, unImpSugRuleOut);
        applySugenoAggregationMethod(orr, r37);
        loop_ub = arr->size[0];
        arr_idx_1 = arr->size[1];
        i84 = arr->size[0] * arr->size[1];
        arr->size[0] = loop_ub;
        arr->size[1] = arr_idx_1;
        emxEnsureCapacity_real_T(arr, i84);
        loop_ub *= arr_idx_1;
        for (i84 = 0; i84 < loop_ub; i84++) {
          arr->data[i84] = r37->data[i84];
        }

        e_applySugenoDefuzzificationMet(numInputDataSets, arr, fis->outputRange,
          fis->numOutputs, r35);
        loop_ub = r35->size[0];
        for (i84 = 0; i84 < loop_ub; i84++) {
          y->data[i + y->size[0] * i84] = r35->data[i84];
        }
      }
    }
  } else if (h_isequal(fis->defuzzMethod, uv57)) {
    b_initVariables(fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
                    fis->numOutputMFs, fis->numCumOutputMFs,
                    fis->outputSamplePoints, fis->orrSize, fis->aggSize, inputs,
                    y, irr, orr, arr, w, unImpSugRuleOut, outputMFCache,
                    &numInputDataSets);
    extractVarMF(fis->inputMF, inVarMF);
    d10 = sum(fis->numInputMFs);
    i83 = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)d10;
    emxEnsureCapacity_real_T(inputMFCache, i83);
    irrOfOneRule_data[0] = 0.0;
    i83 = (int)numInputDataSets;
    for (i = 0; i < i83; i++) {
      b_fuzzifyInputs(inputs->data[i], fis->antecedent, fis->connection,
                      fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                      inVarMF, inputMFCache, irr);
      i84 = r35->size[0];
      r35->size[0] = 1;
      emxEnsureCapacity_real_T(r35, i84);
      r35->data[0] = irrOfOneRule_data[0];
      numInputDataSets = applyOperators(irr, fis->andMethod, fis->orMethod,
        fis->connection, fis->weight, fis->numInputs, fis->numRules, w, r35);
      loop_ub = r35->size[0];
      for (i84 = 0; i84 < loop_ub; i84++) {
        irrOfOneRule_data[i84] = r35->data[i84];
      }

      b_char(fis->type, r36);
      if (e_strcmp(r36)) {
        applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
          fis->numOutputs, fis->numRules, fis->numCumOutputMFs, fis->orrSize,
          outputMFCache, orr);
        applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
          fis->numRules, fis->aggSize, b_arr);
        i84 = arr->size[0] * arr->size[1];
        arr->size[0] = b_arr->size[0];
        arr->size[1] = b_arr->size[1];
        emxEnsureCapacity_real_T(arr, i84);
        f_applyMamdaniDefuzzificationMe(fis->outputSamplePoints,
          numInputDataSets, b_arr, fis->outputRange, fis->numOutputs, r35);
        loop_ub = r35->size[0];
        for (i84 = 0; i84 < loop_ub; i84++) {
          y->data[i + y->size[0] * i84] = r35->data[i84];
        }
      } else {
        b_applySugenoImplicationMethod(inputs->data[i], w, fis->outputMF,
          fis->consequent, fis->numOutputs, fis->numRules, fis->numOutputMFs,
          fis->numCumOutputMFs, fis->orrSize, orr, unImpSugRuleOut);
        applySugenoAggregationMethod(orr, r37);
        loop_ub = arr->size[0];
        arr_idx_1 = arr->size[1];
        i84 = arr->size[0] * arr->size[1];
        arr->size[0] = loop_ub;
        arr->size[1] = arr_idx_1;
        emxEnsureCapacity_real_T(arr, i84);
        loop_ub *= arr_idx_1;
        for (i84 = 0; i84 < loop_ub; i84++) {
          arr->data[i84] = r37->data[i84];
        }

        f_applySugenoDefuzzificationMet(numInputDataSets, arr, fis->outputRange,
          fis->numOutputs, r35);
        loop_ub = r35->size[0];
        for (i84 = 0; i84 < loop_ub; i84++) {
          y->data[i + y->size[0] * i84] = r35->data[i84];
        }
      }
    }
  } else if (h_isequal(fis->defuzzMethod, uv58)) {
    b_initVariables(fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
                    fis->numOutputMFs, fis->numCumOutputMFs,
                    fis->outputSamplePoints, fis->orrSize, fis->aggSize, inputs,
                    y, irr, orr, arr, w, unImpSugRuleOut, outputMFCache,
                    &numInputDataSets);
    extractVarMF(fis->inputMF, inVarMF);
    d10 = sum(fis->numInputMFs);
    i83 = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)d10;
    emxEnsureCapacity_real_T(inputMFCache, i83);
    irrOfOneRule_data[0] = 0.0;
    i83 = (int)numInputDataSets;
    for (i = 0; i < i83; i++) {
      b_fuzzifyInputs(inputs->data[i], fis->antecedent, fis->connection,
                      fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                      inVarMF, inputMFCache, irr);
      i84 = r35->size[0];
      r35->size[0] = 1;
      emxEnsureCapacity_real_T(r35, i84);
      r35->data[0] = irrOfOneRule_data[0];
      numInputDataSets = applyOperators(irr, fis->andMethod, fis->orMethod,
        fis->connection, fis->weight, fis->numInputs, fis->numRules, w, r35);
      loop_ub = r35->size[0];
      for (i84 = 0; i84 < loop_ub; i84++) {
        irrOfOneRule_data[i84] = r35->data[i84];
      }

      b_char(fis->type, r36);
      if (e_strcmp(r36)) {
        applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
          fis->numOutputs, fis->numRules, fis->numCumOutputMFs, fis->orrSize,
          outputMFCache, orr);
        applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
          fis->numRules, fis->aggSize, b_arr);
        i84 = arr->size[0] * arr->size[1];
        arr->size[0] = b_arr->size[0];
        arr->size[1] = b_arr->size[1];
        emxEnsureCapacity_real_T(arr, i84);
        g_applyMamdaniDefuzzificationMe(fis->outputSamplePoints,
          numInputDataSets, b_arr, fis->outputRange, fis->numOutputs, r35);
        loop_ub = r35->size[0];
        for (i84 = 0; i84 < loop_ub; i84++) {
          y->data[i + y->size[0] * i84] = r35->data[i84];
        }
      } else {
        b_applySugenoImplicationMethod(inputs->data[i], w, fis->outputMF,
          fis->consequent, fis->numOutputs, fis->numRules, fis->numOutputMFs,
          fis->numCumOutputMFs, fis->orrSize, orr, unImpSugRuleOut);
        applySugenoAggregationMethod(orr, r37);
        loop_ub = arr->size[0];
        arr_idx_1 = arr->size[1];
        i84 = arr->size[0] * arr->size[1];
        arr->size[0] = loop_ub;
        arr->size[1] = arr_idx_1;
        emxEnsureCapacity_real_T(arr, i84);
        loop_ub *= arr_idx_1;
        for (i84 = 0; i84 < loop_ub; i84++) {
          arr->data[i84] = r37->data[i84];
        }

        f_applySugenoDefuzzificationMet(numInputDataSets, arr, fis->outputRange,
          fis->numOutputs, r35);
        loop_ub = r35->size[0];
        for (i84 = 0; i84 < loop_ub; i84++) {
          y->data[i + y->size[0] * i84] = r35->data[i84];
        }
      }
    }
  } else if (j_isequal(fis->defuzzMethod, uv59)) {
    b_initVariables(fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
                    fis->numOutputMFs, fis->numCumOutputMFs,
                    fis->outputSamplePoints, fis->orrSize, fis->aggSize, inputs,
                    y, irr, orr, arr, w, unImpSugRuleOut, outputMFCache,
                    &numInputDataSets);
    extractVarMF(fis->inputMF, inVarMF);
    d10 = sum(fis->numInputMFs);
    i83 = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)d10;
    emxEnsureCapacity_real_T(inputMFCache, i83);
    irrOfOneRule_data[0] = 0.0;
    i83 = (int)numInputDataSets;
    for (i = 0; i < i83; i++) {
      b_fuzzifyInputs(inputs->data[i], fis->antecedent, fis->connection,
                      fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                      inVarMF, inputMFCache, irr);
      i84 = r35->size[0];
      r35->size[0] = 1;
      emxEnsureCapacity_real_T(r35, i84);
      r35->data[0] = irrOfOneRule_data[0];
      numInputDataSets = applyOperators(irr, fis->andMethod, fis->orMethod,
        fis->connection, fis->weight, fis->numInputs, fis->numRules, w, r35);
      loop_ub = r35->size[0];
      for (i84 = 0; i84 < loop_ub; i84++) {
        irrOfOneRule_data[i84] = r35->data[i84];
      }

      b_char(fis->type, r36);
      if (e_strcmp(r36)) {
        applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
          fis->numOutputs, fis->numRules, fis->numCumOutputMFs, fis->orrSize,
          outputMFCache, orr);
        applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
          fis->numRules, fis->aggSize, b_arr);
        i84 = arr->size[0] * arr->size[1];
        arr->size[0] = b_arr->size[0];
        arr->size[1] = b_arr->size[1];
        emxEnsureCapacity_real_T(arr, i84);
        h_applyMamdaniDefuzzificationMe(fis->outputSamplePoints,
          numInputDataSets, b_arr, fis->outputRange, fis->numOutputs, r35);
        loop_ub = r35->size[0];
        for (i84 = 0; i84 < loop_ub; i84++) {
          y->data[i + y->size[0] * i84] = r35->data[i84];
        }
      } else {
        b_applySugenoImplicationMethod(inputs->data[i], w, fis->outputMF,
          fis->consequent, fis->numOutputs, fis->numRules, fis->numOutputMFs,
          fis->numCumOutputMFs, fis->orrSize, orr, unImpSugRuleOut);
        applySugenoAggregationMethod(orr, r37);
        loop_ub = arr->size[0];
        arr_idx_1 = arr->size[1];
        i84 = arr->size[0] * arr->size[1];
        arr->size[0] = loop_ub;
        arr->size[1] = arr_idx_1;
        emxEnsureCapacity_real_T(arr, i84);
        loop_ub *= arr_idx_1;
        for (i84 = 0; i84 < loop_ub; i84++) {
          arr->data[i84] = r37->data[i84];
        }

        g_applySugenoDefuzzificationMet(numInputDataSets, arr, fis->outputRange,
          fis->numOutputs, r35);
        loop_ub = r35->size[0];
        for (i84 = 0; i84 < loop_ub; i84++) {
          y->data[i + y->size[0] * i84] = r35->data[i84];
        }
      }
    }
  } else if (k_isequal(fis->defuzzMethod, uv60)) {
    b_initVariables(fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
                    fis->numOutputMFs, fis->numCumOutputMFs,
                    fis->outputSamplePoints, fis->orrSize, fis->aggSize, inputs,
                    y, irr, orr, arr, w, unImpSugRuleOut, outputMFCache,
                    &numInputDataSets);
    extractVarMF(fis->inputMF, inVarMF);
    d10 = sum(fis->numInputMFs);
    i83 = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)d10;
    emxEnsureCapacity_real_T(inputMFCache, i83);
    irrOfOneRule_data[0] = 0.0;
    i83 = (int)numInputDataSets;
    for (i = 0; i < i83; i++) {
      b_fuzzifyInputs(inputs->data[i], fis->antecedent, fis->connection,
                      fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                      inVarMF, inputMFCache, irr);
      i84 = r35->size[0];
      r35->size[0] = 1;
      emxEnsureCapacity_real_T(r35, i84);
      r35->data[0] = irrOfOneRule_data[0];
      numInputDataSets = applyOperators(irr, fis->andMethod, fis->orMethod,
        fis->connection, fis->weight, fis->numInputs, fis->numRules, w, r35);
      loop_ub = r35->size[0];
      for (i84 = 0; i84 < loop_ub; i84++) {
        irrOfOneRule_data[i84] = r35->data[i84];
      }

      b_char(fis->type, r36);
      if (e_strcmp(r36)) {
        applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
          fis->numOutputs, fis->numRules, fis->numCumOutputMFs, fis->orrSize,
          outputMFCache, orr);
        applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
          fis->numRules, fis->aggSize, b_arr);
        i84 = arr->size[0] * arr->size[1];
        arr->size[0] = b_arr->size[0];
        arr->size[1] = b_arr->size[1];
        emxEnsureCapacity_real_T(arr, i84);
        i_applyMamdaniDefuzzificationMe(fis->outputSamplePoints,
          numInputDataSets, fis->outputRange, fis->numOutputs, r35);
        loop_ub = r35->size[0];
        for (i84 = 0; i84 < loop_ub; i84++) {
          y->data[i + y->size[0] * i84] = r35->data[i84];
        }
      } else {
        b_applySugenoImplicationMethod(inputs->data[i], w, fis->outputMF,
          fis->consequent, fis->numOutputs, fis->numRules, fis->numOutputMFs,
          fis->numCumOutputMFs, fis->orrSize, orr, unImpSugRuleOut);
        applySugenoAggregationMethod(orr, r37);
        loop_ub = arr->size[0];
        arr_idx_1 = arr->size[1];
        i84 = arr->size[0] * arr->size[1];
        arr->size[0] = loop_ub;
        arr->size[1] = arr_idx_1;
        emxEnsureCapacity_real_T(arr, i84);
        loop_ub *= arr_idx_1;
        for (i84 = 0; i84 < loop_ub; i84++) {
          arr->data[i84] = r37->data[i84];
        }

        f_applySugenoDefuzzificationMet(numInputDataSets, arr, fis->outputRange,
          fis->numOutputs, r35);
        loop_ub = r35->size[0];
        for (i84 = 0; i84 < loop_ub; i84++) {
          y->data[i + y->size[0] * i84] = r35->data[i84];
        }
      }
    }
  } else {
    i83 = y->size[0] * y->size[1];
    y->size[0] = inputs->size[0];
    y->size[1] = fis->numOutputs;
    emxEnsureCapacity_real_T(y, i83);
    b_char(fis->type, r36);
    if (e_strcmp(r36)) {
      emxInit_real_T(&b_fis, 2);
      createMamdaniOutputMFCache(fis->outputMF, fis->numOutputs,
        fis->numOutputMFs, fis->numCumOutputMFs, fis->outputSamplePoints, b_fis);
      emxFree_real_T(&b_fis);
    }

    exit(0);
  }

  emxFree_real_T(&r37);
  emxFree_char_T(&r36);
  emxFree_real_T(&r35);
  emxFree_real_T(&b_arr);
  emxFree_real_T(&outputMFCache);
  emxFree_real_T(&unImpSugRuleOut);
  emxFree_real_T(&w);
  emxFree_real_T(&arr);
  emxFree_real_T(&orr);
  emxFree_real_T(&irr);
  emxFree_real_T(&inputMFCache);
  emxFree_cell_wrap_0(&inVarMF);
}

/*
 * Arguments    : const emxArray_real_T *inputs
 *                const i_struct_T *fis
 *                emxArray_real_T *y
 * Return Type  : void
 */
void evaluateFIS(const emxArray_real_T *inputs, const i_struct_T *fis,
                 emxArray_real_T *y)
{
  /* Debug: print inputs and input ranges */
  printf("evaluateFIS: called with inputs size=%d, data[0]=%.3f, data[1]=%.3f\r\n", 
         (int)inputs->size[1], inputs->data[0], inputs->data[1]);
  int i62_temp;
  printf("evaluateFIS: inputRange size=[%d,%d], values: ", (int)fis->inputRange->size[0], (int)fis->inputRange->size[1]);
  for (i62_temp = 0; i62_temp < (int)(fis->inputRange->size[0] * fis->inputRange->size[1]); i62_temp++) {
    printf("%.3f ", fis->inputRange->data[i62_temp]);
  }
  printf("\r\n");
  emxArray_cell_wrap_0 *inVarMF;
  emxArray_real_T *inputMFCache;
  emxArray_real_T *x;
  emxArray_real_T *irr;
  emxArray_real_T *orr;
  emxArray_real_T *arr;
  emxArray_real_T *w;
  emxArray_real_T *unImpSugRuleOut;
  emxArray_real_T *outputMFCache;
  emxArray_real_T *r31;
  emxArray_char_T *r32;
  static const unsigned char uv19[8] = { 99U, 101U, 110U, 116U, 114U, 111U, 105U,
    100U };

  static const unsigned char uv20[8] = { 98U, 105U, 115U, 101U, 99U, 116U, 111U,
    114U };

  static const unsigned char uv21[3] = { 109U, 111U, 109U };

  static const unsigned char uv22[3] = { 115U, 111U, 109U };

  double sw;
  static const unsigned char uv23[3] = { 108U, 111U, 109U };

  int i62;
  static const unsigned char uv24[6] = { 119U, 116U, 97U, 118U, 101U, 114U };

  static const unsigned char uv25[5] = { 119U, 116U, 115U, 117U, 109U };

  int loop_ub;
  emxArray_real_T *b_fis;
  emxArray_real_T b_inputMFCache;
  int b_arr[2];
  int c_arr[2];
  int d_arr[2];
  int e_arr[2];
  int f_arr[2];
  int g_arr[2];
  int h_arr[2];
  emxInit_cell_wrap_0(&inVarMF, 2);
  emxInit_real_T(&inputMFCache, 2);
  emxInit_real_T(&x, 2);
  emxInit_real_T(&irr, 2);
  emxInit_real_T(&orr, 2);
  emxInit_real_T(&arr, 2);
  emxInit_real_T(&w, 1);
  emxInit_real_T(&unImpSugRuleOut, 2);
  emxInit_real_T(&outputMFCache, 2);
  emxInit_real_T(&r31, 1);
  emxInit_char_T(&r32, 2);
  if (isequal(fis->defuzzMethod, uv19)) {
    initVariables(fis->type, fis->outputMF, fis->numInputs, fis->numOutputs,
                  fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                  fis->outputSamplePoints, fis->orrSize, fis->aggSize, y, irr,
                  orr, arr, w, unImpSugRuleOut, outputMFCache);
    extractVarMF(fis->inputMF, inVarMF);
    sw = sum(fis->numInputMFs);
    i62 = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)sw;
    emxEnsureCapacity_real_T(inputMFCache, i62);
    loop_ub = inputs->size[1];
    i62 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = loop_ub;
    emxEnsureCapacity_real_T(x, i62);
    for (i62 = 0; i62 < loop_ub; i62++) {
      x->data[i62] = inputs->data[i62];
    }

    fuzzifyInputs(x, fis->antecedent, fis->connection, fis->numInputs,
                  fis->numRules, fis->numInputMFs, fis->numCumInputMFs, inVarMF,
                  inputMFCache, irr);
    /* Debug: print membership function values */
    printf("evaluateFIS: after fuzzifyInputs - inputMFCache size=%d, first 5 values: ", (int)inputMFCache->size[1]);
    for (i62 = 0; i62 < 5 && i62 < (int)inputMFCache->size[1]; i62++) {
      printf("%.3f ", inputMFCache->data[i62]);
    }
    printf("\r\n");
    printf("evaluateFIS: irr size=[%d,%d], first 3 values: ", (int)irr->size[0], (int)irr->size[1]);
    for (i62 = 0; i62 < 3 && i62 < (int)(irr->size[0] * irr->size[1]); i62++) {
      printf("%.3f ", irr->data[i62]);
    }
    printf("\r\n");
    i62 = r31->size[0];
    r31->size[0] = fis->numInputs;
    emxEnsureCapacity_real_T(r31, i62);
    loop_ub = fis->numInputs;
    for (i62 = 0; i62 < loop_ub; i62++) {
      r31->data[i62] = 0.0;
    }

    sw = applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                        fis->weight, fis->numInputs, fis->numRules, w, r31);
    /* Debug: print rule weights */
    printf("evaluateFIS: after applyOperators - sw=%.3f, w size=%d, first 3 values: ", sw, (int)w->size[0]);
    for (i62 = 0; i62 < 3 && i62 < (int)w->size[0]; i62++) {
      printf("%.3f ", w->data[i62]);
    }
    printf("\r\n");
    b_char(fis->type, r32);
    if (e_strcmp(r32)) {
      applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
        fis->numOutputs, fis->numRules, fis->numCumOutputMFs, fis->orrSize,
        outputMFCache, orr);
      printf("evaluateFIS: after implication - orr size=[%d,%d], first 3 values: ", (int)orr->size[0], (int)orr->size[1]);
      for (i62 = 0; i62 < 3 && i62 < (int)(orr->size[0] * orr->size[1]); i62++) {
        printf("%.3f ", orr->data[i62]);
      }
      printf("\r\n");
      applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
        fis->numRules, fis->aggSize, arr);
      printf("evaluateFIS: after aggregation - arr size=[%d,%d], first 3 values: ", (int)arr->size[0], (int)arr->size[1]);
      for (i62 = 0; i62 < 3 && i62 < (int)(arr->size[0] * arr->size[1]); i62++) {
        printf("%.3f ", arr->data[i62]);
      }
      printf("\r\n");
      c_applyMamdaniDefuzzificationMe(fis->outputSamplePoints, sw, arr,
        fis->outputRange, fis->numOutputs, r31);
      printf("evaluateFIS: after defuzzification - r31 size=%d, values: ", (int)r31->size[0]);
      for (i62 = 0; i62 < (int)r31->size[0]; i62++) {
        printf("%.6f ", r31->data[i62]);
      }
      printf("\r\n");
      loop_ub = r31->size[0];
      for (i62 = 0; i62 < loop_ub; i62++) {
        y->data[i62] = r31->data[i62];
      }
      printf("evaluateFIS: Mamdani path - output size=%d, data[0]=%.6f\r\n", loop_ub, y->data[0]);
    } else {
      applySugenoImplicationMethod(x, w, fis->outputMF, fis->consequent,
        fis->numOutputs, fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
        fis->orrSize, orr, irr);
      applySugenoAggregationMethod(orr, inputMFCache);
      b_inputMFCache = *inputMFCache;
      b_arr[0] = (*(int (*)[2])arr->size)[0];
      b_arr[1] = (*(int (*)[2])arr->size)[1];
      b_inputMFCache.size = &b_arr[0];
      b_inputMFCache.numDimensions = 1;
      c_applySugenoDefuzzificationMet(sw, &b_inputMFCache, fis->outputRange,
        fis->numOutputs, r31);
      loop_ub = r31->size[0];
      for (i62 = 0; i62 < loop_ub; i62++) {
        y->data[i62] = r31->data[i62];
      }
      printf("evaluateFIS: Sugeno path - output size=%d, data[0]=%.6f\r\n", loop_ub, y->data[0]);
    }
  } else if (isequal(fis->defuzzMethod, uv20)) {
    initVariables(fis->type, fis->outputMF, fis->numInputs, fis->numOutputs,
                  fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                  fis->outputSamplePoints, fis->orrSize, fis->aggSize, y, irr,
                  orr, arr, w, unImpSugRuleOut, outputMFCache);
    extractVarMF(fis->inputMF, inVarMF);
    sw = sum(fis->numInputMFs);
    i62 = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)sw;
    emxEnsureCapacity_real_T(inputMFCache, i62);
    loop_ub = inputs->size[1];
    i62 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = loop_ub;
    emxEnsureCapacity_real_T(x, i62);
    for (i62 = 0; i62 < loop_ub; i62++) {
      x->data[i62] = inputs->data[i62];
    }

    fuzzifyInputs(x, fis->antecedent, fis->connection, fis->numInputs,
                  fis->numRules, fis->numInputMFs, fis->numCumInputMFs, inVarMF,
                  inputMFCache, irr);
    i62 = r31->size[0];
    r31->size[0] = fis->numInputs;
    emxEnsureCapacity_real_T(r31, i62);
    loop_ub = fis->numInputs;
    for (i62 = 0; i62 < loop_ub; i62++) {
      r31->data[i62] = 0.0;
    }

    sw = applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                        fis->weight, fis->numInputs, fis->numRules, w, r31);
    b_char(fis->type, r32);
    if (e_strcmp(r32)) {
      applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
        fis->numOutputs, fis->numRules, fis->numCumOutputMFs, fis->orrSize,
        outputMFCache, orr);
      applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
        fis->numRules, fis->aggSize, arr);
      d_applyMamdaniDefuzzificationMe(fis->outputSamplePoints, sw, arr,
        fis->outputRange, fis->numOutputs, r31);
      loop_ub = r31->size[0];
      for (i62 = 0; i62 < loop_ub; i62++) {
        y->data[i62] = r31->data[i62];
      }
    } else {
      applySugenoImplicationMethod(x, w, fis->outputMF, fis->consequent,
        fis->numOutputs, fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
        fis->orrSize, orr, irr);
      applySugenoAggregationMethod(orr, inputMFCache);
      b_inputMFCache = *inputMFCache;
      c_arr[0] = (*(int (*)[2])arr->size)[0];
      c_arr[1] = (*(int (*)[2])arr->size)[1];
      b_inputMFCache.size = &c_arr[0];
      b_inputMFCache.numDimensions = 1;
      d_applySugenoDefuzzificationMet(sw, &b_inputMFCache, fis->outputRange,
        fis->numOutputs, r31);
      loop_ub = r31->size[0];
      for (i62 = 0; i62 < loop_ub; i62++) {
        y->data[i62] = r31->data[i62];
      }
    }
  } else if (h_isequal(fis->defuzzMethod, uv21)) {
    initVariables(fis->type, fis->outputMF, fis->numInputs, fis->numOutputs,
                  fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                  fis->outputSamplePoints, fis->orrSize, fis->aggSize, y, irr,
                  orr, arr, w, unImpSugRuleOut, outputMFCache);
    extractVarMF(fis->inputMF, inVarMF);
    sw = sum(fis->numInputMFs);
    i62 = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)sw;
    emxEnsureCapacity_real_T(inputMFCache, i62);
    loop_ub = inputs->size[1];
    i62 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = loop_ub;
    emxEnsureCapacity_real_T(x, i62);
    for (i62 = 0; i62 < loop_ub; i62++) {
      x->data[i62] = inputs->data[i62];
    }

    fuzzifyInputs(x, fis->antecedent, fis->connection, fis->numInputs,
                  fis->numRules, fis->numInputMFs, fis->numCumInputMFs, inVarMF,
                  inputMFCache, irr);
    i62 = r31->size[0];
    r31->size[0] = fis->numInputs;
    emxEnsureCapacity_real_T(r31, i62);
    loop_ub = fis->numInputs;
    for (i62 = 0; i62 < loop_ub; i62++) {
      r31->data[i62] = 0.0;
    }

    sw = applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                        fis->weight, fis->numInputs, fis->numRules, w, r31);
    b_char(fis->type, r32);
    if (e_strcmp(r32)) {
      applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
        fis->numOutputs, fis->numRules, fis->numCumOutputMFs, fis->orrSize,
        outputMFCache, orr);
      applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
        fis->numRules, fis->aggSize, arr);
      e_applyMamdaniDefuzzificationMe(fis->outputSamplePoints, sw, arr,
        fis->outputRange, fis->numOutputs, r31);
      loop_ub = r31->size[0];
      for (i62 = 0; i62 < loop_ub; i62++) {
        y->data[i62] = r31->data[i62];
      }
    } else {
      applySugenoImplicationMethod(x, w, fis->outputMF, fis->consequent,
        fis->numOutputs, fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
        fis->orrSize, orr, irr);
      applySugenoAggregationMethod(orr, inputMFCache);
      b_inputMFCache = *inputMFCache;
      d_arr[0] = (*(int (*)[2])arr->size)[0];
      d_arr[1] = (*(int (*)[2])arr->size)[1];
      b_inputMFCache.size = &d_arr[0];
      b_inputMFCache.numDimensions = 1;
      e_applySugenoDefuzzificationMet(sw, &b_inputMFCache, fis->outputRange,
        fis->numOutputs, r31);
      loop_ub = r31->size[0];
      for (i62 = 0; i62 < loop_ub; i62++) {
        y->data[i62] = r31->data[i62];
      }
    }
  } else if (h_isequal(fis->defuzzMethod, uv22)) {
    initVariables(fis->type, fis->outputMF, fis->numInputs, fis->numOutputs,
                  fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                  fis->outputSamplePoints, fis->orrSize, fis->aggSize, y, irr,
                  orr, arr, w, unImpSugRuleOut, outputMFCache);
    extractVarMF(fis->inputMF, inVarMF);
    sw = sum(fis->numInputMFs);
    i62 = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)sw;
    emxEnsureCapacity_real_T(inputMFCache, i62);
    loop_ub = inputs->size[1];
    i62 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = loop_ub;
    emxEnsureCapacity_real_T(x, i62);
    for (i62 = 0; i62 < loop_ub; i62++) {
      x->data[i62] = inputs->data[i62];
    }

    fuzzifyInputs(x, fis->antecedent, fis->connection, fis->numInputs,
                  fis->numRules, fis->numInputMFs, fis->numCumInputMFs, inVarMF,
                  inputMFCache, irr);
    i62 = r31->size[0];
    r31->size[0] = fis->numInputs;
    emxEnsureCapacity_real_T(r31, i62);
    loop_ub = fis->numInputs;
    for (i62 = 0; i62 < loop_ub; i62++) {
      r31->data[i62] = 0.0;
    }

    sw = applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                        fis->weight, fis->numInputs, fis->numRules, w, r31);
    b_char(fis->type, r32);
    if (e_strcmp(r32)) {
      applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
        fis->numOutputs, fis->numRules, fis->numCumOutputMFs, fis->orrSize,
        outputMFCache, orr);
      applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
        fis->numRules, fis->aggSize, arr);
      f_applyMamdaniDefuzzificationMe(fis->outputSamplePoints, sw, arr,
        fis->outputRange, fis->numOutputs, r31);
      loop_ub = r31->size[0];
      for (i62 = 0; i62 < loop_ub; i62++) {
        y->data[i62] = r31->data[i62];
      }
    } else {
      applySugenoImplicationMethod(x, w, fis->outputMF, fis->consequent,
        fis->numOutputs, fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
        fis->orrSize, orr, irr);
      applySugenoAggregationMethod(orr, inputMFCache);
      b_inputMFCache = *inputMFCache;
      e_arr[0] = (*(int (*)[2])arr->size)[0];
      e_arr[1] = (*(int (*)[2])arr->size)[1];
      b_inputMFCache.size = &e_arr[0];
      b_inputMFCache.numDimensions = 1;
      f_applySugenoDefuzzificationMet(sw, &b_inputMFCache, fis->outputRange,
        fis->numOutputs, r31);
      loop_ub = r31->size[0];
      for (i62 = 0; i62 < loop_ub; i62++) {
        y->data[i62] = r31->data[i62];
      }
    }
  } else if (h_isequal(fis->defuzzMethod, uv23)) {
    initVariables(fis->type, fis->outputMF, fis->numInputs, fis->numOutputs,
                  fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                  fis->outputSamplePoints, fis->orrSize, fis->aggSize, y, irr,
                  orr, arr, w, unImpSugRuleOut, outputMFCache);
    extractVarMF(fis->inputMF, inVarMF);
    sw = sum(fis->numInputMFs);
    i62 = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)sw;
    emxEnsureCapacity_real_T(inputMFCache, i62);
    loop_ub = inputs->size[1];
    i62 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = loop_ub;
    emxEnsureCapacity_real_T(x, i62);
    for (i62 = 0; i62 < loop_ub; i62++) {
      x->data[i62] = inputs->data[i62];
    }

    fuzzifyInputs(x, fis->antecedent, fis->connection, fis->numInputs,
                  fis->numRules, fis->numInputMFs, fis->numCumInputMFs, inVarMF,
                  inputMFCache, irr);
    i62 = r31->size[0];
    r31->size[0] = fis->numInputs;
    emxEnsureCapacity_real_T(r31, i62);
    loop_ub = fis->numInputs;
    for (i62 = 0; i62 < loop_ub; i62++) {
      r31->data[i62] = 0.0;
    }

    sw = applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                        fis->weight, fis->numInputs, fis->numRules, w, r31);
    b_char(fis->type, r32);
    if (e_strcmp(r32)) {
      applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
        fis->numOutputs, fis->numRules, fis->numCumOutputMFs, fis->orrSize,
        outputMFCache, orr);
      applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
        fis->numRules, fis->aggSize, arr);
      g_applyMamdaniDefuzzificationMe(fis->outputSamplePoints, sw, arr,
        fis->outputRange, fis->numOutputs, r31);
      loop_ub = r31->size[0];
      for (i62 = 0; i62 < loop_ub; i62++) {
        y->data[i62] = r31->data[i62];
      }
    } else {
      applySugenoImplicationMethod(x, w, fis->outputMF, fis->consequent,
        fis->numOutputs, fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
        fis->orrSize, orr, irr);
      applySugenoAggregationMethod(orr, inputMFCache);
      b_inputMFCache = *inputMFCache;
      f_arr[0] = (*(int (*)[2])arr->size)[0];
      f_arr[1] = (*(int (*)[2])arr->size)[1];
      b_inputMFCache.size = &f_arr[0];
      b_inputMFCache.numDimensions = 1;
      f_applySugenoDefuzzificationMet(sw, &b_inputMFCache, fis->outputRange,
        fis->numOutputs, r31);
      loop_ub = r31->size[0];
      for (i62 = 0; i62 < loop_ub; i62++) {
        y->data[i62] = r31->data[i62];
      }
    }
  } else if (j_isequal(fis->defuzzMethod, uv24)) {
    initVariables(fis->type, fis->outputMF, fis->numInputs, fis->numOutputs,
                  fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                  fis->outputSamplePoints, fis->orrSize, fis->aggSize, y, irr,
                  orr, arr, w, unImpSugRuleOut, outputMFCache);
    extractVarMF(fis->inputMF, inVarMF);
    sw = sum(fis->numInputMFs);
    i62 = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)sw;
    emxEnsureCapacity_real_T(inputMFCache, i62);
    loop_ub = inputs->size[1];
    i62 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = loop_ub;
    emxEnsureCapacity_real_T(x, i62);
    for (i62 = 0; i62 < loop_ub; i62++) {
      x->data[i62] = inputs->data[i62];
    }

    fuzzifyInputs(x, fis->antecedent, fis->connection, fis->numInputs,
                  fis->numRules, fis->numInputMFs, fis->numCumInputMFs, inVarMF,
                  inputMFCache, irr);
    i62 = r31->size[0];
    r31->size[0] = fis->numInputs;
    emxEnsureCapacity_real_T(r31, i62);
    loop_ub = fis->numInputs;
    for (i62 = 0; i62 < loop_ub; i62++) {
      r31->data[i62] = 0.0;
    }

    sw = applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                        fis->weight, fis->numInputs, fis->numRules, w, r31);
    b_char(fis->type, r32);
    if (e_strcmp(r32)) {
      applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
        fis->numOutputs, fis->numRules, fis->numCumOutputMFs, fis->orrSize,
        outputMFCache, orr);
      applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
        fis->numRules, fis->aggSize, arr);
      h_applyMamdaniDefuzzificationMe(fis->outputSamplePoints, sw, arr,
        fis->outputRange, fis->numOutputs, r31);
      loop_ub = r31->size[0];
      for (i62 = 0; i62 < loop_ub; i62++) {
        y->data[i62] = r31->data[i62];
      }
    } else {
      applySugenoImplicationMethod(x, w, fis->outputMF, fis->consequent,
        fis->numOutputs, fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
        fis->orrSize, orr, irr);
      applySugenoAggregationMethod(orr, inputMFCache);
      b_inputMFCache = *inputMFCache;
      g_arr[0] = (*(int (*)[2])arr->size)[0];
      g_arr[1] = (*(int (*)[2])arr->size)[1];
      b_inputMFCache.size = &g_arr[0];
      b_inputMFCache.numDimensions = 1;
      g_applySugenoDefuzzificationMet(sw, &b_inputMFCache, fis->outputRange,
        fis->numOutputs, r31);
      loop_ub = r31->size[0];
      for (i62 = 0; i62 < loop_ub; i62++) {
        y->data[i62] = r31->data[i62];
      }
    }
  } else if (k_isequal(fis->defuzzMethod, uv25)) {
    initVariables(fis->type, fis->outputMF, fis->numInputs, fis->numOutputs,
                  fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                  fis->outputSamplePoints, fis->orrSize, fis->aggSize, y, irr,
                  orr, arr, w, unImpSugRuleOut, outputMFCache);
    extractVarMF(fis->inputMF, inVarMF);
    sw = sum(fis->numInputMFs);
    i62 = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)sw;
    emxEnsureCapacity_real_T(inputMFCache, i62);
    loop_ub = inputs->size[1];
    i62 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = loop_ub;
    emxEnsureCapacity_real_T(x, i62);
    for (i62 = 0; i62 < loop_ub; i62++) {
      x->data[i62] = inputs->data[i62];
    }

    fuzzifyInputs(x, fis->antecedent, fis->connection, fis->numInputs,
                  fis->numRules, fis->numInputMFs, fis->numCumInputMFs, inVarMF,
                  inputMFCache, irr);
    i62 = r31->size[0];
    r31->size[0] = fis->numInputs;
    emxEnsureCapacity_real_T(r31, i62);
    loop_ub = fis->numInputs;
    for (i62 = 0; i62 < loop_ub; i62++) {
      r31->data[i62] = 0.0;
    }

    sw = applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                        fis->weight, fis->numInputs, fis->numRules, w, r31);
    b_char(fis->type, r32);
    if (e_strcmp(r32)) {
      applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
        fis->numOutputs, fis->numRules, fis->numCumOutputMFs, fis->orrSize,
        outputMFCache, orr);
      applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
        fis->numRules, fis->aggSize, arr);
      i_applyMamdaniDefuzzificationMe(fis->outputSamplePoints, sw,
        fis->outputRange, fis->numOutputs, r31);
      loop_ub = r31->size[0];
      for (i62 = 0; i62 < loop_ub; i62++) {
        y->data[i62] = r31->data[i62];
      }
    } else {
      applySugenoImplicationMethod(x, w, fis->outputMF, fis->consequent,
        fis->numOutputs, fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
        fis->orrSize, orr, irr);
      applySugenoAggregationMethod(orr, inputMFCache);
      b_inputMFCache = *inputMFCache;
      h_arr[0] = (*(int (*)[2])arr->size)[0];
      h_arr[1] = (*(int (*)[2])arr->size)[1];
      b_inputMFCache.size = &h_arr[0];
      b_inputMFCache.numDimensions = 1;
      f_applySugenoDefuzzificationMet(sw, &b_inputMFCache, fis->outputRange,
        fis->numOutputs, r31);
      loop_ub = r31->size[0];
      for (i62 = 0; i62 < loop_ub; i62++) {
        y->data[i62] = r31->data[i62];
      }
    }
  } else {
    i62 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = fis->numOutputs;
    emxEnsureCapacity_real_T(y, i62);
    b_char(fis->type, r32);
    if (e_strcmp(r32)) {
      emxInit_real_T(&b_fis, 2);
      createMamdaniOutputMFCache(fis->outputMF, fis->numOutputs,
        fis->numOutputMFs, fis->numCumOutputMFs, fis->outputSamplePoints, b_fis);
      emxFree_real_T(&b_fis);
    }

    exit(0);
  }

  emxFree_char_T(&r32);
  emxFree_real_T(&r31);
  emxFree_real_T(&outputMFCache);
  emxFree_real_T(&unImpSugRuleOut);
  emxFree_real_T(&w);
  emxFree_real_T(&arr);
  emxFree_real_T(&orr);
  emxFree_real_T(&irr);
  emxFree_real_T(&x);
  emxFree_real_T(&inputMFCache);
  emxFree_cell_wrap_0(&inVarMF);
}

/*
 * File trailer for evaluateFIS.c
 *
 * [EOF]
 */
