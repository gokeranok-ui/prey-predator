//
// File: applyMamdaniAggregationMethod.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//
#ifndef APPLYMAMDANIAGGREGATIONMETHOD_H
#define APPLYMAMDANIAGGREGATIONMETHOD_H

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
        void applyMamdaniAggregationMethod(const ::coder::array<double, 2U>
          &consequentOutputs, const ::coder::array<unsigned char, 2U>
          &fis_aggMethod, int fis_numOutputs, int fis_numRules, const int
          fis_aggSize[2], ::coder::array<double, 2U> &aggregatedOutputs);
      }
    }
  }
}

#endif

//
// File trailer for applyMamdaniAggregationMethod.h
//
// [EOF]
//
