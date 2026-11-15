/*
 * File: extractVarMF.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "extractVarMF.h"
#include "opkene_emxutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const e_emxArray_struct_T *varin
 *                emxArray_cell_wrap_0 *varout
 * Return Type  : void
 */
void extractVarMF(const e_emxArray_struct_T *varin,
                  emxArray_cell_wrap_0 *varout)
{
  cell_wrap_0 *varout_data;
  const e_struct_T *varin_data;
  h_emxArray_struct_T *mf;
  h_struct_T expl_temp;
  h_struct_T *mf_data;
  int b_i;
  int i;
  int i1;
  int j;
  varin_data = varin->data;
  i = varout->size[0] * varout->size[1];
  varout->size[0] = 1;
  varout->size[1] = varin->size[1];
  emxEnsureCapacity_cell_wrap_0(varout, i);
  varout_data = varout->data;
  i = varin->size[1];
  emxInit_struct_T7(&mf);
  emxInitStruct_struct_T8(&expl_temp);
  for (b_i = 0; b_i < i; b_i++) {
    int i2;
    int loop_ub;
    i1 = mf->size[0] * mf->size[1];
    mf->size[0] = 1;
    i2 = varin_data[b_i].origNumMF;
    mf->size[1] = i2;
    emxEnsureCapacity_struct_T7(mf, i1);
    mf_data = mf->data;
    for (j = 0; j < i2; j++) {
      int loop_ub_tmp;
      loop_ub_tmp = varin_data[b_i].mf->data[j].origTypeLength;
      if (loop_ub_tmp < 1) {
        loop_ub = 0;
      } else {
        loop_ub = loop_ub_tmp;
      }
      loop_ub_tmp = varin_data[b_i].mf->data[j].origParamLength;
      if (loop_ub_tmp < 1) {
        loop_ub_tmp = 0;
      }
      i1 = expl_temp.type->size[0] * expl_temp.type->size[1];
      expl_temp.type->size[0] = 1;
      expl_temp.type->size[1] = loop_ub;
      emxEnsureCapacity_char_T(expl_temp.type, i1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        expl_temp.type->data[i1] = varin_data[b_i].mf->data[j].type->data[i1];
      }
      i1 = expl_temp.params->size[0] * expl_temp.params->size[1];
      expl_temp.params->size[0] = 1;
      expl_temp.params->size[1] = loop_ub_tmp;
      emxEnsureCapacity_real_T(expl_temp.params, i1);
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        expl_temp.params->data[i1] =
            varin_data[b_i].mf->data[j].params->data[i1];
      }
      emxCopyStruct_struct_T7(&mf_data[j], &expl_temp);
    }
    i1 = varout_data[b_i].f1->size[0] * varout_data[b_i].f1->size[1];
    varout_data[b_i].f1->size[0] = 1;
    varout_data[b_i].f1->size[1] = mf->size[1];
    emxEnsureCapacity_struct_T7(varout_data[b_i].f1, i1);
    loop_ub = mf->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      emxCopyStruct_struct_T7(&varout_data[b_i].f1->data[i1], &mf_data[i1]);
    }
  }
  emxFreeStruct_struct_T8(&expl_temp);
  emxFree_struct_T7(&mf);
}

/*
 * File trailer for extractVarMF.c
 *
 * [EOF]
 */
