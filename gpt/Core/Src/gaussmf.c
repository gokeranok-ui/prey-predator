/*
 * File: gaussmf.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "gaussmf.h"
#include "power.h"

/* Function Definitions */

/*
 * Arguments    : double x
 *                const emxArray_real_T *params
 * Return Type  : double
 */
double b_gaussmf(double x, const emxArray_real_T *params)
{
  double a;
  a = x - params->data[1];
  return exp(-(a * a) / (2.0 * (params->data[0] * params->data[0])));
}

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const emxArray_real_T *params
 *                double y_data[]
 *                int y_size[2]
 * Return Type  : void
 */
void gaussmf(const double x_data[], const int x_size[2], const emxArray_real_T
             *params, double y_data[], int y_size[2])
{
  double c;
  int b_x_size[2];
  double b_params;
  int nx;
  int k;
  double b_x_data[51];
  c = params->data[0] * params->data[0];
  b_x_size[0] = 1;
  b_x_size[1] = x_size[1];
  b_params = params->data[1];
  nx = x_size[0] * x_size[1];
  for (k = 0; k < nx; k++) {
    b_x_data[k] = x_data[k] - b_params;
  }

  power(b_x_data, b_x_size, y_data, y_size);
  k = y_size[0] * y_size[1];
  y_size[0] = 1;
  c *= 2.0;
  nx = k - 1;
  for (k = 0; k <= nx; k++) {
    y_data[k] = -y_data[k] / c;
  }

  nx = y_size[1];
  for (k = 0; k < nx; k++) {
    y_data[k] = exp(y_data[k]);
  }
}

/*
 * File trailer for gaussmf.c
 *
 * [EOF]
 */
