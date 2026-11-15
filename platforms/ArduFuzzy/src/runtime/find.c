/*
 * File: find.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "find.h"
#include "opkene_emxutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_boolean_T *x
 *                emxArray_int32_T *i
 * Return Type  : void
 */
void b_eml_find(const emxArray_boolean_T *x, emxArray_int32_T *i)
{
  int idx;
  int ii;
  int nx;
  int *i_data;
  const boolean_T *x_data;
  boolean_T exitg1;
  x_data = x->data;
  nx = x->size[1];
  idx = 0;
  ii = i->size[0] * i->size[1];
  i->size[0] = 1;
  i->size[1] = x->size[1];
  emxEnsureCapacity_int32_T(i, ii);
  i_data = i->data;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x_data[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (x->size[1] == 1) {
    if (idx == 0) {
      i->size[0] = 1;
      i->size[1] = 0;
    }
  } else {
    ii = i->size[0] * i->size[1];
    if (idx < 1) {
      i->size[1] = 0;
    } else {
      i->size[1] = idx;
    }
    emxEnsureCapacity_int32_T(i, ii);
  }
}

/*
 * Arguments    : const emxArray_boolean_T *x
 *                int i_data[]
 *                int i_size[2]
 * Return Type  : void
 */
void eml_find(const emxArray_boolean_T *x, int i_data[], int i_size[2])
{
  emxArray_int32_T *i;
  int b_i;
  int idx;
  int ii;
  int k;
  int *b_i_data;
  const boolean_T *x_data;
  boolean_T exitg1;
  x_data = x->data;
  k = (x->size[1] >= 1);
  idx = 0;
  emxInit_int32_T(&i);
  b_i = i->size[0] * i->size[1];
  i->size[0] = 1;
  i->size[1] = k;
  emxEnsureCapacity_int32_T(i, b_i);
  b_i_data = i->data;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= x->size[1] - 1)) {
    if (x_data[ii]) {
      idx++;
      b_i_data[idx - 1] = ii + 1;
      if (idx >= k) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (k == 1) {
    if (idx == 0) {
      i->size[0] = 1;
      i->size[1] = 0;
    }
  } else {
    b_i = i->size[0] * i->size[1];
    i->size[1] = (idx >= 1);
    emxEnsureCapacity_int32_T(i, b_i);
    b_i_data = i->data;
  }
  i_size[0] = 1;
  i_size[1] = i->size[1];
  ii = i->size[1];
  for (b_i = 0; b_i < ii; b_i++) {
    i_data[0] = b_i_data[0];
  }
  emxFree_int32_T(&i);
}

/*
 * File trailer for find.c
 *
 * [EOF]
 */
