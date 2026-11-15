/*
 * File: gauss2mf.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "gauss2mf.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const boolean_T in2_data[]
 *                const int in2_size[2]
 *                const double in3_data[]
 *                const int in3_size[2]
 *                const boolean_T in4_data[]
 *                const int in4_size[2]
 * Return Type  : void
 */
void c_binary_expand_op(double in1_data[], int in1_size[2],
                        const boolean_T in2_data[], const int in2_size[2],
                        const double in3_data[], const int in3_size[2],
                        const boolean_T in4_data[], const int in4_size[2])
{
  double b_in1_data[51];
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1_tmp;
  int stride_3_1;
  int stride_4_1_tmp;
  if (in4_size[1] == 1) {
    i = in3_size[1];
  } else {
    i = in4_size[1];
  }
  if (i == 1) {
    if (in2_size[1] == 1) {
      loop_ub = in1_size[1];
    } else {
      loop_ub = in2_size[1];
    }
  } else {
    loop_ub = i;
  }
  stride_0_1 = (in1_size[1] != 1);
  stride_1_1_tmp = (in2_size[1] != 1);
  stride_3_1 = (in3_size[1] != 1);
  stride_4_1_tmp = (in4_size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    int b_in1_tmp;
    int in1_tmp;
    in1_tmp = in2_data[i * stride_1_1_tmp];
    b_in1_tmp = in4_data[i * stride_4_1_tmp];
    b_in1_data[i] =
        (in1_data[i * stride_0_1] * (double)in1_tmp + (1.0 - (double)in1_tmp)) *
        (in3_data[i * stride_3_1] * (double)b_in1_tmp +
         (1.0 - (double)b_in1_tmp));
  }
  in1_size[0] = 1;
  in1_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&in1_data[0], &b_in1_data[0],
           (unsigned int)loop_ub * sizeof(double));
  }
}

/*
 * File trailer for gauss2mf.c
 *
 * [EOF]
 */
