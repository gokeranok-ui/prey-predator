//
// File: isequal.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "isequal.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<char, 2U> &varargin_1
//                const unsigned char varargin_2[6]
// Return Type  : boolean_T
//
namespace coder
{
  boolean_T b_isequal(const ::coder::array<char, 2U> &varargin_1, const unsigned
                      char varargin_2[6])
  {
    boolean_T b_p;
    boolean_T p;
    p = false;
    b_p = (varargin_1.size(1) == 6);
    if (b_p && (varargin_1.size(1) != 0)) {
      int k;
      boolean_T exitg1;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 6)) {
        if (static_cast<unsigned char>(varargin_1[k]) != varargin_2[k]) {
          b_p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    return b_p || p;
  }

  //
  // Arguments    : const ::coder::array<unsigned char, 2U> &varargin_1
  //                const unsigned char varargin_2[3]
  // Return Type  : boolean_T
  //
  boolean_T b_isequal(const ::coder::array<unsigned char, 2U> &varargin_1, const
                      unsigned char varargin_2[3])
  {
    boolean_T b_p;
    boolean_T p;
    p = false;
    b_p = (varargin_1.size(1) == 3);
    if (b_p && (varargin_1.size(1) != 0)) {
      int k;
      boolean_T exitg1;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if (varargin_1[k] != varargin_2[k]) {
          b_p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    return b_p || p;
  }

  //
  // Arguments    : const ::coder::array<char, 2U> &varargin_1
  //                const unsigned char varargin_2[7]
  // Return Type  : boolean_T
  //
  boolean_T c_isequal(const ::coder::array<char, 2U> &varargin_1, const unsigned
                      char varargin_2[7])
  {
    boolean_T b_p;
    boolean_T p;
    p = false;
    b_p = (varargin_1.size(1) == 7);
    if (b_p && (varargin_1.size(1) != 0)) {
      int k;
      boolean_T exitg1;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 7)) {
        if (static_cast<unsigned char>(varargin_1[k]) != varargin_2[k]) {
          b_p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    return b_p || p;
  }

  //
  // Arguments    : const ::coder::array<unsigned char, 2U> &varargin_1
  //                const unsigned char varargin_2[4]
  // Return Type  : boolean_T
  //
  boolean_T c_isequal(const ::coder::array<unsigned char, 2U> &varargin_1, const
                      unsigned char varargin_2[4])
  {
    boolean_T b_p;
    boolean_T p;
    p = false;
    b_p = (varargin_1.size(1) == 4);
    if (b_p && (varargin_1.size(1) != 0)) {
      int k;
      boolean_T exitg1;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (varargin_1[k] != varargin_2[k]) {
          b_p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    return b_p || p;
  }

  //
  // Arguments    : const ::coder::array<char, 2U> &varargin_1
  //                const unsigned char varargin_2[3]
  // Return Type  : boolean_T
  //
  boolean_T d_isequal(const ::coder::array<char, 2U> &varargin_1, const unsigned
                      char varargin_2[3])
  {
    boolean_T b_p;
    boolean_T p;
    p = false;
    b_p = (varargin_1.size(1) == 3);
    if (b_p && (varargin_1.size(1) != 0)) {
      int k;
      boolean_T exitg1;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if (static_cast<unsigned char>(varargin_1[k]) != varargin_2[k]) {
          b_p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    return b_p || p;
  }

  //
  // Arguments    : const ::coder::array<unsigned char, 2U> &varargin_1
  //                const unsigned char varargin_2[6]
  // Return Type  : boolean_T
  //
  boolean_T d_isequal(const ::coder::array<unsigned char, 2U> &varargin_1, const
                      unsigned char varargin_2[6])
  {
    boolean_T b_p;
    boolean_T p;
    p = false;
    b_p = (varargin_1.size(1) == 6);
    if (b_p && (varargin_1.size(1) != 0)) {
      int k;
      boolean_T exitg1;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 6)) {
        if (varargin_1[k] != varargin_2[k]) {
          b_p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    return b_p || p;
  }

  //
  // Arguments    : const ::coder::array<unsigned char, 2U> &varargin_1
  //                const unsigned char varargin_2[5]
  // Return Type  : boolean_T
  //
  boolean_T e_isequal(const ::coder::array<unsigned char, 2U> &varargin_1, const
                      unsigned char varargin_2[5])
  {
    boolean_T b_p;
    boolean_T p;
    p = false;
    b_p = (varargin_1.size(1) == 5);
    if (b_p && (varargin_1.size(1) != 0)) {
      int k;
      boolean_T exitg1;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 5)) {
        if (varargin_1[k] != varargin_2[k]) {
          b_p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    return b_p || p;
  }

  //
  // Arguments    : const ::coder::array<char, 2U> &varargin_1
  //                const unsigned char varargin_2[8]
  // Return Type  : boolean_T
  //
  boolean_T e_isequal(const ::coder::array<char, 2U> &varargin_1, const unsigned
                      char varargin_2[8])
  {
    boolean_T b_p;
    boolean_T p;
    p = false;
    b_p = (varargin_1.size(1) == 8);
    if (b_p && (varargin_1.size(1) != 0)) {
      int k;
      boolean_T exitg1;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 8)) {
        if (static_cast<unsigned char>(varargin_1[k]) != varargin_2[k]) {
          b_p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    return b_p || p;
  }

  //
  // Arguments    : const ::coder::array<char, 2U> &varargin_1
  //                const unsigned char varargin_2[4]
  // Return Type  : boolean_T
  //
  boolean_T f_isequal(const ::coder::array<char, 2U> &varargin_1, const unsigned
                      char varargin_2[4])
  {
    boolean_T b_p;
    boolean_T p;
    p = false;
    b_p = (varargin_1.size(1) == 4);
    if (b_p && (varargin_1.size(1) != 0)) {
      int k;
      boolean_T exitg1;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (static_cast<unsigned char>(varargin_1[k]) != varargin_2[k]) {
          b_p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    return b_p || p;
  }

  //
  // Arguments    : const ::coder::array<unsigned char, 2U> &varargin_1
  //                const unsigned char varargin_2[8]
  // Return Type  : boolean_T
  //
  boolean_T isequal(const ::coder::array<unsigned char, 2U> &varargin_1, const
                    unsigned char varargin_2[8])
  {
    boolean_T b_p;
    boolean_T p;
    p = false;
    b_p = (varargin_1.size(1) == 8);
    if (b_p && (varargin_1.size(1) != 0)) {
      int k;
      boolean_T exitg1;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 8)) {
        if (varargin_1[k] != varargin_2[k]) {
          b_p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    return b_p || p;
  }

  //
  // Arguments    : const ::coder::array<char, 2U> &varargin_1
  //                const unsigned char varargin_2[5]
  // Return Type  : boolean_T
  //
  boolean_T isequal(const ::coder::array<char, 2U> &varargin_1, const unsigned
                    char varargin_2[5])
  {
    boolean_T b_p;
    boolean_T p;
    p = false;
    b_p = (varargin_1.size(1) == 5);
    if (b_p && (varargin_1.size(1) != 0)) {
      int k;
      boolean_T exitg1;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 5)) {
        if (static_cast<unsigned char>(varargin_1[k]) != varargin_2[k]) {
          b_p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    return b_p || p;
  }
}

//
// File trailer for isequal.cpp
//
// [EOF]
//
