/*
 * File: xor.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "xor.h"
#include "opkene_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_uint8_T *s
 *                const emxArray_uint8_T *t
 *                emxArray_boolean_T *y
 * Return Type  : void
 */
void xor(const emxArray_uint8_T *s, const emxArray_uint8_T *t,
         emxArray_boolean_T *y)
{
  int i8;
  int loop_ub;
  i8 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = s->size[1];
  emxEnsureCapacity_boolean_T(y, i8);
  loop_ub = s->size[0] * s->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    y->data[i8] = (((s->data[i8] != 0) ^ (t->data[i8] != 0)) != 0);
  }
}

/*
 * File trailer for xor.c
 *
 * [EOF]
 */
