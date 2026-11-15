//
// File: evaluateFIS.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//
#ifndef EVALUATEFIS_H
#define EVALUATEFIS_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct f_struct_T;

// Function Declarations
namespace coder
{
  namespace fuzzy
  {
    namespace internal
    {
      namespace codegen
      {
        void evaluateFIS(const ::coder::array<double, 1U> &inputs, const
                         f_struct_T *fis, ::coder::array<double, 2U> &y);
        void evaluateFIS(const ::coder::array<double, 2U> &inputs, const
                         f_struct_T *fis, ::coder::array<double, 2U> &y);
      }
    }
  }
}

#endif

//
// File trailer for evaluateFIS.h
//
// [EOF]
//
