//
// File: find.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<boolean_T, 2U> &x
//                ::coder::array<int, 2U> &i
// Return Type  : void
//
namespace coder
{
  void b_eml_find(const ::coder::array<boolean_T, 2U> &x, ::coder::array<int, 2U>
                  &i)
  {
    int idx;
    int ii;
    int nx;
    boolean_T exitg1;
    nx = x.size(1);
    idx = 0;
    i.set_size(1, x.size(1));
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii <= nx - 1)) {
      if (x[ii]) {
        idx++;
        i[idx - 1] = ii + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          ii++;
        }
      } else {
        ii++;
      }
    }

    if (x.size(1) == 1) {
      if (idx == 0) {
        i.set_size(1, 0);
      }
    } else {
      if (1 > idx) {
        idx = 0;
      }

      i.set_size(i.size(0), idx);
    }
  }

  //
  // Arguments    : const ::coder::array<boolean_T, 2U> &x
  //                int i_data[]
  //                int i_size[2]
  // Return Type  : void
  //
  void eml_find(const ::coder::array<boolean_T, 2U> &x, int i_data[], int
                i_size[2])
  {
    array<int, 2U> i;
    int idx;
    int ii;
    boolean_T exitg1;
    idx = 0;
    i.set_size(1, 1);
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii <= x.size(1) - 1)) {
      if (x[ii]) {
        idx = 1;
        i[0] = ii + 1;
        exitg1 = true;
      } else {
        ii++;
      }
    }

    if (idx == 0) {
      i.set_size(1, 0);
    }

    i_size[0] = 1;
    i_size[1] = i.size(1);
    idx = i.size(0) * i.size(1);
    for (ii = 0; ii < idx; ii++) {
      i_data[ii] = i[ii];
    }
  }
}

//
// File trailer for find.cpp
//
// [EOF]
//
