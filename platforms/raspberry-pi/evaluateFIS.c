/*
 * File: evaluateFIS.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "evaluateFIS.h"
#include "applyMamdaniAggregationMethod.h"
#include "applyMamdaniDefuzzificationMethod.h"
#include "applyMamdaniImplicationMethod.h"
#include "applyOperators.h"
#include "applySugenoAggregationMethod.h"
#include "applySugenoDefuzzificationMethod.h"
#include "applySugenoImplicationMethod.h"
#include "createMamdaniOutputMFCache.h"
#include "extractVarMF.h"
#include "fuzzifyInputs.h"
#include "isequal.h"
#include "opkene_emxutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"
#include "sum.h"

/* Function Declarations */
static double b_initVariables(
    const emxArray_uint8_T *fis_type, const e_emxArray_struct_T *fis_outputMF,
    int fis_numOutputs, int fis_numRules,
    const emxArray_int32_T *fis_numOutputMFs,
    const emxArray_int32_T *fis_numCumOutputMFs,
    const emxArray_real_T *fis_outputSamplePoints, const int fis_orrSize[2],
    const int fis_aggSize[2], const emxArray_real_T *inputs, emxArray_real_T *y,
    emxArray_real_T *irr, emxArray_real_T *orr, emxArray_real_T *arr,
    emxArray_real_T *rfs, emxArray_real_T *unImpSugRuleOut,
    emxArray_real_T *outputMFCache);

static void b_runFIS(const emxArray_real_T *inputs, const i_struct_T *fis,
                     emxArray_real_T *y, emxArray_real_T *irr,
                     emxArray_real_T *orr, emxArray_real_T *arr,
                     emxArray_real_T *w, emxArray_real_T *unImpSugRuleOut);

static void c_runFIS(const emxArray_real_T *inputs, const i_struct_T *fis,
                     emxArray_real_T *y, emxArray_real_T *irr,
                     emxArray_real_T *orr, emxArray_real_T *arr,
                     emxArray_real_T *w, emxArray_real_T *unImpSugRuleOut);

static void initVariables(
    const emxArray_uint8_T *fis_type, const e_emxArray_struct_T *fis_outputMF,
    int fis_numInputs, int fis_numOutputs, int fis_numRules,
    const emxArray_int32_T *fis_numOutputMFs,
    const emxArray_int32_T *fis_numCumOutputMFs,
    const emxArray_real_T *fis_outputSamplePoints, const int fis_orrSize[2],
    const int fis_aggSize[2], emxArray_real_T *y, emxArray_real_T *irr,
    emxArray_real_T *orr, emxArray_real_T *arr, emxArray_real_T *rfs,
    emxArray_real_T *unImpSugRuleOut, emxArray_real_T *outputMFCache);

static void runFIS(const emxArray_real_T *inputs, const i_struct_T *fis,
                   emxArray_real_T *y, emxArray_real_T *irr,
                   emxArray_real_T *orr, emxArray_real_T *arr,
                   emxArray_real_T *w, emxArray_real_T *unImpSugRuleOut);

/* Function Definitions */
/*
 * Arguments    : const emxArray_uint8_T *fis_type
 *                const e_emxArray_struct_T *fis_outputMF
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
 * Return Type  : double
 */
static double b_initVariables(
    const emxArray_uint8_T *fis_type, const e_emxArray_struct_T *fis_outputMF,
    int fis_numOutputs, int fis_numRules,
    const emxArray_int32_T *fis_numOutputMFs,
    const emxArray_int32_T *fis_numCumOutputMFs,
    const emxArray_real_T *fis_outputSamplePoints, const int fis_orrSize[2],
    const int fis_aggSize[2], const emxArray_real_T *inputs, emxArray_real_T *y,
    emxArray_real_T *irr, emxArray_real_T *orr, emxArray_real_T *arr,
    emxArray_real_T *rfs, emxArray_real_T *unImpSugRuleOut,
    emxArray_real_T *outputMFCache)
{
  static const char cv[7] = {'m', 'a', 'm', 'd', 'a', 'n', 'i'};
  emxArray_char_T *b_y;
  double *outputMFCache_data;
  int b_numInputDataSets;
  int i;
  int loop_ub;
  const unsigned char *fis_type_data;
  char *y_data;
  boolean_T b_bool;
  fis_type_data = fis_type->data;
  b_numInputDataSets = inputs->size[0];
  i = y->size[0] * y->size[1];
  y->size[0] = inputs->size[0];
  y->size[1] = fis_numOutputs;
  emxEnsureCapacity_real_T(y, i);
  i = irr->size[0] * irr->size[1];
  irr->size[0] = fis_numRules;
  irr->size[1] = 1;
  emxEnsureCapacity_real_T(irr, i);
  i = orr->size[0] * orr->size[1];
  orr->size[0] = fis_orrSize[0];
  orr->size[1] = fis_orrSize[1];
  emxEnsureCapacity_real_T(orr, i);
  i = arr->size[0] * arr->size[1];
  arr->size[0] = fis_aggSize[0];
  arr->size[1] = fis_aggSize[1];
  emxEnsureCapacity_real_T(arr, i);
  i = rfs->size[0];
  rfs->size[0] = fis_numRules;
  emxEnsureCapacity_real_T(rfs, i);
  emxInit_char_T(&b_y, 2);
  i = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = fis_type->size[1];
  emxEnsureCapacity_char_T(b_y, i);
  y_data = b_y->data;
  loop_ub = fis_type->size[1];
  for (i = 0; i < loop_ub; i++) {
    y_data[i] = (signed char)fis_type_data[i];
  }
  b_bool = false;
  if (b_y->size[1] == 7) {
    loop_ub = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (loop_ub < 7) {
        if (y_data[loop_ub] != cv[loop_ub]) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  emxFree_char_T(&b_y);
  if (b_bool) {
    createMamdaniOutputMFCache(fis_outputMF, fis_numOutputs, fis_numOutputMFs,
                               fis_numCumOutputMFs, fis_outputSamplePoints,
                               outputMFCache);
    i = unImpSugRuleOut->size[0] * unImpSugRuleOut->size[1];
    unImpSugRuleOut->size[0] = 1;
    unImpSugRuleOut->size[1] = 1;
    emxEnsureCapacity_real_T(unImpSugRuleOut, i);
    outputMFCache_data = unImpSugRuleOut->data;
    outputMFCache_data[0] = 0.0;
  } else {
    i = outputMFCache->size[0] * outputMFCache->size[1];
    outputMFCache->size[0] = 1;
    outputMFCache->size[1] = 1;
    emxEnsureCapacity_real_T(outputMFCache, i);
    outputMFCache_data = outputMFCache->data;
    outputMFCache_data[0] = 0.0;
    i = unImpSugRuleOut->size[0] * unImpSugRuleOut->size[1];
    unImpSugRuleOut->size[0] = fis_orrSize[0];
    unImpSugRuleOut->size[1] = fis_orrSize[1];
    emxEnsureCapacity_real_T(unImpSugRuleOut, i);
  }
  return b_numInputDataSets;
}

/*
 * Arguments    : const emxArray_real_T *inputs
 *                const i_struct_T *fis
 *                emxArray_real_T *y
 *                emxArray_real_T *irr
 *                emxArray_real_T *orr
 *                emxArray_real_T *arr
 *                emxArray_real_T *w
 *                emxArray_real_T *unImpSugRuleOut
 * Return Type  : void
 */
static void b_runFIS(const emxArray_real_T *inputs, const i_struct_T *fis,
                     emxArray_real_T *y, emxArray_real_T *irr,
                     emxArray_real_T *orr, emxArray_real_T *arr,
                     emxArray_real_T *w, emxArray_real_T *unImpSugRuleOut)
{
  static const char cv[7] = {'m', 'a', 'm', 'd', 'a', 'n', 'i'};
  emxArray_cell_wrap_0 *inVarMF;
  emxArray_char_T *b_y;
  emxArray_real_T *defuzzifiedOutputs;
  emxArray_real_T *inputMFCache;
  emxArray_real_T *outputMFCache;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  const double *inputs_data;
  double irrOfOneRule_data;
  double numInputDataSets;
  double *arr_data;
  double *defuzzifiedOutputs_data;
  double *y_data;
  int b_i;
  int i;
  int i1;
  int loop_ub;
  char *b_y_data;
  inputs_data = inputs->data;
  emxInit_real_T(&outputMFCache, 2);
  numInputDataSets = b_initVariables(
      fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
      fis->numOutputMFs, fis->numCumOutputMFs, fis->outputSamplePoints,
      fis->orrSize, fis->aggSize, inputs, y, irr, orr, arr, w, unImpSugRuleOut,
      outputMFCache);
  y_data = y->data;
  emxInit_cell_wrap_0(&inVarMF);
  extractVarMF(fis->inputMF, inVarMF);
  emxInit_real_T(&inputMFCache, 2);
  i = inputMFCache->size[0] * inputMFCache->size[1];
  inputMFCache->size[0] = 1;
  inputMFCache->size[1] = (int)sum(fis->numInputMFs);
  emxEnsureCapacity_real_T(inputMFCache, i);
  irrOfOneRule_data = 0.0;
  i = (int)numInputDataSets;
  emxInit_real_T(&r, 1);
  emxInit_char_T(&b_y, 2);
  emxInit_real_T(&defuzzifiedOutputs, 1);
  emxInit_real_T(&r1, 2);
  for (b_i = 0; b_i < i; b_i++) {
    boolean_T b_bool;
    b_fuzzifyInputs(inputs_data[b_i], fis->antecedent, fis->connection,
                    fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                    inVarMF, inputMFCache, irr);
    i1 = r->size[0];
    r->size[0] = 1;
    emxEnsureCapacity_real_T(r, i1);
    defuzzifiedOutputs_data = r->data;
    defuzzifiedOutputs_data[0] = irrOfOneRule_data;
    numInputDataSets =
        applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                       fis->weight, fis->numInputs, fis->numRules, w, r);
    defuzzifiedOutputs_data = r->data;
    loop_ub = r->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      irrOfOneRule_data = defuzzifiedOutputs_data[i1];
    }
    i1 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    loop_ub = fis->type->size[1];
    b_y->size[1] = fis->type->size[1];
    emxEnsureCapacity_char_T(b_y, i1);
    b_y_data = b_y->data;
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_y_data[i1] = (signed char)fis->type->data[i1];
    }
    b_bool = false;
    if (b_y->size[1] == 7) {
      loop_ub = 0;
      int exitg1;
      do {
        exitg1 = 0;
        if (loop_ub < 7) {
          if (b_y_data[loop_ub] != cv[loop_ub]) {
            exitg1 = 1;
          } else {
            loop_ub++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (b_bool) {
      applyMamdaniImplicationMethod(
          w, fis->impMethod, fis->consequent, fis->numOutputs, fis->numRules,
          fis->numCumOutputMFs, fis->orrSize, outputMFCache, orr);
      applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                                    fis->numRules, fis->aggSize, arr);
      h_applyMamdaniDefuzzificationMe(fis->outputSamplePoints, numInputDataSets,
                                      arr, fis->outputRange, fis->numOutputs,
                                      r);
      defuzzifiedOutputs_data = r->data;
      loop_ub = r->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        y_data[b_i + y->size[0] * i1] = defuzzifiedOutputs_data[i1];
      }
    } else {
      int arr_idx_1;
      unsigned int u;
      b_applySugenoImplicationMethod(
          inputs_data[b_i], w, fis->outputMF, fis->consequent, fis->numOutputs,
          fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs, fis->orrSize,
          orr, unImpSugRuleOut);
      applySugenoAggregationMethod(orr, r1);
      defuzzifiedOutputs_data = r1->data;
      loop_ub = arr->size[0];
      arr_idx_1 = arr->size[1];
      i1 = arr->size[0] * arr->size[1];
      arr->size[0] = loop_ub;
      arr->size[1] = arr_idx_1;
      emxEnsureCapacity_real_T(arr, i1);
      arr_data = arr->data;
      loop_ub *= arr_idx_1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        arr_data[i1] = defuzzifiedOutputs_data[i1];
      }
      i1 = defuzzifiedOutputs->size[0];
      defuzzifiedOutputs->size[0] = fis->numOutputs;
      emxEnsureCapacity_real_T(defuzzifiedOutputs, i1);
      defuzzifiedOutputs_data = defuzzifiedOutputs->data;
      u = (unsigned int)fis->numOutputs;
      if ((unsigned int)fis->numOutputs > 2147483647UL) {
        u = 2147483647UL;
      }
      i1 = (int)u;
      for (loop_ub = 0; loop_ub < i1; loop_ub++) {
        if (numInputDataSets == 0.0) {
          defuzzifiedOutputs_data[loop_ub] =
              (fis->outputRange->data[loop_ub] +
               fis->outputRange->data[loop_ub + fis->outputRange->size[0]]) /
              2.0;
        } else {
          defuzzifiedOutputs_data[loop_ub] =
              arr_data[loop_ub] * (1.0 / numInputDataSets);
        }
      }
      loop_ub = defuzzifiedOutputs->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        y_data[b_i + y->size[0] * i1] = defuzzifiedOutputs_data[i1];
      }
    }
  }
  emxFree_real_T(&r1);
  emxFree_real_T(&defuzzifiedOutputs);
  emxFree_char_T(&b_y);
  emxFree_real_T(&r);
  emxFree_real_T(&outputMFCache);
  emxFree_real_T(&inputMFCache);
  emxFree_cell_wrap_0(&inVarMF);
}

