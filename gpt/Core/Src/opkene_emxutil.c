/*
 * File: opkene_emxutil.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "opkene.h"
#include "opkene_emxutil.h"

/* Function Declarations */
static void emxCopyMatrix_real_T(double dst[2], const double src[2]);
static void emxCopy_char_T(emxArray_char_T **dst, emxArray_char_T * const *src);
static void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T * const *src);
static void emxCopy_struct_T(e_emxArray_struct_T **dst, e_emxArray_struct_T *
  const *src);
static void emxCopy_struct_T1(c_emxArray_struct_T **dst, c_emxArray_struct_T *
  const *src);
static void emxCopy_struct_T2(emxArray_struct_T **dst, emxArray_struct_T * const
  *src);
static void emxExpand_cell_wrap_0(emxArray_cell_wrap_0 *emxArray, int fromIndex,
  int toIndex);
static void emxExpand_struct_T(f_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex);
static void emxExpand_struct_T1(e_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex);
static void emxExpand_struct_T2(d_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex);
static void emxExpand_struct_T3(c_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex);
static void emxExpand_struct_T4(emxArray_struct_T *emxArray, int fromIndex, int
  toIndex);
static void emxExpand_struct_T5(h_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex);
static void emxExpand_struct_T6(b_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex);
static void emxExpand_struct_T7(g_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex);
static void emxFreeStruct_cell_wrap_0(cell_wrap_0 *pStruct);
static void emxFreeStruct_struct_T9(g_struct_T *pStruct);
static void emxFree_struct_T(e_emxArray_struct_T **pEmxArray);
static void emxFree_struct_T1(c_emxArray_struct_T **pEmxArray);
static void emxInitStruct_cell_wrap_0(cell_wrap_0 *pStruct);
static void emxInitStruct_struct_T9(g_struct_T *pStruct);
static void emxInit_struct_T(e_emxArray_struct_T **pEmxArray, int numDimensions);
static void emxInit_struct_T1(c_emxArray_struct_T **pEmxArray, int numDimensions);
static void emxTrim_cell_wrap_0(emxArray_cell_wrap_0 *emxArray, int fromIndex,
  int toIndex);
static void emxTrim_struct_T(f_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex);
static void emxTrim_struct_T1(e_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex);
static void emxTrim_struct_T2(d_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex);
static void emxTrim_struct_T3(c_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex);
static void emxTrim_struct_T4(emxArray_struct_T *emxArray, int fromIndex, int
  toIndex);
static void emxTrim_struct_T5(h_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex);
static void emxTrim_struct_T6(b_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex);
static void emxTrim_struct_T7(g_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex);

/* Function Definitions */

/*
 * Arguments    : double dst[2]
 *                const double src[2]
 * Return Type  : void
 */
static void emxCopyMatrix_real_T(double dst[2], const double src[2])
{
  dst[0] = src[0];
  dst[1] = src[1];
}

/*
 * Arguments    : emxArray_char_T **dst
 *                emxArray_char_T * const *src
 * Return Type  : void
 */
