//
// File: any1.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "any1.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<unsigned char, 2U> &x
// Return Type  : boolean_T
//
namespace coder
{
  boolean_T any(const ::coder::array<unsigned char, 2U> &x)
  {
    int ix;
    boolean_T exitg1;
    boolean_T y;
    y = false;
    ix = 1;
    exitg1 = false;
    while ((!exitg1) && (ix <= x.size(1))) {
      if (x[ix - 1] == 0) {
        ix++;
      } else {
        y = true;
        exitg1 = true;
      }
    }

    return y;
  }
}

//
// File trailer for any1.cpp
//
// [EOF]
//
