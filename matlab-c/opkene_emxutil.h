/*
 * File: opkene_emxutil.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

#ifndef OPKENE_EMXUTIL_H
#define OPKENE_EMXUTIL_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "opkene_types.h"

/* Function Declarations */
extern void emxCopyStruct_struct_T(f_struct_T *dst, const f_struct_T *src);
extern void emxCopyStruct_struct_T1(e_struct_T *dst, const e_struct_T *src);
extern void emxCopyStruct_struct_T2(d_struct_T *dst, const d_struct_T *src);
extern void emxCopyStruct_struct_T3(c_struct_T *dst, const c_struct_T *src);
extern void emxCopyStruct_struct_T4(struct_T *dst, const struct_T *src);
extern void emxCopyStruct_struct_T5(h_struct_T *dst, const h_struct_T *src);
extern void emxCopyStruct_struct_T6(b_struct_T *dst, const b_struct_T *src);
extern void emxCopyStruct_struct_T7(g_struct_T *dst, const g_struct_T *src);
extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_cell_wrap_0(emxArray_cell_wrap_0 *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_char_T(emxArray_char_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_struct_T(f_emxArray_struct_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_struct_T1(e_emxArray_struct_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_struct_T2(d_emxArray_struct_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_struct_T3(c_emxArray_struct_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_struct_T4(emxArray_struct_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_struct_T5(h_emxArray_struct_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_struct_T6(b_emxArray_struct_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_struct_T7(g_emxArray_struct_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_uint32_T(emxArray_uint32_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray, int oldNumel);
extern void emxFreeStruct_struct_T(e_struct_T *pStruct);
extern void emxFreeStruct_struct_T1(f_struct_T *pStruct);
extern void emxFreeStruct_struct_T2(c_struct_T *pStruct);
extern void emxFreeStruct_struct_T3(d_struct_T *pStruct);
extern void emxFreeStruct_struct_T4(h_struct_T *pStruct);
extern void emxFreeStruct_struct_T5(struct_T *pStruct);
extern void emxFreeStruct_struct_T6(b_struct_T *pStruct);
extern void emxFreeStruct_struct_T7(i_struct_T *pStruct);
extern void emxFreeStruct_struct_T8(j_struct_T *pStruct);
extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
extern void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray);
extern void emxFree_char_T(emxArray_char_T **pEmxArray);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_int8_T(emxArray_int8_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxFree_struct_T2(h_emxArray_struct_T **pEmxArray);
extern void emxFree_struct_T3(emxArray_struct_T **pEmxArray);
extern void emxFree_struct_T4(b_emxArray_struct_T **pEmxArray);
extern void emxFree_struct_T5(d_emxArray_struct_T **pEmxArray);
extern void emxFree_struct_T6(f_emxArray_struct_T **pEmxArray);
extern void emxFree_struct_T7(g_emxArray_struct_T **pEmxArray);
extern void emxFree_uint32_T(emxArray_uint32_T **pEmxArray);
extern void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);
extern void emxInitStruct_struct_T(f_struct_T *pStruct);
extern void emxInitStruct_struct_T1(e_struct_T *pStruct);
extern void emxInitStruct_struct_T2(d_struct_T *pStruct);
extern void emxInitStruct_struct_T3(c_struct_T *pStruct);
extern void emxInitStruct_struct_T4(i_struct_T *pStruct);
extern void emxInitStruct_struct_T5(j_struct_T *pStruct);
extern void emxInitStruct_struct_T6(struct_T *pStruct);
extern void emxInitStruct_struct_T7(h_struct_T *pStruct);
extern void emxInitStruct_struct_T8(b_struct_T *pStruct);
extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int numDimensions);
extern void emxInit_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray, int
  numDimensions);
extern void emxInit_char_T(emxArray_char_T **pEmxArray, int numDimensions);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_int8_T(emxArray_int8_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_struct_T2(h_emxArray_struct_T **pEmxArray, int numDimensions);
extern void emxInit_struct_T3(b_emxArray_struct_T **pEmxArray, int numDimensions);
extern void emxInit_struct_T4(d_emxArray_struct_T **pEmxArray, int numDimensions);
extern void emxInit_struct_T5(f_emxArray_struct_T **pEmxArray, int numDimensions);
extern void emxInit_struct_T6(emxArray_struct_T **pEmxArray, int numDimensions);
extern void emxInit_struct_T7(g_emxArray_struct_T **pEmxArray, int numDimensions);
extern void emxInit_uint32_T(emxArray_uint32_T **pEmxArray, int numDimensions);
extern void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int numDimensions);

#endif

/*
 * File trailer for opkene_emxutil.h
 *
 * [EOF]
 */
