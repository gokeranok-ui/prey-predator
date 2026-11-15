/*
 * File: pimf.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "pimf.h"

/* Function Definitions */

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const emxArray_real_T *params
 *                double y_data[]
 *                int y_size[2]
 * Return Type  : void
 */
void pimf(const double x_data[], const int x_size[2], const emxArray_real_T
          *params, double y_data[], int y_size[2])
{
  double x0;
  double x1;
  signed char unnamed_idx_1;
  int i;
  int i73;
  double value;
  double tmp_data[51];
  x0 = params->data[0];
  x1 = params->data[1];
  if (params->data[0] >= params->data[1]) {
    y_size[1] = x_size[1];
    x0 = (params->data[0] + params->data[1]) / 2.0;
    i = x_size[0] * x_size[1];
    for (i73 = 0; i73 < i; i73++) {
      y_data[i73] = (x_data[i73] >= x0);
    }
  } else {
    unnamed_idx_1 = (signed char)x_size[1];
    y_size[1] = unnamed_idx_1;
    if (0 <= unnamed_idx_1 - 1) {
      memset(&y_data[0], 0, (unsigned int)(unnamed_idx_1 * (int)sizeof(double)));
    }

    i73 = x_size[1];
    for (i = 0; i < i73; i++) {
      if ((x0 < x_data[i]) && (x_data[i] <= (x0 + x1) / 2.0)) {
        value = (x_data[i] - x0) * (1.0 / (x1 - x0));
        y_data[i] = 2.0 * value * value;
      }

      if (((x0 + x1) / 2.0 < x_data[i]) && (x_data[i] <= x1)) {
        value = (x1 - x_data[i]) * (1.0 / (x1 - x0));
        y_data[i] = 1.0 - 2.0 * value * value;
      }

      if (x1 <= x_data[i]) {
        y_data[i] = 1.0;
      }
    }
  }

  x1 = params->data[2];
  x0 = params->data[3];
  if (params->data[2] >= params->data[3]) {
    x0 = (params->data[3] + params->data[2]) / 2.0;
    i = x_size[0] * x_size[1];
    for (i73 = 0; i73 < i; i73++) {
      tmp_data[i73] = (x_data[i73] <= x0);
    }
  } else {
    unnamed_idx_1 = (signed char)x_size[1];
    if (0 <= unnamed_idx_1 - 1) {
      memset(&tmp_data[0], 0, (unsigned int)(unnamed_idx_1 * (int)sizeof(double)));
    }

    i73 = x_size[1];
    for (i = 0; i < i73; i++) {
      if (x_data[i] <= x1) {
        tmp_data[i] = 1.0;
      }

      if ((x1 < x_data[i]) && (x_data[i] <= (x1 + x0) / 2.0)) {
        value = (x_data[i] - x1) * (1.0 / (x1 - x0));
        tmp_data[i] = 1.0 - 2.0 * value * value;
      }

      if (((x1 + x0) / 2.0 < x_data[i]) && (x_data[i] <= x0)) {
        value = (x0 - x_data[i]) * (1.0 / (x1 - x0));
        tmp_data[i] = 2.0 * value * value;
      }

      if (x0 <= x_data[i]) {
        tmp_data[i] = 0.0;
      }
    }
  }

  y_size[0] = 1;
  i = y_size[1] - 1;
  for (i73 = 0; i73 <= i; i73++) {
    y_data[i73] *= tmp_data[i73];
  }
}

/*
 * File trailer for pimf.c
 *
 * [EOF]
 */
