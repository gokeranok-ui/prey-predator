/*
 * File: sigmf.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "sigmf.h"

/* Function Definitions */

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const emxArray_real_T *params
 *                double y_data[]
 *                int y_size[2]
 * Return Type  : void
 */
void sigmf(const double x_data[], const int x_size[2], const emxArray_real_T
           *params, double y_data[], int y_size[2])
{
  double b_params;
  double c_params;
  int nx;
  int k;
  y_size[1] = x_size[1];
  b_params = -params->data[0];
  c_params = params->data[1];
  nx = x_size[0] * x_size[1];
  for (k = 0; k < nx; k++) {
    y_data[k] = b_params * (x_data[k] - c_params);
  }

  nx = x_size[1];
  for (k = 0; k < nx; k++) {
    y_data[k] = exp(y_data[k]);
  }

  y_size[0] = 1;
  nx = x_size[1] - 1;
  for (k = 0; k <= nx; k++) {
    y_data[k] = 1.0 / (1.0 + y_data[k]);
  }
}

/*
 * File trailer for sigmf.c
 *
 * [EOF]
 */
