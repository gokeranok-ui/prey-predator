/*
 * File: pimf.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "pimf.h"
#include "opkene_types.h"
#include "pimf1.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const emxArray_real_T *params
 *                double y_data[]
 *                int y_size[2]
 * Return Type  : void
 */
void pimf(const double x_data[], const int x_size[2],
          const emxArray_real_T *params, double y_data[], int y_size[2])
{
  double tmp_data[51];
  const double *params_data;
  double b_value;
  double d;
  double x0;
  double x1;
  int tmp_size[2];
  int i;
  int loop_ub;
  params_data = params->data;
  x0 = params_data[0];
  x1 = params_data[1];
  if (params_data[0] >= params_data[1]) {
    y_size[0] = 1;
    y_size[1] = x_size[1];
    x0 = (params_data[0] + params_data[1]) / 2.0;
    loop_ub = x_size[1];
    for (i = 0; i < loop_ub; i++) {
      y_data[i] = (x_data[i] >= x0);
    }
  } else {
    y_size[0] = 1;
    y_size[1] = (signed char)x_size[1];
    loop_ub = (signed char)x_size[1];
    if (loop_ub - 1 >= 0) {
      memset(&y_data[0], 0, (unsigned int)loop_ub * sizeof(double));
    }
    i = x_size[1];
    for (loop_ub = 0; loop_ub < i; loop_ub++) {
      d = x_data[loop_ub];
      if ((x0 < d) && (d <= (x0 + x1) / 2.0)) {
        b_value = (d - x0) * (1.0 / (x1 - x0));
        y_data[loop_ub] = 2.0 * b_value * b_value;
      }
      if (((x0 + x1) / 2.0 < d) && (d <= x1)) {
        b_value = (x1 - d) * (1.0 / (x1 - x0));
        y_data[loop_ub] = 1.0 - 2.0 * b_value * b_value;
      }
      if (x1 <= d) {
        y_data[loop_ub] = 1.0;
      }
    }
  }
  x1 = params_data[2];
  x0 = params_data[3];
  if (params_data[2] >= params_data[3]) {
    tmp_size[0] = 1;
    tmp_size[1] = x_size[1];
    x0 = (params_data[2] + params_data[3]) / 2.0;
    loop_ub = x_size[1];
    for (i = 0; i < loop_ub; i++) {
      tmp_data[i] = (x_data[i] <= x0);
    }
  } else {
    tmp_size[0] = 1;
    tmp_size[1] = (signed char)x_size[1];
    loop_ub = (signed char)x_size[1];
    if (loop_ub - 1 >= 0) {
      memset(&tmp_data[0], 0, (unsigned int)loop_ub * sizeof(double));
    }
    i = x_size[1];
    for (loop_ub = 0; loop_ub < i; loop_ub++) {
      d = x_data[loop_ub];
      if (d <= x1) {
        tmp_data[loop_ub] = 1.0;
      }
      if ((x1 < d) && (d <= (x1 + x0) / 2.0)) {
        b_value = (d - x1) * (1.0 / (x1 - x0));
        tmp_data[loop_ub] = 1.0 - 2.0 * b_value * b_value;
      }
      if (((x1 + x0) / 2.0 < d) && (d <= x0)) {
        b_value = (x0 - d) * (1.0 / (x1 - x0));
        tmp_data[loop_ub] = 2.0 * b_value * b_value;
      }
      if (x0 <= d) {
        tmp_data[loop_ub] = 0.0;
      }
    }
  }
  if (y_size[1] == tmp_size[1]) {
    loop_ub = y_size[1] - 1;
    y_size[0] = 1;
    for (i = 0; i <= loop_ub; i++) {
      y_data[i] *= tmp_data[i];
    }
  } else {
    times(y_data, y_size, tmp_data, tmp_size);
  }
}

/*
 * File trailer for pimf.c
 *
 * [EOF]
 */
