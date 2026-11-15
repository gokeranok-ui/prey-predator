//
// File: applySugenoImplicationMethod.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//
#ifndef APPLYSUGENOIMPLICATIONMETHOD_H
#define APPLYSUGENOIMPLICATIONMETHOD_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct e_struct_T;

// Function Declarations
namespace coder
{
  namespace fuzzy
  {
    namespace internal
    {
      namespace codegen
      {
        void applySugenoImplicationMethod(double inputs, const ::coder::array<
          double, 1U> &antecedentOutputs, const ::coder::array<e_struct_T, 2U>
          &fis_outputMF, const ::coder::array<double, 2U> &fis_consequent, int
          fis_numOutputs, int fis_numRules, const ::coder::array<int, 2U>
          &fis_numOutputMFs, const ::coder::array<int, 2U> &fis_numCumOutputMFs,
          const int fis_orrSize[2], ::coder::array<double, 2U>
          &consequentOutputs, ::coder::array<double, 2U> &unscaledOutputs);
        void applySugenoImplicationMethod(const ::coder::array<double, 2U>
          &inputs, const ::coder::array<double, 1U> &antecedentOutputs, const ::
          coder::array<e_struct_T, 2U> &fis_outputMF, const ::coder::array<
          double, 2U> &fis_consequent, int fis_numOutputs, int fis_numRules,
          const ::coder::array<int, 2U> &fis_numOutputMFs, const ::coder::array<
          int, 2U> &fis_numCumOutputMFs, const int fis_orrSize[2], ::coder::
          array<double, 2U> &consequentOutputs, ::coder::array<double, 2U>
          &unscaledOutputs);
      }
    }
  }
}

#endif

//
// File trailer for applySugenoImplicationMethod.h
//
// [EOF]
//
