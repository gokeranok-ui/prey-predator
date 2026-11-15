//
// File: evaluateFIS.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
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
#include "opkene_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
namespace coder
{
  namespace fuzzy
  {
    namespace internal
    {
      namespace codegen
      {
        static void b_runFIS(const ::coder::array<double, 1U> &inputs, const
                             f_struct_T *fis, ::coder::array<double, 2U> &y, ::
                             coder::array<double, 2U> &irr, ::coder::array<
                             double, 2U> &orr, ::coder::array<double, 2U> &arr, ::
                             coder::array<double, 1U> &w, ::coder::array<double,
                             2U> &unImpSugRuleOut);
        static void b_runFIS(const ::coder::array<double, 2U> &inputs, const
                             f_struct_T *fis, ::coder::array<double, 2U> &y, ::
                             coder::array<double, 2U> &irr, ::coder::array<
                             double, 2U> &orr, ::coder::array<double, 2U> &arr, ::
                             coder::array<double, 1U> &w, ::coder::array<double,
                             2U> &unImpSugRuleOut);
        static void c_runFIS(const ::coder::array<double, 1U> &inputs, const
                             f_struct_T *fis, ::coder::array<double, 2U> &y, ::
                             coder::array<double, 2U> &irr, ::coder::array<
                             double, 2U> &orr, ::coder::array<double, 2U> &arr, ::
                             coder::array<double, 1U> &w, ::coder::array<double,
                             2U> &unImpSugRuleOut);
        static void initVariables(const ::coder::array<unsigned char, 2U>
          &fis_type, const ::coder::array<e_struct_T, 2U> &fis_outputMF, int
          fis_numOutputs, int fis_numRules, const ::coder::array<int, 2U>
          &fis_numOutputMFs, const ::coder::array<int, 2U> &fis_numCumOutputMFs,
          const ::coder::array<double, 2U> &fis_outputSamplePoints, const int
          fis_orrSize[2], const int fis_aggSize[2], const ::coder::array<double,
          1U> &inputs, ::coder::array<double, 2U> &y, ::coder::array<double, 2U>
          &irr, ::coder::array<double, 2U> &orr, ::coder::array<double, 2U> &arr,
          ::coder::array<double, 1U> &rfs, ::coder::array<double, 2U>
          &unImpSugRuleOut, ::coder::array<double, 2U> &outputMFCache, double
          *numInputDataSets);
        static void initVariables(const ::coder::array<unsigned char, 2U>
          &fis_type, const ::coder::array<e_struct_T, 2U> &fis_outputMF, int
          fis_numInputs, int fis_numOutputs, int fis_numRules, const ::coder::
          array<int, 2U> &fis_numOutputMFs, const ::coder::array<int, 2U>
          &fis_numCumOutputMFs, const ::coder::array<double, 2U>
          &fis_outputSamplePoints, const int fis_orrSize[2], const int
          fis_aggSize[2], ::coder::array<double, 2U> &y, ::coder::array<double,
          2U> &irr, ::coder::array<double, 2U> &orr, ::coder::array<double, 2U>
          &arr, ::coder::array<double, 1U> &rfs, ::coder::array<double, 2U>
          &unImpSugRuleOut, ::coder::array<double, 2U> &outputMFCache);
        static void runFIS(const ::coder::array<double, 1U> &inputs, const
                           f_struct_T *fis, ::coder::array<double, 2U> &y, ::
                           coder::array<double, 2U> &irr, ::coder::array<double,
                           2U> &orr, ::coder::array<double, 2U> &arr, ::coder::
                           array<double, 1U> &w, ::coder::array<double, 2U>
                           &unImpSugRuleOut);
        static void runFIS(const ::coder::array<double, 2U> &inputs, const
                           f_struct_T *fis, ::coder::array<double, 2U> &y, ::
                           coder::array<double, 2U> &irr, ::coder::array<double,
                           2U> &orr, ::coder::array<double, 2U> &arr, ::coder::
                           array<double, 1U> &w, ::coder::array<double, 2U>
                           &unImpSugRuleOut);
      }
    }
  }
}

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &inputs
//                const f_struct_T *fis
//                ::coder::array<double, 2U> &y
//                ::coder::array<double, 2U> &irr
//                ::coder::array<double, 2U> &orr
//                ::coder::array<double, 2U> &arr
//                ::coder::array<double, 1U> &w
//                ::coder::array<double, 2U> &unImpSugRuleOut
// Return Type  : void
//
namespace coder
{
  namespace fuzzy
  {
    namespace internal
    {
      namespace codegen
      {
        static void b_runFIS(const ::coder::array<double, 1U> &inputs, const
                             f_struct_T *fis, ::coder::array<double, 2U> &y, ::
                             coder::array<double, 2U> &irr, ::coder::array<
                             double, 2U> &orr, ::coder::array<double, 2U> &arr, ::
                             coder::array<double, 1U> &w, ::coder::array<double,
                             2U> &unImpSugRuleOut)
        {
          static const char cv[7] = { 'm', 'a', 'm', 'd', 'a', 'n', 'i' };

          array<cell_wrap_0, 2U> inVarMF;
          array<double, 2U> inputMFCache;
          array<double, 2U> outputMFCache;
          array<double, 2U> r1;
          array<double, 1U> defuzzifiedOutputs;
          array<double, 1U> r;
          array<char, 2U> c_y;
          double irrOfOneRule_data[1];
          double b_y;
          double numInputDataSets;
          int i;
          int k;
          int vlen;
          initVariables(fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
                        fis->numOutputMFs, fis->numCumOutputMFs,
                        fis->outputSamplePoints, fis->orrSize, fis->aggSize,
                        inputs, y, irr, orr, arr, w, unImpSugRuleOut,
                        outputMFCache, &numInputDataSets);
          extractVarMF(fis->inputMF, inVarMF);
          vlen = fis->numInputMFs.size(1);
          if (fis->numInputMFs.size(1) == 0) {
            b_y = 0.0;
          } else {
            b_y = fis->numInputMFs[0];
            for (k = 2; k <= vlen; k++) {
              b_y += static_cast<double>(fis->numInputMFs[k - 1]);
            }
          }

          inputMFCache.set_size(1, (static_cast<int>(b_y)));
          irrOfOneRule_data[0] = 0.0;
          i = static_cast<int>(numInputDataSets);
          for (int b_i = 0; b_i < i; b_i++) {
            boolean_T b_bool;
            fuzzifyInputs(inputs[b_i], fis->antecedent, fis->connection,
                          fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                          inVarMF, inputMFCache, irr);
            r.set_size(1);
            r[0] = irrOfOneRule_data[0];
            numInputDataSets = applyOperators(irr, fis->andMethod, fis->orMethod,
              fis->connection, fis->weight, fis->numInputs, fis->numRules, w, r);
            vlen = r.size(0);
            for (k = 0; k < vlen; k++) {
              irrOfOneRule_data[k] = r[k];
            }

            vlen = fis->type.size(1);
            c_y.set_size(1, fis->type.size(1));
            for (k = 0; k < vlen; k++) {
              c_y[k] = static_cast<signed char>(fis->type[k]);
            }

            b_bool = false;
            if (c_y.size(1) == 7) {
              vlen = 0;
              int exitg1;
              do {
                exitg1 = 0;
                if (vlen < 7) {
                  if (c_y[vlen] != cv[vlen]) {
                    exitg1 = 1;
                  } else {
                    vlen++;
                  }
                } else {
                  b_bool = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }

            if (b_bool) {
              applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
                fis->numOutputs, fis->numRules, fis->numCumOutputMFs,
                fis->orrSize, outputMFCache, orr);
              applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                fis->numRules, fis->aggSize, arr);
              f_applyMamdaniDefuzzificationMethod(fis->outputSamplePoints,
                numInputDataSets, arr, fis->outputRange, fis->numOutputs, r);
              vlen = r.size(0);
              for (k = 0; k < vlen; k++) {
                y[b_i + y.size(0) * k] = r[k];
              }
            } else {
              applySugenoImplicationMethod(inputs[b_i], w, fis->outputMF,
                fis->consequent, fis->numOutputs, fis->numRules,
                fis->numOutputMFs, fis->numCumOutputMFs, fis->orrSize, orr,
                unImpSugRuleOut);
              applySugenoAggregationMethod(orr, r1);
              vlen = arr.size(0);
              k = arr.size(1);
              arr.set_size(vlen, k);
              vlen *= k;
              for (k = 0; k < vlen; k++) {
                arr[k] = r1[k];
              }

              vlen = fis->numOutputs;
              defuzzifiedOutputs.set_size(fis->numOutputs);
              for (k = 0; k < vlen; k++) {
                if (numInputDataSets == 0.0) {
                  defuzzifiedOutputs[k] = (fis->outputRange[k] +
                    fis->outputRange[k + fis->outputRange.size(0)]) / 2.0;
                } else {
                  defuzzifiedOutputs[k] = arr[k] * (1.0 / numInputDataSets);
                }
              }

              vlen = defuzzifiedOutputs.size(0);
              for (k = 0; k < vlen; k++) {
                y[b_i + y.size(0) * k] = defuzzifiedOutputs[k];
              }
            }
          }
        }

