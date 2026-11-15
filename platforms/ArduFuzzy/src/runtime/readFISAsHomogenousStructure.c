/*
 * File: readFISAsHomogenousStructure.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "readFISAsHomogenousStructure.h"
#include "fclose.h"
#include "deblank.h"
#include "fileManager.h"
#include "find.h"
#include "findTopic.h"
#include "getNextLine.h"
#include "opkene_data.h"
#include "opkene_emxutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include <stdio.h>

/* Function Definitions */
/*
 * Arguments    : double fid
 *                double maxLineLength
 *                double info_maxInputNameLength
 *                double info_maxNumMF
 *                double info_maxMFNameLength
 *                double info_maxMFTypeLength
 *                double info_maxMFParamLength
 *                double info_numVars
 *                boolean_T updateOutputRange
 *                b_emxArray_struct_T *var
 * Return Type  : void
 */
void b_getVar(double fid, double maxLineLength, double info_maxInputNameLength,
              double info_maxNumMF, double info_maxMFNameLength,
              double info_maxMFTypeLength, double info_maxMFParamLength,
              double info_numVars, boolean_T updateOutputRange,
              b_emxArray_struct_T *var)
{
  static const unsigned char uv[7] = {91U, 79U, 117U, 116U, 112U, 117U, 116U};
  FILE *filestar;
  b_struct_T varTemplate;
  b_struct_T *var_data;
  emxArray_boolean_T *bufferEqual;
  emxArray_char_T *b_nextLineVar;
  emxArray_char_T *r;
  emxArray_int32_T *ids;
  emxArray_uint8_T *mfInfo2;
  emxArray_uint8_T *mfInfo3;
  emxArray_uint8_T *nextLineVar;
  emxArray_uint8_T *template;
  struct_T mfTemplate;
  int b_i;
  int b_loop_ub;
  int c_loop_ub;
  int i;
  int i1;
  int i2;
  int idR_data;
  int j;
  int k;
  int loop_ub;
  int loop_ub_tmp;
  int *ids_data;
  char *b_nextLineVar_data;
  unsigned char *mfInfo2_data;
  unsigned char *mfInfo3_data;
  unsigned char *nextLineVar_data;
  unsigned char *template_data;
  boolean_T *bufferEqual_data;
  emxInitStruct_struct_T1(&mfTemplate);
  i = mfTemplate.name->size[0] * mfTemplate.name->size[1];
  mfTemplate.name->size[0] = 1;
  loop_ub_tmp = (int)info_maxMFNameLength;
  mfTemplate.name->size[1] = (int)info_maxMFNameLength;
  emxEnsureCapacity_char_T(mfTemplate.name, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    mfTemplate.name->data[i] = '\x00';
  }
  mfTemplate.origNameLength = 0.0;
  i = mfTemplate.type->size[0] * mfTemplate.type->size[1];
  mfTemplate.type->size[0] = 1;
  loop_ub_tmp = (int)info_maxMFTypeLength;
  mfTemplate.type->size[1] = (int)info_maxMFTypeLength;
  emxEnsureCapacity_char_T(mfTemplate.type, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    mfTemplate.type->data[i] = '\x00';
  }
  mfTemplate.origTypeLength = 0.0;
  i = mfTemplate.params->size[0] * mfTemplate.params->size[1];
  mfTemplate.params->size[0] = 1;
  loop_ub_tmp = (int)info_maxMFParamLength;
  mfTemplate.params->size[1] = (int)info_maxMFParamLength;
  emxEnsureCapacity_real_T(mfTemplate.params, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    mfTemplate.params->data[i] = 0.0;
  }
  mfTemplate.origParamLength = 0.0;
  emxInitStruct_struct_T2(&varTemplate);
  i = varTemplate.name->size[0] * varTemplate.name->size[1];
  varTemplate.name->size[0] = 1;
  loop_ub_tmp = (int)info_maxInputNameLength;
  varTemplate.name->size[1] = (int)info_maxInputNameLength;
  emxEnsureCapacity_char_T(varTemplate.name, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    varTemplate.name->data[i] = '\x00';
  }
  varTemplate.origNameLength = 0.0;
  varTemplate.range[0] = 0.0;
  varTemplate.range[1] = 0.0;
  i = varTemplate.mf->size[0] * varTemplate.mf->size[1];
  varTemplate.mf->size[0] = 1;
  loop_ub_tmp = (int)info_maxNumMF;
  varTemplate.mf->size[1] = (int)info_maxNumMF;
  emxEnsureCapacity_struct_T(varTemplate.mf, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    emxCopyStruct_struct_T(&varTemplate.mf->data[i], &mfTemplate);
  }
  emxFreeStruct_struct_T1(&mfTemplate);
  varTemplate.origNumMF = 0.0;
  i = var->size[0] * var->size[1];
  var->size[0] = 1;
  loop_ub_tmp = (int)info_numVars;
  var->size[1] = (int)info_numVars;
  emxEnsureCapacity_struct_T1(var, i);
  var_data = var->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    emxCopyStruct_struct_T1(&var_data[i], &varTemplate);
  }
  emxFreeStruct_struct_T(&varTemplate);
  emxInit_uint8_T(&template, 2);
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual);
  emxInit_uint8_T(&mfInfo2, 2);
  emxInit_uint8_T(&mfInfo3, 2);
  emxInit_int32_T(&ids);
  emxInit_char_T(&b_nextLineVar, 2);
  emxInit_char_T(&r, 2);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    int b_loop_ub_tmp;
    boolean_T exitg1;
    boolean_T topicFound;
    i = template->size[0] * template->size[1];
    template->size[0] = 1;
    b_loop_ub_tmp = (int)maxLineLength;
    template->size[1] = (int)maxLineLength;
    emxEnsureCapacity_uint8_T(template, i);
    template_data = template->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      template_data[i] = 0U;
    }
    for (i = 0; i < 7; i++) {
      template_data[i] = uv[i];
    }
    topicFound = false;
    exitg1 = false;
    while ((!exitg1) && (!topicFound)) {
      getNextLine(fid, maxLineLength, nextLineVar);
      nextLineVar_data = nextLineVar->data;
      filestar = fileManager(fid);
      if (filestar == NULL) {
        i = 0;
      } else {
        int st;
        st = feof(filestar);
        i = ((int)st != 0);
      }
      if (i != 0) {
        exitg1 = true;
      } else {
        boolean_T exitg2;
        boolean_T y;
        i = bufferEqual->size[0] * bufferEqual->size[1];
        bufferEqual->size[0] = 1;
        bufferEqual->size[1] = nextLineVar->size[1];
        emxEnsureCapacity_boolean_T(bufferEqual, i);
        bufferEqual_data = bufferEqual->data;
        loop_ub = nextLineVar->size[1];
        for (i = 0; i < loop_ub; i++) {
          bufferEqual_data[i] = (nextLineVar_data[i] == template_data[i]);
        }
        y = true;
        k = 0;
        exitg2 = false;
        while ((!exitg2) && (k <= 6)) {
          if (!bufferEqual_data[k]) {
            y = false;
            exitg2 = true;
          } else {
            k++;
          }
        }
        if (y) {
          creal_T x;
          int idR_size[2];
          topicFound = true;
          findTopic(fid, maxLineLength, nextLineVar);
          nextLineVar_data = nextLineVar->data;
          if (info_maxInputNameLength < 1.0) {
            loop_ub = 0;
          } else {
            loop_ub = (int)info_maxInputNameLength;
          }
          for (i = 0; i < loop_ub; i++) {
            var_data[b_i].name->data[i] = (signed char)nextLineVar_data[i];
          }
          deblank(var_data[b_i].name, r);
          var_data[b_i].origNameLength = r->size[1];
          j_findTopic(fid, maxLineLength, nextLineVar);
          nextLineVar_data = nextLineVar->data;
          i = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i);
          bufferEqual_data = bufferEqual->data;
          loop_ub = nextLineVar->size[1];
          for (i = 0; i < loop_ub; i++) {
            bufferEqual_data[i] = (nextLineVar_data[i] == 32);
          }
          eml_find(bufferEqual, (int *)&idR_data, idR_size);
          if ((double)idR_data - 1.0 < 1.0) {
            loop_ub = 0;
          } else {
            loop_ub = idR_data - 1;
          }
          i = b_nextLineVar->size[0] * b_nextLineVar->size[1];
          b_nextLineVar->size[0] = 1;
          b_nextLineVar->size[1] = loop_ub;
          emxEnsureCapacity_char_T(b_nextLineVar, i);
          b_nextLineVar_data = b_nextLineVar->data;
          for (i = 0; i < loop_ub; i++) {
            b_nextLineVar_data[i] = (signed char)nextLineVar_data[i];
          }
          deblank(b_nextLineVar, r);
          x = str2double(r);
          var_data[b_i].range[0] = x.re;
          if ((double)idR_data + 1.0 > nextLineVar->size[1]) {
            i = -1;
            i1 = -1;
          } else {
            i = idR_data - 1;
            i1 = nextLineVar->size[1] - 1;
          }
          idR_data = i1 - i;
          i1 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
          b_nextLineVar->size[0] = 1;
          b_nextLineVar->size[1] = idR_data;
          emxEnsureCapacity_char_T(b_nextLineVar, i1);
          b_nextLineVar_data = b_nextLineVar->data;
          for (i1 = 0; i1 < idR_data; i1++) {
            b_nextLineVar_data[i1] =
                (signed char)nextLineVar_data[(i + i1) + 1];
          }
          deblank(b_nextLineVar, r);
          x = str2double(r);
          var_data[b_i].range[1] = x.re;
          if (updateOutputRange &&
              (var_data[b_i].range[1] <= var_data[b_i].range[0])) {
            var_data[b_i].range[1] = var_data[b_i].range[0] + 1.0;
          }
          h_findTopic(fid, maxLineLength, nextLineVar);
          nextLineVar_data = nextLineVar->data;
          i = b_nextLineVar->size[0] * b_nextLineVar->size[1];
          b_nextLineVar->size[0] = 1;
          b_nextLineVar->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_char_T(b_nextLineVar, i);
          b_nextLineVar_data = b_nextLineVar->data;
          loop_ub = nextLineVar->size[1];
          for (i = 0; i < loop_ub; i++) {
            b_nextLineVar_data[i] = (signed char)nextLineVar_data[i];
          }
          deblank(b_nextLineVar, r);
          x = str2double(r);
          var_data[b_i].origNumMF = x.re;
          i = (int)x.re;
          if (i - 1 >= 0) {
            if (info_maxMFNameLength < 1.0) {
              b_loop_ub = 0;
            } else {
              b_loop_ub = (int)info_maxMFNameLength;
            }
            if (info_maxMFTypeLength < 1.0) {
              c_loop_ub = 0;
            } else {
              c_loop_ub = (int)info_maxMFTypeLength;
            }
          }
          for (j = 0; j < i; j++) {
            double startIndex;
            i_findTopic(fid, maxLineLength, nextLineVar);
            nextLineVar_data = nextLineVar->data;
            i1 = mfInfo2->size[0] * mfInfo2->size[1];
            mfInfo2->size[0] = 1;
            mfInfo2->size[1] = (int)maxLineLength;
            emxEnsureCapacity_uint8_T(mfInfo2, i1);
            mfInfo2_data = mfInfo2->data;
            for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
              mfInfo2_data[i1] = 0U;
            }
            loop_ub = nextLineVar->size[1];
            for (i1 = 0; i1 <= loop_ub - 3; i1++) {
              mfInfo2_data[i1] = nextLineVar_data[i1 + 2];
            }
            i1 = bufferEqual->size[0] * bufferEqual->size[1];
            bufferEqual->size[0] = 1;
            bufferEqual->size[1] = mfInfo2->size[1];
            emxEnsureCapacity_boolean_T(bufferEqual, i1);
            bufferEqual_data = bufferEqual->data;
            loop_ub = mfInfo2->size[1];
            for (i1 = 0; i1 < loop_ub; i1++) {
              bufferEqual_data[i1] = (mfInfo2_data[i1] == 39);
            }
            eml_find(bufferEqual, (int *)&idR_data, idR_size);
            i1 = nextLineVar->size[0] * nextLineVar->size[1];
            nextLineVar->size[0] = 1;
            nextLineVar->size[1] = (int)maxLineLength;
            emxEnsureCapacity_uint8_T(nextLineVar, i1);
            nextLineVar_data = nextLineVar->data;
            for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
              nextLineVar_data[i1] = 0U;
            }
            if ((double)idR_data - 1.0 < 1.0) {
              loop_ub = 0;
            } else {
              loop_ub = idR_data - 1;
            }
            for (i1 = 0; i1 < loop_ub; i1++) {
              nextLineVar_data[i1] = mfInfo2_data[i1];
            }
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              var_data[b_i].mf->data[j].name->data[i1] =
                  (signed char)nextLineVar_data[i1];
            }
            deblank(var_data[b_i].mf->data[j].name, r);
            var_data[b_i].mf->data[j].origNameLength = r->size[1];
            i1 = mfInfo3->size[0] * mfInfo3->size[1];
            mfInfo3->size[0] = 1;
            mfInfo3->size[1] = (int)maxLineLength;
            emxEnsureCapacity_uint8_T(mfInfo3, i1);
            mfInfo3_data = mfInfo3->data;
            for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
              mfInfo3_data[i1] = 0U;
            }
            if ((double)idR_data + 3.0 > mfInfo2->size[1]) {
              i1 = 0;
              i2 = 0;
            } else {
              i1 = idR_data + 2;
              i2 = mfInfo2->size[1];
            }
            loop_ub = i2 - i1;
            for (i2 = 0; i2 < loop_ub; i2++) {
              mfInfo3_data[i2] = mfInfo2_data[i1 + i2];
            }
            i1 = bufferEqual->size[0] * bufferEqual->size[1];
            bufferEqual->size[0] = 1;
            bufferEqual->size[1] = mfInfo3->size[1];
            emxEnsureCapacity_boolean_T(bufferEqual, i1);
            bufferEqual_data = bufferEqual->data;
            loop_ub = mfInfo3->size[1];
            for (i1 = 0; i1 < loop_ub; i1++) {
              bufferEqual_data[i1] = (mfInfo3_data[i1] == 39);
            }
            eml_find(bufferEqual, (int *)&idR_data, idR_size);
            i1 = nextLineVar->size[0] * nextLineVar->size[1];
            nextLineVar->size[0] = 1;
            nextLineVar->size[1] = (int)maxLineLength;
            emxEnsureCapacity_uint8_T(nextLineVar, i1);
            nextLineVar_data = nextLineVar->data;
            for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
              nextLineVar_data[i1] = 0U;
            }
            if ((double)idR_data - 1.0 < 1.0) {
              loop_ub = 0;
            } else {
              loop_ub = idR_data - 1;
            }
            for (i1 = 0; i1 < loop_ub; i1++) {
              nextLineVar_data[i1] = mfInfo3_data[i1];
            }
            for (i1 = 0; i1 < c_loop_ub; i1++) {
              var_data[b_i].mf->data[j].type->data[i1] =
                  (signed char)nextLineVar_data[i1];
            }
            deblank(var_data[b_i].mf->data[j].type, r);
            var_data[b_i].mf->data[j].origTypeLength = r->size[1];
            i1 = nextLineVar->size[0] * nextLineVar->size[1];
            nextLineVar->size[0] = 1;
            nextLineVar->size[1] = (int)maxLineLength;
            emxEnsureCapacity_uint8_T(nextLineVar, i1);
            nextLineVar_data = nextLineVar->data;
            for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
              nextLineVar_data[i1] = 0U;
            }
            if ((double)idR_data + 3.0 > mfInfo3->size[1]) {
              i1 = 0;
              i2 = 0;
            } else {
              i1 = idR_data + 2;
              i2 = mfInfo3->size[1];
            }
            loop_ub = i2 - i1;
            for (i2 = 0; i2 < loop_ub; i2++) {
              nextLineVar_data[i2] = mfInfo3_data[i1 + i2];
            }
            i1 = bufferEqual->size[0] * bufferEqual->size[1];
            bufferEqual->size[0] = 1;
            bufferEqual->size[1] = nextLineVar->size[1];
            emxEnsureCapacity_boolean_T(bufferEqual, i1);
            bufferEqual_data = bufferEqual->data;
            loop_ub = nextLineVar->size[1];
            for (i1 = 0; i1 < loop_ub; i1++) {
              bufferEqual_data[i1] = (nextLineVar_data[i1] == 32);
            }
            b_eml_find(bufferEqual, ids);
            ids_data = ids->data;
            startIndex = 1.0;
            i1 = ids->size[1];
            for (k = 0; k <= i1; k++) {
              double endIndex;
              if ((unsigned int)k == (unsigned int)ids->size[1]) {
                i2 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
                b_nextLineVar->size[0] = 1;
                b_nextLineVar->size[1] = nextLineVar->size[1];
                emxEnsureCapacity_char_T(b_nextLineVar, i2);
                b_nextLineVar_data = b_nextLineVar->data;
                loop_ub = nextLineVar->size[1];
                for (i2 = 0; i2 < loop_ub; i2++) {
                  b_nextLineVar_data[i2] = (signed char)nextLineVar_data[i2];
                }
                deblank(b_nextLineVar, r);
                endIndex = r->size[1];
              } else {
                endIndex = (double)ids_data[k] - 1.0;
              }
              if (startIndex > endIndex) {
                i2 = -1;
                loop_ub = -1;
              } else {
                i2 = (int)startIndex - 2;
                loop_ub = (int)endIndex - 1;
              }
              idR_data = loop_ub - i2;
              loop_ub = b_nextLineVar->size[0] * b_nextLineVar->size[1];
              b_nextLineVar->size[0] = 1;
              b_nextLineVar->size[1] = idR_data;
              emxEnsureCapacity_char_T(b_nextLineVar, loop_ub);
              b_nextLineVar_data = b_nextLineVar->data;
              for (loop_ub = 0; loop_ub < idR_data; loop_ub++) {
                b_nextLineVar_data[loop_ub] =
                    (signed char)nextLineVar_data[(i2 + loop_ub) + 1];
              }
              x = str2double(b_nextLineVar);
              var_data[b_i].mf->data[j].params->data[k] = x.re;
              startIndex = endIndex + 2.0;
            }
            var_data[b_i].mf->data[j].origParamLength =
                (double)ids->size[1] + 1.0;
          }
        }
      }
    }
  }
  emxFree_char_T(&r);
  emxFree_char_T(&b_nextLineVar);
  emxFree_int32_T(&ids);
  emxFree_uint8_T(&mfInfo3);
  emxFree_uint8_T(&mfInfo2);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&template);
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                boolean_T checkForSugenoMFs
 *                double *info_maxNumMF
 *                double *info_maxMFNameLength
 *                double *info_maxMFTypeLength
 *                double *info_maxMFParamLength
 *                double *info_numVars
 *                boolean_T *info_hasSugenoMFs
 * Return Type  : double
 */
