/*
 * File: repmat.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "repmat.h"
#include "opkene_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const h_struct_T a
 *                double varargin_2
 *                h_emxArray_struct_T *b
 * Return Type  : void
 */
void b_repmat(const h_struct_T a, double varargin_2, h_emxArray_struct_T *b)
{
  int i40;
  int loop_ub;
  i40 = b->size[0] * b->size[1];
  b->size[0] = 1;
  loop_ub = (int)varargin_2;
  b->size[1] = loop_ub;
  emxEnsureCapacity_struct_T5(b, i40);
  for (i40 = 0; i40 < loop_ub; i40++) {
    emxCopyStruct_struct_T5(&b->data[i40], &a);
  }
}

/*
 * Arguments    : const b_struct_T a
 *                double varargin_2
 *                b_emxArray_struct_T *b
 * Return Type  : void
 */
void c_repmat(const b_struct_T a, double varargin_2, b_emxArray_struct_T *b)
{
  int i54;
  int loop_ub;
  i54 = b->size[0] * b->size[1];
  b->size[0] = 1;
  loop_ub = (int)varargin_2;
  b->size[1] = loop_ub;
  emxEnsureCapacity_struct_T6(b, i54);
  for (i54 = 0; i54 < loop_ub; i54++) {
    emxCopyStruct_struct_T6(&b->data[i54], &a);
  }
}

/*
 * Arguments    : const struct_T a
 *                double varargin_2
 *                emxArray_struct_T *b
 * Return Type  : void
 */
void repmat(const struct_T a, double varargin_2, emxArray_struct_T *b)
{
  int i39;
  int loop_ub;
  i39 = b->size[0] * b->size[1];
  b->size[0] = 1;
  loop_ub = (int)varargin_2;
  b->size[1] = loop_ub;
  emxEnsureCapacity_struct_T4(b, i39);
  for (i39 = 0; i39 < loop_ub; i39++) {
    emxCopyStruct_struct_T4(&b->data[i39], &a);
  }
}

/*
 * File trailer for repmat.c
 *
 * [EOF]
 */
