//
// File: applyMamdaniAggregationMethod.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "applyMamdaniAggregationMethod.h"
#include "isequal.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &consequentOutputs
//                const ::coder::array<unsigned char, 2U> &fis_aggMethod
//                int fis_numOutputs
//                int fis_numRules
//                const int fis_aggSize[2]
//                ::coder::array<double, 2U> &aggregatedOutputs
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
        void applyMamdaniAggregationMethod(const ::coder::array<double, 2U>
          &consequentOutputs, const ::coder::array<unsigned char, 2U>
          &fis_aggMethod, int fis_numOutputs, int fis_numRules, const int
          fis_aggSize[2], ::coder::array<double, 2U> &aggregatedOutputs)
        {
          static const unsigned char uv1[6] = { 112U, 114U, 111U, 98U, 111U,
            114U };

          static const unsigned char uv[3] = { 109U, 97U, 120U };

          static const unsigned char uv2[3] = { 115U, 117U, 109U };

          double x[2];
          double aggVal;
          if (b_isequal(fis_aggMethod, uv)) {
            aggregatedOutputs.set_size(fis_aggSize[0], fis_aggSize[1]);
            for (int outputID = 0; outputID < fis_numOutputs; outputID++) {
              long long i;
              int b_qY;
              int loop_ub;
              int qY;
              if (outputID + 1 < -2147483647) {
                loop_ub = MIN_int32_T;
              } else {
                loop_ub = outputID;
              }

              i = static_cast<long long>(loop_ub) * fis_numRules;
              if (i > 2147483647LL) {
                i = 2147483647LL;
              } else {
                if (i < -2147483648LL) {
                  i = -2147483648LL;
                }
              }

              if (static_cast<int>(i) > 2147483646) {
                loop_ub = MAX_int32_T;
              } else {
                loop_ub = static_cast<int>(i) + 1;
              }

              if ((static_cast<int>(i) < 0) && (fis_numRules < MIN_int32_T -
                   static_cast<int>(i))) {
                qY = MIN_int32_T;
              } else if ((static_cast<int>(i) > 0) && (fis_numRules >
                          MAX_int32_T - static_cast<int>(i))) {
                qY = MAX_int32_T;
              } else {
                qY = static_cast<int>(i) + fis_numRules;
              }

              if (loop_ub > 2147483646) {
                b_qY = MAX_int32_T;
              } else {
                b_qY = loop_ub + 1;
              }

              for (int sampleID = 0; sampleID < 51; sampleID++) {
                aggVal = consequentOutputs[sampleID + consequentOutputs.size(0) *
                  (loop_ub - 1)];
                for (int id = b_qY; id <= qY; id++) {
                  x[0] = aggVal;
                  x[1] = consequentOutputs[sampleID + consequentOutputs.size(0) *
                    (id - 1)];
                  aggVal = ::coder::internal::maximum(x);
                }

                aggregatedOutputs[sampleID + aggregatedOutputs.size(0) *
                  outputID] = aggVal;
              }
            }
          } else if (d_isequal(fis_aggMethod, uv1)) {
            aggregatedOutputs.set_size(fis_aggSize[0], fis_aggSize[1]);
            for (int outputID = 0; outputID < fis_numOutputs; outputID++) {
              long long i;
              int b_qY;
              int loop_ub;
              int qY;
              if (outputID + 1 < -2147483647) {
                loop_ub = MIN_int32_T;
              } else {
                loop_ub = outputID;
              }

              i = static_cast<long long>(loop_ub) * fis_numRules;
              if (i > 2147483647LL) {
                i = 2147483647LL;
              } else {
                if (i < -2147483648LL) {
                  i = -2147483648LL;
                }
              }

              if (static_cast<int>(i) > 2147483646) {
                loop_ub = MAX_int32_T;
              } else {
                loop_ub = static_cast<int>(i) + 1;
              }

              if ((static_cast<int>(i) < 0) && (fis_numRules < MIN_int32_T -
                   static_cast<int>(i))) {
                qY = MIN_int32_T;
              } else if ((static_cast<int>(i) > 0) && (fis_numRules >
                          MAX_int32_T - static_cast<int>(i))) {
                qY = MAX_int32_T;
              } else {
                qY = static_cast<int>(i) + fis_numRules;
              }

              if (loop_ub > 2147483646) {
                b_qY = MAX_int32_T;
              } else {
                b_qY = loop_ub + 1;
              }

              for (int sampleID = 0; sampleID < 51; sampleID++) {
                aggVal = consequentOutputs[sampleID + consequentOutputs.size(0) *
                  (loop_ub - 1)];
                for (int id = b_qY; id <= qY; id++) {
                  x[1] = consequentOutputs[sampleID + consequentOutputs.size(0) *
                    (id - 1)];
                  aggVal = (aggVal + x[1]) - aggVal * x[1];
                }

                aggregatedOutputs[sampleID + aggregatedOutputs.size(0) *
                  outputID] = aggVal;
              }
            }
          } else if (b_isequal(fis_aggMethod, uv2)) {
            aggregatedOutputs.set_size(fis_aggSize[0], fis_aggSize[1]);
            for (int outputID = 0; outputID < fis_numOutputs; outputID++) {
              long long i;
              int b_qY;
              int loop_ub;
              int qY;
              if (outputID + 1 < -2147483647) {
                loop_ub = MIN_int32_T;
              } else {
                loop_ub = outputID;
              }

              i = static_cast<long long>(loop_ub) * fis_numRules;
              if (i > 2147483647LL) {
                i = 2147483647LL;
              } else {
                if (i < -2147483648LL) {
                  i = -2147483648LL;
                }
              }

              if (static_cast<int>(i) > 2147483646) {
                loop_ub = MAX_int32_T;
              } else {
                loop_ub = static_cast<int>(i) + 1;
              }

              if ((static_cast<int>(i) < 0) && (fis_numRules < MIN_int32_T -
                   static_cast<int>(i))) {
                qY = MIN_int32_T;
              } else if ((static_cast<int>(i) > 0) && (fis_numRules >
                          MAX_int32_T - static_cast<int>(i))) {
                qY = MAX_int32_T;
              } else {
                qY = static_cast<int>(i) + fis_numRules;
              }

              if (loop_ub > 2147483646) {
                b_qY = MAX_int32_T;
              } else {
                b_qY = loop_ub + 1;
              }

              for (int sampleID = 0; sampleID < 51; sampleID++) {
                aggVal = consequentOutputs[sampleID + consequentOutputs.size(0) *
                  (loop_ub - 1)];
                for (int id = b_qY; id <= qY; id++) {
                  aggVal += consequentOutputs[sampleID + consequentOutputs.size
                    (0) * (id - 1)];
                }

                aggregatedOutputs[sampleID + aggregatedOutputs.size(0) *
                  outputID] = aggVal;
              }
            }
          } else {
            int loop_ub;
            aggregatedOutputs.set_size(fis_aggSize[0], fis_aggSize[1]);
            loop_ub = fis_aggSize[0] * fis_aggSize[1];
            for (int qY = 0; qY < loop_ub; qY++) {
              aggregatedOutputs[qY] = 0.0;
            }

            exit(0);
          }
        }
      }
    }
  }
}

//
// File trailer for applyMamdaniAggregationMethod.cpp
//
// [EOF]
//