static void emxCopy_char_T(emxArray_char_T **dst, emxArray_char_T * const *src)
{
  int numElDst;
  int numElSrc;
  int i;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }

  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }

  emxEnsureCapacity_char_T(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

/*
 * Arguments    : emxArray_real_T **dst
 *                emxArray_real_T * const *src
 * Return Type  : void
 */
static void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T * const *src)
{
  int numElDst;
  int numElSrc;
  int i;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }

  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }

  emxEnsureCapacity_real_T(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

/*
 * Arguments    : e_emxArray_struct_T **dst
 *                e_emxArray_struct_T * const *src
 * Return Type  : void
 */
static void emxCopy_struct_T(e_emxArray_struct_T **dst, e_emxArray_struct_T *
  const *src)
{
  int numElDst;
  int numElSrc;
  int i;
  
  /* Debug: check inputs */
  if (*dst == NULL) {
    printf("emxCopy_struct_T: ERROR - destination is NULL!\r\n");
    return;
  }
  if (*src == NULL) {
    printf("emxCopy_struct_T: ERROR - source is NULL!\r\n");
    return;
  }
  
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }
  
  printf("emxCopy_struct_T: before copy - dst size=%d, src size=%d\r\n", numElDst, numElSrc);

  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }

  printf("emxCopy_struct_T: calling emxEnsureCapacity_struct_T1 with numElDst=%d\r\n", numElDst);
  emxEnsureCapacity_struct_T1(*dst, numElDst);
  printf("emxCopy_struct_T: after emxEnsureCapacity - dst->data=%p\r\n", (void*)(*dst)->data);
  
  /* If source has valid data pointer but destination doesn't (size=0 case), allocate minimal array */
  if ((*src)->data != NULL && (*dst)->data == NULL && numElSrc == 0) {
    printf("emxCopy_struct_T: WARNING - source has valid pointer but size=0, allocating minimal array\r\n");
    printf("emxCopy_struct_T: source allocatedSize=%d, size=%d\r\n", (int)(*src)->allocatedSize, numElSrc);
    /* When size=0, the array has 0 elements, so source[0] is out of bounds */
    /* We should NOT copy from source[0] when size=0, even if allocatedSize > 0 */
    /* Instead, we should just initialize the destination with empty structures */
    /* The real issue is why the source has size=0 - it should have been populated */
    /* Allocate at least 1 element to have a valid pointer */
    (*dst)->allocatedSize = 1;
    (*dst)->data = (e_struct_T *)calloc(1, sizeof(e_struct_T));
    (*dst)->canFreeData = true;
    /* Initialize the nested structures in the allocated element */
    emxInitStruct_struct_T1(&(*dst)->data[0]);
    printf("emxCopy_struct_T: allocated minimal array (size=0, not copying from source), dst->data=%p\r\n", (void*)(*dst)->data);
  }
  
  for (i = 0; i < numElSrc; i++) {
    emxCopyStruct_struct_T1(&(*dst)->data[i], &(*src)->data[i]);
  }
  printf("emxCopy_struct_T: copy completed\r\n");
}

/*
 * Arguments    : c_emxArray_struct_T **dst
 *                c_emxArray_struct_T * const *src
 * Return Type  : void
 */
static void emxCopy_struct_T1(c_emxArray_struct_T **dst, c_emxArray_struct_T *
  const *src)
{
  int numElDst;
  int numElSrc;
  int i;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }

  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }

  emxEnsureCapacity_struct_T3(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    emxCopyStruct_struct_T3(&(*dst)->data[i], &(*src)->data[i]);
  }
}

/*
 * Arguments    : emxArray_struct_T **dst
 *                emxArray_struct_T * const *src
 * Return Type  : void
 */
static void emxCopy_struct_T2(emxArray_struct_T **dst, emxArray_struct_T * const
  *src)
{
  int numElDst;
  int numElSrc;
  int i;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }

  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }

  emxEnsureCapacity_struct_T4(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    emxCopyStruct_struct_T4(&(*dst)->data[i], &(*src)->data[i]);
  }
}

/*
 * Arguments    : emxArray_cell_wrap_0 *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxExpand_cell_wrap_0(emxArray_cell_wrap_0 *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_0(&emxArray->data[i]);
  }
}

/*
 * Arguments    : f_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxExpand_struct_T(f_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T(&emxArray->data[i]);
  }
}

/*
 * Arguments    : e_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxExpand_struct_T1(e_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T1(&emxArray->data[i]);
  }
}

/*
 * Arguments    : d_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxExpand_struct_T2(d_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T2(&emxArray->data[i]);
  }
}

/*
 * Arguments    : c_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxExpand_struct_T3(c_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T3(&emxArray->data[i]);
  }
}

/*
 * Arguments    : emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxExpand_struct_T4(emxArray_struct_T *emxArray, int fromIndex, int
  toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T6(&emxArray->data[i]);
  }
}

/*
 * Arguments    : h_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxExpand_struct_T5(h_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T7(&emxArray->data[i]);
  }
}

/*
 * Arguments    : b_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxExpand_struct_T6(b_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T8(&emxArray->data[i]);
  }
}

/*
 * Arguments    : g_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxExpand_struct_T7(g_emxArray_struct_T *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T9(&emxArray->data[i]);
  }
}

/*
 * Arguments    : cell_wrap_0 *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_cell_wrap_0(cell_wrap_0 *pStruct)
{
  emxFree_struct_T7(&pStruct->f1);
}

/*
 * Arguments    : g_struct_T *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_struct_T9(g_struct_T *pStruct)
{
  emxFree_char_T(&pStruct->type);
  emxFree_real_T(&pStruct->params);
}

/*
 * Arguments    : e_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_struct_T(e_emxArray_struct_T **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (e_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (e_struct_T *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct_T(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (e_emxArray_struct_T *)NULL;
  }
}

/*
 * Arguments    : c_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_struct_T1(c_emxArray_struct_T **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (c_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (c_struct_T *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct_T2(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (c_emxArray_struct_T *)NULL;
  }
}

/*
 * Arguments    : cell_wrap_0 *pStruct
 * Return Type  : void
 */
