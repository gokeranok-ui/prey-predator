//
// File: deblank.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "deblank.h"
#include "opkene_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<char, 2U> &x
//                ::coder::array<char, 2U> &y
// Return Type  : void
//
namespace coder
{
  void deblank(const ::coder::array<char, 2U> &x, ::coder::array<char, 2U> &y)
  {
    int i;
    int ncols;
    boolean_T exitg1;
    ncols = x.size(1) - 1;
    exitg1 = false;
    while ((!exitg1) && (ncols + 1 > 0)) {
      i = static_cast<unsigned char>(x[ncols]);
      if ((i != 0) && (!bv[i & 127])) {
        exitg1 = true;
      } else {
        ncols--;
      }
    }

    if (1 > ncols + 1) {
      ncols = -1;
    }

    y.set_size(1, (ncols + 1));
    for (i = 0; i <= ncols; i++) {
      y[i] = x[i];
    }
  }
}

//
// File trailer for deblank.cpp
//
// [EOF]
//
