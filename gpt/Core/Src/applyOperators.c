/*
 * File: applyOperators.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "applyOperators.h"
#include "isequal.h"
#include "sum.h"

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
double applyOperators(const emxArray_real_T *fuzzifiedInputs, const
                      emxArray_uint8_T *fis_andMethod, const emxArray_uint8_T
                      *fis_orMethod, const emxArray_real_T *fis_connection,
                      const emxArray_real_T *fis_weight, int fis_numInputs, int
                      fis_numRules, emxArray_real_T *varargin_1, emxArray_real_T
                      *varargin_2)
{
  double sumAntecedentOutputs;
  int ruleID;
  int idx;
  double b_varargin_2;
  static const unsigned char uv62[3] = { 109U, 97U, 120U };

  static const unsigned char uv63[3] = { 109U, 105U, 110U };

  static const unsigned char uv64[6] = { 112U, 114U, 111U, 98U, 111U, 114U };

  int n;
  static const unsigned char uv65[4] = { 112U, 114U, 111U, 100U };

  static const unsigned char uv66[3] = { 115U, 117U, 109U };

  double tmp_data[1];
  int i86;
  int k;
  boolean_T exitg1;
  double c_varargin_2;
  sumAntecedentOutputs = 0.0;
  for (ruleID = 0; ruleID < fis_numRules; ruleID++) {
    for (idx = 0; idx < fis_numInputs; idx++) {
      varargin_2->data[idx] = fuzzifiedInputs->data[ruleID +
        fuzzifiedInputs->size[0] * idx];
    }

    if (fis_connection->data[ruleID] == 1.0) {
      b_varargin_2 = -1.0;
      if (h_isequal(fis_andMethod, uv63)) {
        n = varargin_2->size[0];
        if (varargin_2->size[0] <= 2) {
          if (varargin_2->size[0] == 1) {
            b_varargin_2 = varargin_2->data[0];
          } else if ((varargin_2->data[0] > varargin_2->data[1]) || (rtIsNaN
                      (varargin_2->data[0]) && (!rtIsNaN(varargin_2->data[1]))))
          {
            b_varargin_2 = varargin_2->data[1];
          } else {
            b_varargin_2 = varargin_2->data[0];
          }
        } else {
          if (!rtIsNaN(varargin_2->data[0])) {
            idx = 1;
          } else {
            idx = 0;
            k = 2;
            exitg1 = false;
            while ((!exitg1) && (k <= varargin_2->size[0])) {
              if (!rtIsNaN(varargin_2->data[k - 1])) {
                idx = k;
                exitg1 = true;
              } else {
                k++;
              }
            }
          }

          if (idx == 0) {
            b_varargin_2 = varargin_2->data[0];
          } else {
            b_varargin_2 = varargin_2->data[idx - 1];
            i86 = idx + 1;
            for (k = i86; k <= n; k++) {
              if (b_varargin_2 > varargin_2->data[k - 1]) {
                b_varargin_2 = varargin_2->data[k - 1];
              }
            }
          }
        }
      } else if (i_isequal(fis_andMethod, uv65)) {
        idx = varargin_2->size[0];
        if (varargin_2->size[0] == 0) {
          b_varargin_2 = 1.0;
        } else {
          b_varargin_2 = varargin_2->data[0];
          for (k = 2; k <= idx; k++) {
            b_varargin_2 *= varargin_2->data[k - 1];
          }
        }
      } else {
        exit(0);
      }

      varargin_1->data[ruleID] = b_varargin_2;
    } else {
      varargin_1->data[ruleID] = -1.0;
      if (h_isequal(fis_orMethod, uv62)) {
        n = varargin_2->size[0];
        if (varargin_2->size[0] <= 2) {
          if (varargin_2->size[0] == 1) {
            varargin_1->data[ruleID] = varargin_2->data[0];
          } else if ((varargin_2->data[0] < varargin_2->data[1]) || (rtIsNaN
                      (varargin_2->data[0]) && (!rtIsNaN(varargin_2->data[1]))))
          {
            varargin_1->data[ruleID] = varargin_2->data[1];
          } else {
            varargin_1->data[ruleID] = varargin_2->data[0];
          }
        } else {
          if (!rtIsNaN(varargin_2->data[0])) {
            idx = 1;
          } else {
            idx = 0;
            k = 2;
            exitg1 = false;
            while ((!exitg1) && (k <= varargin_2->size[0])) {
              if (!rtIsNaN(varargin_2->data[k - 1])) {
                idx = k;
                exitg1 = true;
              } else {
                k++;
              }
            }
          }

          if (idx == 0) {
            varargin_1->data[ruleID] = varargin_2->data[0];
          } else {
            b_varargin_2 = varargin_2->data[idx - 1];
            i86 = idx + 1;
            for (k = i86; k <= n; k++) {
              if (b_varargin_2 < varargin_2->data[k - 1]) {
                b_varargin_2 = varargin_2->data[k - 1];
              }
            }

            varargin_1->data[ruleID] = b_varargin_2;
          }
        }
      } else if (j_isequal(fis_orMethod, uv64)) {
        if (varargin_2->size[0] <= 1) {
          idx = varargin_2->size[0];
          for (i86 = 0; i86 < idx; i86++) {
            tmp_data[i86] = varargin_2->data[i86];
          }
        } else {
          tmp_data[0] = varargin_2->data[0];
          i86 = varargin_2->size[0];
          for (idx = 0; idx <= i86 - 2; idx++) {
            b_varargin_2 = varargin_2->data[idx + 1];
            c_varargin_2 = varargin_2->data[idx + 1];
            for (n = 0; n < 1; n++) {
              tmp_data[0] = (tmp_data[0] + b_varargin_2) - tmp_data[0] *
                c_varargin_2;
            }
          }
        }

        varargin_1->data[ruleID] = tmp_data[0];
      } else if (h_isequal(fis_orMethod, uv66)) {
        varargin_1->data[ruleID] = b_sum(varargin_2);
      } else {
        exit(0);
      }
    }

    varargin_1->data[ruleID] *= fis_weight->data[ruleID];
    sumAntecedentOutputs += varargin_1->data[ruleID];
  }

  return sumAntecedentOutputs;
}

/*
 * File trailer for applyOperators.c
 *
 * [EOF]
 */
