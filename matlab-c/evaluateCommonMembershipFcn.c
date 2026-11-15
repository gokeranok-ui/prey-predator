/*
 * File: evaluateCommonMembershipFcn.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "evaluateCommonMembershipFcn.h"
#include "trimf.h"
#include "trapmf.h"
#include "gaussmf.h"
#include "isequal.h"
#include "opkene_rtwutil.h"

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
  double y;
  static const unsigned char uv37[5] = { 116U, 114U, 105U, 109U, 102U };

  static const unsigned char uv38[6] = { 116U, 114U, 97U, 112U, 109U, 102U };

  static const unsigned char uv39[7] = { 103U, 97U, 117U, 115U, 115U, 109U, 102U
  };

  static const unsigned char uv40[7] = { 103U, 98U, 101U, 108U, 108U, 109U, 102U
  };

  static const unsigned char uv41[5] = { 115U, 105U, 103U, 109U, 102U };

  static const unsigned char uv42[3] = { 115U, 109U, 102U };

  double value;
  static const unsigned char uv43[3] = { 122U, 109U, 102U };

  static const unsigned char uv44[8] = { 103U, 97U, 117U, 115U, 115U, 50U, 109U,
    102U };

  static const unsigned char uv45[6] = { 100U, 115U, 105U, 103U, 109U, 102U };

  boolean_T c1Index;
  static const unsigned char uv46[6] = { 112U, 115U, 105U, 103U, 109U, 102U };

  boolean_T c2Index;
  static const unsigned char uv47[4] = { 112U, 105U, 109U, 102U };

  double a;
  y = -1.0;
  if (b_isequal(mfType, uv37)) {
    y = b_trimf(x, params);
  } else if (c_isequal(mfType, uv38)) {
    y = b_trapmf(x, params);
  } else if (d_isequal(mfType, uv39)) {
    y = b_gaussmf(x, params);
  } else if (d_isequal(mfType, uv40)) {
    y = 0.0;
    value = (x - params->data[2]) * (1.0 / params->data[0]);
    value *= value;
    if ((value <= 0.0) && (params->data[1] == 0.0)) {
      y = 0.5;
    } else if ((value <= 0.0) && (params->data[1] < 0.0)) {
    } else {
      value = rt_powd_snf(value, params->data[1]);
      y = 1.0 / (1.0 + value);
    }
  } else if (b_isequal(mfType, uv41)) {
    y = 1.0 / (1.0 + exp(-params->data[0] * (x - params->data[1])));
  } else if (e_isequal(mfType, uv42)) {
    if (params->data[0] >= params->data[1]) {
      y = (x >= (params->data[0] + params->data[1]) / 2.0);
    } else {
      y = 0.0;
      if ((params->data[0] < x) && (x <= (params->data[0] + params->data[1]) /
           2.0)) {
        value = (x - params->data[0]) * (1.0 / (params->data[1] - params->data[0]));
        y = 2.0 * value * value;
      }

      if (((params->data[0] + params->data[1]) / 2.0 < x) && (x <= params->data
           [1])) {
        value = (params->data[1] - x) * (1.0 / (params->data[1] - params->data[0]));
        y = 1.0 - 2.0 * value * value;
      }

      if (params->data[1] <= x) {
        y = 1.0;
      }
    }
  } else if (e_isequal(mfType, uv43)) {
    if (params->data[0] >= params->data[1]) {
      y = (x <= (params->data[1] + params->data[0]) / 2.0);
    } else {
      y = 0.0;
      if (x <= params->data[0]) {
        y = 1.0;
      }

      if ((params->data[0] < x) && (x <= (params->data[0] + params->data[1]) /
           2.0)) {
        value = (x - params->data[0]) * (1.0 / (params->data[0] - params->data[1]));
        y = 1.0 - 2.0 * value * value;
      }

      if (((params->data[0] + params->data[1]) / 2.0 < x) && (x <= params->data
           [1])) {
        value = (params->data[1] - x) * (1.0 / (params->data[0] - params->data[1]));
        y = 2.0 * value * value;
      }

      if (params->data[1] <= x) {
        y = 0.0;
      }
    }
  } else if (f_isequal(mfType, uv44)) {
    c1Index = (x <= params->data[1]);
    c2Index = (x >= params->data[3]);
    value = x - params->data[1];
    a = x - params->data[3];
    y = (exp(-(value * value) / (2.0 * (params->data[0] * params->data[0]))) *
         (double)c1Index + (1.0 - (double)c1Index)) * (exp(-(a * a) / (2.0 *
      (params->data[2] * params->data[2]))) * (double)c2Index + (1.0 - (double)
      c2Index));
  } else if (c_isequal(mfType, uv45)) {
    y = fabs(1.0 / (1.0 + exp(-params->data[0] * (x - params->data[1]))) - 1.0 /
             (1.0 + exp(-params->data[2] * (x - params->data[3]))));
  } else if (c_isequal(mfType, uv46)) {
    y = 1.0 / (1.0 + exp(-params->data[0] * (x - params->data[1]))) * (1.0 /
      (1.0 + exp(-params->data[2] * (x - params->data[3]))));
  } else if (g_isequal(mfType, uv47)) {
    if (params->data[0] >= params->data[1]) {
      y = (x >= (params->data[0] + params->data[1]) / 2.0);
    } else {
      y = 0.0;
      if ((params->data[0] < x) && (x <= (params->data[0] + params->data[1]) /
           2.0)) {
        value = (x - params->data[0]) * (1.0 / (params->data[1] - params->data[0]));
        y = 2.0 * value * value;
      }

      if (((params->data[0] + params->data[1]) / 2.0 < x) && (x <= params->data
           [1])) {
        value = (params->data[1] - x) * (1.0 / (params->data[1] - params->data[0]));
        y = 1.0 - 2.0 * value * value;
      }

      if (params->data[1] <= x) {
        y = 1.0;
      }
    }

    if (params->data[2] >= params->data[3]) {
      value = (x <= (params->data[3] + params->data[2]) / 2.0);
    } else {
      value = 0.0;
      if (x <= params->data[2]) {
        value = 1.0;
      }

      if ((params->data[2] < x) && (x <= (params->data[2] + params->data[3]) /
           2.0)) {
        value = (x - params->data[2]) * (1.0 / (params->data[2] - params->data[3]));
        value = 1.0 - 2.0 * value * value;
      }

      if (((params->data[2] + params->data[3]) / 2.0 < x) && (x <= params->data
           [3])) {
        value = (params->data[3] - x) * (1.0 / (params->data[2] - params->data[3]));
        value *= 2.0 * value;
      }

      if (params->data[3] <= x) {
        value = 0.0;
      }
    }

    y *= value;
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
