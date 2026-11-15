/*
 * File: feof.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "feof.h"
#include "fileManager.h"

/* Function Definitions */

/*
 * Arguments    : double fileID
 * Return Type  : double
 */
double b_feof(double fileID)
{
  double st;
  FILE * b_NULL;
  FILE * filestar;
  int b_st;
  b_NULL = NULL;
  filestar = fileManager(fileID);
  if (filestar == b_NULL) {
    st = 0.0;
  } else {
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
