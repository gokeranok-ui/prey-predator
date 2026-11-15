/*
 * File: mrdivide_helper.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "mrdivide_helper.h"

/* Function Definitions */

/*
 * Arguments    : const double B_data[]
 *                const int B_size[1]
 *                double y_data[]
 *                int y_size[2]
 * Return Type  : void
 */
void mrdivide_helper(const double B_data[], const int B_size[1], double y_data[],
                     int y_size[2])
{
  double A_data[51];
  int n;
  int b_n;
  int jpvt_data[51];
  int yk;
  int k;
  double smax;
  double vn1_data[51];
  double vn2_data[51];
  double temp1;
  double temp2;
  if (B_size[0] == 1) {
    y_size[0] = 1;
    y_size[1] = 1;
    y_data[0] = 1.0 / B_data[0];
  } else {
    if (0 <= B_size[0] - 1) {
      memcpy(&A_data[0], &B_data[0], (unsigned int)(B_size[0] * (int)sizeof
              (double)));
    }

    n = B_size[0];
    b_n = B_size[0];
    jpvt_data[0] = 1;
    yk = 1;
    for (k = 2; k <= b_n; k++) {
      yk++;
      jpvt_data[k - 1] = yk;
    }

    k = 0;
    for (b_n = 0; b_n < n; b_n++) {
      smax = fabs(A_data[k]);
      vn1_data[b_n] = smax;
      vn2_data[b_n] = smax;
      k++;
    }

    b_n = 0;
    yk = 0;
    smax = vn1_data[0];
    for (k = 2; k <= n; k++) {
      yk++;
      if (vn1_data[yk] > smax) {
        b_n = k - 1;
        smax = vn1_data[yk];
      }
    }

    if (b_n + 1 != 1) {
      smax = A_data[b_n];
      A_data[b_n] = A_data[0];
      A_data[0] = smax;
      jpvt_data[0] = jpvt_data[b_n];
      vn1_data[b_n] = vn1_data[0];
      vn2_data[b_n] = vn2_data[0];
    }

    for (b_n = 2; b_n <= n; b_n++) {
      smax = vn1_data[b_n - 1];
      if (smax != 0.0) {
        temp1 = fabs(A_data[b_n - 1]) / smax;
        temp1 = 1.0 - temp1 * temp1;
        if (temp1 < 0.0) {
          temp1 = 0.0;
        }

        temp2 = smax / vn2_data[b_n - 1];
        temp2 = temp1 * (temp2 * temp2);
        if (temp2 <= 1.4901161193847656E-8) {
          vn1_data[b_n - 1] = 0.0;
          vn2_data[b_n - 1] = 0.0;
        } else {
          vn1_data[b_n - 1] = smax * sqrt(temp1);
        }
      }
    }

    yk = 0;
    smax = fabs(A_data[0]);
    if (!(smax <= 2.2204460492503131E-15 * (double)B_size[0] * smax)) {
      yk = 1;
    }

    b_n = (signed char)B_size[0];
    if (0 <= b_n - 1) {
      memset(&vn1_data[0], 0, (unsigned int)(b_n * (int)sizeof(double)));
    }

    if (0 <= yk - 1) {
      vn1_data[jpvt_data[0] - 1] = 1.0;
    }

    for (b_n = yk; b_n >= 1; b_n--) {
      vn1_data[jpvt_data[0] - 1] /= A_data[0];
    }

    y_size[0] = 1;
    y_size[1] = (signed char)B_size[0];
    b_n = (signed char)B_size[0];
    if (0 <= b_n - 1) {
      memcpy(&y_data[0], &vn1_data[0], (unsigned int)(b_n * (int)sizeof(double)));
    }
  }
}

/*
 * File trailer for mrdivide_helper.c
 *
 * [EOF]
 */
