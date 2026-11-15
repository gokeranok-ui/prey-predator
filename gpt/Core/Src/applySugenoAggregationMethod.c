/*
 * File: applySugenoAggregationMethod.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "applySugenoAggregationMethod.h"
#include "opkene_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *consequentOutputs
 *                emxArray_real_T *aggregatedOutputs
 * Return Type  : void
 */
void applySugenoAggregationMethod(const emxArray_real_T *consequentOutputs,
  emxArray_real_T *aggregatedOutputs)
{
  int vlen;
  int npages;
  unsigned int sz_idx_1;
  int xpageoffset;
  int i;
  int k;
  vlen = consequentOutputs->size[0];
  if ((consequentOutputs->size[0] == 0) || (consequentOutputs->size[1] == 0)) {
    sz_idx_1 = (unsigned int)consequentOutputs->size[1];
    xpageoffset = aggregatedOutputs->size[0] * aggregatedOutputs->size[1];
    aggregatedOutputs->size[0] = 1;
    aggregatedOutputs->size[1] = (int)sz_idx_1;
    emxEnsureCapacity_real_T(aggregatedOutputs, xpageoffset);
    i = (int)sz_idx_1;
    for (xpageoffset = 0; xpageoffset < i; xpageoffset++) {
      aggregatedOutputs->data[xpageoffset] = 0.0;
    }
  } else {
    npages = consequentOutputs->size[1];
    xpageoffset = aggregatedOutputs->size[0] * aggregatedOutputs->size[1];
    aggregatedOutputs->size[0] = 1;
    aggregatedOutputs->size[1] = consequentOutputs->size[1];
    emxEnsureCapacity_real_T(aggregatedOutputs, xpageoffset);
    for (i = 0; i < npages; i++) {
      xpageoffset = i * consequentOutputs->size[0];
      aggregatedOutputs->data[i] = consequentOutputs->data[xpageoffset];
      for (k = 2; k <= vlen; k++) {
        aggregatedOutputs->data[i] += consequentOutputs->data[(xpageoffset + k)
          - 1];
      }
    }
  }
}

/*
 * File trailer for applySugenoAggregationMethod.c
 *
 * [EOF]
 */
