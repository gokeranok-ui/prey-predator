//
// File: pimf.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "pimf.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
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
  void pimf(const double x_data[], const int x_size[2], const ::coder::array<
            double, 2U> &params, double y_data[], int y_size[2])
  {
    double tmp_data[51];
    double d;
    double value;
    double x0;
    double x1;
    int i;
    int loop_ub;
    x0 = params[0];
    x1 = params[1];
    if (params[0] >= params[1]) {
      y_size[1] = x_size[1];
      x0 = (params[0] + params[1]) / 2.0;
      loop_ub = x_size[0] * x_size[1];
      for (i = 0; i < loop_ub; i++) {
        y_data[i] = (x_data[i] >= x0);
      }
    } else {
      y_size[1] = static_cast<signed char>(x_size[1]);
      loop_ub = static_cast<signed char>(x_size[1]);
      if (0 <= loop_ub - 1) {
        std::memset(&y_data[0], 0, loop_ub * sizeof(double));
      }

      i = x_size[1];
      for (loop_ub = 0; loop_ub < i; loop_ub++) {
        d = x_data[loop_ub];
        if ((x0 < d) && (d <= (x0 + x1) / 2.0)) {
          value = (d - x0) * (1.0 / (x1 - x0));
          y_data[loop_ub] = 2.0 * value * value;
        }

        if (((x0 + x1) / 2.0 < d) && (d <= x1)) {
          value = (x1 - d) * (1.0 / (x1 - x0));
          y_data[loop_ub] = 1.0 - 2.0 * value * value;
        }

        if (x1 <= d) {
          y_data[loop_ub] = 1.0;
        }
      }
    }

    x1 = params[2];
    x0 = params[3];
    if (params[2] >= params[3]) {
      x0 = (params[3] + params[2]) / 2.0;
      loop_ub = x_size[0] * x_size[1];
      for (i = 0; i < loop_ub; i++) {
        tmp_data[i] = (x_data[i] <= x0);
      }
    } else {
      loop_ub = static_cast<signed char>(x_size[1]);
      if (0 <= loop_ub - 1) {
        std::memset(&tmp_data[0], 0, loop_ub * sizeof(double));
      }

      i = x_size[1];
      for (loop_ub = 0; loop_ub < i; loop_ub++) {
        d = x_data[loop_ub];
        if (d <= x1) {
          tmp_data[loop_ub] = 1.0;
        }

        if ((x1 < d) && (d <= (x1 + x0) / 2.0)) {
          value = (d - x1) * (1.0 / (x1 - x0));
          tmp_data[loop_ub] = 1.0 - 2.0 * value * value;
        }

        if (((x1 + x0) / 2.0 < d) && (d <= x0)) {
          value = (x0 - d) * (1.0 / (x1 - x0));
          tmp_data[loop_ub] = 2.0 * value * value;
        }

        if (x0 <= d) {
          tmp_data[loop_ub] = 0.0;
        }
      }
    }

    y_size[0] = 1;
    loop_ub = y_size[1] - 1;
    for (i = 0; i <= loop_ub; i++) {
      y_data[i] *= tmp_data[i];
    }
  }
}

//
// File trailer for pimf.cpp
//
// [EOF]
//
