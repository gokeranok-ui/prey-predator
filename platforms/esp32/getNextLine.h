//
// File: getNextLine.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//
#ifndef GETNEXTLINE_H
#define GETNEXTLINE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder
{
  namespace fuzzy
  {
    namespace internal
    {
      namespace codegen
      {
        void getLine(double fid, double maxLength, ::coder::array<unsigned char,
                     2U> &result);
        void getNextLine(double fid, double maxLength, ::coder::array<unsigned
                         char, 2U> &result);
      }
    }
  }
}

#endif

//
// File trailer for getNextLine.h
//
// [EOF]
//
