/*
 * File: deblank.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "deblank.h"
#include "opkene_emxutil.h"
#include "opkene_data.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_char_T *x
 *                emxArray_char_T *y
 * Return Type  : void
 */
void deblank(const emxArray_char_T *x, emxArray_char_T *y)
{
  int ncols;
  int i5;
  ncols = x->size[1];
  while ((ncols > 0) && (((unsigned char)x->data[ncols - 1] == 0) || bv0
                         [(unsigned char)x->data[ncols - 1] & 127])) {
    ncols--;
  }

  if (1 > ncols) {
    ncols = 0;
  }

  i5 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = ncols;
  emxEnsureCapacity_char_T(y, i5);
  for (i5 = 0; i5 < ncols; i5++) {
    y->data[i5] = x->data[i5];
  }
}

/*
 * File trailer for deblank.c
 *
 * [EOF]
 */
