/*
 * File: extractVarMF.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "extractVarMF.h"
#include "opkene_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const d_emxArray_struct_T *varin
 *                emxArray_cell_wrap_0 *varout
 * Return Type  : void
 */
void extractVarMF(const d_emxArray_struct_T *varin, emxArray_cell_wrap_0 *varout)
{
  int i65;
  g_emxArray_struct_T *mf;
  int i;
  int i66;
  int j;
  int loop_ub;
  int b_loop_ub;
  int i67;
  i65 = varout->size[0] * varout->size[1];
  varout->size[0] = 1;
  varout->size[1] = varin->size[1];
  emxEnsureCapacity_cell_wrap_0(varout, i65);
  i65 = varin->size[1];
  emxInit_struct_T7(&mf, 2);
  for (i = 0; i < i65; i++) {
    i66 = mf->size[0] * mf->size[1];
    mf->size[0] = 1;
    mf->size[1] = varin->data[i].origNumMF;
    emxEnsureCapacity_struct_T7(mf, i66);
    i66 = varin->data[i].origNumMF;
    for (j = 0; j < i66; j++) {
      if (1 > varin->data[i].mf->data[j].origTypeLength) {
        loop_ub = 0;
      } else {
        loop_ub = varin->data[i].mf->data[j].origTypeLength;
      }

      if (1 > varin->data[i].mf->data[j].origParamLength) {
        b_loop_ub = 0;
      } else {
        b_loop_ub = varin->data[i].mf->data[j].origParamLength;
      }

      i67 = mf->data[j].type->size[0] * mf->data[j].type->size[1];
      mf->data[j].type->size[0] = 1;
      mf->data[j].type->size[1] = loop_ub;
      emxEnsureCapacity_char_T(mf->data[j].type, i67);
      for (i67 = 0; i67 < loop_ub; i67++) {
        mf->data[j].type->data[i67] = varin->data[i].mf->data[j].type->data[i67];
      }

      i67 = mf->data[j].params->size[0] * mf->data[j].params->size[1];
      mf->data[j].params->size[0] = 1;
      mf->data[j].params->size[1] = b_loop_ub;
      emxEnsureCapacity_real_T(mf->data[j].params, i67);
      for (i67 = 0; i67 < b_loop_ub; i67++) {
        mf->data[j].params->data[i67] = varin->data[i].mf->data[j].params->
          data[i67];
      }
    }

    i66 = varout->data[i].f1->size[0] * varout->data[i].f1->size[1];
    varout->data[i].f1->size[0] = 1;
    varout->data[i].f1->size[1] = mf->size[1];
    emxEnsureCapacity_struct_T7(varout->data[i].f1, i66);
    loop_ub = mf->size[0] * mf->size[1];
    for (i66 = 0; i66 < loop_ub; i66++) {
      emxCopyStruct_struct_T7(&varout->data[i].f1->data[i66], &mf->data[i66]);
    }
  }

  emxFree_struct_T7(&mf);
}

/*
 * File trailer for extractVarMF.c
 *
 * [EOF]
 */
