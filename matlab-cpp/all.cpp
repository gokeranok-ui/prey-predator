//
// File: all.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "all.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const boolean_T x[6]
// Return Type  : boolean_T
//
namespace coder
{
  boolean_T all(const boolean_T x[6])
  {
    int k;
    boolean_T exitg1;
    boolean_T y;
    y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 5)) {
      if (!x[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }

    return y;
  }

  //
  // Arguments    : const boolean_T x[7]
  // Return Type  : boolean_T
  //
  boolean_T b_all(const boolean_T x[7])
  {
    int k;
    boolean_T exitg1;
    boolean_T y;
    y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 6)) {
      if (!x[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }

    return y;
  }
}

//
// File trailer for all.cpp
//
// [EOF]
//
