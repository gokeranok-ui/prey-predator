/*
 * File: opkene_emxutil.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

#ifndef OPKENE_EMXUTIL_H
#define OPKENE_EMXUTIL_H

/* Include Files */
#include "opkene_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxCopyMatrix_real_T(double dst[2], const double src[2]);

extern void emxCopyStruct_struct_T(struct_T *dst, const struct_T *src);

extern void emxCopyStruct_struct_T1(b_struct_T *dst, const b_struct_T *src);

extern void emxCopyStruct_struct_T2(c_struct_T *dst, const c_struct_T *src);

extern void emxCopyStruct_struct_T3(f_struct_T *dst, const f_struct_T *src);

extern void emxCopyStruct_struct_T4(g_struct_T *dst, const g_struct_T *src);

extern void emxCopyStruct_struct_T5(d_struct_T *dst, const d_struct_T *src);

extern void emxCopyStruct_struct_T6(e_struct_T *dst, const e_struct_T *src);

extern void emxCopyStruct_struct_T7(h_struct_T *dst, const h_struct_T *src);

extern void emxCopy_char_T(emxArray_char_T **dst, emxArray_char_T *const *src);

extern void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T *const *src);

extern void emxCopy_struct_T(emxArray_struct_T **dst,
                             emxArray_struct_T *const *src);

extern void emxCopy_struct_T1(f_emxArray_struct_T **dst,
                              f_emxArray_struct_T *const *src);

extern void emxCopy_struct_T2(d_emxArray_struct_T **dst,
                              d_emxArray_struct_T *const *src);

extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_cell_wrap_0(emxArray_cell_wrap_0 *emxArray,
                                          int oldNumel);

