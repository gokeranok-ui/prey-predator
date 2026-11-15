/*
 * File: char.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "char.h"
#include "opkene_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_uint8_T *varargin_1
 *                emxArray_char_T *y
 * Return Type  : void
 */
void b_char(const emxArray_uint8_T *varargin_1, emxArray_char_T *y)
{
  int i4;
  int loop_ub;
  i4 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = varargin_1->size[1];
  emxEnsureCapacity_char_T(y, i4);
  loop_ub = varargin_1->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    y->data[i4] = (signed char)varargin_1->data[i4];
  }
}

/*
 * Arguments    : const emxArray_real_T *varargin_1
 *                emxArray_char_T *y
 * Return Type  : void
 */
void c_char(const emxArray_real_T *varargin_1, emxArray_char_T *y)
{
  int i25;
  int loop_ub;
  double d0;
  i25 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = varargin_1->size[1];
  emxEnsureCapacity_char_T(y, i25);
  loop_ub = varargin_1->size[1];
  for (i25 = 0; i25 < loop_ub; i25++) {
    d0 = trunc(varargin_1->data[i25]);
    if (rtIsNaN(d0) || rtIsInf(d0)) {
      d0 = 0.0;
    } else {
      d0 = fmod(d0, 256.0);
    }

    if (d0 < 0.0) {
      y->data[i25] = (signed char)-(signed char)(unsigned char)-d0;
    } else {
      y->data[i25] = (signed char)(unsigned char)d0;
    }
  }
}

/*
 * File trailer for char.c
 *
 * [EOF]
 */