double b_getVarInfo(double fid, double maxLineLength,
                    boolean_T checkForSugenoMFs, double *info_maxNumMF,
                    double *info_maxMFNameLength, double *info_maxMFTypeLength,
                    double *info_maxMFParamLength, double *info_numVars,
                    boolean_T *info_hasSugenoMFs)
{
  static const char cv[8] = {'c', 'o', 'n', 's', 't', 'a', 'n', 't'};
  static const unsigned char uv[7] = {91U, 79U, 117U, 116U, 112U, 117U, 116U};
  static const char cv1[6] = {'l', 'i', 'n', 'e', 'a', 'r'};
  FILE *filestar;
  emxArray_boolean_T *bufferEqual;
  emxArray_char_T *a;
  emxArray_char_T *b_nextLineVar;
  emxArray_int32_T *r;
  emxArray_uint8_T *mfInfo2;
  emxArray_uint8_T *mfInfo3;
  emxArray_uint8_T *nextLineVar;
  emxArray_uint8_T *template;
  double info_maxInputNameLength;
  int i;
  int i1;
  int id_data;
  int j;
  int loop_ub_tmp;
  int maxInputNameLength;
  int maxMFNameLength;
  unsigned int maxMFParamLength;
  int maxMFTypeLength;
  char *b_nextLineVar_data;
  unsigned char *mfInfo2_data;
  unsigned char *mfInfo3_data;
  unsigned char *nextLineVar_data;
  unsigned char *template_data;
  boolean_T *bufferEqual_data;
  *info_numVars = 0.0;
  maxInputNameLength = 0;
  *info_maxNumMF = 0.0;
  maxMFNameLength = 0;
  maxMFTypeLength = 0;
  maxMFParamLength = 0U;
  *info_hasSugenoMFs = false;
  emxInit_uint8_T(&template, 2);
  i = template->size[0] * template->size[1];
  template->size[0] = 1;
  loop_ub_tmp = (int)maxLineLength;
  template->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(template, i);
  template_data = template->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    template_data[i] = 0U;
  }
  for (i = 0; i < 7; i++) {
    template_data[i] = uv[i];
  }
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual);
  emxInit_uint8_T(&mfInfo2, 2);
  emxInit_uint8_T(&mfInfo3, 2);
  emxInit_char_T(&a, 2);
  emxInit_int32_T(&r);
  emxInit_char_T(&b_nextLineVar, 2);
  int exitg1;
  do {
    exitg1 = 0;
    filestar = fileManager(fid);
    if (filestar == NULL) {
      i = 0;
    } else {
      int st;
      st = feof(filestar);
      i = ((int)st != 0);
    }
    if (i == 0) {
      int loop_ub;
      boolean_T exitg2;
      boolean_T y;
      getNextLine(fid, maxLineLength, nextLineVar);
      nextLineVar_data = nextLineVar->data;
      i = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i);
      bufferEqual_data = bufferEqual->data;
      loop_ub = nextLineVar->size[1];
      for (i = 0; i < loop_ub; i++) {
        bufferEqual_data[i] = (nextLineVar_data[i] == template_data[i]);
      }
      y = true;
      loop_ub = 0;
      exitg2 = false;
      while ((!exitg2) && (loop_ub <= 6)) {
        if (!bufferEqual_data[loop_ub]) {
          y = false;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }
      if (y) {
        creal_T x;
        (*info_numVars)++;
        findTopic(fid, maxLineLength, nextLineVar);
        nextLineVar_data = nextLineVar->data;
        i = b_nextLineVar->size[0] * b_nextLineVar->size[1];
        b_nextLineVar->size[0] = 1;
        b_nextLineVar->size[1] = nextLineVar->size[1];
        emxEnsureCapacity_char_T(b_nextLineVar, i);
        b_nextLineVar_data = b_nextLineVar->data;
        loop_ub = nextLineVar->size[1];
        for (i = 0; i < loop_ub; i++) {
          b_nextLineVar_data[i] = (signed char)nextLineVar_data[i];
        }
        deblank(b_nextLineVar, a);
        if (a->size[1] > maxInputNameLength) {
          maxInputNameLength = a->size[1];
        }
        h_findTopic(fid, maxLineLength, nextLineVar);
        nextLineVar_data = nextLineVar->data;
        i = b_nextLineVar->size[0] * b_nextLineVar->size[1];
        b_nextLineVar->size[0] = 1;
        b_nextLineVar->size[1] = nextLineVar->size[1];
        emxEnsureCapacity_char_T(b_nextLineVar, i);
        b_nextLineVar_data = b_nextLineVar->data;
        loop_ub = nextLineVar->size[1];
        for (i = 0; i < loop_ub; i++) {
          b_nextLineVar_data[i] = (signed char)nextLineVar_data[i];
        }
        deblank(b_nextLineVar, a);
        x = str2double(a);
        if (x.re > *info_maxNumMF) {
          *info_maxNumMF = x.re;
        }
        i = (int)x.re;
        for (j = 0; j < i; j++) {
          int id_size[2];
          i_findTopic(fid, maxLineLength, nextLineVar);
          nextLineVar_data = nextLineVar->data;
          i1 = mfInfo2->size[0] * mfInfo2->size[1];
          mfInfo2->size[0] = 1;
          mfInfo2->size[1] = (int)maxLineLength;
          emxEnsureCapacity_uint8_T(mfInfo2, i1);
          mfInfo2_data = mfInfo2->data;
          for (i1 = 0; i1 < loop_ub_tmp; i1++) {
            mfInfo2_data[i1] = 0U;
          }
          loop_ub = nextLineVar->size[1];
          for (i1 = 0; i1 <= loop_ub - 3; i1++) {
            mfInfo2_data[i1] = nextLineVar_data[i1 + 2];
          }
          i1 = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = mfInfo2->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i1);
          bufferEqual_data = bufferEqual->data;
          loop_ub = mfInfo2->size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            bufferEqual_data[i1] = (mfInfo2_data[i1] == 39);
          }
          eml_find(bufferEqual, (int *)&id_data, id_size);
          i1 = nextLineVar->size[0] * nextLineVar->size[1];
          nextLineVar->size[0] = 1;
          nextLineVar->size[1] = (int)maxLineLength;
          emxEnsureCapacity_uint8_T(nextLineVar, i1);
          nextLineVar_data = nextLineVar->data;
          for (i1 = 0; i1 < loop_ub_tmp; i1++) {
            nextLineVar_data[i1] = 0U;
          }
          if ((double)id_data - 1.0 < 1.0) {
            loop_ub = 0;
          } else {
            loop_ub = id_data - 1;
          }
          for (i1 = 0; i1 < loop_ub; i1++) {
            nextLineVar_data[i1] = mfInfo2_data[i1];
          }
          i1 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
          b_nextLineVar->size[0] = 1;
          b_nextLineVar->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_char_T(b_nextLineVar, i1);
          b_nextLineVar_data = b_nextLineVar->data;
          loop_ub = nextLineVar->size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_nextLineVar_data[i1] = (signed char)nextLineVar_data[i1];
          }
          deblank(b_nextLineVar, a);
          if (a->size[1] > maxMFNameLength) {
            maxMFNameLength = a->size[1];
          }
          i1 = mfInfo3->size[0] * mfInfo3->size[1];
          mfInfo3->size[0] = 1;
          mfInfo3->size[1] = (int)maxLineLength;
          emxEnsureCapacity_uint8_T(mfInfo3, i1);
          mfInfo3_data = mfInfo3->data;
          for (i1 = 0; i1 < loop_ub_tmp; i1++) {
            mfInfo3_data[i1] = 0U;
          }
          if ((double)id_data + 3.0 > mfInfo2->size[1]) {
            i1 = 0;
            id_data = 0;
          } else {
            i1 = id_data + 2;
            id_data = mfInfo2->size[1];
          }
          loop_ub = id_data - i1;
          for (id_data = 0; id_data < loop_ub; id_data++) {
            mfInfo3_data[id_data] = mfInfo2_data[i1 + id_data];
          }
          i1 = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = mfInfo3->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i1);
          bufferEqual_data = bufferEqual->data;
          loop_ub = mfInfo3->size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            bufferEqual_data[i1] = (mfInfo3_data[i1] == 39);
          }
          eml_find(bufferEqual, (int *)&id_data, id_size);
          i1 = nextLineVar->size[0] * nextLineVar->size[1];
          nextLineVar->size[0] = 1;
          nextLineVar->size[1] = (int)maxLineLength;
          emxEnsureCapacity_uint8_T(nextLineVar, i1);
          nextLineVar_data = nextLineVar->data;
          for (i1 = 0; i1 < loop_ub_tmp; i1++) {
            nextLineVar_data[i1] = 0U;
          }
          if ((double)id_data - 1.0 < 1.0) {
            loop_ub = 0;
          } else {
            loop_ub = id_data - 1;
          }
          for (i1 = 0; i1 < loop_ub; i1++) {
            nextLineVar_data[i1] = mfInfo3_data[i1];
          }
          i1 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
          b_nextLineVar->size[0] = 1;
          b_nextLineVar->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_char_T(b_nextLineVar, i1);
          b_nextLineVar_data = b_nextLineVar->data;
          loop_ub = nextLineVar->size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_nextLineVar_data[i1] = (signed char)nextLineVar_data[i1];
          }
          deblank(b_nextLineVar, a);
          if (a->size[1] > maxMFTypeLength) {
            maxMFTypeLength = a->size[1];
          }
          if (checkForSugenoMFs && (!*info_hasSugenoMFs)) {
            int exitg3;
            i1 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
            b_nextLineVar->size[0] = 1;
            b_nextLineVar->size[1] = nextLineVar->size[1];
            emxEnsureCapacity_char_T(b_nextLineVar, i1);
            b_nextLineVar_data = b_nextLineVar->data;
            loop_ub = nextLineVar->size[1];
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_nextLineVar_data[i1] = (signed char)nextLineVar_data[i1];
            }
            deblank(b_nextLineVar, a);
            b_nextLineVar_data = a->data;
            y = false;
            if (a->size[1] == 8) {
              loop_ub = 0;
              do {
                exitg3 = 0;
                if (loop_ub < 8) {
                  if (b_nextLineVar_data[loop_ub] != cv[loop_ub]) {
                    exitg3 = 1;
                  } else {
                    loop_ub++;
                  }
                } else {
                  y = true;
                  exitg3 = 1;
                }
              } while (exitg3 == 0);
            }
            if (y) {
              *info_hasSugenoMFs = true;
            } else {
              i1 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
              b_nextLineVar->size[0] = 1;
              b_nextLineVar->size[1] = nextLineVar->size[1];
              emxEnsureCapacity_char_T(b_nextLineVar, i1);
              b_nextLineVar_data = b_nextLineVar->data;
              loop_ub = nextLineVar->size[1];
              for (i1 = 0; i1 < loop_ub; i1++) {
                b_nextLineVar_data[i1] = (signed char)nextLineVar_data[i1];
              }
              deblank(b_nextLineVar, a);
              b_nextLineVar_data = a->data;
              y = false;
              if (a->size[1] == 6) {
                loop_ub = 0;
                do {
                  exitg3 = 0;
                  if (loop_ub < 6) {
                    if (b_nextLineVar_data[loop_ub] != cv1[loop_ub]) {
                      exitg3 = 1;
                    } else {
                      loop_ub++;
                    }
                  } else {
                    y = true;
                    exitg3 = 1;
                  }
                } while (exitg3 == 0);
              }
              if (y) {
                *info_hasSugenoMFs = true;
              }
            }
          }
          i1 = nextLineVar->size[0] * nextLineVar->size[1];
          nextLineVar->size[0] = 1;
          nextLineVar->size[1] = (int)maxLineLength;
          emxEnsureCapacity_uint8_T(nextLineVar, i1);
          nextLineVar_data = nextLineVar->data;
          for (i1 = 0; i1 < loop_ub_tmp; i1++) {
            nextLineVar_data[i1] = 0U;
          }
          if ((double)id_data + 3.0 > mfInfo3->size[1]) {
            i1 = 0;
            id_data = 0;
          } else {
            i1 = id_data + 2;
            id_data = mfInfo3->size[1];
          }
          loop_ub = id_data - i1;
          for (id_data = 0; id_data < loop_ub; id_data++) {
            nextLineVar_data[id_data] = mfInfo3_data[i1 + id_data];
          }
          i1 = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i1);
          bufferEqual_data = bufferEqual->data;
          loop_ub = nextLineVar->size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            bufferEqual_data[i1] = (nextLineVar_data[i1] == 44);
          }
          eml_find(bufferEqual, (int *)&loop_ub, id_size);
          if (id_size[1] != 0) {
            b_fclose(fid);
            exit(0);
          }
          i1 = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i1);
          bufferEqual_data = bufferEqual->data;
          loop_ub = nextLineVar->size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            bufferEqual_data[i1] = (nextLineVar_data[i1] == 32);
          }
          b_eml_find(bufferEqual, r);
          if ((unsigned int)r->size[1] + 1U > maxMFParamLength) {
            maxMFParamLength = (unsigned int)r->size[1] + 1U;
          }
        }
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emxFree_char_T(&b_nextLineVar);
  emxFree_int32_T(&r);
  emxFree_char_T(&a);
  emxFree_uint8_T(&mfInfo3);
  emxFree_uint8_T(&mfInfo2);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&template);
  info_maxInputNameLength = maxInputNameLength;
  *info_maxMFNameLength = maxMFNameLength;
  *info_maxMFTypeLength = maxMFTypeLength;
  *info_maxMFParamLength = maxMFParamLength;
  return info_maxInputNameLength;
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                double info_maxInputNameLength
 *                double info_maxNumMF
 *                double info_maxMFNameLength
 *                double info_maxMFTypeLength
 *                double info_maxMFParamLength
 *                double info_numVars
 *                b_emxArray_struct_T *var
 * Return Type  : void
 */