/*
 * Arguments    : const emxArray_real_T *inputs
 *                const i_struct_T *fis
 *                emxArray_real_T *y
 *                emxArray_real_T *irr
 *                emxArray_real_T *orr
 *                emxArray_real_T *arr
 *                emxArray_real_T *w
 *                emxArray_real_T *unImpSugRuleOut
 * Return Type  : void
 */
static void c_runFIS(const emxArray_real_T *inputs, const i_struct_T *fis,
                     emxArray_real_T *y, emxArray_real_T *irr,
                     emxArray_real_T *orr, emxArray_real_T *arr,
                     emxArray_real_T *w, emxArray_real_T *unImpSugRuleOut)
{
  static const char cv[7] = {'m', 'a', 'm', 'd', 'a', 'n', 'i'};
  emxArray_cell_wrap_0 *inVarMF;
  emxArray_char_T *b_y;
  emxArray_real_T *defuzzifiedOutputs;
  emxArray_real_T *inputMFCache;
  emxArray_real_T *outputMFCache;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  const double *inputs_data;
  double irrOfOneRule_data;
  double numInputDataSets;
  double *arr_data;
  double *defuzzifiedOutputs_data;
  double *y_data;
  int b_i;
  int i;
  int i1;
  int loop_ub;
  char *b_y_data;
  inputs_data = inputs->data;
  emxInit_real_T(&outputMFCache, 2);
  numInputDataSets = b_initVariables(
      fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
      fis->numOutputMFs, fis->numCumOutputMFs, fis->outputSamplePoints,
      fis->orrSize, fis->aggSize, inputs, y, irr, orr, arr, w, unImpSugRuleOut,
      outputMFCache);
  y_data = y->data;
  emxInit_cell_wrap_0(&inVarMF);
  extractVarMF(fis->inputMF, inVarMF);
  emxInit_real_T(&inputMFCache, 2);
  i = inputMFCache->size[0] * inputMFCache->size[1];
  inputMFCache->size[0] = 1;
  inputMFCache->size[1] = (int)sum(fis->numInputMFs);
  emxEnsureCapacity_real_T(inputMFCache, i);
  irrOfOneRule_data = 0.0;
  i = (int)numInputDataSets;
  emxInit_real_T(&r, 1);
  emxInit_char_T(&b_y, 2);
  emxInit_real_T(&defuzzifiedOutputs, 1);
  emxInit_real_T(&r1, 2);
  for (b_i = 0; b_i < i; b_i++) {
    boolean_T b_bool;
    b_fuzzifyInputs(inputs_data[b_i], fis->antecedent, fis->connection,
                    fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                    inVarMF, inputMFCache, irr);
    i1 = r->size[0];
    r->size[0] = 1;
    emxEnsureCapacity_real_T(r, i1);
    defuzzifiedOutputs_data = r->data;
    defuzzifiedOutputs_data[0] = irrOfOneRule_data;
    numInputDataSets =
        applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                       fis->weight, fis->numInputs, fis->numRules, w, r);
    defuzzifiedOutputs_data = r->data;
    loop_ub = r->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      irrOfOneRule_data = defuzzifiedOutputs_data[i1];
    }
    i1 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    loop_ub = fis->type->size[1];
    b_y->size[1] = fis->type->size[1];
    emxEnsureCapacity_char_T(b_y, i1);
    b_y_data = b_y->data;
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_y_data[i1] = (signed char)fis->type->data[i1];
    }
    b_bool = false;
    if (b_y->size[1] == 7) {
      loop_ub = 0;
      int exitg1;
      do {
        exitg1 = 0;
        if (loop_ub < 7) {
          if (b_y_data[loop_ub] != cv[loop_ub]) {
            exitg1 = 1;
          } else {
            loop_ub++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (b_bool) {
      applyMamdaniImplicationMethod(
          w, fis->impMethod, fis->consequent, fis->numOutputs, fis->numRules,
          fis->numCumOutputMFs, fis->orrSize, outputMFCache, orr);
      applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                                    fis->numRules, fis->aggSize, arr);
      i_applyMamdaniDefuzzificationMe(fis->outputSamplePoints, numInputDataSets,
                                      fis->outputRange, fis->numOutputs, r);
      defuzzifiedOutputs_data = r->data;
      loop_ub = r->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        y_data[b_i + y->size[0] * i1] = defuzzifiedOutputs_data[i1];
      }
    } else {
      int arr_idx_1;
      unsigned int u;
      b_applySugenoImplicationMethod(
          inputs_data[b_i], w, fis->outputMF, fis->consequent, fis->numOutputs,
          fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs, fis->orrSize,
          orr, unImpSugRuleOut);
      applySugenoAggregationMethod(orr, r1);
      defuzzifiedOutputs_data = r1->data;
      loop_ub = arr->size[0];
      arr_idx_1 = arr->size[1];
      i1 = arr->size[0] * arr->size[1];
      arr->size[0] = loop_ub;
      arr->size[1] = arr_idx_1;
      emxEnsureCapacity_real_T(arr, i1);
      arr_data = arr->data;
      loop_ub *= arr_idx_1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        arr_data[i1] = defuzzifiedOutputs_data[i1];
      }
      i1 = defuzzifiedOutputs->size[0];
      defuzzifiedOutputs->size[0] = fis->numOutputs;
      emxEnsureCapacity_real_T(defuzzifiedOutputs, i1);
      defuzzifiedOutputs_data = defuzzifiedOutputs->data;
      u = (unsigned int)fis->numOutputs;
      if ((unsigned int)fis->numOutputs > 2147483647UL) {
        u = 2147483647UL;
      }
      i1 = (int)u;
      for (loop_ub = 0; loop_ub < i1; loop_ub++) {
        if (numInputDataSets == 0.0) {
          defuzzifiedOutputs_data[loop_ub] =
              (fis->outputRange->data[loop_ub] +
               fis->outputRange->data[loop_ub + fis->outputRange->size[0]]) /
              2.0;
        } else {
          defuzzifiedOutputs_data[loop_ub] = arr_data[loop_ub];
        }
      }
      loop_ub = defuzzifiedOutputs->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        y_data[b_i + y->size[0] * i1] = defuzzifiedOutputs_data[i1];
      }
    }
  }
  emxFree_real_T(&r1);
  emxFree_real_T(&defuzzifiedOutputs);
  emxFree_char_T(&b_y);
  emxFree_real_T(&r);
  emxFree_real_T(&outputMFCache);
  emxFree_real_T(&inputMFCache);
  emxFree_cell_wrap_0(&inVarMF);
}

