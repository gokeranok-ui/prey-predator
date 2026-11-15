/*
 * File: createMamdaniOutputMFCache.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "createMamdaniOutputMFCache.h"
#include "opkene_emxutil.h"
#include "trimf.h"
#include "trapmf.h"
#include "gaussmf.h"
#include "gbellmf.h"
#include "sigmf.h"
#include "smf.h"
#include "zmf.h"
#include "gauss2mf.h"
#include "dsigmf.h"
#include "psigmf.h"
#include "pimf.h"
#include "isequal.h"
#include "extractVarMF.h"
#include "sum.h"

/* Function Definitions */

/*
 * Arguments    : const d_emxArray_struct_T *fis_outputMF
 *                int fis_numOutputs
 *                const emxArray_int32_T *fis_numOutputMFs
 *                const emxArray_int32_T *fis_numCumOutputMFs
 *                const emxArray_real_T *outputSamplePoints
 *                emxArray_real_T *outputMFCache
 * Return Type  : void
 */
void createMamdaniOutputMFCache(const d_emxArray_struct_T *fis_outputMF, int
  fis_numOutputs, const emxArray_int32_T *fis_numOutputMFs, const
  emxArray_int32_T *fis_numCumOutputMFs, const emxArray_real_T
  *outputSamplePoints, emxArray_real_T *outputMFCache)
{
  emxArray_cell_wrap_0 *outVarMF;
  double d5;
  int i64;
  int outputID;
  int numMFs;
  int mfID;
  int q0;
  int q1;
  int x_size[2];
  double x_data[51];
  signed char unnamed_idx_1;
  int y_size[2];
  static const unsigned char uv26[5] = { 116U, 114U, 105U, 109U, 102U };

  double y_data[51];
  static const unsigned char uv27[6] = { 116U, 114U, 97U, 112U, 109U, 102U };

  static const unsigned char uv28[7] = { 103U, 97U, 117U, 115U, 115U, 109U, 102U
  };

  static const unsigned char uv29[7] = { 103U, 98U, 101U, 108U, 108U, 109U, 102U
  };

  static const unsigned char uv30[5] = { 115U, 105U, 103U, 109U, 102U };

  static const unsigned char uv31[3] = { 115U, 109U, 102U };

  static const unsigned char uv32[3] = { 122U, 109U, 102U };

  static const unsigned char uv33[8] = { 103U, 97U, 117U, 115U, 115U, 50U, 109U,
    102U };

  static const unsigned char uv34[6] = { 100U, 115U, 105U, 103U, 109U, 102U };

  static const unsigned char uv35[6] = { 112U, 115U, 105U, 103U, 109U, 102U };

  static const unsigned char uv36[4] = { 112U, 105U, 109U, 102U };

  emxInit_cell_wrap_0(&outVarMF, 2);
  d5 = sum(fis_numOutputMFs);
  i64 = outputMFCache->size[0] * outputMFCache->size[1];
  outputMFCache->size[0] = (int)d5;
  outputMFCache->size[1] = 51;
  emxEnsureCapacity_real_T(outputMFCache, i64);
  extractVarMF(fis_outputMF, outVarMF);
  for (outputID = 0; outputID < fis_numOutputs; outputID++) {
    numMFs = fis_numOutputMFs->data[outputID];
    for (mfID = 0; mfID < numMFs; mfID++) {
      q0 = fis_numCumOutputMFs->data[outputID];
      q1 = mfID + 1;
      if ((q0 < 0) && (q1 < MIN_int32_T - q0)) {
        q0 = MIN_int32_T;
      } else if ((q0 > 0) && (q1 > MAX_int32_T - q0)) {
        q0 = MAX_int32_T;
      } else {
        q0 += q1;
      }

      i64 = q0 - 1;
      q0 = outputSamplePoints->size[1];
      x_size[0] = 1;
      x_size[1] = q0;
      for (q1 = 0; q1 < q0; q1++) {
        x_data[q1] = outputSamplePoints->data[outputID +
          outputSamplePoints->size[0] * q1];
      }

      q0 = outputSamplePoints->size[1];
      unnamed_idx_1 = (signed char)q0;
      y_size[1] = unnamed_idx_1;
      q0 = unnamed_idx_1;
      for (q1 = 0; q1 < q0; q1++) {
        y_data[q1] = -1.0;
      }

      if (b_isequal(outVarMF->data[outputID].f1->data[mfID].type, uv26)) {
        trimf(x_data, x_size, outVarMF->data[outputID].f1->data[mfID].params,
              y_data, y_size);
      } else if (c_isequal(outVarMF->data[outputID].f1->data[mfID].type, uv27))
      {
        trapmf(x_data, x_size, outVarMF->data[outputID].f1->data[mfID].params,
               y_data, y_size);
      } else if (d_isequal(outVarMF->data[outputID].f1->data[mfID].type, uv28))
      {
        gaussmf(x_data, x_size, outVarMF->data[outputID].f1->data[mfID].params,
                y_data, y_size);
      } else if (d_isequal(outVarMF->data[outputID].f1->data[mfID].type, uv29))
      {
        gbellmf(x_data, x_size, outVarMF->data[outputID].f1->data[mfID].params,
                y_data, y_size);
      } else if (b_isequal(outVarMF->data[outputID].f1->data[mfID].type, uv30))
      {
        sigmf(x_data, x_size, outVarMF->data[outputID].f1->data[mfID].params,
              y_data, y_size);
      } else if (e_isequal(outVarMF->data[outputID].f1->data[mfID].type, uv31))
      {
        smf(x_data, x_size, outVarMF->data[outputID].f1->data[mfID].params,
            y_data, y_size);
      } else if (e_isequal(outVarMF->data[outputID].f1->data[mfID].type, uv32))
      {
        zmf(x_data, x_size, outVarMF->data[outputID].f1->data[mfID].params,
            y_data, y_size);
      } else if (f_isequal(outVarMF->data[outputID].f1->data[mfID].type, uv33))
      {
        gauss2mf(x_data, x_size, outVarMF->data[outputID].f1->data[mfID].params,
                 y_data, y_size);
      } else if (c_isequal(outVarMF->data[outputID].f1->data[mfID].type, uv34))
      {
        dsigmf(x_data, x_size, outVarMF->data[outputID].f1->data[mfID].params,
               y_data, y_size);
      } else if (c_isequal(outVarMF->data[outputID].f1->data[mfID].type, uv35))
      {
        psigmf(x_data, x_size, outVarMF->data[outputID].f1->data[mfID].params,
               y_data, y_size);
      } else if (g_isequal(outVarMF->data[outputID].f1->data[mfID].type, uv36))
      {
        pimf(x_data, x_size, outVarMF->data[outputID].f1->data[mfID].params,
             y_data, y_size);
      } else {
        exit(0);
      }

      q0 = y_size[1];
      for (q1 = 0; q1 < q0; q1++) {
        outputMFCache->data[i64 + outputMFCache->size[0] * q1] = y_data[q1];
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
