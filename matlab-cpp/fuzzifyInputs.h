//
// File: fuzzifyInputs.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//
#ifndef FUZZIFYINPUTS_H
#define FUZZIFYINPUTS_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct cell_wrap_0;

// Function Declarations
namespace coder
{
  namespace fuzzy
  {
    namespace internal
    {
      namespace codegen
      {
        void fuzzifyInputs(double inputs, const ::coder::array<double, 2U>
                           &fis_antecedent, const ::coder::array<double, 2U>
                           &fis_connection, int fis_numRules, const ::coder::
                           array<int, 2U> &fis_numInputMFs, const ::coder::array<
                           int, 2U> &fis_numCumInputMFs, const ::coder::array<
                           cell_wrap_0, 2U> &varargin_1, ::coder::array<double,
                           2U> &varargin_2, ::coder::array<double, 2U>
                           &varargin_3);
        void fuzzifyInputs(const ::coder::array<double, 2U> &inputs, const ::
                           coder::array<double, 2U> &fis_antecedent, const ::
                           coder::array<double, 2U> &fis_connection, int
                           fis_numInputs, int fis_numRules, const ::coder::array<
                           int, 2U> &fis_numInputMFs, const ::coder::array<int,
                           2U> &fis_numCumInputMFs, const ::coder::array<
                           cell_wrap_0, 2U> &varargin_1, ::coder::array<double,
                           2U> &varargin_2, ::coder::array<double, 2U>
                           &varargin_3);
      }
    }
  }
}

#endif

//
// File trailer for fuzzifyInputs.h
//
// [EOF]
//
