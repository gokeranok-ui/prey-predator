//
// File: gauss2mf.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "gauss2mf.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

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
  void gauss2mf(const double x_data[], const int x_size[2], const ::coder::array<
                double, 2U> &params, double y_data[], int y_size[2])
  {
    double a_data[51];
    double b_y_data[51];
    double b_params;
    int k;
    int loop_ub_tmp;
    int nx;
    boolean_T c1Index_data[51];
    boolean_T c2Index_data[51];
    b_params = params[1];
    loop_ub_tmp = x_size[0] * x_size[1];
    for (k = 0; k < loop_ub_tmp; k++) {
      c1Index_data[k] = (x_data[k] <= b_params);
    }

    b_params = params[3];
    for (k = 0; k < loop_ub_tmp; k++) {
      c2Index_data[k] = (x_data[k] >= b_params);
    }

    b_params = params[1];
    for (k = 0; k < loop_ub_tmp; k++) {
      a_data[k] = x_data[k] - b_params;
    }

    y_size[1] = static_cast<signed char>(x_size[1]);
    nx = static_cast<signed char>(x_size[1]);
    for (k = 0; k < nx; k++) {
      b_params = a_data[k];
      y_data[k] = b_params * b_params;
    }

    b_params = 2.0 * (params[0] * params[0]);
    nx = static_cast<signed char>(x_size[1]) - 1;
    for (k = 0; k <= nx; k++) {
      y_data[k] = -y_data[k] / b_params;
    }

    nx = static_cast<signed char>(x_size[1]);
    for (k = 0; k < nx; k++) {
      y_data[k] = std::exp(y_data[k]);
    }

    b_params = params[3];
    for (k = 0; k < loop_ub_tmp; k++) {
      a_data[k] = x_data[k] - b_params;
    }

    loop_ub_tmp = static_cast<signed char>(x_size[1]);
    nx = static_cast<signed char>(x_size[1]);
    for (k = 0; k < nx; k++) {
      b_params = a_data[k];
      b_y_data[k] = b_params * b_params;
    }

    b_params = 2.0 * (params[2] * params[2]);
    nx = static_cast<signed char>(x_size[1]) - 1;
    for (k = 0; k <= nx; k++) {
      b_y_data[k] = -b_y_data[k] / b_params;
    }

    for (k = 0; k < loop_ub_tmp; k++) {
      b_y_data[k] = std::exp(b_y_data[k]);
    }

    y_size[0] = 1;
    nx = static_cast<signed char>(x_size[1]) - 1;
    for (k = 0; k <= nx; k++) {
      boolean_T b;
      boolean_T b1;
      b = c1Index_data[k];
      b1 = c2Index_data[k];
      y_data[k] = (y_data[k] * static_cast<double>(b) + (1.0 - static_cast<
        double>(b))) * (b_y_data[k] * static_cast<double>(b1) + (1.0 -
        static_cast<double>(b1)));
    }
  }
}

//
// File trailer for gauss2mf.cpp
//
// [EOF]
//