        //
        // Arguments    : const ::coder::array<double, 2U> &inputs
        //                const f_struct_T *fis
        //                ::coder::array<double, 2U> &y
        //                ::coder::array<double, 2U> &irr
        //                ::coder::array<double, 2U> &orr
        //                ::coder::array<double, 2U> &arr
        //                ::coder::array<double, 1U> &w
        //                ::coder::array<double, 2U> &unImpSugRuleOut
        // Return Type  : void
        //
        static void b_runFIS(const ::coder::array<double, 2U> &inputs, const
                             f_struct_T *fis, ::coder::array<double, 2U> &y, ::
                             coder::array<double, 2U> &irr, ::coder::array<
                             double, 2U> &orr, ::coder::array<double, 2U> &arr, ::
                             coder::array<double, 1U> &w, ::coder::array<double,
                             2U> &unImpSugRuleOut)
        {
          static const char cv[7] = { 'm', 'a', 'm', 'd', 'a', 'n', 'i' };

          array<cell_wrap_0, 2U> r;
          array<double, 2U> b_arr;
          array<double, 2U> b_inputs;
          array<double, 2U> inputMFCache;
          array<double, 2U> outputMFCache;
          array<double, 1U> defuzzifiedOutputs;
          array<double, 1U> r1;
          array<char, 2U> c_y;
          double b_y;
          int k;
          int vlen;
          boolean_T b_bool;
          initVariables(fis->type, fis->outputMF, fis->numInputs,
                        fis->numOutputs, fis->numRules, fis->numOutputMFs,
                        fis->numCumOutputMFs, fis->outputSamplePoints,
                        fis->orrSize, fis->aggSize, y, irr, orr, b_arr, w,
                        unImpSugRuleOut, outputMFCache);
          vlen = fis->numInputMFs.size(1);
          if (fis->numInputMFs.size(1) == 0) {
            b_y = 0.0;
          } else {
            b_y = fis->numInputMFs[0];
            for (k = 2; k <= vlen; k++) {
              b_y += static_cast<double>(fis->numInputMFs[k - 1]);
            }
          }

          inputMFCache.set_size(1, (static_cast<int>(b_y)));
          vlen = inputs.size(1);
          b_inputs.set_size(1, inputs.size(1));
          for (k = 0; k < vlen; k++) {
            b_inputs[k] = inputs[k];
          }

          extractVarMF(fis->inputMF, r);
          fuzzifyInputs(b_inputs, fis->antecedent, fis->connection,
                        fis->numInputs, fis->numRules, fis->numInputMFs,
                        fis->numCumInputMFs, r, inputMFCache, irr);
          r1.set_size(fis->numInputs);
          vlen = fis->numInputs;
          for (k = 0; k < vlen; k++) {
            r1[k] = 0.0;
          }

          b_y = applyOperators(irr, fis->andMethod, fis->orMethod,
                               fis->connection, fis->weight, fis->numInputs,
                               fis->numRules, w, r1);
          c_y.set_size(1, fis->type.size(1));
          vlen = fis->type.size(1);
          for (k = 0; k < vlen; k++) {
            c_y[k] = static_cast<signed char>(fis->type[k]);
          }

          b_bool = false;
          if (c_y.size(1) == 7) {
            vlen = 0;
            int exitg1;
            do {
              exitg1 = 0;
              if (vlen < 7) {
                if (c_y[vlen] != cv[vlen]) {
                  exitg1 = 1;
                } else {
                  vlen++;
                }
              } else {
                b_bool = true;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }

          if (b_bool) {
            applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
              fis->numOutputs, fis->numRules, fis->numCumOutputMFs, fis->orrSize,
              outputMFCache, orr);
            applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
              fis->numRules, fis->aggSize, arr);
            f_applyMamdaniDefuzzificationMethod(fis->outputSamplePoints, b_y,
              arr, fis->outputRange, fis->numOutputs, r1);
            vlen = r1.size(0);
            for (k = 0; k < vlen; k++) {
              y[k] = r1[k];
            }
          } else {
            vlen = inputs.size(1);
            b_inputs.set_size(1, inputs.size(1));
            for (k = 0; k < vlen; k++) {
              b_inputs[k] = inputs[k];
            }

            applySugenoImplicationMethod(b_inputs, w, fis->outputMF,
              fis->consequent, fis->numOutputs, fis->numRules, fis->numOutputMFs,
              fis->numCumOutputMFs, fis->orrSize, orr, unImpSugRuleOut);
            applySugenoAggregationMethod(orr, inputMFCache);
            arr.set_size(b_arr.size(0), b_arr.size(1));
            vlen = b_arr.size(0) * b_arr.size(1);
            for (k = 0; k < vlen; k++) {
              arr[k] = inputMFCache[k];
            }

            vlen = fis->numOutputs;
            defuzzifiedOutputs.set_size(fis->numOutputs);
            for (k = 0; k < vlen; k++) {
              if (b_y == 0.0) {
                defuzzifiedOutputs[k] = (fis->outputRange[k] + fis->
                  outputRange[k + fis->outputRange.size(0)]) / 2.0;
              } else {
                defuzzifiedOutputs[k] = arr[k] * (1.0 / b_y);
              }
            }

            vlen = defuzzifiedOutputs.size(0);
            for (k = 0; k < vlen; k++) {
              y[k] = defuzzifiedOutputs[k];
            }
          }
        }

        //
        // Arguments    : const ::coder::array<double, 1U> &inputs
        //                const f_struct_T *fis
        //                ::coder::array<double, 2U> &y
        //                ::coder::array<double, 2U> &irr
        //                ::coder::array<double, 2U> &orr
        //                ::coder::array<double, 2U> &arr
        //                ::coder::array<double, 1U> &w
        //                ::coder::array<double, 2U> &unImpSugRuleOut
        // Return Type  : void
        //
        static void c_runFIS(const ::coder::array<double, 1U> &inputs, const
                             f_struct_T *fis, ::coder::array<double, 2U> &y, ::
                             coder::array<double, 2U> &irr, ::coder::array<
                             double, 2U> &orr, ::coder::array<double, 2U> &arr, ::
                             coder::array<double, 1U> &w, ::coder::array<double,
                             2U> &unImpSugRuleOut)
        {
          static const char cv[7] = { 'm', 'a', 'm', 'd', 'a', 'n', 'i' };

          const ::coder::array<double, 2U> *fis_outputRange;
          const ::coder::array<double, 2U> *outputSamplePoints;
          array<cell_wrap_0, 2U> inVarMF;
          array<double, 2U> inputMFCache;
          array<double, 2U> outputMFCache;
          array<double, 2U> r1;
          array<double, 1U> defuzzifiedOutputs;
          array<double, 1U> r;
          array<char, 2U> c_y;
          double irrOfOneRule_data[1];
          double b_y;
          double numInputDataSets;
          int i;
          int k;
          int vlen;
          initVariables(fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
                        fis->numOutputMFs, fis->numCumOutputMFs,
                        fis->outputSamplePoints, fis->orrSize, fis->aggSize,
                        inputs, y, irr, orr, arr, w, unImpSugRuleOut,
                        outputMFCache, &numInputDataSets);
          extractVarMF(fis->inputMF, inVarMF);
          vlen = fis->numInputMFs.size(1);
          if (fis->numInputMFs.size(1) == 0) {
            b_y = 0.0;
          } else {
            b_y = fis->numInputMFs[0];
            for (k = 2; k <= vlen; k++) {
              b_y += static_cast<double>(fis->numInputMFs[k - 1]);
            }
          }

          inputMFCache.set_size(1, (static_cast<int>(b_y)));
          irrOfOneRule_data[0] = 0.0;
          i = static_cast<int>(numInputDataSets);
          for (int b_i = 0; b_i < i; b_i++) {
            boolean_T b_bool;
            fuzzifyInputs(inputs[b_i], fis->antecedent, fis->connection,
                          fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                          inVarMF, inputMFCache, irr);
            r.set_size(1);
            r[0] = irrOfOneRule_data[0];
            numInputDataSets = applyOperators(irr, fis->andMethod, fis->orMethod,
              fis->connection, fis->weight, fis->numInputs, fis->numRules, w, r);
            vlen = r.size(0);
            for (k = 0; k < vlen; k++) {
              irrOfOneRule_data[k] = r[k];
            }

            vlen = fis->type.size(1);
            c_y.set_size(1, fis->type.size(1));
            for (k = 0; k < vlen; k++) {
              c_y[k] = static_cast<signed char>(fis->type[k]);
            }

            b_bool = false;
            if (c_y.size(1) == 7) {
              vlen = 0;
              int exitg1;
              do {
                exitg1 = 0;
                if (vlen < 7) {
                  if (c_y[vlen] != cv[vlen]) {
                    exitg1 = 1;
                  } else {
                    vlen++;
                  }
                } else {
                  b_bool = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }

            if (b_bool) {
              applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
                fis->numOutputs, fis->numRules, fis->numCumOutputMFs,
                fis->orrSize, outputMFCache, orr);
              applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                fis->numRules, fis->aggSize, arr);
              outputSamplePoints = &fis->outputSamplePoints;
              fis_outputRange = &fis->outputRange;
              vlen = fis->numOutputs;
              r.set_size(vlen);
              for (k = 0; k < vlen; k++) {
                if (numInputDataSets == 0.0) {
                  r[k] = ((*fis_outputRange)[k] + (*fis_outputRange)[k +
                          fis_outputRange->size(0)]) / 2.0;
                } else {
                  r[k] = (*outputSamplePoints)[k];
                }
              }

              vlen = r.size(0);
              for (k = 0; k < vlen; k++) {
                y[b_i + y.size(0) * k] = r[k];
              }
            } else {
              applySugenoImplicationMethod(inputs[b_i], w, fis->outputMF,
                fis->consequent, fis->numOutputs, fis->numRules,
                fis->numOutputMFs, fis->numCumOutputMFs, fis->orrSize, orr,
                unImpSugRuleOut);
              applySugenoAggregationMethod(orr, r1);
              vlen = arr.size(0);
              k = arr.size(1);
              arr.set_size(vlen, k);
              vlen *= k;
              for (k = 0; k < vlen; k++) {
                arr[k] = r1[k];
              }

              vlen = fis->numOutputs;
              defuzzifiedOutputs.set_size(fis->numOutputs);
              for (k = 0; k < vlen; k++) {
                if (numInputDataSets == 0.0) {
                  defuzzifiedOutputs[k] = (fis->outputRange[k] +
                    fis->outputRange[k + fis->outputRange.size(0)]) / 2.0;
                } else {
                  defuzzifiedOutputs[k] = arr[k];
                }
              }

              vlen = defuzzifiedOutputs.size(0);
              for (k = 0; k < vlen; k++) {
                y[b_i + y.size(0) * k] = defuzzifiedOutputs[k];
              }
            }
          }
        }

