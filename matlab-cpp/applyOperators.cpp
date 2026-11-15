//
// File: applyOperators.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "applyOperators.h"
#include "isequal.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &fuzzifiedInputs
//                const ::coder::array<unsigned char, 2U> &fis_andMethod
//                const ::coder::array<unsigned char, 2U> &fis_orMethod
//                const ::coder::array<double, 2U> &fis_connection
//                const ::coder::array<double, 2U> &fis_weight
//                int fis_numInputs
//                int fis_numRules
//                ::coder::array<double, 1U> &varargin_1
//                ::coder::array<double, 1U> &varargin_2
// Return Type  : double
//
namespace coder
{
  namespace fuzzy
  {
    namespace internal
    {
      namespace codegen
      {
        double applyOperators(const ::coder::array<double, 2U> &fuzzifiedInputs,
                              const ::coder::array<unsigned char, 2U>
                              &fis_andMethod, const ::coder::array<unsigned char,
                              2U> &fis_orMethod, const ::coder::array<double, 2U>
                              &fis_connection, const ::coder::array<double, 2U>
                              &fis_weight, int fis_numInputs, int fis_numRules, ::
                              coder::array<double, 1U> &varargin_1, ::coder::
                              array<double, 1U> &varargin_2)
        {
          static const unsigned char uv2[6] = { 112U, 114U, 111U, 98U, 111U,
            114U };

          static const unsigned char uv3[4] = { 112U, 114U, 111U, 100U };

          static const unsigned char uv[3] = { 109U, 97U, 120U };

          static const unsigned char uv1[3] = { 109U, 105U, 110U };

          static const unsigned char uv4[3] = { 115U, 117U, 109U };

          double tmp_data[1];
          double sumAntecedentOutputs;
          double y;
          sumAntecedentOutputs = 0.0;
          for (int ruleID = 0; ruleID < fis_numRules; ruleID++) {
            int vlen;
            for (vlen = 0; vlen < fis_numInputs; vlen++) {
              varargin_2[vlen] = fuzzifiedInputs[ruleID + fuzzifiedInputs.size(0)
                * vlen];
            }

            if (fis_connection[ruleID] == 1.0) {
              y = -1.0;
              if (b_isequal(fis_andMethod, uv1)) {
                int n;
                n = varargin_2.size(0);
                if (varargin_2.size(0) <= 2) {
                  if (varargin_2.size(0) == 1) {
                    y = varargin_2[0];
                  } else if ((varargin_2[0] > varargin_2[1]) || (rtIsNaN
                              (varargin_2[0]) && (!rtIsNaN(varargin_2[1])))) {
                    y = varargin_2[1];
                  } else {
                    y = varargin_2[0];
                  }
                } else {
                  int k;
                  if (!rtIsNaN(varargin_2[0])) {
                    vlen = 1;
                  } else {
                    boolean_T exitg1;
                    vlen = 0;
                    k = 2;
                    exitg1 = false;
                    while ((!exitg1) && (k <= varargin_2.size(0))) {
                      if (!rtIsNaN(varargin_2[k - 1])) {
                        vlen = k;
                        exitg1 = true;
                      } else {
                        k++;
                      }
                    }
                  }

                  if (vlen == 0) {
                    y = varargin_2[0];
                  } else {
                    int i;
                    y = varargin_2[vlen - 1];
                    i = vlen + 1;
                    for (k = i; k <= n; k++) {
                      double d;
                      d = varargin_2[k - 1];
                      if (y > d) {
                        y = d;
                      }
                    }
                  }
                }
              } else if (c_isequal(fis_andMethod, uv3)) {
                vlen = varargin_2.size(0);
                if (varargin_2.size(0) == 0) {
                  y = 1.0;
                } else {
                  y = varargin_2[0];
                  for (int k = 2; k <= vlen; k++) {
                    y *= varargin_2[k - 1];
                  }
                }
              } else {
                exit(0);
              }

              varargin_1[ruleID] = y;
            } else {
              varargin_1[ruleID] = -1.0;
              if (b_isequal(fis_orMethod, uv)) {
                varargin_1[ruleID] = ::coder::internal::maximum(varargin_2);
              } else if (d_isequal(fis_orMethod, uv2)) {
                if (varargin_2.size(0) <= 1) {
                  vlen = varargin_2.size(0);
                  for (int i = 0; i < vlen; i++) {
                    tmp_data[i] = varargin_2[i];
                  }
                } else {
                  int i;
                  tmp_data[0] = varargin_2[0];
                  i = varargin_2.size(0);
                  for (vlen = 0; vlen <= i - 2; vlen++) {
                    y = varargin_2[vlen + 1];
                    for (int n = 0; n < 1; n++) {
                      tmp_data[0] = (tmp_data[0] + y) - tmp_data[0] * y;
                    }
                  }
                }

                varargin_1[ruleID] = tmp_data[0];
              } else if (b_isequal(fis_orMethod, uv4)) {
                vlen = varargin_2.size(0);
                if (varargin_2.size(0) == 0) {
                  y = 0.0;
                } else {
                  y = varargin_2[0];
                  for (int k = 2; k <= vlen; k++) {
                    y += varargin_2[k - 1];
                  }
                }

                varargin_1[ruleID] = y;
              } else {
                exit(0);
              }
            }

            varargin_1[ruleID] = varargin_1[ruleID] * fis_weight[ruleID];
            sumAntecedentOutputs += varargin_1[ruleID];
          }

          return sumAntecedentOutputs;
        }
      }
    }
  }
}

//
// File trailer for applyOperators.cpp
//
// [EOF]
//
