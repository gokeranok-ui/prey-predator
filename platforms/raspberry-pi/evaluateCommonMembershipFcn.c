/*
 * File: evaluateCommonMembershipFcn.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "evaluateCommonMembershipFcn.h"
#include "isequal.h"
#include "opkene_rtwutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_char_T *mfType
 *                double x
 *                const emxArray_real_T *params
 * Return Type  : double
 */
double evaluateCommonMembershipFcn(const emxArray_char_T *mfType, double x,
                                   const emxArray_real_T *params)
{
  static const unsigned char uv9[8] = {103U, 97U, 117U, 115U,
                                       115U, 50U, 109U, 102U};
  static const unsigned char uv2[7] = {103U, 97U, 117U, 115U, 115U, 109U, 102U};
  static const unsigned char uv3[7] = {103U, 98U, 101U, 108U, 108U, 109U, 102U};
  static const unsigned char uv1[6] = {116U, 114U, 97U, 112U, 109U, 102U};
  static const unsigned char uv10[6] = {100U, 115U, 105U, 103U, 109U, 102U};
  static const unsigned char uv11[6] = {112U, 115U, 105U, 103U, 109U, 102U};
  static const unsigned char uv7[6] = {108U, 105U, 110U, 115U, 109U, 102U};
  static const unsigned char uv8[6] = {108U, 105U, 110U, 122U, 109U, 102U};
  static const unsigned char uv[5] = {116U, 114U, 105U, 109U, 102U};
  static const unsigned char uv4[5] = {115U, 105U, 103U, 109U, 102U};
  static const unsigned char uv5[3] = {115U, 109U, 102U};
  static const unsigned char uv6[3] = {122U, 109U, 102U};
  const double *params_data;
  double y;
  params_data = params->data;
  y = -1.0;
  if (b_isequal(mfType, uv)) {
    y = 0.0;
    if ((params_data[0] != params_data[1]) && (params_data[0] < x) &&
        (x < params_data[1])) {
      y = (x - params_data[0]) * (1.0 / (params_data[1] - params_data[0]));
    }
    if ((params_data[1] != params_data[2]) && (params_data[1] < x) &&
        (x < params_data[2])) {
      y = (params_data[2] - x) * (1.0 / (params_data[2] - params_data[1]));
    }
    if (x == params_data[1]) {
      y = 1.0;
    }
  } else if (c_isequal(mfType, uv1)) {
    double b_value;
    b_value = 0.0;
    y = 0.0;
    if (x >= params_data[1]) {
      b_value = 1.0;
    }
    if (x < params_data[0]) {
      b_value = 0.0;
    }
    if ((params_data[0] <= x) && (x < params_data[1]) &&
        (params_data[0] != params_data[1])) {
      b_value =
          (x - params_data[0]) * (1.0 / (params_data[1] - params_data[0]));
    }
    if (x <= params_data[2]) {
      y = 1.0;
    }
    if (x > params_data[3]) {
      y = 0.0;
    }
    if ((params_data[2] < x) && (x <= params_data[3]) &&
        (params_data[2] != params_data[3])) {
      y = (params_data[3] - x) * (1.0 / (params_data[3] - params_data[2]));
    }
    y = fmin(b_value, y);
  } else if (d_isequal(mfType, uv2)) {
    double b_value;
    b_value = x - params_data[1];
    y = exp(-(b_value * b_value) / (2.0 * (params_data[0] * params_data[0])));
  } else if (d_isequal(mfType, uv3)) {
    double b_value;
    y = 0.0;
    b_value = (x - params_data[2]) * (1.0 / params_data[0]);
    b_value *= b_value;
    if ((b_value <= 0.0) && (params_data[1] == 0.0)) {
      y = 0.5;
    } else if ((!(b_value <= 0.0)) || (!(params_data[1] < 0.0))) {
      b_value = rt_powd_snf(b_value, params_data[1]);
      y = 1.0 / (b_value + 1.0);
    }
  } else if (b_isequal(mfType, uv4)) {
    y = 1.0 / (exp(-params_data[0] * (x - params_data[1])) + 1.0);
  } else if (e_isequal(mfType, uv5)) {
    if (params_data[0] >= params_data[1]) {
      y = (x >= (params_data[0] + params_data[1]) / 2.0);
    } else {
      double b_value;
      y = 0.0;
      if ((params_data[0] < x) &&
          (x <= (params_data[0] + params_data[1]) / 2.0)) {
        b_value =
            (x - params_data[0]) * (1.0 / (params_data[1] - params_data[0]));
        y = 2.0 * b_value * b_value;
      }
      if (((params_data[0] + params_data[1]) / 2.0 < x) &&
          (x <= params_data[1])) {
        b_value =
            (params_data[1] - x) * (1.0 / (params_data[1] - params_data[0]));
        y = 1.0 - 2.0 * b_value * b_value;
      }
      if (params_data[1] <= x) {
        y = 1.0;
      }
    }
  } else if (e_isequal(mfType, uv6)) {
    if (params_data[0] >= params_data[1]) {
      y = (x <= (params_data[0] + params_data[1]) / 2.0);
    } else {
      double b_value;
      y = 0.0;
      if (x <= params_data[0]) {
        y = 1.0;
      }
      if ((params_data[0] < x) &&
          (x <= (params_data[0] + params_data[1]) / 2.0)) {
        b_value =
            (x - params_data[0]) * (1.0 / (params_data[0] - params_data[1]));
        y = 1.0 - 2.0 * b_value * b_value;
      }
      if (((params_data[0] + params_data[1]) / 2.0 < x) &&
          (x <= params_data[1])) {
        b_value =
            (params_data[1] - x) * (1.0 / (params_data[0] - params_data[1]));
        y = 2.0 * b_value * b_value;
      }
      if (params_data[1] <= x) {
        y = 0.0;
      }
    }
  } else if (c_isequal(mfType, uv7)) {
    y = 0.0;
    if (x >= params_data[1]) {
      y = 1.0;
    } else if (x >= params_data[0]) {
      y = (x - params_data[0]) * (1.0 / (params_data[1] - params_data[0]));
    }
  } else if (c_isequal(mfType, uv8)) {
    y = 0.0;
    if (x < params_data[0]) {
      y = 1.0;
    } else if (x < params_data[1]) {
      y = (params_data[1] - x) * (1.0 / (params_data[1] - params_data[0]));
    }
  } else if (f_isequal(mfType, uv9)) {
    double a;
    double b_value;
    boolean_T c1Index;
    boolean_T c2Index;
    c1Index = (x <= params_data[1]);
    c2Index = (x >= params_data[3]);
    b_value = x - params_data[1];
    a = x - params_data[3];
    y = (exp(-(b_value * b_value) / (2.0 * (params_data[0] * params_data[0]))) *
             (double)c1Index +
         (1.0 - (double)c1Index)) *
        (exp(-(a * a) / (2.0 * (params_data[2] * params_data[2]))) *
             (double)c2Index +
         (1.0 - (double)c2Index));
  } else if (c_isequal(mfType, uv10)) {
    y = fabs(1.0 / (exp(-params_data[0] * (x - params_data[1])) + 1.0) -
             1.0 / (exp(-params_data[2] * (x - params_data[3])) + 1.0));
  } else if (c_isequal(mfType, uv11)) {
    y = 1.0 / (exp(-params_data[0] * (x - params_data[1])) + 1.0) *
        (1.0 / (exp(-params_data[2] * (x - params_data[3])) + 1.0));
  } else if (j_isequal(mfType)) {
    double b_value;
    if (params_data[0] >= params_data[1]) {
      y = (x >= (params_data[0] + params_data[1]) / 2.0);
    } else {
      y = 0.0;
      if ((params_data[0] < x) &&
          (x <= (params_data[0] + params_data[1]) / 2.0)) {
        b_value =
            (x - params_data[0]) * (1.0 / (params_data[1] - params_data[0]));
        y = 2.0 * b_value * b_value;
      }
      if (((params_data[0] + params_data[1]) / 2.0 < x) &&
          (x <= params_data[1])) {
        b_value =
            (params_data[1] - x) * (1.0 / (params_data[1] - params_data[0]));
        y = 1.0 - 2.0 * b_value * b_value;
      }
      if (params_data[1] <= x) {
        y = 1.0;
      }
    }
    if (params_data[2] >= params_data[3]) {
      b_value = (x <= (params_data[2] + params_data[3]) / 2.0);
    } else {
      b_value = 0.0;
      if (x <= params_data[2]) {
        b_value = 1.0;
      }
      if ((params_data[2] < x) &&
          (x <= (params_data[2] + params_data[3]) / 2.0)) {
        b_value =
            (x - params_data[2]) * (1.0 / (params_data[2] - params_data[3]));
        b_value = 1.0 - 2.0 * b_value * b_value;
      }
      if (((params_data[2] + params_data[3]) / 2.0 < x) &&
          (x <= params_data[3])) {
        b_value =
            (params_data[3] - x) * (1.0 / (params_data[2] - params_data[3]));
        b_value *= 2.0 * b_value;
      }
      if (params_data[3] <= x) {
        b_value = 0.0;
      }
    }
    y *= b_value;
  } else {
    exit(0);
  }
  return y;
}

/*
 * File trailer for evaluateCommonMembershipFcn.c
 *
 * [EOF]
 */