void getVar(double fid, double maxLineLength, double info_maxInputNameLength,
            double info_maxNumMF, double info_maxMFNameLength,
            double info_maxMFTypeLength, double info_maxMFParamLength,
            double info_numVars, b_emxArray_struct_T *var)
{
  static const unsigned char uv[6] = {91U, 73U, 110U, 112U, 117U, 116U};
  FILE *filestar;
  b_struct_T varTemplate;
  b_struct_T *var_data;
  emxArray_boolean_T *bufferEqual;
  emxArray_char_T *b_nextLineVar;
  emxArray_char_T *r;
  emxArray_int32_T *ids;
  emxArray_uint8_T *mfInfo2;
  emxArray_uint8_T *mfInfo3;
  emxArray_uint8_T *nextLineVar;
  emxArray_uint8_T *template;
  struct_T mfTemplate;
  int b_i;
  int b_loop_ub;
  int c_loop_ub;
  int i;
  int i1;
  int i2;
  int idR_data;
  int j;
  int k;
  int loop_ub;
  int loop_ub_tmp;
  int *ids_data;
  char *b_nextLineVar_data;
  unsigned char *mfInfo2_data;
  unsigned char *mfInfo3_data;
  unsigned char *nextLineVar_data;
  unsigned char *template_data;
  boolean_T *bufferEqual_data;
  emxInitStruct_struct_T1(&mfTemplate);
  i = mfTemplate.name->size[0] * mfTemplate.name->size[1];
  mfTemplate.name->size[0] = 1;
  loop_ub_tmp = (int)info_maxMFNameLength;
  mfTemplate.name->size[1] = (int)info_maxMFNameLength;
  emxEnsureCapacity_char_T(mfTemplate.name, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    mfTemplate.name->data[i] = '\x00';
  }
  mfTemplate.origNameLength = 0.0;
  i = mfTemplate.type->size[0] * mfTemplate.type->size[1];
  mfTemplate.type->size[0] = 1;
  loop_ub_tmp = (int)info_maxMFTypeLength;
  mfTemplate.type->size[1] = (int)info_maxMFTypeLength;
  emxEnsureCapacity_char_T(mfTemplate.type, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    mfTemplate.type->data[i] = '\x00';
  }
  mfTemplate.origTypeLength = 0.0;
  i = mfTemplate.params->size[0] * mfTemplate.params->size[1];
  mfTemplate.params->size[0] = 1;
  loop_ub_tmp = (int)info_maxMFParamLength;
  mfTemplate.params->size[1] = (int)info_maxMFParamLength;
  emxEnsureCapacity_real_T(mfTemplate.params, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    mfTemplate.params->data[i] = 0.0;
  }
  mfTemplate.origParamLength = 0.0;
  emxInitStruct_struct_T2(&varTemplate);
  i = varTemplate.name->size[0] * varTemplate.name->size[1];
  varTemplate.name->size[0] = 1;
  loop_ub_tmp = (int)info_maxInputNameLength;
  varTemplate.name->size[1] = (int)info_maxInputNameLength;
  emxEnsureCapacity_char_T(varTemplate.name, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    varTemplate.name->data[i] = '\x00';
  }
  varTemplate.origNameLength = 0.0;
  varTemplate.range[0] = 0.0;
  varTemplate.range[1] = 0.0;
  i = varTemplate.mf->size[0] * varTemplate.mf->size[1];
  varTemplate.mf->size[0] = 1;
  loop_ub_tmp = (int)info_maxNumMF;
  varTemplate.mf->size[1] = (int)info_maxNumMF;
  emxEnsureCapacity_struct_T(varTemplate.mf, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    emxCopyStruct_struct_T(&varTemplate.mf->data[i], &mfTemplate);
  }
  emxFreeStruct_struct_T1(&mfTemplate);
  varTemplate.origNumMF = 0.0;
  i = var->size[0] * var->size[1];
  var->size[0] = 1;
  loop_ub_tmp = (int)info_numVars;
  var->size[1] = (int)info_numVars;
  emxEnsureCapacity_struct_T1(var, i);
  var_data = var->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    emxCopyStruct_struct_T1(&var_data[i], &varTemplate);
  }
  emxFreeStruct_struct_T(&varTemplate);
  emxInit_uint8_T(&template, 2);
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual);
  emxInit_uint8_T(&mfInfo2, 2);
  emxInit_uint8_T(&mfInfo3, 2);
  emxInit_int32_T(&ids);
  emxInit_char_T(&b_nextLineVar, 2);
  emxInit_char_T(&r, 2);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    int b_loop_ub_tmp;
    boolean_T exitg1;
    boolean_T topicFound;
    i = template->size[0] * template->size[1];
    template->size[0] = 1;
    b_loop_ub_tmp = (int)maxLineLength;
    template->size[1] = (int)maxLineLength;
    emxEnsureCapacity_uint8_T(template, i);
    template_data = template->data;
    for (i = 0; i < b_loop_ub_tmp; i++) {
      template_data[i] = 0U;
    }
    for (i = 0; i < 6; i++) {
      template_data[i] = uv[i];
    }
    topicFound = false;
    exitg1 = false;
    while ((!exitg1) && (!topicFound)) {
      getNextLine(fid, maxLineLength, nextLineVar);
      nextLineVar_data = nextLineVar->data;
      filestar = fileManager(fid);
      if (filestar == NULL) {
        i = 0;
      } else {
        int st;
        st = feof(filestar);
        i = ((int)st != 0);
      }
      if (i != 0) {
        exitg1 = true;
      } else {
        boolean_T exitg2;
        boolean_T y;
        i = bufferEqual->size[0] * bufferEqual->size[1];
        bufferEqual->size[0] = 1;
        bufferEqual->size[1] = nextLineVar->size[1];
        emxEnsureCapacity_boolean_T(bufferEqual, i);
        bufferEqual_data = bufferEqual->data;
        loop_ub = nextLineVar->size[1];
        for (i = 0; i < loop_ub; i++) {
          bufferEqual_data[i] = (nextLineVar_data[i] == template_data[i]);
        }
        y = true;
        k = 0;
        exitg2 = false;
        while ((!exitg2) && (k <= 5)) {
          if (!bufferEqual_data[k]) {
            y = false;
            exitg2 = true;
          } else {
            k++;
          }
        }
        if (y) {
          creal_T x;
          int idR_size[2];
          topicFound = true;
          findTopic(fid, maxLineLength, nextLineVar);
          nextLineVar_data = nextLineVar->data;
          if (info_maxInputNameLength < 1.0) {
            loop_ub = 0;
          } else {
            loop_ub = (int)info_maxInputNameLength;
          }
          for (i = 0; i < loop_ub; i++) {
            var_data[b_i].name->data[i] = (signed char)nextLineVar_data[i];
          }
          deblank(var_data[b_i].name, r);
          var_data[b_i].origNameLength = r->size[1];
          j_findTopic(fid, maxLineLength, nextLineVar);
          nextLineVar_data = nextLineVar->data;
          i = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i);
          bufferEqual_data = bufferEqual->data;
          loop_ub = nextLineVar->size[1];
          for (i = 0; i < loop_ub; i++) {
            bufferEqual_data[i] = (nextLineVar_data[i] == 32);
          }
          eml_find(bufferEqual, (int *)&idR_data, idR_size);
          if ((double)idR_data - 1.0 < 1.0) {
            loop_ub = 0;
          } else {
            loop_ub = idR_data - 1;
          }
          i = b_nextLineVar->size[0] * b_nextLineVar->size[1];
          b_nextLineVar->size[0] = 1;
          b_nextLineVar->size[1] = loop_ub;
          emxEnsureCapacity_char_T(b_nextLineVar, i);
          b_nextLineVar_data = b_nextLineVar->data;
          for (i = 0; i < loop_ub; i++) {
            b_nextLineVar_data[i] = (signed char)nextLineVar_data[i];
          }
          deblank(b_nextLineVar, r);
          x = str2double(r);
          var_data[b_i].range[0] = x.re;
          if ((double)idR_data + 1.0 > nextLineVar->size[1]) {
            i = -1;
            i1 = -1;
          } else {
            i = idR_data - 1;
            i1 = nextLineVar->size[1] - 1;
          }
          idR_data = i1 - i;
          i1 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
          b_nextLineVar->size[0] = 1;
          b_nextLineVar->size[1] = idR_data;
          emxEnsureCapacity_char_T(b_nextLineVar, i1);
          b_nextLineVar_data = b_nextLineVar->data;
          for (i1 = 0; i1 < idR_data; i1++) {
            b_nextLineVar_data[i1] =
                (signed char)nextLineVar_data[(i + i1) + 1];
          }
          deblank(b_nextLineVar, r);
          x = str2double(r);
          var_data[b_i].range[1] = x.re;
          h_findTopic(fid, maxLineLength, nextLineVar);
          nextLineVar_data = nextLineVar->data;
          i = b_nextLineVar->size[0] * b_nextLineVar->size[1];
          b_nextLineVar->size[0] = 1;
          b_nextLineVar->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_char_T(b_nextLineVar, i);
          b_nextLineVar_data = b_nextLineVar->data;
          loop_ub = nextLineVar->size[1];
          for (i = 0; i < loop_ub; i++) {
            b_nextLineVar_data[i] = (signed char)nextLineVar_data[i];
          }
          deblank(b_nextLineVar, r);
          x = str2double(r);
          var_data[b_i].origNumMF = x.re;
          i = (int)x.re;
          if (i - 1 >= 0) {
            if (info_maxMFNameLength < 1.0) {
              b_loop_ub = 0;
            } else {
              b_loop_ub = (int)info_maxMFNameLength;
            }
            if (info_maxMFTypeLength < 1.0) {
              c_loop_ub = 0;
            } else {
              c_loop_ub = (int)info_maxMFTypeLength;
            }
          }
          for (j = 0; j < i; j++) {
            double startIndex;
            i_findTopic(fid, maxLineLength, nextLineVar);
            nextLineVar_data = nextLineVar->data;
            i1 = mfInfo2->size[0] * mfInfo2->size[1];
            mfInfo2->size[0] = 1;
            mfInfo2->size[1] = (int)maxLineLength;
            emxEnsureCapacity_uint8_T(mfInfo2, i1);
            mfInfo2_data = mfInfo2->data;
            for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
              mfInfo2_data[i1] = 0U;
            }
            loop_ub = nextLineVar->size[1];
            for (i1 = 0; i1 <= loop_ub - 3; i1++) {
              mfInfo2_data[i1] = nextLineVar_data[i1 + 2];
            }
            i1 = bufferEqual->size[0] * bufferEqual->size[1];
            bufferEqual->size[0] = 1;
            bufferEqual->size[1] = mfInfo2->size[1];
            emxEnsureCapacity_boolean_T(bufferEqual, i1);
            bufferEqual_data = bufferEqual->data;
            loop_ub = mfInfo2->size[1];
            for (i1 = 0; i1 < loop_ub; i1++) {
              bufferEqual_data[i1] = (mfInfo2_data[i1] == 39);
            }
            eml_find(bufferEqual, (int *)&idR_data, idR_size);
            i1 = nextLineVar->size[0] * nextLineVar->size[1];
            nextLineVar->size[0] = 1;
            nextLineVar->size[1] = (int)maxLineLength;
            emxEnsureCapacity_uint8_T(nextLineVar, i1);
            nextLineVar_data = nextLineVar->data;
            for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
              nextLineVar_data[i1] = 0U;
            }
            if ((double)idR_data - 1.0 < 1.0) {
              loop_ub = 0;
            } else {
              loop_ub = idR_data - 1;
            }
            for (i1 = 0; i1 < loop_ub; i1++) {
              nextLineVar_data[i1] = mfInfo2_data[i1];
            }
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              var_data[b_i].mf->data[j].name->data[i1] =
                  (signed char)nextLineVar_data[i1];
            }
            deblank(var_data[b_i].mf->data[j].name, r);
            var_data[b_i].mf->data[j].origNameLength = r->size[1];
            i1 = mfInfo3->size[0] * mfInfo3->size[1];
            mfInfo3->size[0] = 1;
            mfInfo3->size[1] = (int)maxLineLength;
            emxEnsureCapacity_uint8_T(mfInfo3, i1);
            mfInfo3_data = mfInfo3->data;
            for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
              mfInfo3_data[i1] = 0U;
            }
            if ((double)idR_data + 3.0 > mfInfo2->size[1]) {
              i1 = 0;
              i2 = 0;
            } else {
              i1 = idR_data + 2;
              i2 = mfInfo2->size[1];
            }
            loop_ub = i2 - i1;
            for (i2 = 0; i2 < loop_ub; i2++) {
              mfInfo3_data[i2] = mfInfo2_data[i1 + i2];
            }
            i1 = bufferEqual->size[0] * bufferEqual->size[1];
            bufferEqual->size[0] = 1;
            bufferEqual->size[1] = mfInfo3->size[1];
            emxEnsureCapacity_boolean_T(bufferEqual, i1);
            bufferEqual_data = bufferEqual->data;
            loop_ub = mfInfo3->size[1];
            for (i1 = 0; i1 < loop_ub; i1++) {
              bufferEqual_data[i1] = (mfInfo3_data[i1] == 39);
            }
            eml_find(bufferEqual, (int *)&idR_data, idR_size);
            i1 = nextLineVar->size[0] * nextLineVar->size[1];
            nextLineVar->size[0] = 1;
            nextLineVar->size[1] = (int)maxLineLength;
            emxEnsureCapacity_uint8_T(nextLineVar, i1);
            nextLineVar_data = nextLineVar->data;
            for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
              nextLineVar_data[i1] = 0U;
            }
            if ((double)idR_data - 1.0 < 1.0) {
              loop_ub = 0;
            } else {
              loop_ub = idR_data - 1;
            }
            for (i1 = 0; i1 < loop_ub; i1++) {
              nextLineVar_data[i1] = mfInfo3_data[i1];
            }
            for (i1 = 0; i1 < c_loop_ub; i1++) {
              var_data[b_i].mf->data[j].type->data[i1] =
                  (signed char)nextLineVar_data[i1];
            }
            deblank(var_data[b_i].mf->data[j].type, r);
            var_data[b_i].mf->data[j].origTypeLength = r->size[1];
            i1 = nextLineVar->size[0] * nextLineVar->size[1];
            nextLineVar->size[0] = 1;
            nextLineVar->size[1] = (int)maxLineLength;
            emxEnsureCapacity_uint8_T(nextLineVar, i1);
            nextLineVar_data = nextLineVar->data;
            for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
              nextLineVar_data[i1] = 0U;
            }
            if ((double)idR_data + 3.0 > mfInfo3->size[1]) {
              i1 = 0;
              i2 = 0;
            } else {
              i1 = idR_data + 2;
              i2 = mfInfo3->size[1];
            }
            loop_ub = i2 - i1;
            for (i2 = 0; i2 < loop_ub; i2++) {
              nextLineVar_data[i2] = mfInfo3_data[i1 + i2];
            }
            i1 = bufferEqual->size[0] * bufferEqual->size[1];
            bufferEqual->size[0] = 1;
            bufferEqual->size[1] = nextLineVar->size[1];
            emxEnsureCapacity_boolean_T(bufferEqual, i1);
            bufferEqual_data = bufferEqual->data;
            loop_ub = nextLineVar->size[1];
            for (i1 = 0; i1 < loop_ub; i1++) {
              bufferEqual_data[i1] = (nextLineVar_data[i1] == 32);
            }
            b_eml_find(bufferEqual, ids);
            ids_data = ids->data;
            startIndex = 1.0;
            i1 = ids->size[1];
            for (k = 0; k <= i1; k++) {
              double endIndex;
              if ((unsigned int)k == (unsigned int)ids->size[1]) {
                i2 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
                b_nextLineVar->size[0] = 1;
                b_nextLineVar->size[1] = nextLineVar->size[1];
                emxEnsureCapacity_char_T(b_nextLineVar, i2);
                b_nextLineVar_data = b_nextLineVar->data;
                loop_ub = nextLineVar->size[1];
                for (i2 = 0; i2 < loop_ub; i2++) {
                  b_nextLineVar_data[i2] = (signed char)nextLineVar_data[i2];
                }
                deblank(b_nextLineVar, r);
                endIndex = r->size[1];
              } else {
                endIndex = (double)ids_data[k] - 1.0;
              }
              if (startIndex > endIndex) {
                i2 = -1;
                loop_ub = -1;
              } else {
                i2 = (int)startIndex - 2;
                loop_ub = (int)endIndex - 1;
              }
              idR_data = loop_ub - i2;
              loop_ub = b_nextLineVar->size[0] * b_nextLineVar->size[1];
              b_nextLineVar->size[0] = 1;
              b_nextLineVar->size[1] = idR_data;
              emxEnsureCapacity_char_T(b_nextLineVar, loop_ub);
              b_nextLineVar_data = b_nextLineVar->data;
              for (loop_ub = 0; loop_ub < idR_data; loop_ub++) {
                b_nextLineVar_data[loop_ub] =
                    (signed char)nextLineVar_data[(i2 + loop_ub) + 1];
              }
              x = str2double(b_nextLineVar);
              var_data[b_i].mf->data[j].params->data[k] = x.re;
              startIndex = endIndex + 2.0;
            }
            var_data[b_i].mf->data[j].origParamLength =
                (double)ids->size[1] + 1.0;
          }
        }
      }
    }
  }
  emxFree_char_T(&r);
  emxFree_char_T(&b_nextLineVar);
  emxFree_int32_T(&ids);
  emxFree_uint8_T(&mfInfo3);
  emxFree_uint8_T(&mfInfo2);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&template);
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                double *info_maxNumMF
 *                double *info_maxMFNameLength
 *                double *info_maxMFTypeLength
 *                double *info_maxMFParamLength
 *                double *info_numVars
 *                boolean_T *info_hasSugenoMFs
 * Return Type  : double
 */
