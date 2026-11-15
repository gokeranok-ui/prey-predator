//
// File: createMamdaniOutputMFCache.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "createMamdaniOutputMFCache.h"
#include "extractVarMF.h"
#include "gauss2mf.h"
#include "gbellmf.h"
#include "isequal.h"
#include "opkene_internal_types.h"
#include "pimf.h"
#include "rt_nonfinite.h"
#include "trapmf.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const ::coder::array<e_struct_T, 2U> &fis_outputMF
//                int fis_numOutputs
//                const ::coder::array<int, 2U> &fis_numOutputMFs
//                const ::coder::array<int, 2U> &fis_numCumOutputMFs
//                const ::coder::array<double, 2U> &outputSamplePoints
//                ::coder::array<double, 2U> &outputMFCache
// Return Type  : void
//
namespace coder
{
  void createMamdaniOutputMFCache(const ::coder::array<e_struct_T, 2U>
    &fis_outputMF, int fis_numOutputs, const ::coder::array<int, 2U>
    &fis_numOutputMFs, const ::coder::array<int, 2U> &fis_numCumOutputMFs, const
    ::coder::array<double, 2U> &outputSamplePoints, ::coder::array<double, 2U>
    &outputMFCache)
  {
    static const unsigned char uv7[8] = { 103U, 97U, 117U, 115U, 115U, 50U, 109U,
      102U };

    static const unsigned char uv2[7] = { 103U, 97U, 117U, 115U, 115U, 109U,
      102U };

    static const unsigned char uv3[7] = { 103U, 98U, 101U, 108U, 108U, 109U,
      102U };

    static const unsigned char uv1[6] = { 116U, 114U, 97U, 112U, 109U, 102U };

    static const unsigned char uv8[6] = { 100U, 115U, 105U, 103U, 109U, 102U };

    static const unsigned char uv9[6] = { 112U, 115U, 105U, 103U, 109U, 102U };

    static const unsigned char uv[5] = { 116U, 114U, 105U, 109U, 102U };

    static const unsigned char uv4[5] = { 115U, 105U, 103U, 109U, 102U };

    static const unsigned char uv10[4] = { 112U, 105U, 109U, 102U };

    static const unsigned char uv5[3] = { 115U, 109U, 102U };

    static const unsigned char uv6[3] = { 122U, 109U, 102U };

    array<cell_wrap_0, 2U> outVarMF;
    double outputSamplePoints_data[51];
    double y_data[51];
    double x1;
    int outputSamplePoints_size[2];
    int y_size[2];
    int i;
    int k;
    int loop_ub;
    int q0;
    int vlen;
    vlen = fis_numOutputMFs.size(1);
    if (fis_numOutputMFs.size(1) == 0) {
      x1 = 0.0;
    } else {
      x1 = fis_numOutputMFs[0];
      for (k = 2; k <= vlen; k++) {
        x1 += static_cast<double>(fis_numOutputMFs[k - 1]);
      }
    }

    outputMFCache.set_size((static_cast<int>(x1)), 51);
    fuzzy::internal::codegen::extractVarMF(fis_outputMF, outVarMF);
    for (int outputID = 0; outputID < fis_numOutputs; outputID++) {
      int numMFs;
      numMFs = fis_numOutputMFs[outputID];
      if (0 <= numMFs - 1) {
        q0 = fis_numCumOutputMFs[outputID];
        i = outputSamplePoints.size(1);
        loop_ub = static_cast<signed char>(i);
      }

      for (int mfID = 0; mfID < numMFs; mfID++) {
        int i1;
        int qY;
        if ((q0 < 0) && (mfID + 1 < MIN_int32_T - q0)) {
          qY = MIN_int32_T;
        } else if ((q0 > 0) && (mfID + 1 > MAX_int32_T - q0)) {
          qY = MAX_int32_T;
        } else {
          qY = (q0 + mfID) + 1;
        }

        y_size[1] = static_cast<signed char>(i);
        for (i1 = 0; i1 < loop_ub; i1++) {
          y_data[i1] = -1.0;
        }

        if (isequal(outVarMF[outputID].f1[mfID].type, uv)) {
          double c;
          double x0;
          x1 = outVarMF[outputID].f1[mfID].params[0];
          x0 = outVarMF[outputID].f1[mfID].params[1];
          c = outVarMF[outputID].f1[mfID].params[2];
          i1 = outputSamplePoints.size(1);
          y_size[1] = static_cast<signed char>(i1);
          vlen = static_cast<signed char>(i1);
          if (0 <= vlen - 1) {
            std::memset(&y_data[0], 0, vlen * sizeof(double));
          }

          i1 = outputSamplePoints.size(1) - 1;
          for (vlen = 0; vlen <= i1; vlen++) {
            if ((x1 != x0) && (x1 < outputSamplePoints[outputID +
                               outputSamplePoints.size(0) * vlen]) &&
                (outputSamplePoints[outputID + outputSamplePoints.size(0) * vlen]
                 < x0)) {
              y_data[vlen] = (outputSamplePoints[outputID +
                              outputSamplePoints.size(0) * vlen] - x1) * (1.0 /
                (x0 - x1));
            }

            if ((x0 != c) && (x0 < outputSamplePoints[outputID +
                              outputSamplePoints.size(0) * vlen]) &&
                (outputSamplePoints[outputID + outputSamplePoints.size(0) * vlen]
                 < c)) {
              y_data[vlen] = (c - outputSamplePoints[outputID +
                              outputSamplePoints.size(0) * vlen]) * (1.0 / (c -
                x0));
            }

            if (outputSamplePoints[outputID + outputSamplePoints.size(0) * vlen]
                == x0) {
              y_data[vlen] = 1.0;
            }
          }
        } else if (b_isequal(outVarMF[outputID].f1[mfID].type, uv1)) {
          vlen = outputSamplePoints.size(1);
          outputSamplePoints_size[0] = 1;
          outputSamplePoints_size[1] = outputSamplePoints.size(1);
          for (i1 = 0; i1 < vlen; i1++) {
            outputSamplePoints_data[i1] = outputSamplePoints[outputID +
              outputSamplePoints.size(0) * i1];
          }

          trapmf(outputSamplePoints_data, outputSamplePoints_size,
                 outVarMF[outputID].f1[mfID].params, y_data, y_size);
        } else if (c_isequal(outVarMF[outputID].f1[mfID].type, uv2)) {
          double c;
          x1 = outVarMF[outputID].f1[mfID].params[1];
          vlen = outputSamplePoints.size(1);
          outputSamplePoints_size[1] = outputSamplePoints.size(1);
          for (i1 = 0; i1 < vlen; i1++) {
            outputSamplePoints_data[i1] = outputSamplePoints[outputID +
              outputSamplePoints.size(0) * i1] - x1;
          }

          y_size[1] = static_cast<signed char>(outputSamplePoints_size[1]);
          vlen = static_cast<signed char>(outputSamplePoints_size[1]);
          for (k = 0; k < vlen; k++) {
            c = outputSamplePoints_data[k];
            y_data[k] = c * c;
          }

          c = 2.0 * (outVarMF[outputID].f1[mfID].params[0] * outVarMF[outputID].
                     f1[mfID].params[0]);
          vlen = static_cast<signed char>(outputSamplePoints_size[1]) - 1;
          for (i1 = 0; i1 <= vlen; i1++) {
            y_data[i1] = -y_data[i1] / c;
          }

          vlen = static_cast<signed char>(outputSamplePoints_size[1]);
          for (k = 0; k < vlen; k++) {
            y_data[k] = std::exp(y_data[k]);
          }
        } else if (c_isequal(outVarMF[outputID].f1[mfID].type, uv3)) {
          vlen = outputSamplePoints.size(1);
          outputSamplePoints_size[0] = 1;
          outputSamplePoints_size[1] = outputSamplePoints.size(1);
          for (i1 = 0; i1 < vlen; i1++) {
            outputSamplePoints_data[i1] = outputSamplePoints[outputID +
              outputSamplePoints.size(0) * i1];
          }

          gbellmf(outputSamplePoints_data, outputSamplePoints_size,
                  outVarMF[outputID].f1[mfID].params, y_data, y_size);
        } else if (isequal(outVarMF[outputID].f1[mfID].type, uv4)) {
          double x0;
          x1 = -outVarMF[outputID].f1[mfID].params[0];
          x0 = outVarMF[outputID].f1[mfID].params[1];
          vlen = outputSamplePoints.size(1);
          y_size[1] = outputSamplePoints.size(1);
          for (i1 = 0; i1 < vlen; i1++) {
            y_data[i1] = x1 * (outputSamplePoints[outputID +
                               outputSamplePoints.size(0) * i1] - x0);
          }

          vlen = y_size[1];
          for (k = 0; k < vlen; k++) {
            y_data[k] = std::exp(y_data[k]);
          }

          vlen = y_size[1] - 1;
          for (i1 = 0; i1 <= vlen; i1++) {
            y_data[i1] = 1.0 / (y_data[i1] + 1.0);
          }
        } else if (d_isequal(outVarMF[outputID].f1[mfID].type, uv5)) {
          double x0;
          x0 = outVarMF[outputID].f1[mfID].params[0];
          x1 = outVarMF[outputID].f1[mfID].params[1];
          if (outVarMF[outputID].f1[mfID].params[0] >= outVarMF[outputID]
              .f1[mfID].params[1]) {
            x1 = (outVarMF[outputID].f1[mfID].params[0] + outVarMF[outputID]
                  .f1[mfID].params[1]) / 2.0;
            vlen = outputSamplePoints.size(1);
            y_size[1] = outputSamplePoints.size(1);
            for (i1 = 0; i1 < vlen; i1++) {
              y_data[i1] = (outputSamplePoints[outputID +
                            outputSamplePoints.size(0) * i1] >= x1);
            }
          } else {
            i1 = outputSamplePoints.size(1);
            y_size[1] = static_cast<signed char>(i1);
            vlen = static_cast<signed char>(i1);
            if (0 <= vlen - 1) {
              std::memset(&y_data[0], 0, vlen * sizeof(double));
            }

            i1 = outputSamplePoints.size(1) - 1;
            for (vlen = 0; vlen <= i1; vlen++) {
              double c;
              double value;
              c = outputSamplePoints[outputID + outputSamplePoints.size(0) *
                vlen];
              if ((x0 < c) && (c <= (x0 + x1) / 2.0)) {
                value = (c - x0) * (1.0 / (x1 - x0));
                y_data[vlen] = 2.0 * value * value;
              }

              if (((x0 + x1) / 2.0 < c) && (c <= x1)) {
                value = (x1 - c) * (1.0 / (x1 - x0));
                y_data[vlen] = 1.0 - 2.0 * value * value;
              }

              if (x1 <= c) {
                y_data[vlen] = 1.0;
              }
            }
          }
        } else if (d_isequal(outVarMF[outputID].f1[mfID].type, uv6)) {
          double x0;
          x1 = outVarMF[outputID].f1[mfID].params[0];
          x0 = outVarMF[outputID].f1[mfID].params[1];
          if (outVarMF[outputID].f1[mfID].params[0] >= outVarMF[outputID]
              .f1[mfID].params[1]) {
            x1 = (outVarMF[outputID].f1[mfID].params[1] + outVarMF[outputID]
                  .f1[mfID].params[0]) / 2.0;
            vlen = outputSamplePoints.size(1);
            y_size[1] = outputSamplePoints.size(1);
            for (i1 = 0; i1 < vlen; i1++) {
              y_data[i1] = (outputSamplePoints[outputID +
                            outputSamplePoints.size(0) * i1] <= x1);
            }
          } else {
            i1 = outputSamplePoints.size(1);
            y_size[1] = static_cast<signed char>(i1);
            vlen = static_cast<signed char>(i1);
            if (0 <= vlen - 1) {
              std::memset(&y_data[0], 0, vlen * sizeof(double));
            }

            i1 = outputSamplePoints.size(1) - 1;
            for (vlen = 0; vlen <= i1; vlen++) {
              double c;
              double value;
              c = outputSamplePoints[outputID + outputSamplePoints.size(0) *
                vlen];
              if (c <= x1) {
                y_data[vlen] = 1.0;
              }

              if ((x1 < c) && (c <= (x1 + x0) / 2.0)) {
                value = (c - x1) * (1.0 / (x1 - x0));
                y_data[vlen] = 1.0 - 2.0 * value * value;
              }

              if (((x1 + x0) / 2.0 < c) && (c <= x0)) {
                value = (x0 - c) * (1.0 / (x1 - x0));
                y_data[vlen] = 2.0 * value * value;
              }

              if (x0 <= c) {
                y_data[vlen] = 0.0;
              }
            }
          }
        } else if (e_isequal(outVarMF[outputID].f1[mfID].type, uv7)) {
          vlen = outputSamplePoints.size(1);
          outputSamplePoints_size[0] = 1;
          outputSamplePoints_size[1] = outputSamplePoints.size(1);
          for (i1 = 0; i1 < vlen; i1++) {
            outputSamplePoints_data[i1] = outputSamplePoints[outputID +
              outputSamplePoints.size(0) * i1];
          }

          gauss2mf(outputSamplePoints_data, outputSamplePoints_size,
                   outVarMF[outputID].f1[mfID].params, y_data, y_size);
        } else if (b_isequal(outVarMF[outputID].f1[mfID].type, uv8)) {
          double x0;
          x1 = -outVarMF[outputID].f1[mfID].params[0];
          x0 = outVarMF[outputID].f1[mfID].params[1];
          vlen = outputSamplePoints.size(1);
          outputSamplePoints_size[1] = outputSamplePoints.size(1);
          for (i1 = 0; i1 < vlen; i1++) {
            outputSamplePoints_data[i1] = x1 * (outputSamplePoints[outputID +
              outputSamplePoints.size(0) * i1] - x0);
          }

          vlen = outputSamplePoints_size[1];
          for (k = 0; k < vlen; k++) {
            outputSamplePoints_data[k] = std::exp(outputSamplePoints_data[k]);
          }

          x1 = -outVarMF[outputID].f1[mfID].params[2];
          x0 = outVarMF[outputID].f1[mfID].params[3];
          vlen = outputSamplePoints.size(1);
          y_size[1] = outputSamplePoints.size(1);
          for (i1 = 0; i1 < vlen; i1++) {
            y_data[i1] = x1 * (outputSamplePoints[outputID +
                               outputSamplePoints.size(0) * i1] - x0);
          }

          vlen = y_size[1];
          for (k = 0; k < vlen; k++) {
            y_data[k] = std::exp(y_data[k]);
          }

          vlen = outputSamplePoints_size[1] - 1;
          for (i1 = 0; i1 <= vlen; i1++) {
            outputSamplePoints_data[i1] = 1.0 / (outputSamplePoints_data[i1] +
              1.0) - 1.0 / (y_data[i1] + 1.0);
          }

          i1 = outputSamplePoints_size[1];
          y_size[1] = static_cast<signed char>(outputSamplePoints_size[1]);
          for (k = 0; k < i1; k++) {
            y_data[k] = std::abs(outputSamplePoints_data[k]);
          }
        } else if (b_isequal(outVarMF[outputID].f1[mfID].type, uv9)) {
          double x0;
          x1 = -outVarMF[outputID].f1[mfID].params[0];
          x0 = outVarMF[outputID].f1[mfID].params[1];
          vlen = outputSamplePoints.size(1);
          y_size[1] = outputSamplePoints.size(1);
          for (i1 = 0; i1 < vlen; i1++) {
            y_data[i1] = x1 * (outputSamplePoints[outputID +
                               outputSamplePoints.size(0) * i1] - x0);
          }

          vlen = y_size[1];
          for (k = 0; k < vlen; k++) {
            y_data[k] = std::exp(y_data[k]);
          }

          x1 = -outVarMF[outputID].f1[mfID].params[2];
          x0 = outVarMF[outputID].f1[mfID].params[3];
          vlen = outputSamplePoints.size(1);
          outputSamplePoints_size[1] = outputSamplePoints.size(1);
          for (i1 = 0; i1 < vlen; i1++) {
            outputSamplePoints_data[i1] = x1 * (outputSamplePoints[outputID +
              outputSamplePoints.size(0) * i1] - x0);
          }

          vlen = outputSamplePoints_size[1];
          for (k = 0; k < vlen; k++) {
            outputSamplePoints_data[k] = std::exp(outputSamplePoints_data[k]);
          }

          vlen = y_size[1] - 1;
          for (i1 = 0; i1 <= vlen; i1++) {
            y_data[i1] = 1.0 / (y_data[i1] + 1.0) * (1.0 /
              (outputSamplePoints_data[i1] + 1.0));
          }
        } else if (f_isequal(outVarMF[outputID].f1[mfID].type, uv10)) {
          vlen = outputSamplePoints.size(1);
          outputSamplePoints_size[0] = 1;
          outputSamplePoints_size[1] = outputSamplePoints.size(1);
          for (i1 = 0; i1 < vlen; i1++) {
            outputSamplePoints_data[i1] = outputSamplePoints[outputID +
              outputSamplePoints.size(0) * i1];
          }

          pimf(outputSamplePoints_data, outputSamplePoints_size,
               outVarMF[outputID].f1[mfID].params, y_data, y_size);
        } else {
          exit(0);
        }

        vlen = y_size[1];
        for (i1 = 0; i1 < vlen; i1++) {
          outputMFCache[(qY + outputMFCache.size(0) * i1) - 1] = y_data[i1];
        }
      }
    }
  }
}

//
// File trailer for createMamdaniOutputMFCache.cpp
//
// [EOF]
//
