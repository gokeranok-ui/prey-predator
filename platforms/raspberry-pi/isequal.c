/*
 * File: isequal.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "isequal.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_char_T *varargin_1
 *                const unsigned char varargin_2[5]
 * Return Type  : boolean_T
 */
boolean_T b_isequal(const emxArray_char_T *varargin_1,
                    const unsigned char varargin_2[5])
{
  const char *varargin_1_data;
  boolean_T p;
  varargin_1_data = varargin_1->data;
  p = (varargin_1->size[1] == 5);
  if (p && (varargin_1->size[1] != 0)) {
    int k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if ((unsigned char)varargin_1_data[k] != varargin_2[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return p;
}

/*
 * Arguments    : const emxArray_char_T *varargin_1
 *                const unsigned char varargin_2[6]
 * Return Type  : boolean_T
 */
boolean_T c_isequal(const emxArray_char_T *varargin_1,
                    const unsigned char varargin_2[6])
{
  const char *varargin_1_data;
  boolean_T p;
  varargin_1_data = varargin_1->data;
  p = (varargin_1->size[1] == 6);
  if (p && (varargin_1->size[1] != 0)) {
    int k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if ((unsigned char)varargin_1_data[k] != varargin_2[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return p;
}

/*
 * Arguments    : const emxArray_char_T *varargin_1
 *                const unsigned char varargin_2[7]
 * Return Type  : boolean_T
 */
boolean_T d_isequal(const emxArray_char_T *varargin_1,
                    const unsigned char varargin_2[7])
{
  const char *varargin_1_data;
  boolean_T p;
  varargin_1_data = varargin_1->data;
  p = (varargin_1->size[1] == 7);
  if (p && (varargin_1->size[1] != 0)) {
    int k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if ((unsigned char)varargin_1_data[k] != varargin_2[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return p;
}

/*
 * Arguments    : const emxArray_char_T *varargin_1
 *                const unsigned char varargin_2[3]
 * Return Type  : boolean_T
 */
boolean_T e_isequal(const emxArray_char_T *varargin_1,
                    const unsigned char varargin_2[3])
{
  const char *varargin_1_data;
  boolean_T p;
  varargin_1_data = varargin_1->data;
  p = (varargin_1->size[1] == 3);
  if (p && (varargin_1->size[1] != 0)) {
    int k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if ((unsigned char)varargin_1_data[k] != varargin_2[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return p;
}

/*
 * Arguments    : const emxArray_char_T *varargin_1
 *                const unsigned char varargin_2[8]
 * Return Type  : boolean_T
 */
boolean_T f_isequal(const emxArray_char_T *varargin_1,
                    const unsigned char varargin_2[8])
{
  const char *varargin_1_data;
  boolean_T p;
  varargin_1_data = varargin_1->data;
  p = (varargin_1->size[1] == 8);
  if (p && (varargin_1->size[1] != 0)) {
    int k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if ((unsigned char)varargin_1_data[k] != varargin_2[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return p;
}

/*
 * Arguments    : const emxArray_uint8_T *varargin_1
 *                const unsigned char varargin_2[3]
 * Return Type  : boolean_T
 */
boolean_T g_isequal(const emxArray_uint8_T *varargin_1,
                    const unsigned char varargin_2[3])
{
  const unsigned char *varargin_1_data;
  boolean_T p;
  varargin_1_data = varargin_1->data;
  p = (varargin_1->size[1] == 3);
  if (p && (varargin_1->size[1] != 0)) {
    int k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (varargin_1_data[k] != varargin_2[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return p;
}

/*
 * Arguments    : const emxArray_uint8_T *varargin_1
 *                const unsigned char varargin_2[6]
 * Return Type  : boolean_T
 */
boolean_T h_isequal(const emxArray_uint8_T *varargin_1,
                    const unsigned char varargin_2[6])
{
  const unsigned char *varargin_1_data;
  boolean_T p;
  varargin_1_data = varargin_1->data;
  p = (varargin_1->size[1] == 6);
  if (p && (varargin_1->size[1] != 0)) {
    int k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (varargin_1_data[k] != varargin_2[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return p;
}

/*
 * Arguments    : const emxArray_uint8_T *varargin_1
 * Return Type  : boolean_T
 */
boolean_T i_isequal(const emxArray_uint8_T *varargin_1)
{
  static const unsigned char uv[5] = {119U, 116U, 115U, 117U, 109U};
  const unsigned char *varargin_1_data;
  boolean_T p;
  varargin_1_data = varargin_1->data;
  p = (varargin_1->size[1] == 5);
  if (p && (varargin_1->size[1] != 0)) {
    int k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (varargin_1_data[k] != uv[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return p;
}

/*
 * Arguments    : const emxArray_uint8_T *varargin_1
 *                const unsigned char varargin_2[8]
 * Return Type  : boolean_T
 */
boolean_T isequal(const emxArray_uint8_T *varargin_1,
                  const unsigned char varargin_2[8])
{
  const unsigned char *varargin_1_data;
  boolean_T p;
  varargin_1_data = varargin_1->data;
  p = (varargin_1->size[1] == 8);
  if (p && (varargin_1->size[1] != 0)) {
    int k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (varargin_1_data[k] != varargin_2[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return p;
}

/*
 * Arguments    : const emxArray_char_T *varargin_1
 * Return Type  : boolean_T
 */
boolean_T j_isequal(const emxArray_char_T *varargin_1)
{
  static const unsigned char uv[4] = {112U, 105U, 109U, 102U};
  const char *varargin_1_data;
  boolean_T p;
  varargin_1_data = varargin_1->data;
  p = (varargin_1->size[1] == 4);
  if (p && (varargin_1->size[1] != 0)) {
    int k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if ((unsigned char)varargin_1_data[k] != uv[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return p;
}

/*
 * Arguments    : const emxArray_uint8_T *varargin_1
 * Return Type  : boolean_T
 */
boolean_T k_isequal(const emxArray_uint8_T *varargin_1)
{
  static const unsigned char uv[4] = {112U, 114U, 111U, 100U};
  const unsigned char *varargin_1_data;
  boolean_T p;
  varargin_1_data = varargin_1->data;
  p = (varargin_1->size[1] == 4);
  if (p && (varargin_1->size[1] != 0)) {
    int k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (varargin_1_data[k] != uv[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return p;
}

/*
 * File trailer for isequal.c
 *
 * [EOF]
 */
