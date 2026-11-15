/*
 * File: frewind.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "frewind.h"
#include "fileManager.h"

/* Function Definitions */

/*
 * Arguments    : double fileID
 * Return Type  : void
 */
void frewind(double fileID)
{
  FILE * b_NULL;
  FILE * filestar;
  b_NULL = NULL;
  filestar = fileManager(fileID);
  if ((!(filestar == b_NULL)) && (!(fileID == 0.0)) && (!(fileID == 1.0)) &&
      (!(fileID == 2.0))) {
    fseek(filestar, 0, SEEK_SET);
  }
}

/*
 * File trailer for frewind.c
 *
 * [EOF]
 */
