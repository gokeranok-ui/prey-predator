/*
 * File: strcmp.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "strcmp.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_char_T *a
 * Return Type  : boolean_T
 */
boolean_T b_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv2[8] = { 'c', 'o', 'n', 's', 't', 'a', 'n', 't' };

  b_bool = false;
  if (a->size[1] == 8) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (a->data[kstr] != cv2[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

/*
 * Arguments    : const emxArray_char_T *a
 * Return Type  : boolean_T
 */
boolean_T c_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv3[6] = { 'l', 'i', 'n', 'e', 'a', 'r' };

  b_bool = false;
  if (a->size[1] == 6) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (a->data[kstr] != cv3[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

/*
 * Arguments    : const emxArray_char_T *a
 * Return Type  : boolean_T
 */
boolean_T d_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv4[7] = { '[', 'R', 'u', 'l', 'e', 's', ']' };

  b_bool = false;
  if (a->size[1] == 7) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 7) {
        if (a->data[kstr] != cv4[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

/*
 * Arguments    : const emxArray_char_T *a
 * Return Type  : boolean_T
 */
boolean_T e_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv5[7] = { 'm', 'a', 'm', 'd', 'a', 'n', 'i' };

  b_bool = false;
  if (a->size[1] == 7) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 7) {
        if (a->data[kstr] != cv5[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

/*
 * File trailer for strcmp.c
 *
 * [EOF]
 */
