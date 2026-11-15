/*
 * File: applyOperators.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "applyOperators.h"
#include "isequal.h"
#include "minOrMax.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *fuzzifiedInputs
 *                const emxArray_uint8_T *fis_andMethod
 *                const emxArray_uint8_T *fis_orMethod
 *                const emxArray_real_T *fis_connection
 *                const emxArray_real_T *fis_weight
 *                int fis_numInputs
 *                int fis_numRules
 *                emxArray_real_T *varargin_1
 *                emxArray_real_T *varargin_2
 * Return Type  : double
 */
double applyOperators(const emxArray_real_T *fuzzifiedInputs,
                      const emxArray_uint8_T *fis_andMethod,
                      const emxArray_uint8_T *fis_orMethod,
                      const emxArray_real_T *fis_connection,
                      const emxArray_real_T *fis_weight, int fis_numInputs,
                      int fis_numRules, emxArray_real_T *varargin_1,
                      emxArray_real_T *varargin_2)
{
  static const unsigned char uv2[6] = {112U, 114U, 111U, 98U, 111U, 114U};
  static const unsigned char uv[3] = {109U, 97U, 120U};
  static const unsigned char uv1[3] = {109U, 105U, 110U};
  static const unsigned char uv3[3] = {115U, 117U, 109U};
  const double *fis_connection_data;
  const double *fis_weight_data;
  const double *fuzzifiedInputs_data;
  double sumAntecedentOutputs;
  double *varargin_1_data;
  double *varargin_2_data;
  int i;
  int i1;
  int k;
  int ruleID;
  unsigned int u;
  int vlen;
  varargin_2_data = varargin_2->data;
  varargin_1_data = varargin_1->data;
  fis_weight_data = fis_weight->data;
  fis_connection_data = fis_connection->data;
  fuzzifiedInputs_data = fuzzifiedInputs->data;
  sumAntecedentOutputs = 0.0;
  u = (unsigned int)fis_numRules;
  if ((unsigned int)fis_numRules > 2147483647UL) {
    u = 2147483647UL;
  }
  i = (int)u;
  for (ruleID = 0; ruleID < i; ruleID++) {
    double b_varargin_2;
    u = (unsigned int)fis_numInputs;
    if ((unsigned int)fis_numInputs > 2147483647UL) {
      u = 2147483647UL;
    }
    i1 = (int)u;
    for (vlen = 0; vlen < i1; vlen++) {
      varargin_2_data[vlen] =
          fuzzifiedInputs_data[ruleID + fuzzifiedInputs->size[0] * vlen];
    }
    if (fis_connection_data[ruleID] == 1.0) {
      double tmp_data;
      tmp_data = -1.0;
      if (g_isequal(fis_andMethod, uv1)) {
        int last;
        last = varargin_2->size[0];
        if (varargin_2->size[0] <= 2) {
          if (varargin_2->size[0] == 1) {
            tmp_data = varargin_2_data[0];
          } else {
            tmp_data = varargin_2_data[varargin_2->size[0] - 1];
            if ((!(varargin_2_data[0] > tmp_data)) &&
                ((!rtIsNaN(varargin_2_data[0])) || rtIsNaN(tmp_data))) {
              tmp_data = varargin_2_data[0];
            }
          }
        } else {
          if (!rtIsNaN(varargin_2_data[0])) {
            vlen = 1;
          } else {
            boolean_T exitg1;
            vlen = 0;
            k = 2;
            exitg1 = false;
            while ((!exitg1) && (k <= last)) {
              if (!rtIsNaN(varargin_2_data[k - 1])) {
                vlen = k;
                exitg1 = true;
              } else {
                k++;
              }
            }
          }
          if (vlen == 0) {
            tmp_data = varargin_2_data[0];
          } else {
            tmp_data = varargin_2_data[vlen - 1];
            i1 = vlen + 1;
            for (k = i1; k <= last; k++) {
              b_varargin_2 = varargin_2_data[k - 1];
              if (tmp_data > b_varargin_2) {
                tmp_data = b_varargin_2;
              }
            }
          }
        }
      } else if (k_isequal(fis_andMethod)) {
        vlen = varargin_2->size[0];
        if (varargin_2->size[0] == 0) {
          tmp_data = 1.0;
        } else {
          tmp_data = varargin_2_data[0];
          for (k = 2; k <= vlen; k++) {
            tmp_data *= varargin_2_data[k - 1];
          }
        }
      } else {
        exit(0);
      }
      varargin_1_data[ruleID] = tmp_data;
    } else {
      varargin_1_data[ruleID] = -1.0;
      if (g_isequal(fis_orMethod, uv)) {
        varargin_1_data[ruleID] = maximum(varargin_2);
      } else if (h_isequal(fis_orMethod, uv2)) {
        double tmp_data;
        if (varargin_2->size[0] <= 1) {
          vlen = varargin_2->size[0];
          for (i1 = 0; i1 < vlen; i1++) {
            tmp_data = varargin_2_data[i1];
          }
        } else {
          tmp_data = varargin_2_data[0];
          i1 = varargin_2->size[0];
          for (vlen = 0; vlen <= i1 - 2; vlen++) {
            b_varargin_2 = varargin_2_data[vlen + 1];
            tmp_data = (tmp_data + b_varargin_2) - tmp_data * b_varargin_2;
          }
        }
        varargin_1_data[ruleID] = tmp_data;
      } else if (g_isequal(fis_orMethod, uv3)) {
        varargin_1_data[ruleID] = b_sum(varargin_2);
      } else {
        exit(0);
      }
    }
    b_varargin_2 = varargin_1_data[ruleID] * fis_weight_data[ruleID];
    varargin_1_data[ruleID] = b_varargin_2;
    sumAntecedentOutputs += b_varargin_2;
  }
  return sumAntecedentOutputs;
}

/*
 * File trailer for applyOperators.c
 *
 * [EOF]
 */
