/*
 * File: feof.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "feof.h"
#include "fileManager.h"
#include "opkene_data.h"
#include "rt_nonfinite.h"
#include <stdio.h>

/* Function Definitions */
/*
 * Arguments    : double fileID
 * Return Type  : double
 */
double b_feof(double fileID)
{
  FILE *filestar;
  double st;
  filestar = fileManager(fileID);
  if (filestar == NULL) {
    st = 0.0;
  } else {
    int b_st;
    b_st = feof(filestar);
    st = ((int)b_st != 0);
  }
  return st;
}

/*
 * File trailer for feof.c
 *
 * [EOF]
 */