/*
 * Arguments    : const emxArray_uint8_T *fis_type
 *                const e_emxArray_struct_T *fis_outputMF
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
static void initVariables(
    const emxArray_uint8_T *fis_type, const e_emxArray_struct_T *fis_outputMF,
    int fis_numInputs, int fis_numOutputs, int fis_numRules,
    const emxArray_int32_T *fis_numOutputMFs,
    const emxArray_int32_T *fis_numCumOutputMFs,
    const emxArray_real_T *fis_outputSamplePoints, const int fis_orrSize[2],
    const int fis_aggSize[2], emxArray_real_T *y, emxArray_real_T *irr,
    emxArray_real_T *orr, emxArray_real_T *arr, emxArray_real_T *rfs,
    emxArray_real_T *unImpSugRuleOut, emxArray_real_T *outputMFCache)
{
  static const char cv[7] = {'m', 'a', 'm', 'd', 'a', 'n', 'i'};
  emxArray_char_T *b_y;
  double *outputMFCache_data;
  int i;
  int loop_ub;
  const unsigned char *fis_type_data;
  char *y_data;
  boolean_T b_bool;
  fis_type_data = fis_type->data;
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = fis_numOutputs;
  emxEnsureCapacity_real_T(y, i);
  i = irr->size[0] * irr->size[1];
  irr->size[0] = fis_numRules;
  irr->size[1] = fis_numInputs;
  emxEnsureCapacity_real_T(irr, i);
  i = orr->size[0] * orr->size[1];
  orr->size[0] = fis_orrSize[0];
  orr->size[1] = fis_orrSize[1];
  emxEnsureCapacity_real_T(orr, i);
  i = arr->size[0] * arr->size[1];
  arr->size[0] = fis_aggSize[0];
  arr->size[1] = fis_aggSize[1];
  emxEnsureCapacity_real_T(arr, i);
  i = rfs->size[0];
  rfs->size[0] = fis_numRules;
  emxEnsureCapacity_real_T(rfs, i);
  emxInit_char_T(&b_y, 2);
  i = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = fis_type->size[1];
  emxEnsureCapacity_char_T(b_y, i);
  y_data = b_y->data;
  loop_ub = fis_type->size[1];
  for (i = 0; i < loop_ub; i++) {
    y_data[i] = (signed char)fis_type_data[i];
  }
  b_bool = false;
  if (b_y->size[1] == 7) {
    loop_ub = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (loop_ub < 7) {
        if (y_data[loop_ub] != cv[loop_ub]) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  emxFree_char_T(&b_y);
  if (b_bool) {
    createMamdaniOutputMFCache(fis_outputMF, fis_numOutputs, fis_numOutputMFs,
                               fis_numCumOutputMFs, fis_outputSamplePoints,
                               outputMFCache);
    i = unImpSugRuleOut->size[0] * unImpSugRuleOut->size[1];
    unImpSugRuleOut->size[0] = 1;
    unImpSugRuleOut->size[1] = 1;
    emxEnsureCapacity_real_T(unImpSugRuleOut, i);
    outputMFCache_data = unImpSugRuleOut->data;
    outputMFCache_data[0] = 0.0;
  } else {
    i = outputMFCache->size[0] * outputMFCache->size[1];
    outputMFCache->size[0] = 1;
    outputMFCache->size[1] = 1;
    emxEnsureCapacity_real_T(outputMFCache, i);
    outputMFCache_data = outputMFCache->data;
    outputMFCache_data[0] = 0.0;
    i = unImpSugRuleOut->size[0] * unImpSugRuleOut->size[1];
    unImpSugRuleOut->size[0] = fis_orrSize[0];
    unImpSugRuleOut->size[1] = fis_orrSize[1];
    emxEnsureCapacity_real_T(unImpSugRuleOut, i);
  }
}

/*
 * Arguments    : const emxArray_real_T *inputs
 *                const i_struct_T *fis
 *                emxArray_real_T *y
 *                emxArray_real_T *irr
 *                emxArray_real_T *orr
 *                emxArray_real_T *arr
 *                emxArray_real_T *w
 *                emxArray_real_T *unImpSugRuleOut
 * Return Type  : void
 */
