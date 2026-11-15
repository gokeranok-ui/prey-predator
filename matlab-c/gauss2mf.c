/*
 * File: gauss2mf.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "gauss2mf.h"
#include "power.h"

/* Function Definitions */

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const emxArray_real_T *params
 *                double y_data[]
 *                int y_size[2]
 * Return Type  : void
 */
void gauss2mf(const double x_data[], const int x_size[2], const emxArray_real_T *
              params, double y_data[], int y_size[2])
{
  double b_params;
  int loop_ub_tmp;
  int nx;
  boolean_T c1Index_data[51];
  double c;
  boolean_T c2Index_data[51];
  int b_x_size[2];
  double b_x_data[51];
  int loop_ub;
  int c_x_size[2];
  double c_x_data[51];
  b_params = params->data[1];
  loop_ub_tmp = x_size[0] * x_size[1];
  for (nx = 0; nx < loop_ub_tmp; nx++) {
    c1Index_data[nx] = (x_data[nx] <= b_params);
  }

  b_params = params->data[3];
  for (nx = 0; nx < loop_ub_tmp; nx++) {
    c2Index_data[nx] = (x_data[nx] >= b_params);
  }

  c = params->data[0] * params->data[0];
  b_x_size[0] = 1;
  b_x_size[1] = x_size[1];
  b_params = params->data[1];
  for (nx = 0; nx < loop_ub_tmp; nx++) {
    b_x_data[nx] = x_data[nx] - b_params;
  }

  power(b_x_data, b_x_size, y_data, y_size);
  b_params = 2.0 * c;
  loop_ub = y_size[0] * y_size[1] - 1;
  for (nx = 0; nx <= loop_ub; nx++) {
    y_data[nx] = -y_data[nx] / b_params;
  }

  nx = y_size[1];
  for (loop_ub = 0; loop_ub < nx; loop_ub++) {
    y_data[loop_ub] = exp(y_data[loop_ub]);
  }

  c = params->data[2] * params->data[2];
  c_x_size[0] = 1;
  c_x_size[1] = x_size[1];
  b_params = params->data[3];
  for (nx = 0; nx < loop_ub_tmp; nx++) {
    b_x_data[nx] = x_data[nx] - b_params;
  }

  power(b_x_data, c_x_size, c_x_data, b_x_size);
  b_params = 2.0 * c;
  loop_ub = b_x_size[0] * b_x_size[1] - 1;
  for (nx = 0; nx <= loop_ub; nx++) {
    c_x_data[nx] = -c_x_data[nx] / b_params;
  }

  nx = b_x_size[1];
  for (loop_ub = 0; loop_ub < nx; loop_ub++) {
    c_x_data[loop_ub] = exp(c_x_data[loop_ub]);
  }

  y_size[0] = 1;
  loop_ub = y_size[1] - 1;
  for (nx = 0; nx <= loop_ub; nx++) {
    y_data[nx] = (y_data[nx] * (double)c1Index_data[nx] + (1.0 - (double)
      c1Index_data[nx])) * (c_x_data[nx] * (double)c2Index_data[nx] + (1.0 -
      (double)c2Index_data[nx]));
  }
}

/*
 * File trailer for gauss2mf.c
 *
 * [EOF]
 */
