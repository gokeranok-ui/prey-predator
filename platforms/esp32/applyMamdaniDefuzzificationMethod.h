//
// File: applyMamdaniDefuzzificationMethod.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//
#ifndef APPLYMAMDANIDEFUZZIFICATIONMETHOD_H
#define APPLYMAMDANIDEFUZZIFICATIONMETHOD_H

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
        void applyMamdaniDefuzzificationMethod(const ::coder::array<double, 2U>
          &outputSamplePoints, double sumAntecedentOutputs, const ::coder::array<
          double, 2U> &aggregatedOutputs, const ::coder::array<double, 2U>
          &fis_outputRange, int fis_numOutputs, ::coder::array<double, 1U>
          &defuzzifiedOutputs);
        void b_applyMamdaniDefuzzificationMethod(const ::coder::array<double, 2U>
          &outputSamplePoints, double sumAntecedentOutputs, const ::coder::array<
          double, 2U> &aggregatedOutputs, const ::coder::array<double, 2U>
          &fis_outputRange, int fis_numOutputs, ::coder::array<double, 1U>
          &defuzzifiedOutputs);
        void c_applyMamdaniDefuzzificationMethod(const ::coder::array<double, 2U>
          &outputSamplePoints, double sumAntecedentOutputs, const ::coder::array<
          double, 2U> &aggregatedOutputs, const ::coder::array<double, 2U>
          &fis_outputRange, int fis_numOutputs, ::coder::array<double, 1U>
          &defuzzifiedOutputs);
        void d_applyMamdaniDefuzzificationMethod(const ::coder::array<double, 2U>
          &outputSamplePoints, double sumAntecedentOutputs, const ::coder::array<
          double, 2U> &aggregatedOutputs, const ::coder::array<double, 2U>
          &fis_outputRange, int fis_numOutputs, ::coder::array<double, 1U>
          &defuzzifiedOutputs);
        void e_applyMamdaniDefuzzificationMethod(const ::coder::array<double, 2U>
          &outputSamplePoints, double sumAntecedentOutputs, const ::coder::array<
          double, 2U> &aggregatedOutputs, const ::coder::array<double, 2U>
          &fis_outputRange, int fis_numOutputs, ::coder::array<double, 1U>
          &defuzzifiedOutputs);
        void f_applyMamdaniDefuzzificationMethod(const ::coder::array<double, 2U>
          &outputSamplePoints, double sumAntecedentOutputs, const ::coder::array<
          double, 2U> &aggregatedOutputs, const ::coder::array<double, 2U>
          &fis_outputRange, int fis_numOutputs, ::coder::array<double, 1U>
          &defuzzifiedOutputs);
      }
    }
  }
}

#endif

//
// File trailer for applyMamdaniDefuzzificationMethod.h
//
// [EOF]
//
