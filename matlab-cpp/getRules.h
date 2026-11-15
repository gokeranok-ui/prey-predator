//
// File: getRules.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//
#ifndef GETRULES_H
#define GETRULES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct c_struct_T;

// Function Declarations
namespace coder
{
  namespace fuzzy
  {
    namespace internal
    {
      namespace codegen
      {
        void getRules(double fid, double maxLineLength, double numInputs, double
                      numOutputs, ::coder::array<c_struct_T, 2U> &rules);
      }
    }
  }
}

#endif

//
// File trailer for getRules.h
//
// [EOF]
//
