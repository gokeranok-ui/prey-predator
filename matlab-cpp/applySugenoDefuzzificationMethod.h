//
// File: applySugenoDefuzzificationMethod.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//
#ifndef APPLYSUGENODEFUZZIFICATIONMETHOD_H
#define APPLYSUGENODEFUZZIFICATIONMETHOD_H

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
        void applySugenoDefuzzificationMethod(double sumAntecedentOutputs, const
          ::coder::array<double, 2U> &aggregatedOutputs, const ::coder::array<
          double, 2U> &fis_outputRange, int fis_numOutputs, ::coder::array<
          double, 1U> &defuzzifiedOutputs);
      }
    }
  }
}

#endif

//
// File trailer for applySugenoDefuzzificationMethod.h
//
// [EOF]
//
