/*
 * File: dsigmf.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "dsigmf.h"

/* Function Definitions */

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const emxArray_real_T *params
 *                double y_data[]
 *                int y_size[2]
 * Return Type  : void
 */
void dsigmf(const double x_data[], const int x_size[2], const emxArray_real_T
            *params, double y_data[], int y_size[2])
{
  double a;
  double c;
  int loop_ub_tmp;
  int k;
  int nx;
  double b_y_data[51];
  a = params->data[0];
  c = params->data[1];
  loop_ub_tmp = x_size[0] * x_size[1];
  for (k = 0; k < loop_ub_tmp; k++) {
    b_y_data[k] = -a * (x_data[k] - c);
  }

  nx = x_size[1];
  for (k = 0; k < nx; k++) {
    b_y_data[k] = exp(b_y_data[k]);
  }

  a = params->data[2];
  c = params->data[3];
  for (k = 0; k < loop_ub_tmp; k++) {
    y_data[k] = -a * (x_data[k] - c);
  }

  nx = x_size[1];
  for (k = 0; k < nx; k++) {
    y_data[k] = exp(y_data[k]);
  }

  nx = x_size[1] - 1;
  for (k = 0; k <= nx; k++) {
    b_y_data[k] = 1.0 / (1.0 + b_y_data[k]) - 1.0 / (1.0 + y_data[k]);
  }

  nx = x_size[1];
  y_size[0] = 1;
  y_size[1] = (signed char)x_size[1];
  for (k = 0; k < nx; k++) {
    y_data[k] = fabs(b_y_data[k]);
  }
}

/*
 * File trailer for dsigmf.c
 *
 * [EOF]
 */
