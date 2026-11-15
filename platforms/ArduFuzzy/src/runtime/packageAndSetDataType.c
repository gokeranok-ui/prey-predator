/*
 * File: packageAndSetDataType.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "packageAndSetDataType.h"
#include "opkene_emxutil.h"
#include "opkene_rtwutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : i_struct_T *in1
 *                const emxArray_real_T *in2
 *                const emxArray_real_T *in3
 * Return Type  : void
 */
void b_binary_expand_op(i_struct_T *in1, const emxArray_real_T *in2,
                        const emxArray_real_T *in3)
{
  const double *in2_data;
  const double *in3_data;
  int aux_0_1;
  int aux_1_1;
  int i;
  int i1;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in3_data = in3->data;
  in2_data = in2->data;
  i = in1->numCumInputMFs->size[0] * in1->numCumInputMFs->size[1];
  in1->numCumInputMFs->size[0] = in2->size[0];
  emxEnsureCapacity_int32_T(in1->numCumInputMFs, i);
  if (in3->size[1] == 1) {
    loop_ub = in2->size[1];
  } else {
    loop_ub = in3->size[1];
  }
  i = in1->numCumInputMFs->size[0] * in1->numCumInputMFs->size[1];
  in1->numCumInputMFs->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(in1->numCumInputMFs, i);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < loop_ub; i++) {
    int b_loop_ub;
    b_loop_ub = in2->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      double d;
      int i2;
      d = rt_roundd_snf(in2_data[i1 + in2->size[0] * aux_0_1] -
                        in3_data[i1 + aux_1_1]);
      if (d < 2.147483648E+9) {
        if (d >= -2.147483648E+9) {
          i2 = (int)d;
        } else {
          i2 = MIN_int32_T;
        }
      } else if (d >= 2.147483648E+9) {
        i2 = MAX_int32_T;
      } else {
        i2 = 0;
      }
      in1->numCumInputMFs->data[i1 + i] = i2;
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

/*
 * Arguments    : i_struct_T *in1
 *                const emxArray_real_T *in2
 *                const emxArray_real_T *in3
 * Return Type  : void
 */
void binary_expand_op(i_struct_T *in1, const emxArray_real_T *in2,
                      const emxArray_real_T *in3)
{
  const double *in2_data;
  const double *in3_data;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in3_data = in3->data;
  in2_data = in2->data;
  i = in1->numCumOutputMFs->size[0] * in1->numCumOutputMFs->size[1];
  in1->numCumOutputMFs->size[0] = 1;
  emxEnsureCapacity_int32_T(in1->numCumOutputMFs, i);
  if (in3->size[1] == 1) {
    loop_ub = in2->size[1];
  } else {
    loop_ub = in3->size[1];
  }
  i = in1->numCumOutputMFs->size[0] * in1->numCumOutputMFs->size[1];
  in1->numCumOutputMFs->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(in1->numCumOutputMFs, i);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_1 = (in3->size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    double d;
    int i1;
    d = rt_roundd_snf(in2_data[i * stride_0_1] - in3_data[i * stride_1_1]);
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        i1 = (int)d;
      } else {
        i1 = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      i1 = MAX_int32_T;
    } else {
      i1 = 0;
    }
    in1->numCumOutputMFs->data[i] = i1;
  }
}

/*
 * Arguments    : const b_emxArray_struct_T *in
 *                g_emxArray_struct_T *out
 * Return Type  : void
 */