static void emxInitStruct_cell_wrap_0(cell_wrap_0 *pStruct)
{
  emxInit_struct_T7(&pStruct->f1, 2);
}

/*
 * Arguments    : g_struct_T *pStruct
 * Return Type  : void
 */
static void emxInitStruct_struct_T9(g_struct_T *pStruct)
{
  emxInit_char_T(&pStruct->type, 2);
  emxInit_real_T(&pStruct->params, 2);
}

/*
 * Arguments    : e_emxArray_struct_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
static void emxInit_struct_T(e_emxArray_struct_T **pEmxArray, int numDimensions)
{
  e_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (e_emxArray_struct_T *)malloc(sizeof(e_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (e_struct_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : c_emxArray_struct_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
static void emxInit_struct_T1(c_emxArray_struct_T **pEmxArray, int numDimensions)
{
  c_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (c_emxArray_struct_T *)malloc(sizeof(c_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (c_struct_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_0 *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxTrim_cell_wrap_0(emxArray_cell_wrap_0 *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_0(&emxArray->data[i]);
  }
}

/*
 * Arguments    : f_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxTrim_struct_T(f_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T1(&emxArray->data[i]);
  }
}

/*
 * Arguments    : e_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxTrim_struct_T1(e_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T(&emxArray->data[i]);
  }
}

/*
 * Arguments    : d_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxTrim_struct_T2(d_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T3(&emxArray->data[i]);
  }
}

/*
 * Arguments    : c_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxTrim_struct_T3(c_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T2(&emxArray->data[i]);
  }
}

/*
 * Arguments    : emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxTrim_struct_T4(emxArray_struct_T *emxArray, int fromIndex, int
  toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T5(&emxArray->data[i]);
  }
}

/*
 * Arguments    : h_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxTrim_struct_T5(h_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T4(&emxArray->data[i]);
  }
}

/*
 * Arguments    : b_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxTrim_struct_T6(b_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T6(&emxArray->data[i]);
  }
}

/*
 * Arguments    : g_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxTrim_struct_T7(g_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T9(&emxArray->data[i]);
  }
}

/*
 * Arguments    : f_struct_T *dst
 *                const f_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T(f_struct_T *dst, const f_struct_T *src)
{
  /* Initialize destination mf field if it's NULL */
  if (dst->mf == NULL) {
    emxInit_struct_T(&dst->mf, 2);
  }
  /* Debug: check source mf before copying */
  if (src->mf == NULL) {
    printf("emxCopyStruct_struct_T: WARNING - source mf is NULL!\r\n");
  } else if (src->mf->data == NULL) {
    printf("emxCopyStruct_struct_T: WARNING - source mf->data is NULL (size=%d)\r\n", 
           (int)(src->mf->size[0] * src->mf->size[1]));
  } else {
    printf("emxCopyStruct_struct_T: source mf->data is valid (size=%d)\r\n", 
           (int)(src->mf->size[0] * src->mf->size[1]));
  }
  emxCopy_struct_T(&dst->mf, &src->mf);
  /* Debug: check destination mf after copying */
  if (dst->mf == NULL) {
    printf("emxCopyStruct_struct_T: ERROR - destination mf is NULL after copy!\r\n");
  } else if (dst->mf->data == NULL) {
    printf("emxCopyStruct_struct_T: ERROR - destination mf->data is NULL after copy (size=%d)\r\n", 
           (int)(dst->mf->size[0] * dst->mf->size[1]));
  } else {
    printf("emxCopyStruct_struct_T: destination mf->data is valid after copy (size=%d)\r\n", 
           (int)(dst->mf->size[0] * dst->mf->size[1]));
  }
  dst->origNumMF = src->origNumMF;
}