static void runFIS(const emxArray_real_T *inputs, const i_struct_T *fis,
                   emxArray_real_T *y, emxArray_real_T *irr,
                   emxArray_real_T *orr, emxArray_real_T *arr,
                   emxArray_real_T *w, emxArray_real_T *unImpSugRuleOut)
{
  static const char cv[7] = {'m', 'a', 'm', 'd', 'a', 'n', 'i'};
  emxArray_cell_wrap_0 *r;
  emxArray_char_T *b_y;
  emxArray_real_T *b_arr;
  emxArray_real_T *defuzzifiedOutputs;
  emxArray_real_T *inputMFCache;
  emxArray_real_T *outputMFCache;
  emxArray_real_T *r1;
  const double *inputs_data;
  double sw;
  double *arr_data;
  double *defuzzifiedOutputs_data;
  double *y_data;
  int i;
  int loop_ub;
  char *b_y_data;
  boolean_T b_bool;
  inputs_data = inputs->data;
  emxInit_real_T(&b_arr, 2);
  emxInit_real_T(&outputMFCache, 2);
  initVariables(fis->type, fis->outputMF, fis->numInputs, fis->numOutputs,
                fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                fis->outputSamplePoints, fis->orrSize, fis->aggSize, y, irr,
                orr, b_arr, w, unImpSugRuleOut, outputMFCache);
  y_data = y->data;
  emxInit_real_T(&inputMFCache, 2);
  i = inputMFCache->size[0] * inputMFCache->size[1];
  inputMFCache->size[0] = 1;
  inputMFCache->size[1] = (int)sum(fis->numInputMFs);
  emxEnsureCapacity_real_T(inputMFCache, i);
  i = arr->size[0] * arr->size[1];
  arr->size[0] = 1;
  arr->size[1] = inputs->size[1];
  emxEnsureCapacity_real_T(arr, i);
  arr_data = arr->data;
  loop_ub = inputs->size[1];
  for (i = 0; i < loop_ub; i++) {
    arr_data[i] = inputs_data[i];
  }
  emxInit_cell_wrap_0(&r);
  extractVarMF(fis->inputMF, r);
  fuzzifyInputs(arr, fis->antecedent, fis->connection, fis->numInputs,
                fis->numRules, fis->numInputMFs, fis->numCumInputMFs, r,
                inputMFCache, irr);
  emxFree_cell_wrap_0(&r);
  emxInit_real_T(&r1, 1);
  i = r1->size[0];
  r1->size[0] = fis->numInputs;
  emxEnsureCapacity_real_T(r1, i);
  arr_data = r1->data;
  loop_ub = fis->numInputs;
  for (i = 0; i < loop_ub; i++) {
    arr_data[i] = 0.0;
  }
  sw = applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                      fis->weight, fis->numInputs, fis->numRules, w, r1);
  emxInit_char_T(&b_y, 2);
  i = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = fis->type->size[1];
  emxEnsureCapacity_char_T(b_y, i);
  b_y_data = b_y->data;
  loop_ub = fis->type->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_y_data[i] = (signed char)fis->type->data[i];
  }
  b_bool = false;
  if (b_y->size[1] == 7) {
    loop_ub = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (loop_ub < 7) {
        if (b_y_data[loop_ub] != cv[loop_ub]) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  emxFree_char_T(&b_y);
  if (b_bool) {
    applyMamdaniImplicationMethod(
        w, fis->impMethod, fis->consequent, fis->numOutputs, fis->numRules,
        fis->numCumOutputMFs, fis->orrSize, outputMFCache, orr);
    applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                                  fis->numRules, fis->aggSize, arr);
    i_applyMamdaniDefuzzificationMe(fis->outputSamplePoints, sw,
                                    fis->outputRange, fis->numOutputs, r1);
    arr_data = r1->data;
    loop_ub = r1->size[0];
    for (i = 0; i < loop_ub; i++) {
      y_data[i] = arr_data[i];
    }
  } else {
    unsigned int u;
    applySugenoImplicationMethod(arr, w, fis->outputMF, fis->consequent,
                                 fis->numOutputs, fis->numRules,
                                 fis->numOutputMFs, fis->numCumOutputMFs,
                                 fis->orrSize, orr, unImpSugRuleOut);
    applySugenoAggregationMethod(orr, inputMFCache);
    arr_data = inputMFCache->data;
    applySugenoAggregationMethod(orr, arr);
    i = arr->size[0] * arr->size[1];
    arr->size[0] = b_arr->size[0];
    arr->size[1] = b_arr->size[1];
    emxEnsureCapacity_real_T(arr, i);
    emxInit_real_T(&defuzzifiedOutputs, 1);
    i = defuzzifiedOutputs->size[0];
    defuzzifiedOutputs->size[0] = fis->numOutputs;
    emxEnsureCapacity_real_T(defuzzifiedOutputs, i);
    defuzzifiedOutputs_data = defuzzifiedOutputs->data;
    u = (unsigned int)fis->numOutputs;
    if ((unsigned int)fis->numOutputs > 2147483647UL) {
      u = 2147483647UL;
    }
    i = (int)u;
    for (loop_ub = 0; loop_ub < i; loop_ub++) {
      if (sw == 0.0) {
        defuzzifiedOutputs_data[loop_ub] =
            (fis->outputRange->data[loop_ub] +
             fis->outputRange->data[loop_ub + fis->outputRange->size[0]]) /
            2.0;
      } else {
        defuzzifiedOutputs_data[loop_ub] = arr_data[loop_ub];
      }
    }
    loop_ub = defuzzifiedOutputs->size[0];
    for (i = 0; i < loop_ub; i++) {
      y_data[i] = defuzzifiedOutputs_data[i];
    }
    emxFree_real_T(&defuzzifiedOutputs);
  }
  emxFree_real_T(&r1);
  emxFree_real_T(&outputMFCache);
  emxFree_real_T(&b_arr);
  emxFree_real_T(&inputMFCache);
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
  static const unsigned char uv[8] = {99U,  101U, 110U, 116U,
                                      114U, 111U, 105U, 100U};
  static const unsigned char uv1[8] = {98U, 105U, 115U, 101U,
                                       99U, 116U, 111U, 114U};
  static const char cv[7] = {'m', 'a', 'm', 'd', 'a', 'n', 'i'};
  static const unsigned char uv5[6] = {119U, 116U, 97U, 118U, 101U, 114U};
  static const unsigned char uv2[3] = {109U, 111U, 109U};
  static const unsigned char uv3[3] = {115U, 111U, 109U};
  static const unsigned char uv4[3] = {108U, 111U, 109U};
  emxArray_cell_wrap_0 *inVarMF;
  emxArray_char_T *b_y;
  emxArray_real_T *arr;
  emxArray_real_T *b_fis;
  emxArray_real_T *defuzzifiedOutputs;
  emxArray_real_T *inputMFCache;
  emxArray_real_T *irr;
  emxArray_real_T *orr;
  emxArray_real_T *outputMFCache;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  emxArray_real_T *rfs;
  emxArray_real_T *unImpSugRuleOut;
  const double *inputs_data;
  double *arr_data;
  double *defuzzifiedOutputs_data;
  double *y_data;
  int b_i;
  int i;
  int i1;
  int loop_ub;
  char *b_y_data;
  inputs_data = inputs->data;
  emxInit_real_T(&irr, 2);
  emxInit_real_T(&orr, 2);
  emxInit_real_T(&arr, 2);
  emxInit_real_T(&unImpSugRuleOut, 2);
  emxInit_char_T(&b_y, 2);
  emxInit_cell_wrap_0(&inVarMF);
  emxInit_real_T(&inputMFCache, 2);
  emxInit_real_T(&outputMFCache, 2);
  emxInit_real_T(&r, 1);
  emxInit_real_T(&defuzzifiedOutputs, 1);
  emxInit_real_T(&r1, 2);
  if (isequal(fis->defuzzMethod, uv)) {
    double irrOfOneRule_data;
    double numInputDataSets;
    numInputDataSets = b_initVariables(
        fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
        fis->numOutputMFs, fis->numCumOutputMFs, fis->outputSamplePoints,
        fis->orrSize, fis->aggSize, inputs, y, irr, orr, arr,
        defuzzifiedOutputs, unImpSugRuleOut, outputMFCache);
    y_data = y->data;
    extractVarMF(fis->inputMF, inVarMF);
    i = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)sum(fis->numInputMFs);
    emxEnsureCapacity_real_T(inputMFCache, i);
    irrOfOneRule_data = 0.0;
    i = (int)numInputDataSets;
    for (b_i = 0; b_i < i; b_i++) {
      boolean_T b_bool;
      b_fuzzifyInputs(inputs_data[b_i], fis->antecedent, fis->connection,
                      fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                      inVarMF, inputMFCache, irr);
      i1 = r->size[0];
      r->size[0] = 1;
      emxEnsureCapacity_real_T(r, i1);
      defuzzifiedOutputs_data = r->data;
      defuzzifiedOutputs_data[0] = irrOfOneRule_data;
      numInputDataSets = applyOperators(
          irr, fis->andMethod, fis->orMethod, fis->connection, fis->weight,
          fis->numInputs, fis->numRules, defuzzifiedOutputs, r);
      defuzzifiedOutputs_data = r->data;
      loop_ub = r->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        irrOfOneRule_data = defuzzifiedOutputs_data[i1];
      }
      i1 = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      loop_ub = fis->type->size[1];
      b_y->size[1] = fis->type->size[1];
      emxEnsureCapacity_char_T(b_y, i1);
      b_y_data = b_y->data;
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_y_data[i1] = (signed char)fis->type->data[i1];
      }
      b_bool = false;
      if (b_y->size[1] == 7) {
        loop_ub = 0;
        int exitg1;
        do {
          exitg1 = 0;
          if (loop_ub < 7) {
            if (b_y_data[loop_ub] != cv[loop_ub]) {
              exitg1 = 1;
            } else {
              loop_ub++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (b_bool) {
        applyMamdaniImplicationMethod(defuzzifiedOutputs, fis->impMethod,
                                      fis->consequent, fis->numOutputs,
                                      fis->numRules, fis->numCumOutputMFs,
                                      fis->orrSize, outputMFCache, orr);
        applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                                      fis->numRules, fis->aggSize, arr);
        c_applyMamdaniDefuzzificationMe(fis->outputSamplePoints,
                                        numInputDataSets, arr, fis->outputRange,
                                        fis->numOutputs, r);
        defuzzifiedOutputs_data = r->data;
        loop_ub = r->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          y_data[b_i + y->size[0] * i1] = defuzzifiedOutputs_data[i1];
        }
      } else {
        int arr_idx_1;
        b_applySugenoImplicationMethod(
            inputs_data[b_i], defuzzifiedOutputs, fis->outputMF,
            fis->consequent, fis->numOutputs, fis->numRules, fis->numOutputMFs,
            fis->numCumOutputMFs, fis->orrSize, orr, unImpSugRuleOut);
        applySugenoAggregationMethod(orr, r1);
        defuzzifiedOutputs_data = r1->data;
        loop_ub = arr->size[0];
        arr_idx_1 = arr->size[1];
        i1 = arr->size[0] * arr->size[1];
        arr->size[0] = loop_ub;
        arr->size[1] = arr_idx_1;
        emxEnsureCapacity_real_T(arr, i1);
        arr_data = arr->data;
        loop_ub *= arr_idx_1;
        for (i1 = 0; i1 < loop_ub; i1++) {
          arr_data[i1] = defuzzifiedOutputs_data[i1];
        }
        c_applySugenoDefuzzificationMet(numInputDataSets, arr, fis->outputRange,
                                        fis->numOutputs, r);
        defuzzifiedOutputs_data = r->data;
        loop_ub = r->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          y_data[b_i + y->size[0] * i1] = defuzzifiedOutputs_data[i1];
        }
      }
    }
  } else if (isequal(fis->defuzzMethod, uv1)) {
    double irrOfOneRule_data;
    double numInputDataSets;
    numInputDataSets = b_initVariables(
        fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
        fis->numOutputMFs, fis->numCumOutputMFs, fis->outputSamplePoints,
        fis->orrSize, fis->aggSize, inputs, y, irr, orr, arr,
        defuzzifiedOutputs, unImpSugRuleOut, outputMFCache);
    y_data = y->data;
    extractVarMF(fis->inputMF, inVarMF);
    i = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)sum(fis->numInputMFs);
    emxEnsureCapacity_real_T(inputMFCache, i);
    irrOfOneRule_data = 0.0;
    i = (int)numInputDataSets;
    for (b_i = 0; b_i < i; b_i++) {
      boolean_T b_bool;
      b_fuzzifyInputs(inputs_data[b_i], fis->antecedent, fis->connection,
                      fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                      inVarMF, inputMFCache, irr);
      i1 = r->size[0];
      r->size[0] = 1;
      emxEnsureCapacity_real_T(r, i1);
      defuzzifiedOutputs_data = r->data;
      defuzzifiedOutputs_data[0] = irrOfOneRule_data;
      numInputDataSets = applyOperators(
          irr, fis->andMethod, fis->orMethod, fis->connection, fis->weight,
          fis->numInputs, fis->numRules, defuzzifiedOutputs, r);
      defuzzifiedOutputs_data = r->data;
      loop_ub = r->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        irrOfOneRule_data = defuzzifiedOutputs_data[i1];
      }
      i1 = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      loop_ub = fis->type->size[1];
      b_y->size[1] = fis->type->size[1];
      emxEnsureCapacity_char_T(b_y, i1);
      b_y_data = b_y->data;
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_y_data[i1] = (signed char)fis->type->data[i1];
      }
      b_bool = false;
      if (b_y->size[1] == 7) {
        loop_ub = 0;
        int exitg1;
        do {
          exitg1 = 0;
          if (loop_ub < 7) {
            if (b_y_data[loop_ub] != cv[loop_ub]) {
              exitg1 = 1;
            } else {
              loop_ub++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (b_bool) {
        applyMamdaniImplicationMethod(defuzzifiedOutputs, fis->impMethod,
                                      fis->consequent, fis->numOutputs,
                                      fis->numRules, fis->numCumOutputMFs,
                                      fis->orrSize, outputMFCache, orr);
        applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                                      fis->numRules, fis->aggSize, arr);
        d_applyMamdaniDefuzzificationMe(fis->outputSamplePoints,
                                        numInputDataSets, arr, fis->outputRange,
                                        fis->numOutputs, r);
        defuzzifiedOutputs_data = r->data;
        loop_ub = r->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          y_data[b_i + y->size[0] * i1] = defuzzifiedOutputs_data[i1];
        }
      } else {
        int arr_idx_1;
        b_applySugenoImplicationMethod(
            inputs_data[b_i], defuzzifiedOutputs, fis->outputMF,
            fis->consequent, fis->numOutputs, fis->numRules, fis->numOutputMFs,
            fis->numCumOutputMFs, fis->orrSize, orr, unImpSugRuleOut);
        applySugenoAggregationMethod(orr, r1);
        defuzzifiedOutputs_data = r1->data;
        loop_ub = arr->size[0];
        arr_idx_1 = arr->size[1];
        i1 = arr->size[0] * arr->size[1];
        arr->size[0] = loop_ub;
        arr->size[1] = arr_idx_1;
        emxEnsureCapacity_real_T(arr, i1);
        arr_data = arr->data;
        loop_ub *= arr_idx_1;
        for (i1 = 0; i1 < loop_ub; i1++) {
          arr_data[i1] = defuzzifiedOutputs_data[i1];
        }
        d_applySugenoDefuzzificationMet(numInputDataSets, arr, fis->outputRange,
                                        fis->numOutputs, r);
        defuzzifiedOutputs_data = r->data;
        loop_ub = r->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          y_data[b_i + y->size[0] * i1] = defuzzifiedOutputs_data[i1];
        }
      }
    }
  } else if (g_isequal(fis->defuzzMethod, uv2)) {
    double irrOfOneRule_data;
    double numInputDataSets;
    numInputDataSets = b_initVariables(
        fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
        fis->numOutputMFs, fis->numCumOutputMFs, fis->outputSamplePoints,
        fis->orrSize, fis->aggSize, inputs, y, irr, orr, arr,
        defuzzifiedOutputs, unImpSugRuleOut, outputMFCache);
    y_data = y->data;
    extractVarMF(fis->inputMF, inVarMF);
    i = inputMFCache->size[0] * inputMFCache->size[1];
    inputMFCache->size[0] = 1;
    inputMFCache->size[1] = (int)sum(fis->numInputMFs);
    emxEnsureCapacity_real_T(inputMFCache, i);
    irrOfOneRule_data = 0.0;
    i = (int)numInputDataSets;
    for (b_i = 0; b_i < i; b_i++) {
      boolean_T b_bool;
      b_fuzzifyInputs(inputs_data[b_i], fis->antecedent, fis->connection,
                      fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                      inVarMF, inputMFCache, irr);
      i1 = r->size[0];
      r->size[0] = 1;
      emxEnsureCapacity_real_T(r, i1);
      defuzzifiedOutputs_data = r->data;
      defuzzifiedOutputs_data[0] = irrOfOneRule_data;
      numInputDataSets = applyOperators(
          irr, fis->andMethod, fis->orMethod, fis->connection, fis->weight,
          fis->numInputs, fis->numRules, defuzzifiedOutputs, r);
      defuzzifiedOutputs_data = r->data;
      loop_ub = r->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        irrOfOneRule_data = defuzzifiedOutputs_data[i1];
      }
      i1 = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      loop_ub = fis->type->size[1];
      b_y->size[1] = fis->type->size[1];
      emxEnsureCapacity_char_T(b_y, i1);
      b_y_data = b_y->data;
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_y_data[i1] = (signed char)fis->type->data[i1];
      }
      b_bool = false;
      if (b_y->size[1] == 7) {
        loop_ub = 0;
        int exitg1;
        do {
          exitg1 = 0;
          if (loop_ub < 7) {
            if (b_y_data[loop_ub] != cv[loop_ub]) {
              exitg1 = 1;
            } else {
              loop_ub++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (b_bool) {
        applyMamdaniImplicationMethod(defuzzifiedOutputs, fis->impMethod,
                                      fis->consequent, fis->numOutputs,
                                      fis->numRules, fis->numCumOutputMFs,
                                      fis->orrSize, outputMFCache, orr);
        applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                                      fis->numRules, fis->aggSize, arr);
        e_applyMamdaniDefuzzificationMe(fis->outputSamplePoints,
                                        numInputDataSets, arr, fis->outputRange,
                                        fis->numOutputs, r);
        defuzzifiedOutputs_data = r->data;
        loop_ub = r->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          y_data[b_i + y->size[0] * i1] = defuzzifiedOutputs_data[i1];
        }
      } else {
        int arr_idx_1;
        b_applySugenoImplicationMethod(
            inputs_data[b_i], defuzzifiedOutputs, fis->outputMF,
            fis->consequent, fis->numOutputs, fis->numRules, fis->numOutputMFs,
            fis->numCumOutputMFs, fis->orrSize, orr, unImpSugRuleOut);
        applySugenoAggregationMethod(orr, r1);
        defuzzifiedOutputs_data = r1->data;
        loop_ub = arr->size[0];
        arr_idx_1 = arr->size[1];
        i1 = arr->size[0] * arr->size[1];
        arr->size[0] = loop_ub;
        arr->size[1] = arr_idx_1;
        emxEnsureCapacity_real_T(arr, i1);
        arr_data = arr->data;
        loop_ub *= arr_idx_1;
        for (i1 = 0; i1 < loop_ub; i1++) {
          arr_data[i1] = defuzzifiedOutputs_data[i1];
        }
        e_applySugenoDefuzzificationMet(numInputDataSets, arr, fis->outputRange,
                                        fis->numOutputs, r);
        defuzzifiedOutputs_data = r->data;
        loop_ub = r->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          y_data[b_i + y->size[0] * i1] = defuzzifiedOutputs_data[i1];
        }
      }
    }
  } else {
    emxInit_real_T(&rfs, 1);
    if (g_isequal(fis->defuzzMethod, uv3)) {
      double irrOfOneRule_data;
      double numInputDataSets;
      numInputDataSets = b_initVariables(
          fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
          fis->numOutputMFs, fis->numCumOutputMFs, fis->outputSamplePoints,
          fis->orrSize, fis->aggSize, inputs, y, irr, orr, arr, rfs,
          unImpSugRuleOut, outputMFCache);
      y_data = y->data;
      extractVarMF(fis->inputMF, inVarMF);
      i = inputMFCache->size[0] * inputMFCache->size[1];
      inputMFCache->size[0] = 1;
      inputMFCache->size[1] = (int)sum(fis->numInputMFs);
      emxEnsureCapacity_real_T(inputMFCache, i);
      irrOfOneRule_data = 0.0;
      i = (int)numInputDataSets;
      for (b_i = 0; b_i < i; b_i++) {
        boolean_T b_bool;
        b_fuzzifyInputs(inputs_data[b_i], fis->antecedent, fis->connection,
                        fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                        inVarMF, inputMFCache, irr);
        i1 = r->size[0];
        r->size[0] = 1;
        emxEnsureCapacity_real_T(r, i1);
        defuzzifiedOutputs_data = r->data;
        defuzzifiedOutputs_data[0] = irrOfOneRule_data;
        numInputDataSets =
            applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                           fis->weight, fis->numInputs, fis->numRules, rfs, r);
        defuzzifiedOutputs_data = r->data;
        loop_ub = r->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          irrOfOneRule_data = defuzzifiedOutputs_data[i1];
        }
        i1 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        loop_ub = fis->type->size[1];
        b_y->size[1] = fis->type->size[1];
        emxEnsureCapacity_char_T(b_y, i1);
        b_y_data = b_y->data;
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_y_data[i1] = (signed char)fis->type->data[i1];
        }
        b_bool = false;
        if (b_y->size[1] == 7) {
          loop_ub = 0;
          int exitg1;
          do {
            exitg1 = 0;
            if (loop_ub < 7) {
              if (b_y_data[loop_ub] != cv[loop_ub]) {
                exitg1 = 1;
              } else {
                loop_ub++;
              }
            } else {
              b_bool = true;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }
        if (b_bool) {
          applyMamdaniImplicationMethod(rfs, fis->impMethod, fis->consequent,
                                        fis->numOutputs, fis->numRules,
                                        fis->numCumOutputMFs, fis->orrSize,
                                        outputMFCache, orr);
          applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                                        fis->numRules, fis->aggSize, arr);
          f_applyMamdaniDefuzzificationMe(fis->outputSamplePoints,
                                          numInputDataSets, arr,
                                          fis->outputRange, fis->numOutputs, r);
          defuzzifiedOutputs_data = r->data;
          loop_ub = r->size[0];
          for (i1 = 0; i1 < loop_ub; i1++) {
            y_data[b_i + y->size[0] * i1] = defuzzifiedOutputs_data[i1];
          }
        } else {
          int arr_idx_1;
          unsigned int u;
          b_applySugenoImplicationMethod(
              inputs_data[b_i], rfs, fis->outputMF, fis->consequent,
              fis->numOutputs, fis->numRules, fis->numOutputMFs,
              fis->numCumOutputMFs, fis->orrSize, orr, unImpSugRuleOut);
          applySugenoAggregationMethod(orr, r1);
          defuzzifiedOutputs_data = r1->data;
          loop_ub = arr->size[0];
          arr_idx_1 = arr->size[1];
          i1 = arr->size[0] * arr->size[1];
          arr->size[0] = loop_ub;
          arr->size[1] = arr_idx_1;
          emxEnsureCapacity_real_T(arr, i1);
          arr_data = arr->data;
          loop_ub *= arr_idx_1;
          for (i1 = 0; i1 < loop_ub; i1++) {
            arr_data[i1] = defuzzifiedOutputs_data[i1];
          }
          i1 = defuzzifiedOutputs->size[0];
          defuzzifiedOutputs->size[0] = fis->numOutputs;
          emxEnsureCapacity_real_T(defuzzifiedOutputs, i1);
          defuzzifiedOutputs_data = defuzzifiedOutputs->data;
          u = (unsigned int)fis->numOutputs;
          if ((unsigned int)fis->numOutputs > 2147483647UL) {
            u = 2147483647UL;
          }
          i1 = (int)u;
          for (loop_ub = 0; loop_ub < i1; loop_ub++) {
            if (numInputDataSets == 0.0) {
              defuzzifiedOutputs_data[loop_ub] =
                  (fis->outputRange->data[loop_ub] +
                   fis->outputRange
                       ->data[loop_ub + fis->outputRange->size[0]]) /
                  2.0;
            } else {
              defuzzifiedOutputs_data[loop_ub] = arr_data[loop_ub];
            }
          }
          loop_ub = defuzzifiedOutputs->size[0];
          for (i1 = 0; i1 < loop_ub; i1++) {
            y_data[b_i + y->size[0] * i1] = defuzzifiedOutputs_data[i1];
          }
        }
      }
    } else if (g_isequal(fis->defuzzMethod, uv4)) {
      double irrOfOneRule_data;
      double numInputDataSets;
      numInputDataSets = b_initVariables(
          fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
          fis->numOutputMFs, fis->numCumOutputMFs, fis->outputSamplePoints,
          fis->orrSize, fis->aggSize, inputs, y, irr, orr, arr, rfs,
          unImpSugRuleOut, outputMFCache);
      y_data = y->data;
      extractVarMF(fis->inputMF, inVarMF);
      i = inputMFCache->size[0] * inputMFCache->size[1];
      inputMFCache->size[0] = 1;
      inputMFCache->size[1] = (int)sum(fis->numInputMFs);
      emxEnsureCapacity_real_T(inputMFCache, i);
      irrOfOneRule_data = 0.0;
      i = (int)numInputDataSets;
      for (b_i = 0; b_i < i; b_i++) {
        boolean_T b_bool;
        b_fuzzifyInputs(inputs_data[b_i], fis->antecedent, fis->connection,
                        fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                        inVarMF, inputMFCache, irr);
        i1 = r->size[0];
        r->size[0] = 1;
        emxEnsureCapacity_real_T(r, i1);
        defuzzifiedOutputs_data = r->data;
        defuzzifiedOutputs_data[0] = irrOfOneRule_data;
        numInputDataSets =
            applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                           fis->weight, fis->numInputs, fis->numRules, rfs, r);
        defuzzifiedOutputs_data = r->data;
        loop_ub = r->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          irrOfOneRule_data = defuzzifiedOutputs_data[i1];
        }
        i1 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        loop_ub = fis->type->size[1];
        b_y->size[1] = fis->type->size[1];
        emxEnsureCapacity_char_T(b_y, i1);
        b_y_data = b_y->data;
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_y_data[i1] = (signed char)fis->type->data[i1];
        }
        b_bool = false;
        if (b_y->size[1] == 7) {
          loop_ub = 0;
          int exitg1;
          do {
            exitg1 = 0;
            if (loop_ub < 7) {
              if (b_y_data[loop_ub] != cv[loop_ub]) {
                exitg1 = 1;
              } else {
                loop_ub++;
              }
            } else {
              b_bool = true;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }
        if (b_bool) {
          applyMamdaniImplicationMethod(rfs, fis->impMethod, fis->consequent,
                                        fis->numOutputs, fis->numRules,
                                        fis->numCumOutputMFs, fis->orrSize,
                                        outputMFCache, orr);
          applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                                        fis->numRules, fis->aggSize, arr);
          g_applyMamdaniDefuzzificationMe(fis->outputSamplePoints,
                                          numInputDataSets, arr,
                                          fis->outputRange, fis->numOutputs, r);
          defuzzifiedOutputs_data = r->data;
          loop_ub = r->size[0];
          for (i1 = 0; i1 < loop_ub; i1++) {
            y_data[b_i + y->size[0] * i1] = defuzzifiedOutputs_data[i1];
          }
        } else {
          int arr_idx_1;
          unsigned int u;
          b_applySugenoImplicationMethod(
              inputs_data[b_i], rfs, fis->outputMF, fis->consequent,
              fis->numOutputs, fis->numRules, fis->numOutputMFs,
              fis->numCumOutputMFs, fis->orrSize, orr, unImpSugRuleOut);
          applySugenoAggregationMethod(orr, r1);
          defuzzifiedOutputs_data = r1->data;
          loop_ub = arr->size[0];
          arr_idx_1 = arr->size[1];
          i1 = arr->size[0] * arr->size[1];
          arr->size[0] = loop_ub;
          arr->size[1] = arr_idx_1;
          emxEnsureCapacity_real_T(arr, i1);
          arr_data = arr->data;
          loop_ub *= arr_idx_1;
          for (i1 = 0; i1 < loop_ub; i1++) {
            arr_data[i1] = defuzzifiedOutputs_data[i1];
          }
          i1 = defuzzifiedOutputs->size[0];
          defuzzifiedOutputs->size[0] = fis->numOutputs;
          emxEnsureCapacity_real_T(defuzzifiedOutputs, i1);
          defuzzifiedOutputs_data = defuzzifiedOutputs->data;
          u = (unsigned int)fis->numOutputs;
          if ((unsigned int)fis->numOutputs > 2147483647UL) {
            u = 2147483647UL;
          }
          i1 = (int)u;
          for (loop_ub = 0; loop_ub < i1; loop_ub++) {
            if (numInputDataSets == 0.0) {
              defuzzifiedOutputs_data[loop_ub] =
                  (fis->outputRange->data[loop_ub] +
                   fis->outputRange
                       ->data[loop_ub + fis->outputRange->size[0]]) /
                  2.0;
            } else {
              defuzzifiedOutputs_data[loop_ub] = arr_data[loop_ub];
            }
          }
          loop_ub = defuzzifiedOutputs->size[0];
          for (i1 = 0; i1 < loop_ub; i1++) {
            y_data[b_i + y->size[0] * i1] = defuzzifiedOutputs_data[i1];
          }
        }
      }
    } else if (h_isequal(fis->defuzzMethod, uv5)) {
      b_runFIS(inputs, fis, y, irr, orr, arr, rfs, unImpSugRuleOut);
    } else if (i_isequal(fis->defuzzMethod)) {
      c_runFIS(inputs, fis, y, irr, orr, arr, rfs, unImpSugRuleOut);
    } else {
      boolean_T b_bool;
      i = y->size[0] * y->size[1];
      y->size[0] = inputs->size[0];
      y->size[1] = fis->numOutputs;
      emxEnsureCapacity_real_T(y, i);
      i = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      b_y->size[1] = fis->type->size[1];
      emxEnsureCapacity_char_T(b_y, i);
      b_y_data = b_y->data;
      loop_ub = fis->type->size[1];
      for (i = 0; i < loop_ub; i++) {
        b_y_data[i] = (signed char)fis->type->data[i];
      }
      b_bool = false;
      if (b_y->size[1] == 7) {
        loop_ub = 0;
        int exitg1;
        do {
          exitg1 = 0;
          if (loop_ub < 7) {
            if (b_y_data[loop_ub] != cv[loop_ub]) {
              exitg1 = 1;
            } else {
              loop_ub++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (b_bool) {
        emxInit_real_T(&b_fis, 2);
        createMamdaniOutputMFCache(fis->outputMF, fis->numOutputs,
                                   fis->numOutputMFs, fis->numCumOutputMFs,
                                   fis->outputSamplePoints, b_fis);
        emxFree_real_T(&b_fis);
      }
      exit(0);
    }
    emxFree_real_T(&rfs);
  }
  emxFree_real_T(&r1);
  emxFree_real_T(&defuzzifiedOutputs);
  emxFree_real_T(&r);
  emxFree_real_T(&outputMFCache);
  emxFree_real_T(&inputMFCache);
  emxFree_cell_wrap_0(&inVarMF);
  emxFree_char_T(&b_y);
  emxFree_real_T(&unImpSugRuleOut);
  emxFree_real_T(&arr);
  emxFree_real_T(&orr);
  emxFree_real_T(&irr);
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
  static const unsigned char uv[8] = {99U,  101U, 110U, 116U,
                                      114U, 111U, 105U, 100U};
  static const unsigned char uv1[8] = {98U, 105U, 115U, 101U,
                                       99U, 116U, 111U, 114U};
  static const char cv[7] = {'m', 'a', 'm', 'd', 'a', 'n', 'i'};
  static const unsigned char uv5[6] = {119U, 116U, 97U, 118U, 101U, 114U};
  static const unsigned char uv2[3] = {109U, 111U, 109U};
  static const unsigned char uv3[3] = {115U, 111U, 109U};
  static const unsigned char uv4[3] = {108U, 111U, 109U};
  emxArray_cell_wrap_0 *r1;
  emxArray_char_T *b_y;
  emxArray_real_T c_arr;
  emxArray_real_T *arr;
  emxArray_real_T *b_arr;
  emxArray_real_T *b_fis;
  emxArray_real_T *defuzzifiedOutputs;
  emxArray_real_T *irr;
  emxArray_real_T *orr;
  emxArray_real_T *outputMFCache;
  emxArray_real_T *r;
  emxArray_real_T *rfs;
  emxArray_real_T *unImpSugRuleOut;
  emxArray_real_T *x;
  const double *inputs_data;
  double *arr_data;
  double *defuzzifiedOutputs_data;
  double *x_data;
  double *y_data;
  int d_arr[2];
  int e_arr[2];
  int f_arr[2];
  int i;
  int loop_ub;
  char *b_y_data;
  inputs_data = inputs->data;
  emxInit_real_T(&arr, 2);
  emxInit_real_T(&irr, 2);
  emxInit_real_T(&orr, 2);
  emxInit_real_T(&b_arr, 2);
  emxInit_real_T(&rfs, 1);
  emxInit_real_T(&unImpSugRuleOut, 2);
  emxInit_char_T(&b_y, 2);
  emxInit_real_T(&x, 2);
  emxInit_real_T(&outputMFCache, 2);
  emxInit_real_T(&r, 1);
  emxInit_cell_wrap_0(&r1);
  if (isequal(fis->defuzzMethod, uv)) {
    double sw;
    boolean_T b_bool;
    initVariables(fis->type, fis->outputMF, fis->numInputs, fis->numOutputs,
                  fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                  fis->outputSamplePoints, fis->orrSize, fis->aggSize, y, irr,
                  orr, b_arr, rfs, unImpSugRuleOut, outputMFCache);
    y_data = y->data;
    i = arr->size[0] * arr->size[1];
    arr->size[0] = 1;
    arr->size[1] = (int)sum(fis->numInputMFs);
    emxEnsureCapacity_real_T(arr, i);
    i = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = inputs->size[1];
    emxEnsureCapacity_real_T(x, i);
    x_data = x->data;
    loop_ub = inputs->size[1];
    for (i = 0; i < loop_ub; i++) {
      x_data[i] = inputs_data[i];
    }
    extractVarMF(fis->inputMF, r1);
    fuzzifyInputs(x, fis->antecedent, fis->connection, fis->numInputs,
                  fis->numRules, fis->numInputMFs, fis->numCumInputMFs, r1, arr,
                  irr);
    i = r->size[0];
    r->size[0] = fis->numInputs;
    emxEnsureCapacity_real_T(r, i);
    x_data = r->data;
    loop_ub = fis->numInputs;
    for (i = 0; i < loop_ub; i++) {
      x_data[i] = 0.0;
    }
    sw = applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                        fis->weight, fis->numInputs, fis->numRules, rfs, r);
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = fis->type->size[1];
    emxEnsureCapacity_char_T(b_y, i);
    b_y_data = b_y->data;
    loop_ub = fis->type->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_y_data[i] = (signed char)fis->type->data[i];
    }
    b_bool = false;
    if (b_y->size[1] == 7) {
      loop_ub = 0;
      int exitg1;
      do {
        exitg1 = 0;
        if (loop_ub < 7) {
          if (b_y_data[loop_ub] != cv[loop_ub]) {
            exitg1 = 1;
          } else {
            loop_ub++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (b_bool) {
      applyMamdaniImplicationMethod(
          rfs, fis->impMethod, fis->consequent, fis->numOutputs, fis->numRules,
          fis->numCumOutputMFs, fis->orrSize, outputMFCache, orr);
      applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                                    fis->numRules, fis->aggSize, b_arr);
      c_applyMamdaniDefuzzificationMe(fis->outputSamplePoints, sw, b_arr,
                                      fis->outputRange, fis->numOutputs, r);
      x_data = r->data;
      loop_ub = r->size[0];
      for (i = 0; i < loop_ub; i++) {
        y_data[i] = x_data[i];
      }
    } else {
      applySugenoImplicationMethod(x, rfs, fis->outputMF, fis->consequent,
                                   fis->numOutputs, fis->numRules,
                                   fis->numOutputMFs, fis->numCumOutputMFs,
                                   fis->orrSize, orr, irr);
      applySugenoAggregationMethod(orr, arr);
      c_arr = *arr;
      d_arr[0] = (*(int(*)[2])b_arr->size)[0];
      d_arr[1] = (*(int(*)[2])b_arr->size)[1];
      c_arr.size = &d_arr[0];
      c_arr.numDimensions = 2;
      c_applySugenoDefuzzificationMet(sw, &c_arr, fis->outputRange,
                                      fis->numOutputs, r);
      x_data = r->data;
      loop_ub = r->size[0];
      for (i = 0; i < loop_ub; i++) {
        y_data[i] = x_data[i];
      }
    }
  } else if (isequal(fis->defuzzMethod, uv1)) {
    double sw;
    boolean_T b_bool;
    initVariables(fis->type, fis->outputMF, fis->numInputs, fis->numOutputs,
                  fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                  fis->outputSamplePoints, fis->orrSize, fis->aggSize, y, irr,
                  orr, b_arr, rfs, unImpSugRuleOut, outputMFCache);
    y_data = y->data;
    i = arr->size[0] * arr->size[1];
    arr->size[0] = 1;
    arr->size[1] = (int)sum(fis->numInputMFs);
    emxEnsureCapacity_real_T(arr, i);
    i = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = inputs->size[1];
    emxEnsureCapacity_real_T(x, i);
    x_data = x->data;
    loop_ub = inputs->size[1];
    for (i = 0; i < loop_ub; i++) {
      x_data[i] = inputs_data[i];
    }
    extractVarMF(fis->inputMF, r1);
    fuzzifyInputs(x, fis->antecedent, fis->connection, fis->numInputs,
                  fis->numRules, fis->numInputMFs, fis->numCumInputMFs, r1, arr,
                  irr);
    i = r->size[0];
    r->size[0] = fis->numInputs;
    emxEnsureCapacity_real_T(r, i);
    x_data = r->data;
    loop_ub = fis->numInputs;
    for (i = 0; i < loop_ub; i++) {
      x_data[i] = 0.0;
    }
    sw = applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                        fis->weight, fis->numInputs, fis->numRules, rfs, r);
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = fis->type->size[1];
    emxEnsureCapacity_char_T(b_y, i);
    b_y_data = b_y->data;
    loop_ub = fis->type->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_y_data[i] = (signed char)fis->type->data[i];
    }
    b_bool = false;
    if (b_y->size[1] == 7) {
      loop_ub = 0;
      int exitg1;
      do {
        exitg1 = 0;
        if (loop_ub < 7) {
          if (b_y_data[loop_ub] != cv[loop_ub]) {
            exitg1 = 1;
          } else {
            loop_ub++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (b_bool) {
      applyMamdaniImplicationMethod(
          rfs, fis->impMethod, fis->consequent, fis->numOutputs, fis->numRules,
          fis->numCumOutputMFs, fis->orrSize, outputMFCache, orr);
      applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                                    fis->numRules, fis->aggSize, b_arr);
      d_applyMamdaniDefuzzificationMe(fis->outputSamplePoints, sw, b_arr,
                                      fis->outputRange, fis->numOutputs, r);
      x_data = r->data;
      loop_ub = r->size[0];
      for (i = 0; i < loop_ub; i++) {
        y_data[i] = x_data[i];
      }
    } else {
      applySugenoImplicationMethod(x, rfs, fis->outputMF, fis->consequent,
                                   fis->numOutputs, fis->numRules,
                                   fis->numOutputMFs, fis->numCumOutputMFs,
                                   fis->orrSize, orr, irr);
      applySugenoAggregationMethod(orr, arr);
      c_arr = *arr;
      e_arr[0] = (*(int(*)[2])b_arr->size)[0];
      e_arr[1] = (*(int(*)[2])b_arr->size)[1];
      c_arr.size = &e_arr[0];
      c_arr.numDimensions = 2;
      d_applySugenoDefuzzificationMet(sw, &c_arr, fis->outputRange,
                                      fis->numOutputs, r);
      x_data = r->data;
      loop_ub = r->size[0];
      for (i = 0; i < loop_ub; i++) {
        y_data[i] = x_data[i];
      }
    }
  } else if (g_isequal(fis->defuzzMethod, uv2)) {
    double sw;
    boolean_T b_bool;
    initVariables(fis->type, fis->outputMF, fis->numInputs, fis->numOutputs,
                  fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                  fis->outputSamplePoints, fis->orrSize, fis->aggSize, y, irr,
                  orr, b_arr, rfs, unImpSugRuleOut, outputMFCache);
    y_data = y->data;
    i = arr->size[0] * arr->size[1];
    arr->size[0] = 1;
    arr->size[1] = (int)sum(fis->numInputMFs);
    emxEnsureCapacity_real_T(arr, i);
    i = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = inputs->size[1];
    emxEnsureCapacity_real_T(x, i);
    x_data = x->data;
    loop_ub = inputs->size[1];
    for (i = 0; i < loop_ub; i++) {
      x_data[i] = inputs_data[i];
    }
    extractVarMF(fis->inputMF, r1);
    fuzzifyInputs(x, fis->antecedent, fis->connection, fis->numInputs,
                  fis->numRules, fis->numInputMFs, fis->numCumInputMFs, r1, arr,
                  irr);
    i = r->size[0];
    r->size[0] = fis->numInputs;
    emxEnsureCapacity_real_T(r, i);
    x_data = r->data;
    loop_ub = fis->numInputs;
    for (i = 0; i < loop_ub; i++) {
      x_data[i] = 0.0;
    }
    sw = applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                        fis->weight, fis->numInputs, fis->numRules, rfs, r);
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = fis->type->size[1];
    emxEnsureCapacity_char_T(b_y, i);
    b_y_data = b_y->data;
    loop_ub = fis->type->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_y_data[i] = (signed char)fis->type->data[i];
    }
    b_bool = false;
    if (b_y->size[1] == 7) {
      loop_ub = 0;
      int exitg1;
      do {
        exitg1 = 0;
        if (loop_ub < 7) {
          if (b_y_data[loop_ub] != cv[loop_ub]) {
            exitg1 = 1;
          } else {
            loop_ub++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (b_bool) {
      applyMamdaniImplicationMethod(
          rfs, fis->impMethod, fis->consequent, fis->numOutputs, fis->numRules,
          fis->numCumOutputMFs, fis->orrSize, outputMFCache, orr);
      applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                                    fis->numRules, fis->aggSize, b_arr);
      e_applyMamdaniDefuzzificationMe(fis->outputSamplePoints, sw, b_arr,
                                      fis->outputRange, fis->numOutputs, r);
      x_data = r->data;
      loop_ub = r->size[0];
      for (i = 0; i < loop_ub; i++) {
        y_data[i] = x_data[i];
      }
    } else {
      applySugenoImplicationMethod(x, rfs, fis->outputMF, fis->consequent,
                                   fis->numOutputs, fis->numRules,
                                   fis->numOutputMFs, fis->numCumOutputMFs,
                                   fis->orrSize, orr, irr);
      applySugenoAggregationMethod(orr, arr);
      c_arr = *arr;
      f_arr[0] = (*(int(*)[2])b_arr->size)[0];
      f_arr[1] = (*(int(*)[2])b_arr->size)[1];
      c_arr.size = &f_arr[0];
      c_arr.numDimensions = 2;
      e_applySugenoDefuzzificationMet(sw, &c_arr, fis->outputRange,
                                      fis->numOutputs, r);
      x_data = r->data;
      loop_ub = r->size[0];
      for (i = 0; i < loop_ub; i++) {
        y_data[i] = x_data[i];
      }
    }
  } else {
    emxInit_real_T(&defuzzifiedOutputs, 1);
    if (g_isequal(fis->defuzzMethod, uv3)) {
      double sw;
      boolean_T b_bool;
      initVariables(fis->type, fis->outputMF, fis->numInputs, fis->numOutputs,
                    fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                    fis->outputSamplePoints, fis->orrSize, fis->aggSize, y, irr,
                    orr, b_arr, rfs, unImpSugRuleOut, outputMFCache);
      y_data = y->data;
      i = arr->size[0] * arr->size[1];
      arr->size[0] = 1;
      arr->size[1] = (int)sum(fis->numInputMFs);
      emxEnsureCapacity_real_T(arr, i);
      i = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = inputs->size[1];
      emxEnsureCapacity_real_T(x, i);
      x_data = x->data;
      loop_ub = inputs->size[1];
      for (i = 0; i < loop_ub; i++) {
        x_data[i] = inputs_data[i];
      }
      extractVarMF(fis->inputMF, r1);
      fuzzifyInputs(x, fis->antecedent, fis->connection, fis->numInputs,
                    fis->numRules, fis->numInputMFs, fis->numCumInputMFs, r1,
                    arr, irr);
      i = r->size[0];
      r->size[0] = fis->numInputs;
      emxEnsureCapacity_real_T(r, i);
      x_data = r->data;
      loop_ub = fis->numInputs;
      for (i = 0; i < loop_ub; i++) {
        x_data[i] = 0.0;
      }
      sw = applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                          fis->weight, fis->numInputs, fis->numRules, rfs, r);
      i = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      b_y->size[1] = fis->type->size[1];
      emxEnsureCapacity_char_T(b_y, i);
      b_y_data = b_y->data;
      loop_ub = fis->type->size[1];
      for (i = 0; i < loop_ub; i++) {
        b_y_data[i] = (signed char)fis->type->data[i];
      }
      b_bool = false;
      if (b_y->size[1] == 7) {
        loop_ub = 0;
        int exitg1;
        do {
          exitg1 = 0;
          if (loop_ub < 7) {
            if (b_y_data[loop_ub] != cv[loop_ub]) {
              exitg1 = 1;
            } else {
              loop_ub++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (b_bool) {
        applyMamdaniImplicationMethod(rfs, fis->impMethod, fis->consequent,
                                      fis->numOutputs, fis->numRules,
                                      fis->numCumOutputMFs, fis->orrSize,
                                      outputMFCache, orr);
        applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                                      fis->numRules, fis->aggSize, b_arr);
        f_applyMamdaniDefuzzificationMe(fis->outputSamplePoints, sw, b_arr,
                                        fis->outputRange, fis->numOutputs, r);
        x_data = r->data;
        loop_ub = r->size[0];
        for (i = 0; i < loop_ub; i++) {
          y_data[i] = x_data[i];
        }
      } else {
        int arr_idx_1;
        unsigned int u;
        applySugenoImplicationMethod(x, rfs, fis->outputMF, fis->consequent,
                                     fis->numOutputs, fis->numRules,
                                     fis->numOutputMFs, fis->numCumOutputMFs,
                                     fis->orrSize, orr, unImpSugRuleOut);
        applySugenoAggregationMethod(orr, arr);
        x_data = arr->data;
        loop_ub = b_arr->size[0];
        arr_idx_1 = b_arr->size[1];
        i = b_arr->size[0] * b_arr->size[1];
        b_arr->size[0] = loop_ub;
        b_arr->size[1] = arr_idx_1;
        emxEnsureCapacity_real_T(b_arr, i);
        arr_data = b_arr->data;
        loop_ub *= arr_idx_1;
        for (i = 0; i < loop_ub; i++) {
          arr_data[i] = x_data[i];
        }
        i = defuzzifiedOutputs->size[0];
        defuzzifiedOutputs->size[0] = fis->numOutputs;
        emxEnsureCapacity_real_T(defuzzifiedOutputs, i);
        defuzzifiedOutputs_data = defuzzifiedOutputs->data;
        u = (unsigned int)fis->numOutputs;
        if ((unsigned int)fis->numOutputs > 2147483647UL) {
          u = 2147483647UL;
        }
        i = (int)u;
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          if (sw == 0.0) {
            defuzzifiedOutputs_data[loop_ub] =
                (fis->outputRange->data[loop_ub] +
                 fis->outputRange->data[loop_ub + fis->outputRange->size[0]]) /
                2.0;
          } else {
            defuzzifiedOutputs_data[loop_ub] = arr_data[loop_ub];
          }
        }
        loop_ub = defuzzifiedOutputs->size[0];
        for (i = 0; i < loop_ub; i++) {
          y_data[i] = defuzzifiedOutputs_data[i];
        }
      }
    } else if (g_isequal(fis->defuzzMethod, uv4)) {
      double sw;
      boolean_T b_bool;
      initVariables(fis->type, fis->outputMF, fis->numInputs, fis->numOutputs,
                    fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                    fis->outputSamplePoints, fis->orrSize, fis->aggSize, y, irr,
                    orr, b_arr, rfs, unImpSugRuleOut, outputMFCache);
      y_data = y->data;
      i = arr->size[0] * arr->size[1];
      arr->size[0] = 1;
      arr->size[1] = (int)sum(fis->numInputMFs);
      emxEnsureCapacity_real_T(arr, i);
      i = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = inputs->size[1];
      emxEnsureCapacity_real_T(x, i);
      x_data = x->data;
      loop_ub = inputs->size[1];
      for (i = 0; i < loop_ub; i++) {
        x_data[i] = inputs_data[i];
      }
      extractVarMF(fis->inputMF, r1);
      fuzzifyInputs(x, fis->antecedent, fis->connection, fis->numInputs,
                    fis->numRules, fis->numInputMFs, fis->numCumInputMFs, r1,
                    arr, irr);
      i = r->size[0];
      r->size[0] = fis->numInputs;
      emxEnsureCapacity_real_T(r, i);
      x_data = r->data;
      loop_ub = fis->numInputs;
      for (i = 0; i < loop_ub; i++) {
        x_data[i] = 0.0;
      }
      sw = applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                          fis->weight, fis->numInputs, fis->numRules, rfs, r);
      i = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      b_y->size[1] = fis->type->size[1];
      emxEnsureCapacity_char_T(b_y, i);
      b_y_data = b_y->data;
      loop_ub = fis->type->size[1];
      for (i = 0; i < loop_ub; i++) {
        b_y_data[i] = (signed char)fis->type->data[i];
      }
      b_bool = false;
      if (b_y->size[1] == 7) {
        loop_ub = 0;
        int exitg1;
        do {
          exitg1 = 0;
          if (loop_ub < 7) {
            if (b_y_data[loop_ub] != cv[loop_ub]) {
              exitg1 = 1;
            } else {
              loop_ub++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (b_bool) {
        applyMamdaniImplicationMethod(rfs, fis->impMethod, fis->consequent,
                                      fis->numOutputs, fis->numRules,
                                      fis->numCumOutputMFs, fis->orrSize,
                                      outputMFCache, orr);
        applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                                      fis->numRules, fis->aggSize, b_arr);
        g_applyMamdaniDefuzzificationMe(fis->outputSamplePoints, sw, b_arr,
                                        fis->outputRange, fis->numOutputs, r);
        x_data = r->data;
        loop_ub = r->size[0];
        for (i = 0; i < loop_ub; i++) {
          y_data[i] = x_data[i];
        }
      } else {
        int arr_idx_1;
        unsigned int u;
        applySugenoImplicationMethod(x, rfs, fis->outputMF, fis->consequent,
                                     fis->numOutputs, fis->numRules,
                                     fis->numOutputMFs, fis->numCumOutputMFs,
                                     fis->orrSize, orr, unImpSugRuleOut);
        applySugenoAggregationMethod(orr, arr);
        x_data = arr->data;
        loop_ub = b_arr->size[0];
        arr_idx_1 = b_arr->size[1];
        i = b_arr->size[0] * b_arr->size[1];
        b_arr->size[0] = loop_ub;
        b_arr->size[1] = arr_idx_1;
        emxEnsureCapacity_real_T(b_arr, i);
        arr_data = b_arr->data;
        loop_ub *= arr_idx_1;
        for (i = 0; i < loop_ub; i++) {
          arr_data[i] = x_data[i];
        }
        i = defuzzifiedOutputs->size[0];
        defuzzifiedOutputs->size[0] = fis->numOutputs;
        emxEnsureCapacity_real_T(defuzzifiedOutputs, i);
        defuzzifiedOutputs_data = defuzzifiedOutputs->data;
        u = (unsigned int)fis->numOutputs;
        if ((unsigned int)fis->numOutputs > 2147483647UL) {
          u = 2147483647UL;
        }
        i = (int)u;
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          if (sw == 0.0) {
            defuzzifiedOutputs_data[loop_ub] =
                (fis->outputRange->data[loop_ub] +
                 fis->outputRange->data[loop_ub + fis->outputRange->size[0]]) /
                2.0;
          } else {
            defuzzifiedOutputs_data[loop_ub] = arr_data[loop_ub];
          }
        }
        loop_ub = defuzzifiedOutputs->size[0];
        for (i = 0; i < loop_ub; i++) {
          y_data[i] = defuzzifiedOutputs_data[i];
        }
      }
    } else if (h_isequal(fis->defuzzMethod, uv5)) {
      double sw;
      boolean_T b_bool;
      initVariables(fis->type, fis->outputMF, fis->numInputs, fis->numOutputs,
                    fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                    fis->outputSamplePoints, fis->orrSize, fis->aggSize, y, irr,
                    orr, b_arr, rfs, unImpSugRuleOut, outputMFCache);
      y_data = y->data;
      i = arr->size[0] * arr->size[1];
      arr->size[0] = 1;
      arr->size[1] = (int)sum(fis->numInputMFs);
      emxEnsureCapacity_real_T(arr, i);
      i = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = inputs->size[1];
      emxEnsureCapacity_real_T(x, i);
      x_data = x->data;
      loop_ub = inputs->size[1];
      for (i = 0; i < loop_ub; i++) {
        x_data[i] = inputs_data[i];
      }
      extractVarMF(fis->inputMF, r1);
      fuzzifyInputs(x, fis->antecedent, fis->connection, fis->numInputs,
                    fis->numRules, fis->numInputMFs, fis->numCumInputMFs, r1,
                    arr, irr);
      i = r->size[0];
      r->size[0] = fis->numInputs;
      emxEnsureCapacity_real_T(r, i);
      x_data = r->data;
      loop_ub = fis->numInputs;
      for (i = 0; i < loop_ub; i++) {
        x_data[i] = 0.0;
      }
      sw = applyOperators(irr, fis->andMethod, fis->orMethod, fis->connection,
                          fis->weight, fis->numInputs, fis->numRules, rfs, r);
      i = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      b_y->size[1] = fis->type->size[1];
      emxEnsureCapacity_char_T(b_y, i);
      b_y_data = b_y->data;
      loop_ub = fis->type->size[1];
      for (i = 0; i < loop_ub; i++) {
        b_y_data[i] = (signed char)fis->type->data[i];
      }
      b_bool = false;
      if (b_y->size[1] == 7) {
        loop_ub = 0;
        int exitg1;
        do {
          exitg1 = 0;
          if (loop_ub < 7) {
            if (b_y_data[loop_ub] != cv[loop_ub]) {
              exitg1 = 1;
            } else {
              loop_ub++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (b_bool) {
        applyMamdaniImplicationMethod(rfs, fis->impMethod, fis->consequent,
                                      fis->numOutputs, fis->numRules,
                                      fis->numCumOutputMFs, fis->orrSize,
                                      outputMFCache, orr);
        applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                                      fis->numRules, fis->aggSize, arr);
        h_applyMamdaniDefuzzificationMe(fis->outputSamplePoints, sw, arr,
                                        fis->outputRange, fis->numOutputs, r);
        x_data = r->data;
        loop_ub = r->size[0];
        for (i = 0; i < loop_ub; i++) {
          y_data[i] = x_data[i];
        }
      } else {
        unsigned int u;
        applySugenoImplicationMethod(x, rfs, fis->outputMF, fis->consequent,
                                     fis->numOutputs, fis->numRules,
                                     fis->numOutputMFs, fis->numCumOutputMFs,
                                     fis->orrSize, orr, unImpSugRuleOut);
        applySugenoAggregationMethod(orr, arr);
        i = arr->size[0] * arr->size[1];
        arr->size[0] = b_arr->size[0];
        arr->size[1] = b_arr->size[1];
        emxEnsureCapacity_real_T(arr, i);
        x_data = arr->data;
        i = defuzzifiedOutputs->size[0];
        defuzzifiedOutputs->size[0] = fis->numOutputs;
        emxEnsureCapacity_real_T(defuzzifiedOutputs, i);
        defuzzifiedOutputs_data = defuzzifiedOutputs->data;
        u = (unsigned int)fis->numOutputs;
        if ((unsigned int)fis->numOutputs > 2147483647UL) {
          u = 2147483647UL;
        }
        i = (int)u;
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          if (sw == 0.0) {
            defuzzifiedOutputs_data[loop_ub] =
                (fis->outputRange->data[loop_ub] +
                 fis->outputRange->data[loop_ub + fis->outputRange->size[0]]) /
                2.0;
          } else {
            defuzzifiedOutputs_data[loop_ub] = x_data[loop_ub] * (1.0 / sw);
          }
        }
        loop_ub = defuzzifiedOutputs->size[0];
        for (i = 0; i < loop_ub; i++) {
          y_data[i] = defuzzifiedOutputs_data[i];
        }
      }
    } else if (i_isequal(fis->defuzzMethod)) {
      runFIS(inputs, fis, y, irr, orr, b_arr, rfs, unImpSugRuleOut);
    } else {
      boolean_T b_bool;
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = fis->numOutputs;
      emxEnsureCapacity_real_T(y, i);
      i = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      b_y->size[1] = fis->type->size[1];
      emxEnsureCapacity_char_T(b_y, i);
      b_y_data = b_y->data;
      loop_ub = fis->type->size[1];
      for (i = 0; i < loop_ub; i++) {
        b_y_data[i] = (signed char)fis->type->data[i];
      }
      b_bool = false;
      if (b_y->size[1] == 7) {
        loop_ub = 0;
        int exitg1;
        do {
          exitg1 = 0;
          if (loop_ub < 7) {
            if (b_y_data[loop_ub] != cv[loop_ub]) {
              exitg1 = 1;
            } else {
              loop_ub++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (b_bool) {
        emxInit_real_T(&b_fis, 2);
        createMamdaniOutputMFCache(fis->outputMF, fis->numOutputs,
                                   fis->numOutputMFs, fis->numCumOutputMFs,
                                   fis->outputSamplePoints, b_fis);
        emxFree_real_T(&b_fis);
      }
      exit(0);
    }
    emxFree_real_T(&defuzzifiedOutputs);
  }
  emxFree_cell_wrap_0(&r1);
  emxFree_real_T(&r);
  emxFree_real_T(&outputMFCache);
  emxFree_real_T(&x);
  emxFree_char_T(&b_y);
  emxFree_real_T(&unImpSugRuleOut);
  emxFree_real_T(&rfs);
  emxFree_real_T(&b_arr);
  emxFree_real_T(&orr);
  emxFree_real_T(&irr);
  emxFree_real_T(&arr);
}

/*
 * File trailer for evaluateFIS.c
 *
 * [EOF]
 */