void makeHomogenousMF(const b_emxArray_struct_T *in, g_emxArray_struct_T *out)
{
  const b_struct_T *in_data;
  f_struct_T mfStruct;
  g_struct_T varStruct;
  g_struct_T *out_data;
  double maxMFParamLength;
  double maxMFTypeLength;
  double maxNumMF;
  int b_loop_ub;
  int i;
  int i1;
  int i2;
  int loop_ub;
  int mfID;
  int outsize_idx_1;
  int varID;
  in_data = in->data;
  emxInitStruct_struct_T4(&mfStruct);
  i = mfStruct.type->size[0] * mfStruct.type->size[1];
  mfStruct.type->size[0] = 1;
  mfStruct.type->size[1] = 1;
  emxEnsureCapacity_char_T(mfStruct.type, i);
  mfStruct.type->data[0] = '\x00';
  mfStruct.origTypeLength = 0.0;
  i = mfStruct.params->size[0] * mfStruct.params->size[1];
  mfStruct.params->size[0] = 1;
  mfStruct.params->size[1] = 1;
  emxEnsureCapacity_real_T(mfStruct.params, i);
  mfStruct.params->data[0] = 0.0;
  mfStruct.origParamLength = 0.0;
  emxInitStruct_struct_T5(&varStruct);
  i = varStruct.mf->size[0] * varStruct.mf->size[1];
  varStruct.mf->size[0] = 1;
  varStruct.mf->size[1] = 1;
  emxEnsureCapacity_struct_T3(varStruct.mf, i);
  emxCopyStruct_struct_T3(&varStruct.mf->data[0], &mfStruct);
  varStruct.origNumMF = 0.0;
  i = out->size[0] * out->size[1];
  out->size[0] = 1;
  out->size[1] = in->size[1];
  emxEnsureCapacity_struct_T4(out, i);
  out_data = out->data;
  loop_ub = in->size[1];
  maxNumMF = 0.0;
  maxMFTypeLength = 0.0;
  maxMFParamLength = 0.0;
  for (varID = 0; varID < loop_ub; varID++) {
    emxCopyStruct_struct_T4(&out_data[varID], &varStruct);
    if (maxNumMF < in_data[varID].origNumMF) {
      maxNumMF = in_data[varID].origNumMF;
    }
    i = (int)in_data[varID].origNumMF;
    for (mfID = 0; mfID < i; mfID++) {
      if (maxMFTypeLength < in_data[varID].mf->data[mfID].origTypeLength) {
        maxMFTypeLength = in_data[varID].mf->data[mfID].origTypeLength;
      }
      if (maxMFParamLength < in_data[varID].mf->data[mfID].origParamLength) {
        maxMFParamLength = in_data[varID].mf->data[mfID].origParamLength;
      }
    }
  }
  emxFreeStruct_struct_T7(&varStruct);
  i = in->size[1];
  if (in->size[1] - 1 >= 0) {
    outsize_idx_1 = (int)maxNumMF;
    b_loop_ub = (int)maxNumMF;
    i1 = (int)maxNumMF;
  }
  for (varID = 0; varID < i; varID++) {
    out_data[varID].origNumMF = in_data[varID].origNumMF;
    i2 = out_data[varID].mf->size[0] * out_data[varID].mf->size[1];
    out_data[varID].mf->size[0] = 1;
    out_data[varID].mf->size[1] = outsize_idx_1;
    emxEnsureCapacity_struct_T3(out_data[varID].mf, i2);
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      emxCopyStruct_struct_T3(&out_data[varID].mf->data[i2], &mfStruct);
    }
    for (mfID = 0; mfID < i1; mfID++) {
      i2 = out_data[varID].mf->data[mfID].type->size[0] *
           out_data[varID].mf->data[mfID].type->size[1];
      out_data[varID].mf->data[mfID].type->size[0] = 1;
      out_data[varID].mf->data[mfID].type->size[1] = (int)maxMFTypeLength;
      emxEnsureCapacity_char_T(out_data[varID].mf->data[mfID].type, i2);
      loop_ub = out_data[varID].mf->data[mfID].type->size[1];
      i2 = out_data[varID].mf->data[mfID].type->size[0] *
           out_data[varID].mf->data[mfID].type->size[1];
      out_data[varID].mf->data[mfID].type->size[0] = 1;
      out_data[varID].mf->data[mfID].type->size[1] = loop_ub;
      emxEnsureCapacity_char_T(out_data[varID].mf->data[mfID].type, i2);
      for (i2 = 0; i2 < loop_ub; i2++) {
        out_data[varID].mf->data[mfID].type->data[i2] = '\x00';
      }
      i2 = out_data[varID].mf->data[mfID].params->size[0] *
           out_data[varID].mf->data[mfID].params->size[1];
      out_data[varID].mf->data[mfID].params->size[0] = 1;
      loop_ub = (int)maxMFParamLength;
      out_data[varID].mf->data[mfID].params->size[1] = (int)maxMFParamLength;
      emxEnsureCapacity_real_T(out_data[varID].mf->data[mfID].params, i2);
      for (i2 = 0; i2 < loop_ub; i2++) {
        out_data[varID].mf->data[mfID].params->data[i2] = 0.0;
      }
      out_data[varID].mf->data[mfID].origTypeLength = 0.0;
      out_data[varID].mf->data[mfID].origParamLength = 0.0;
      if ((double)mfID + 1.0 <= out_data[varID].origNumMF) {
        i2 = out_data[varID].mf->data[mfID].type->size[0] *
             out_data[varID].mf->data[mfID].type->size[1];
        out_data[varID].mf->data[mfID].type->size[0] = 1;
        loop_ub = in_data[varID].mf->data[mfID].type->size[1];
        out_data[varID].mf->data[mfID].type->size[1] =
            in_data[varID].mf->data[mfID].type->size[1];
        emxEnsureCapacity_char_T(out_data[varID].mf->data[mfID].type, i2);
        for (i2 = 0; i2 < loop_ub; i2++) {
          out_data[varID].mf->data[mfID].type->data[i2] =
              in_data[varID].mf->data[mfID].type->data[i2];
        }
        out_data[varID].mf->data[mfID].origTypeLength =
            in_data[varID].mf->data[mfID].origTypeLength;
        i2 = out_data[varID].mf->data[mfID].params->size[0] *
             out_data[varID].mf->data[mfID].params->size[1];
        out_data[varID].mf->data[mfID].params->size[0] = 1;
        loop_ub = in_data[varID].mf->data[mfID].params->size[1];
        out_data[varID].mf->data[mfID].params->size[1] =
            in_data[varID].mf->data[mfID].params->size[1];
        emxEnsureCapacity_real_T(out_data[varID].mf->data[mfID].params, i2);
        for (i2 = 0; i2 < loop_ub; i2++) {
          out_data[varID].mf->data[mfID].params->data[i2] =
              in_data[varID].mf->data[mfID].params->data[i2];
        }
        out_data[varID].mf->data[mfID].origParamLength =
            in_data[varID].mf->data[mfID].origParamLength;
      }
    }
  }
  emxFreeStruct_struct_T6(&mfStruct);
}

