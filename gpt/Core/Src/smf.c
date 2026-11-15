/*
 * File: smf.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "smf.h"

/* Function Definitions */

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const emxArray_real_T *params
 *                double y_data[]
 *                int y_size[2]
 * Return Type  : void
 */
void smf(const double x_data[], const int x_size[2], const emxArray_real_T
         *params, double y_data[], int y_size[2])
{
  double x0;
  double x1;
  signed char unnamed_idx_1;
  int i;
  int i71;
  double value;
  x0 = params->data[0];
  x1 = params->data[1];
  if (params->data[0] >= params->data[1]) {
    y_size[0] = 1;
    y_size[1] = x_size[1];
    x0 = (params->data[0] + params->data[1]) / 2.0;
    i = x_size[0] * x_size[1];
    for (i71 = 0; i71 < i; i71++) {
      y_data[i71] = (x_data[i71] >= x0);
    }
  } else {
    unnamed_idx_1 = (signed char)x_size[1];
    y_size[0] = 1;
    y_size[1] = unnamed_idx_1;
    if (0 <= unnamed_idx_1 - 1) {
      memset(&y_data[0], 0, (unsigned int)(unnamed_idx_1 * (int)sizeof(double)));
    }

    i71 = x_size[1];
    for (i = 0; i < i71; i++) {
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
}

/*
 * File trailer for smf.c
 *
 * [EOF]
 */
