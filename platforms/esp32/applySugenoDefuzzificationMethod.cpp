//
// File: applySugenoDefuzzificationMethod.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "applySugenoDefuzzificationMethod.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : double sumAntecedentOutputs
//                const ::coder::array<double, 2U> &aggregatedOutputs
//                const ::coder::array<double, 2U> &fis_outputRange
//                int fis_numOutputs
//                ::coder::array<double, 1U> &defuzzifiedOutputs
// Return Type  : void
//
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
          double, 1U> &defuzzifiedOutputs)
        {
          defuzzifiedOutputs.set_size(fis_numOutputs);
          for (int outputID = 0; outputID < fis_numOutputs; outputID++) {
            if (sumAntecedentOutputs == 0.0) {
              defuzzifiedOutputs[outputID] = (fis_outputRange[outputID] +
                fis_outputRange[outputID + fis_outputRange.size(0)]) / 2.0;
            } else {
              double maxValueInX;
              int maxValueIdsInX;
              maxValueInX = 0.0;
              maxValueIdsInX = 0;
              if (sumAntecedentOutputs == sumAntecedentOutputs) {
                maxValueInX = aggregatedOutputs[outputID];
                maxValueIdsInX = 1;
              }

              defuzzifiedOutputs[outputID] = maxValueInX * (1.0 / static_cast<
                double>(maxValueIdsInX));
            }
          }
        }
      }
    }
  }
}

//
// File trailer for applySugenoDefuzzificationMethod.cpp
//
// [EOF]
//