/*
 * Arguments    : e_struct_T *dst
 *                const e_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T1(e_struct_T *dst, const e_struct_T *src)
{
  emxCopy_char_T(&dst->type, &src->type);
  dst->origTypeLength = src->origTypeLength;
  emxCopy_real_T(&dst->params, &src->params);
  dst->origParamLength = src->origParamLength;
}

/*
 * Arguments    : d_struct_T *dst
 *                const d_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T2(d_struct_T *dst, const d_struct_T *src)
{
  emxCopy_struct_T1(&dst->mf, &src->mf);
  dst->origNumMF = src->origNumMF;
}

/*
 * Arguments    : c_struct_T *dst
 *                const c_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T3(c_struct_T *dst, const c_struct_T *src)
{
  emxCopy_char_T(&dst->type, &src->type);
  dst->origTypeLength = src->origTypeLength;
  emxCopy_real_T(&dst->params, &src->params);
  dst->origParamLength = src->origParamLength;
}

/*
 * Arguments    : struct_T *dst
 *                const struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T4(struct_T *dst, const struct_T *src)
{
  emxCopy_char_T(&dst->name, &src->name);
  dst->origNameLength = src->origNameLength;
  emxCopy_char_T(&dst->type, &src->type);
  dst->origTypeLength = src->origTypeLength;
  emxCopy_real_T(&dst->params, &src->params);
  dst->origParamLength = src->origParamLength;
}

/*
 * Arguments    : h_struct_T *dst
 *                const h_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T5(h_struct_T *dst, const h_struct_T *src)
{
  emxCopy_char_T(&dst->name, &src->name);
  dst->origNameLength = src->origNameLength;
  emxCopyMatrix_real_T(dst->range, src->range);
  emxCopy_struct_T2(&dst->mf, &src->mf);
  dst->origNumMF = src->origNumMF;
}

/*
 * Arguments    : b_struct_T *dst
 *                const b_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T6(b_struct_T *dst, const b_struct_T *src)
{
  emxCopy_real_T(&dst->antecedent, &src->antecedent);
  emxCopy_real_T(&dst->consequent, &src->consequent);
  dst->weight = src->weight;
  dst->connection = src->connection;
}

/*
 * Arguments    : g_struct_T *dst
 *                const g_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T7(g_struct_T *dst, const g_struct_T *src)
{
  emxCopy_char_T(&dst->type, &src->type);
  emxCopy_real_T(&dst->params, &src->params);
}

/*
 * Arguments    : emxArray_boolean_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(boolean_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_0 *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_cell_wrap_0(emxArray_cell_wrap_0 *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(cell_wrap_0));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_0) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (cell_wrap_0 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_0(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_cell_wrap_0(emxArray, oldNumel, newNumel);
    }
  }
}

/*
 * Arguments    : emxArray_char_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_char_T(emxArray_char_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(char));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(char) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (char *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_int32_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(int));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (int *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_int8_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(signed char));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(signed char) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (signed char *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(double));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(double) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (double *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : f_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T(f_emxArray_struct_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(f_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(f_struct_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (f_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_struct_T(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_struct_T(emxArray, oldNumel, newNumel);
    }
  }
}

/*
 * Arguments    : e_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T1(e_emxArray_struct_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(e_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(e_struct_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (e_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_struct_T1(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_struct_T1(emxArray, oldNumel, newNumel);
    }
  }
}

/*
 * Arguments    : d_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T2(d_emxArray_struct_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(d_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(d_struct_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (d_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_struct_T2(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_struct_T2(emxArray, oldNumel, newNumel);
    }
  }
}

/*
 * Arguments    : c_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T3(c_emxArray_struct_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(c_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(c_struct_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (c_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_struct_T3(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_struct_T3(emxArray, oldNumel, newNumel);
    }
  }
}

/*
 * Arguments    : emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T4(emxArray_struct_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(struct_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_struct_T4(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_struct_T4(emxArray, oldNumel, newNumel);
    }
  }
}

/*
 * Arguments    : h_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T5(h_emxArray_struct_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(h_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(h_struct_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (h_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_struct_T5(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_struct_T5(emxArray, oldNumel, newNumel);
    }
  }
}

/*
 * Arguments    : b_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T6(b_emxArray_struct_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(b_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(b_struct_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (b_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_struct_T6(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_struct_T6(emxArray, oldNumel, newNumel);
    }
  }
}

/*
 * Arguments    : g_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T7(g_emxArray_struct_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(g_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(g_struct_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (g_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_struct_T7(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_struct_T7(emxArray, oldNumel, newNumel);
    }
  }
}

/*
 * Arguments    : emxArray_uint32_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_uint32_T(emxArray_uint32_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(unsigned int));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(unsigned int) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (unsigned int *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_uint8_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(unsigned char));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(unsigned char) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (unsigned char *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : e_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T(e_struct_T *pStruct)
{
  emxFree_char_T(&pStruct->type);
  emxFree_real_T(&pStruct->params);
}

/*
 * Arguments    : f_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T1(f_struct_T *pStruct)
{
  emxFree_struct_T(&pStruct->mf);
}

/*
 * Arguments    : c_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T2(c_struct_T *pStruct)
{
  emxFree_char_T(&pStruct->type);
  emxFree_real_T(&pStruct->params);
}

/*
 * Arguments    : d_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T3(d_struct_T *pStruct)
{
  emxFree_struct_T1(&pStruct->mf);
}

/*
 * Arguments    : h_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T4(h_struct_T *pStruct)
{
  emxFree_char_T(&pStruct->name);
  emxFree_struct_T3(&pStruct->mf);
}

/*
 * Arguments    : struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T5(struct_T *pStruct)
{
  emxFree_char_T(&pStruct->name);
  emxFree_char_T(&pStruct->type);
  emxFree_real_T(&pStruct->params);
}

/*
 * Arguments    : b_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T6(b_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->antecedent);
  emxFree_real_T(&pStruct->consequent);
}

/*
 * Arguments    : i_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T7(i_struct_T *pStruct)
{
  emxFree_uint8_T(&pStruct->type);
  emxFree_uint8_T(&pStruct->andMethod);
  emxFree_uint8_T(&pStruct->orMethod);
  emxFree_uint8_T(&pStruct->defuzzMethod);
  emxFree_uint8_T(&pStruct->impMethod);
  emxFree_uint8_T(&pStruct->aggMethod);
  emxFree_real_T(&pStruct->inputRange);
  emxFree_real_T(&pStruct->outputRange);
  emxFree_struct_T5(&pStruct->inputMF);
  emxFree_struct_T5(&pStruct->outputMF);
  emxFree_real_T(&pStruct->antecedent);
  emxFree_real_T(&pStruct->consequent);
  emxFree_real_T(&pStruct->connection);
  emxFree_real_T(&pStruct->weight);
  emxFree_int32_T(&pStruct->numInputMFs);
  emxFree_int32_T(&pStruct->numCumInputMFs);
  emxFree_int32_T(&pStruct->numOutputMFs);
  emxFree_int32_T(&pStruct->numCumOutputMFs);
  emxFree_real_T(&pStruct->outputSamplePoints);
}

/*
 * Arguments    : j_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T8(j_struct_T *pStruct)
{
  emxFree_char_T(&pStruct->type);
  emxFree_char_T(&pStruct->andMethod);
  emxFree_char_T(&pStruct->orMethod);
  emxFree_char_T(&pStruct->defuzzMethod);
  emxFree_char_T(&pStruct->impMethod);
  emxFree_char_T(&pStruct->aggMethod);
  emxFree_struct_T6(&pStruct->inputMF);
  emxFree_struct_T6(&pStruct->outputMF);
  emxFree_real_T(&pStruct->inputRange);
  emxFree_real_T(&pStruct->outputRange);
  emxFree_real_T(&pStruct->antecedent);
  emxFree_real_T(&pStruct->consequent);
  emxFree_real_T(&pStruct->connection);
  emxFree_real_T(&pStruct->weight);
  emxFree_real_T(&pStruct->numInputMFs);
  emxFree_real_T(&pStruct->numCumInputMFs);
  emxFree_real_T(&pStruct->numOutputMFs);
  emxFree_real_T(&pStruct->numCumOutputMFs);
  emxFree_real_T(&pStruct->outputSamplePoints);
}

/*
 * Arguments    : emxArray_boolean_T **pEmxArray
 * Return Type  : void
 */
