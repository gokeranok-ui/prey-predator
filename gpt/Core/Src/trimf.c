/*
 * File: trimf.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "trimf.h"

/* Function Definitions */

/*
 * Arguments    : double x
 *                const emxArray_real_T *params
 * Return Type  : double
 */
double b_trimf(double x, const emxArray_real_T *params)
{
  double y;
  y = 0.0;
  if ((params->data[0] != params->data[1]) && (params->data[0] < x) && (x <
       params->data[1])) {
    y = (x - params->data[0]) * (1.0 / (params->data[1] - params->data[0]));
  }

  if ((params->data[1] != params->data[2]) && (params->data[1] < x) && (x <
       params->data[2])) {
    y = (params->data[2] - x) * (1.0 / (params->data[2] - params->data[1]));
  }

  if (x == params->data[1]) {
    y = 1.0;
  }

  return y;
}

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const emxArray_real_T *params
 *                double y_data[]
 *                int y_size[2]
 * Return Type  : void
 */
void trimf(const double x_data[], const int x_size[2], const emxArray_real_T
           *params, double y_data[], int y_size[2])
{
  double a;
  double b;
  double c;
  signed char unnamed_idx_1;
  int i68;
  int i;
  a = params->data[0];
  b = params->data[1];
  c = params->data[2];
  unnamed_idx_1 = (signed char)x_size[1];
  y_size[0] = 1;
  y_size[1] = unnamed_idx_1;
  if (0 <= unnamed_idx_1 - 1) {
    memset(&y_data[0], 0, (unsigned int)(unnamed_idx_1 * (int)sizeof(double)));
  }

  i68 = x_size[1];
  for (i = 0; i < i68; i++) {
    if ((a != b) && (a < x_data[i]) && (x_data[i] < b)) {
      y_data[i] = (x_data[i] - a) * (1.0 / (b - a));
    }

    if ((b != c) && (b < x_data[i]) && (x_data[i] < c)) {
      y_data[i] = (c - x_data[i]) * (1.0 / (c - b));
    }

    if (x_data[i] == b) {
      y_data[i] = 1.0;
    }
  }
}

/*
 * File trailer for trimf.c
 *
 * [EOF]
 */