/*
 * Arguments    : const g_emxArray_struct_T *in
 *                e_emxArray_struct_T *out
 * Return Type  : void
 */
void setMFDataType(const g_emxArray_struct_T *in, e_emxArray_struct_T *out)
{
  d_struct_T mfStruct;
  e_struct_T varStruct;
  e_struct_T *out_data;
  const g_struct_T *in_data;
  int i;
  int i1;
  int loop_ub;
  int mfID;
  int varID;
  in_data = in->data;
  emxInitStruct_struct_T6(&mfStruct);
  i = mfStruct.type->size[0] * mfStruct.type->size[1];
  mfStruct.type->size[0] = 1;
  mfStruct.type->size[1] = in_data[0].mf->data[0].type->size[1];
  emxEnsureCapacity_char_T(mfStruct.type, i);
  loop_ub = in_data[0].mf->data[0].type->size[1];
  for (i = 0; i < loop_ub; i++) {
    mfStruct.type->data[i] = '\x00';
  }
  mfStruct.origTypeLength = 0;
  i = mfStruct.params->size[0] * mfStruct.params->size[1];
  mfStruct.params->size[0] = 1;
  mfStruct.params->size[1] = in_data[0].mf->data[0].params->size[1];
  emxEnsureCapacity_real_T(mfStruct.params, i);
  loop_ub = in_data[0].mf->data[0].params->size[1];
  for (i = 0; i < loop_ub; i++) {
    mfStruct.params->data[i] = 0.0;
  }
  mfStruct.origParamLength = 0;
  emxInitStruct_struct_T7(&varStruct);
  i = varStruct.mf->size[0] * varStruct.mf->size[1];
  varStruct.mf->size[0] = 1;
  varStruct.mf->size[1] = in_data[0].mf->size[1];
  emxEnsureCapacity_struct_T5(varStruct.mf, i);
  loop_ub = in_data[0].mf->size[1];
  for (i = 0; i < loop_ub; i++) {
    emxCopyStruct_struct_T5(&varStruct.mf->data[i], &mfStruct);
  }
  emxFreeStruct_struct_T4(&mfStruct);
  varStruct.origNumMF = 0;
  i = out->size[0] * out->size[1];
  out->size[0] = 1;
  out->size[1] = in->size[1];
  emxEnsureCapacity_struct_T6(out, i);
  out_data = out->data;
  loop_ub = in->size[1];
  for (varID = 0; varID < loop_ub; varID++) {
    double d;
    emxCopyStruct_struct_T6(&out_data[varID], &varStruct);
    d = rt_roundd_snf(in_data[varID].origNumMF);
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        i = (int)d;
      } else {
        i = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      i = MAX_int32_T;
    } else {
      i = 0;
    }
    out_data[varID].origNumMF = i;
    i = in_data[0].mf->size[1];
    for (mfID = 0; mfID < i; mfID++) {
      int b_loop_ub;
      i1 = out_data[varID].mf->data[mfID].type->size[0] *
           out_data[varID].mf->data[mfID].type->size[1];
      out_data[varID].mf->data[mfID].type->size[0] = 1;
      b_loop_ub = in_data[varID].mf->data[mfID].type->size[1];
      out_data[varID].mf->data[mfID].type->size[1] =
          in_data[varID].mf->data[mfID].type->size[1];
      emxEnsureCapacity_char_T(out_data[varID].mf->data[mfID].type, i1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        out_data[varID].mf->data[mfID].type->data[i1] =
            in_data[varID].mf->data[mfID].type->data[i1];
      }
      i1 = out_data[varID].mf->data[mfID].params->size[0] *
           out_data[varID].mf->data[mfID].params->size[1];
      out_data[varID].mf->data[mfID].params->size[0] = 1;
      b_loop_ub = in_data[varID].mf->data[mfID].params->size[1];
      out_data[varID].mf->data[mfID].params->size[1] =
          in_data[varID].mf->data[mfID].params->size[1];
      emxEnsureCapacity_real_T(out_data[varID].mf->data[mfID].params, i1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        out_data[varID].mf->data[mfID].params->data[i1] =
            in_data[varID].mf->data[mfID].params->data[i1];
      }
      d = rt_roundd_snf(in_data[varID].mf->data[mfID].origTypeLength);
      if (d < 2.147483648E+9) {
        if (d >= -2.147483648E+9) {
          i1 = (int)d;
        } else {
          i1 = MIN_int32_T;
        }
      } else if (d >= 2.147483648E+9) {
        i1 = MAX_int32_T;
      } else {
        i1 = 0;
      }
      out_data[varID].mf->data[mfID].origTypeLength = i1;
      d = rt_roundd_snf(in_data[varID].mf->data[mfID].origParamLength);
      if (d < 2.147483648E+9) {
        if (d >= -2.147483648E+9) {
          i1 = (int)d;
        } else {
          i1 = MIN_int32_T;
        }
      } else if (d >= 2.147483648E+9) {
        i1 = MAX_int32_T;
      } else {
        i1 = 0;
      }
      out_data[varID].mf->data[mfID].origParamLength = i1;
    }
  }
  emxFreeStruct_struct_T5(&varStruct);
}

/*
 * File trailer for packageAndSetDataType.c
 *
 * [EOF]
 */