void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) && (*pEmxArray)->canFreeData)
    {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_0 **pEmxArray
 * Return Type  : void
 */
void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (emxArray_cell_wrap_0 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_0 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_0(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_0 *)NULL;
  }
}

/*
 * Arguments    : emxArray_char_T **pEmxArray
 * Return Type  : void
 */
void emxFree_char_T(emxArray_char_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T *)NULL) {
    if (((*pEmxArray)->data != (char *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 * Return Type  : void
 */
void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_int8_T **pEmxArray
 * Return Type  : void
 */
void emxFree_int8_T(emxArray_int8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int8_T *)NULL) {
    if (((*pEmxArray)->data != (signed char *)NULL) && (*pEmxArray)->canFreeData)
    {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int8_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (double *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : h_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T2(h_emxArray_struct_T **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (h_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (h_struct_T *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct_T4(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (h_emxArray_struct_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T3(emxArray_struct_T **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (struct_T *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct_T5(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_struct_T *)NULL;
  }
}

/*
 * Arguments    : b_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T4(b_emxArray_struct_T **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (b_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (b_struct_T *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct_T6(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (b_emxArray_struct_T *)NULL;
  }
}

/*
 * Arguments    : d_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T5(d_emxArray_struct_T **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (d_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (d_struct_T *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct_T3(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (d_emxArray_struct_T *)NULL;
  }
}

/*
 * Arguments    : f_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T6(f_emxArray_struct_T **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (f_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (f_struct_T *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct_T1(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (f_emxArray_struct_T *)NULL;
  }
}

/*
 * Arguments    : g_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T7(g_emxArray_struct_T **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (g_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (g_struct_T *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct_T9(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (g_emxArray_struct_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_uint32_T **pEmxArray
 * Return Type  : void
 */
void emxFree_uint32_T(emxArray_uint32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint32_T *)NULL) {
    if (((*pEmxArray)->data != (unsigned int *)NULL) && (*pEmxArray)
        ->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_uint32_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_uint8_T **pEmxArray
 * Return Type  : void
 */
void emxFree_uint8_T(emxArray_uint8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint8_T *)NULL) {
    if (((*pEmxArray)->data != (unsigned char *)NULL) && (*pEmxArray)
        ->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_uint8_T *)NULL;
  }
}

/*
 * Arguments    : f_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T(f_struct_T *pStruct)
{
  emxInit_struct_T(&pStruct->mf, 2);
}

/*
 * Arguments    : e_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T1(e_struct_T *pStruct)
{
  emxInit_char_T(&pStruct->type, 2);
  emxInit_real_T(&pStruct->params, 2);
}

/*
 * Arguments    : d_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T2(d_struct_T *pStruct)
{
  emxInit_struct_T1(&pStruct->mf, 2);
}

/*
 * Arguments    : c_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T3(c_struct_T *pStruct)
{
  emxInit_char_T(&pStruct->type, 2);
  emxInit_real_T(&pStruct->params, 2);
}

/*
 * Arguments    : i_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T4(i_struct_T *pStruct)
{
  emxInit_uint8_T(&pStruct->type, 2);
  emxInit_uint8_T(&pStruct->andMethod, 2);
  emxInit_uint8_T(&pStruct->orMethod, 2);
  emxInit_uint8_T(&pStruct->defuzzMethod, 2);
  emxInit_uint8_T(&pStruct->impMethod, 2);
  emxInit_uint8_T(&pStruct->aggMethod, 2);
  emxInit_real_T(&pStruct->inputRange, 2);
  emxInit_real_T(&pStruct->outputRange, 2);
  emxInit_struct_T4(&pStruct->inputMF, 2);
  emxInit_struct_T4(&pStruct->outputMF, 2);
  emxInit_real_T(&pStruct->antecedent, 2);
  emxInit_real_T(&pStruct->consequent, 2);
  emxInit_real_T(&pStruct->connection, 2);
  emxInit_real_T(&pStruct->weight, 2);
  emxInit_int32_T(&pStruct->numInputMFs, 2);
  emxInit_int32_T(&pStruct->numCumInputMFs, 2);
  emxInit_int32_T(&pStruct->numOutputMFs, 2);
  emxInit_int32_T(&pStruct->numCumOutputMFs, 2);
  emxInit_real_T(&pStruct->outputSamplePoints, 2);
}

/*
 * Arguments    : j_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T5(j_struct_T *pStruct)
{
  emxInit_char_T(&pStruct->type, 2);
  emxInit_char_T(&pStruct->andMethod, 2);
  emxInit_char_T(&pStruct->orMethod, 2);
  emxInit_char_T(&pStruct->defuzzMethod, 2);
  emxInit_char_T(&pStruct->impMethod, 2);
  emxInit_char_T(&pStruct->aggMethod, 2);
  emxInit_struct_T5(&pStruct->inputMF, 2);
  emxInit_struct_T5(&pStruct->outputMF, 2);
  emxInit_real_T(&pStruct->inputRange, 2);
  emxInit_real_T(&pStruct->outputRange, 2);
  emxInit_real_T(&pStruct->antecedent, 2);
  emxInit_real_T(&pStruct->consequent, 2);
  emxInit_real_T(&pStruct->connection, 2);
  emxInit_real_T(&pStruct->weight, 2);
  emxInit_real_T(&pStruct->numInputMFs, 2);
  emxInit_real_T(&pStruct->numCumInputMFs, 2);
  emxInit_real_T(&pStruct->numOutputMFs, 2);
  emxInit_real_T(&pStruct->numCumOutputMFs, 2);
  emxInit_real_T(&pStruct->outputSamplePoints, 2);
}

/*
 * Arguments    : struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T6(struct_T *pStruct)
{
  emxInit_char_T(&pStruct->name, 2);
  emxInit_char_T(&pStruct->type, 2);
  emxInit_real_T(&pStruct->params, 2);
}

/*
 * Arguments    : h_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T7(h_struct_T *pStruct)
{
  emxInit_char_T(&pStruct->name, 2);
  emxInit_struct_T6(&pStruct->mf, 2);
  /* Initialize origNumMF to 0.0 to prevent NaN on embedded systems */
  pStruct->origNumMF = 0.0;
  pStruct->origNameLength = 0.0;
  pStruct->range[0] = 0.0;
  pStruct->range[1] = 0.0;
}

/*
 * Arguments    : b_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T8(b_struct_T *pStruct)
{
  emxInit_real_T(&pStruct->antecedent, 2);
  emxInit_real_T(&pStruct->consequent, 2);
}

/*
 * Arguments    : emxArray_boolean_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int numDimensions)
{
  emxArray_boolean_T *emxArray;
  int i;
  *pEmxArray = (emxArray_boolean_T *)malloc(sizeof(emxArray_boolean_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_0 **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray, int numDimensions)
{
  emxArray_cell_wrap_0 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_0 *)malloc(sizeof(emxArray_cell_wrap_0));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_0 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_char_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxArray_char_T *emxArray;
  int i;
  *pEmxArray = (emxArray_char_T *)malloc(sizeof(emxArray_char_T));
  emxArray = *pEmxArray;
  emxArray->data = (char *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxArray_int32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_int8_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_int8_T(emxArray_int8_T **pEmxArray, int numDimensions)
{
  emxArray_int8_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int8_T *)malloc(sizeof(emxArray_int8_T));
  emxArray = *pEmxArray;
  emxArray->data = (signed char *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxArray_real_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (double *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : h_emxArray_struct_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_struct_T2(h_emxArray_struct_T **pEmxArray, int numDimensions)
{
  h_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (h_emxArray_struct_T *)malloc(sizeof(h_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (h_struct_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : b_emxArray_struct_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_struct_T3(b_emxArray_struct_T **pEmxArray, int numDimensions)
{
  b_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (b_emxArray_struct_T *)malloc(sizeof(b_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (b_struct_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : d_emxArray_struct_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_struct_T4(d_emxArray_struct_T **pEmxArray, int numDimensions)
{
  d_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (d_emxArray_struct_T *)malloc(sizeof(d_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (d_struct_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : f_emxArray_struct_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_struct_T5(f_emxArray_struct_T **pEmxArray, int numDimensions)
{
  f_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (f_emxArray_struct_T *)malloc(sizeof(f_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (f_struct_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_struct_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_struct_T6(emxArray_struct_T **pEmxArray, int numDimensions)
{
  emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (emxArray_struct_T *)malloc(sizeof(emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (struct_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : g_emxArray_struct_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_struct_T7(g_emxArray_struct_T **pEmxArray, int numDimensions)
{
  g_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (g_emxArray_struct_T *)malloc(sizeof(g_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (g_struct_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_uint32_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_uint32_T(emxArray_uint32_T **pEmxArray, int numDimensions)
{
  emxArray_uint32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_uint32_T *)malloc(sizeof(emxArray_uint32_T));
  emxArray = *pEmxArray;
  emxArray->data = (unsigned int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_uint8_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int numDimensions)
{
  emxArray_uint8_T *emxArray;
  int i;
  *pEmxArray = (emxArray_uint8_T *)malloc(sizeof(emxArray_uint8_T));
  emxArray = *pEmxArray;
  emxArray->data = (unsigned char *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * File trailer for opkene_emxutil.c
 *
 * [EOF]
 */