extern void emxEnsureCapacity_char_T(emxArray_char_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_struct_T(emxArray_struct_T *emxArray,
                                       int oldNumel);

extern void emxEnsureCapacity_struct_T1(b_emxArray_struct_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_struct_T2(c_emxArray_struct_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_struct_T3(f_emxArray_struct_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_struct_T4(g_emxArray_struct_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_struct_T5(d_emxArray_struct_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_struct_T6(e_emxArray_struct_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_struct_T7(h_emxArray_struct_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray, int oldNumel);

extern void emxExpand_cell_wrap_0(emxArray_cell_wrap_0 *emxArray, int fromIndex,
                                  int toIndex);

extern void emxExpand_struct_T(emxArray_struct_T *emxArray, int fromIndex,
                               int toIndex);

extern void emxExpand_struct_T1(b_emxArray_struct_T *emxArray, int fromIndex,
                                int toIndex);

extern void emxExpand_struct_T2(c_emxArray_struct_T *emxArray, int fromIndex,
                                int toIndex);

extern void emxExpand_struct_T3(f_emxArray_struct_T *emxArray, int fromIndex,
                                int toIndex);

extern void emxExpand_struct_T4(g_emxArray_struct_T *emxArray, int fromIndex,
                                int toIndex);

extern void emxExpand_struct_T5(d_emxArray_struct_T *emxArray, int fromIndex,
                                int toIndex);

extern void emxExpand_struct_T6(e_emxArray_struct_T *emxArray, int fromIndex,
                                int toIndex);

extern void emxExpand_struct_T7(h_emxArray_struct_T *emxArray, int fromIndex,
                                int toIndex);

extern void emxFreeStruct_cell_wrap_0(cell_wrap_0 *pStruct);

extern void emxFreeStruct_struct_T(b_struct_T *pStruct);

extern void emxFreeStruct_struct_T1(struct_T *pStruct);

extern void emxFreeStruct_struct_T2(c_struct_T *pStruct);

extern void emxFreeStruct_struct_T3(i_struct_T *pStruct);

extern void emxFreeStruct_struct_T4(d_struct_T *pStruct);

extern void emxFreeStruct_struct_T5(e_struct_T *pStruct);

extern void emxFreeStruct_struct_T6(f_struct_T *pStruct);

extern void emxFreeStruct_struct_T7(g_struct_T *pStruct);

extern void emxFreeStruct_struct_T8(h_struct_T *pStruct);

extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);

extern void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray);

extern void emxFree_char_T(emxArray_char_T **pEmxArray);

extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxFree_struct_T(b_emxArray_struct_T **pEmxArray);

extern void emxFree_struct_T1(emxArray_struct_T **pEmxArray);

extern void emxFree_struct_T2(c_emxArray_struct_T **pEmxArray);

extern void emxFree_struct_T3(e_emxArray_struct_T **pEmxArray);

extern void emxFree_struct_T4(d_emxArray_struct_T **pEmxArray);

extern void emxFree_struct_T5(g_emxArray_struct_T **pEmxArray);

extern void emxFree_struct_T6(f_emxArray_struct_T **pEmxArray);

extern void emxFree_struct_T7(h_emxArray_struct_T **pEmxArray);

extern void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);

extern void emxInitStruct_cell_wrap_0(cell_wrap_0 *pStruct);

extern void emxInitStruct_struct_T(i_struct_T *pStruct);

extern void emxInitStruct_struct_T1(struct_T *pStruct);

extern void emxInitStruct_struct_T2(b_struct_T *pStruct);

extern void emxInitStruct_struct_T3(c_struct_T *pStruct);

extern void emxInitStruct_struct_T4(f_struct_T *pStruct);

extern void emxInitStruct_struct_T5(g_struct_T *pStruct);

extern void emxInitStruct_struct_T6(d_struct_T *pStruct);

extern void emxInitStruct_struct_T7(e_struct_T *pStruct);

extern void emxInitStruct_struct_T8(h_struct_T *pStruct);

extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray);

extern void emxInit_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray);

extern void emxInit_char_T(emxArray_char_T **pEmxArray, int numDimensions);

extern void emxInit_int32_T(emxArray_int32_T **pEmxArray);

extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

extern void emxInit_struct_T(b_emxArray_struct_T **pEmxArray);

extern void emxInit_struct_T1(c_emxArray_struct_T **pEmxArray);

extern void emxInit_struct_T2(e_emxArray_struct_T **pEmxArray);

extern void emxInit_struct_T3(g_emxArray_struct_T **pEmxArray);

extern void emxInit_struct_T4(emxArray_struct_T **pEmxArray);

extern void emxInit_struct_T5(f_emxArray_struct_T **pEmxArray);

extern void emxInit_struct_T6(d_emxArray_struct_T **pEmxArray);

extern void emxInit_struct_T7(h_emxArray_struct_T **pEmxArray);

extern void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int numDimensions);

extern void emxTrim_cell_wrap_0(emxArray_cell_wrap_0 *emxArray, int fromIndex,
                                int toIndex);

extern void emxTrim_struct_T(emxArray_struct_T *emxArray, int fromIndex,
                             int toIndex);

extern void emxTrim_struct_T1(b_emxArray_struct_T *emxArray, int fromIndex,
                              int toIndex);

extern void emxTrim_struct_T2(c_emxArray_struct_T *emxArray, int fromIndex,
                              int toIndex);

extern void emxTrim_struct_T3(f_emxArray_struct_T *emxArray, int fromIndex,
                              int toIndex);

extern void emxTrim_struct_T4(g_emxArray_struct_T *emxArray, int fromIndex,
                              int toIndex);

extern void emxTrim_struct_T5(d_emxArray_struct_T *emxArray, int fromIndex,
                              int toIndex);

extern void emxTrim_struct_T6(e_emxArray_struct_T *emxArray, int fromIndex,
                              int toIndex);

extern void emxTrim_struct_T7(h_emxArray_struct_T *emxArray, int fromIndex,
                              int toIndex);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for opkene_emxutil.h
 *
 * [EOF]
 */
