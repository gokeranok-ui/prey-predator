/*
 * File: trapmf.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "trapmf.h"

/* Function Definitions */

/*
 * Arguments    : double x
 *                const emxArray_real_T *params
 * Return Type  : double
 */
double b_trapmf(double x, const emxArray_real_T *params)
{
  double y;
  double b_x;
  b_x = 0.0;
  y = 0.0;
  if (x >= params->data[1]) {
    b_x = 1.0;
  }

  if (x < params->data[0]) {
    b_x = 0.0;
  }

  if ((params->data[0] <= x) && (x < params->data[1]) && (params->data[0] !=
       params->data[1])) {
    b_x = (x - params->data[0]) * (1.0 / (params->data[1] - params->data[0]));
  }

  if (x <= params->data[2]) {
    y = 1.0;
  }

  if (x > params->data[3]) {
    y = 0.0;
  }

  if ((params->data[2] < x) && (x <= params->data[3]) && (params->data[2] !=
       params->data[3])) {
    y = (params->data[3] - x) * (1.0 / (params->data[3] - params->data[2]));
  }

  return fmin(b_x, y);
}

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const emxArray_real_T *params
 *                double y_data[]
 *                int y_size[2]
 * Return Type  : void
 */
void trapmf(const double x_data[], const int x_size[2], const emxArray_real_T
            *params, double y_data[], int y_size[2])
{
  double a;
  double b;
  double c;
  double d;
  signed char unnamed_idx_1;
  double y1_data[51];
  double y2_data[51];
  int i69;
  int i;
  double b_y2_data;
  double b_y1_data;
  a = params->data[0];
  b = params->data[1];
  c = params->data[2];
  d = params->data[3];
  unnamed_idx_1 = (signed char)x_size[1];
  y_size[0] = 1;
  y_size[1] = unnamed_idx_1;
  if (0 <= unnamed_idx_1 - 1) {
    memset(&y_data[0], 0, (unsigned int)(unnamed_idx_1 * (int)sizeof(double)));
  }

  unnamed_idx_1 = (signed char)x_size[1];
  if (0 <= unnamed_idx_1 - 1) {
    memset(&y1_data[0], 0, (unsigned int)(unnamed_idx_1 * (int)sizeof(double)));
  }

  unnamed_idx_1 = (signed char)x_size[1];
  if (0 <= unnamed_idx_1 - 1) {
    memset(&y2_data[0], 0, (unsigned int)(unnamed_idx_1 * (int)sizeof(double)));
  }

  i69 = x_size[1];
  for (i = 0; i < i69; i++) {
    b_y2_data = y2_data[i];
    b_y1_data = y1_data[i];
    if (x_data[i] >= b) {
      b_y1_data = 1.0;
    }

    if (x_data[i] < a) {
      b_y1_data = 0.0;
    }

    if ((a <= x_data[i]) && (x_data[i] < b) && (a != b)) {
      b_y1_data = (x_data[i] - a) * (1.0 / (b - a));
    }

    if (x_data[i] <= c) {
      b_y2_data = 1.0;
    }

    if (x_data[i] > d) {
      b_y2_data = 0.0;
    }

    if ((c < x_data[i]) && (x_data[i] <= d) && (c != d)) {
      b_y2_data = (d - x_data[i]) * (1.0 / (d - c));
    }

    y_data[i] = fmin(b_y1_data, b_y2_data);
    y1_data[i] = b_y1_data;
    y2_data[i] = b_y2_data;
  }
}

/*
 * File trailer for trapmf.c
 *
 * [EOF]
 */
