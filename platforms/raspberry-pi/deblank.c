/*
 * File: deblank.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "deblank.h"
#include "opkene_data.h"
#include "opkene_emxutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_char_T *x
 *                emxArray_char_T *y
 * Return Type  : void
 */
void deblank(const emxArray_char_T *x, emxArray_char_T *y)
{
  int i;
  int ncols;
  const char *x_data;
  char *y_data;
  boolean_T exitg1;
  x_data = x->data;
  ncols = x->size[1] - 1;
  exitg1 = false;
  while ((!exitg1) && (ncols + 1 > 0)) {
    i = (unsigned char)x_data[ncols];
    if ((i != 0) && (!bv[i & 127])) {
      exitg1 = true;
    } else {
      ncols--;
    }
  }
  if (ncols + 1 < 1) {
    ncols = -1;
  }
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = ncols + 1;
  emxEnsureCapacity_char_T(y, i);
  y_data = y->data;
  for (i = 0; i <= ncols; i++) {
    y_data[i] = x_data[i];
  }
}

/*
 * File trailer for deblank.c
 *
 * [EOF]
 */
