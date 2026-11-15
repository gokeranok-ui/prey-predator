/*
 * File: gbellmf.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "gbellmf.h"
#include "evaluateCommonMembershipFcn.h"
#include "opkene_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const emxArray_real_T *params
 *                double y_data[]
 *                int y_size[2]
 * Return Type  : void
 */
void gbellmf(const double x_data[], const int x_size[2], const emxArray_real_T
             *params, double y_data[], int y_size[2])
{
  double b;
  signed char unnamed_idx_1;
  int i70;
  int i;
  double tmp;
  b = params->data[1];
  unnamed_idx_1 = (signed char)x_size[1];
  y_size[0] = 1;
  y_size[1] = unnamed_idx_1;
  if (0 <= unnamed_idx_1 - 1) {
    memset(&y_data[0], 0, (unsigned int)(unnamed_idx_1 * (int)sizeof(double)));
  }

  i70 = x_size[1];
  for (i = 0; i < i70; i++) {
    tmp = (x_data[i] - params->data[2]) * (1.0 / params->data[0]);
    tmp *= tmp;
    if ((tmp <= 0.0) && (b == 0.0)) {
      y_data[i] = 0.5;
    } else if ((tmp <= 0.0) && (b < 0.0)) {
    } else {
      tmp = rt_powd_snf(tmp, b);
      y_data[i] = 1.0 / (1.0 + tmp);
    }
  }
}

/*
 * File trailer for gbellmf.c
 *
 * [EOF]
 */