double getVarInfo(double fid, double maxLineLength, double *info_maxNumMF,
                  double *info_maxMFNameLength, double *info_maxMFTypeLength,
                  double *info_maxMFParamLength, double *info_numVars,
                  boolean_T *info_hasSugenoMFs)
{
  static const unsigned char uv[6] = {91U, 73U, 110U, 112U, 117U, 116U};
  FILE *filestar;
  emxArray_boolean_T *bufferEqual;
  emxArray_char_T *b_nextLineVar;
  emxArray_char_T *r;
  emxArray_int32_T *r1;
  emxArray_uint8_T *mfInfo2;
  emxArray_uint8_T *mfInfo3;
  emxArray_uint8_T *nextLineVar;
  emxArray_uint8_T *template;
  double info_maxInputNameLength;
  int i;
  int i1;
  int id_data;
  int j;
  int loop_ub_tmp;
  int maxInputNameLength;
  int maxMFNameLength;
  unsigned int maxMFParamLength;
  int maxMFTypeLength;
  char *b_nextLineVar_data;
  unsigned char *mfInfo2_data;
  unsigned char *mfInfo3_data;
  unsigned char *nextLineVar_data;
  unsigned char *template_data;
  boolean_T *bufferEqual_data;
  *info_numVars = 0.0;
  maxInputNameLength = 0;
  *info_maxNumMF = 0.0;
  maxMFNameLength = 0;
  maxMFTypeLength = 0;
  maxMFParamLength = 0U;
  emxInit_uint8_T(&template, 2);
  i = template->size[0] * template->size[1];
  template->size[0] = 1;
  loop_ub_tmp = (int)maxLineLength;
  template->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(template, i);
  template_data = template->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    template_data[i] = 0U;
  }
  for (i = 0; i < 6; i++) {
    template_data[i] = uv[i];
  }
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual);
  emxInit_uint8_T(&mfInfo2, 2);
  emxInit_uint8_T(&mfInfo3, 2);
  emxInit_char_T(&r, 2);
  emxInit_int32_T(&r1);
  emxInit_char_T(&b_nextLineVar, 2);
  int exitg1;
  do {
    exitg1 = 0;
    filestar = fileManager(fid);
    if (filestar == NULL) {
      i = 0;
    } else {
      int st;
      st = feof(filestar);
      i = ((int)st != 0);
    }
    if (i == 0) {
      int loop_ub;
      boolean_T exitg3;
      boolean_T y;
      getLine(fid, maxLineLength, nextLineVar);
      nextLineVar_data = nextLineVar->data;
      int exitg2;
      do {
        exitg2 = 0;
        y = false;
        id_data = 1;
        exitg3 = false;
        while ((!exitg3) && (id_data <= nextLineVar->size[1])) {
          if (nextLineVar_data[id_data - 1] != 0) {
            y = true;
            exitg3 = true;
          } else {
            id_data++;
          }
        }
        if (y && (((signed char)nextLineVar_data[0] == '%') ||
                  (nextLineVar_data[0] == 10))) {
          getLine(fid, maxLineLength, nextLineVar);
          nextLineVar_data = nextLineVar->data;
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);
      i = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i);
      bufferEqual_data = bufferEqual->data;
      loop_ub = nextLineVar->size[1];
      for (i = 0; i < loop_ub; i++) {
        bufferEqual_data[i] = (nextLineVar_data[i] == template_data[i]);
      }
      y = true;
      id_data = 0;
      exitg3 = false;
      while ((!exitg3) && (id_data <= 5)) {
        if (!bufferEqual_data[id_data]) {
          y = false;
          exitg3 = true;
        } else {
          id_data++;
        }
      }
      if (y) {
        creal_T x;
        (*info_numVars)++;
        findTopic(fid, maxLineLength, nextLineVar);
        nextLineVar_data = nextLineVar->data;
        i = b_nextLineVar->size[0] * b_nextLineVar->size[1];
        b_nextLineVar->size[0] = 1;
        b_nextLineVar->size[1] = nextLineVar->size[1];
        emxEnsureCapacity_char_T(b_nextLineVar, i);
        b_nextLineVar_data = b_nextLineVar->data;
        loop_ub = nextLineVar->size[1];
        for (i = 0; i < loop_ub; i++) {
          b_nextLineVar_data[i] = (signed char)nextLineVar_data[i];
        }
        deblank(b_nextLineVar, r);
        if (r->size[1] > maxInputNameLength) {
          maxInputNameLength = r->size[1];
        }
        h_findTopic(fid, maxLineLength, nextLineVar);
        nextLineVar_data = nextLineVar->data;
        i = b_nextLineVar->size[0] * b_nextLineVar->size[1];
        b_nextLineVar->size[0] = 1;
        b_nextLineVar->size[1] = nextLineVar->size[1];
        emxEnsureCapacity_char_T(b_nextLineVar, i);
        b_nextLineVar_data = b_nextLineVar->data;
        loop_ub = nextLineVar->size[1];
        for (i = 0; i < loop_ub; i++) {
          b_nextLineVar_data[i] = (signed char)nextLineVar_data[i];
        }
        deblank(b_nextLineVar, r);
        x = str2double(r);
        if (x.re > *info_maxNumMF) {
          *info_maxNumMF = x.re;
        }
        i = (int)x.re;
        for (j = 0; j < i; j++) {
          int id_size[2];
          i_findTopic(fid, maxLineLength, nextLineVar);
          nextLineVar_data = nextLineVar->data;
          i1 = mfInfo2->size[0] * mfInfo2->size[1];
          mfInfo2->size[0] = 1;
          mfInfo2->size[1] = (int)maxLineLength;
          emxEnsureCapacity_uint8_T(mfInfo2, i1);
          mfInfo2_data = mfInfo2->data;
          for (i1 = 0; i1 < loop_ub_tmp; i1++) {
            mfInfo2_data[i1] = 0U;
          }
          loop_ub = nextLineVar->size[1];
          for (i1 = 0; i1 <= loop_ub - 3; i1++) {
            mfInfo2_data[i1] = nextLineVar_data[i1 + 2];
          }
          i1 = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = mfInfo2->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i1);
          bufferEqual_data = bufferEqual->data;
          loop_ub = mfInfo2->size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            bufferEqual_data[i1] = (mfInfo2_data[i1] == 39);
          }
          eml_find(bufferEqual, (int *)&id_data, id_size);
          i1 = nextLineVar->size[0] * nextLineVar->size[1];
          nextLineVar->size[0] = 1;
          nextLineVar->size[1] = (int)maxLineLength;
          emxEnsureCapacity_uint8_T(nextLineVar, i1);
          nextLineVar_data = nextLineVar->data;
          for (i1 = 0; i1 < loop_ub_tmp; i1++) {
            nextLineVar_data[i1] = 0U;
          }
          if ((double)id_data - 1.0 < 1.0) {
            loop_ub = 0;
          } else {
            loop_ub = id_data - 1;
          }
          for (i1 = 0; i1 < loop_ub; i1++) {
            nextLineVar_data[i1] = mfInfo2_data[i1];
          }
          i1 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
          b_nextLineVar->size[0] = 1;
          b_nextLineVar->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_char_T(b_nextLineVar, i1);
          b_nextLineVar_data = b_nextLineVar->data;
          loop_ub = nextLineVar->size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_nextLineVar_data[i1] = (signed char)nextLineVar_data[i1];
          }
          deblank(b_nextLineVar, r);
          if (r->size[1] > maxMFNameLength) {
            maxMFNameLength = r->size[1];
          }
          i1 = mfInfo3->size[0] * mfInfo3->size[1];
          mfInfo3->size[0] = 1;
          mfInfo3->size[1] = (int)maxLineLength;
          emxEnsureCapacity_uint8_T(mfInfo3, i1);
          mfInfo3_data = mfInfo3->data;
          for (i1 = 0; i1 < loop_ub_tmp; i1++) {
            mfInfo3_data[i1] = 0U;
          }
          if ((double)id_data + 3.0 > mfInfo2->size[1]) {
            i1 = 0;
            id_data = 0;
          } else {
            i1 = id_data + 2;
            id_data = mfInfo2->size[1];
          }
          loop_ub = id_data - i1;
          for (id_data = 0; id_data < loop_ub; id_data++) {
            mfInfo3_data[id_data] = mfInfo2_data[i1 + id_data];
          }
          i1 = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = mfInfo3->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i1);
          bufferEqual_data = bufferEqual->data;
          loop_ub = mfInfo3->size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            bufferEqual_data[i1] = (mfInfo3_data[i1] == 39);
          }
          eml_find(bufferEqual, (int *)&id_data, id_size);
          i1 = nextLineVar->size[0] * nextLineVar->size[1];
          nextLineVar->size[0] = 1;
          nextLineVar->size[1] = (int)maxLineLength;
          emxEnsureCapacity_uint8_T(nextLineVar, i1);
          nextLineVar_data = nextLineVar->data;
          for (i1 = 0; i1 < loop_ub_tmp; i1++) {
            nextLineVar_data[i1] = 0U;
          }
          if ((double)id_data - 1.0 < 1.0) {
            loop_ub = 0;
          } else {
            loop_ub = id_data - 1;
          }
          for (i1 = 0; i1 < loop_ub; i1++) {
            nextLineVar_data[i1] = mfInfo3_data[i1];
          }
          i1 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
          b_nextLineVar->size[0] = 1;
          b_nextLineVar->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_char_T(b_nextLineVar, i1);
          b_nextLineVar_data = b_nextLineVar->data;
          loop_ub = nextLineVar->size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_nextLineVar_data[i1] = (signed char)nextLineVar_data[i1];
          }
          deblank(b_nextLineVar, r);
          if (r->size[1] > maxMFTypeLength) {
            maxMFTypeLength = r->size[1];
          }
          i1 = nextLineVar->size[0] * nextLineVar->size[1];
          nextLineVar->size[0] = 1;
          nextLineVar->size[1] = (int)maxLineLength;
          emxEnsureCapacity_uint8_T(nextLineVar, i1);
          nextLineVar_data = nextLineVar->data;
          for (i1 = 0; i1 < loop_ub_tmp; i1++) {
            nextLineVar_data[i1] = 0U;
          }
          if ((double)id_data + 3.0 > mfInfo3->size[1]) {
            i1 = 0;
            id_data = 0;
          } else {
            i1 = id_data + 2;
            id_data = mfInfo3->size[1];
          }
          loop_ub = id_data - i1;
          for (id_data = 0; id_data < loop_ub; id_data++) {
            nextLineVar_data[id_data] = mfInfo3_data[i1 + id_data];
          }
          i1 = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i1);
          bufferEqual_data = bufferEqual->data;
          loop_ub = nextLineVar->size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            bufferEqual_data[i1] = (nextLineVar_data[i1] == 44);
          }
          eml_find(bufferEqual, (int *)&id_data, id_size);
          if (id_size[1] != 0) {
            b_fclose(fid);
            exit(0);
          }
          i1 = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i1);
          bufferEqual_data = bufferEqual->data;
          loop_ub = nextLineVar->size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            bufferEqual_data[i1] = (nextLineVar_data[i1] == 32);
          }
          b_eml_find(bufferEqual, r1);
          if ((unsigned int)r1->size[1] + 1U > maxMFParamLength) {
            maxMFParamLength = (unsigned int)r1->size[1] + 1U;
          }
        }
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emxFree_char_T(&b_nextLineVar);
  emxFree_int32_T(&r1);
  emxFree_char_T(&r);
  emxFree_uint8_T(&mfInfo3);
  emxFree_uint8_T(&mfInfo2);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&template);
  info_maxInputNameLength = maxInputNameLength;
  *info_maxMFNameLength = maxMFNameLength;
  *info_maxMFTypeLength = maxMFTypeLength;
  *info_maxMFParamLength = maxMFParamLength;
  *info_hasSugenoMFs = false;
  return info_maxInputNameLength;
}

/*
 * File trailer for readFISAsHomogenousStructure.c
 *
 * [EOF]
 */
