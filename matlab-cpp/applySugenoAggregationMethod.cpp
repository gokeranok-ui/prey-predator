//
// File: applySugenoAggregationMethod.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "applySugenoAggregationMethod.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &consequentOutputs
//                ::coder::array<double, 2U> &aggregatedOutputs
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
        void applySugenoAggregationMethod(const ::coder::array<double, 2U>
          &consequentOutputs, ::coder::array<double, 2U> &aggregatedOutputs)
        {
          int vlen;
          vlen = consequentOutputs.size(0);
          if ((consequentOutputs.size(0) == 0) || (consequentOutputs.size(1) ==
               0)) {
            aggregatedOutputs.set_size(1, consequentOutputs.size(1));
            vlen = consequentOutputs.size(1);
            for (int npages = 0; npages < vlen; npages++) {
              aggregatedOutputs[npages] = 0.0;
            }
          } else {
            int npages;
            npages = consequentOutputs.size(1);
            aggregatedOutputs.set_size(1, consequentOutputs.size(1));
            for (int i = 0; i < npages; i++) {
              int xpageoffset;
              xpageoffset = i * consequentOutputs.size(0);
              aggregatedOutputs[i] = consequentOutputs[xpageoffset];
              for (int k = 2; k <= vlen; k++) {
                aggregatedOutputs[i] = aggregatedOutputs[i] + consequentOutputs
                  [(xpageoffset + k) - 1];
              }
            }
          }
        }
      }
    }
  }
}

//
// File trailer for applySugenoAggregationMethod.cpp
//
// [EOF]
//
