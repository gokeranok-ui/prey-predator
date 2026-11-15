//
// File: fuzzifyInputs.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "fuzzifyInputs.h"
#include "evaluateCommonMembershipFcn.h"
#include "opkene_internal_types.h"
#include "opkene_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double inputs
//                const ::coder::array<double, 2U> &fis_antecedent
//                const ::coder::array<double, 2U> &fis_connection
//                int fis_numRules
//                const ::coder::array<int, 2U> &fis_numInputMFs
//                const ::coder::array<int, 2U> &fis_numCumInputMFs
//                const ::coder::array<cell_wrap_0, 2U> &varargin_1
//                ::coder::array<double, 2U> &varargin_2
//                ::coder::array<double, 2U> &varargin_3
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
        void fuzzifyInputs(double inputs, const ::coder::array<double, 2U>
                           &fis_antecedent, const ::coder::array<double, 2U>
                           &fis_connection, int fis_numRules, const ::coder::
                           array<int, 2U> &fis_numInputMFs, const ::coder::array<
                           int, 2U> &fis_numCumInputMFs, const ::coder::array<
                           cell_wrap_0, 2U> &varargin_1, ::coder::array<double,
                           2U> &varargin_2, ::coder::array<double, 2U>
                           &varargin_3)
        {
          int inputID;
          int numMFs;
          int q0;
          numMFs = fis_numInputMFs[0];
          for (inputID = 0; inputID < 1; inputID++) {
            for (int mfID = 0; mfID < numMFs; mfID++) {
              q0 = fis_numCumInputMFs[0];
              if ((q0 < 0) && (mfID + 1 < MIN_int32_T - q0)) {
                q0 = MIN_int32_T;
              } else if ((q0 > 0) && (mfID + 1 > MAX_int32_T - q0)) {
                q0 = MAX_int32_T;
              } else {
                q0 = (q0 + mfID) + 1;
              }

              varargin_2[q0 - 1] = evaluateCommonMembershipFcn(varargin_1[0]
                .f1[mfID].type, inputs, varargin_1[0].f1[mfID].params);
            }
          }

          for (inputID = 0; inputID < fis_numRules; inputID++) {
            double d;
            d = rt_roundd_snf(std::abs(fis_antecedent[inputID]));
            if (d < 2.147483648E+9) {
              numMFs = static_cast<int>(d);
            } else if (d >= 2.147483648E+9) {
              numMFs = MAX_int32_T;
            } else {
              numMFs = 0;
            }

            if (numMFs == 0) {
              varargin_3[inputID] = (fis_connection[inputID] == 1.0);
            } else {
              if (fis_numCumInputMFs[0] < 0) {
                q0 = fis_numCumInputMFs[0];
                if (q0 <= MIN_int32_T) {
                  q0 = MAX_int32_T;
                } else {
                  q0 = -q0;
                }
              } else {
                q0 = fis_numCumInputMFs[0];
              }

              if ((q0 < 0) && (numMFs < MIN_int32_T - q0)) {
                q0 = MIN_int32_T;
              } else if ((q0 > 0) && (numMFs > MAX_int32_T - q0)) {
                q0 = MAX_int32_T;
              } else {
                q0 += numMFs;
              }

              varargin_3[inputID] = varargin_2[q0 - 1];
              if (fis_antecedent[inputID] < 0.0) {
                varargin_3[inputID] = 1.0 - varargin_3[inputID];
              }
            }
          }
        }

        //
        // Arguments    : const ::coder::array<double, 2U> &inputs
        //                const ::coder::array<double, 2U> &fis_antecedent
        //                const ::coder::array<double, 2U> &fis_connection
        //                int fis_numInputs
        //                int fis_numRules
        //                const ::coder::array<int, 2U> &fis_numInputMFs
        //                const ::coder::array<int, 2U> &fis_numCumInputMFs
        //                const ::coder::array<cell_wrap_0, 2U> &varargin_1
        //                ::coder::array<double, 2U> &varargin_2
        //                ::coder::array<double, 2U> &varargin_3
        // Return Type  : void
        //
        void fuzzifyInputs(const ::coder::array<double, 2U> &inputs, const ::
                           coder::array<double, 2U> &fis_antecedent, const ::
                           coder::array<double, 2U> &fis_connection, int
                           fis_numInputs, int fis_numRules, const ::coder::array<
                           int, 2U> &fis_numInputMFs, const ::coder::array<int,
                           2U> &fis_numCumInputMFs, const ::coder::array<
                           cell_wrap_0, 2U> &varargin_1, ::coder::array<double,
                           2U> &varargin_2, ::coder::array<double, 2U>
                           &varargin_3)
        {
          int inputID;
          int mfID;
          int numMFs;
          int q0;
          for (inputID = 0; inputID < fis_numInputs; inputID++) {
            numMFs = fis_numInputMFs[inputID];
            for (mfID = 0; mfID < numMFs; mfID++) {
              q0 = fis_numCumInputMFs[inputID];
              if ((q0 < 0) && (mfID + 1 < MIN_int32_T - q0)) {
                q0 = MIN_int32_T;
              } else if ((q0 > 0) && (mfID + 1 > MAX_int32_T - q0)) {
                q0 = MAX_int32_T;
              } else {
                q0 = (q0 + mfID) + 1;
              }

              varargin_2[q0 - 1] = evaluateCommonMembershipFcn
                (varargin_1[inputID].f1[mfID].type, inputs[inputID],
                 varargin_1[inputID].f1[mfID].params);
            }
          }

          for (mfID = 0; mfID < fis_numRules; mfID++) {
            for (inputID = 0; inputID < fis_numInputs; inputID++) {
              double d;
              double d1;
              d = fis_antecedent[mfID + fis_antecedent.size(0) * inputID];
              d1 = rt_roundd_snf(std::abs(d));
              if (d1 < 2.147483648E+9) {
                numMFs = static_cast<int>(d1);
              } else if (d1 >= 2.147483648E+9) {
                numMFs = MAX_int32_T;
              } else {
                numMFs = 0;
              }

              if (numMFs == 0) {
                varargin_3[mfID + varargin_3.size(0) * inputID] =
                  (fis_connection[mfID] == 1.0);
              } else {
                if (fis_numCumInputMFs[inputID] < 0) {
                  q0 = fis_numCumInputMFs[inputID];
                  if (q0 <= MIN_int32_T) {
                    q0 = MAX_int32_T;
                  } else {
                    q0 = -q0;
                  }
                } else {
                  q0 = fis_numCumInputMFs[inputID];
                }

                if ((q0 < 0) && (numMFs < MIN_int32_T - q0)) {
                  q0 = MIN_int32_T;
                } else if ((q0 > 0) && (numMFs > MAX_int32_T - q0)) {
                  q0 = MAX_int32_T;
                } else {
                  q0 += numMFs;
                }

                varargin_3[mfID + varargin_3.size(0) * inputID] = varargin_2[q0
                  - 1];
                if (d < 0.0) {
                  varargin_3[mfID + varargin_3.size(0) * inputID] = 1.0 -
                    varargin_3[mfID + varargin_3.size(0) * inputID];
                }
              }
            }
          }
        }
      }
    }
  }
}

//
// File trailer for fuzzifyInputs.cpp
//
// [EOF]
//
