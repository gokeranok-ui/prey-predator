//
// File: applyMamdaniImplicationMethod.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//
#ifndef APPLYMAMDANIIMPLICATIONMETHOD_H
#define APPLYMAMDANIIMPLICATIONMETHOD_H

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
        void applyMamdaniImplicationMethod(const ::coder::array<double, 1U>
          &antecedentOutputs, const ::coder::array<unsigned char, 2U>
          &fis_impMethod, const ::coder::array<double, 2U> &fis_consequent, int
          fis_numOutputs, int fis_numRules, const ::coder::array<int, 2U>
          &fis_numCumOutputMFs, const int fis_orrSize[2], const ::coder::array<
          double, 2U> &varargin_1, ::coder::array<double, 2U> &consequentOutputs);
      }
    }
  }
}

#endif

//
// File trailer for applyMamdaniImplicationMethod.h
//
// [EOF]
//