        //
        // Arguments    : const ::coder::array<unsigned char, 2U> &fis_type
        //                const ::coder::array<e_struct_T, 2U> &fis_outputMF
        //                int fis_numOutputs
        //                int fis_numRules
        //                const ::coder::array<int, 2U> &fis_numOutputMFs
        //                const ::coder::array<int, 2U> &fis_numCumOutputMFs
        //                const ::coder::array<double, 2U> &fis_outputSamplePoints
        //                const int fis_orrSize[2]
        //                const int fis_aggSize[2]
        //                const ::coder::array<double, 1U> &inputs
        //                ::coder::array<double, 2U> &y
        //                ::coder::array<double, 2U> &irr
        //                ::coder::array<double, 2U> &orr
        //                ::coder::array<double, 2U> &arr
        //                ::coder::array<double, 1U> &rfs
        //                ::coder::array<double, 2U> &unImpSugRuleOut
        //                ::coder::array<double, 2U> &outputMFCache
        //                double *numInputDataSets
        // Return Type  : void
        //
        static void initVariables(const ::coder::array<unsigned char, 2U>
          &fis_type, const ::coder::array<e_struct_T, 2U> &fis_outputMF, int
          fis_numOutputs, int fis_numRules, const ::coder::array<int, 2U>
          &fis_numOutputMFs, const ::coder::array<int, 2U> &fis_numCumOutputMFs,
          const ::coder::array<double, 2U> &fis_outputSamplePoints, const int
          fis_orrSize[2], const int fis_aggSize[2], const ::coder::array<double,
          1U> &inputs, ::coder::array<double, 2U> &y, ::coder::array<double, 2U>
          &irr, ::coder::array<double, 2U> &orr, ::coder::array<double, 2U> &arr,
          ::coder::array<double, 1U> &rfs, ::coder::array<double, 2U>
          &unImpSugRuleOut, ::coder::array<double, 2U> &outputMFCache, double
          *numInputDataSets)
        {
          static const char cv[7] = { 'm', 'a', 'm', 'd', 'a', 'n', 'i' };

          array<double, 2U> r;
          array<char, 2U> b_y;
          int b_numInputDataSets;
          int i;
          int loop_ub;
          boolean_T b_bool;
          b_numInputDataSets = inputs.size(0);
          y.set_size(inputs.size(0), fis_numOutputs);
          irr.set_size(fis_numRules, 1);
          orr.set_size(fis_orrSize[0], fis_orrSize[1]);
          arr.set_size(fis_aggSize[0], fis_aggSize[1]);
          rfs.set_size(fis_numRules);
          b_y.set_size(1, fis_type.size(1));
          loop_ub = fis_type.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_y[i] = static_cast<signed char>(fis_type[i]);
          }

