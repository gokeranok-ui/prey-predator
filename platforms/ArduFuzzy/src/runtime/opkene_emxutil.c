/*
 * File: opkene_emxutil.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "opkene_emxutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"
#include <stdlib.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : double dst[2]
 *                const double src[2]
 * Return Type  : void
 */
void emxCopyMatrix_real_T(double dst[2], const double src[2])
{
  int i;
  for (i = 0; i < 2; i++) {
    dst[i] = src[i];
  }
}

/*
 * Arguments    : struct_T *dst
 *                const struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T(struct_T *dst, const struct_T *src)
{
  emxCopy_char_T(&dst->name, &src->name);
  dst->origNameLength = src->origNameLength;
  emxCopy_char_T(&dst->type, &src->type);
  dst->origTypeLength = src->origTypeLength;
  emxCopy_real_T(&dst->params, &src->params);
  dst->origParamLength = src->origParamLength;
}

/*
 * Arguments    : b_struct_T *dst
 *                const b_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T1(b_struct_T *dst, const b_struct_T *src)
{
  emxCopy_char_T(&dst->name, &src->name);
  dst->origNameLength = src->origNameLength;
  emxCopyMatrix_real_T(dst->range, src->range);
  emxCopy_struct_T(&dst->mf, &src->mf);
  dst->origNumMF = src->origNumMF;
}

/*
 * Arguments    : c_struct_T *dst
 *                const c_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T2(c_struct_T *dst, const c_struct_T *src)
{
  emxCopy_real_T(&dst->antecedent, &src->antecedent);
  emxCopy_real_T(&dst->consequent, &src->consequent);
  dst->weight = src->weight;
  dst->connection = src->connection;
}

/*
 * Arguments    : f_struct_T *dst
 *                const f_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T3(f_struct_T *dst, const f_struct_T *src)
{
  emxCopy_char_T(&dst->type, &src->type);
  dst->origTypeLength = src->origTypeLength;
  emxCopy_real_T(&dst->params, &src->params);
  dst->origParamLength = src->origParamLength;
}

/*
 * Arguments    : g_struct_T *dst
 *                const g_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T4(g_struct_T *dst, const g_struct_T *src)
{
  emxCopy_struct_T1(&dst->mf, &src->mf);
  dst->origNumMF = src->origNumMF;
}

/*
 * Arguments    : d_struct_T *dst
 *                const d_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T5(d_struct_T *dst, const d_struct_T *src)
{
  emxCopy_char_T(&dst->type, &src->type);
  dst->origTypeLength = src->origTypeLength;
  emxCopy_real_T(&dst->params, &src->params);
  dst->origParamLength = src->origParamLength;
}

/*
 * Arguments    : e_struct_T *dst
 *                const e_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T6(e_struct_T *dst, const e_struct_T *src)
{
  emxCopy_struct_T2(&dst->mf, &src->mf);
  dst->origNumMF = src->origNumMF;
}

/*
 * Arguments    : h_struct_T *dst
 *                const h_struct_T *src
 * Return Type  : void
 */
void emxCopyStruct_struct_T7(h_struct_T *dst, const h_struct_T *src)
{
  emxCopy_char_T(&dst->type, &src->type);
  emxCopy_real_T(&dst->params, &src->params);
}

/*
 * Arguments    : emxArray_char_T **dst
 *                emxArray_char_T * const *src
 * Return Type  : void
 */
void emxCopy_char_T(emxArray_char_T **dst, emxArray_char_T *const *src)
{
  int i;
  int numElDst;
  int numElSrc;
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
void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T *const *src)
{
  int i;
  int numElDst;
  int numElSrc;
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
 * Arguments    : emxArray_struct_T **dst
 *                emxArray_struct_T * const *src
 * Return Type  : void
 */
void emxCopy_struct_T(emxArray_struct_T **dst, emxArray_struct_T *const *src)
{
  int i;
  int numElDst;
  int numElSrc;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }
  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }
  emxEnsureCapacity_struct_T(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    emxCopyStruct_struct_T(&(*dst)->data[i], &(*src)->data[i]);
  }
}

/*
 * Arguments    : f_emxArray_struct_T **dst
 *                f_emxArray_struct_T * const *src
 * Return Type  : void
 */
