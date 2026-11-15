/*
 * File: getNextLine.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "getNextLine.h"
#include "fileManager.h"
#include "opkene_data.h"
#include "opkene_emxutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include <stdio.h>

/* Function Definitions */
/*
 * Arguments    : double fid
 *                double maxLength
 *                emxArray_uint8_T *result
 * Return Type  : void
 */
void getLine(double fid, double maxLength, emxArray_uint8_T *result)
{
  FILE *filestar;
  double count;
  int i;
  int loop_ub_tmp;
  unsigned char *result_data;
  boolean_T p;
  i = result->size[0] * result->size[1];
  result->size[0] = 1;
  loop_ub_tmp = (int)maxLength;
  result->size[1] = (int)maxLength;
  emxEnsureCapacity_uint8_T(result, i);
  result_data = result->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    result_data[i] = 0U;
  }
  count = 0.0;
  if ((fid != 0.0) && (fid != 1.0) && (fid != 2.0)) {
    p = true;
  } else {
    p = false;
  }
  int exitg1;
  do {
    exitg1 = 0;
    filestar = fileManager(fid);
    if (!p) {
      filestar = NULL;
    }
    if (filestar == NULL) {
      exitg1 = 1;
    } else {
      size_t numReadSizeT;
      unsigned char buf;
      unsigned char value_data;
      value_data = 0U;
      numReadSizeT = fread(&buf, sizeof(unsigned char), (size_t)1, filestar);
      if ((int)numReadSizeT - 1 >= 0) {
        value_data = buf;
      }
      if ((int)numReadSizeT + 1 <= 1) {
        value_data = 0U;
      }
      if ((int)numReadSizeT < 1) {
        exitg1 = 1;
      } else if (value_data != 10) {
        count++;
        result_data[(int)count - 1] = value_data;
      } else {
        if (count == 0.0) {
          result_data[0] = value_data;
        }
        exitg1 = 1;
      }
    }
  } while (exitg1 == 0);
}

/*
 * Arguments    : double fid
 *                double maxLength
 *                emxArray_uint8_T *result
 * Return Type  : void
 */
void getNextLine(double fid, double maxLength, emxArray_uint8_T *result)
{
  unsigned char *result_data;
  getLine(fid, maxLength, result);
  result_data = result->data;
  int exitg1;
  int ix;
  boolean_T exitg2;
  boolean_T y;
  do {
    exitg1 = 0;
    y = false;
    ix = 1;
    exitg2 = false;
    while ((!exitg2) && (ix <= result->size[1])) {
      if (result_data[ix - 1] != 0) {
        y = true;
        exitg2 = true;
      } else {
        ix++;
      }
    }
    if (y && (((signed char)result_data[0] == '%') || (result_data[0] == 10))) {
      getLine(fid, maxLength, result);
      result_data = result->data;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/*
 * File trailer for getNextLine.c
 *
 * [EOF]
 */
