/*
 * File: power.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "power.h"

/* Function Definitions */

/*
 * Arguments    : const double a_data[]
 *                const int a_size[2]
 *                double y_data[]
 *                int y_size[2]
 * Return Type  : void
 */
void power(const double a_data[], const int a_size[2], double y_data[], int
           y_size[2])
{
  int nx;
  int k;
  y_size[0] = 1;
  y_size[1] = (signed char)a_size[1];
  nx = (signed char)a_size[1];
  for (k = 0; k < nx; k++) {
    y_data[k] = a_data[k] * a_data[k];
  }
}

/*
 * File trailer for power.c
 *
 * [EOF]
 */
