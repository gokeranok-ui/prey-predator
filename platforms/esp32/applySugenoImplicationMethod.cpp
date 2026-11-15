//
// File: applySugenoImplicationMethod.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "applySugenoImplicationMethod.h"
#include "extractVarMF.h"
#include "isequal.h"
#include "opkene_internal_types.h"
#include "opkene_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : double inputs
//                const ::coder::array<double, 1U> &antecedentOutputs
//                const ::coder::array<e_struct_T, 2U> &fis_outputMF
//                const ::coder::array<double, 2U> &fis_consequent
//                int fis_numOutputs
//                int fis_numRules
//                const ::coder::array<int, 2U> &fis_numOutputMFs
//                const ::coder::array<int, 2U> &fis_numCumOutputMFs
//                const int fis_orrSize[2]
//                ::coder::array<double, 2U> &consequentOutputs
//                ::coder::array<double, 2U> &unscaledOutputs
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
        void applySugenoImplicationMethod(double inputs, const ::coder::array<
          double, 1U> &antecedentOutputs, const ::coder::array<e_struct_T, 2U>
          &fis_outputMF, const ::coder::array<double, 2U> &fis_consequent, int
          fis_numOutputs, int fis_numRules, const ::coder::array<int, 2U>
          &fis_numOutputMFs, const ::coder::array<int, 2U> &fis_numCumOutputMFs,
          const int fis_orrSize[2], ::coder::array<double, 2U>
          &consequentOutputs, ::coder::array<double, 2U> &unscaledOutputs)
        {
          static const unsigned char uv[8] = { 99U, 111U, 110U, 115U, 116U, 97U,
            110U, 116U };

          array<cell_wrap_0, 2U> outVarMF;
          array<double, 1U> outputMFCache;
          double y;
          int k;
          int mfID;
          int outputID;
          int vlen;
          consequentOutputs.set_size(fis_orrSize[0], fis_orrSize[1]);
          vlen = fis_orrSize[0] * fis_orrSize[1];
          unscaledOutputs.set_size(fis_orrSize[0], fis_orrSize[1]);
          for (k = 0; k < vlen; k++) {
            consequentOutputs[k] = 0.0;
            unscaledOutputs[k] = 0.0;
          }

          vlen = fis_numOutputMFs.size(1);
          if (fis_numOutputMFs.size(1) == 0) {
            y = 0.0;
          } else {
            y = fis_numOutputMFs[0];
            for (k = 2; k <= vlen; k++) {
              y += static_cast<double>(fis_numOutputMFs[k - 1]);
            }
          }

          outputMFCache.set_size((static_cast<int>(y)));
          vlen = static_cast<int>(y);
          for (k = 0; k < vlen; k++) {
            outputMFCache[k] = 0.0;
          }

          extractVarMF(fis_outputMF, outVarMF);
          for (outputID = 0; outputID < fis_numOutputs; outputID++) {
            vlen = fis_numOutputMFs[outputID];
            for (mfID = 0; mfID < vlen; mfID++) {
              if (e_isequal(outVarMF[outputID].f1[mfID].type, uv)) {
                k = fis_numCumOutputMFs[outputID];
                if ((k < 0) && (mfID + 1 < MIN_int32_T - k)) {
                  k = MIN_int32_T;
                } else if ((k > 0) && (mfID + 1 > MAX_int32_T - k)) {
                  k = MAX_int32_T;
                } else {
                  k = (k + mfID) + 1;
                }

                outputMFCache[k - 1] = outVarMF[outputID].f1[mfID].params[0];
              } else {
                k = fis_numCumOutputMFs[outputID];
                if ((k < 0) && (mfID + 1 < MIN_int32_T - k)) {
                  k = MIN_int32_T;
                } else if ((k > 0) && (mfID + 1 > MAX_int32_T - k)) {
                  k = MAX_int32_T;
                } else {
                  k = (k + mfID) + 1;
                }

                outputMFCache[k - 1] = inputs * outVarMF[outputID].f1[mfID].
                  params[0] + outVarMF[outputID].f1[mfID].params[1];
              }
            }
          }

          for (mfID = 0; mfID < fis_numRules; mfID++) {
            for (outputID = 0; outputID < fis_numOutputs; outputID++) {
              y = rt_roundd_snf(fis_consequent[mfID + fis_consequent.size(0) *
                                outputID]);
              if (y < 2.147483648E+9) {
                if (y >= -2.147483648E+9) {
                  vlen = static_cast<int>(y);
                } else {
                  vlen = MIN_int32_T;
                }
              } else if (y >= 2.147483648E+9) {
                vlen = MAX_int32_T;
              } else {
                vlen = 0;
              }

              if (vlen != 0) {
                k = fis_numCumOutputMFs[outputID];
                if ((k < 0) && (vlen < MIN_int32_T - k)) {
                  k = MIN_int32_T;
                } else if ((k > 0) && (vlen > MAX_int32_T - k)) {
                  k = MAX_int32_T;
                } else {
                  k += vlen;
                }

                unscaledOutputs[mfID + unscaledOutputs.size(0) * outputID] =
                  outputMFCache[k - 1];
                k = fis_numCumOutputMFs[outputID];
                if ((k < 0) && (vlen < MIN_int32_T - k)) {
                  k = MIN_int32_T;
                } else if ((k > 0) && (vlen > MAX_int32_T - k)) {
                  k = MAX_int32_T;
                } else {
                  k += vlen;
                }

                consequentOutputs[mfID + consequentOutputs.size(0) * outputID] =
                  outputMFCache[k - 1] * antecedentOutputs[mfID];
              }
            }
          }
        }

        //
        // Arguments    : const ::coder::array<double, 2U> &inputs
        //                const ::coder::array<double, 1U> &antecedentOutputs
        //                const ::coder::array<e_struct_T, 2U> &fis_outputMF
        //                const ::coder::array<double, 2U> &fis_consequent
        //                int fis_numOutputs
        //                int fis_numRules
        //                const ::coder::array<int, 2U> &fis_numOutputMFs
        //                const ::coder::array<int, 2U> &fis_numCumOutputMFs
        //                const int fis_orrSize[2]
        //                ::coder::array<double, 2U> &consequentOutputs
        //                ::coder::array<double, 2U> &unscaledOutputs
        // Return Type  : void
        //
        void applySugenoImplicationMethod(const ::coder::array<double, 2U>
          &inputs, const ::coder::array<double, 1U> &antecedentOutputs, const ::
          coder::array<e_struct_T, 2U> &fis_outputMF, const ::coder::array<
          double, 2U> &fis_consequent, int fis_numOutputs, int fis_numRules,
          const ::coder::array<int, 2U> &fis_numOutputMFs, const ::coder::array<
          int, 2U> &fis_numCumOutputMFs, const int fis_orrSize[2], ::coder::
          array<double, 2U> &consequentOutputs, ::coder::array<double, 2U>
          &unscaledOutputs)
        {
          static const unsigned char uv[8] = { 99U, 111U, 110U, 115U, 116U, 97U,
            110U, 116U };

          array<cell_wrap_0, 2U> outVarMF;
          array<double, 1U> outputMFCache;
          double y;
          int k;
          int outputID;
          int ruleID;
          int vlen;
          consequentOutputs.set_size(fis_orrSize[0], fis_orrSize[1]);
          vlen = fis_orrSize[0] * fis_orrSize[1];
          unscaledOutputs.set_size(fis_orrSize[0], fis_orrSize[1]);
          for (ruleID = 0; ruleID < vlen; ruleID++) {
            consequentOutputs[ruleID] = 0.0;
            unscaledOutputs[ruleID] = 0.0;
          }

          vlen = fis_numOutputMFs.size(1);
          if (fis_numOutputMFs.size(1) == 0) {
            y = 0.0;
          } else {
            y = fis_numOutputMFs[0];
            for (k = 2; k <= vlen; k++) {
              y += static_cast<double>(fis_numOutputMFs[k - 1]);
            }
          }

          outputMFCache.set_size((static_cast<int>(y)));
          vlen = static_cast<int>(y);
          for (ruleID = 0; ruleID < vlen; ruleID++) {
            outputMFCache[ruleID] = 0.0;
          }

          extractVarMF(fis_outputMF, outVarMF);
          for (outputID = 0; outputID < fis_numOutputs; outputID++) {
            vlen = fis_numOutputMFs[outputID];
            for (int mfID = 0; mfID < vlen; mfID++) {
              if (e_isequal(outVarMF[outputID].f1[mfID].type, uv)) {
                k = fis_numCumOutputMFs[outputID];
                if ((k < 0) && (mfID + 1 < MIN_int32_T - k)) {
                  k = MIN_int32_T;
                } else if ((k > 0) && (mfID + 1 > MAX_int32_T - k)) {
                  k = MAX_int32_T;
                } else {
                  k = (k + mfID) + 1;
                }

                outputMFCache[k - 1] = outVarMF[outputID].f1[mfID].params[0];
              } else {
                y = 0.0;
                ruleID = inputs.size(1);
                for (k = 0; k < ruleID; k++) {
                  y += inputs[k] * outVarMF[outputID].f1[mfID].params[k];
                }

                k = fis_numCumOutputMFs[outputID];
                if ((k < 0) && (mfID + 1 < MIN_int32_T - k)) {
                  k = MIN_int32_T;
                } else if ((k > 0) && (mfID + 1 > MAX_int32_T - k)) {
                  k = MAX_int32_T;
                } else {
                  k = (k + mfID) + 1;
                }

                outputMFCache[k - 1] = y + outVarMF[outputID].f1[mfID]
                  .params[inputs.size(1)];
              }
            }
          }

          for (ruleID = 0; ruleID < fis_numRules; ruleID++) {
            for (outputID = 0; outputID < fis_numOutputs; outputID++) {
              y = rt_roundd_snf(fis_consequent[ruleID + fis_consequent.size(0) *
                                outputID]);
              if (y < 2.147483648E+9) {
                if (y >= -2.147483648E+9) {
                  vlen = static_cast<int>(y);
                } else {
                  vlen = MIN_int32_T;
                }
              } else if (y >= 2.147483648E+9) {
                vlen = MAX_int32_T;
              } else {
                vlen = 0;
              }

              if (vlen != 0) {
                k = fis_numCumOutputMFs[outputID];
                if ((k < 0) && (vlen < MIN_int32_T - k)) {
                  k = MIN_int32_T;
                } else if ((k > 0) && (vlen > MAX_int32_T - k)) {
                  k = MAX_int32_T;
                } else {
                  k += vlen;
                }

                unscaledOutputs[ruleID + unscaledOutputs.size(0) * outputID] =
                  outputMFCache[k - 1];
                k = fis_numCumOutputMFs[outputID];
                if ((k < 0) && (vlen < MIN_int32_T - k)) {
                  k = MIN_int32_T;
                } else if ((k > 0) && (vlen > MAX_int32_T - k)) {
                  k = MAX_int32_T;
                } else {
                  k += vlen;
                }

                consequentOutputs[ruleID + consequentOutputs.size(0) * outputID]
                  = outputMFCache[k - 1] * antecedentOutputs[ruleID];
              }
            }
          }
        }
      }
    }
  }
}

//
// File trailer for applySugenoImplicationMethod.cpp
//
// [EOF]
//
