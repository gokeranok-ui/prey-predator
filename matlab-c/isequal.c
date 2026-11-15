/*
 * File: isequal.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "isequal.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_char_T *varargin_1
 *                const unsigned char varargin_2[5]
 * Return Type  : boolean_T
 */
boolean_T b_isequal(const emxArray_char_T *varargin_1, const unsigned char
                    varargin_2[5])
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if ((unsigned char)varargin_1->data[k] != varargin_2[k]) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/*
 * Arguments    : const emxArray_char_T *varargin_1
 *                const unsigned char varargin_2[6]
 * Return Type  : boolean_T
 */
boolean_T c_isequal(const emxArray_char_T *varargin_1, const unsigned char
                    varargin_2[6])
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if ((unsigned char)varargin_1->data[k] != varargin_2[k]) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/*
 * Arguments    : const emxArray_char_T *varargin_1
 *                const unsigned char varargin_2[7]
 * Return Type  : boolean_T
 */
boolean_T d_isequal(const emxArray_char_T *varargin_1, const unsigned char
                    varargin_2[7])
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if ((unsigned char)varargin_1->data[k] != varargin_2[k]) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/*
 * Arguments    : const emxArray_char_T *varargin_1
 *                const unsigned char varargin_2[3]
 * Return Type  : boolean_T
 */
boolean_T e_isequal(const emxArray_char_T *varargin_1, const unsigned char
                    varargin_2[3])
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if ((unsigned char)varargin_1->data[k] != varargin_2[k]) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/*
 * Arguments    : const emxArray_char_T *varargin_1
 *                const unsigned char varargin_2[8]
 * Return Type  : boolean_T
 */
boolean_T f_isequal(const emxArray_char_T *varargin_1, const unsigned char
                    varargin_2[8])
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if ((unsigned char)varargin_1->data[k] != varargin_2[k]) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/*
 * Arguments    : const emxArray_char_T *varargin_1
 *                const unsigned char varargin_2[4]
 * Return Type  : boolean_T
 */
boolean_T g_isequal(const emxArray_char_T *varargin_1, const unsigned char
                    varargin_2[4])
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if ((unsigned char)varargin_1->data[k] != varargin_2[k]) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/*
 * Arguments    : const emxArray_uint8_T *varargin_1
 *                const unsigned char varargin_2[3]
 * Return Type  : boolean_T
 */
boolean_T h_isequal(const emxArray_uint8_T *varargin_1, const unsigned char
                    varargin_2[3])
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (varargin_1->data[k] != varargin_2[k]) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/*
 * Arguments    : const emxArray_uint8_T *varargin_1
 *                const unsigned char varargin_2[4]
 * Return Type  : boolean_T
 */
boolean_T i_isequal(const emxArray_uint8_T *varargin_1, const unsigned char
                    varargin_2[4])
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (varargin_1->data[k] != varargin_2[k]) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/*
 * Arguments    : const emxArray_uint8_T *varargin_1
 *                const unsigned char varargin_2[8]
 * Return Type  : boolean_T
 */
boolean_T isequal(const emxArray_uint8_T *varargin_1, const unsigned char
                  varargin_2[8])
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (varargin_1->data[k] != varargin_2[k]) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/*
 * Arguments    : const emxArray_uint8_T *varargin_1
 *                const unsigned char varargin_2[6]
 * Return Type  : boolean_T
 */
boolean_T j_isequal(const emxArray_uint8_T *varargin_1, const unsigned char
                    varargin_2[6])
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (varargin_1->data[k] != varargin_2[k]) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/*
 * Arguments    : const emxArray_uint8_T *varargin_1
 *                const unsigned char varargin_2[5]
 * Return Type  : boolean_T
 */
boolean_T k_isequal(const emxArray_uint8_T *varargin_1, const unsigned char
                    varargin_2[5])
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (varargin_1->data[k] != varargin_2[k]) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/*
 * File trailer for isequal.c
 *
 * [EOF]
 */