void emxCopy_struct_T1(f_emxArray_struct_T **dst,
                       f_emxArray_struct_T *const *src)
{
  int i;
  int numElDst;
  int numElSrc;
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
 * Arguments    : d_emxArray_struct_T **dst
 *                d_emxArray_struct_T * const *src
 * Return Type  : void
 */
void emxCopy_struct_T2(d_emxArray_struct_T **dst,
                       d_emxArray_struct_T *const *src)
{
  int i;
  int numElDst;
  int numElSrc;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }
  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }
  emxEnsureCapacity_struct_T5(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    emxCopyStruct_struct_T5(&(*dst)->data[i], &(*src)->data[i]);
  }
}

/*
 * Arguments    : emxArray_boolean_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
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
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(boolean_T) * (unsigned int)oldNumel);
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
  int i;
  int newNumel;
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
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(cell_wrap_0));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(cell_wrap_0) * (unsigned int)oldNumel);
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
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_0(emxArray, oldNumel, newNumel);
  }
}

/*
 * Arguments    : emxArray_char_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_char_T(emxArray_char_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
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
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(char));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(char) * (unsigned int)oldNumel);
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
  int i;
  int newNumel;
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
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(int));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int) * (unsigned int)oldNumel);
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
 * Arguments    : emxArray_real_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
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
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(double));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(double) * (unsigned int)oldNumel);
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
 * Arguments    : emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T(emxArray_struct_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
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
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(struct_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_struct_T(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_struct_T(emxArray, oldNumel, newNumel);
  }
}

/*
 * Arguments    : b_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T1(b_emxArray_struct_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
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
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(b_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(b_struct_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (b_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_struct_T1(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_struct_T1(emxArray, oldNumel, newNumel);
  }
}

/*
 * Arguments    : c_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T2(c_emxArray_struct_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
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
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(c_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(c_struct_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (c_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_struct_T2(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_struct_T2(emxArray, oldNumel, newNumel);
  }
}

/*
 * Arguments    : f_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T3(f_emxArray_struct_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
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
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(f_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(f_struct_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (f_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_struct_T3(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_struct_T3(emxArray, oldNumel, newNumel);
  }
}

/*
 * Arguments    : g_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T4(g_emxArray_struct_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
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
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(g_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(g_struct_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (g_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_struct_T4(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_struct_T4(emxArray, oldNumel, newNumel);
  }
}

/*
 * Arguments    : d_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T5(d_emxArray_struct_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
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
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(d_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(d_struct_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (d_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_struct_T5(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_struct_T5(emxArray, oldNumel, newNumel);
  }
}

/*
 * Arguments    : e_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T6(e_emxArray_struct_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
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
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(e_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(e_struct_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (e_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_struct_T6(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_struct_T6(emxArray, oldNumel, newNumel);
  }
}

/*
 * Arguments    : h_emxArray_struct_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_struct_T7(h_emxArray_struct_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
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
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(h_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(h_struct_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (h_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_struct_T7(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_struct_T7(emxArray, oldNumel, newNumel);
  }
}

/*
 * Arguments    : emxArray_uint8_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
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
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(unsigned char));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(unsigned char) * (unsigned int)oldNumel);
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
 * Arguments    : emxArray_cell_wrap_0 *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
void emxExpand_cell_wrap_0(emxArray_cell_wrap_0 *emxArray, int fromIndex,
                           int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_0(&emxArray->data[i]);
  }
}

/*
 * Arguments    : emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
void emxExpand_struct_T(emxArray_struct_T *emxArray, int fromIndex, int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T1(&emxArray->data[i]);
  }
}

/*
 * Arguments    : b_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
void emxExpand_struct_T1(b_emxArray_struct_T *emxArray, int fromIndex,
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
void emxExpand_struct_T2(c_emxArray_struct_T *emxArray, int fromIndex,
                         int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T3(&emxArray->data[i]);
  }
}

/*
 * Arguments    : f_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
void emxExpand_struct_T3(f_emxArray_struct_T *emxArray, int fromIndex,
                         int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T4(&emxArray->data[i]);
  }
}

/*
 * Arguments    : g_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
void emxExpand_struct_T4(g_emxArray_struct_T *emxArray, int fromIndex,
                         int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T5(&emxArray->data[i]);
  }
}

/*
 * Arguments    : d_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
void emxExpand_struct_T5(d_emxArray_struct_T *emxArray, int fromIndex,
                         int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T6(&emxArray->data[i]);
  }
}

/*
 * Arguments    : e_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
void emxExpand_struct_T6(e_emxArray_struct_T *emxArray, int fromIndex,
                         int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T7(&emxArray->data[i]);
  }
}

/*
 * Arguments    : h_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
void emxExpand_struct_T7(h_emxArray_struct_T *emxArray, int fromIndex,
                         int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T8(&emxArray->data[i]);
  }
}

/*
 * Arguments    : cell_wrap_0 *pStruct
 * Return Type  : void
 */
