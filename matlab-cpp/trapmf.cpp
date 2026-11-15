//
// File: trapmf.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "trapmf.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
//
// Arguments    : const double x_data[]
//                const int x_size[2]
//                const ::coder::array<double, 2U> &params
//                double y_data[]
//                int y_size[2]
// Return Type  : void
//
namespace coder
{
  void trapmf(const double x_data[], const int x_size[2], const ::coder::array<
              double, 2U> &params, double y_data[], int y_size[2])
  {
    double y1_data[51];
    double y2_data[51];
    double a;
    double b;
    double c;
    double d;
    int loop_ub;
    a = params[0];
    b = params[1];
    c = params[2];
    d = params[3];
    y_size[0] = 1;
    y_size[1] = static_cast<signed char>(x_size[1]);
    loop_ub = static_cast<signed char>(x_size[1]);
    if (0 <= loop_ub - 1) {
      std::memset(&y_data[0], 0, loop_ub * sizeof(double));
    }

    loop_ub = static_cast<signed char>(x_size[1]);
    if (0 <= loop_ub - 1) {
      std::memset(&y1_data[0], 0, loop_ub * sizeof(double));
    }

    loop_ub = static_cast<signed char>(x_size[1]);
    if (0 <= loop_ub - 1) {
      std::memset(&y2_data[0], 0, loop_ub * sizeof(double));
    }

    loop_ub = x_size[1];
    for (int i = 0; i < loop_ub; i++) {
      double b_d;
      double d1;
      b_d = x_data[i];
      if (b_d >= b) {
        y1_data[i] = 1.0;
      }

      if (b_d < a) {
        y1_data[i] = 0.0;
      }

      if ((a <= b_d) && (b_d < b) && (a != b)) {
        y1_data[i] = (b_d - a) * (1.0 / (b - a));
      }

      if (b_d <= c) {
        y2_data[i] = 1.0;
      }

      if (b_d > d) {
        y2_data[i] = 0.0;
      }

      if ((c < b_d) && (b_d <= d) && (c != d)) {
        y2_data[i] = (d - b_d) * (1.0 / (d - c));
      }

      b_d = y1_data[i];
      d1 = y2_data[i];
      if ((b_d < d1) || rtIsNaN(d1)) {
        y_data[i] = b_d;
      } else {
        y_data[i] = d1;
      }
    }
  }
}

//
// File trailer for trapmf.cpp
//
// [EOF]
//
