/*
 * File: getFISCodeGenerationData.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "getFISCodeGenerationData.h"
#include "any.h"
#include "deblank.h"
#include "fileManager.h"
#include "findTopic.h"
#include "getNextLine.h"
#include "getRules.h"
#include "fclose.h"
#include "opkene_data.h"
#include "opkene_emxutil.h"
#include "opkene_types.h"
#include "readFISAsHomogenousStructure.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include <stdio.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_char_T *name
 *                emxArray_char_T *fis_name
 *                emxArray_char_T *fis_type
 *                emxArray_char_T *fis_andMethod
 *                emxArray_char_T *fis_orMethod
 *                emxArray_char_T *fis_defuzzMethod
 *                emxArray_char_T *fis_impMethod
 *                emxArray_char_T *fis_aggMethod
 *                b_emxArray_struct_T *fis_input
 *                b_emxArray_struct_T *fis_output
 *                c_emxArray_struct_T *fis_rule
 * Return Type  : void
 */
void getFISCodeGenerationData(
    const emxArray_char_T *name, emxArray_char_T *fis_name,
    emxArray_char_T *fis_type, emxArray_char_T *fis_andMethod,
    emxArray_char_T *fis_orMethod, emxArray_char_T *fis_defuzzMethod,
    emxArray_char_T *fis_impMethod, emxArray_char_T *fis_aggMethod,
    b_emxArray_struct_T *fis_input, b_emxArray_struct_T *fis_output,
    c_emxArray_struct_T *fis_rule)
{
  static const char cv[8] = {'[', 'S', 'y', 's', 't', 'e', 'm', ']'};
  static const unsigned char uv2[8] = {85U,  110U, 116U, 105U,
                                       116U, 108U, 101U, 100U};
  static const unsigned char uv4[8] = {99U,  101U, 110U, 116U,
                                       114U, 111U, 105U, 100U};
  static const unsigned char uv[7] = {109U, 97U, 109U, 100U, 97U, 110U, 105U};
  static const char cv1[6] = {'s', 'u', 'g', 'e', 'n', 'o'};
  static const unsigned char uv1[6] = {115U, 117U, 103U, 101U, 110U, 111U};
  static const unsigned char uv3[6] = {112U, 114U, 111U, 98U, 111U, 114U};
  static const unsigned char uv5[6] = {119U, 116U, 97U, 118U, 101U, 114U};
  FILE *filestar;
  size_t nBytes;
  emxArray_char_T *a;
  emxArray_char_T *b_nextLineVar;
  emxArray_int32_T *r;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_int32_T *r5;
  emxArray_int32_T *r6;
  emxArray_uint8_T *At;
  emxArray_uint8_T *aggMethod;
  emxArray_uint8_T *andMethod;
  emxArray_uint8_T *defuzzMethod;
  emxArray_uint8_T *impMethod;
  emxArray_uint8_T *nextLineVar;
  emxArray_uint8_T *orMethod;
  emxArray_uint8_T *type;
  double inputInfo_maxInputNameLength;
  double inputInfo_maxMFNameLength;
  double inputInfo_maxMFParamLength;
  double inputInfo_maxMFTypeLength;
  double inputInfo_maxNumMF;
  double inputInfo_numVars;
  double outputInfo_maxInputNameLength;
  double outputInfo_maxMFNameLength;
  double outputInfo_maxMFParamLength;
  double outputInfo_maxMFTypeLength;
  double outputInfo_maxNumMF;
  double outputInfo_numVars;
  int b_i;
  int c;
  int exitg1;
  int i;
  int i1;
  int lastIndex;
  int *r1;
  signed char fileid;
  unsigned char *At_data;
  unsigned char *aggMethod_data;
  unsigned char *andMethod_data;
  unsigned char *defuzzMethod_data;
  unsigned char *impMethod_data;
  char *nextLineVar_data;
  unsigned char *orMethod_data;
  unsigned char *type_data;
  boolean_T isSugeno;
  boolean_T systemSectionHeaderFound;
  fileid = cfopen(name, "rb");
  if (fileid < 0) {
    exit(0);
  }
  emxInit_uint8_T(&At, 1);
  At_data = At->data;
  nBytes = sizeof(unsigned char);
  filestar = fileManager(fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    filestar = NULL;
  }
  At->size[0] = 0;
  if (!(filestar == NULL)) {
    c = 1;
    while (c > 0) {
      unsigned char tbuf[1024];
      c = 0;
      lastIndex = 1;
      while ((c < 1024) && (lastIndex > 0)) {
        size_t numReadSizeT;
        numReadSizeT = fread(&tbuf[c], nBytes, (size_t)(1024 - c), filestar);
        lastIndex = (int)numReadSizeT;
        c += (int)numReadSizeT;
      }
      if (c < 1) {
        lastIndex = 0;
      } else {
        lastIndex = c;
      }
      i = At->size[0];
      i1 = At->size[0];
      At->size[0] += lastIndex;
      emxEnsureCapacity_uint8_T(At, i1);
      At_data = At->data;
      for (i1 = 0; i1 < lastIndex; i1++) {
        At_data[i + i1] = tbuf[i1];
      }
    }
  }
  c = 0;
  lastIndex = 0;
  i = At->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    if (At_data[b_i] == 10) {
      i1 = b_i - lastIndex;
      if (i1 > c) {
        c = i1;
        lastIndex = b_i;
      }
    }
  }
  emxFree_uint8_T(&At);
  if (c == 0) {
    b_fclose(fileid);
    exit(0);
  }
  filestar = fileManager(fileid);
  if ((!(filestar == NULL)) && (fileid != 0) && (fileid != 1) &&
      (fileid != 2)) {
    fseek(filestar, 0, SEEK_SET);
  }
  if (c < 8) {
    c = 8;
  }
  systemSectionHeaderFound = false;
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_char_T(&a, 2);
  emxInit_char_T(&b_nextLineVar, 2);
  int exitg2;
  do {
    exitg2 = 0;
    isSugeno = !systemSectionHeaderFound;
    if (isSugeno) {
      getLine(fileid, c, nextLineVar);
      At_data = nextLineVar->data;
      while (any(nextLineVar) &&
             (((signed char)At_data[0] == '%') || (At_data[0] == 10))) {
        getLine(fileid, c, nextLineVar);
        At_data = nextLineVar->data;
      }
      filestar = fileManager(fileid);
      if (filestar == NULL) {
        i = 0;
      } else {
        int st;
        st = feof(filestar);
        i = ((int)st != 0);
      }
      if (i != 0) {
        exitg2 = 1;
      } else {
        i = b_nextLineVar->size[0] * b_nextLineVar->size[1];
        b_nextLineVar->size[0] = 1;
        b_nextLineVar->size[1] = nextLineVar->size[1];
        emxEnsureCapacity_char_T(b_nextLineVar, i);
        nextLineVar_data = b_nextLineVar->data;
        lastIndex = nextLineVar->size[1];
        for (i = 0; i < lastIndex; i++) {
          nextLineVar_data[i] = (signed char)At_data[i];
        }
        deblank(b_nextLineVar, a);
        nextLineVar_data = a->data;
        systemSectionHeaderFound = false;
        if (a->size[1] == 8) {
          lastIndex = 0;
          do {
            exitg1 = 0;
            if (lastIndex < 8) {
              if (nextLineVar_data[lastIndex] != cv[lastIndex]) {
                exitg1 = 1;
              } else {
                lastIndex++;
              }
            } else {
              systemSectionHeaderFound = true;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }
      }
    } else {
      exitg2 = 1;
    }
  } while (exitg2 == 0);
  emxInit_uint8_T(&type, 2);
  emxInit_uint8_T(&andMethod, 2);
  emxInit_uint8_T(&orMethod, 2);
  emxInit_uint8_T(&impMethod, 2);
  emxInit_uint8_T(&aggMethod, 2);
  emxInit_uint8_T(&defuzzMethod, 2);
  if (systemSectionHeaderFound) {
    findTopic(fileid, c, nextLineVar);
    At_data = nextLineVar->data;
    b_findTopic(fileid, c, type);
    type_data = type->data;
    c_findTopic(fileid, c, andMethod);
    andMethod_data = andMethod->data;
    d_findTopic(fileid, c, orMethod);
    orMethod_data = orMethod->data;
    e_findTopic(fileid, c, impMethod);
    impMethod_data = impMethod->data;
    f_findTopic(fileid, c, aggMethod);
    aggMethod_data = aggMethod->data;
    g_findTopic(fileid, c, defuzzMethod);
    defuzzMethod_data = defuzzMethod->data;
  } else {
    i = nextLineVar->size[0] * nextLineVar->size[1];
    nextLineVar->size[0] = 1;
    nextLineVar->size[1] = c;
    emxEnsureCapacity_uint8_T(nextLineVar, i);
    At_data = nextLineVar->data;
    i = type->size[0] * type->size[1];
    type->size[0] = 1;
    type->size[1] = c;
    emxEnsureCapacity_uint8_T(type, i);
    type_data = type->data;
    i = andMethod->size[0] * andMethod->size[1];
    andMethod->size[0] = 1;
    andMethod->size[1] = c;
    emxEnsureCapacity_uint8_T(andMethod, i);
    andMethod_data = andMethod->data;
    i = orMethod->size[0] * orMethod->size[1];
    orMethod->size[0] = 1;
    orMethod->size[1] = c;
    emxEnsureCapacity_uint8_T(orMethod, i);
    orMethod_data = orMethod->data;
    i = impMethod->size[0] * impMethod->size[1];
    impMethod->size[0] = 1;
    impMethod->size[1] = c;
    emxEnsureCapacity_uint8_T(impMethod, i);
    impMethod_data = impMethod->data;
    i = aggMethod->size[0] * aggMethod->size[1];
    aggMethod->size[0] = 1;
    aggMethod->size[1] = c;
    emxEnsureCapacity_uint8_T(aggMethod, i);
    aggMethod_data = aggMethod->data;
    i = defuzzMethod->size[0] * defuzzMethod->size[1];
    defuzzMethod->size[0] = 1;
    defuzzMethod->size[1] = c;
    emxEnsureCapacity_uint8_T(defuzzMethod, i);
    defuzzMethod_data = defuzzMethod->data;
    for (i = 0; i < c; i++) {
      At_data[i] = 0U;
      type_data[i] = 0U;
      andMethod_data[i] = 0U;
      orMethod_data[i] = 0U;
      impMethod_data[i] = 0U;
      aggMethod_data[i] = 0U;
      defuzzMethod_data[i] = 0U;
    }
  }
  filestar = fileManager(fileid);
  if ((!(filestar == NULL)) && (fileid != 0) && (fileid != 1) &&
      (fileid != 2)) {
    fseek(filestar, 0, SEEK_SET);
  }
  inputInfo_maxInputNameLength =
      getVarInfo(fileid, c, &inputInfo_maxNumMF, &inputInfo_maxMFNameLength,
                 &inputInfo_maxMFTypeLength, &inputInfo_maxMFParamLength,
                 &inputInfo_numVars, &systemSectionHeaderFound);
  filestar = fileManager(fileid);
  if ((!(filestar == NULL)) && (fileid != 0) && (fileid != 1) &&
      (fileid != 2)) {
    fseek(filestar, 0, SEEK_SET);
  }
  if (isSugeno || (!any(type))) {
    systemSectionHeaderFound = true;
  } else {
    systemSectionHeaderFound = false;
  }
  outputInfo_maxInputNameLength = b_getVarInfo(
      fileid, c, systemSectionHeaderFound, &outputInfo_maxNumMF,
      &outputInfo_maxMFNameLength, &outputInfo_maxMFTypeLength,
      &outputInfo_maxMFParamLength, &outputInfo_numVars, &isSugeno);
  filestar = fileManager(fileid);
  if ((!(filestar == NULL)) && (fileid != 0) && (fileid != 1) &&
      (fileid != 2)) {
    fseek(filestar, 0, SEEK_SET);
  }
  if (systemSectionHeaderFound) {
    if (isSugeno) {
      for (i = 0; i < 6; i++) {
        type_data[i] = uv1[i];
      }
    } else {
      for (i = 0; i < 7; i++) {
        type_data[i] = uv[i];
      }
    }
  } else {
    i = b_nextLineVar->size[0] * b_nextLineVar->size[1];
    b_nextLineVar->size[0] = 1;
    b_nextLineVar->size[1] = type->size[1];
    emxEnsureCapacity_char_T(b_nextLineVar, i);
    nextLineVar_data = b_nextLineVar->data;
    lastIndex = type->size[1];
    for (i = 0; i < lastIndex; i++) {
      nextLineVar_data[i] = (signed char)type_data[i];
    }
    deblank(b_nextLineVar, a);
    nextLineVar_data = a->data;
    isSugeno = false;
    if (a->size[1] == 6) {
      lastIndex = 0;
      do {
        exitg1 = 0;
        if (lastIndex < 6) {
          if (nextLineVar_data[lastIndex] != cv1[lastIndex]) {
            exitg1 = 1;
          } else {
            lastIndex++;
          }
        } else {
          isSugeno = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
  }
  emxFree_char_T(&b_nextLineVar);
  emxFree_char_T(&a);
  getVar(fileid, c, inputInfo_maxInputNameLength, inputInfo_maxNumMF,
         inputInfo_maxMFNameLength, inputInfo_maxMFTypeLength,
         inputInfo_maxMFParamLength, inputInfo_numVars, fis_input);
  b_getVar(fileid, c, outputInfo_maxInputNameLength, outputInfo_maxNumMF,
           outputInfo_maxMFNameLength, outputInfo_maxMFTypeLength,
           outputInfo_maxMFParamLength, outputInfo_numVars, isSugeno,
           fis_output);
  getRules(fileid, c, inputInfo_numVars, outputInfo_numVars, fis_rule);
  if (!any(nextLineVar)) {
    for (i = 0; i < 8; i++) {
      At_data[i] = uv2[i];
    }
  }
  if (isSugeno) {
    lastIndex = impMethod->size[1];
    i = impMethod->size[0] * impMethod->size[1];
    impMethod->size[0] = 1;
    impMethod->size[1] = lastIndex;
    emxEnsureCapacity_uint8_T(impMethod, i);
    impMethod_data = impMethod->data;
    for (i = 0; i < lastIndex; i++) {
      impMethod_data[i] = 0U;
    }
    impMethod_data[0] = 112U;
    impMethod_data[1] = 114U;
    impMethod_data[2] = 111U;
    impMethod_data[3] = 100U;
    lastIndex = aggMethod->size[1];
    i = aggMethod->size[0] * aggMethod->size[1];
    aggMethod->size[0] = 1;
    aggMethod->size[1] = lastIndex;
    emxEnsureCapacity_uint8_T(aggMethod, i);
    aggMethod_data = aggMethod->data;
    for (i = 0; i < lastIndex; i++) {
      aggMethod_data[i] = 0U;
    }
    aggMethod_data[0] = 115U;
    aggMethod_data[1] = 117U;
    aggMethod_data[2] = 109U;
  }
  if (!any(andMethod)) {
    if (isSugeno) {
      andMethod_data[0] = 112U;
      andMethod_data[1] = 114U;
      andMethod_data[2] = 111U;
      andMethod_data[3] = 100U;
    } else {
      andMethod_data[0] = 109U;
      andMethod_data[1] = 105U;
      andMethod_data[2] = 110U;
    }
  }
  if (!any(orMethod)) {
    if (isSugeno) {
      for (i = 0; i < 6; i++) {
        orMethod_data[i] = uv3[i];
      }
    } else {
      orMethod_data[0] = 109U;
      orMethod_data[1] = 97U;
      orMethod_data[2] = 120U;
    }
  }
  if ((!any(impMethod)) && (!isSugeno)) {
    impMethod_data[0] = 109U;
    impMethod_data[1] = 105U;
    impMethod_data[2] = 110U;
  }
  if ((!any(aggMethod)) && (!isSugeno)) {
    aggMethod_data[0] = 109U;
    aggMethod_data[1] = 97U;
    aggMethod_data[2] = 120U;
  }
  if (!any(defuzzMethod)) {
    if (isSugeno) {
      for (i = 0; i < 6; i++) {
        defuzzMethod_data[i] = uv5[i];
      }
    } else {
      for (i = 0; i < 8; i++) {
        defuzzMethod_data[i] = uv4[i];
      }
    }
  }
  i = fis_name->size[0] * fis_name->size[1];
  fis_name->size[0] = 1;
  emxEnsureCapacity_char_T(fis_name, i);
  c = nextLineVar->size[1] - 1;
  lastIndex = 0;
  for (b_i = 0; b_i <= c; b_i++) {
    if (At_data[b_i] != 0) {
      lastIndex++;
    }
  }
  i = fis_name->size[0] * fis_name->size[1];
  fis_name->size[1] = lastIndex;
  emxEnsureCapacity_char_T(fis_name, i);
  nextLineVar_data = fis_name->data;
  lastIndex = 0;
  for (b_i = 0; b_i <= c; b_i++) {
    unsigned char u;
    u = At_data[b_i];
    if (u != 0) {
      nextLineVar_data[lastIndex] = (signed char)u;
      lastIndex++;
    }
  }
  emxFree_uint8_T(&nextLineVar);
  c = type->size[1] - 1;
  lastIndex = 0;
  for (b_i = 0; b_i <= c; b_i++) {
    if (type_data[b_i] != 0) {
      lastIndex++;
    }
  }
  emxInit_int32_T(&r);
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = lastIndex;
  emxEnsureCapacity_int32_T(r, i);
  r1 = r->data;
  lastIndex = 0;
  for (b_i = 0; b_i <= c; b_i++) {
    if (type_data[b_i] != 0) {
      r1[lastIndex] = b_i;
      lastIndex++;
    }
  }
  lastIndex = r->size[1];
  i = fis_type->size[0] * fis_type->size[1];
  fis_type->size[0] = 1;
  fis_type->size[1] = r->size[1];
  emxEnsureCapacity_char_T(fis_type, i);
  nextLineVar_data = fis_type->data;
  for (i = 0; i < lastIndex; i++) {
    nextLineVar_data[i] = (signed char)type_data[r1[i]];
  }
  emxFree_int32_T(&r);
  emxFree_uint8_T(&type);
  c = andMethod->size[1] - 1;
  lastIndex = 0;
  for (b_i = 0; b_i <= c; b_i++) {
    if (andMethod_data[b_i] != 0) {
      lastIndex++;
    }
  }
  emxInit_int32_T(&r2);
  i = r2->size[0] * r2->size[1];
  r2->size[0] = 1;
  r2->size[1] = lastIndex;
  emxEnsureCapacity_int32_T(r2, i);
  r1 = r2->data;
  lastIndex = 0;
  for (b_i = 0; b_i <= c; b_i++) {
    if (andMethod_data[b_i] != 0) {
      r1[lastIndex] = b_i;
      lastIndex++;
    }
  }
  lastIndex = r2->size[1];
  i = fis_andMethod->size[0] * fis_andMethod->size[1];
  fis_andMethod->size[0] = 1;
  fis_andMethod->size[1] = r2->size[1];
  emxEnsureCapacity_char_T(fis_andMethod, i);
  nextLineVar_data = fis_andMethod->data;
  for (i = 0; i < lastIndex; i++) {
    nextLineVar_data[i] = (signed char)andMethod_data[r1[i]];
  }
  emxFree_int32_T(&r2);
  emxFree_uint8_T(&andMethod);
  c = orMethod->size[1] - 1;
  lastIndex = 0;
  for (b_i = 0; b_i <= c; b_i++) {
    if (orMethod_data[b_i] != 0) {
      lastIndex++;
    }
  }
  emxInit_int32_T(&r3);
  i = r3->size[0] * r3->size[1];
  r3->size[0] = 1;
  r3->size[1] = lastIndex;
  emxEnsureCapacity_int32_T(r3, i);
  r1 = r3->data;
  lastIndex = 0;
  for (b_i = 0; b_i <= c; b_i++) {
    if (orMethod_data[b_i] != 0) {
      r1[lastIndex] = b_i;
      lastIndex++;
    }
  }
  lastIndex = r3->size[1];
  i = fis_orMethod->size[0] * fis_orMethod->size[1];
  fis_orMethod->size[0] = 1;
  fis_orMethod->size[1] = r3->size[1];
  emxEnsureCapacity_char_T(fis_orMethod, i);
  nextLineVar_data = fis_orMethod->data;
  for (i = 0; i < lastIndex; i++) {
    nextLineVar_data[i] = (signed char)orMethod_data[r1[i]];
  }
  emxFree_int32_T(&r3);
  emxFree_uint8_T(&orMethod);
  c = defuzzMethod->size[1] - 1;
  lastIndex = 0;
  for (b_i = 0; b_i <= c; b_i++) {
    if (defuzzMethod_data[b_i] != 0) {
      lastIndex++;
    }
  }
  emxInit_int32_T(&r4);
  i = r4->size[0] * r4->size[1];
  r4->size[0] = 1;
  r4->size[1] = lastIndex;
  emxEnsureCapacity_int32_T(r4, i);
  r1 = r4->data;
  lastIndex = 0;
  for (b_i = 0; b_i <= c; b_i++) {
    if (defuzzMethod_data[b_i] != 0) {
      r1[lastIndex] = b_i;
      lastIndex++;
    }
  }
  lastIndex = r4->size[1];
  i = fis_defuzzMethod->size[0] * fis_defuzzMethod->size[1];
  fis_defuzzMethod->size[0] = 1;
  fis_defuzzMethod->size[1] = r4->size[1];
  emxEnsureCapacity_char_T(fis_defuzzMethod, i);
  nextLineVar_data = fis_defuzzMethod->data;
  for (i = 0; i < lastIndex; i++) {
    nextLineVar_data[i] = (signed char)defuzzMethod_data[r1[i]];
  }
  emxFree_int32_T(&r4);
  emxFree_uint8_T(&defuzzMethod);
  c = impMethod->size[1] - 1;
  lastIndex = 0;
  for (b_i = 0; b_i <= c; b_i++) {
    if (impMethod_data[b_i] != 0) {
      lastIndex++;
    }
  }
  emxInit_int32_T(&r5);
  i = r5->size[0] * r5->size[1];
  r5->size[0] = 1;
  r5->size[1] = lastIndex;
  emxEnsureCapacity_int32_T(r5, i);
  r1 = r5->data;
  lastIndex = 0;
  for (b_i = 0; b_i <= c; b_i++) {
    if (impMethod_data[b_i] != 0) {
      r1[lastIndex] = b_i;
      lastIndex++;
    }
  }
  lastIndex = r5->size[1];
  i = fis_impMethod->size[0] * fis_impMethod->size[1];
  fis_impMethod->size[0] = 1;
  fis_impMethod->size[1] = r5->size[1];
  emxEnsureCapacity_char_T(fis_impMethod, i);
  nextLineVar_data = fis_impMethod->data;
  for (i = 0; i < lastIndex; i++) {
    nextLineVar_data[i] = (signed char)impMethod_data[r1[i]];
  }
  emxFree_int32_T(&r5);
  emxFree_uint8_T(&impMethod);
  c = aggMethod->size[1] - 1;
  lastIndex = 0;
  for (b_i = 0; b_i <= c; b_i++) {
    if (aggMethod_data[b_i] != 0) {
      lastIndex++;
    }
  }
  emxInit_int32_T(&r6);
  i = r6->size[0] * r6->size[1];
  r6->size[0] = 1;
  r6->size[1] = lastIndex;
  emxEnsureCapacity_int32_T(r6, i);
  r1 = r6->data;
  lastIndex = 0;
  for (b_i = 0; b_i <= c; b_i++) {
    if (aggMethod_data[b_i] != 0) {
      r1[lastIndex] = b_i;
      lastIndex++;
    }
  }
  lastIndex = r6->size[1];
  i = fis_aggMethod->size[0] * fis_aggMethod->size[1];
  fis_aggMethod->size[0] = 1;
  fis_aggMethod->size[1] = r6->size[1];
  emxEnsureCapacity_char_T(fis_aggMethod, i);
  nextLineVar_data = fis_aggMethod->data;
  for (i = 0; i < lastIndex; i++) {
    nextLineVar_data[i] = (signed char)aggMethod_data[r1[i]];
  }
  emxFree_int32_T(&r6);
  emxFree_uint8_T(&aggMethod);
  b_fclose(fileid);
}

/*
 * File trailer for getFISCodeGenerationData.c
 *
 * [EOF]
 */