void emxFreeStruct_cell_wrap_0(cell_wrap_0 *pStruct)
{
  emxFree_struct_T7(&pStruct->f1);
}

/*
 * Arguments    : b_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T(b_struct_T *pStruct)
{
  emxFree_char_T(&pStruct->name);
  emxFree_struct_T1(&pStruct->mf);
}

/*
 * Arguments    : struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T1(struct_T *pStruct)
{
  emxFree_char_T(&pStruct->name);
  emxFree_char_T(&pStruct->type);
  emxFree_real_T(&pStruct->params);
}

/*
 * Arguments    : c_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T2(c_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->antecedent);
  emxFree_real_T(&pStruct->consequent);
}

/*
 * Arguments    : i_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T3(i_struct_T *pStruct)
{
  emxFree_uint8_T(&pStruct->type);
  emxFree_uint8_T(&pStruct->andMethod);
  emxFree_uint8_T(&pStruct->orMethod);
  emxFree_uint8_T(&pStruct->defuzzMethod);
  emxFree_uint8_T(&pStruct->impMethod);
  emxFree_uint8_T(&pStruct->aggMethod);
  emxFree_real_T(&pStruct->inputRange);
  emxFree_real_T(&pStruct->outputRange);
  emxFree_struct_T3(&pStruct->inputMF);
  emxFree_struct_T3(&pStruct->outputMF);
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
 * Arguments    : d_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T4(d_struct_T *pStruct)
{
  emxFree_char_T(&pStruct->type);
  emxFree_real_T(&pStruct->params);
}

/*
 * Arguments    : e_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T5(e_struct_T *pStruct)
{
  emxFree_struct_T4(&pStruct->mf);
}

/*
 * Arguments    : f_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T6(f_struct_T *pStruct)
{
  emxFree_char_T(&pStruct->type);
  emxFree_real_T(&pStruct->params);
}

/*
 * Arguments    : g_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T7(g_struct_T *pStruct)
{
  emxFree_struct_T6(&pStruct->mf);
}

/*
 * Arguments    : h_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T8(h_struct_T *pStruct)
{
  emxFree_char_T(&pStruct->type);
  emxFree_real_T(&pStruct->params);
}

/*
 * Arguments    : emxArray_boolean_T **pEmxArray
 * Return Type  : void
 */