          b_bool = false;
          if (b_y.size(1) == 7) {
            loop_ub = 0;
            int exitg1;
            do {
              exitg1 = 0;
              if (loop_ub < 7) {
                if (b_y[loop_ub] != cv[loop_ub]) {
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
            createMamdaniOutputMFCache(fis_outputMF, fis_numOutputs,
              fis_numOutputMFs, fis_numCumOutputMFs, fis_outputSamplePoints, r);
            outputMFCache.set_size(r.size(0), 51);
            loop_ub = r.size(0) * r.size(1);
            for (i = 0; i < loop_ub; i++) {
              outputMFCache[i] = r[i];
            }

            unImpSugRuleOut.set_size(1, 1);
            unImpSugRuleOut[0] = 0.0;
          } else {
            outputMFCache.set_size(1, 1);
            outputMFCache[0] = 0.0;
            unImpSugRuleOut.set_size(fis_orrSize[0], fis_orrSize[1]);
          }

          *numInputDataSets = b_numInputDataSets;
        }

        //
        // Arguments    : const ::coder::array<unsigned char, 2U> &fis_type
        //                const ::coder::array<e_struct_T, 2U> &fis_outputMF
        //                int fis_numInputs
        //                int fis_numOutputs
        //                int fis_numRules
        //                const ::coder::array<int, 2U> &fis_numOutputMFs
        //                const ::coder::array<int, 2U> &fis_numCumOutputMFs
        //                const ::coder::array<double, 2U> &fis_outputSamplePoints
        //                const int fis_orrSize[2]
        //                const int fis_aggSize[2]
        //                ::coder::array<double, 2U> &y
        //                ::coder::array<double, 2U> &irr
        //                ::coder::array<double, 2U> &orr
        //                ::coder::array<double, 2U> &arr
        //                ::coder::array<double, 1U> &rfs
        //                ::coder::array<double, 2U> &unImpSugRuleOut
        //                ::coder::array<double, 2U> &outputMFCache
        // Return Type  : void
        //
        static void initVariables(const ::coder::array<unsigned char, 2U>
          &fis_type, const ::coder::array<e_struct_T, 2U> &fis_outputMF, int
          fis_numInputs, int fis_numOutputs, int fis_numRules, const ::coder::
          array<int, 2U> &fis_numOutputMFs, const ::coder::array<int, 2U>
          &fis_numCumOutputMFs, const ::coder::array<double, 2U>
          &fis_outputSamplePoints, const int fis_orrSize[2], const int
          fis_aggSize[2], ::coder::array<double, 2U> &y, ::coder::array<double,
          2U> &irr, ::coder::array<double, 2U> &orr, ::coder::array<double, 2U>
          &arr, ::coder::array<double, 1U> &rfs, ::coder::array<double, 2U>
          &unImpSugRuleOut, ::coder::array<double, 2U> &outputMFCache)
        {
          static const char cv[7] = { 'm', 'a', 'm', 'd', 'a', 'n', 'i' };

          array<double, 2U> r;
          array<char, 2U> b_y;
          int i;
          int loop_ub;
          boolean_T b_bool;
          y.set_size(1, fis_numOutputs);
          irr.set_size(fis_numRules, fis_numInputs);
          orr.set_size(fis_orrSize[0], fis_orrSize[1]);
          arr.set_size(fis_aggSize[0], fis_aggSize[1]);
          rfs.set_size(fis_numRules);
          b_y.set_size(1, fis_type.size(1));
          loop_ub = fis_type.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_y[i] = static_cast<signed char>(fis_type[i]);
          }

          b_bool = false;
          if (b_y.size(1) == 7) {
            loop_ub = 0;
            int exitg1;
            do {
              exitg1 = 0;
              if (loop_ub < 7) {
                if (b_y[loop_ub] != cv[loop_ub]) {
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
            createMamdaniOutputMFCache(fis_outputMF, fis_numOutputs,
              fis_numOutputMFs, fis_numCumOutputMFs, fis_outputSamplePoints, r);
            outputMFCache.set_size(r.size(0), 51);
            loop_ub = r.size(0) * r.size(1);
            for (i = 0; i < loop_ub; i++) {
              outputMFCache[i] = r[i];
            }

            unImpSugRuleOut.set_size(1, 1);
            unImpSugRuleOut[0] = 0.0;
          } else {
            outputMFCache.set_size(1, 1);
            outputMFCache[0] = 0.0;
            unImpSugRuleOut.set_size(fis_orrSize[0], fis_orrSize[1]);
          }
        }

        //
        // Arguments    : const ::coder::array<double, 1U> &inputs
        //                const f_struct_T *fis
        //                ::coder::array<double, 2U> &y
        //                ::coder::array<double, 2U> &irr
        //                ::coder::array<double, 2U> &orr
        //                ::coder::array<double, 2U> &arr
        //                ::coder::array<double, 1U> &w
        //                ::coder::array<double, 2U> &unImpSugRuleOut
        // Return Type  : void
        //
        static void runFIS(const ::coder::array<double, 1U> &inputs, const
                           f_struct_T *fis, ::coder::array<double, 2U> &y, ::
                           coder::array<double, 2U> &irr, ::coder::array<double,
                           2U> &orr, ::coder::array<double, 2U> &arr, ::coder::
                           array<double, 1U> &w, ::coder::array<double, 2U>
                           &unImpSugRuleOut)
        {
          static const char cv[7] = { 'm', 'a', 'm', 'd', 'a', 'n', 'i' };

          array<cell_wrap_0, 2U> inVarMF;
          array<double, 2U> inputMFCache;
          array<double, 2U> outputMFCache;
          array<double, 2U> r1;
          array<double, 1U> defuzzifiedOutputs;
          array<double, 1U> r;
          array<char, 2U> c_y;
          double irrOfOneRule_data[1];
          double b_y;
          double numInputDataSets;
          int i;
          int k;
          int vlen;
          initVariables(fis->type, fis->outputMF, fis->numOutputs, fis->numRules,
                        fis->numOutputMFs, fis->numCumOutputMFs,
                        fis->outputSamplePoints, fis->orrSize, fis->aggSize,
                        inputs, y, irr, orr, arr, w, unImpSugRuleOut,
                        outputMFCache, &numInputDataSets);
          extractVarMF(fis->inputMF, inVarMF);
          vlen = fis->numInputMFs.size(1);
          if (fis->numInputMFs.size(1) == 0) {
            b_y = 0.0;
          } else {
            b_y = fis->numInputMFs[0];
            for (k = 2; k <= vlen; k++) {
              b_y += static_cast<double>(fis->numInputMFs[k - 1]);
            }
          }

          inputMFCache.set_size(1, (static_cast<int>(b_y)));
          irrOfOneRule_data[0] = 0.0;
          i = static_cast<int>(numInputDataSets);
          for (int b_i = 0; b_i < i; b_i++) {
            boolean_T b_bool;
            fuzzifyInputs(inputs[b_i], fis->antecedent, fis->connection,
                          fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                          inVarMF, inputMFCache, irr);
            r.set_size(1);
            r[0] = irrOfOneRule_data[0];
            numInputDataSets = applyOperators(irr, fis->andMethod, fis->orMethod,
              fis->connection, fis->weight, fis->numInputs, fis->numRules, w, r);
            vlen = r.size(0);
            for (k = 0; k < vlen; k++) {
              irrOfOneRule_data[k] = r[k];
            }

            vlen = fis->type.size(1);
            c_y.set_size(1, fis->type.size(1));
            for (k = 0; k < vlen; k++) {
              c_y[k] = static_cast<signed char>(fis->type[k]);
            }

            b_bool = false;
            if (c_y.size(1) == 7) {
              vlen = 0;
              int exitg1;
              do {
                exitg1 = 0;
                if (vlen < 7) {
                  if (c_y[vlen] != cv[vlen]) {
                    exitg1 = 1;
                  } else {
                    vlen++;
                  }
                } else {
                  b_bool = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }

            if (b_bool) {
              applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
                fis->numOutputs, fis->numRules, fis->numCumOutputMFs,
                fis->orrSize, outputMFCache, orr);
              applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                fis->numRules, fis->aggSize, arr);
              b_applyMamdaniDefuzzificationMethod(fis->outputSamplePoints,
                numInputDataSets, arr, fis->outputRange, fis->numOutputs, r);
              vlen = r.size(0);
              for (k = 0; k < vlen; k++) {
                y[b_i + y.size(0) * k] = r[k];
              }
            } else {
              applySugenoImplicationMethod(inputs[b_i], w, fis->outputMF,
                fis->consequent, fis->numOutputs, fis->numRules,
                fis->numOutputMFs, fis->numCumOutputMFs, fis->orrSize, orr,
                unImpSugRuleOut);
              applySugenoAggregationMethod(orr, r1);
              vlen = arr.size(0);
              k = arr.size(1);
              arr.set_size(vlen, k);
              vlen *= k;
              for (k = 0; k < vlen; k++) {
                arr[k] = r1[k];
              }

              vlen = fis->numOutputs;
              defuzzifiedOutputs.set_size(fis->numOutputs);
              for (k = 0; k < vlen; k++) {
                if (numInputDataSets == 0.0) {
                  defuzzifiedOutputs[k] = (fis->outputRange[k] +
                    fis->outputRange[k + fis->outputRange.size(0)]) / 2.0;
                } else if (numInputDataSets == 0.0) {
                  defuzzifiedOutputs[k] = (arr[k] + arr[k]) / 2.0;
                } else {
                  defuzzifiedOutputs[k] = arr[k];
                }
              }

              vlen = defuzzifiedOutputs.size(0);
              for (k = 0; k < vlen; k++) {
                y[b_i + y.size(0) * k] = defuzzifiedOutputs[k];
              }
            }
          }
        }

        //
        // Arguments    : const ::coder::array<double, 2U> &inputs
        //                const f_struct_T *fis
        //                ::coder::array<double, 2U> &y
        //                ::coder::array<double, 2U> &irr
        //                ::coder::array<double, 2U> &orr
        //                ::coder::array<double, 2U> &arr
        //                ::coder::array<double, 1U> &w
        //                ::coder::array<double, 2U> &unImpSugRuleOut
        // Return Type  : void
        //
        static void runFIS(const ::coder::array<double, 2U> &inputs, const
                           f_struct_T *fis, ::coder::array<double, 2U> &y, ::
                           coder::array<double, 2U> &irr, ::coder::array<double,
                           2U> &orr, ::coder::array<double, 2U> &arr, ::coder::
                           array<double, 1U> &w, ::coder::array<double, 2U>
                           &unImpSugRuleOut)
        {
          static const char cv[7] = { 'm', 'a', 'm', 'd', 'a', 'n', 'i' };

          array<cell_wrap_0, 2U> r;
          array<double, 2U> b_arr;
          array<double, 2U> b_inputs;
          array<double, 2U> inputMFCache;
          array<double, 2U> outputMFCache;
          array<double, 1U> defuzzifiedOutputs;
          array<double, 1U> r1;
          array<char, 2U> c_y;
          double b_y;
          int k;
          int vlen;
          boolean_T b_bool;
          initVariables(fis->type, fis->outputMF, fis->numInputs,
                        fis->numOutputs, fis->numRules, fis->numOutputMFs,
                        fis->numCumOutputMFs, fis->outputSamplePoints,
                        fis->orrSize, fis->aggSize, y, irr, orr, b_arr, w,
                        unImpSugRuleOut, outputMFCache);
          vlen = fis->numInputMFs.size(1);
          if (fis->numInputMFs.size(1) == 0) {
            b_y = 0.0;
          } else {
            b_y = fis->numInputMFs[0];
            for (k = 2; k <= vlen; k++) {
              b_y += static_cast<double>(fis->numInputMFs[k - 1]);
            }
          }

          inputMFCache.set_size(1, (static_cast<int>(b_y)));
          vlen = inputs.size(1);
          b_inputs.set_size(1, inputs.size(1));
          for (k = 0; k < vlen; k++) {
            b_inputs[k] = inputs[k];
          }

          extractVarMF(fis->inputMF, r);
          fuzzifyInputs(b_inputs, fis->antecedent, fis->connection,
                        fis->numInputs, fis->numRules, fis->numInputMFs,
                        fis->numCumInputMFs, r, inputMFCache, irr);
          r1.set_size(fis->numInputs);
          vlen = fis->numInputs;
          for (k = 0; k < vlen; k++) {
            r1[k] = 0.0;
          }

          b_y = applyOperators(irr, fis->andMethod, fis->orMethod,
                               fis->connection, fis->weight, fis->numInputs,
                               fis->numRules, w, r1);
          c_y.set_size(1, fis->type.size(1));
          vlen = fis->type.size(1);
          for (k = 0; k < vlen; k++) {
            c_y[k] = static_cast<signed char>(fis->type[k]);
          }

          b_bool = false;
          if (c_y.size(1) == 7) {
            vlen = 0;
            int exitg1;
            do {
              exitg1 = 0;
              if (vlen < 7) {
                if (c_y[vlen] != cv[vlen]) {
                  exitg1 = 1;
                } else {
                  vlen++;
                }
              } else {
                b_bool = true;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }

          if (b_bool) {
            applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
              fis->numOutputs, fis->numRules, fis->numCumOutputMFs, fis->orrSize,
              outputMFCache, orr);
            applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
              fis->numRules, fis->aggSize, arr);
            b_applyMamdaniDefuzzificationMethod(fis->outputSamplePoints, b_y,
              arr, fis->outputRange, fis->numOutputs, r1);
            vlen = r1.size(0);
            for (k = 0; k < vlen; k++) {
              y[k] = r1[k];
            }
          } else {
            vlen = inputs.size(1);
            b_inputs.set_size(1, inputs.size(1));
            for (k = 0; k < vlen; k++) {
              b_inputs[k] = inputs[k];
            }

            applySugenoImplicationMethod(b_inputs, w, fis->outputMF,
              fis->consequent, fis->numOutputs, fis->numRules, fis->numOutputMFs,
              fis->numCumOutputMFs, fis->orrSize, orr, unImpSugRuleOut);
            applySugenoAggregationMethod(orr, inputMFCache);
            arr.set_size(b_arr.size(0), b_arr.size(1));
            vlen = b_arr.size(0) * b_arr.size(1);
            for (k = 0; k < vlen; k++) {
              arr[k] = inputMFCache[k];
            }

            vlen = fis->numOutputs;
            defuzzifiedOutputs.set_size(fis->numOutputs);
            for (k = 0; k < vlen; k++) {
              if (b_y == 0.0) {
                defuzzifiedOutputs[k] = (fis->outputRange[k] + fis->
                  outputRange[k + fis->outputRange.size(0)]) / 2.0;
              } else if (b_y == 0.0) {
                defuzzifiedOutputs[k] = (arr[k] + arr[k]) / 2.0;
              } else {
                defuzzifiedOutputs[k] = arr[k];
              }
            }

            vlen = defuzzifiedOutputs.size(0);
            for (k = 0; k < vlen; k++) {
              y[k] = defuzzifiedOutputs[k];
            }
          }
        }

        //
        // Arguments    : const ::coder::array<double, 1U> &inputs
        //                const f_struct_T *fis
        //                ::coder::array<double, 2U> &y
        // Return Type  : void
        //
        void evaluateFIS(const ::coder::array<double, 1U> &inputs, const
                         f_struct_T *fis, ::coder::array<double, 2U> &y)
        {
          static const unsigned char uv[8] = { 99U, 101U, 110U, 116U, 114U, 111U,
            105U, 100U };

          static const unsigned char uv1[8] = { 98U, 105U, 115U, 101U, 99U, 116U,
            111U, 114U };

          static const char cv[7] = { 'm', 'a', 'm', 'd', 'a', 'n', 'i' };

          static const unsigned char uv5[6] = { 119U, 116U, 97U, 118U, 101U,
            114U };

          static const unsigned char uv6[5] = { 119U, 116U, 115U, 117U, 109U };

          static const unsigned char uv2[3] = { 109U, 111U, 109U };

          static const unsigned char uv3[3] = { 115U, 111U, 109U };

          static const unsigned char uv4[3] = { 108U, 111U, 109U };

          const ::coder::array<double, 2U> *fis_outputRange;
          array<cell_wrap_0, 2U> inVarMF;
          array<double, 2U> arr;
          array<double, 2U> b_arr;
          array<double, 2U> b_fis;
          array<double, 2U> inputMFCache;
          array<double, 2U> orr;
          array<double, 2U> outputMFCache;
          array<double, 2U> r;
          array<double, 2U> unImpSugRuleOut;
          array<double, 1U> defuzzifiedOutputs;
          array<double, 1U> rfs;
          array<char, 2U> c_y;
          double irrOfOneRule_data[1];
          double b_y;
          double numInputDataSets;
          int vlen;
          if (isequal(fis->defuzzMethod, uv)) {
            int i;
            int k;
            initVariables(fis->type, fis->outputMF, fis->numOutputs,
                          fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                          fis->outputSamplePoints, fis->orrSize, fis->aggSize,
                          inputs, y, b_fis, orr, arr, rfs, unImpSugRuleOut,
                          outputMFCache, &numInputDataSets);
            extractVarMF(fis->inputMF, inVarMF);
            vlen = fis->numInputMFs.size(1);
            if (fis->numInputMFs.size(1) == 0) {
              b_y = 0.0;
            } else {
              b_y = fis->numInputMFs[0];
              for (k = 2; k <= vlen; k++) {
                b_y += static_cast<double>(fis->numInputMFs[k - 1]);
              }
            }

            inputMFCache.set_size(1, (static_cast<int>(b_y)));
            irrOfOneRule_data[0] = 0.0;
            i = static_cast<int>(numInputDataSets);
            for (int b_i = 0; b_i < i; b_i++) {
              boolean_T b_bool;
              fuzzifyInputs(inputs[b_i], fis->antecedent, fis->connection,
                            fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                            inVarMF, inputMFCache, b_fis);
              defuzzifiedOutputs.set_size(1);
              defuzzifiedOutputs[0] = irrOfOneRule_data[0];
              numInputDataSets = applyOperators(b_fis, fis->andMethod,
                fis->orMethod, fis->connection, fis->weight, fis->numInputs,
                fis->numRules, rfs, defuzzifiedOutputs);
              vlen = defuzzifiedOutputs.size(0);
              for (k = 0; k < vlen; k++) {
                irrOfOneRule_data[k] = defuzzifiedOutputs[k];
              }

              vlen = fis->type.size(1);
              c_y.set_size(1, fis->type.size(1));
              for (k = 0; k < vlen; k++) {
                c_y[k] = static_cast<signed char>(fis->type[k]);
              }

              b_bool = false;
              if (c_y.size(1) == 7) {
                vlen = 0;
                int exitg1;
                do {
                  exitg1 = 0;
                  if (vlen < 7) {
                    if (c_y[vlen] != cv[vlen]) {
                      exitg1 = 1;
                    } else {
                      vlen++;
                    }
                  } else {
                    b_bool = true;
                    exitg1 = 1;
                  }
                } while (exitg1 == 0);
              }

              if (b_bool) {
                applyMamdaniImplicationMethod(rfs, fis->impMethod,
                  fis->consequent, fis->numOutputs, fis->numRules,
                  fis->numCumOutputMFs, fis->orrSize, outputMFCache, orr);
                applyMamdaniAggregationMethod(orr, fis->aggMethod,
                  fis->numOutputs, fis->numRules, fis->aggSize, b_arr);
                arr.set_size(b_arr.size(0), b_arr.size(1));
                applyMamdaniDefuzzificationMethod(fis->outputSamplePoints,
                  numInputDataSets, b_arr, fis->outputRange, fis->numOutputs,
                  defuzzifiedOutputs);
                vlen = defuzzifiedOutputs.size(0);
                for (k = 0; k < vlen; k++) {
                  y[b_i + y.size(0) * k] = defuzzifiedOutputs[k];
                }
              } else {
                applySugenoImplicationMethod(inputs[b_i], rfs, fis->outputMF,
                  fis->consequent, fis->numOutputs, fis->numRules,
                  fis->numOutputMFs, fis->numCumOutputMFs, fis->orrSize, orr,
                  unImpSugRuleOut);
                applySugenoAggregationMethod(orr, r);
                vlen = arr.size(0);
                k = arr.size(1);
                arr.set_size(vlen, k);
                vlen *= k;
                for (k = 0; k < vlen; k++) {
                  arr[k] = r[k];
                }

                fis_outputRange = &fis->outputRange;
                vlen = fis->numOutputs;
                defuzzifiedOutputs.set_size(vlen);
                for (k = 0; k < vlen; k++) {
                  if (numInputDataSets == 0.0) {
                    defuzzifiedOutputs[k] = ((*fis_outputRange)[k] +
                      (*fis_outputRange)[k + fis_outputRange->size(0)]) / 2.0;
                  } else if (numInputDataSets == 0.0) {
                    defuzzifiedOutputs[k] = (arr[k] + arr[k]) / 2.0;
                  } else {
                    defuzzifiedOutputs[k] = arr[k] * numInputDataSets * (1.0 /
                      numInputDataSets);
                  }
                }

                vlen = defuzzifiedOutputs.size(0);
                for (k = 0; k < vlen; k++) {
                  y[b_i + y.size(0) * k] = defuzzifiedOutputs[k];
                }
              }
            }
          } else if (isequal(fis->defuzzMethod, uv1)) {
            runFIS(inputs, fis, y, b_fis, orr, arr, rfs, unImpSugRuleOut);
          } else if (b_isequal(fis->defuzzMethod, uv2)) {
            int i;
            int k;
            initVariables(fis->type, fis->outputMF, fis->numOutputs,
                          fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                          fis->outputSamplePoints, fis->orrSize, fis->aggSize,
                          inputs, y, b_fis, orr, arr, rfs, unImpSugRuleOut,
                          outputMFCache, &numInputDataSets);
            extractVarMF(fis->inputMF, inVarMF);
            vlen = fis->numInputMFs.size(1);
            if (fis->numInputMFs.size(1) == 0) {
              b_y = 0.0;
            } else {
              b_y = fis->numInputMFs[0];
              for (k = 2; k <= vlen; k++) {
                b_y += static_cast<double>(fis->numInputMFs[k - 1]);
              }
            }

            inputMFCache.set_size(1, (static_cast<int>(b_y)));
            irrOfOneRule_data[0] = 0.0;
            i = static_cast<int>(numInputDataSets);
            for (int b_i = 0; b_i < i; b_i++) {
              boolean_T b_bool;
              fuzzifyInputs(inputs[b_i], fis->antecedent, fis->connection,
                            fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                            inVarMF, inputMFCache, b_fis);
              defuzzifiedOutputs.set_size(1);
              defuzzifiedOutputs[0] = irrOfOneRule_data[0];
              numInputDataSets = applyOperators(b_fis, fis->andMethod,
                fis->orMethod, fis->connection, fis->weight, fis->numInputs,
                fis->numRules, rfs, defuzzifiedOutputs);
              vlen = defuzzifiedOutputs.size(0);
              for (k = 0; k < vlen; k++) {
                irrOfOneRule_data[k] = defuzzifiedOutputs[k];
              }

              vlen = fis->type.size(1);
              c_y.set_size(1, fis->type.size(1));
              for (k = 0; k < vlen; k++) {
                c_y[k] = static_cast<signed char>(fis->type[k]);
              }

              b_bool = false;
              if (c_y.size(1) == 7) {
                vlen = 0;
                int exitg1;
                do {
                  exitg1 = 0;
                  if (vlen < 7) {
                    if (c_y[vlen] != cv[vlen]) {
                      exitg1 = 1;
                    } else {
                      vlen++;
                    }
                  } else {
                    b_bool = true;
                    exitg1 = 1;
                  }
                } while (exitg1 == 0);
              }

              if (b_bool) {
                applyMamdaniImplicationMethod(rfs, fis->impMethod,
                  fis->consequent, fis->numOutputs, fis->numRules,
                  fis->numCumOutputMFs, fis->orrSize, outputMFCache, orr);
                applyMamdaniAggregationMethod(orr, fis->aggMethod,
                  fis->numOutputs, fis->numRules, fis->aggSize, b_arr);
                arr.set_size(b_arr.size(0), b_arr.size(1));
                c_applyMamdaniDefuzzificationMethod(fis->outputSamplePoints,
                  numInputDataSets, b_arr, fis->outputRange, fis->numOutputs,
                  defuzzifiedOutputs);
                vlen = defuzzifiedOutputs.size(0);
                for (k = 0; k < vlen; k++) {
                  y[b_i + y.size(0) * k] = defuzzifiedOutputs[k];
                }
              } else {
                applySugenoImplicationMethod(inputs[b_i], rfs, fis->outputMF,
                  fis->consequent, fis->numOutputs, fis->numRules,
                  fis->numOutputMFs, fis->numCumOutputMFs, fis->orrSize, orr,
                  unImpSugRuleOut);
                applySugenoAggregationMethod(orr, r);
                vlen = arr.size(0);
                k = arr.size(1);
                arr.set_size(vlen, k);
                vlen *= k;
                for (k = 0; k < vlen; k++) {
                  arr[k] = r[k];
                }

                applySugenoDefuzzificationMethod(numInputDataSets, arr,
                  fis->outputRange, fis->numOutputs, defuzzifiedOutputs);
                vlen = defuzzifiedOutputs.size(0);
                for (k = 0; k < vlen; k++) {
                  y[b_i + y.size(0) * k] = defuzzifiedOutputs[k];
                }
              }
            }
          } else if (b_isequal(fis->defuzzMethod, uv3)) {
            int i;
            int k;
            initVariables(fis->type, fis->outputMF, fis->numOutputs,
                          fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                          fis->outputSamplePoints, fis->orrSize, fis->aggSize,
                          inputs, y, b_fis, orr, arr, rfs, unImpSugRuleOut,
                          outputMFCache, &numInputDataSets);
            extractVarMF(fis->inputMF, inVarMF);
            vlen = fis->numInputMFs.size(1);
            if (fis->numInputMFs.size(1) == 0) {
              b_y = 0.0;
            } else {
              b_y = fis->numInputMFs[0];
              for (k = 2; k <= vlen; k++) {
                b_y += static_cast<double>(fis->numInputMFs[k - 1]);
              }
            }

            inputMFCache.set_size(1, (static_cast<int>(b_y)));
            irrOfOneRule_data[0] = 0.0;
            i = static_cast<int>(numInputDataSets);
            for (int b_i = 0; b_i < i; b_i++) {
              boolean_T b_bool;
              fuzzifyInputs(inputs[b_i], fis->antecedent, fis->connection,
                            fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                            inVarMF, inputMFCache, b_fis);
              defuzzifiedOutputs.set_size(1);
              defuzzifiedOutputs[0] = irrOfOneRule_data[0];
              numInputDataSets = applyOperators(b_fis, fis->andMethod,
                fis->orMethod, fis->connection, fis->weight, fis->numInputs,
                fis->numRules, rfs, defuzzifiedOutputs);
              vlen = defuzzifiedOutputs.size(0);
              for (k = 0; k < vlen; k++) {
                irrOfOneRule_data[k] = defuzzifiedOutputs[k];
              }

              vlen = fis->type.size(1);
              c_y.set_size(1, fis->type.size(1));
              for (k = 0; k < vlen; k++) {
                c_y[k] = static_cast<signed char>(fis->type[k]);
              }

              b_bool = false;
              if (c_y.size(1) == 7) {
                vlen = 0;
                int exitg1;
                do {
                  exitg1 = 0;
                  if (vlen < 7) {
                    if (c_y[vlen] != cv[vlen]) {
                      exitg1 = 1;
                    } else {
                      vlen++;
                    }
                  } else {
                    b_bool = true;
                    exitg1 = 1;
                  }
                } while (exitg1 == 0);
              }

              if (b_bool) {
                applyMamdaniImplicationMethod(rfs, fis->impMethod,
                  fis->consequent, fis->numOutputs, fis->numRules,
                  fis->numCumOutputMFs, fis->orrSize, outputMFCache, orr);
                applyMamdaniAggregationMethod(orr, fis->aggMethod,
                  fis->numOutputs, fis->numRules, fis->aggSize, b_arr);
                arr.set_size(b_arr.size(0), b_arr.size(1));
                d_applyMamdaniDefuzzificationMethod(fis->outputSamplePoints,
                  numInputDataSets, b_arr, fis->outputRange, fis->numOutputs,
                  defuzzifiedOutputs);
                vlen = defuzzifiedOutputs.size(0);
                for (k = 0; k < vlen; k++) {
                  y[b_i + y.size(0) * k] = defuzzifiedOutputs[k];
                }
              } else {
                applySugenoImplicationMethod(inputs[b_i], rfs, fis->outputMF,
                  fis->consequent, fis->numOutputs, fis->numRules,
                  fis->numOutputMFs, fis->numCumOutputMFs, fis->orrSize, orr,
                  unImpSugRuleOut);
                applySugenoAggregationMethod(orr, r);
                vlen = arr.size(0);
                k = arr.size(1);
                arr.set_size(vlen, k);
                vlen *= k;
                for (k = 0; k < vlen; k++) {
                  arr[k] = r[k];
                }

                vlen = fis->numOutputs;
                defuzzifiedOutputs.set_size(fis->numOutputs);
                for (k = 0; k < vlen; k++) {
                  if (numInputDataSets == 0.0) {
                    defuzzifiedOutputs[k] = (fis->outputRange[k] +
                      fis->outputRange[k + fis->outputRange.size(0)]) / 2.0;
                  } else {
                    defuzzifiedOutputs[k] = arr[k];
                  }
                }

                vlen = defuzzifiedOutputs.size(0);
                for (k = 0; k < vlen; k++) {
                  y[b_i + y.size(0) * k] = defuzzifiedOutputs[k];
                }
              }
            }
          } else if (b_isequal(fis->defuzzMethod, uv4)) {
            int i;
            int k;
            initVariables(fis->type, fis->outputMF, fis->numOutputs,
                          fis->numRules, fis->numOutputMFs, fis->numCumOutputMFs,
                          fis->outputSamplePoints, fis->orrSize, fis->aggSize,
                          inputs, y, b_fis, orr, arr, rfs, unImpSugRuleOut,
                          outputMFCache, &numInputDataSets);
            extractVarMF(fis->inputMF, inVarMF);
            vlen = fis->numInputMFs.size(1);
            if (fis->numInputMFs.size(1) == 0) {
              b_y = 0.0;
            } else {
              b_y = fis->numInputMFs[0];
              for (k = 2; k <= vlen; k++) {
                b_y += static_cast<double>(fis->numInputMFs[k - 1]);
              }
            }

            inputMFCache.set_size(1, (static_cast<int>(b_y)));
            irrOfOneRule_data[0] = 0.0;
            i = static_cast<int>(numInputDataSets);
            for (int b_i = 0; b_i < i; b_i++) {
              boolean_T b_bool;
              fuzzifyInputs(inputs[b_i], fis->antecedent, fis->connection,
                            fis->numRules, fis->numInputMFs, fis->numCumInputMFs,
                            inVarMF, inputMFCache, b_fis);
              defuzzifiedOutputs.set_size(1);
              defuzzifiedOutputs[0] = irrOfOneRule_data[0];
              numInputDataSets = applyOperators(b_fis, fis->andMethod,
                fis->orMethod, fis->connection, fis->weight, fis->numInputs,
                fis->numRules, rfs, defuzzifiedOutputs);
              vlen = defuzzifiedOutputs.size(0);
              for (k = 0; k < vlen; k++) {
                irrOfOneRule_data[k] = defuzzifiedOutputs[k];
              }

              vlen = fis->type.size(1);
              c_y.set_size(1, fis->type.size(1));
              for (k = 0; k < vlen; k++) {
                c_y[k] = static_cast<signed char>(fis->type[k]);
              }

              b_bool = false;
              if (c_y.size(1) == 7) {
                vlen = 0;
                int exitg1;
                do {
                  exitg1 = 0;
                  if (vlen < 7) {
                    if (c_y[vlen] != cv[vlen]) {
                      exitg1 = 1;
                    } else {
                      vlen++;
                    }
                  } else {
                    b_bool = true;
                    exitg1 = 1;
                  }
                } while (exitg1 == 0);
              }

              if (b_bool) {
                applyMamdaniImplicationMethod(rfs, fis->impMethod,
                  fis->consequent, fis->numOutputs, fis->numRules,
                  fis->numCumOutputMFs, fis->orrSize, outputMFCache, orr);
                applyMamdaniAggregationMethod(orr, fis->aggMethod,
                  fis->numOutputs, fis->numRules, fis->aggSize, b_arr);
                arr.set_size(b_arr.size(0), b_arr.size(1));
                e_applyMamdaniDefuzzificationMethod(fis->outputSamplePoints,
                  numInputDataSets, b_arr, fis->outputRange, fis->numOutputs,
                  defuzzifiedOutputs);
                vlen = defuzzifiedOutputs.size(0);
                for (k = 0; k < vlen; k++) {
                  y[b_i + y.size(0) * k] = defuzzifiedOutputs[k];
                }
              } else {
                applySugenoImplicationMethod(inputs[b_i], rfs, fis->outputMF,
                  fis->consequent, fis->numOutputs, fis->numRules,
                  fis->numOutputMFs, fis->numCumOutputMFs, fis->orrSize, orr,
                  unImpSugRuleOut);
                applySugenoAggregationMethod(orr, r);
                vlen = arr.size(0);
                k = arr.size(1);
                arr.set_size(vlen, k);
                vlen *= k;
                for (k = 0; k < vlen; k++) {
                  arr[k] = r[k];
                }

                vlen = fis->numOutputs;
                defuzzifiedOutputs.set_size(fis->numOutputs);
                for (k = 0; k < vlen; k++) {
                  if (numInputDataSets == 0.0) {
                    defuzzifiedOutputs[k] = (fis->outputRange[k] +
                      fis->outputRange[k + fis->outputRange.size(0)]) / 2.0;
                  } else {
                    defuzzifiedOutputs[k] = arr[k];
                  }
                }

                vlen = defuzzifiedOutputs.size(0);
                for (k = 0; k < vlen; k++) {
                  y[b_i + y.size(0) * k] = defuzzifiedOutputs[k];
                }
              }
            }
          } else if (d_isequal(fis->defuzzMethod, uv5)) {
            b_runFIS(inputs, fis, y, b_fis, orr, arr, rfs, unImpSugRuleOut);
          } else if (e_isequal(fis->defuzzMethod, uv6)) {
            c_runFIS(inputs, fis, y, b_fis, orr, arr, rfs, unImpSugRuleOut);
          } else {
            boolean_T b_bool;
            y.set_size(inputs.size(0), fis->numOutputs);
            c_y.set_size(1, fis->type.size(1));
            vlen = fis->type.size(1);
            for (int i = 0; i < vlen; i++) {
              c_y[i] = static_cast<signed char>(fis->type[i]);
            }

            b_bool = false;
            if (c_y.size(1) == 7) {
              vlen = 0;
              int exitg1;
              do {
                exitg1 = 0;
                if (vlen < 7) {
                  if (c_y[vlen] != cv[vlen]) {
                    exitg1 = 1;
                  } else {
                    vlen++;
                  }
                } else {
                  b_bool = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }

            if (b_bool) {
              createMamdaniOutputMFCache(fis->outputMF, fis->numOutputs,
                fis->numOutputMFs, fis->numCumOutputMFs, fis->outputSamplePoints,
                b_fis);
            }

            exit(0);
          }
        }

        //
        // Arguments    : const ::coder::array<double, 2U> &inputs
        //                const f_struct_T *fis
        //                ::coder::array<double, 2U> &y
        // Return Type  : void
        //
        void evaluateFIS(const ::coder::array<double, 2U> &inputs, const
                         f_struct_T *fis, ::coder::array<double, 2U> &y)
        {
          static const unsigned char uv[8] = { 99U, 101U, 110U, 116U, 114U, 111U,
            105U, 100U };

          static const unsigned char uv1[8] = { 98U, 105U, 115U, 101U, 99U, 116U,
            111U, 114U };

          static const char cv[7] = { 'm', 'a', 'm', 'd', 'a', 'n', 'i' };

          static const unsigned char uv5[6] = { 119U, 116U, 97U, 118U, 101U,
            114U };

          static const unsigned char uv6[5] = { 119U, 116U, 115U, 117U, 109U };

          static const unsigned char uv2[3] = { 109U, 111U, 109U };

          static const unsigned char uv3[3] = { 115U, 111U, 109U };

          static const unsigned char uv4[3] = { 108U, 111U, 109U };

          const ::coder::array<double, 2U> *fis_outputRange;
          const ::coder::array<double, 2U> *outputSamplePoints;
          array<cell_wrap_0, 2U> r;
          array<double, 2U> arr;
          array<double, 2U> b_fis;
          array<double, 2U> b_inputs;
          array<double, 2U> b_orr;
          array<double, 2U> inputMFCache;
          array<double, 2U> orr;
          array<double, 2U> outputMFCache;
          array<double, 2U> unImpSugRuleOut;
          array<double, 1U> defuzzifiedOutputs;
          array<double, 1U> r1;
          array<double, 1U> w;
          array<char, 2U> c_y;
          double b_y;
          int vlen;
          if (isequal(fis->defuzzMethod, uv)) {
            int k;
            boolean_T b_bool;
            initVariables(fis->type, fis->outputMF, fis->numInputs,
                          fis->numOutputs, fis->numRules, fis->numOutputMFs,
                          fis->numCumOutputMFs, fis->outputSamplePoints,
                          fis->orrSize, fis->aggSize, y, b_fis, orr, arr, w,
                          unImpSugRuleOut, outputMFCache);
            vlen = fis->numInputMFs.size(1);
            if (fis->numInputMFs.size(1) == 0) {
              b_y = 0.0;
            } else {
              b_y = fis->numInputMFs[0];
              for (k = 2; k <= vlen; k++) {
                b_y += static_cast<double>(fis->numInputMFs[k - 1]);
              }
            }

            inputMFCache.set_size(1, (static_cast<int>(b_y)));
            vlen = inputs.size(1);
            b_inputs.set_size(1, inputs.size(1));
            for (k = 0; k < vlen; k++) {
              b_inputs[k] = inputs[k];
            }

            extractVarMF(fis->inputMF, r);
            fuzzifyInputs(b_inputs, fis->antecedent, fis->connection,
                          fis->numInputs, fis->numRules, fis->numInputMFs,
                          fis->numCumInputMFs, r, inputMFCache, b_fis);
            r1.set_size(fis->numInputs);
            vlen = fis->numInputs;
            for (k = 0; k < vlen; k++) {
              r1[k] = 0.0;
            }

            b_y = applyOperators(b_fis, fis->andMethod, fis->orMethod,
                                 fis->connection, fis->weight, fis->numInputs,
                                 fis->numRules, w, r1);
            c_y.set_size(1, fis->type.size(1));
            vlen = fis->type.size(1);
            for (k = 0; k < vlen; k++) {
              c_y[k] = static_cast<signed char>(fis->type[k]);
            }

            b_bool = false;
            if (c_y.size(1) == 7) {
              vlen = 0;
              int exitg1;
              do {
                exitg1 = 0;
                if (vlen < 7) {
                  if (c_y[vlen] != cv[vlen]) {
                    exitg1 = 1;
                  } else {
                    vlen++;
                  }
                } else {
                  b_bool = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }

            if (b_bool) {
              applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
                fis->numOutputs, fis->numRules, fis->numCumOutputMFs,
                fis->orrSize, outputMFCache, orr);
              applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                fis->numRules, fis->aggSize, arr);
              applyMamdaniDefuzzificationMethod(fis->outputSamplePoints, b_y,
                arr, fis->outputRange, fis->numOutputs, r1);
              vlen = r1.size(0);
              for (k = 0; k < vlen; k++) {
                y[k] = r1[k];
              }
            } else {
              vlen = inputs.size(1);
              b_inputs.set_size(1, inputs.size(1));
              for (k = 0; k < vlen; k++) {
                b_inputs[k] = inputs[k];
              }

              applySugenoImplicationMethod(b_inputs, w, fis->outputMF,
                fis->consequent, fis->numOutputs, fis->numRules,
                fis->numOutputMFs, fis->numCumOutputMFs, fis->orrSize, orr,
                b_fis);
              applySugenoAggregationMethod(orr, inputMFCache);
              b_fis = inputMFCache.reshape((*(int (*)[2])arr.size())[0], (*(int
                (*)[2])arr.size())[1]);
              fis_outputRange = &fis->outputRange;
              vlen = fis->numOutputs;
              r1.set_size(vlen);
              for (k = 0; k < vlen; k++) {
                if (b_y == 0.0) {
                  r1[k] = ((*fis_outputRange)[k] + (*fis_outputRange)[k +
                           fis_outputRange->size(0)]) / 2.0;
                } else if (b_y == 0.0) {
                  r1[k] = (b_fis[k] + b_fis[k]) / 2.0;
                } else {
                  r1[k] = b_fis[k] * b_y * (1.0 / b_y);
                }
              }

              vlen = r1.size(0);
              for (k = 0; k < vlen; k++) {
                y[k] = r1[k];
              }
            }
          } else if (isequal(fis->defuzzMethod, uv1)) {
            runFIS(inputs, fis, y, b_fis, orr, arr, w, unImpSugRuleOut);
          } else if (b_isequal(fis->defuzzMethod, uv2)) {
            int k;
            boolean_T b_bool;
            initVariables(fis->type, fis->outputMF, fis->numInputs,
                          fis->numOutputs, fis->numRules, fis->numOutputMFs,
                          fis->numCumOutputMFs, fis->outputSamplePoints,
                          fis->orrSize, fis->aggSize, y, b_fis, orr, arr, w,
                          unImpSugRuleOut, outputMFCache);
            vlen = fis->numInputMFs.size(1);
            if (fis->numInputMFs.size(1) == 0) {
              b_y = 0.0;
            } else {
              b_y = fis->numInputMFs[0];
              for (k = 2; k <= vlen; k++) {
                b_y += static_cast<double>(fis->numInputMFs[k - 1]);
              }
            }

            inputMFCache.set_size(1, (static_cast<int>(b_y)));
            vlen = inputs.size(1);
            b_inputs.set_size(1, inputs.size(1));
            for (k = 0; k < vlen; k++) {
              b_inputs[k] = inputs[k];
            }

            extractVarMF(fis->inputMF, r);
            fuzzifyInputs(b_inputs, fis->antecedent, fis->connection,
                          fis->numInputs, fis->numRules, fis->numInputMFs,
                          fis->numCumInputMFs, r, inputMFCache, b_fis);
            r1.set_size(fis->numInputs);
            vlen = fis->numInputs;
            for (k = 0; k < vlen; k++) {
              r1[k] = 0.0;
            }

            b_y = applyOperators(b_fis, fis->andMethod, fis->orMethod,
                                 fis->connection, fis->weight, fis->numInputs,
                                 fis->numRules, w, r1);
            c_y.set_size(1, fis->type.size(1));
            vlen = fis->type.size(1);
            for (k = 0; k < vlen; k++) {
              c_y[k] = static_cast<signed char>(fis->type[k]);
            }

            b_bool = false;
            if (c_y.size(1) == 7) {
              vlen = 0;
              int exitg1;
              do {
                exitg1 = 0;
                if (vlen < 7) {
                  if (c_y[vlen] != cv[vlen]) {
                    exitg1 = 1;
                  } else {
                    vlen++;
                  }
                } else {
                  b_bool = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }

            if (b_bool) {
              applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
                fis->numOutputs, fis->numRules, fis->numCumOutputMFs,
                fis->orrSize, outputMFCache, orr);
              applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                fis->numRules, fis->aggSize, arr);
              c_applyMamdaniDefuzzificationMethod(fis->outputSamplePoints, b_y,
                arr, fis->outputRange, fis->numOutputs, r1);
              vlen = r1.size(0);
              for (k = 0; k < vlen; k++) {
                y[k] = r1[k];
              }
            } else {
              vlen = inputs.size(1);
              b_inputs.set_size(1, inputs.size(1));
              for (k = 0; k < vlen; k++) {
                b_inputs[k] = inputs[k];
              }

              applySugenoImplicationMethod(b_inputs, w, fis->outputMF,
                fis->consequent, fis->numOutputs, fis->numRules,
                fis->numOutputMFs, fis->numCumOutputMFs, fis->orrSize, orr,
                b_fis);
              applySugenoAggregationMethod(orr, inputMFCache);
              b_fis = inputMFCache.reshape((*(int (*)[2])arr.size())[0], (*(int
                (*)[2])arr.size())[1]);
              applySugenoDefuzzificationMethod(b_y, b_fis, fis->outputRange,
                fis->numOutputs, r1);
              vlen = r1.size(0);
              for (k = 0; k < vlen; k++) {
                y[k] = r1[k];
              }
            }
          } else if (b_isequal(fis->defuzzMethod, uv3)) {
            int k;
            boolean_T b_bool;
            initVariables(fis->type, fis->outputMF, fis->numInputs,
                          fis->numOutputs, fis->numRules, fis->numOutputMFs,
                          fis->numCumOutputMFs, fis->outputSamplePoints,
                          fis->orrSize, fis->aggSize, y, b_fis, orr, arr, w,
                          unImpSugRuleOut, outputMFCache);
            vlen = fis->numInputMFs.size(1);
            if (fis->numInputMFs.size(1) == 0) {
              b_y = 0.0;
            } else {
              b_y = fis->numInputMFs[0];
              for (k = 2; k <= vlen; k++) {
                b_y += static_cast<double>(fis->numInputMFs[k - 1]);
              }
            }

            inputMFCache.set_size(1, (static_cast<int>(b_y)));
            vlen = inputs.size(1);
            b_inputs.set_size(1, inputs.size(1));
            for (k = 0; k < vlen; k++) {
              b_inputs[k] = inputs[k];
            }

            extractVarMF(fis->inputMF, r);
            fuzzifyInputs(b_inputs, fis->antecedent, fis->connection,
                          fis->numInputs, fis->numRules, fis->numInputMFs,
                          fis->numCumInputMFs, r, inputMFCache, b_fis);
            r1.set_size(fis->numInputs);
            vlen = fis->numInputs;
            for (k = 0; k < vlen; k++) {
              r1[k] = 0.0;
            }

            b_y = applyOperators(b_fis, fis->andMethod, fis->orMethod,
                                 fis->connection, fis->weight, fis->numInputs,
                                 fis->numRules, w, r1);
            c_y.set_size(1, fis->type.size(1));
            vlen = fis->type.size(1);
            for (k = 0; k < vlen; k++) {
              c_y[k] = static_cast<signed char>(fis->type[k]);
            }

            b_bool = false;
            if (c_y.size(1) == 7) {
              vlen = 0;
              int exitg1;
              do {
                exitg1 = 0;
                if (vlen < 7) {
                  if (c_y[vlen] != cv[vlen]) {
                    exitg1 = 1;
                  } else {
                    vlen++;
                  }
                } else {
                  b_bool = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }

            if (b_bool) {
              applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
                fis->numOutputs, fis->numRules, fis->numCumOutputMFs,
                fis->orrSize, outputMFCache, orr);
              applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                fis->numRules, fis->aggSize, arr);
              d_applyMamdaniDefuzzificationMethod(fis->outputSamplePoints, b_y,
                arr, fis->outputRange, fis->numOutputs, r1);
              vlen = r1.size(0);
              for (k = 0; k < vlen; k++) {
                y[k] = r1[k];
              }
            } else {
              vlen = inputs.size(1);
              b_inputs.set_size(1, inputs.size(1));
              for (k = 0; k < vlen; k++) {
                b_inputs[k] = inputs[k];
              }

              applySugenoImplicationMethod(b_inputs, w, fis->outputMF,
                fis->consequent, fis->numOutputs, fis->numRules,
                fis->numOutputMFs, fis->numCumOutputMFs, fis->orrSize, orr,
                b_fis);
              applySugenoAggregationMethod(orr, inputMFCache);
              vlen = arr.size(0);
              k = arr.size(1);
              arr.set_size(vlen, k);
              vlen *= k;
              for (k = 0; k < vlen; k++) {
                arr[k] = inputMFCache[k];
              }

              vlen = fis->numOutputs;
              defuzzifiedOutputs.set_size(fis->numOutputs);
              for (k = 0; k < vlen; k++) {
                if (b_y == 0.0) {
                  defuzzifiedOutputs[k] = (fis->outputRange[k] +
                    fis->outputRange[k + fis->outputRange.size(0)]) / 2.0;
                } else {
                  defuzzifiedOutputs[k] = arr[k];
                }
              }

              vlen = defuzzifiedOutputs.size(0);
              for (k = 0; k < vlen; k++) {
                y[k] = defuzzifiedOutputs[k];
              }
            }
          } else if (b_isequal(fis->defuzzMethod, uv4)) {
            int k;
            boolean_T b_bool;
            initVariables(fis->type, fis->outputMF, fis->numInputs,
                          fis->numOutputs, fis->numRules, fis->numOutputMFs,
                          fis->numCumOutputMFs, fis->outputSamplePoints,
                          fis->orrSize, fis->aggSize, y, b_fis, orr, arr, w,
                          unImpSugRuleOut, outputMFCache);
            vlen = fis->numInputMFs.size(1);
            if (fis->numInputMFs.size(1) == 0) {
              b_y = 0.0;
            } else {
              b_y = fis->numInputMFs[0];
              for (k = 2; k <= vlen; k++) {
                b_y += static_cast<double>(fis->numInputMFs[k - 1]);
              }
            }

            inputMFCache.set_size(1, (static_cast<int>(b_y)));
            vlen = inputs.size(1);
            b_inputs.set_size(1, inputs.size(1));
            for (k = 0; k < vlen; k++) {
              b_inputs[k] = inputs[k];
            }

            extractVarMF(fis->inputMF, r);
            fuzzifyInputs(b_inputs, fis->antecedent, fis->connection,
                          fis->numInputs, fis->numRules, fis->numInputMFs,
                          fis->numCumInputMFs, r, inputMFCache, b_fis);
            r1.set_size(fis->numInputs);
            vlen = fis->numInputs;
            for (k = 0; k < vlen; k++) {
              r1[k] = 0.0;
            }

            b_y = applyOperators(b_fis, fis->andMethod, fis->orMethod,
                                 fis->connection, fis->weight, fis->numInputs,
                                 fis->numRules, w, r1);
            c_y.set_size(1, fis->type.size(1));
            vlen = fis->type.size(1);
            for (k = 0; k < vlen; k++) {
              c_y[k] = static_cast<signed char>(fis->type[k]);
            }

            b_bool = false;
            if (c_y.size(1) == 7) {
              vlen = 0;
              int exitg1;
              do {
                exitg1 = 0;
                if (vlen < 7) {
                  if (c_y[vlen] != cv[vlen]) {
                    exitg1 = 1;
                  } else {
                    vlen++;
                  }
                } else {
                  b_bool = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }

            if (b_bool) {
              applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
                fis->numOutputs, fis->numRules, fis->numCumOutputMFs,
                fis->orrSize, outputMFCache, orr);
              applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                fis->numRules, fis->aggSize, arr);
              e_applyMamdaniDefuzzificationMethod(fis->outputSamplePoints, b_y,
                arr, fis->outputRange, fis->numOutputs, r1);
              vlen = r1.size(0);
              for (k = 0; k < vlen; k++) {
                y[k] = r1[k];
              }
            } else {
              vlen = inputs.size(1);
              b_inputs.set_size(1, inputs.size(1));
              for (k = 0; k < vlen; k++) {
                b_inputs[k] = inputs[k];
              }

              applySugenoImplicationMethod(b_inputs, w, fis->outputMF,
                fis->consequent, fis->numOutputs, fis->numRules,
                fis->numOutputMFs, fis->numCumOutputMFs, fis->orrSize, orr,
                b_fis);
              applySugenoAggregationMethod(orr, inputMFCache);
              vlen = arr.size(0);
              k = arr.size(1);
              arr.set_size(vlen, k);
              vlen *= k;
              for (k = 0; k < vlen; k++) {
                arr[k] = inputMFCache[k];
              }

              vlen = fis->numOutputs;
              defuzzifiedOutputs.set_size(fis->numOutputs);
              for (k = 0; k < vlen; k++) {
                if (b_y == 0.0) {
                  defuzzifiedOutputs[k] = (fis->outputRange[k] +
                    fis->outputRange[k + fis->outputRange.size(0)]) / 2.0;
                } else {
                  defuzzifiedOutputs[k] = arr[k];
                }
              }

              vlen = defuzzifiedOutputs.size(0);
              for (k = 0; k < vlen; k++) {
                y[k] = defuzzifiedOutputs[k];
              }
            }
          } else if (d_isequal(fis->defuzzMethod, uv5)) {
            b_runFIS(inputs, fis, y, b_fis, orr, arr, w, unImpSugRuleOut);
          } else if (e_isequal(fis->defuzzMethod, uv6)) {
            int k;
            boolean_T b_bool;
            initVariables(fis->type, fis->outputMF, fis->numInputs,
                          fis->numOutputs, fis->numRules, fis->numOutputMFs,
                          fis->numCumOutputMFs, fis->outputSamplePoints,
                          fis->orrSize, fis->aggSize, y, b_fis, orr, arr, w,
                          unImpSugRuleOut, outputMFCache);
            vlen = fis->numInputMFs.size(1);
            if (fis->numInputMFs.size(1) == 0) {
              b_y = 0.0;
            } else {
              b_y = fis->numInputMFs[0];
              for (k = 2; k <= vlen; k++) {
                b_y += static_cast<double>(fis->numInputMFs[k - 1]);
              }
            }

            inputMFCache.set_size(1, (static_cast<int>(b_y)));
            vlen = inputs.size(1);
            b_inputs.set_size(1, inputs.size(1));
            for (k = 0; k < vlen; k++) {
              b_inputs[k] = inputs[k];
            }

            extractVarMF(fis->inputMF, r);
            fuzzifyInputs(b_inputs, fis->antecedent, fis->connection,
                          fis->numInputs, fis->numRules, fis->numInputMFs,
                          fis->numCumInputMFs, r, inputMFCache, b_fis);
            r1.set_size(fis->numInputs);
            vlen = fis->numInputs;
            for (k = 0; k < vlen; k++) {
              r1[k] = 0.0;
            }

            b_y = applyOperators(b_fis, fis->andMethod, fis->orMethod,
                                 fis->connection, fis->weight, fis->numInputs,
                                 fis->numRules, w, r1);
            c_y.set_size(1, fis->type.size(1));
            vlen = fis->type.size(1);
            for (k = 0; k < vlen; k++) {
              c_y[k] = static_cast<signed char>(fis->type[k]);
            }

            b_bool = false;
            if (c_y.size(1) == 7) {
              vlen = 0;
              int exitg1;
              do {
                exitg1 = 0;
                if (vlen < 7) {
                  if (c_y[vlen] != cv[vlen]) {
                    exitg1 = 1;
                  } else {
                    vlen++;
                  }
                } else {
                  b_bool = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }

            if (b_bool) {
              applyMamdaniImplicationMethod(w, fis->impMethod, fis->consequent,
                fis->numOutputs, fis->numRules, fis->numCumOutputMFs,
                fis->orrSize, outputMFCache, orr);
              applyMamdaniAggregationMethod(orr, fis->aggMethod, fis->numOutputs,
                fis->numRules, fis->aggSize, b_orr);
              outputSamplePoints = &fis->outputSamplePoints;
              fis_outputRange = &fis->outputRange;
              vlen = fis->numOutputs;
              r1.set_size(vlen);
              for (k = 0; k < vlen; k++) {
                if (b_y == 0.0) {
                  r1[k] = ((*fis_outputRange)[k] + (*fis_outputRange)[k +
                           fis_outputRange->size(0)]) / 2.0;
                } else {
                  r1[k] = (*outputSamplePoints)[k];
                }
              }

              vlen = r1.size(0);
              for (k = 0; k < vlen; k++) {
                y[k] = r1[k];
              }
            } else {
              vlen = inputs.size(1);
              b_inputs.set_size(1, inputs.size(1));
              for (k = 0; k < vlen; k++) {
                b_inputs[k] = inputs[k];
              }

              applySugenoImplicationMethod(b_inputs, w, fis->outputMF,
                fis->consequent, fis->numOutputs, fis->numRules,
                fis->numOutputMFs, fis->numCumOutputMFs, fis->orrSize, orr,
                unImpSugRuleOut);
              applySugenoAggregationMethod(orr, inputMFCache);
              vlen = fis->numOutputs;
              defuzzifiedOutputs.set_size(fis->numOutputs);
              for (k = 0; k < vlen; k++) {
                if (b_y == 0.0) {
                  defuzzifiedOutputs[k] = (fis->outputRange[k] +
                    fis->outputRange[k + fis->outputRange.size(0)]) / 2.0;
                } else {
                  defuzzifiedOutputs[k] = inputMFCache[k];
                }
              }

              vlen = defuzzifiedOutputs.size(0);
              for (k = 0; k < vlen; k++) {
                y[k] = defuzzifiedOutputs[k];
              }
            }
          } else {
            boolean_T b_bool;
            y.set_size(1, fis->numOutputs);
            c_y.set_size(1, fis->type.size(1));
            vlen = fis->type.size(1);
            for (int k = 0; k < vlen; k++) {
              c_y[k] = static_cast<signed char>(fis->type[k]);
            }

            b_bool = false;
            if (c_y.size(1) == 7) {
              vlen = 0;
              int exitg1;
              do {
                exitg1 = 0;
                if (vlen < 7) {
                  if (c_y[vlen] != cv[vlen]) {
                    exitg1 = 1;
                  } else {
                    vlen++;
                  }
                } else {
                  b_bool = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }

            if (b_bool) {
              createMamdaniOutputMFCache(fis->outputMF, fis->numOutputs,
                fis->numOutputMFs, fis->numCumOutputMFs, fis->outputSamplePoints,
                b_fis);
            }

            exit(0);
          }
        }
      }
    }
  }
}

//
// File trailer for evaluateFIS.cpp
//
// [EOF]
//
