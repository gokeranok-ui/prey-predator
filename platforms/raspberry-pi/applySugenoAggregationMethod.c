/*
 * File: applySugenoAggregationMethod.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "applySugenoAggregationMethod.h"
#include "opkene_emxutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *consequentOutputs
 *                emxArray_real_T *aggregatedOutputs
 * Return Type  : void
 */
void applySugenoAggregationMethod(const emxArray_real_T *consequentOutputs,
                                  emxArray_real_T *aggregatedOutputs)
{
  const double *consequentOutputs_data;
  double *aggregatedOutputs_data;
  int ib;
  int k;
  int nblocks;
  int xi;
  consequentOutputs_data = consequentOutputs->data;
  if ((consequentOutputs->size[0] == 0) || (consequentOutputs->size[1] == 0)) {
    int firstBlockLength;
    nblocks = aggregatedOutputs->size[0] * aggregatedOutputs->size[1];
    aggregatedOutputs->size[0] = 1;
    aggregatedOutputs->size[1] = consequentOutputs->size[1];
    emxEnsureCapacity_real_T(aggregatedOutputs, nblocks);
    aggregatedOutputs_data = aggregatedOutputs->data;
    firstBlockLength = consequentOutputs->size[1];
    for (nblocks = 0; nblocks < firstBlockLength; nblocks++) {
      aggregatedOutputs_data[nblocks] = 0.0;
    }
  } else {
    int firstBlockLength;
    int lastBlockLength;
    int npages;
    npages = consequentOutputs->size[1];
    nblocks = aggregatedOutputs->size[0] * aggregatedOutputs->size[1];
    aggregatedOutputs->size[0] = 1;
    aggregatedOutputs->size[1] = consequentOutputs->size[1];
    emxEnsureCapacity_real_T(aggregatedOutputs, nblocks);
    aggregatedOutputs_data = aggregatedOutputs->data;
    if (consequentOutputs->size[0] <= 1024) {
      firstBlockLength = consequentOutputs->size[0];
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = (int)((unsigned int)consequentOutputs->size[0] >> 10);
      lastBlockLength = consequentOutputs->size[0] - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    for (xi = 0; xi < npages; xi++) {
      int xpageoffset;
      xpageoffset = xi * consequentOutputs->size[0];
      aggregatedOutputs_data[xi] = consequentOutputs_data[xpageoffset];
      for (k = 2; k <= firstBlockLength; k++) {
        aggregatedOutputs_data[xi] +=
            consequentOutputs_data[(xpageoffset + k) - 1];
      }
      for (ib = 2; ib <= nblocks; ib++) {
        double bsum;
        int hi;
        int xblockoffset;
        xblockoffset = xpageoffset + ((ib - 1) << 10);
        bsum = consequentOutputs_data[xblockoffset];
        if (ib == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }
        for (k = 2; k <= hi; k++) {
          bsum += consequentOutputs_data[(xblockoffset + k) - 1];
        }
        aggregatedOutputs_data[xi] += bsum;
      }
    }
  }
}

/*
 * File trailer for applySugenoAggregationMethod.c
 *
 * [EOF]
 */
