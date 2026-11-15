//
// File: applyOperators.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//
#ifndef APPLYOPERATORS_H
#define APPLYOPERATORS_H

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
        double applyOperators(const ::coder::array<double, 2U> &fuzzifiedInputs,
                              const ::coder::array<unsigned char, 2U>
                              &fis_andMethod, const ::coder::array<unsigned char,
                              2U> &fis_orMethod, const ::coder::array<double, 2U>
                              &fis_connection, const ::coder::array<double, 2U>
                              &fis_weight, int fis_numInputs, int fis_numRules, ::
                              coder::array<double, 1U> &varargin_1, ::coder::
                              array<double, 1U> &varargin_2);
      }
    }
  }
}

#endif

//
// File trailer for applyOperators.h
//
// [EOF]
//
