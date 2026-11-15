//
// File: applyMamdaniImplicationMethod.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "applyMamdaniImplicationMethod.h"
#include "isequal.h"
#include "minOrMax.h"
#include "opkene_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &antecedentOutputs
//                const ::coder::array<unsigned char, 2U> &fis_impMethod
//                const ::coder::array<double, 2U> &fis_consequent
//                int fis_numOutputs
//                int fis_numRules
//                const ::coder::array<int, 2U> &fis_numCumOutputMFs
//                const int fis_orrSize[2]
//                const ::coder::array<double, 2U> &varargin_1
//                ::coder::array<double, 2U> &consequentOutputs
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
        void applyMamdaniImplicationMethod(const ::coder::array<double, 1U>
          &antecedentOutputs, const ::coder::array<unsigned char, 2U>
          &fis_impMethod, const ::coder::array<double, 2U> &fis_consequent, int
          fis_numOutputs, int fis_numRules, const ::coder::array<int, 2U>
          &fis_numCumOutputMFs, const int fis_orrSize[2], const ::coder::array<
          double, 2U> &varargin_1, ::coder::array<double, 2U> &consequentOutputs)
        {
          static const unsigned char uv1[4] = { 112U, 114U, 111U, 100U };

          static const unsigned char uv[3] = { 109U, 105U, 110U };

          double x[2];
          int loop_ub;
          if (b_isequal(fis_impMethod, uv)) {
            consequentOutputs.set_size(fis_orrSize[0], fis_orrSize[1]);
            for (int outputID = 0; outputID < fis_numOutputs; outputID++) {
              long long i1;
              int qY;
              if (outputID + 1 < -2147483647) {
                qY = MIN_int32_T;
              } else {
                qY = outputID;
              }

              i1 = static_cast<long long>(qY) * fis_numRules;
              if (i1 > 2147483647LL) {
                i1 = 2147483647LL;
              } else {
                if (i1 < -2147483648LL) {
                  i1 = -2147483648LL;
                }
              }

              for (int ruleID = 0; ruleID < fis_numRules; ruleID++) {
                double d;
                int q1;
                d = rt_roundd_snf(std::abs(fis_consequent[ruleID +
                  fis_consequent.size(0) * outputID]));
                if (d < 2.147483648E+9) {
                  q1 = static_cast<int>(d);
                } else if (d >= 2.147483648E+9) {
                  q1 = MAX_int32_T;
                } else {
                  q1 = 0;
                }

                if ((static_cast<int>(i1) < 0) && (ruleID + 1 < MIN_int32_T -
                     static_cast<int>(i1))) {
                  qY = MIN_int32_T;
                } else if ((static_cast<int>(i1) > 0) && (ruleID + 1 >
                            MAX_int32_T - static_cast<int>(i1))) {
                  qY = MAX_int32_T;
                } else {
                  qY = (static_cast<int>(i1) + ruleID) + 1;
                }

                if (q1 == 0) {
                  loop_ub = consequentOutputs.size(0);
                  for (int i = 0; i < loop_ub; i++) {
                    consequentOutputs[i + consequentOutputs.size(0) * (qY - 1)] =
                      0.0;
                  }
                } else {
                  if (fis_numCumOutputMFs[outputID] < 0) {
                    int i;
                    i = fis_numCumOutputMFs[outputID];
                    if (i <= MIN_int32_T) {
                      loop_ub = MAX_int32_T;
                    } else {
                      loop_ub = -i;
                    }
                  } else {
                    loop_ub = fis_numCumOutputMFs[outputID];
                  }

                  if ((loop_ub < 0) && (q1 < MIN_int32_T - loop_ub)) {
                    loop_ub = MIN_int32_T;
                  } else if ((loop_ub > 0) && (q1 > MAX_int32_T - loop_ub)) {
                    loop_ub = MAX_int32_T;
                  } else {
                    loop_ub += q1;
                  }

                  for (q1 = 0; q1 < 51; q1++) {
                    consequentOutputs[q1 + consequentOutputs.size(0) * (qY - 1)]
                      = varargin_1[(loop_ub + varargin_1.size(0) * q1) - 1];
                    if (fis_consequent[ruleID + fis_consequent.size(0) *
                        outputID] < 0.0) {
                      x[0] = 0.0;
                      x[1] = 1.0 - consequentOutputs[q1 + consequentOutputs.size
                        (0) * (qY - 1)];
                      consequentOutputs[q1 + consequentOutputs.size(0) * (qY - 1)]
                        = ::coder::internal::maximum(x);
                    }

                    x[0] = consequentOutputs[q1 + consequentOutputs.size(0) *
                      (qY - 1)];
                    if ((x[0] > antecedentOutputs[ruleID]) || (rtIsNaN(x[0]) &&
                         (!rtIsNaN(antecedentOutputs[ruleID])))) {
                      consequentOutputs[q1 + consequentOutputs.size(0) * (qY - 1)]
                        = antecedentOutputs[ruleID];
                    } else {
                      consequentOutputs[q1 + consequentOutputs.size(0) * (qY - 1)]
                        = x[0];
                    }
                  }
                }
              }
            }
          } else if (c_isequal(fis_impMethod, uv1)) {
            consequentOutputs.set_size(fis_orrSize[0], fis_orrSize[1]);
            for (int outputID = 0; outputID < fis_numOutputs; outputID++) {
              long long i1;
              int qY;
              if (outputID + 1 < -2147483647) {
                qY = MIN_int32_T;
              } else {
                qY = outputID;
              }

              i1 = static_cast<long long>(qY) * fis_numRules;
              if (i1 > 2147483647LL) {
                i1 = 2147483647LL;
              } else {
                if (i1 < -2147483648LL) {
                  i1 = -2147483648LL;
                }
              }

              for (int ruleID = 0; ruleID < fis_numRules; ruleID++) {
                double d;
                int q1;
                d = rt_roundd_snf(std::abs(fis_consequent[ruleID +
                  fis_consequent.size(0) * outputID]));
                if (d < 2.147483648E+9) {
                  q1 = static_cast<int>(d);
                } else if (d >= 2.147483648E+9) {
                  q1 = MAX_int32_T;
                } else {
                  q1 = 0;
                }

                if ((static_cast<int>(i1) < 0) && (ruleID + 1 < MIN_int32_T -
                     static_cast<int>(i1))) {
                  qY = MIN_int32_T;
                } else if ((static_cast<int>(i1) > 0) && (ruleID + 1 >
                            MAX_int32_T - static_cast<int>(i1))) {
                  qY = MAX_int32_T;
                } else {
                  qY = (static_cast<int>(i1) + ruleID) + 1;
                }

                if (q1 == 0) {
                  loop_ub = consequentOutputs.size(0);
                  for (int i = 0; i < loop_ub; i++) {
                    consequentOutputs[i + consequentOutputs.size(0) * (qY - 1)] =
                      0.0;
                  }
                } else {
                  if (fis_numCumOutputMFs[outputID] < 0) {
                    int i;
                    i = fis_numCumOutputMFs[outputID];
                    if (i <= MIN_int32_T) {
                      loop_ub = MAX_int32_T;
                    } else {
                      loop_ub = -i;
                    }
                  } else {
                    loop_ub = fis_numCumOutputMFs[outputID];
                  }

                  if ((loop_ub < 0) && (q1 < MIN_int32_T - loop_ub)) {
                    loop_ub = MIN_int32_T;
                  } else if ((loop_ub > 0) && (q1 > MAX_int32_T - loop_ub)) {
                    loop_ub = MAX_int32_T;
                  } else {
                    loop_ub += q1;
                  }

                  for (q1 = 0; q1 < 51; q1++) {
                    consequentOutputs[q1 + consequentOutputs.size(0) * (qY - 1)]
                      = varargin_1[(loop_ub + varargin_1.size(0) * q1) - 1];
                    if (fis_consequent[ruleID + fis_consequent.size(0) *
                        outputID] < 0.0) {
                      x[0] = 0.0;
                      x[1] = 1.0 - consequentOutputs[q1 + consequentOutputs.size
                        (0) * (qY - 1)];
                      consequentOutputs[q1 + consequentOutputs.size(0) * (qY - 1)]
                        = ::coder::internal::maximum(x);
                    }

                    consequentOutputs[q1 + consequentOutputs.size(0) * (qY - 1)]
                      = consequentOutputs[q1 + consequentOutputs.size(0) * (qY -
                      1)] * antecedentOutputs[ruleID];
                  }
                }
              }
            }
          } else {
            consequentOutputs.set_size(fis_orrSize[0], fis_orrSize[1]);
            loop_ub = fis_orrSize[0] * fis_orrSize[1];
            for (int i = 0; i < loop_ub; i++) {
              consequentOutputs[i] = 0.0;
            }

            exit(0);
          }
        }
      }
    }
  }
}

//
// File trailer for applyMamdaniImplicationMethod.cpp
//
// [EOF]
//
