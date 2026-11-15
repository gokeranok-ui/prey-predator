/*
 * File: createMamdaniOutputMFCache.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "createMamdaniOutputMFCache.h"
#include "dsigmf.h"
#include "extractVarMF.h"
#include "gauss2mf.h"
#include "isequal.h"
#include "opkene_emxutil.h"
#include "opkene_rtwutil.h"
#include "opkene_types.h"
#include "pimf.h"
#include "psigmf.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const e_emxArray_struct_T *fis_outputMF
 *                int fis_numOutputs
 *                const emxArray_int32_T *fis_numOutputMFs
 *                const emxArray_int32_T *fis_numCumOutputMFs
 *                const emxArray_real_T *outputSamplePoints
 *                emxArray_real_T *outputMFCache
 * Return Type  : void
 */
void createMamdaniOutputMFCache(const e_emxArray_struct_T *fis_outputMF,
                                int fis_numOutputs,
                                const emxArray_int32_T *fis_numOutputMFs,
                                const emxArray_int32_T *fis_numCumOutputMFs,
                                const emxArray_real_T *outputSamplePoints,
                                emxArray_real_T *outputMFCache)
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
  cell_wrap_0 *outVarMF_data;
  emxArray_cell_wrap_0 *outVarMF;
  double y1_data[51];
  double y2_data[51];
  double y_data[51];
  const double *outputSamplePoints_data;
  double *outputMFCache_data;
  int c1Index_size[2];
  int c2Index_size[2];
  int y1_size[2];
  int y_size[2];
  const int *fis_numCumOutputMFs_data;
  const int *fis_numOutputMFs_data;
  int i;
  int i1;
  int mfID;
  int outputID;
  int q0;
  unsigned int u;
  outputSamplePoints_data = outputSamplePoints->data;
  fis_numCumOutputMFs_data = fis_numCumOutputMFs->data;
  fis_numOutputMFs_data = fis_numOutputMFs->data;
  i = outputMFCache->size[0] * outputMFCache->size[1];
  outputMFCache->size[0] = (int)sum(fis_numOutputMFs);
  outputMFCache->size[1] = 51;
  emxEnsureCapacity_real_T(outputMFCache, i);
  outputMFCache_data = outputMFCache->data;
  emxInit_cell_wrap_0(&outVarMF);
  extractVarMF(fis_outputMF, outVarMF);
  outVarMF_data = outVarMF->data;
  u = (unsigned int)fis_numOutputs;
  if ((unsigned int)fis_numOutputs > 2147483647UL) {
    u = 2147483647UL;
  }
  i = (int)u;
  for (outputID = 0; outputID < i; outputID++) {
    int numMFs;
    numMFs = fis_numOutputMFs_data[outputID];
    for (mfID = 0; mfID < numMFs; mfID++) {
      int qY;
      q0 = fis_numCumOutputMFs_data[outputID];
      if ((q0 < 0) && (mfID + 1 < MIN_int32_T - q0)) {
        qY = MIN_int32_T;
      } else if ((q0 > 0) && (mfID + 1 > MAX_int32_T - q0)) {
        qY = MAX_int32_T;
      } else {
        qY = (q0 + mfID) + 1;
      }
      y_size[1] = outputSamplePoints->size[1];
      q0 = outputSamplePoints->size[1];
      for (i1 = 0; i1 < q0; i1++) {
        y_data[i1] = -1.0;
      }
      if (b_isequal(outVarMF_data[outputID].f1->data[mfID].type, uv)) {
        double a;
        double b;
        double x0;
        a = outVarMF_data[outputID].f1->data[mfID].params->data[0];
        b = outVarMF_data[outputID].f1->data[mfID].params->data[1];
        x0 = outVarMF_data[outputID].f1->data[mfID].params->data[2];
        y_size[1] = outputSamplePoints->size[1];
        q0 = outputSamplePoints->size[1];
        if (q0 - 1 >= 0) {
          memset(&y_data[0], 0, (unsigned int)q0 * sizeof(double));
        }
        i1 = outputSamplePoints->size[1];
        for (q0 = 0; q0 < i1; q0++) {
          double d;
          if (a != b) {
            d = outputSamplePoints_data[outputID +
                                        outputSamplePoints->size[0] * q0];
            if ((a < d) && (d < b)) {
              y_data[q0] = (d - a) * (1.0 / (b - a));
            }
          }
          if (b != x0) {
            d = outputSamplePoints_data[outputID +
                                        outputSamplePoints->size[0] * q0];
            if ((b < d) && (d < x0)) {
              y_data[q0] = (x0 - d) * (1.0 / (x0 - b));
            }
          }
          if (outputSamplePoints_data[outputID +
                                      outputSamplePoints->size[0] * q0] == b) {
            y_data[q0] = 1.0;
          }
        }
      } else if (c_isequal(outVarMF_data[outputID].f1->data[mfID].type, uv1)) {
        double a;
        double b;
        double b_value;
        double x0;
        a = outVarMF_data[outputID].f1->data[mfID].params->data[0];
        b = outVarMF_data[outputID].f1->data[mfID].params->data[1];
        x0 = outVarMF_data[outputID].f1->data[mfID].params->data[2];
        b_value = outVarMF_data[outputID].f1->data[mfID].params->data[3];
        y_size[1] = outputSamplePoints->size[1];
        q0 = outputSamplePoints->size[1];
        if (q0 - 1 >= 0) {
          memset(&y_data[0], 0, (unsigned int)q0 * sizeof(double));
        }
        q0 = outputSamplePoints->size[1];
        if (q0 - 1 >= 0) {
          memset(&y1_data[0], 0, (unsigned int)q0 * sizeof(double));
        }
        q0 = outputSamplePoints->size[1];
        if (q0 - 1 >= 0) {
          memset(&y2_data[0], 0, (unsigned int)q0 * sizeof(double));
        }
        i1 = outputSamplePoints->size[1];
        for (q0 = 0; q0 < i1; q0++) {
          double d;
          d = outputSamplePoints_data[outputID +
                                      outputSamplePoints->size[0] * q0];
          if (d >= b) {
            y1_data[q0] = 1.0;
          }
          if (d < a) {
            y1_data[q0] = 0.0;
          }
          if ((a <= d) && (d < b) && (a != b)) {
            y1_data[q0] = (d - a) * (1.0 / (b - a));
          }
          if (d <= x0) {
            y2_data[q0] = 1.0;
          }
          if (d > b_value) {
            y2_data[q0] = 0.0;
          }
          if ((x0 < d) && (d <= b_value) && (x0 != b_value)) {
            y2_data[q0] = (b_value - d) * (1.0 / (b_value - x0));
          }
          y_data[q0] = fmin(y1_data[q0], y2_data[q0]);
        }
      } else if (d_isequal(outVarMF_data[outputID].f1->data[mfID].type, uv2)) {
        double d;
        double x0;
        x0 = outVarMF_data[outputID].f1->data[mfID].params->data[1];
        d = 2.0 * (outVarMF_data[outputID].f1->data[mfID].params->data[0] *
                   outVarMF_data[outputID].f1->data[mfID].params->data[0]);
        q0 = outputSamplePoints->size[1];
        y_size[1] = outputSamplePoints->size[1];
        for (i1 = 0; i1 < q0; i1++) {
          double a;
          a = outputSamplePoints_data[outputID +
                                      outputSamplePoints->size[0] * i1] -
              x0;
          y_data[i1] = -(a * a) / d;
        }
        i1 = y_size[1];
        for (q0 = 0; q0 < i1; q0++) {
          y_data[q0] = exp(y_data[q0]);
        }
      } else if (d_isequal(outVarMF_data[outputID].f1->data[mfID].type, uv3)) {
        double b;
        b = outVarMF_data[outputID].f1->data[mfID].params->data[1];
        y_size[1] = outputSamplePoints->size[1];
        q0 = outputSamplePoints->size[1];
        if (q0 - 1 >= 0) {
          memset(&y_data[0], 0, (unsigned int)q0 * sizeof(double));
        }
        i1 = outputSamplePoints->size[1];
        for (q0 = 0; q0 < i1; q0++) {
          double a;
          a = (outputSamplePoints_data[outputID +
                                       outputSamplePoints->size[0] * q0] -
               outVarMF_data[outputID].f1->data[mfID].params->data[2]) *
              (1.0 / outVarMF_data[outputID].f1->data[mfID].params->data[0]);
          a *= a;
          if ((a <= 0.0) && (b == 0.0)) {
            y_data[q0] = 0.5;
          } else if ((!(a <= 0.0)) || (!(b < 0.0))) {
            a = rt_powd_snf(a, b);
            y_data[q0] = 1.0 / (a + 1.0);
          }
        }
      } else if (b_isequal(outVarMF_data[outputID].f1->data[mfID].type, uv4)) {
        double b_value;
        double x0;
        x0 = -outVarMF_data[outputID].f1->data[mfID].params->data[0];
        b_value = outVarMF_data[outputID].f1->data[mfID].params->data[1];
        q0 = outputSamplePoints->size[1];
        y_size[1] = outputSamplePoints->size[1];
        for (i1 = 0; i1 < q0; i1++) {
          y_data[i1] =
              x0 * (outputSamplePoints_data[outputID +
                                            outputSamplePoints->size[0] * i1] -
                    b_value);
        }
        i1 = y_size[1];
        for (q0 = 0; q0 < i1; q0++) {
          y_data[q0] = exp(y_data[q0]);
        }
        q0 = y_size[1] - 1;
        for (i1 = 0; i1 <= q0; i1++) {
          y_data[i1] = 1.0 / (y_data[i1] + 1.0);
        }
      } else if (e_isequal(outVarMF_data[outputID].f1->data[mfID].type, uv5)) {
        double a;
        double x0;
        x0 = outVarMF_data[outputID].f1->data[mfID].params->data[0];
        a = outVarMF_data[outputID].f1->data[mfID].params->data[1];
        if (outVarMF_data[outputID].f1->data[mfID].params->data[0] >=
            outVarMF_data[outputID].f1->data[mfID].params->data[1]) {
          x0 = (outVarMF_data[outputID].f1->data[mfID].params->data[0] +
                outVarMF_data[outputID].f1->data[mfID].params->data[1]) /
               2.0;
          q0 = outputSamplePoints->size[1];
          y_size[1] = outputSamplePoints->size[1];
          for (i1 = 0; i1 < q0; i1++) {
            y_data[i1] =
                (outputSamplePoints_data[outputID +
                                         outputSamplePoints->size[0] * i1] >=
                 x0);
          }
        } else {
          y_size[1] = outputSamplePoints->size[1];
          q0 = outputSamplePoints->size[1];
          if (q0 - 1 >= 0) {
            memset(&y_data[0], 0, (unsigned int)q0 * sizeof(double));
          }
          i1 = outputSamplePoints->size[1];
          for (q0 = 0; q0 < i1; q0++) {
            double b_value;
            double d;
            d = outputSamplePoints_data[outputID +
                                        outputSamplePoints->size[0] * q0];
            if ((x0 < d) && (d <= (x0 + a) / 2.0)) {
              b_value = (d - x0) * (1.0 / (a - x0));
              y_data[q0] = 2.0 * b_value * b_value;
            }
            if (((x0 + a) / 2.0 < d) && (d <= a)) {
              b_value = (a - d) * (1.0 / (a - x0));
              y_data[q0] = 1.0 - 2.0 * b_value * b_value;
            }
            if (a <= d) {
              y_data[q0] = 1.0;
            }
          }
        }
      } else if (e_isequal(outVarMF_data[outputID].f1->data[mfID].type, uv6)) {
        double a;
        double x0;
        a = outVarMF_data[outputID].f1->data[mfID].params->data[0];
        x0 = outVarMF_data[outputID].f1->data[mfID].params->data[1];
        if (outVarMF_data[outputID].f1->data[mfID].params->data[0] >=
            outVarMF_data[outputID].f1->data[mfID].params->data[1]) {
          x0 = (outVarMF_data[outputID].f1->data[mfID].params->data[0] +
                outVarMF_data[outputID].f1->data[mfID].params->data[1]) /
               2.0;
          q0 = outputSamplePoints->size[1];
          y_size[1] = outputSamplePoints->size[1];
          for (i1 = 0; i1 < q0; i1++) {
            y_data[i1] =
                (outputSamplePoints_data[outputID +
                                         outputSamplePoints->size[0] * i1] <=
                 x0);
          }
        } else {
          y_size[1] = outputSamplePoints->size[1];
          q0 = outputSamplePoints->size[1];
          if (q0 - 1 >= 0) {
            memset(&y_data[0], 0, (unsigned int)q0 * sizeof(double));
          }
          i1 = outputSamplePoints->size[1];
          for (q0 = 0; q0 < i1; q0++) {
            double b_value;
            double d;
            d = outputSamplePoints_data[outputID +
                                        outputSamplePoints->size[0] * q0];
            if (d <= a) {
              y_data[q0] = 1.0;
            }
            if ((a < d) && (d <= (a + x0) / 2.0)) {
              b_value = (d - a) * (1.0 / (a - x0));
              y_data[q0] = 1.0 - 2.0 * b_value * b_value;
            }
            if (((a + x0) / 2.0 < d) && (d <= x0)) {
              b_value = (x0 - d) * (1.0 / (a - x0));
              y_data[q0] = 2.0 * b_value * b_value;
            }
            if (x0 <= d) {
              y_data[q0] = 0.0;
            }
          }
        }
      } else if (c_isequal(outVarMF_data[outputID].f1->data[mfID].type, uv7)) {
        double a;
        double b;
        a = outVarMF_data[outputID].f1->data[mfID].params->data[0];
        b = outVarMF_data[outputID].f1->data[mfID].params->data[1];
        y_size[1] = outputSamplePoints->size[1];
        q0 = outputSamplePoints->size[1];
        if (q0 - 1 >= 0) {
          memset(&y_data[0], 0, (unsigned int)q0 * sizeof(double));
        }
        i1 = outputSamplePoints->size[1];
        for (q0 = 0; q0 < i1; q0++) {
          double d;
          d = outputSamplePoints_data[outputID +
                                      outputSamplePoints->size[0] * q0];
          if (d >= b) {
            y_data[q0] = 1.0;
          } else if (d >= a) {
            y_data[q0] = (d - a) * (1.0 / (b - a));
          }
        }
      } else if (c_isequal(outVarMF_data[outputID].f1->data[mfID].type, uv8)) {
        double a;
        double b;
        a = outVarMF_data[outputID].f1->data[mfID].params->data[0];
        b = outVarMF_data[outputID].f1->data[mfID].params->data[1];
        y_size[1] = outputSamplePoints->size[1];
        q0 = outputSamplePoints->size[1];
        if (q0 - 1 >= 0) {
          memset(&y_data[0], 0, (unsigned int)q0 * sizeof(double));
        }
        i1 = outputSamplePoints->size[1];
        for (q0 = 0; q0 < i1; q0++) {
          double d;
          d = outputSamplePoints_data[outputID +
                                      outputSamplePoints->size[0] * q0];
          if (d < a) {
            y_data[q0] = 1.0;
          } else if (d < b) {
            y_data[q0] = (b - d) * (1.0 / (b - a));
          }
        }
      } else if (f_isequal(outVarMF_data[outputID].f1->data[mfID].type, uv9)) {
        double a;
        double b;
        double b_value;
        double d;
        double x0;
        boolean_T c1Index_data[51];
        boolean_T c2Index_data[51];
        x0 = outVarMF_data[outputID].f1->data[mfID].params->data[1];
        c1Index_size[0] = 1;
        q0 = outputSamplePoints->size[1];
        c1Index_size[1] = outputSamplePoints->size[1];
        b_value = outVarMF_data[outputID].f1->data[mfID].params->data[3];
        c2Index_size[0] = 1;
        c2Index_size[1] = outputSamplePoints->size[1];
        b = outVarMF_data[outputID].f1->data[mfID].params->data[1];
        d = 2.0 * (outVarMF_data[outputID].f1->data[mfID].params->data[0] *
                   outVarMF_data[outputID].f1->data[mfID].params->data[0]);
        y_size[0] = 1;
        y_size[1] = outputSamplePoints->size[1];
        for (i1 = 0; i1 < q0; i1++) {
          a = outputSamplePoints_data[outputID +
                                      outputSamplePoints->size[0] * i1];
          c1Index_data[i1] = (a <= x0);
          c2Index_data[i1] = (a >= b_value);
          a -= b;
          y_data[i1] = -(a * a) / d;
        }
        i1 = y_size[1];
        x0 = outVarMF_data[outputID].f1->data[mfID].params->data[3];
        d = 2.0 * (outVarMF_data[outputID].f1->data[mfID].params->data[2] *
                   outVarMF_data[outputID].f1->data[mfID].params->data[2]);
        y1_size[0] = 1;
        y1_size[1] = outputSamplePoints->size[1];
        for (q0 = 0; q0 < i1; q0++) {
          y_data[q0] = exp(y_data[q0]);
          a = outputSamplePoints_data[outputID +
                                      outputSamplePoints->size[0] * q0] -
              x0;
          y1_data[q0] = -(a * a) / d;
        }
        i1 = y1_size[1];
        for (q0 = 0; q0 < i1; q0++) {
          y1_data[q0] = exp(y1_data[q0]);
        }
        if (y_size[1] == 1) {
          i1 = c1Index_size[1];
        } else {
          i1 = y_size[1];
        }
        if ((y_size[1] == c1Index_size[1]) && (i1 == c1Index_size[1]) &&
            (y1_size[1] == c2Index_size[1]) && (i1 == c2Index_size[1])) {
          q0 = y_size[1] - 1;
          for (i1 = 0; i1 <= q0; i1++) {
            boolean_T b1;
            boolean_T b_b;
            b_b = c1Index_data[i1];
            b1 = c2Index_data[i1];
            y_data[i1] = (y_data[i1] * (double)b_b + (1.0 - (double)b_b)) *
                         (y1_data[i1] * (double)b1 + (1.0 - (double)b1));
          }
        } else {
          c_binary_expand_op(y_data, y_size, c1Index_data, c1Index_size,
                             y1_data, y1_size, c2Index_data, c2Index_size);
        }
      } else if (c_isequal(outVarMF_data[outputID].f1->data[mfID].type, uv10)) {
        double b_value;
        double x0;
        x0 = -outVarMF_data[outputID].f1->data[mfID].params->data[0];
        b_value = outVarMF_data[outputID].f1->data[mfID].params->data[1];
        y1_size[0] = 1;
        q0 = outputSamplePoints->size[1];
        y1_size[1] = outputSamplePoints->size[1];
        for (i1 = 0; i1 < q0; i1++) {
          y1_data[i1] =
              x0 * (outputSamplePoints_data[outputID +
                                            outputSamplePoints->size[0] * i1] -
                    b_value);
        }
        i1 = y1_size[1];
        x0 = -outVarMF_data[outputID].f1->data[mfID].params->data[2];
        b_value = outVarMF_data[outputID].f1->data[mfID].params->data[3];
        y_size[0] = 1;
        y_size[1] = outputSamplePoints->size[1];
        for (q0 = 0; q0 < i1; q0++) {
          y1_data[q0] = exp(y1_data[q0]);
          y_data[q0] =
              x0 * (outputSamplePoints_data[outputID +
                                            outputSamplePoints->size[0] * q0] -
                    b_value);
        }
        i1 = y_size[1];
        for (q0 = 0; q0 < i1; q0++) {
          y_data[q0] = exp(y_data[q0]);
        }
        if (y1_size[1] == y_size[1]) {
          q0 = y1_size[1] - 1;
          for (i1 = 0; i1 <= q0; i1++) {
            y1_data[i1] = 1.0 / (y1_data[i1] + 1.0) - 1.0 / (y_data[i1] + 1.0);
          }
        } else {
          d_binary_expand_op(y1_data, y1_size, y_data, y_size);
        }
        i1 = y1_size[1];
        y_size[1] = y1_size[1];
        for (q0 = 0; q0 < i1; q0++) {
          y_data[q0] = fabs(y1_data[q0]);
        }
      } else if (c_isequal(outVarMF_data[outputID].f1->data[mfID].type, uv11)) {
        double b_value;
        double x0;
        x0 = -outVarMF_data[outputID].f1->data[mfID].params->data[0];
        b_value = outVarMF_data[outputID].f1->data[mfID].params->data[1];
        y_size[0] = 1;
        q0 = outputSamplePoints->size[1];
        y_size[1] = outputSamplePoints->size[1];
        for (i1 = 0; i1 < q0; i1++) {
          y_data[i1] =
              x0 * (outputSamplePoints_data[outputID +
                                            outputSamplePoints->size[0] * i1] -
                    b_value);
        }
        i1 = y_size[1];
        x0 = -outVarMF_data[outputID].f1->data[mfID].params->data[2];
        b_value = outVarMF_data[outputID].f1->data[mfID].params->data[3];
        y1_size[0] = 1;
        y1_size[1] = outputSamplePoints->size[1];
        for (q0 = 0; q0 < i1; q0++) {
          y_data[q0] = exp(y_data[q0]);
          y1_data[q0] =
              x0 * (outputSamplePoints_data[outputID +
                                            outputSamplePoints->size[0] * q0] -
                    b_value);
        }
        i1 = y1_size[1];
        for (q0 = 0; q0 < i1; q0++) {
          y1_data[q0] = exp(y1_data[q0]);
        }
        if (y_size[1] == y1_size[1]) {
          q0 = y_size[1] - 1;
          for (i1 = 0; i1 <= q0; i1++) {
            y_data[i1] = 1.0 / (y_data[i1] + 1.0) * (1.0 / (y1_data[i1] + 1.0));
          }
        } else {
          e_binary_expand_op(y_data, y_size, y1_data, y1_size);
        }
      } else if (j_isequal(outVarMF_data[outputID].f1->data[mfID].type)) {
        y1_size[0] = 1;
        q0 = outputSamplePoints->size[1];
        y1_size[1] = outputSamplePoints->size[1];
        for (i1 = 0; i1 < q0; i1++) {
          y1_data[i1] =
              outputSamplePoints_data[outputID +
                                      outputSamplePoints->size[0] * i1];
        }
        pimf(y1_data, y1_size, outVarMF_data[outputID].f1->data[mfID].params,
             y_data, y_size);
      } else {
        exit(0);
      }
      q0 = y_size[1];
      for (i1 = 0; i1 < q0; i1++) {
        outputMFCache_data[(qY + outputMFCache->size[0] * i1) - 1] = y_data[i1];
      }
    }
  }
  emxFree_cell_wrap_0(&outVarMF);
}

/*
 * File trailer for createMamdaniOutputMFCache.c
 *
 * [EOF]
 */
