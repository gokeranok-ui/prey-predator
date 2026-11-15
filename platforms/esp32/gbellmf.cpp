//
// File: gbellmf.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "gbellmf.h"
#include "opkene_rtwutil.h"
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
  void gbellmf(const double x_data[], const int x_size[2], const ::coder::array<
               double, 2U> &params, double y_data[], int y_size[2])
  {
    double b;
    double tmp;
    int loop_ub;
    b = params[1];
    y_size[0] = 1;
    y_size[1] = static_cast<signed char>(x_size[1]);
    loop_ub = static_cast<signed char>(x_size[1]);
    if (0 <= loop_ub - 1) {
      std::memset(&y_data[0], 0, loop_ub * sizeof(double));
    }

    loop_ub = x_size[1];
    for (int i = 0; i < loop_ub; i++) {
      tmp = (x_data[i] - params[2]) * (1.0 / params[0]);
      tmp *= tmp;
      if ((tmp <= 0.0) && (b == 0.0)) {
        y_data[i] = 0.5;
      } else {
        if ((!(tmp <= 0.0)) || (!(b < 0.0))) {
          tmp = rt_powd_snf(tmp, b);
          y_data[i] = 1.0 / (tmp + 1.0);
        }
      }
    }
  }
}

//
// File trailer for gbellmf.cpp
//
// [EOF]
//
