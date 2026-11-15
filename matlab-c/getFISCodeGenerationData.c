/*
 * File: getFISCodeGenerationData.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "getFISCodeGenerationData.h"
#include "opkene_emxutil.h"
#include "fclose.h"
#include "char.h"
#include "any.h"
#include "readFISAsHomogenousStructure.h"
#include "deblank.h"
#include "frewind.h"
#include "fileManager.h"

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
 *                h_emxArray_struct_T *fis_input
 *                h_emxArray_struct_T *fis_output
 *                b_emxArray_struct_T *fis_rule
 * Return Type  : void
 */
void getFISCodeGenerationData(const emxArray_char_T *name, emxArray_char_T
  *fis_name, emxArray_char_T *fis_type, emxArray_char_T *fis_andMethod,
  emxArray_char_T *fis_orMethod, emxArray_char_T *fis_defuzzMethod,
  emxArray_char_T *fis_impMethod, emxArray_char_T *fis_aggMethod,
  h_emxArray_struct_T *fis_input, h_emxArray_struct_T *fis_output,
  b_emxArray_struct_T *fis_rule)
{
  signed char fileid;
  double maxLineLength;
  boolean_T systemSectionHeaderFound;
  emxArray_uint8_T *nextLineVar;
  emxArray_char_T *a;
  emxArray_char_T *r0;
  boolean_T exitg1;
  emxArray_uint8_T *type;
  emxArray_uint8_T *andMethod;
  FILE * b_NULL;
  emxArray_uint8_T *orMethod;
  FILE * filestar;
  emxArray_uint8_T *impMethod;
  emxArray_uint8_T *aggMethod;
  int st;
  int i;
  emxArray_uint8_T *defuzzMethod;
  int kstr;
  boolean_T b_bool;
  int exitg2;
  static const char cv0[8] = { '[', 'S', 'y', 's', 't', 'e', 'm', ']' };

  double inputInfo_maxInputNameLength;
  double inputInfo_maxNumMF;
  double inputInfo_maxMFNameLength;
  double inputInfo_maxMFTypeLength;
  double inputInfo_maxMFParamLength;
  double inputInfo_numVars;
  double outputInfo_maxInputNameLength;
  double outputInfo_maxNumMF;
  double outputInfo_maxMFNameLength;
  double outputInfo_maxMFTypeLength;
  double outputInfo_maxMFParamLength;
  double outputInfo_numVars;
  static const unsigned char uv0[7] = { 109U, 97U, 109U, 100U, 97U, 110U, 105U };

  static const unsigned char uv1[6] = { 115U, 117U, 103U, 101U, 110U, 111U };

  static const char cv1[6] = { 's', 'u', 'g', 'e', 'n', 'o' };

  static const unsigned char uv2[8] = { 85U, 110U, 116U, 105U, 116U, 108U, 101U,
    100U };

  static const unsigned char uv3[6] = { 112U, 114U, 111U, 98U, 111U, 114U };

  int end;
  static const unsigned char uv4[8] = { 99U, 101U, 110U, 116U, 114U, 111U, 105U,
    100U };

  static const unsigned char uv5[6] = { 119U, 116U, 97U, 118U, 101U, 114U };

  emxArray_int32_T *r1;
  emxArray_uint8_T *b_nextLineVar;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_int32_T *r5;
  emxArray_int32_T *r6;
  emxArray_int32_T *r7;
  fileid = cfopen(name, "rb");
  if (fileid < 0) {
    exit(0);
  }

  maxLineLength = getMaxLineLength(fileid);
  if (maxLineLength == 0.0) {
    b_fclose(fileid);
    exit(0);
  }

  frewind(fileid);
  if (maxLineLength < 8.0) {
    maxLineLength = 8.0;
  }

  systemSectionHeaderFound = false;
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_char_T(&a, 2);
  emxInit_char_T(&r0, 2);
  exitg1 = false;
  while ((!exitg1) && (!systemSectionHeaderFound)) {
    getNextLine(fileid, maxLineLength, nextLineVar);
    b_NULL = NULL;
    filestar = fileManager(fileid);
    if (filestar == b_NULL) {
      i = 0;
    } else {
      st = feof(filestar);
      i = ((int)st != 0);
    }

    if (i != 0) {
      exitg1 = true;
    } else {
      b_char(nextLineVar, r0);
      deblank(r0, a);
      b_bool = false;
      if (a->size[1] == 8) {
        kstr = 0;
        do {
          exitg2 = 0;
          if (kstr < 8) {
            if (a->data[kstr] != cv0[kstr]) {
              exitg2 = 1;
            } else {
              kstr++;
            }
          } else {
            b_bool = true;
            exitg2 = 1;
          }
        } while (exitg2 == 0);
      }

      if (b_bool) {
        systemSectionHeaderFound = true;
      }
    }
  }

  emxInit_uint8_T(&type, 2);
  emxInit_uint8_T(&andMethod, 2);
  emxInit_uint8_T(&orMethod, 2);
  emxInit_uint8_T(&impMethod, 2);
  emxInit_uint8_T(&aggMethod, 2);
  emxInit_uint8_T(&defuzzMethod, 2);
  if (systemSectionHeaderFound) {
    findTopic(fileid, maxLineLength, nextLineVar);
    b_findTopic(fileid, maxLineLength, type);
    c_findTopic(fileid, maxLineLength, andMethod);
    d_findTopic(fileid, maxLineLength, orMethod);
    e_findTopic(fileid, maxLineLength, impMethod);
    f_findTopic(fileid, maxLineLength, aggMethod);
    g_findTopic(fileid, maxLineLength, defuzzMethod);
  } else {
    i = nextLineVar->size[0] * nextLineVar->size[1];
    nextLineVar->size[0] = 1;
    kstr = (int)maxLineLength;
    nextLineVar->size[1] = kstr;
    emxEnsureCapacity_uint8_T(nextLineVar, i);
    for (i = 0; i < kstr; i++) {
      nextLineVar->data[i] = 0U;
    }

    i = type->size[0] * type->size[1];
    type->size[0] = 1;
    type->size[1] = kstr;
    emxEnsureCapacity_uint8_T(type, i);
    for (i = 0; i < kstr; i++) {
      type->data[i] = 0U;
    }

    i = andMethod->size[0] * andMethod->size[1];
    andMethod->size[0] = 1;
    andMethod->size[1] = kstr;
    emxEnsureCapacity_uint8_T(andMethod, i);
    for (i = 0; i < kstr; i++) {
      andMethod->data[i] = 0U;
    }

    i = orMethod->size[0] * orMethod->size[1];
    orMethod->size[0] = 1;
    orMethod->size[1] = kstr;
    emxEnsureCapacity_uint8_T(orMethod, i);
    for (i = 0; i < kstr; i++) {
      orMethod->data[i] = 0U;
    }

    i = impMethod->size[0] * impMethod->size[1];
    impMethod->size[0] = 1;
    impMethod->size[1] = kstr;
    emxEnsureCapacity_uint8_T(impMethod, i);
    for (i = 0; i < kstr; i++) {
      impMethod->data[i] = 0U;
    }

    i = aggMethod->size[0] * aggMethod->size[1];
    aggMethod->size[0] = 1;
    aggMethod->size[1] = kstr;
    emxEnsureCapacity_uint8_T(aggMethod, i);
    for (i = 0; i < kstr; i++) {
      aggMethod->data[i] = 0U;
    }

    i = defuzzMethod->size[0] * defuzzMethod->size[1];
    defuzzMethod->size[0] = 1;
    defuzzMethod->size[1] = kstr;
    emxEnsureCapacity_uint8_T(defuzzMethod, i);
    for (i = 0; i < kstr; i++) {
      defuzzMethod->data[i] = 0U;
    }
  }

  frewind(fileid);
  getVarInfo(fileid, maxLineLength, &inputInfo_maxInputNameLength,
             &inputInfo_maxNumMF, &inputInfo_maxMFNameLength,
             &inputInfo_maxMFTypeLength, &inputInfo_maxMFParamLength,
             &inputInfo_numVars, &b_bool);
  frewind(fileid);
  if ((!systemSectionHeaderFound) || (!any(type))) {
    b_bool = true;
  } else {
    b_bool = false;
  }

  b_getVarInfo(fileid, maxLineLength, b_bool, &outputInfo_maxInputNameLength,
               &outputInfo_maxNumMF, &outputInfo_maxMFNameLength,
               &outputInfo_maxMFTypeLength, &outputInfo_maxMFParamLength,
               &outputInfo_numVars, &systemSectionHeaderFound);
  frewind(fileid);
  if (b_bool) {
    if (systemSectionHeaderFound) {
      for (i = 0; i < 6; i++) {
        type->data[i] = uv1[i];
      }
    } else {
      for (i = 0; i < 7; i++) {
        type->data[i] = uv0[i];
      }
    }
  } else {
    b_char(type, r0);
    deblank(r0, a);
    systemSectionHeaderFound = false;
    if (a->size[1] == 6) {
      kstr = 0;
      do {
        exitg2 = 0;
        if (kstr < 6) {
          if (a->data[kstr] != cv1[kstr]) {
            exitg2 = 1;
          } else {
            kstr++;
          }
        } else {
          systemSectionHeaderFound = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }
  }

  emxFree_char_T(&r0);
  emxFree_char_T(&a);
  getVar(fileid, maxLineLength, inputInfo_maxInputNameLength, inputInfo_maxNumMF,
         inputInfo_maxMFNameLength, inputInfo_maxMFTypeLength,
         inputInfo_maxMFParamLength, inputInfo_numVars, fis_input);
  b_getVar(fileid, maxLineLength, outputInfo_maxInputNameLength,
           outputInfo_maxNumMF, outputInfo_maxMFNameLength,
           outputInfo_maxMFTypeLength, outputInfo_maxMFParamLength,
           outputInfo_numVars, systemSectionHeaderFound, fis_output);
  getRules(fileid, maxLineLength, inputInfo_numVars, outputInfo_numVars,
           fis_rule);
  if (!any(nextLineVar)) {
    for (i = 0; i < 8; i++) {
      nextLineVar->data[i] = uv2[i];
    }
  }

  if (systemSectionHeaderFound) {
    i = impMethod->size[0] * impMethod->size[1];
    impMethod->size[0] = 1;
    emxEnsureCapacity_uint8_T(impMethod, i);
    kstr = impMethod->size[1];
    for (i = 0; i < kstr; i++) {
      impMethod->data[i] = 0U;
    }

    impMethod->data[0] = 112U;
    impMethod->data[1] = 114U;
    impMethod->data[2] = 111U;
    impMethod->data[3] = 100U;
    i = aggMethod->size[0] * aggMethod->size[1];
    aggMethod->size[0] = 1;
    emxEnsureCapacity_uint8_T(aggMethod, i);
    kstr = aggMethod->size[1];
    for (i = 0; i < kstr; i++) {
      aggMethod->data[i] = 0U;
    }

    aggMethod->data[0] = 115U;
    aggMethod->data[1] = 117U;
    aggMethod->data[2] = 109U;
  }

  if (!any(andMethod)) {
    if (systemSectionHeaderFound) {
      andMethod->data[0] = 112U;
      andMethod->data[1] = 114U;
      andMethod->data[2] = 111U;
      andMethod->data[3] = 100U;
    } else {
      andMethod->data[0] = 109U;
      andMethod->data[1] = 105U;
      andMethod->data[2] = 110U;
    }
  }

  if (!any(orMethod)) {
    if (systemSectionHeaderFound) {
      for (i = 0; i < 6; i++) {
        orMethod->data[i] = uv3[i];
      }
    } else {
      orMethod->data[0] = 109U;
      orMethod->data[1] = 97U;
      orMethod->data[2] = 120U;
    }
  }

  if ((!any(impMethod)) && (!systemSectionHeaderFound)) {
    impMethod->data[0] = 109U;
    impMethod->data[1] = 105U;
    impMethod->data[2] = 110U;
  }

  if ((!any(aggMethod)) && (!systemSectionHeaderFound)) {
    aggMethod->data[0] = 109U;
    aggMethod->data[1] = 97U;
    aggMethod->data[2] = 120U;
  }

  if (!any(defuzzMethod)) {
    if (systemSectionHeaderFound) {
      for (i = 0; i < 6; i++) {
        defuzzMethod->data[i] = uv5[i];
      }
    } else {
      for (i = 0; i < 8; i++) {
        defuzzMethod->data[i] = uv4[i];
      }
    }
  }

  end = nextLineVar->size[1] - 1;
  kstr = 0;
  for (i = 0; i <= end; i++) {
    if (nextLineVar->data[i] != 0) {
      kstr++;
    }
  }

  emxInit_int32_T(&r1, 2);
  i = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  r1->size[1] = kstr;
  emxEnsureCapacity_int32_T(r1, i);
  kstr = 0;
  for (i = 0; i <= end; i++) {
    if (nextLineVar->data[i] != 0) {
      r1->data[kstr] = i + 1;
      kstr++;
    }
  }

  emxInit_uint8_T(&b_nextLineVar, 2);
  i = b_nextLineVar->size[0] * b_nextLineVar->size[1];
  b_nextLineVar->size[0] = 1;
  b_nextLineVar->size[1] = r1->size[1];
  emxEnsureCapacity_uint8_T(b_nextLineVar, i);
  kstr = r1->size[0] * r1->size[1];
  for (i = 0; i < kstr; i++) {
    b_nextLineVar->data[i] = nextLineVar->data[r1->data[i] - 1];
  }

  emxFree_int32_T(&r1);
  b_char(b_nextLineVar, fis_name);
  end = type->size[1] - 1;
  kstr = 0;
  emxFree_uint8_T(&b_nextLineVar);
  for (i = 0; i <= end; i++) {
    if (type->data[i] != 0) {
      kstr++;
    }
  }

  emxInit_int32_T(&r2, 2);
  i = r2->size[0] * r2->size[1];
  r2->size[0] = 1;
  r2->size[1] = kstr;
  emxEnsureCapacity_int32_T(r2, i);
  kstr = 0;
  for (i = 0; i <= end; i++) {
    if (type->data[i] != 0) {
      r2->data[kstr] = i + 1;
      kstr++;
    }
  }

  i = nextLineVar->size[0] * nextLineVar->size[1];
  nextLineVar->size[0] = 1;
  nextLineVar->size[1] = r2->size[1];
  emxEnsureCapacity_uint8_T(nextLineVar, i);
  kstr = r2->size[0] * r2->size[1];
  for (i = 0; i < kstr; i++) {
    nextLineVar->data[i] = type->data[r2->data[i] - 1];
  }

  emxFree_int32_T(&r2);
  emxFree_uint8_T(&type);
  b_char(nextLineVar, fis_type);
  end = andMethod->size[1] - 1;
  kstr = 0;
  for (i = 0; i <= end; i++) {
    if (andMethod->data[i] != 0) {
      kstr++;
    }
  }

  emxInit_int32_T(&r3, 2);
  i = r3->size[0] * r3->size[1];
  r3->size[0] = 1;
  r3->size[1] = kstr;
  emxEnsureCapacity_int32_T(r3, i);
  kstr = 0;
  for (i = 0; i <= end; i++) {
    if (andMethod->data[i] != 0) {
      r3->data[kstr] = i + 1;
      kstr++;
    }
  }

  i = nextLineVar->size[0] * nextLineVar->size[1];
  nextLineVar->size[0] = 1;
  nextLineVar->size[1] = r3->size[1];
  emxEnsureCapacity_uint8_T(nextLineVar, i);
  kstr = r3->size[0] * r3->size[1];
  for (i = 0; i < kstr; i++) {
    nextLineVar->data[i] = andMethod->data[r3->data[i] - 1];
  }

  emxFree_int32_T(&r3);
  emxFree_uint8_T(&andMethod);
  b_char(nextLineVar, fis_andMethod);
  end = orMethod->size[1] - 1;
  kstr = 0;
  for (i = 0; i <= end; i++) {
    if (orMethod->data[i] != 0) {
      kstr++;
    }
  }

  emxInit_int32_T(&r4, 2);
  i = r4->size[0] * r4->size[1];
  r4->size[0] = 1;
  r4->size[1] = kstr;
  emxEnsureCapacity_int32_T(r4, i);
  kstr = 0;
  for (i = 0; i <= end; i++) {
    if (orMethod->data[i] != 0) {
      r4->data[kstr] = i + 1;
      kstr++;
    }
  }

  i = nextLineVar->size[0] * nextLineVar->size[1];
  nextLineVar->size[0] = 1;
  nextLineVar->size[1] = r4->size[1];
  emxEnsureCapacity_uint8_T(nextLineVar, i);
  kstr = r4->size[0] * r4->size[1];
  for (i = 0; i < kstr; i++) {
    nextLineVar->data[i] = orMethod->data[r4->data[i] - 1];
  }

  emxFree_int32_T(&r4);
  emxFree_uint8_T(&orMethod);
  b_char(nextLineVar, fis_orMethod);
  end = defuzzMethod->size[1] - 1;
  kstr = 0;
  for (i = 0; i <= end; i++) {
    if (defuzzMethod->data[i] != 0) {
      kstr++;
    }
  }

  emxInit_int32_T(&r5, 2);
  i = r5->size[0] * r5->size[1];
  r5->size[0] = 1;
  r5->size[1] = kstr;
  emxEnsureCapacity_int32_T(r5, i);
  kstr = 0;
  for (i = 0; i <= end; i++) {
    if (defuzzMethod->data[i] != 0) {
      r5->data[kstr] = i + 1;
      kstr++;
    }
  }

  i = nextLineVar->size[0] * nextLineVar->size[1];
  nextLineVar->size[0] = 1;
  nextLineVar->size[1] = r5->size[1];
  emxEnsureCapacity_uint8_T(nextLineVar, i);
  kstr = r5->size[0] * r5->size[1];
  for (i = 0; i < kstr; i++) {
    nextLineVar->data[i] = defuzzMethod->data[r5->data[i] - 1];
  }

  emxFree_int32_T(&r5);
  emxFree_uint8_T(&defuzzMethod);
  b_char(nextLineVar, fis_defuzzMethod);
  end = impMethod->size[1] - 1;
  kstr = 0;
  for (i = 0; i <= end; i++) {
    if (impMethod->data[i] != 0) {
      kstr++;
    }
  }

  emxInit_int32_T(&r6, 2);
  i = r6->size[0] * r6->size[1];
  r6->size[0] = 1;
  r6->size[1] = kstr;
  emxEnsureCapacity_int32_T(r6, i);
  kstr = 0;
  for (i = 0; i <= end; i++) {
    if (impMethod->data[i] != 0) {
      r6->data[kstr] = i + 1;
      kstr++;
    }
  }

  i = nextLineVar->size[0] * nextLineVar->size[1];
  nextLineVar->size[0] = 1;
  nextLineVar->size[1] = r6->size[1];
  emxEnsureCapacity_uint8_T(nextLineVar, i);
  kstr = r6->size[0] * r6->size[1];
  for (i = 0; i < kstr; i++) {
    nextLineVar->data[i] = impMethod->data[r6->data[i] - 1];
  }

  emxFree_int32_T(&r6);
  emxFree_uint8_T(&impMethod);
  b_char(nextLineVar, fis_impMethod);
  end = aggMethod->size[1] - 1;
  kstr = 0;
  for (i = 0; i <= end; i++) {
    if (aggMethod->data[i] != 0) {
      kstr++;
    }
  }

  emxInit_int32_T(&r7, 2);
  i = r7->size[0] * r7->size[1];
  r7->size[0] = 1;
  r7->size[1] = kstr;
  emxEnsureCapacity_int32_T(r7, i);
  kstr = 0;
  for (i = 0; i <= end; i++) {
    if (aggMethod->data[i] != 0) {
      r7->data[kstr] = i + 1;
      kstr++;
    }
  }

  i = nextLineVar->size[0] * nextLineVar->size[1];
  nextLineVar->size[0] = 1;
  nextLineVar->size[1] = r7->size[1];
  emxEnsureCapacity_uint8_T(nextLineVar, i);
  kstr = r7->size[0] * r7->size[1];
  for (i = 0; i < kstr; i++) {
    nextLineVar->data[i] = aggMethod->data[r7->data[i] - 1];
  }

  emxFree_int32_T(&r7);
  emxFree_uint8_T(&aggMethod);
  b_char(nextLineVar, fis_aggMethod);
  b_fclose(fileid);
  emxFree_uint8_T(&nextLineVar);
}

/*
 * File trailer for getFISCodeGenerationData.c
 *
 * [EOF]
 */