void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
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
  int i;
  if (*pEmxArray != (emxArray_cell_wrap_0 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_0 *)NULL) {
      int numEl;
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
 * Arguments    : b_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T(b_emxArray_struct_T **pEmxArray)
{
  int i;
  if (*pEmxArray != (b_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (b_struct_T *)NULL) {
      int numEl;
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
    *pEmxArray = (b_emxArray_struct_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T1(emxArray_struct_T **pEmxArray)
{
  int i;
  if (*pEmxArray != (emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (struct_T *)NULL) {
      int numEl;
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
    *pEmxArray = (emxArray_struct_T *)NULL;
  }
}

/*
 * Arguments    : c_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T2(c_emxArray_struct_T **pEmxArray)
{
  int i;
  if (*pEmxArray != (c_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (c_struct_T *)NULL) {
      int numEl;
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
 * Arguments    : e_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T3(e_emxArray_struct_T **pEmxArray)
{
  int i;
  if (*pEmxArray != (e_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (e_struct_T *)NULL) {
      int numEl;
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
    *pEmxArray = (e_emxArray_struct_T *)NULL;
  }
}

/*
 * Arguments    : d_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T4(d_emxArray_struct_T **pEmxArray)
{
  int i;
  if (*pEmxArray != (d_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (d_struct_T *)NULL) {
      int numEl;
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
    *pEmxArray = (d_emxArray_struct_T *)NULL;
  }
}

/*
 * Arguments    : g_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T5(g_emxArray_struct_T **pEmxArray)
{
  int i;
  if (*pEmxArray != (g_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (g_struct_T *)NULL) {
      int numEl;
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct_T7(&(*pEmxArray)->data[i]);
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
 * Arguments    : f_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T6(f_emxArray_struct_T **pEmxArray)
{
  int i;
  if (*pEmxArray != (f_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (f_struct_T *)NULL) {
      int numEl;
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
    *pEmxArray = (f_emxArray_struct_T *)NULL;
  }
}

/*
 * Arguments    : h_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct_T7(h_emxArray_struct_T **pEmxArray)
{
  int i;
  if (*pEmxArray != (h_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (h_struct_T *)NULL) {
      int numEl;
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct_T8(&(*pEmxArray)->data[i]);
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
 * Arguments    : emxArray_uint8_T **pEmxArray
 * Return Type  : void
 */
void emxFree_uint8_T(emxArray_uint8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint8_T *)NULL) {
    if (((*pEmxArray)->data != (unsigned char *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_uint8_T *)NULL;
  }
}

/*
 * Arguments    : cell_wrap_0 *pStruct
 * Return Type  : void
 */
void emxInitStruct_cell_wrap_0(cell_wrap_0 *pStruct)
{
  emxInit_struct_T7(&pStruct->f1);
}

/*
 * Arguments    : i_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T(i_struct_T *pStruct)
{
  emxInit_uint8_T(&pStruct->type, 2);
  emxInit_uint8_T(&pStruct->andMethod, 2);
  emxInit_uint8_T(&pStruct->orMethod, 2);
  emxInit_uint8_T(&pStruct->defuzzMethod, 2);
  emxInit_uint8_T(&pStruct->impMethod, 2);
  emxInit_uint8_T(&pStruct->aggMethod, 2);
  emxInit_real_T(&pStruct->inputRange, 2);
  emxInit_real_T(&pStruct->outputRange, 2);
  emxInit_struct_T2(&pStruct->inputMF);
  emxInit_struct_T2(&pStruct->outputMF);
  emxInit_real_T(&pStruct->antecedent, 2);
  emxInit_real_T(&pStruct->consequent, 2);
  emxInit_real_T(&pStruct->connection, 2);
  emxInit_real_T(&pStruct->weight, 2);
  emxInit_int32_T(&pStruct->numInputMFs);
  emxInit_int32_T(&pStruct->numCumInputMFs);
  emxInit_int32_T(&pStruct->numOutputMFs);
  emxInit_int32_T(&pStruct->numCumOutputMFs);
  emxInit_real_T(&pStruct->outputSamplePoints, 2);
}

/*
 * Arguments    : struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T1(struct_T *pStruct)
{
  emxInit_char_T(&pStruct->name, 2);
  emxInit_char_T(&pStruct->type, 2);
  emxInit_real_T(&pStruct->params, 2);
}

/*
 * Arguments    : b_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T2(b_struct_T *pStruct)
{
  emxInit_char_T(&pStruct->name, 2);
  emxInit_struct_T4(&pStruct->mf);
}

/*
 * Arguments    : c_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T3(c_struct_T *pStruct)
{
  emxInit_real_T(&pStruct->antecedent, 2);
  emxInit_real_T(&pStruct->consequent, 2);
}

/*
 * Arguments    : f_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T4(f_struct_T *pStruct)
{
  emxInit_char_T(&pStruct->type, 2);
  emxInit_real_T(&pStruct->params, 2);
}

/*
 * Arguments    : g_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T5(g_struct_T *pStruct)
{
  emxInit_struct_T5(&pStruct->mf);
}

/*
 * Arguments    : d_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T6(d_struct_T *pStruct)
{
  emxInit_char_T(&pStruct->type, 2);
  emxInit_real_T(&pStruct->params, 2);
}

/*
 * Arguments    : e_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T7(e_struct_T *pStruct)
{
  emxInit_struct_T6(&pStruct->mf);
}

/*
 * Arguments    : h_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T8(h_struct_T *pStruct)
{
  emxInit_char_T(&pStruct->type, 2);
  emxInit_real_T(&pStruct->params, 2);
}

/*
 * Arguments    : emxArray_boolean_T **pEmxArray
 * Return Type  : void
 */
void emxInit_boolean_T(emxArray_boolean_T **pEmxArray)
{
  emxArray_boolean_T *emxArray;
  int i;
  *pEmxArray = (emxArray_boolean_T *)malloc(sizeof(emxArray_boolean_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_0 **pEmxArray
 * Return Type  : void
 */
void emxInit_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray)
{
  emxArray_cell_wrap_0 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_0 *)malloc(sizeof(emxArray_cell_wrap_0));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_0 *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
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
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 * Return Type  : void
 */
void emxInit_int32_T(emxArray_int32_T **pEmxArray)
{
  emxArray_int32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
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
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : b_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxInit_struct_T(b_emxArray_struct_T **pEmxArray)
{
  b_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (b_emxArray_struct_T *)malloc(sizeof(b_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (b_struct_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : c_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxInit_struct_T1(c_emxArray_struct_T **pEmxArray)
{
  c_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (c_emxArray_struct_T *)malloc(sizeof(c_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (c_struct_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : e_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxInit_struct_T2(e_emxArray_struct_T **pEmxArray)
{
  e_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (e_emxArray_struct_T *)malloc(sizeof(e_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (e_struct_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : g_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxInit_struct_T3(g_emxArray_struct_T **pEmxArray)
{
  g_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (g_emxArray_struct_T *)malloc(sizeof(g_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (g_struct_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxInit_struct_T4(emxArray_struct_T **pEmxArray)
{
  emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (emxArray_struct_T *)malloc(sizeof(emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (struct_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : f_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxInit_struct_T5(f_emxArray_struct_T **pEmxArray)
{
  f_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (f_emxArray_struct_T *)malloc(sizeof(f_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (f_struct_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : d_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxInit_struct_T6(d_emxArray_struct_T **pEmxArray)
{
  d_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (d_emxArray_struct_T *)malloc(sizeof(d_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (d_struct_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : h_emxArray_struct_T **pEmxArray
 * Return Type  : void
 */
void emxInit_struct_T7(h_emxArray_struct_T **pEmxArray)
{
  h_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (h_emxArray_struct_T *)malloc(sizeof(h_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (h_struct_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
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
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
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
void emxTrim_cell_wrap_0(emxArray_cell_wrap_0 *emxArray, int fromIndex,
                         int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_0(&emxArray->data[i]);
  }
}

/*
 * Arguments    : emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
void emxTrim_struct_T(emxArray_struct_T *emxArray, int fromIndex, int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T1(&emxArray->data[i]);
  }
}

/*
 * Arguments    : b_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
void emxTrim_struct_T1(b_emxArray_struct_T *emxArray, int fromIndex,
                       int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T(&emxArray->data[i]);
  }
}

/*
 * Arguments    : c_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
void emxTrim_struct_T2(c_emxArray_struct_T *emxArray, int fromIndex,
                       int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T2(&emxArray->data[i]);
  }
}

/*
 * Arguments    : f_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
void emxTrim_struct_T3(f_emxArray_struct_T *emxArray, int fromIndex,
                       int toIndex)
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
void emxTrim_struct_T4(g_emxArray_struct_T *emxArray, int fromIndex,
                       int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T7(&emxArray->data[i]);
  }
}

/*
 * Arguments    : d_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
void emxTrim_struct_T5(d_emxArray_struct_T *emxArray, int fromIndex,
                       int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T4(&emxArray->data[i]);
  }
}

/*
 * Arguments    : e_emxArray_struct_T *emxArray
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
void emxTrim_struct_T6(e_emxArray_struct_T *emxArray, int fromIndex,
                       int toIndex)
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
void emxTrim_struct_T7(h_emxArray_struct_T *emxArray, int fromIndex,
                       int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T8(&emxArray->data[i]);
  }
}

/*
 * File trailer for opkene_emxutil.c
 *
 * [EOF]
 */
