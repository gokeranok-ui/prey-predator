//
// File: evaluateCommonMembershipFcn.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "evaluateCommonMembershipFcn.h"
#include "isequal.h"
#include "opkene_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<char, 2U> &mfType
//                double x
//                const ::coder::array<double, 2U> &params
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
        double evaluateCommonMembershipFcn(const ::coder::array<char, 2U>
          &mfType, double x, const ::coder::array<double, 2U> &params)
        {
          static const unsigned char uv7[8] = { 103U, 97U, 117U, 115U, 115U, 50U,
            109U, 102U };

          static const unsigned char uv2[7] = { 103U, 97U, 117U, 115U, 115U,
            109U, 102U };

          static const unsigned char uv3[7] = { 103U, 98U, 101U, 108U, 108U,
            109U, 102U };

          static const unsigned char uv1[6] = { 116U, 114U, 97U, 112U, 109U,
            102U };

          static const unsigned char uv8[6] = { 100U, 115U, 105U, 103U, 109U,
            102U };

          static const unsigned char uv9[6] = { 112U, 115U, 105U, 103U, 109U,
            102U };

          static const unsigned char uv[5] = { 116U, 114U, 105U, 109U, 102U };

          static const unsigned char uv4[5] = { 115U, 105U, 103U, 109U, 102U };

          static const unsigned char uv10[4] = { 112U, 105U, 109U, 102U };

          static const unsigned char uv5[3] = { 115U, 109U, 102U };

          static const unsigned char uv6[3] = { 122U, 109U, 102U };

          double value;
          double y;
          y = -1.0;
          if (isequal(mfType, uv)) {
            y = 0.0;
            if ((params[0] != params[1]) && (params[0] < x) && (x < params[1]))
            {
              y = (x - params[0]) * (1.0 / (params[1] - params[0]));
            }

            if ((params[1] != params[2]) && (params[1] < x) && (x < params[2]))
            {
              y = (params[2] - x) * (1.0 / (params[2] - params[1]));
            }

            if (x == params[1]) {
              y = 1.0;
            }
          } else if (b_isequal(mfType, uv1)) {
            value = 0.0;
            y = 0.0;
            if (x >= params[1]) {
              value = 1.0;
            }

            if (x < params[0]) {
              value = 0.0;
            }

            if ((params[0] <= x) && (x < params[1]) && (params[0] != params[1]))
            {
              value = (x - params[0]) * (1.0 / (params[1] - params[0]));
            }

            if (x <= params[2]) {
              y = 1.0;
            }

            if (x > params[3]) {
              y = 0.0;
            }

            if ((params[2] < x) && (x <= params[3]) && (params[2] != params[3]))
            {
              y = (params[3] - x) * (1.0 / (params[3] - params[2]));
            }

            if ((value < y) || rtIsNaN(y)) {
              y = value;
            }
          } else if (c_isequal(mfType, uv2)) {
            value = x - params[1];
            y = std::exp(-(value * value) / (2.0 * (params[0] * params[0])));
          } else if (c_isequal(mfType, uv3)) {
            y = 0.0;
            value = (x - params[2]) * (1.0 / params[0]);
            value *= value;
            if ((value <= 0.0) && (params[1] == 0.0)) {
              y = 0.5;
            } else {
              if ((!(value <= 0.0)) || (!(params[1] < 0.0))) {
                value = rt_powd_snf(value, params[1]);
                y = 1.0 / (value + 1.0);
              }
            }
          } else if (isequal(mfType, uv4)) {
            y = 1.0 / (std::exp(-params[0] * (x - params[1])) + 1.0);
          } else if (d_isequal(mfType, uv5)) {
            if (params[0] >= params[1]) {
              y = (x >= (params[0] + params[1]) / 2.0);
            } else {
              y = 0.0;
              if ((params[0] < x) && (x <= (params[0] + params[1]) / 2.0)) {
                value = (x - params[0]) * (1.0 / (params[1] - params[0]));
                y = 2.0 * value * value;
              }

              if (((params[0] + params[1]) / 2.0 < x) && (x <= params[1])) {
                value = (params[1] - x) * (1.0 / (params[1] - params[0]));
                y = 1.0 - 2.0 * value * value;
              }

              if (params[1] <= x) {
                y = 1.0;
              }
            }
          } else if (d_isequal(mfType, uv6)) {
            if (params[0] >= params[1]) {
              y = (x <= (params[1] + params[0]) / 2.0);
            } else {
              y = 0.0;
              if (x <= params[0]) {
                y = 1.0;
              }

              if ((params[0] < x) && (x <= (params[0] + params[1]) / 2.0)) {
                value = (x - params[0]) * (1.0 / (params[0] - params[1]));
                y = 1.0 - 2.0 * value * value;
              }

              if (((params[0] + params[1]) / 2.0 < x) && (x <= params[1])) {
                value = (params[1] - x) * (1.0 / (params[0] - params[1]));
                y = 2.0 * value * value;
              }

              if (params[1] <= x) {
                y = 0.0;
              }
            }
          } else if (e_isequal(mfType, uv7)) {
            boolean_T c1Index;
            boolean_T c2Index;
            c1Index = (x <= params[1]);
            c2Index = (x >= params[3]);
            value = x - params[1];
            y = x - params[3];
            y = (std::exp(-(value * value) / (2.0 * (params[0] * params[0]))) *
                 static_cast<double>(c1Index) + (1.0 - static_cast<double>
                  (c1Index))) * (std::exp(-(y * y) / (2.0 * (params[2] * params
              [2]))) * static_cast<double>(c2Index) + (1.0 - static_cast<double>
              (c2Index)));
          } else if (b_isequal(mfType, uv8)) {
            y = std::abs(1.0 / (std::exp(-params[0] * (x - params[1])) + 1.0) -
                         1.0 / (std::exp(-params[2] * (x - params[3])) + 1.0));
          } else if (b_isequal(mfType, uv9)) {
            y = 1.0 / (std::exp(-params[0] * (x - params[1])) + 1.0) * (1.0 /
              (std::exp(-params[2] * (x - params[3])) + 1.0));
          } else if (f_isequal(mfType, uv10)) {
            if (params[0] >= params[1]) {
              y = (x >= (params[0] + params[1]) / 2.0);
            } else {
              y = 0.0;
              if ((params[0] < x) && (x <= (params[0] + params[1]) / 2.0)) {
                value = (x - params[0]) * (1.0 / (params[1] - params[0]));
                y = 2.0 * value * value;
              }

              if (((params[0] + params[1]) / 2.0 < x) && (x <= params[1])) {
                value = (params[1] - x) * (1.0 / (params[1] - params[0]));
                y = 1.0 - 2.0 * value * value;
              }

              if (params[1] <= x) {
                y = 1.0;
              }
            }

            if (params[2] >= params[3]) {
              value = (x <= (params[3] + params[2]) / 2.0);
            } else {
              value = 0.0;
              if (x <= params[2]) {
                value = 1.0;
              }

              if ((params[2] < x) && (x <= (params[2] + params[3]) / 2.0)) {
                value = (x - params[2]) * (1.0 / (params[2] - params[3]));
                value = 1.0 - 2.0 * value * value;
              }

              if (((params[2] + params[3]) / 2.0 < x) && (x <= params[3])) {
                value = (params[3] - x) * (1.0 / (params[2] - params[3]));
                value *= 2.0 * value;
              }

              if (params[3] <= x) {
                value = 0.0;
              }
            }

            y *= value;
          } else {
            exit(0);
          }

          return y;
        }
      }
    }
  }
}

//
// File trailer for evaluateCommonMembershipFcn.cpp
//
// [EOF]
//
