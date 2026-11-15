/*
 * File: readFISAsHomogenousStructure.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "readFISAsHomogenousStructure.h"
#include "opkene_emxutil.h"
#include "str2double.h"
#include "char.h"
#include "fclose.h"
#include "deblank.h"
#include "feof.h"
#include "fileManager.h"
#include "any.h"
#include "strcmp.h"
#include "frewind.h"
#include "repmat.h"
#include "xor.h"
#include "all.h"

/* Type Definitions */
#include <stddef.h>

/* Function Declarations */
static void getLine(double fid, double maxLength, emxArray_uint8_T *result);
static double getNumRules(double fid, double maxLineLength);
static void h_findTopic(double fid, double maxLineLength, emxArray_uint8_T
  *topicValue);
static void i_findTopic(double fid, double maxLineLength, emxArray_uint8_T
  *topicValue);
static void j_findTopic(double fid, double maxLineLength, emxArray_uint8_T
  *topicValue);
static void validateAntecedentLength(double fid, double numInputs, double n);

/* Function Definitions */

/*
 * Arguments    : double fid
 *                double maxLength
 *                emxArray_uint8_T *result
 * Return Type  : void
 */
static void getLine(double fid, double maxLength, emxArray_uint8_T *result)
{
  int value_size_idx_0;
  int loop_ub;
  double count;
  boolean_T p;
  int exitg1;
  FILE * filestar;
  unsigned char value_data[1];
  size_t numReadSizeT;
  unsigned char buf;
  boolean_T y;
  boolean_T x_data[1];
  value_size_idx_0 = result->size[0] * result->size[1];
  result->size[0] = 1;
  loop_ub = (int)maxLength;
  result->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(result, value_size_idx_0);
  for (value_size_idx_0 = 0; value_size_idx_0 < loop_ub; value_size_idx_0++) {
    result->data[value_size_idx_0] = 0U;
  }

  count = 0.0;
  if ((fid != 0.0) && (fid != 1.0) && (fid != 2.0)) {
    p = true;
  } else {
    p = false;
  }

  do {
    exitg1 = 0;
    filestar = fileManager(fid);
    if (!p) {
      filestar = NULL;
    }

    if (filestar == NULL) {
      value_size_idx_0 = 0;
    } else {
      value_size_idx_0 = 1;
      value_data[0] = 0U;
      numReadSizeT = fread(&buf, sizeof(unsigned char), 1, filestar);
      if (0 <= (int)numReadSizeT - 1) {
        value_data[0] = buf;
      }

      if ((int)numReadSizeT + 1 <= 1) {
        value_data[0] = 0U;
      }

      if ((int)numReadSizeT < 1) {
        value_size_idx_0 = 0;
      }
    }

    if (value_size_idx_0 == 0) {
      exitg1 = 1;
    } else {
      for (value_size_idx_0 = 0; value_size_idx_0 < 1; value_size_idx_0++) {
        x_data[0] = (value_data[0] == 10);
      }

      y = true;
      if (!x_data[0]) {
        y = false;
      }

      if (y) {
        if (count == 0.0) {
          result->data[0] = value_data[0];
        }

        exitg1 = 1;
      } else {
        count++;
        result->data[(int)count - 1] = value_data[0];
      }
    }
  } while (exitg1 == 0);
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 * Return Type  : double
 */
static double getNumRules(double fid, double maxLineLength)
{
  double numRules;
  boolean_T topicFound;
  emxArray_uint8_T *nextLineVar;
  emxArray_char_T *r27;
  emxArray_char_T *r28;
  boolean_T exitg1;
  FILE * b_NULL;
  FILE * filestar;
  int st;
  int i53;
  int exitg2;
  numRules = 0.0;
  topicFound = false;
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_char_T(&r27, 2);
  emxInit_char_T(&r28, 2);
  exitg1 = false;
  while ((!exitg1) && (!topicFound)) {
    getNextLine(fid, maxLineLength, nextLineVar);
    b_NULL = NULL;
    filestar = fileManager(fid);
    if (filestar == b_NULL) {
      i53 = 0;
    } else {
      st = feof(filestar);
      i53 = ((int)st != 0);
    }

    if (i53 != 0) {
      exitg1 = true;
    } else {
      b_char(nextLineVar, r27);
      deblank(r27, r28);
      if (d_strcmp(r28)) {
        topicFound = true;
        b_NULL = NULL;
        filestar = fileManager(fid);
        do {
          exitg2 = 0;
          getNextLine(fid, maxLineLength, nextLineVar);
          if (filestar == b_NULL) {
            i53 = 0;
          } else {
            st = feof(filestar);
            i53 = ((int)st != 0);
          }

          if (i53 != 0) {
            exitg2 = 1;
          } else {
            if (any(nextLineVar) && (nextLineVar->data[0] != 10)) {
              numRules++;
            }
          }
        } while (exitg2 == 0);
      }
    }
  }

  emxFree_char_T(&r28);
  emxFree_char_T(&r27);
  emxFree_uint8_T(&nextLineVar);
  return numRules;
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                emxArray_uint8_T *topicValue
 * Return Type  : void
 */
static void h_findTopic(double fid, double maxLineLength, emxArray_uint8_T
  *topicValue)
{
  emxArray_uint8_T *buffer;
  int i;
  int loop_ub;
  boolean_T topicFound;
  static const unsigned char uv14[7] = { 78U, 117U, 109U, 77U, 70U, 115U, 61U };

  emxArray_uint8_T *nextLineVar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r17;
  boolean_T exitg1;
  FILE * b_NULL;
  FILE * filestar;
  int st;
  boolean_T y;
  boolean_T exitg2;
  int end;
  emxInit_uint8_T(&buffer, 2);
  i = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  loop_ub = (int)maxLineLength;
  buffer->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(buffer, i);
  for (i = 0; i < loop_ub; i++) {
    buffer->data[i] = 0U;
  }

  i = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(topicValue, i);
  for (i = 0; i < loop_ub; i++) {
    topicValue->data[i] = 0U;
  }

  for (i = 0; i < 7; i++) {
    buffer->data[i] = uv14[i];
  }

  topicFound = false;
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual, 2);
  emxInit_int32_T(&r17, 2);
  exitg1 = false;
  while ((!exitg1) && (!topicFound)) {
    getNextLine(fid, maxLineLength, nextLineVar);
    b_NULL = NULL;
    filestar = fileManager(fid);
    if (filestar == b_NULL) {
      i = 0;
    } else {
      st = feof(filestar);
      i = ((int)st != 0);
    }

    if (i != 0) {
      exitg1 = true;
    } else {
      i = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i);
      loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
      for (i = 0; i < loop_ub; i++) {
        bufferEqual->data[i] = (nextLineVar->data[i] == buffer->data[i]);
      }

      y = true;
      loop_ub = 0;
      exitg2 = false;
      while ((!exitg2) && (loop_ub < 7)) {
        if (!bufferEqual->data[loop_ub]) {
          y = false;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }

      if (y) {
        topicFound = true;
        xor(nextLineVar, buffer, bufferEqual);
        end = bufferEqual->size[1] - 1;
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        i = r17->size[0] * r17->size[1];
        r17->size[0] = 1;
        r17->size[1] = loop_ub;
        emxEnsureCapacity_int32_T(r17, i);
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            r17->data[loop_ub] = i + 1;
            loop_ub++;
          }
        }

        loop_ub = r17->size[1];
        for (i = 0; i < loop_ub; i++) {
          topicValue->data[i] = nextLineVar->data[r17->data[i] - 1];
        }
      }
    }
  }

  emxFree_int32_T(&r17);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&buffer);
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                emxArray_uint8_T *topicValue
 * Return Type  : void
 */
static void i_findTopic(double fid, double maxLineLength, emxArray_uint8_T
  *topicValue)
{
  emxArray_uint8_T *buffer;
  int i26;
  int loop_ub;
  boolean_T topicFound;
  emxArray_uint8_T *nextLineVar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r19;
  emxArray_uint8_T *b_nextLineVar;
  boolean_T exitg1;
  FILE * b_NULL;
  FILE * filestar;
  int st;
  boolean_T y;
  boolean_T exitg2;
  int end;
  int i;
  int i27;
  emxInit_uint8_T(&buffer, 2);
  i26 = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  loop_ub = (int)maxLineLength;
  buffer->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(buffer, i26);
  for (i26 = 0; i26 < loop_ub; i26++) {
    buffer->data[i26] = 0U;
  }

  i26 = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(topicValue, i26);
  for (i26 = 0; i26 < loop_ub; i26++) {
    topicValue->data[i26] = 0U;
  }

  buffer->data[0] = 77U;
  buffer->data[1] = 70U;
  topicFound = false;
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual, 2);
  emxInit_int32_T(&r19, 2);
  emxInit_uint8_T(&b_nextLineVar, 1);
  exitg1 = false;
  while ((!exitg1) && (!topicFound)) {
    getNextLine(fid, maxLineLength, nextLineVar);
    b_NULL = NULL;
    filestar = fileManager(fid);
    if (filestar == b_NULL) {
      i26 = 0;
    } else {
      st = feof(filestar);
      i26 = ((int)st != 0);
    }

    if (i26 != 0) {
      exitg1 = true;
    } else {
      i26 = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i26);
      loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
      for (i26 = 0; i26 < loop_ub; i26++) {
        bufferEqual->data[i26] = (nextLineVar->data[i26] == buffer->data[i26]);
      }

      y = true;
      loop_ub = 0;
      exitg2 = false;
      while ((!exitg2) && (loop_ub < 2)) {
        if (!bufferEqual->data[loop_ub]) {
          y = false;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }

      if (y) {
        topicFound = true;
        xor(nextLineVar, buffer, bufferEqual);
        end = bufferEqual->size[1];
        loop_ub = 0;
        for (i = 0; i < end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        if (2.0 > (double)loop_ub - 1.0) {
          i26 = 0;
          i27 = 0;
        } else {
          i26 = 1;
          i27 = loop_ub - 1;
        }

        end = bufferEqual->size[1] - 1;
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        i = r19->size[0] * r19->size[1];
        r19->size[0] = 1;
        r19->size[1] = loop_ub;
        emxEnsureCapacity_int32_T(r19, i);
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            r19->data[loop_ub] = i + 1;
            loop_ub++;
          }
        }

        loop_ub = r19->size[1];
        i = b_nextLineVar->size[0];
        b_nextLineVar->size[0] = loop_ub;
        emxEnsureCapacity_uint8_T(b_nextLineVar, i);
        for (i = 0; i < loop_ub; i++) {
          b_nextLineVar->data[i] = nextLineVar->data[r19->data[i] - 1];
        }

        loop_ub = i27 - i26;
        for (i27 = 0; i27 < loop_ub; i27++) {
          topicValue->data[i27] = b_nextLineVar->data[i26 + i27];
        }
      }
    }
  }

  emxFree_uint8_T(&b_nextLineVar);
  emxFree_int32_T(&r19);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&buffer);
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                emxArray_uint8_T *topicValue
 * Return Type  : void
 */
static void j_findTopic(double fid, double maxLineLength, emxArray_uint8_T
  *topicValue)
{
  emxArray_uint8_T *buffer;
  int i41;
  int loop_ub;
  boolean_T topicFound;
  static const unsigned char uv17[6] = { 82U, 97U, 110U, 103U, 101U, 61U };

  emxArray_uint8_T *nextLineVar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r23;
  emxArray_uint8_T *b_nextLineVar;
  boolean_T exitg1;
  FILE * b_NULL;
  FILE * filestar;
  int st;
  boolean_T y;
  boolean_T exitg2;
  int end;
  int i;
  int i42;
  emxInit_uint8_T(&buffer, 2);
  i41 = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  loop_ub = (int)maxLineLength;
  buffer->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(buffer, i41);
  for (i41 = 0; i41 < loop_ub; i41++) {
    buffer->data[i41] = 0U;
  }

  i41 = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(topicValue, i41);
  for (i41 = 0; i41 < loop_ub; i41++) {
    topicValue->data[i41] = 0U;
  }

  for (i41 = 0; i41 < 6; i41++) {
    buffer->data[i41] = uv17[i41];
  }

  topicFound = false;
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual, 2);
  emxInit_int32_T(&r23, 2);
  emxInit_uint8_T(&b_nextLineVar, 1);
  exitg1 = false;
  while ((!exitg1) && (!topicFound)) {
    getNextLine(fid, maxLineLength, nextLineVar);
    b_NULL = NULL;
    filestar = fileManager(fid);
    if (filestar == b_NULL) {
      i41 = 0;
    } else {
      st = feof(filestar);
      i41 = ((int)st != 0);
    }

    if (i41 != 0) {
      exitg1 = true;
    } else {
      i41 = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i41);
      loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
      for (i41 = 0; i41 < loop_ub; i41++) {
        bufferEqual->data[i41] = (nextLineVar->data[i41] == buffer->data[i41]);
      }

      y = true;
      loop_ub = 0;
      exitg2 = false;
      while ((!exitg2) && (loop_ub < 6)) {
        if (!bufferEqual->data[loop_ub]) {
          y = false;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }

      if (y) {
        topicFound = true;
        xor(nextLineVar, buffer, bufferEqual);
        end = bufferEqual->size[1];
        loop_ub = 0;
        for (i = 0; i < end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        if (2.0 > (double)loop_ub - 1.0) {
          i41 = 0;
          i42 = 0;
        } else {
          i41 = 1;
          i42 = loop_ub - 1;
        }

        end = bufferEqual->size[1] - 1;
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        i = r23->size[0] * r23->size[1];
        r23->size[0] = 1;
        r23->size[1] = loop_ub;
        emxEnsureCapacity_int32_T(r23, i);
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            r23->data[loop_ub] = i + 1;
            loop_ub++;
          }
        }

        loop_ub = r23->size[1];
        i = b_nextLineVar->size[0];
        b_nextLineVar->size[0] = loop_ub;
        emxEnsureCapacity_uint8_T(b_nextLineVar, i);
        for (i = 0; i < loop_ub; i++) {
          b_nextLineVar->data[i] = nextLineVar->data[r23->data[i] - 1];
        }

        loop_ub = i42 - i41;
        for (i42 = 0; i42 < loop_ub; i42++) {
          topicValue->data[i42] = b_nextLineVar->data[i41 + i42];
        }
      }
    }
  }

  emxFree_uint8_T(&b_nextLineVar);
  emxFree_int32_T(&r23);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&buffer);
}

/*
 * Arguments    : double fid
 *                double numInputs
 *                double n
 * Return Type  : void
 */
static void validateAntecedentLength(double fid, double numInputs, double n)
{
  if (n > numInputs) {
    b_fclose(fid);
    exit(0);
  }
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                emxArray_uint8_T *topicValue
 * Return Type  : void
 */
void b_findTopic(double fid, double maxLineLength, emxArray_uint8_T *topicValue)
{
  emxArray_uint8_T *buffer;
  int i9;
  int loop_ub;
  boolean_T topicFound;
  static const unsigned char uv7[5] = { 84U, 121U, 112U, 101U, 61U };

  emxArray_uint8_T *nextLineVar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r9;
  emxArray_uint8_T *b_nextLineVar;
  boolean_T exitg1;
  FILE * b_NULL;
  FILE * filestar;
  int st;
  boolean_T y;
  boolean_T exitg2;
  int end;
  int i;
  int i10;
  emxInit_uint8_T(&buffer, 2);
  i9 = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  loop_ub = (int)maxLineLength;
  buffer->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(buffer, i9);
  for (i9 = 0; i9 < loop_ub; i9++) {
    buffer->data[i9] = 0U;
  }

  i9 = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(topicValue, i9);
  for (i9 = 0; i9 < loop_ub; i9++) {
    topicValue->data[i9] = 0U;
  }

  for (i9 = 0; i9 < 5; i9++) {
    buffer->data[i9] = uv7[i9];
  }

  topicFound = false;
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual, 2);
  emxInit_int32_T(&r9, 2);
  emxInit_uint8_T(&b_nextLineVar, 1);
  exitg1 = false;
  while ((!exitg1) && (!topicFound)) {
    getNextLine(fid, maxLineLength, nextLineVar);
    b_NULL = NULL;
    filestar = fileManager(fid);
    if (filestar == b_NULL) {
      i9 = 0;
    } else {
      st = feof(filestar);
      i9 = ((int)st != 0);
    }

    if (i9 != 0) {
      exitg1 = true;
    } else {
      i9 = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i9);
      loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
      for (i9 = 0; i9 < loop_ub; i9++) {
        bufferEqual->data[i9] = (nextLineVar->data[i9] == buffer->data[i9]);
      }

      y = true;
      loop_ub = 0;
      exitg2 = false;
      while ((!exitg2) && (loop_ub < 5)) {
        if (!bufferEqual->data[loop_ub]) {
          y = false;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }

      if (y) {
        topicFound = true;
        xor(nextLineVar, buffer, bufferEqual);
        end = bufferEqual->size[1];
        loop_ub = 0;
        for (i = 0; i < end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        if (2.0 > (double)loop_ub - 1.0) {
          i9 = 0;
          i10 = 0;
        } else {
          i9 = 1;
          i10 = loop_ub - 1;
        }

        end = bufferEqual->size[1] - 1;
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        i = r9->size[0] * r9->size[1];
        r9->size[0] = 1;
        r9->size[1] = loop_ub;
        emxEnsureCapacity_int32_T(r9, i);
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            r9->data[loop_ub] = i + 1;
            loop_ub++;
          }
        }

        loop_ub = r9->size[1];
        i = b_nextLineVar->size[0];
        b_nextLineVar->size[0] = loop_ub;
        emxEnsureCapacity_uint8_T(b_nextLineVar, i);
        for (i = 0; i < loop_ub; i++) {
          b_nextLineVar->data[i] = nextLineVar->data[r9->data[i] - 1];
        }

        loop_ub = i10 - i9;
        for (i10 = 0; i10 < loop_ub; i10++) {
          topicValue->data[i10] = b_nextLineVar->data[i9 + i10];
        }
      }
    }
  }

  emxFree_uint8_T(&b_nextLineVar);
  emxFree_int32_T(&r9);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&buffer);
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
 *                boolean_T updateOutputRange
 *                h_emxArray_struct_T *var
 * Return Type  : void
 */
void b_getVar(double fid, double maxLineLength, double info_maxInputNameLength,
              double info_maxNumMF, double info_maxMFNameLength, double
              info_maxMFTypeLength, double info_maxMFParamLength, double
              info_numVars, boolean_T updateOutputRange, h_emxArray_struct_T
              *var)
{
  emxArray_real_T *r24;
  int i43;
  int loop_ub;
  emxArray_char_T *mfTemplate_name;
  emxArray_char_T *mfTemplate_type;
  emxArray_int8_T *mfTemplate_params;
  emxArray_char_T *varTemplate_name;
  struct_T expl_temp;
  emxArray_struct_T *varTemplate_mf;
  h_struct_T b_expl_temp;
  emxArray_uint8_T *template;
  emxArray_uint8_T *nextLineVar;
  emxArray_boolean_T *bufferEqual;
  emxArray_uint8_T *mfInfo2;
  emxArray_uint8_T *mfInfo3;
  emxArray_uint32_T *ids;
  emxArray_int32_T *ii;
  emxArray_uint8_T *b_nextLineVar;
  int i;
  int i44;
  boolean_T topicFound;
  static const unsigned char uv18[7] = { 91U, 79U, 117U, 116U, 112U, 117U, 116U
  };

  boolean_T exitg1;
  double d2;
  int b_loop_ub;
  int idx;
  boolean_T exitg2;
  unsigned int idR_data[1];
  creal_T dc3;
  int i45;
  int j;
  int i46;
  int i47;
  int nx;
  unsigned int startIndex;
  int i48;
  int i49;
  emxInit_real_T(&r24, 2);
  i43 = r24->size[0] * r24->size[1];
  r24->size[0] = 1;
  loop_ub = (int)info_maxMFNameLength;
  r24->size[1] = loop_ub;
  emxEnsureCapacity_real_T(r24, i43);
  for (i43 = 0; i43 < loop_ub; i43++) {
    r24->data[i43] = 0.0;
  }

  emxInit_char_T(&mfTemplate_name, 2);
  c_char(r24, mfTemplate_name);
  i43 = r24->size[0] * r24->size[1];
  r24->size[0] = 1;
  loop_ub = (int)info_maxMFTypeLength;
  r24->size[1] = loop_ub;
  emxEnsureCapacity_real_T(r24, i43);
  for (i43 = 0; i43 < loop_ub; i43++) {
    r24->data[i43] = 0.0;
  }

  emxInit_char_T(&mfTemplate_type, 2);
  emxInit_int8_T(&mfTemplate_params, 2);
  c_char(r24, mfTemplate_type);
  i43 = mfTemplate_params->size[0] * mfTemplate_params->size[1];
  mfTemplate_params->size[0] = 1;
  loop_ub = (int)info_maxMFParamLength;
  mfTemplate_params->size[1] = loop_ub;
  emxEnsureCapacity_int8_T(mfTemplate_params, i43);
  for (i43 = 0; i43 < loop_ub; i43++) {
    mfTemplate_params->data[i43] = 0;
  }

  i43 = r24->size[0] * r24->size[1];
  r24->size[0] = 1;
  loop_ub = (int)info_maxInputNameLength;
  r24->size[1] = loop_ub;
  emxEnsureCapacity_real_T(r24, i43);
  for (i43 = 0; i43 < loop_ub; i43++) {
    r24->data[i43] = 0.0;
  }

  emxInit_char_T(&varTemplate_name, 2);
  c_char(r24, varTemplate_name);
  emxFree_real_T(&r24);
  emxInitStruct_struct_T6(&expl_temp);
  expl_temp.origParamLength = 0.0;
  i43 = expl_temp.params->size[0] * expl_temp.params->size[1];
  expl_temp.params->size[0] = 1;
  expl_temp.params->size[1] = mfTemplate_params->size[1];
  emxEnsureCapacity_real_T(expl_temp.params, i43);
  loop_ub = mfTemplate_params->size[0] * mfTemplate_params->size[1];
  for (i43 = 0; i43 < loop_ub; i43++) {
    expl_temp.params->data[i43] = mfTemplate_params->data[i43];
  }

  emxFree_int8_T(&mfTemplate_params);
  expl_temp.origTypeLength = 0.0;
  i43 = expl_temp.type->size[0] * expl_temp.type->size[1];
  expl_temp.type->size[0] = 1;
  expl_temp.type->size[1] = mfTemplate_type->size[1];
  emxEnsureCapacity_char_T(expl_temp.type, i43);
  loop_ub = mfTemplate_type->size[0] * mfTemplate_type->size[1];
  for (i43 = 0; i43 < loop_ub; i43++) {
    expl_temp.type->data[i43] = mfTemplate_type->data[i43];
  }

  expl_temp.origNameLength = 0.0;
  i43 = expl_temp.name->size[0] * expl_temp.name->size[1];
  expl_temp.name->size[0] = 1;
  expl_temp.name->size[1] = mfTemplate_name->size[1];
  emxEnsureCapacity_char_T(expl_temp.name, i43);
  loop_ub = mfTemplate_name->size[0] * mfTemplate_name->size[1];
  for (i43 = 0; i43 < loop_ub; i43++) {
    expl_temp.name->data[i43] = mfTemplate_name->data[i43];
  }

  emxInit_struct_T6(&varTemplate_mf, 2);
  emxInitStruct_struct_T7(&b_expl_temp);
  repmat(expl_temp, info_maxNumMF, varTemplate_mf);
  b_expl_temp.origNumMF = 0.0;
  i43 = b_expl_temp.mf->size[0] * b_expl_temp.mf->size[1];
  b_expl_temp.mf->size[0] = 1;
  b_expl_temp.mf->size[1] = varTemplate_mf->size[1];
  emxEnsureCapacity_struct_T4(b_expl_temp.mf, i43);
  loop_ub = varTemplate_mf->size[0] * varTemplate_mf->size[1];
  emxFreeStruct_struct_T5(&expl_temp);
  for (i43 = 0; i43 < loop_ub; i43++) {
    emxCopyStruct_struct_T4(&b_expl_temp.mf->data[i43], &varTemplate_mf->
      data[i43]);
  }

  emxFree_struct_T3(&varTemplate_mf);
  b_expl_temp.range[0] = 0.0;
  b_expl_temp.range[1] = 0.0;
  b_expl_temp.origNameLength = 0.0;
  i43 = b_expl_temp.name->size[0] * b_expl_temp.name->size[1];
  b_expl_temp.name->size[0] = 1;
  b_expl_temp.name->size[1] = varTemplate_name->size[1];
  emxEnsureCapacity_char_T(b_expl_temp.name, i43);
  loop_ub = varTemplate_name->size[0] * varTemplate_name->size[1];
  for (i43 = 0; i43 < loop_ub; i43++) {
    b_expl_temp.name->data[i43] = varTemplate_name->data[i43];
  }

  emxFree_char_T(&varTemplate_name);
  b_repmat(b_expl_temp, info_numVars, var);
  i43 = (int)info_numVars;
  emxFreeStruct_struct_T4(&b_expl_temp);
  emxInit_uint8_T(&template, 2);
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual, 2);
  emxInit_uint8_T(&mfInfo2, 2);
  emxInit_uint8_T(&mfInfo3, 2);
  emxInit_uint32_T(&ids, 2);
  emxInit_int32_T(&ii, 2);
  emxInit_uint8_T(&b_nextLineVar, 2);
  for (i = 0; i < i43; i++) {
    i44 = template->size[0] * template->size[1];
    template->size[0] = 1;
    loop_ub = (int)maxLineLength;
    template->size[1] = loop_ub;
    emxEnsureCapacity_uint8_T(template, i44);
    for (i44 = 0; i44 < loop_ub; i44++) {
      template->data[i44] = 0U;
    }

    for (i44 = 0; i44 < 7; i44++) {
      template->data[i44] = uv18[i44];
    }

    topicFound = false;
    exitg1 = false;
    while ((!exitg1) && (!topicFound)) {
      getNextLine(fid, maxLineLength, nextLineVar);
      d2 = b_feof(fid);
      if (d2 != 0.0) {
        exitg1 = true;
      } else {
        i44 = bufferEqual->size[0] * bufferEqual->size[1];
        bufferEqual->size[0] = 1;
        bufferEqual->size[1] = nextLineVar->size[1];
        emxEnsureCapacity_boolean_T(bufferEqual, i44);
        b_loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
        for (i44 = 0; i44 < b_loop_ub; i44++) {
          bufferEqual->data[i44] = (nextLineVar->data[i44] == template->data[i44]);
        }

        if (b_all(*(boolean_T (*)[7])&bufferEqual->data[0])) {
          topicFound = true;
          findTopic(fid, maxLineLength, nextLineVar);
          if (1.0 > info_maxInputNameLength) {
            b_loop_ub = -1;
          } else {
            b_loop_ub = (int)info_maxInputNameLength - 1;
          }

          for (i44 = 0; i44 <= b_loop_ub; i44++) {
            var->data[i].name->data[i44] = (signed char)nextLineVar->data[i44];
          }

          deblank(var->data[i].name, mfTemplate_name);
          var->data[i].origNameLength = mfTemplate_name->size[1];
          j_findTopic(fid, maxLineLength, nextLineVar);
          i44 = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i44);
          b_loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
          for (i44 = 0; i44 < b_loop_ub; i44++) {
            bufferEqual->data[i44] = (nextLineVar->data[i44] == 32);
          }

          idx = 0;
          i44 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = 1;
          emxEnsureCapacity_int32_T(ii, i44);
          b_loop_ub = 0;
          exitg2 = false;
          while ((!exitg2) && (b_loop_ub <= bufferEqual->size[1] - 1)) {
            if (bufferEqual->data[b_loop_ub]) {
              idx = 1;
              ii->data[0] = b_loop_ub + 1;
              exitg2 = true;
            } else {
              b_loop_ub++;
            }
          }

          if (idx == 0) {
            ii->size[0] = 1;
            ii->size[1] = 0;
          }

          b_loop_ub = ii->size[0] * ii->size[1];
          for (i44 = 0; i44 < b_loop_ub; i44++) {
            idR_data[i44] = (unsigned int)ii->data[i44];
          }

          if (1 > (int)idR_data[0] - 1) {
            b_loop_ub = 0;
          } else {
            b_loop_ub = (int)idR_data[0] - 1;
          }

          i44 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
          b_nextLineVar->size[0] = 1;
          b_nextLineVar->size[1] = b_loop_ub;
          emxEnsureCapacity_uint8_T(b_nextLineVar, i44);
          for (i44 = 0; i44 < b_loop_ub; i44++) {
            b_nextLineVar->data[i44] = nextLineVar->data[i44];
          }

          b_char(b_nextLineVar, mfTemplate_name);
          deblank(mfTemplate_name, mfTemplate_type);
          dc3 = str2double(mfTemplate_type);
          var->data[i].range[0] = dc3.re;
          if (idR_data[0] + 1U > (unsigned int)nextLineVar->size[1]) {
            i44 = 0;
            i45 = 0;
          } else {
            i44 = (int)idR_data[0];
            i45 = nextLineVar->size[1];
          }

          idx = b_nextLineVar->size[0] * b_nextLineVar->size[1];
          b_nextLineVar->size[0] = 1;
          b_loop_ub = i45 - i44;
          b_nextLineVar->size[1] = b_loop_ub;
          emxEnsureCapacity_uint8_T(b_nextLineVar, idx);
          for (i45 = 0; i45 < b_loop_ub; i45++) {
            b_nextLineVar->data[i45] = nextLineVar->data[i44 + i45];
          }

          b_char(b_nextLineVar, mfTemplate_name);
          deblank(mfTemplate_name, mfTemplate_type);
          dc3 = str2double(mfTemplate_type);
          var->data[i].range[1] = dc3.re;
          if (updateOutputRange && (var->data[i].range[1] <= var->data[i].range
               [0])) {
            var->data[i].range[1] = var->data[i].range[0] + 1.0;
          }

          h_findTopic(fid, maxLineLength, nextLineVar);
          b_char(nextLineVar, mfTemplate_name);
          deblank(mfTemplate_name, mfTemplate_type);
          dc3 = str2double(mfTemplate_type);
          var->data[i].origNumMF = dc3.re;
          i44 = (int)dc3.re;
          for (j = 0; j < i44; j++) {
            i_findTopic(fid, maxLineLength, nextLineVar);
            i45 = mfInfo2->size[0] * mfInfo2->size[1];
            mfInfo2->size[0] = 1;
            mfInfo2->size[1] = loop_ub;
            emxEnsureCapacity_uint8_T(mfInfo2, i45);
            for (i45 = 0; i45 < loop_ub; i45++) {
              mfInfo2->data[i45] = 0U;
            }

            b_loop_ub = nextLineVar->size[1] - 3;
            for (i45 = 0; i45 <= b_loop_ub; i45++) {
              mfInfo2->data[i45] = nextLineVar->data[2 + i45];
            }

            i45 = bufferEqual->size[0] * bufferEqual->size[1];
            bufferEqual->size[0] = 1;
            bufferEqual->size[1] = mfInfo2->size[1];
            emxEnsureCapacity_boolean_T(bufferEqual, i45);
            b_loop_ub = mfInfo2->size[0] * mfInfo2->size[1];
            for (i45 = 0; i45 < b_loop_ub; i45++) {
              bufferEqual->data[i45] = (mfInfo2->data[i45] == 39);
            }

            idx = 0;
            i45 = ii->size[0] * ii->size[1];
            ii->size[0] = 1;
            ii->size[1] = 1;
            emxEnsureCapacity_int32_T(ii, i45);
            b_loop_ub = 0;
            exitg2 = false;
            while ((!exitg2) && (b_loop_ub <= bufferEqual->size[1] - 1)) {
              if (bufferEqual->data[b_loop_ub]) {
                idx = 1;
                ii->data[0] = b_loop_ub + 1;
                exitg2 = true;
              } else {
                b_loop_ub++;
              }
            }

            if (idx == 0) {
              ii->size[0] = 1;
              ii->size[1] = 0;
            }

            b_loop_ub = ii->size[0] * ii->size[1];
            for (i45 = 0; i45 < b_loop_ub; i45++) {
              idR_data[i45] = (unsigned int)ii->data[i45];
            }

            i45 = nextLineVar->size[0] * nextLineVar->size[1];
            nextLineVar->size[0] = 1;
            nextLineVar->size[1] = loop_ub;
            emxEnsureCapacity_uint8_T(nextLineVar, i45);
            for (i45 = 0; i45 < loop_ub; i45++) {
              nextLineVar->data[i45] = 0U;
            }

            if (1 > (int)idR_data[0] - 1) {
              i46 = 0;
            } else {
              i46 = (int)idR_data[0] - 1;
            }

            b_loop_ub = i46 - 1;
            for (i45 = 0; i45 <= b_loop_ub; i45++) {
              nextLineVar->data[i45] = mfInfo2->data[i45];
            }

            if (1.0 > info_maxMFNameLength) {
              b_loop_ub = -1;
            } else {
              b_loop_ub = (int)info_maxMFNameLength - 1;
            }

            for (i45 = 0; i45 <= b_loop_ub; i45++) {
              var->data[i].mf->data[j].name->data[i45] = (signed char)
                nextLineVar->data[i45];
            }

            deblank(var->data[i].mf->data[j].name, mfTemplate_name);
            var->data[i].mf->data[j].origNameLength = mfTemplate_name->size[1];
            i45 = mfInfo3->size[0] * mfInfo3->size[1];
            mfInfo3->size[0] = 1;
            mfInfo3->size[1] = loop_ub;
            emxEnsureCapacity_uint8_T(mfInfo3, i45);
            for (i45 = 0; i45 < loop_ub; i45++) {
              mfInfo3->data[i45] = 0U;
            }

            if (idR_data[0] + 3U > (unsigned int)mfInfo2->size[1]) {
              i45 = 1;
              idx = 0;
            } else {
              i45 = (int)(idR_data[0] + 3U);
              idx = mfInfo2->size[1];
            }

            b_loop_ub = idx - i45;
            for (idx = 0; idx <= b_loop_ub; idx++) {
              mfInfo3->data[idx] = mfInfo2->data[(i45 + idx) - 1];
            }

            i45 = bufferEqual->size[0] * bufferEqual->size[1];
            bufferEqual->size[0] = 1;
            bufferEqual->size[1] = mfInfo3->size[1];
            emxEnsureCapacity_boolean_T(bufferEqual, i45);
            b_loop_ub = mfInfo3->size[0] * mfInfo3->size[1];
            for (i45 = 0; i45 < b_loop_ub; i45++) {
              bufferEqual->data[i45] = (mfInfo3->data[i45] == 39);
            }

            idx = 0;
            i45 = ii->size[0] * ii->size[1];
            ii->size[0] = 1;
            ii->size[1] = 1;
            emxEnsureCapacity_int32_T(ii, i45);
            b_loop_ub = 0;
            exitg2 = false;
            while ((!exitg2) && (b_loop_ub <= bufferEqual->size[1] - 1)) {
              if (bufferEqual->data[b_loop_ub]) {
                idx = 1;
                ii->data[0] = b_loop_ub + 1;
                exitg2 = true;
              } else {
                b_loop_ub++;
              }
            }

            if (idx == 0) {
              ii->size[0] = 1;
              ii->size[1] = 0;
            }

            b_loop_ub = ii->size[0] * ii->size[1];
            for (i45 = 0; i45 < b_loop_ub; i45++) {
              idR_data[i45] = (unsigned int)ii->data[i45];
            }

            i45 = nextLineVar->size[0] * nextLineVar->size[1];
            nextLineVar->size[0] = 1;
            nextLineVar->size[1] = loop_ub;
            emxEnsureCapacity_uint8_T(nextLineVar, i45);
            for (i45 = 0; i45 < loop_ub; i45++) {
              nextLineVar->data[i45] = 0U;
            }

            if (1 > (int)idR_data[0] - 1) {
              i47 = 0;
            } else {
              i47 = (int)idR_data[0] - 1;
            }

            b_loop_ub = i47 - 1;
            for (i45 = 0; i45 <= b_loop_ub; i45++) {
              nextLineVar->data[i45] = mfInfo3->data[i45];
            }

            if (1.0 > info_maxMFTypeLength) {
              b_loop_ub = -1;
            } else {
              b_loop_ub = (int)info_maxMFTypeLength - 1;
            }

            for (i45 = 0; i45 <= b_loop_ub; i45++) {
              var->data[i].mf->data[j].type->data[i45] = (signed char)
                nextLineVar->data[i45];
            }

            deblank(var->data[i].mf->data[j].type, mfTemplate_name);
            var->data[i].mf->data[j].origTypeLength = mfTemplate_name->size[1];
            i45 = nextLineVar->size[0] * nextLineVar->size[1];
            nextLineVar->size[0] = 1;
            nextLineVar->size[1] = loop_ub;
            emxEnsureCapacity_uint8_T(nextLineVar, i45);
            for (i45 = 0; i45 < loop_ub; i45++) {
              nextLineVar->data[i45] = 0U;
            }

            if (idR_data[0] + 3U > (unsigned int)mfInfo3->size[1]) {
              i45 = 1;
              idx = 0;
            } else {
              i45 = (int)(idR_data[0] + 3U);
              idx = mfInfo3->size[1];
            }

            b_loop_ub = idx - i45;
            for (idx = 0; idx <= b_loop_ub; idx++) {
              nextLineVar->data[idx] = mfInfo3->data[(i45 + idx) - 1];
            }

            i45 = bufferEqual->size[0] * bufferEqual->size[1];
            bufferEqual->size[0] = 1;
            bufferEqual->size[1] = nextLineVar->size[1];
            emxEnsureCapacity_boolean_T(bufferEqual, i45);
            b_loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
            for (i45 = 0; i45 < b_loop_ub; i45++) {
              bufferEqual->data[i45] = (nextLineVar->data[i45] == 32);
            }

            nx = bufferEqual->size[1];
            idx = 0;
            i45 = ii->size[0] * ii->size[1];
            ii->size[0] = 1;
            ii->size[1] = bufferEqual->size[1];
            emxEnsureCapacity_int32_T(ii, i45);
            b_loop_ub = 0;
            exitg2 = false;
            while ((!exitg2) && (b_loop_ub <= nx - 1)) {
              if (bufferEqual->data[b_loop_ub]) {
                idx++;
                ii->data[idx - 1] = b_loop_ub + 1;
                if (idx >= nx) {
                  exitg2 = true;
                } else {
                  b_loop_ub++;
                }
              } else {
                b_loop_ub++;
              }
            }

            if (bufferEqual->size[1] == 1) {
              if (idx == 0) {
                ii->size[0] = 1;
                ii->size[1] = 0;
              }
            } else if (1 > idx) {
              ii->size[1] = 0;
            } else {
              i45 = ii->size[0] * ii->size[1];
              ii->size[1] = idx;
              emxEnsureCapacity_int32_T(ii, i45);
            }

            i45 = ids->size[0] * ids->size[1];
            ids->size[0] = 1;
            ids->size[1] = ii->size[1];
            emxEnsureCapacity_uint32_T(ids, i45);
            b_loop_ub = ii->size[0] * ii->size[1];
            for (i45 = 0; i45 < b_loop_ub; i45++) {
              ids->data[i45] = (unsigned int)ii->data[i45];
            }

            i45 = ids->size[1];
            for (nx = 0; nx < i45; nx++) {
              if (1 + nx == ids->size[1]) {
                if (1 + nx == 1) {
                  startIndex = 1U;
                } else {
                  startIndex = ids->data[nx - 1] + 1U;
                }

                if (startIndex > (unsigned int)((int)ids->data[nx] - 1)) {
                  idx = 0;
                  i48 = 0;
                } else {
                  idx = (int)startIndex - 1;
                  i48 = (int)ids->data[nx] - 1;
                }

                i49 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
                b_nextLineVar->size[0] = 1;
                b_loop_ub = i48 - idx;
                b_nextLineVar->size[1] = b_loop_ub;
                emxEnsureCapacity_uint8_T(b_nextLineVar, i49);
                for (i48 = 0; i48 < b_loop_ub; i48++) {
                  b_nextLineVar->data[i48] = nextLineVar->data[idx + i48];
                }

                b_char(b_nextLineVar, mfTemplate_name);
                dc3 = str2double(mfTemplate_name);
                var->data[i].mf->data[j].params->data[nx] = dc3.re;
                if (ids->data[nx] + 1U > (unsigned int)nextLineVar->size[1]) {
                  idx = 0;
                  i48 = 0;
                } else {
                  idx = (int)ids->data[nx];
                  i48 = nextLineVar->size[1];
                }

                i49 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
                b_nextLineVar->size[0] = 1;
                b_loop_ub = i48 - idx;
                b_nextLineVar->size[1] = b_loop_ub;
                emxEnsureCapacity_uint8_T(b_nextLineVar, i49);
                for (i48 = 0; i48 < b_loop_ub; i48++) {
                  b_nextLineVar->data[i48] = nextLineVar->data[idx + i48];
                }

                b_char(b_nextLineVar, mfTemplate_name);
                deblank(mfTemplate_name, mfTemplate_type);
                dc3 = str2double(mfTemplate_type);
                var->data[i].mf->data[j].params->data[nx + 1] = dc3.re;
              } else {
                if (1 + nx == 1) {
                  startIndex = 1U;
                } else {
                  startIndex = ids->data[nx - 1] + 1U;
                }

                if (startIndex > (unsigned int)((int)ids->data[nx] - 1)) {
                  idx = 0;
                  i48 = 0;
                } else {
                  idx = (int)startIndex - 1;
                  i48 = (int)ids->data[nx] - 1;
                }

                i49 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
                b_nextLineVar->size[0] = 1;
                b_loop_ub = i48 - idx;
                b_nextLineVar->size[1] = b_loop_ub;
                emxEnsureCapacity_uint8_T(b_nextLineVar, i49);
                for (i48 = 0; i48 < b_loop_ub; i48++) {
                  b_nextLineVar->data[i48] = nextLineVar->data[idx + i48];
                }

                b_char(b_nextLineVar, mfTemplate_name);
                dc3 = str2double(mfTemplate_name);
                var->data[i].mf->data[j].params->data[nx] = dc3.re;
              }
            }

            var->data[i].mf->data[j].origParamLength = (double)ids->size[1] +
              1.0;
          }
        }
      }
    }
  }

  emxFree_uint8_T(&b_nextLineVar);
  emxFree_int32_T(&ii);
  emxFree_uint32_T(&ids);
  emxFree_uint8_T(&mfInfo3);
  emxFree_uint8_T(&mfInfo2);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&template);
  emxFree_char_T(&mfTemplate_type);
  emxFree_char_T(&mfTemplate_name);
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                boolean_T checkForSugenoMFs
 *                double *info_maxInputNameLength
 *                double *info_maxNumMF
 *                double *info_maxMFNameLength
 *                double *info_maxMFTypeLength
 *                double *info_maxMFParamLength
 *                double *info_numVars
 *                boolean_T *info_hasSugenoMFs
 * Return Type  : void
 */
void b_getVarInfo(double fid, double maxLineLength, boolean_T checkForSugenoMFs,
                  double *info_maxInputNameLength, double *info_maxNumMF, double
                  *info_maxMFNameLength, double *info_maxMFTypeLength, double
                  *info_maxMFParamLength, double *info_numVars, boolean_T
                  *info_hasSugenoMFs)
{
  emxArray_uint8_T *template;
  int maxInputNameLength;
  int maxMFNameLength;
  int maxMFTypeLength;
  unsigned int maxMFParamLength;
  int i28;
  int loop_ub;
  emxArray_uint8_T *nextLineVar;
  static const unsigned char uv15[7] = { 91U, 79U, 117U, 116U, 112U, 117U, 116U
  };

  emxArray_boolean_T *bufferEqual;
  emxArray_uint8_T *mfInfo2;
  emxArray_uint8_T *mfInfo3;
  emxArray_int32_T *ii;
  emxArray_char_T *r20;
  emxArray_char_T *r21;
  FILE * b_NULL;
  FILE * filestar;
  int exitg1;
  int st;
  int b_loop_ub;
  boolean_T y;
  boolean_T exitg2;
  creal_T dc1;
  int j;
  int i29;
  int idx;
  unsigned int id_data[1];
  int i30;
  int i31;
  int nx;
  unsigned int u1;
  emxInit_uint8_T(&template, 2);
  *info_numVars = 0.0;
  maxInputNameLength = 0;
  *info_maxNumMF = 0.0;
  maxMFNameLength = 0;
  maxMFTypeLength = 0;
  maxMFParamLength = 0U;
  *info_hasSugenoMFs = false;
  i28 = template->size[0] * template->size[1];
  template->size[0] = 1;
  loop_ub = (int)maxLineLength;
  template->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(template, i28);
  for (i28 = 0; i28 < loop_ub; i28++) {
    template->data[i28] = 0U;
  }

  for (i28 = 0; i28 < 7; i28++) {
    template->data[i28] = uv15[i28];
  }

  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual, 2);
  emxInit_uint8_T(&mfInfo2, 2);
  emxInit_uint8_T(&mfInfo3, 2);
  emxInit_int32_T(&ii, 2);
  emxInit_char_T(&r20, 2);
  emxInit_char_T(&r21, 2);
  b_NULL = NULL;
  filestar = fileManager(fid);
  do {
    exitg1 = 0;
    if (filestar == b_NULL) {
      i28 = 0;
    } else {
      st = feof(filestar);
      i28 = ((int)st != 0);
    }

    if (i28 == 0) {
      getNextLine(fid, maxLineLength, nextLineVar);
      i28 = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i28);
      b_loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
      for (i28 = 0; i28 < b_loop_ub; i28++) {
        bufferEqual->data[i28] = (nextLineVar->data[i28] == template->data[i28]);
      }

      y = true;
      b_loop_ub = 0;
      exitg2 = false;
      while ((!exitg2) && (b_loop_ub < 7)) {
        if (!bufferEqual->data[b_loop_ub]) {
          y = false;
          exitg2 = true;
        } else {
          b_loop_ub++;
        }
      }

      if (y) {
        (*info_numVars)++;
        findTopic(fid, maxLineLength, nextLineVar);
        b_char(nextLineVar, r20);
        deblank(r20, r21);
        b_loop_ub = r21->size[1];
        if (b_loop_ub > maxInputNameLength) {
          maxInputNameLength = b_loop_ub;
        }

        h_findTopic(fid, maxLineLength, nextLineVar);
        b_char(nextLineVar, r20);
        deblank(r20, r21);
        dc1 = str2double(r21);
        if (dc1.re > *info_maxNumMF) {
          *info_maxNumMF = dc1.re;
        }

        i28 = (int)dc1.re;
        for (j = 0; j < i28; j++) {
          i_findTopic(fid, maxLineLength, nextLineVar);
          i29 = mfInfo2->size[0] * mfInfo2->size[1];
          mfInfo2->size[0] = 1;
          mfInfo2->size[1] = loop_ub;
          emxEnsureCapacity_uint8_T(mfInfo2, i29);
          for (i29 = 0; i29 < loop_ub; i29++) {
            mfInfo2->data[i29] = 0U;
          }

          b_loop_ub = nextLineVar->size[1] - 3;
          for (i29 = 0; i29 <= b_loop_ub; i29++) {
            mfInfo2->data[i29] = nextLineVar->data[2 + i29];
          }

          i29 = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = mfInfo2->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i29);
          b_loop_ub = mfInfo2->size[0] * mfInfo2->size[1];
          for (i29 = 0; i29 < b_loop_ub; i29++) {
            bufferEqual->data[i29] = (mfInfo2->data[i29] == 39);
          }

          idx = 0;
          i29 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = 1;
          emxEnsureCapacity_int32_T(ii, i29);
          b_loop_ub = 0;
          exitg2 = false;
          while ((!exitg2) && (b_loop_ub <= bufferEqual->size[1] - 1)) {
            if (bufferEqual->data[b_loop_ub]) {
              idx = 1;
              ii->data[0] = b_loop_ub + 1;
              exitg2 = true;
            } else {
              b_loop_ub++;
            }
          }

          if (idx == 0) {
            ii->size[0] = 1;
            ii->size[1] = 0;
          }

          b_loop_ub = ii->size[0] * ii->size[1];
          for (i29 = 0; i29 < b_loop_ub; i29++) {
            id_data[i29] = (unsigned int)ii->data[i29];
          }

          i29 = nextLineVar->size[0] * nextLineVar->size[1];
          nextLineVar->size[0] = 1;
          nextLineVar->size[1] = loop_ub;
          emxEnsureCapacity_uint8_T(nextLineVar, i29);
          for (i29 = 0; i29 < loop_ub; i29++) {
            nextLineVar->data[i29] = 0U;
          }

          if (1 > (int)id_data[0] - 1) {
            i30 = 0;
          } else {
            i30 = (int)id_data[0] - 1;
          }

          b_loop_ub = i30 - 1;
          for (i29 = 0; i29 <= b_loop_ub; i29++) {
            nextLineVar->data[i29] = mfInfo2->data[i29];
          }

          b_char(nextLineVar, r20);
          deblank(r20, r21);
          b_loop_ub = r21->size[1];
          if (b_loop_ub > maxMFNameLength) {
            maxMFNameLength = b_loop_ub;
          }

          i29 = mfInfo3->size[0] * mfInfo3->size[1];
          mfInfo3->size[0] = 1;
          mfInfo3->size[1] = loop_ub;
          emxEnsureCapacity_uint8_T(mfInfo3, i29);
          for (i29 = 0; i29 < loop_ub; i29++) {
            mfInfo3->data[i29] = 0U;
          }

          if (id_data[0] + 3U > (unsigned int)mfInfo2->size[1]) {
            i29 = 1;
            idx = 0;
          } else {
            i29 = (int)(id_data[0] + 3U);
            idx = mfInfo2->size[1];
          }

          b_loop_ub = idx - i29;
          for (idx = 0; idx <= b_loop_ub; idx++) {
            mfInfo3->data[idx] = mfInfo2->data[(i29 + idx) - 1];
          }

          i29 = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = mfInfo3->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i29);
          b_loop_ub = mfInfo3->size[0] * mfInfo3->size[1];
          for (i29 = 0; i29 < b_loop_ub; i29++) {
            bufferEqual->data[i29] = (mfInfo3->data[i29] == 39);
          }

          idx = 0;
          i29 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = 1;
          emxEnsureCapacity_int32_T(ii, i29);
          b_loop_ub = 0;
          exitg2 = false;
          while ((!exitg2) && (b_loop_ub <= bufferEqual->size[1] - 1)) {
            if (bufferEqual->data[b_loop_ub]) {
              idx = 1;
              ii->data[0] = b_loop_ub + 1;
              exitg2 = true;
            } else {
              b_loop_ub++;
            }
          }

          if (idx == 0) {
            ii->size[0] = 1;
            ii->size[1] = 0;
          }

          b_loop_ub = ii->size[0] * ii->size[1];
          for (i29 = 0; i29 < b_loop_ub; i29++) {
            id_data[i29] = (unsigned int)ii->data[i29];
          }

          i29 = nextLineVar->size[0] * nextLineVar->size[1];
          nextLineVar->size[0] = 1;
          nextLineVar->size[1] = loop_ub;
          emxEnsureCapacity_uint8_T(nextLineVar, i29);
          for (i29 = 0; i29 < loop_ub; i29++) {
            nextLineVar->data[i29] = 0U;
          }

          if (1 > (int)id_data[0] - 1) {
            i31 = 0;
          } else {
            i31 = (int)id_data[0] - 1;
          }

          b_loop_ub = i31 - 1;
          for (i29 = 0; i29 <= b_loop_ub; i29++) {
            nextLineVar->data[i29] = mfInfo3->data[i29];
          }

          b_char(nextLineVar, r20);
          deblank(r20, r21);
          b_loop_ub = r21->size[1];
          if (b_loop_ub > maxMFTypeLength) {
            maxMFTypeLength = b_loop_ub;
          }

          if (checkForSugenoMFs && (!*info_hasSugenoMFs)) {
            b_char(nextLineVar, r20);
            deblank(r20, r21);
            if (b_strcmp(r21) || c_strcmp(r21)) {
              *info_hasSugenoMFs = true;
            }
          }

          i29 = nextLineVar->size[0] * nextLineVar->size[1];
          nextLineVar->size[0] = 1;
          nextLineVar->size[1] = loop_ub;
          emxEnsureCapacity_uint8_T(nextLineVar, i29);
          for (i29 = 0; i29 < loop_ub; i29++) {
            nextLineVar->data[i29] = 0U;
          }

          if (id_data[0] + 3U > (unsigned int)mfInfo3->size[1]) {
            i29 = 1;
            idx = 0;
          } else {
            i29 = (int)(id_data[0] + 3U);
            idx = mfInfo3->size[1];
          }

          b_loop_ub = idx - i29;
          for (idx = 0; idx <= b_loop_ub; idx++) {
            nextLineVar->data[idx] = mfInfo3->data[(i29 + idx) - 1];
          }

          i29 = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i29);
          b_loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
          for (i29 = 0; i29 < b_loop_ub; i29++) {
            bufferEqual->data[i29] = (nextLineVar->data[i29] == 32);
          }

          nx = bufferEqual->size[1];
          idx = 0;
          i29 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = bufferEqual->size[1];
          emxEnsureCapacity_int32_T(ii, i29);
          b_loop_ub = 0;
          exitg2 = false;
          while ((!exitg2) && (b_loop_ub <= nx - 1)) {
            if (bufferEqual->data[b_loop_ub]) {
              idx++;
              ii->data[idx - 1] = b_loop_ub + 1;
              if (idx >= nx) {
                exitg2 = true;
              } else {
                b_loop_ub++;
              }
            } else {
              b_loop_ub++;
            }
          }

          if (bufferEqual->size[1] == 1) {
            if (idx == 0) {
              ii->size[0] = 1;
              ii->size[1] = 0;
            }
          } else if (1 > idx) {
            ii->size[1] = 0;
          } else {
            i29 = ii->size[0] * ii->size[1];
            ii->size[1] = idx;
            emxEnsureCapacity_int32_T(ii, i29);
          }

          b_loop_ub = ii->size[1];
          u1 = b_loop_ub + 1U;
          if (u1 > maxMFParamLength) {
            maxMFParamLength = u1;
          }
        }
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_char_T(&r21);
  emxFree_char_T(&r20);
  emxFree_int32_T(&ii);
  emxFree_uint8_T(&mfInfo3);
  emxFree_uint8_T(&mfInfo2);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&template);
  *info_maxInputNameLength = maxInputNameLength;
  *info_maxMFNameLength = maxMFNameLength;
  *info_maxMFTypeLength = maxMFTypeLength;
  *info_maxMFParamLength = maxMFParamLength;
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                emxArray_uint8_T *topicValue
 * Return Type  : void
 */
void c_findTopic(double fid, double maxLineLength, emxArray_uint8_T *topicValue)
{
  emxArray_uint8_T *buffer;
  int i11;
  int loop_ub;
  boolean_T topicFound;
  static const unsigned char uv8[10] = { 65U, 110U, 100U, 77U, 101U, 116U, 104U,
    111U, 100U, 61U };

  emxArray_uint8_T *nextLineVar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r10;
  emxArray_uint8_T *b_nextLineVar;
  boolean_T exitg1;
  FILE * b_NULL;
  FILE * filestar;
  int st;
  boolean_T y;
  boolean_T exitg2;
  int end;
  int i;
  int i12;
  emxInit_uint8_T(&buffer, 2);
  i11 = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  loop_ub = (int)maxLineLength;
  buffer->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(buffer, i11);
  for (i11 = 0; i11 < loop_ub; i11++) {
    buffer->data[i11] = 0U;
  }

  i11 = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(topicValue, i11);
  for (i11 = 0; i11 < loop_ub; i11++) {
    topicValue->data[i11] = 0U;
  }

  for (i11 = 0; i11 < 10; i11++) {
    buffer->data[i11] = uv8[i11];
  }

  topicFound = false;
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual, 2);
  emxInit_int32_T(&r10, 2);
  emxInit_uint8_T(&b_nextLineVar, 1);
  exitg1 = false;
  while ((!exitg1) && (!topicFound)) {
    getNextLine(fid, maxLineLength, nextLineVar);
    b_NULL = NULL;
    filestar = fileManager(fid);
    if (filestar == b_NULL) {
      i11 = 0;
    } else {
      st = feof(filestar);
      i11 = ((int)st != 0);
    }

    if (i11 != 0) {
      exitg1 = true;
    } else {
      i11 = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i11);
      loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
      for (i11 = 0; i11 < loop_ub; i11++) {
        bufferEqual->data[i11] = (nextLineVar->data[i11] == buffer->data[i11]);
      }

      y = true;
      loop_ub = -1;
      exitg2 = false;
      while ((!exitg2) && (loop_ub + 1 < 10)) {
        if (!bufferEqual->data[1 + loop_ub]) {
          y = false;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }

      if (y) {
        topicFound = true;
        xor(nextLineVar, buffer, bufferEqual);
        end = bufferEqual->size[1];
        loop_ub = 0;
        for (i = 0; i < end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        if (2.0 > (double)loop_ub - 1.0) {
          i11 = 0;
          i12 = 0;
        } else {
          i11 = 1;
          i12 = loop_ub - 1;
        }

        end = bufferEqual->size[1] - 1;
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        i = r10->size[0] * r10->size[1];
        r10->size[0] = 1;
        r10->size[1] = loop_ub;
        emxEnsureCapacity_int32_T(r10, i);
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            r10->data[loop_ub] = i + 1;
            loop_ub++;
          }
        }

        loop_ub = r10->size[1];
        i = b_nextLineVar->size[0];
        b_nextLineVar->size[0] = loop_ub;
        emxEnsureCapacity_uint8_T(b_nextLineVar, i);
        for (i = 0; i < loop_ub; i++) {
          b_nextLineVar->data[i] = nextLineVar->data[r10->data[i] - 1];
        }

        loop_ub = i12 - i11;
        for (i12 = 0; i12 < loop_ub; i12++) {
          topicValue->data[i12] = b_nextLineVar->data[i11 + i12];
        }
      }
    }
  }

  emxFree_uint8_T(&b_nextLineVar);
  emxFree_int32_T(&r10);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&buffer);
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                emxArray_uint8_T *topicValue
 * Return Type  : void
 */
void d_findTopic(double fid, double maxLineLength, emxArray_uint8_T *topicValue)
{
  emxArray_uint8_T *buffer;
  int i13;
  int loop_ub;
  boolean_T topicFound;
  static const unsigned char uv9[9] = { 79U, 114U, 77U, 101U, 116U, 104U, 111U,
    100U, 61U };

  emxArray_uint8_T *nextLineVar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r11;
  emxArray_uint8_T *b_nextLineVar;
  boolean_T exitg1;
  FILE * b_NULL;
  FILE * filestar;
  int st;
  boolean_T y;
  boolean_T exitg2;
  int end;
  int i;
  int i14;
  emxInit_uint8_T(&buffer, 2);
  i13 = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  loop_ub = (int)maxLineLength;
  buffer->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(buffer, i13);
  for (i13 = 0; i13 < loop_ub; i13++) {
    buffer->data[i13] = 0U;
  }

  i13 = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(topicValue, i13);
  for (i13 = 0; i13 < loop_ub; i13++) {
    topicValue->data[i13] = 0U;
  }

  for (i13 = 0; i13 < 9; i13++) {
    buffer->data[i13] = uv9[i13];
  }

  topicFound = false;
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual, 2);
  emxInit_int32_T(&r11, 2);
  emxInit_uint8_T(&b_nextLineVar, 1);
  exitg1 = false;
  while ((!exitg1) && (!topicFound)) {
    getNextLine(fid, maxLineLength, nextLineVar);
    b_NULL = NULL;
    filestar = fileManager(fid);
    if (filestar == b_NULL) {
      i13 = 0;
    } else {
      st = feof(filestar);
      i13 = ((int)st != 0);
    }

    if (i13 != 0) {
      exitg1 = true;
    } else {
      i13 = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i13);
      loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
      for (i13 = 0; i13 < loop_ub; i13++) {
        bufferEqual->data[i13] = (nextLineVar->data[i13] == buffer->data[i13]);
      }

      y = true;
      loop_ub = -1;
      exitg2 = false;
      while ((!exitg2) && (loop_ub + 1 < 9)) {
        if (!bufferEqual->data[1 + loop_ub]) {
          y = false;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }

      if (y) {
        topicFound = true;
        xor(nextLineVar, buffer, bufferEqual);
        end = bufferEqual->size[1];
        loop_ub = 0;
        for (i = 0; i < end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        if (2.0 > (double)loop_ub - 1.0) {
          i13 = 0;
          i14 = 0;
        } else {
          i13 = 1;
          i14 = loop_ub - 1;
        }

        end = bufferEqual->size[1] - 1;
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        i = r11->size[0] * r11->size[1];
        r11->size[0] = 1;
        r11->size[1] = loop_ub;
        emxEnsureCapacity_int32_T(r11, i);
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            r11->data[loop_ub] = i + 1;
            loop_ub++;
          }
        }

        loop_ub = r11->size[1];
        i = b_nextLineVar->size[0];
        b_nextLineVar->size[0] = loop_ub;
        emxEnsureCapacity_uint8_T(b_nextLineVar, i);
        for (i = 0; i < loop_ub; i++) {
          b_nextLineVar->data[i] = nextLineVar->data[r11->data[i] - 1];
        }

        loop_ub = i14 - i13;
        for (i14 = 0; i14 < loop_ub; i14++) {
          topicValue->data[i14] = b_nextLineVar->data[i13 + i14];
        }
      }
    }
  }

  emxFree_uint8_T(&b_nextLineVar);
  emxFree_int32_T(&r11);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&buffer);
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                emxArray_uint8_T *topicValue
 * Return Type  : void
 */
void e_findTopic(double fid, double maxLineLength, emxArray_uint8_T *topicValue)
{
  emxArray_uint8_T *buffer;
  int i15;
  int loop_ub;
  boolean_T topicFound;
  static const unsigned char uv10[10] = { 73U, 109U, 112U, 77U, 101U, 116U, 104U,
    111U, 100U, 61U };

  emxArray_uint8_T *nextLineVar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r12;
  emxArray_uint8_T *b_nextLineVar;
  boolean_T exitg1;
  FILE * b_NULL;
  FILE * filestar;
  int st;
  boolean_T y;
  boolean_T exitg2;
  int end;
  int i;
  int i16;
  emxInit_uint8_T(&buffer, 2);
  i15 = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  loop_ub = (int)maxLineLength;
  buffer->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(buffer, i15);
  for (i15 = 0; i15 < loop_ub; i15++) {
    buffer->data[i15] = 0U;
  }

  i15 = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(topicValue, i15);
  for (i15 = 0; i15 < loop_ub; i15++) {
    topicValue->data[i15] = 0U;
  }

  for (i15 = 0; i15 < 10; i15++) {
    buffer->data[i15] = uv10[i15];
  }

  topicFound = false;
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual, 2);
  emxInit_int32_T(&r12, 2);
  emxInit_uint8_T(&b_nextLineVar, 1);
  exitg1 = false;
  while ((!exitg1) && (!topicFound)) {
    getNextLine(fid, maxLineLength, nextLineVar);
    b_NULL = NULL;
    filestar = fileManager(fid);
    if (filestar == b_NULL) {
      i15 = 0;
    } else {
      st = feof(filestar);
      i15 = ((int)st != 0);
    }

    if (i15 != 0) {
      exitg1 = true;
    } else {
      i15 = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i15);
      loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
      for (i15 = 0; i15 < loop_ub; i15++) {
        bufferEqual->data[i15] = (nextLineVar->data[i15] == buffer->data[i15]);
      }

      y = true;
      loop_ub = -1;
      exitg2 = false;
      while ((!exitg2) && (loop_ub + 1 < 10)) {
        if (!bufferEqual->data[1 + loop_ub]) {
          y = false;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }

      if (y) {
        topicFound = true;
        xor(nextLineVar, buffer, bufferEqual);
        end = bufferEqual->size[1];
        loop_ub = 0;
        for (i = 0; i < end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        if (2.0 > (double)loop_ub - 1.0) {
          i15 = 0;
          i16 = 0;
        } else {
          i15 = 1;
          i16 = loop_ub - 1;
        }

        end = bufferEqual->size[1] - 1;
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        i = r12->size[0] * r12->size[1];
        r12->size[0] = 1;
        r12->size[1] = loop_ub;
        emxEnsureCapacity_int32_T(r12, i);
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            r12->data[loop_ub] = i + 1;
            loop_ub++;
          }
        }

        loop_ub = r12->size[1];
        i = b_nextLineVar->size[0];
        b_nextLineVar->size[0] = loop_ub;
        emxEnsureCapacity_uint8_T(b_nextLineVar, i);
        for (i = 0; i < loop_ub; i++) {
          b_nextLineVar->data[i] = nextLineVar->data[r12->data[i] - 1];
        }

        loop_ub = i16 - i15;
        for (i16 = 0; i16 < loop_ub; i16++) {
          topicValue->data[i16] = b_nextLineVar->data[i15 + i16];
        }
      }
    }
  }

  emxFree_uint8_T(&b_nextLineVar);
  emxFree_int32_T(&r12);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&buffer);
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                emxArray_uint8_T *topicValue
 * Return Type  : void
 */
void f_findTopic(double fid, double maxLineLength, emxArray_uint8_T *topicValue)
{
  emxArray_uint8_T *buffer;
  int i17;
  int loop_ub;
  boolean_T topicFound;
  static const unsigned char uv11[10] = { 65U, 103U, 103U, 77U, 101U, 116U, 104U,
    111U, 100U, 61U };

  emxArray_uint8_T *nextLineVar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r13;
  emxArray_uint8_T *b_nextLineVar;
  boolean_T exitg1;
  FILE * b_NULL;
  FILE * filestar;
  int st;
  boolean_T y;
  boolean_T exitg2;
  int end;
  int i;
  int i18;
  emxInit_uint8_T(&buffer, 2);
  i17 = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  loop_ub = (int)maxLineLength;
  buffer->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(buffer, i17);
  for (i17 = 0; i17 < loop_ub; i17++) {
    buffer->data[i17] = 0U;
  }

  i17 = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(topicValue, i17);
  for (i17 = 0; i17 < loop_ub; i17++) {
    topicValue->data[i17] = 0U;
  }

  for (i17 = 0; i17 < 10; i17++) {
    buffer->data[i17] = uv11[i17];
  }

  topicFound = false;
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual, 2);
  emxInit_int32_T(&r13, 2);
  emxInit_uint8_T(&b_nextLineVar, 1);
  exitg1 = false;
  while ((!exitg1) && (!topicFound)) {
    getNextLine(fid, maxLineLength, nextLineVar);
    b_NULL = NULL;
    filestar = fileManager(fid);
    if (filestar == b_NULL) {
      i17 = 0;
    } else {
      st = feof(filestar);
      i17 = ((int)st != 0);
    }

    if (i17 != 0) {
      exitg1 = true;
    } else {
      i17 = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i17);
      loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
      for (i17 = 0; i17 < loop_ub; i17++) {
        bufferEqual->data[i17] = (nextLineVar->data[i17] == buffer->data[i17]);
      }

      y = true;
      loop_ub = -1;
      exitg2 = false;
      while ((!exitg2) && (loop_ub + 1 < 10)) {
        if (!bufferEqual->data[1 + loop_ub]) {
          y = false;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }

      if (y) {
        topicFound = true;
        xor(nextLineVar, buffer, bufferEqual);
        end = bufferEqual->size[1];
        loop_ub = 0;
        for (i = 0; i < end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        if (2.0 > (double)loop_ub - 1.0) {
          i17 = 0;
          i18 = 0;
        } else {
          i17 = 1;
          i18 = loop_ub - 1;
        }

        end = bufferEqual->size[1] - 1;
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        i = r13->size[0] * r13->size[1];
        r13->size[0] = 1;
        r13->size[1] = loop_ub;
        emxEnsureCapacity_int32_T(r13, i);
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            r13->data[loop_ub] = i + 1;
            loop_ub++;
          }
        }

        loop_ub = r13->size[1];
        i = b_nextLineVar->size[0];
        b_nextLineVar->size[0] = loop_ub;
        emxEnsureCapacity_uint8_T(b_nextLineVar, i);
        for (i = 0; i < loop_ub; i++) {
          b_nextLineVar->data[i] = nextLineVar->data[r13->data[i] - 1];
        }

        loop_ub = i18 - i17;
        for (i18 = 0; i18 < loop_ub; i18++) {
          topicValue->data[i18] = b_nextLineVar->data[i17 + i18];
        }
      }
    }
  }

  emxFree_uint8_T(&b_nextLineVar);
  emxFree_int32_T(&r13);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&buffer);
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                emxArray_uint8_T *topicValue
 * Return Type  : void
 */
void findTopic(double fid, double maxLineLength, emxArray_uint8_T *topicValue)
{
  emxArray_uint8_T *buffer;
  int i6;
  int loop_ub;
  boolean_T topicFound;
  static const unsigned char uv6[5] = { 78U, 97U, 109U, 101U, 61U };

  emxArray_uint8_T *nextLineVar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r8;
  emxArray_uint8_T *b_nextLineVar;
  boolean_T exitg1;
  FILE * b_NULL;
  FILE * filestar;
  int st;
  boolean_T y;
  boolean_T exitg2;
  int end;
  int i;
  int i7;
  emxInit_uint8_T(&buffer, 2);
  i6 = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  loop_ub = (int)maxLineLength;
  buffer->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(buffer, i6);
  for (i6 = 0; i6 < loop_ub; i6++) {
    buffer->data[i6] = 0U;
  }

  i6 = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(topicValue, i6);
  for (i6 = 0; i6 < loop_ub; i6++) {
    topicValue->data[i6] = 0U;
  }

  for (i6 = 0; i6 < 5; i6++) {
    buffer->data[i6] = uv6[i6];
  }

  topicFound = false;
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual, 2);
  emxInit_int32_T(&r8, 2);
  emxInit_uint8_T(&b_nextLineVar, 1);
  exitg1 = false;
  while ((!exitg1) && (!topicFound)) {
    getNextLine(fid, maxLineLength, nextLineVar);
    b_NULL = NULL;
    filestar = fileManager(fid);
    if (filestar == b_NULL) {
      i6 = 0;
    } else {
      st = feof(filestar);
      i6 = ((int)st != 0);
    }

    if (i6 != 0) {
      exitg1 = true;
    } else {
      i6 = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i6);
      loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        bufferEqual->data[i6] = (nextLineVar->data[i6] == buffer->data[i6]);
      }

      y = true;
      loop_ub = 0;
      exitg2 = false;
      while ((!exitg2) && (loop_ub < 5)) {
        if (!bufferEqual->data[loop_ub]) {
          y = false;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }

      if (y) {
        topicFound = true;
        xor(nextLineVar, buffer, bufferEqual);
        end = bufferEqual->size[1];
        loop_ub = 0;
        for (i = 0; i < end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        if (2.0 > (double)loop_ub - 1.0) {
          i6 = 0;
          i7 = 0;
        } else {
          i6 = 1;
          i7 = loop_ub - 1;
        }

        end = bufferEqual->size[1] - 1;
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        i = r8->size[0] * r8->size[1];
        r8->size[0] = 1;
        r8->size[1] = loop_ub;
        emxEnsureCapacity_int32_T(r8, i);
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            r8->data[loop_ub] = i + 1;
            loop_ub++;
          }
        }

        loop_ub = r8->size[1];
        i = b_nextLineVar->size[0];
        b_nextLineVar->size[0] = loop_ub;
        emxEnsureCapacity_uint8_T(b_nextLineVar, i);
        for (i = 0; i < loop_ub; i++) {
          b_nextLineVar->data[i] = nextLineVar->data[r8->data[i] - 1];
        }

        loop_ub = i7 - i6;
        for (i7 = 0; i7 < loop_ub; i7++) {
          topicValue->data[i7] = b_nextLineVar->data[i6 + i7];
        }
      }
    }
  }

  emxFree_uint8_T(&b_nextLineVar);
  emxFree_int32_T(&r8);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&buffer);
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                emxArray_uint8_T *topicValue
 * Return Type  : void
 */
void g_findTopic(double fid, double maxLineLength, emxArray_uint8_T *topicValue)
{
  emxArray_uint8_T *buffer;
  int i19;
  int loop_ub;
  boolean_T topicFound;
  static const unsigned char uv12[13] = { 68U, 101U, 102U, 117U, 122U, 122U, 77U,
    101U, 116U, 104U, 111U, 100U, 61U };

  emxArray_uint8_T *nextLineVar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r14;
  emxArray_uint8_T *b_nextLineVar;
  boolean_T exitg1;
  FILE * b_NULL;
  FILE * filestar;
  int st;
  boolean_T y;
  boolean_T exitg2;
  int end;
  int i;
  int i20;
  emxInit_uint8_T(&buffer, 2);
  i19 = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  loop_ub = (int)maxLineLength;
  buffer->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(buffer, i19);
  for (i19 = 0; i19 < loop_ub; i19++) {
    buffer->data[i19] = 0U;
  }

  i19 = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(topicValue, i19);
  for (i19 = 0; i19 < loop_ub; i19++) {
    topicValue->data[i19] = 0U;
  }

  for (i19 = 0; i19 < 13; i19++) {
    buffer->data[i19] = uv12[i19];
  }

  topicFound = false;
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual, 2);
  emxInit_int32_T(&r14, 2);
  emxInit_uint8_T(&b_nextLineVar, 1);
  exitg1 = false;
  while ((!exitg1) && (!topicFound)) {
    getNextLine(fid, maxLineLength, nextLineVar);
    b_NULL = NULL;
    filestar = fileManager(fid);
    if (filestar == b_NULL) {
      i19 = 0;
    } else {
      st = feof(filestar);
      i19 = ((int)st != 0);
    }

    if (i19 != 0) {
      exitg1 = true;
    } else {
      i19 = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i19);
      loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
      for (i19 = 0; i19 < loop_ub; i19++) {
        bufferEqual->data[i19] = (nextLineVar->data[i19] == buffer->data[i19]);
      }

      y = true;
      loop_ub = -1;
      exitg2 = false;
      while ((!exitg2) && (loop_ub + 1 < 13)) {
        if (!bufferEqual->data[1 + loop_ub]) {
          y = false;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }

      if (y) {
        topicFound = true;
        xor(nextLineVar, buffer, bufferEqual);
        end = bufferEqual->size[1];
        loop_ub = 0;
        for (i = 0; i < end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        if (2.0 > (double)loop_ub - 1.0) {
          i19 = 0;
          i20 = 0;
        } else {
          i19 = 1;
          i20 = loop_ub - 1;
        }

        end = bufferEqual->size[1] - 1;
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            loop_ub++;
          }
        }

        i = r14->size[0] * r14->size[1];
        r14->size[0] = 1;
        r14->size[1] = loop_ub;
        emxEnsureCapacity_int32_T(r14, i);
        loop_ub = 0;
        for (i = 0; i <= end; i++) {
          if (bufferEqual->data[i]) {
            r14->data[loop_ub] = i + 1;
            loop_ub++;
          }
        }

        loop_ub = r14->size[1];
        i = b_nextLineVar->size[0];
        b_nextLineVar->size[0] = loop_ub;
        emxEnsureCapacity_uint8_T(b_nextLineVar, i);
        for (i = 0; i < loop_ub; i++) {
          b_nextLineVar->data[i] = nextLineVar->data[r14->data[i] - 1];
        }

        loop_ub = i20 - i19;
        for (i20 = 0; i20 < loop_ub; i20++) {
          topicValue->data[i20] = b_nextLineVar->data[i19 + i20];
        }
      }
    }
  }

  emxFree_uint8_T(&b_nextLineVar);
  emxFree_int32_T(&r14);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&buffer);
}

/*
 * Arguments    : double fid
 * Return Type  : double
 */
double getMaxLineLength(double fid)
{
  double maxLength;
  emxArray_uint8_T *At;
  size_t nBytes;
  FILE * filestar;
  int c;
  int numRead;
  int i2;
  int i3;
  size_t numReadSizeT;
  unsigned char tbuf[1024];
  emxInit_uint8_T(&At, 1);
  nBytes = sizeof(unsigned char);
  filestar = fileManager(fid);
  if ((fid != 0.0) && (fid != 1.0) && (fid != 2.0)) {
  } else {
    filestar = NULL;
  }

  At->size[0] = 0;
  if (!(filestar == NULL)) {
    c = 1;
    while (c > 0) {
      c = 0;
      numRead = 1;
      while ((c < 1024) && (numRead > 0)) {
        numReadSizeT = fread(&tbuf[c], nBytes, 1024 - c, filestar);
        numRead = (int)numReadSizeT;
        c += (int)numReadSizeT;
      }

      if (1 > c) {
        numRead = -1;
      } else {
        numRead = c - 1;
      }

      i2 = At->size[0];
      i3 = At->size[0];
      At->size[0] = (i2 + numRead) + 1;
      emxEnsureCapacity_uint8_T(At, i3);
      for (i3 = 0; i3 <= numRead; i3++) {
        At->data[i2 + i3] = tbuf[i3];
      }
    }
  }

  maxLength = 0.0;
  numRead = 0;
  i2 = At->size[0];
  for (c = 0; c < i2; c++) {
    if (At->data[c] == 10) {
      i3 = c - numRead;
      if (i3 > (int)maxLength) {
        maxLength = i3;
        numRead = c;
      }
    }
  }

  emxFree_uint8_T(&At);
  return maxLength;
}

/*
 * Arguments    : double fid
 *                double maxLength
 *                emxArray_uint8_T *result
 * Return Type  : void
 */
void getNextLine(double fid, double maxLength, emxArray_uint8_T *result)
{
  boolean_T exitg1;
  boolean_T b_bool;
  getLine(fid, maxLength, result);
  exitg1 = false;
  while ((!exitg1) && any(result)) {
    b_bool = false;
    if (!((signed char)result->data[0] != '%')) {
      b_bool = true;
    }

    if ((!b_bool) && (result->data[0] != 10)) {
      exitg1 = true;
    } else {
      getLine(fid, maxLength, result);
    }
  }
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                double numInputs
 *                double numOutputs
 *                b_emxArray_struct_T *rules
 * Return Type  : void
 */
void getRules(double fid, double maxLineLength, double numInputs, double
              numOutputs, b_emxArray_struct_T *rules)
{
  emxArray_int8_T *rule_antecedent;
  int i50;
  int startIndex;
  emxArray_int8_T *rule_consequent;
  b_struct_T expl_temp;
  double numRules;
  boolean_T topicFound;
  emxArray_uint8_T *nextLineVar;
  emxArray_uint8_T *ant;
  emxArray_real_T *con;
  emxArray_real_T *wt;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_char_T *r25;
  emxArray_char_T *r26;
  emxArray_real_T *b_con;
  int exitg2;
  double d3;
  int i;
  boolean_T exitg1;
  int idx;
  boolean_T exitg3;
  unsigned int id_data[1];
  int i51;
  int i52;
  unsigned int id2_data[1];
  int nx;
  creal_T dc4;
  int k;
  emxInit_int8_T(&rule_antecedent, 2);
  i50 = rule_antecedent->size[0] * rule_antecedent->size[1];
  rule_antecedent->size[0] = 1;
  startIndex = (int)numInputs;
  rule_antecedent->size[1] = startIndex;
  emxEnsureCapacity_int8_T(rule_antecedent, i50);
  for (i50 = 0; i50 < startIndex; i50++) {
    rule_antecedent->data[i50] = 0;
  }

  emxInit_int8_T(&rule_consequent, 2);
  i50 = rule_consequent->size[0] * rule_consequent->size[1];
  rule_consequent->size[0] = 1;
  startIndex = (int)numOutputs;
  rule_consequent->size[1] = startIndex;
  emxEnsureCapacity_int8_T(rule_consequent, i50);
  for (i50 = 0; i50 < startIndex; i50++) {
    rule_consequent->data[i50] = 0;
  }

  emxInitStruct_struct_T8(&expl_temp);
  numRules = getNumRules(fid, maxLineLength);
  expl_temp.connection = 0.0;
  expl_temp.weight = 0.0;
  i50 = expl_temp.consequent->size[0] * expl_temp.consequent->size[1];
  expl_temp.consequent->size[0] = 1;
  expl_temp.consequent->size[1] = rule_consequent->size[1];
  emxEnsureCapacity_real_T(expl_temp.consequent, i50);
  startIndex = rule_consequent->size[0] * rule_consequent->size[1];
  for (i50 = 0; i50 < startIndex; i50++) {
    expl_temp.consequent->data[i50] = rule_consequent->data[i50];
  }

  emxFree_int8_T(&rule_consequent);
  i50 = expl_temp.antecedent->size[0] * expl_temp.antecedent->size[1];
  expl_temp.antecedent->size[0] = 1;
  expl_temp.antecedent->size[1] = rule_antecedent->size[1];
  emxEnsureCapacity_real_T(expl_temp.antecedent, i50);
  startIndex = rule_antecedent->size[0] * rule_antecedent->size[1];
  for (i50 = 0; i50 < startIndex; i50++) {
    expl_temp.antecedent->data[i50] = rule_antecedent->data[i50];
  }

  emxFree_int8_T(&rule_antecedent);
  c_repmat(expl_temp, numRules, rules);
  emxFreeStruct_struct_T6(&expl_temp);
  if (!(numRules == 0.0)) {
    frewind(fid);
    topicFound = false;
    emxInit_uint8_T(&nextLineVar, 2);
    emxInit_uint8_T(&ant, 2);
    emxInit_real_T(&con, 2);
    emxInit_real_T(&wt, 2);
    emxInit_boolean_T(&x, 2);
    emxInit_int32_T(&ii, 2);
    emxInit_char_T(&r25, 2);
    emxInit_char_T(&r26, 2);
    emxInit_real_T(&b_con, 2);
    do {
      exitg2 = 0;
      if (!topicFound) {
        getNextLine(fid, maxLineLength, nextLineVar);
        d3 = b_feof(fid);
        if (d3 != 0.0) {
          exitg2 = 1;
        } else {
          b_char(nextLineVar, r25);
          deblank(r25, r26);
          if (d_strcmp(r26)) {
            topicFound = true;
            i = 0;
            exitg1 = false;
            while ((!exitg1) && (i <= (int)numRules - 1)) {
              getNextLine(fid, maxLineLength, nextLineVar);
              d3 = b_feof(fid);
              if (d3 != 0.0) {
                exitg1 = true;
              } else {
                i50 = x->size[0] * x->size[1];
                x->size[0] = 1;
                x->size[1] = nextLineVar->size[1];
                emxEnsureCapacity_boolean_T(x, i50);
                startIndex = nextLineVar->size[0] * nextLineVar->size[1];
                for (i50 = 0; i50 < startIndex; i50++) {
                  x->data[i50] = (nextLineVar->data[i50] == 44);
                }

                idx = 0;
                i50 = ii->size[0] * ii->size[1];
                ii->size[0] = 1;
                ii->size[1] = 1;
                emxEnsureCapacity_int32_T(ii, i50);
                startIndex = 0;
                exitg3 = false;
                while ((!exitg3) && (startIndex <= x->size[1] - 1)) {
                  if (x->data[startIndex]) {
                    idx = 1;
                    ii->data[0] = startIndex + 1;
                    exitg3 = true;
                  } else {
                    startIndex++;
                  }
                }

                if (idx == 0) {
                  ii->size[0] = 1;
                  ii->size[1] = 0;
                }

                startIndex = ii->size[0] * ii->size[1];
                for (i50 = 0; i50 < startIndex; i50++) {
                  id_data[i50] = (unsigned int)ii->data[i50];
                }

                i50 = ant->size[0] * ant->size[1];
                ant->size[0] = 1;
                startIndex = (int)id_data[0] - 1;
                ant->size[1] = startIndex;
                emxEnsureCapacity_uint8_T(ant, i50);
                for (i50 = 0; i50 < startIndex; i50++) {
                  ant->data[i50] = 0U;
                }

                if (1 > (int)id_data[0] - 1) {
                  i51 = 0;
                } else {
                  i51 = (int)id_data[0] - 1;
                }

                startIndex = i51 - 1;
                for (i50 = 0; i50 <= startIndex; i50++) {
                  ant->data[i50] = nextLineVar->data[i50];
                }

                startIndex = (int)id_data[0];
                i50 = ii->size[0] * ii->size[1];
                ii->size[0] = 1;
                i52 = (int)id_data[0] + 1;
                ii->size[1] = i52;
                emxEnsureCapacity_int32_T(ii, i50);
                for (i50 = 0; i50 <= startIndex; i50++) {
                  ii->data[i50] = i50;
                }

                startIndex = ii->size[0] * ii->size[1] - 1;
                for (i50 = 0; i50 <= startIndex; i50++) {
                  nextLineVar->data[ii->data[i50]] = 0U;
                }

                i50 = x->size[0] * x->size[1];
                x->size[0] = 1;
                x->size[1] = nextLineVar->size[1];
                emxEnsureCapacity_boolean_T(x, i50);
                startIndex = nextLineVar->size[0] * nextLineVar->size[1];
                for (i50 = 0; i50 < startIndex; i50++) {
                  x->data[i50] = (nextLineVar->data[i50] == 40);
                }

                idx = 0;
                i50 = ii->size[0] * ii->size[1];
                ii->size[0] = 1;
                ii->size[1] = 1;
                emxEnsureCapacity_int32_T(ii, i50);
                startIndex = 0;
                exitg3 = false;
                while ((!exitg3) && (startIndex <= x->size[1] - 1)) {
                  if (x->data[startIndex]) {
                    idx = 1;
                    ii->data[0] = startIndex + 1;
                    exitg3 = true;
                  } else {
                    startIndex++;
                  }
                }

                if (idx == 0) {
                  ii->size[0] = 1;
                  ii->size[1] = 0;
                }

                startIndex = ii->size[0] * ii->size[1];
                for (i50 = 0; i50 < startIndex; i50++) {
                  id2_data[i50] = (unsigned int)ii->data[i50];
                }

                i50 = con->size[0] * con->size[1];
                con->size[0] = 1;
                startIndex = (int)(((double)id2_data[0] - 1.0) - ((double)
                  id_data[0] + 2.0));
                con->size[1] = startIndex;
                emxEnsureCapacity_real_T(con, i50);
                for (i50 = 0; i50 < startIndex; i50++) {
                  con->data[i50] = 0.0;
                }

                if ((double)id_data[0] + 2.0 > (double)id2_data[0] - 2.0) {
                  i50 = 1;
                  nx = 0;
                } else {
                  i50 = (int)(id_data[0] + 2U);
                  nx = (int)id2_data[0] - 2;
                }

                startIndex = nx - i50;
                for (nx = 0; nx <= startIndex; nx++) {
                  con->data[nx] = nextLineVar->data[(i50 + nx) - 1];
                }

                if (id_data[0] + 2U > id2_data[0]) {
                  i52 = 0;
                  i50 = 0;
                } else {
                  i50 = (int)id2_data[0];
                }

                nx = ii->size[0] * ii->size[1];
                ii->size[0] = 1;
                startIndex = i50 - i52;
                ii->size[1] = startIndex;
                emxEnsureCapacity_int32_T(ii, nx);
                for (i50 = 0; i50 < startIndex; i50++) {
                  ii->data[i50] = i52 + i50;
                }

                startIndex = ii->size[0] * ii->size[1] - 1;
                for (i50 = 0; i50 <= startIndex; i50++) {
                  nextLineVar->data[ii->data[i50]] = 0U;
                }

                i50 = x->size[0] * x->size[1];
                x->size[0] = 1;
                x->size[1] = nextLineVar->size[1];
                emxEnsureCapacity_boolean_T(x, i50);
                startIndex = nextLineVar->size[0] * nextLineVar->size[1];
                for (i50 = 0; i50 < startIndex; i50++) {
                  x->data[i50] = (nextLineVar->data[i50] == 41);
                }

                idx = 0;
                i50 = ii->size[0] * ii->size[1];
                ii->size[0] = 1;
                ii->size[1] = 1;
                emxEnsureCapacity_int32_T(ii, i50);
                startIndex = 0;
                exitg3 = false;
                while ((!exitg3) && (startIndex <= x->size[1] - 1)) {
                  if (x->data[startIndex]) {
                    idx = 1;
                    ii->data[0] = startIndex + 1;
                    exitg3 = true;
                  } else {
                    startIndex++;
                  }
                }

                if (idx == 0) {
                  ii->size[0] = 1;
                  ii->size[1] = 0;
                }

                startIndex = ii->size[0] * ii->size[1];
                for (i50 = 0; i50 < startIndex; i50++) {
                  id_data[i50] = (unsigned int)ii->data[i50];
                }

                i50 = wt->size[0] * wt->size[1];
                wt->size[0] = 1;
                startIndex = ((int)id_data[0] - (int)id2_data[0]) - 1;
                wt->size[1] = startIndex;
                emxEnsureCapacity_real_T(wt, i50);
                for (i50 = 0; i50 < startIndex; i50++) {
                  wt->data[i50] = 0.0;
                }

                i50 = (int)id_data[0] - 1;
                if (id2_data[0] + 1U > (unsigned int)i50) {
                  i52 = 1;
                  i50 = 0;
                } else {
                  i52 = (int)(id2_data[0] + 1U);
                }

                startIndex = i50 - i52;
                for (i50 = 0; i50 <= startIndex; i50++) {
                  wt->data[i50] = nextLineVar->data[(i52 + i50) - 1];
                }

                c_char(wt, r25);
                dc4 = str2double(r25);
                rules->data[i].weight = dc4.re;
                dc4 = b_str2double((signed char)nextLineVar->data[(int)id_data[0]
                                   + 3]);
                rules->data[i].connection = dc4.re;
                i50 = x->size[0] * x->size[1];
                x->size[0] = 1;
                x->size[1] = ant->size[1];
                emxEnsureCapacity_boolean_T(x, i50);
                startIndex = ant->size[0] * ant->size[1];
                for (i50 = 0; i50 < startIndex; i50++) {
                  x->data[i50] = (ant->data[i50] == 32);
                }

                nx = x->size[1];
                idx = 0;
                i50 = ii->size[0] * ii->size[1];
                ii->size[0] = 1;
                ii->size[1] = x->size[1];
                emxEnsureCapacity_int32_T(ii, i50);
                startIndex = 0;
                exitg3 = false;
                while ((!exitg3) && (startIndex <= nx - 1)) {
                  if (x->data[startIndex]) {
                    idx++;
                    ii->data[idx - 1] = startIndex + 1;
                    if (idx >= nx) {
                      exitg3 = true;
                    } else {
                      startIndex++;
                    }
                  } else {
                    startIndex++;
                  }
                }

                if (x->size[1] == 1) {
                  if (idx == 0) {
                    ii->size[0] = 1;
                    ii->size[1] = 0;
                  }
                } else if (1 > idx) {
                  ii->size[1] = 0;
                } else {
                  i50 = ii->size[0] * ii->size[1];
                  ii->size[1] = idx;
                  emxEnsureCapacity_int32_T(ii, i50);
                }

                i50 = wt->size[0] * wt->size[1];
                wt->size[0] = 1;
                wt->size[1] = ii->size[1];
                emxEnsureCapacity_real_T(wt, i50);
                startIndex = ii->size[0] * ii->size[1];
                for (i50 = 0; i50 < startIndex; i50++) {
                  wt->data[i50] = ii->data[i50];
                }

                if (wt->size[1] == 0) {
                  validateAntecedentLength(fid, numInputs, 1.0);
                  b_char(ant, r25);
                  dc4 = str2double(r25);
                  rules->data[i].antecedent->data[0] = dc4.re;
                } else {
                  i50 = wt->size[1];
                  for (k = 0; k < i50; k++) {
                    if (1 + k == wt->size[1]) {
                      if (1 + k == 1) {
                        startIndex = 1;
                      } else {
                        startIndex = (int)wt->data[k - 1] + 1;
                      }

                      if (startIndex > (int)wt->data[k] - 1) {
                        i52 = 0;
                        nx = 0;
                      } else {
                        i52 = startIndex - 1;
                        nx = (int)wt->data[k] - 1;
                      }

                      idx = nextLineVar->size[0] * nextLineVar->size[1];
                      nextLineVar->size[0] = 1;
                      startIndex = nx - i52;
                      nextLineVar->size[1] = startIndex;
                      emxEnsureCapacity_uint8_T(nextLineVar, idx);
                      for (nx = 0; nx < startIndex; nx++) {
                        nextLineVar->data[nx] = ant->data[i52 + nx];
                      }

                      b_char(nextLineVar, r25);
                      dc4 = str2double(r25);
                      validateAntecedentLength(fid, numInputs, (1.0 + (double)k)
                        + 1.0);
                      rules->data[i].antecedent->data[k] = dc4.re;
                      if ((int)wt->data[k] + 1 > ant->size[1]) {
                        i52 = 1;
                        nx = 0;
                      } else {
                        i52 = (int)wt->data[k] + 1;
                        nx = ant->size[1];
                      }

                      idx = nextLineVar->size[0] * nextLineVar->size[1];
                      nextLineVar->size[0] = 1;
                      startIndex = (nx - i52) + 1;
                      nextLineVar->size[1] = startIndex;
                      emxEnsureCapacity_uint8_T(nextLineVar, idx);
                      for (nx = 0; nx < startIndex; nx++) {
                        nextLineVar->data[nx] = ant->data[(i52 + nx) - 1];
                      }

                      b_char(nextLineVar, r25);
                      deblank(r25, r26);
                      dc4 = str2double(r26);
                      rules->data[i].antecedent->data[k + 1] = dc4.re;
                    } else {
                      if (1 + k == 1) {
                        startIndex = 1;
                      } else {
                        startIndex = (int)wt->data[k - 1] + 1;
                      }

                      if (startIndex > (int)wt->data[k] - 1) {
                        i52 = 0;
                        nx = 0;
                      } else {
                        i52 = startIndex - 1;
                        nx = (int)wt->data[k] - 1;
                      }

                      idx = nextLineVar->size[0] * nextLineVar->size[1];
                      nextLineVar->size[0] = 1;
                      startIndex = nx - i52;
                      nextLineVar->size[1] = startIndex;
                      emxEnsureCapacity_uint8_T(nextLineVar, idx);
                      for (nx = 0; nx < startIndex; nx++) {
                        nextLineVar->data[nx] = ant->data[i52 + nx];
                      }

                      b_char(nextLineVar, r25);
                      dc4 = str2double(r25);
                      validateAntecedentLength(fid, numInputs, 1.0 + (double)k);
                      rules->data[i].antecedent->data[k] = dc4.re;
                    }
                  }
                }

                i50 = x->size[0] * x->size[1];
                x->size[0] = 1;
                x->size[1] = con->size[1];
                emxEnsureCapacity_boolean_T(x, i50);
                startIndex = con->size[0] * con->size[1];
                for (i50 = 0; i50 < startIndex; i50++) {
                  x->data[i50] = (con->data[i50] == 32.0);
                }

                nx = x->size[1];
                idx = 0;
                i50 = ii->size[0] * ii->size[1];
                ii->size[0] = 1;
                ii->size[1] = x->size[1];
                emxEnsureCapacity_int32_T(ii, i50);
                startIndex = 0;
                exitg3 = false;
                while ((!exitg3) && (startIndex <= nx - 1)) {
                  if (x->data[startIndex]) {
                    idx++;
                    ii->data[idx - 1] = startIndex + 1;
                    if (idx >= nx) {
                      exitg3 = true;
                    } else {
                      startIndex++;
                    }
                  } else {
                    startIndex++;
                  }
                }

                if (x->size[1] == 1) {
                  if (idx == 0) {
                    ii->size[0] = 1;
                    ii->size[1] = 0;
                  }
                } else if (1 > idx) {
                  ii->size[1] = 0;
                } else {
                  i50 = ii->size[0] * ii->size[1];
                  ii->size[1] = idx;
                  emxEnsureCapacity_int32_T(ii, i50);
                }

                i50 = wt->size[0] * wt->size[1];
                wt->size[0] = 1;
                wt->size[1] = ii->size[1];
                emxEnsureCapacity_real_T(wt, i50);
                startIndex = ii->size[0] * ii->size[1];
                for (i50 = 0; i50 < startIndex; i50++) {
                  wt->data[i50] = ii->data[i50];
                }

                if (wt->size[1] == 0) {
                  validateAntecedentLength(fid, numOutputs, 1.0);
                  c_char(con, r25);
                  dc4 = str2double(r25);
                  rules->data[i].consequent->data[0] = dc4.re;
                } else {
                  i50 = wt->size[1];
                  for (k = 0; k < i50; k++) {
                    if (1 + k == wt->size[1]) {
                      if (1 + k == 1) {
                        startIndex = 1;
                      } else {
                        startIndex = (int)wt->data[k - 1] + 1;
                      }

                      if (startIndex > (int)wt->data[k] - 1) {
                        i52 = 0;
                        nx = 0;
                      } else {
                        i52 = startIndex - 1;
                        nx = (int)wt->data[k] - 1;
                      }

                      idx = b_con->size[0] * b_con->size[1];
                      b_con->size[0] = 1;
                      startIndex = nx - i52;
                      b_con->size[1] = startIndex;
                      emxEnsureCapacity_real_T(b_con, idx);
                      for (nx = 0; nx < startIndex; nx++) {
                        b_con->data[nx] = (unsigned char)con->data[i52 + nx];
                      }

                      c_char(b_con, r25);
                      dc4 = str2double(r25);
                      validateAntecedentLength(fid, numOutputs, (1.0 + (double)k)
                        + 1.0);
                      rules->data[i].consequent->data[k] = dc4.re;
                      if ((int)wt->data[k] + 1 > con->size[1]) {
                        i52 = 1;
                        nx = 0;
                      } else {
                        i52 = (int)wt->data[k] + 1;
                        nx = con->size[1];
                      }

                      idx = b_con->size[0] * b_con->size[1];
                      b_con->size[0] = 1;
                      startIndex = (nx - i52) + 1;
                      b_con->size[1] = startIndex;
                      emxEnsureCapacity_real_T(b_con, idx);
                      for (nx = 0; nx < startIndex; nx++) {
                        b_con->data[nx] = (unsigned char)con->data[(i52 + nx) -
                          1];
                      }

                      c_char(b_con, r25);
                      deblank(r25, r26);
                      dc4 = str2double(r26);
                      rules->data[i].consequent->data[k + 1] = dc4.re;
                    } else {
                      if (1 + k == 1) {
                        startIndex = 1;
                      } else {
                        startIndex = (int)wt->data[k - 1] + 1;
                      }

                      if (startIndex > (int)wt->data[k] - 1) {
                        i52 = 0;
                        nx = 0;
                      } else {
                        i52 = startIndex - 1;
                        nx = (int)wt->data[k] - 1;
                      }

                      idx = b_con->size[0] * b_con->size[1];
                      b_con->size[0] = 1;
                      startIndex = nx - i52;
                      b_con->size[1] = startIndex;
                      emxEnsureCapacity_real_T(b_con, idx);
                      for (nx = 0; nx < startIndex; nx++) {
                        b_con->data[nx] = (unsigned char)con->data[i52 + nx];
                      }

                      c_char(b_con, r25);
                      dc4 = str2double(r25);
                      validateAntecedentLength(fid, numOutputs, 1.0 + (double)k);
                      rules->data[i].consequent->data[k] = dc4.re;
                    }
                  }
                }

                i++;
              }
            }
          }
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    emxFree_real_T(&b_con);
    emxFree_char_T(&r26);
    emxFree_char_T(&r25);
    emxFree_int32_T(&ii);
    emxFree_boolean_T(&x);
    emxFree_real_T(&wt);
    emxFree_real_T(&con);
    emxFree_uint8_T(&ant);
    emxFree_uint8_T(&nextLineVar);
  }
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
 *                h_emxArray_struct_T *var
 * Return Type  : void
 */
void getVar(double fid, double maxLineLength, double info_maxInputNameLength,
            double info_maxNumMF, double info_maxMFNameLength, double
            info_maxMFTypeLength, double info_maxMFParamLength, double
            info_numVars, h_emxArray_struct_T *var)
{
  emxArray_real_T *r22;
  int i32;
  int loop_ub;
  emxArray_char_T *mfTemplate_name;
  emxArray_char_T *mfTemplate_type;
  emxArray_int8_T *mfTemplate_params;
  emxArray_char_T *varTemplate_name;
  struct_T expl_temp;
  emxArray_struct_T *varTemplate_mf;
  h_struct_T b_expl_temp;
  emxArray_uint8_T *template;
  emxArray_uint8_T *nextLineVar;
  emxArray_boolean_T *bufferEqual;
  emxArray_uint8_T *mfInfo2;
  emxArray_uint8_T *mfInfo3;
  emxArray_uint32_T *ids;
  emxArray_int32_T *ii;
  emxArray_uint8_T *b_nextLineVar;
  int i;
  int i33;
  boolean_T topicFound;
  static const unsigned char uv16[6] = { 91U, 73U, 110U, 112U, 117U, 116U };

  boolean_T exitg1;
  double d1;
  int b_loop_ub;
  int idx;
  boolean_T exitg2;
  unsigned int idR_data[1];
  creal_T dc2;
  int i34;
  int j;
  int i35;
  int i36;
  int nx;
  unsigned int startIndex;
  int i37;
  int i38;
  emxInit_real_T(&r22, 2);
  i32 = r22->size[0] * r22->size[1];
  r22->size[0] = 1;
  loop_ub = (int)info_maxMFNameLength;
  r22->size[1] = loop_ub;
  emxEnsureCapacity_real_T(r22, i32);
  for (i32 = 0; i32 < loop_ub; i32++) {
    r22->data[i32] = 0.0;
  }

  emxInit_char_T(&mfTemplate_name, 2);
  c_char(r22, mfTemplate_name);
  i32 = r22->size[0] * r22->size[1];
  r22->size[0] = 1;
  loop_ub = (int)info_maxMFTypeLength;
  r22->size[1] = loop_ub;
  emxEnsureCapacity_real_T(r22, i32);
  for (i32 = 0; i32 < loop_ub; i32++) {
    r22->data[i32] = 0.0;
  }

  emxInit_char_T(&mfTemplate_type, 2);
  emxInit_int8_T(&mfTemplate_params, 2);
  c_char(r22, mfTemplate_type);
  i32 = mfTemplate_params->size[0] * mfTemplate_params->size[1];
  mfTemplate_params->size[0] = 1;
  loop_ub = (int)info_maxMFParamLength;
  mfTemplate_params->size[1] = loop_ub;
  emxEnsureCapacity_int8_T(mfTemplate_params, i32);
  for (i32 = 0; i32 < loop_ub; i32++) {
    mfTemplate_params->data[i32] = 0;
  }

  i32 = r22->size[0] * r22->size[1];
  r22->size[0] = 1;
  loop_ub = (int)info_maxInputNameLength;
  r22->size[1] = loop_ub;
  emxEnsureCapacity_real_T(r22, i32);
  for (i32 = 0; i32 < loop_ub; i32++) {
    r22->data[i32] = 0.0;
  }

  emxInit_char_T(&varTemplate_name, 2);
  c_char(r22, varTemplate_name);
  emxFree_real_T(&r22);
  emxInitStruct_struct_T6(&expl_temp);
  expl_temp.origParamLength = 0.0;
  i32 = expl_temp.params->size[0] * expl_temp.params->size[1];
  expl_temp.params->size[0] = 1;
  expl_temp.params->size[1] = mfTemplate_params->size[1];
  emxEnsureCapacity_real_T(expl_temp.params, i32);
  loop_ub = mfTemplate_params->size[0] * mfTemplate_params->size[1];
  for (i32 = 0; i32 < loop_ub; i32++) {
    expl_temp.params->data[i32] = mfTemplate_params->data[i32];
  }

  emxFree_int8_T(&mfTemplate_params);
  expl_temp.origTypeLength = 0.0;
  i32 = expl_temp.type->size[0] * expl_temp.type->size[1];
  expl_temp.type->size[0] = 1;
  expl_temp.type->size[1] = mfTemplate_type->size[1];
  emxEnsureCapacity_char_T(expl_temp.type, i32);
  loop_ub = mfTemplate_type->size[0] * mfTemplate_type->size[1];
  for (i32 = 0; i32 < loop_ub; i32++) {
    expl_temp.type->data[i32] = mfTemplate_type->data[i32];
  }

  expl_temp.origNameLength = 0.0;
  i32 = expl_temp.name->size[0] * expl_temp.name->size[1];
  expl_temp.name->size[0] = 1;
  expl_temp.name->size[1] = mfTemplate_name->size[1];
  emxEnsureCapacity_char_T(expl_temp.name, i32);
  loop_ub = mfTemplate_name->size[0] * mfTemplate_name->size[1];
  for (i32 = 0; i32 < loop_ub; i32++) {
    expl_temp.name->data[i32] = mfTemplate_name->data[i32];
  }

  emxInit_struct_T6(&varTemplate_mf, 2);
  emxInitStruct_struct_T7(&b_expl_temp);
  repmat(expl_temp, info_maxNumMF, varTemplate_mf);
  b_expl_temp.origNumMF = 0.0;
  i32 = b_expl_temp.mf->size[0] * b_expl_temp.mf->size[1];
  b_expl_temp.mf->size[0] = 1;
  b_expl_temp.mf->size[1] = varTemplate_mf->size[1];
  emxEnsureCapacity_struct_T4(b_expl_temp.mf, i32);
  loop_ub = varTemplate_mf->size[0] * varTemplate_mf->size[1];
  emxFreeStruct_struct_T5(&expl_temp);
  for (i32 = 0; i32 < loop_ub; i32++) {
    emxCopyStruct_struct_T4(&b_expl_temp.mf->data[i32], &varTemplate_mf->
      data[i32]);
  }

  emxFree_struct_T3(&varTemplate_mf);
  b_expl_temp.range[0] = 0.0;
  b_expl_temp.range[1] = 0.0;
  b_expl_temp.origNameLength = 0.0;
  i32 = b_expl_temp.name->size[0] * b_expl_temp.name->size[1];
  b_expl_temp.name->size[0] = 1;
  b_expl_temp.name->size[1] = varTemplate_name->size[1];
  emxEnsureCapacity_char_T(b_expl_temp.name, i32);
  loop_ub = varTemplate_name->size[0] * varTemplate_name->size[1];
  for (i32 = 0; i32 < loop_ub; i32++) {
    b_expl_temp.name->data[i32] = varTemplate_name->data[i32];
  }

  emxFree_char_T(&varTemplate_name);
  b_repmat(b_expl_temp, info_numVars, var);
  i32 = (int)info_numVars;
  emxFreeStruct_struct_T4(&b_expl_temp);
  emxInit_uint8_T(&template, 2);
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual, 2);
  emxInit_uint8_T(&mfInfo2, 2);
  emxInit_uint8_T(&mfInfo3, 2);
  emxInit_uint32_T(&ids, 2);
  emxInit_int32_T(&ii, 2);
  emxInit_uint8_T(&b_nextLineVar, 2);
  for (i = 0; i < i32; i++) {
    i33 = template->size[0] * template->size[1];
    template->size[0] = 1;
    loop_ub = (int)maxLineLength;
    template->size[1] = loop_ub;
    emxEnsureCapacity_uint8_T(template, i33);
    for (i33 = 0; i33 < loop_ub; i33++) {
      template->data[i33] = 0U;
    }

    for (i33 = 0; i33 < 6; i33++) {
      template->data[i33] = uv16[i33];
    }

    topicFound = false;
    exitg1 = false;
    while ((!exitg1) && (!topicFound)) {
      getNextLine(fid, maxLineLength, nextLineVar);
      d1 = b_feof(fid);
      if (d1 != 0.0) {
        exitg1 = true;
      } else {
        i33 = bufferEqual->size[0] * bufferEqual->size[1];
        bufferEqual->size[0] = 1;
        bufferEqual->size[1] = nextLineVar->size[1];
        emxEnsureCapacity_boolean_T(bufferEqual, i33);
        b_loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
        for (i33 = 0; i33 < b_loop_ub; i33++) {
          bufferEqual->data[i33] = (nextLineVar->data[i33] == template->data[i33]);
        }

        if (all(*(boolean_T (*)[6])&bufferEqual->data[0])) {
          topicFound = true;
          findTopic(fid, maxLineLength, nextLineVar);
          if (1.0 > info_maxInputNameLength) {
            b_loop_ub = -1;
          } else {
            b_loop_ub = (int)info_maxInputNameLength - 1;
          }

          for (i33 = 0; i33 <= b_loop_ub; i33++) {
            var->data[i].name->data[i33] = (signed char)nextLineVar->data[i33];
          }

          deblank(var->data[i].name, mfTemplate_name);
          var->data[i].origNameLength = mfTemplate_name->size[1];
          j_findTopic(fid, maxLineLength, nextLineVar);
          i33 = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i33);
          b_loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
          for (i33 = 0; i33 < b_loop_ub; i33++) {
            bufferEqual->data[i33] = (nextLineVar->data[i33] == 32);
          }

          idx = 0;
          i33 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = 1;
          emxEnsureCapacity_int32_T(ii, i33);
          b_loop_ub = 0;
          exitg2 = false;
          while ((!exitg2) && (b_loop_ub <= bufferEqual->size[1] - 1)) {
            if (bufferEqual->data[b_loop_ub]) {
              idx = 1;
              ii->data[0] = b_loop_ub + 1;
              exitg2 = true;
            } else {
              b_loop_ub++;
            }
          }

          if (idx == 0) {
            ii->size[0] = 1;
            ii->size[1] = 0;
          }

          b_loop_ub = ii->size[0] * ii->size[1];
          for (i33 = 0; i33 < b_loop_ub; i33++) {
            idR_data[i33] = (unsigned int)ii->data[i33];
          }

          if (1 > (int)idR_data[0] - 1) {
            b_loop_ub = 0;
          } else {
            b_loop_ub = (int)idR_data[0] - 1;
          }

          i33 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
          b_nextLineVar->size[0] = 1;
          b_nextLineVar->size[1] = b_loop_ub;
          emxEnsureCapacity_uint8_T(b_nextLineVar, i33);
          for (i33 = 0; i33 < b_loop_ub; i33++) {
            b_nextLineVar->data[i33] = nextLineVar->data[i33];
          }

          b_char(b_nextLineVar, mfTemplate_name);
          deblank(mfTemplate_name, mfTemplate_type);
          dc2 = str2double(mfTemplate_type);
          var->data[i].range[0] = dc2.re;
          if (idR_data[0] + 1U > (unsigned int)nextLineVar->size[1]) {
            i33 = 0;
            i34 = 0;
          } else {
            i33 = (int)idR_data[0];
            i34 = nextLineVar->size[1];
          }

          idx = b_nextLineVar->size[0] * b_nextLineVar->size[1];
          b_nextLineVar->size[0] = 1;
          b_loop_ub = i34 - i33;
          b_nextLineVar->size[1] = b_loop_ub;
          emxEnsureCapacity_uint8_T(b_nextLineVar, idx);
          for (i34 = 0; i34 < b_loop_ub; i34++) {
            b_nextLineVar->data[i34] = nextLineVar->data[i33 + i34];
          }

          b_char(b_nextLineVar, mfTemplate_name);
          deblank(mfTemplate_name, mfTemplate_type);
          dc2 = str2double(mfTemplate_type);
          var->data[i].range[1] = dc2.re;
          h_findTopic(fid, maxLineLength, nextLineVar);
          b_char(nextLineVar, mfTemplate_name);
          deblank(mfTemplate_name, mfTemplate_type);
          dc2 = str2double(mfTemplate_type);
          var->data[i].origNumMF = dc2.re;
          i33 = (int)dc2.re;
          for (j = 0; j < i33; j++) {
            i_findTopic(fid, maxLineLength, nextLineVar);
            i34 = mfInfo2->size[0] * mfInfo2->size[1];
            mfInfo2->size[0] = 1;
            mfInfo2->size[1] = loop_ub;
            emxEnsureCapacity_uint8_T(mfInfo2, i34);
            for (i34 = 0; i34 < loop_ub; i34++) {
              mfInfo2->data[i34] = 0U;
            }

            b_loop_ub = nextLineVar->size[1] - 3;
            for (i34 = 0; i34 <= b_loop_ub; i34++) {
              mfInfo2->data[i34] = nextLineVar->data[2 + i34];
            }

            i34 = bufferEqual->size[0] * bufferEqual->size[1];
            bufferEqual->size[0] = 1;
            bufferEqual->size[1] = mfInfo2->size[1];
            emxEnsureCapacity_boolean_T(bufferEqual, i34);
            b_loop_ub = mfInfo2->size[0] * mfInfo2->size[1];
            for (i34 = 0; i34 < b_loop_ub; i34++) {
              bufferEqual->data[i34] = (mfInfo2->data[i34] == 39);
            }

            idx = 0;
            i34 = ii->size[0] * ii->size[1];
            ii->size[0] = 1;
            ii->size[1] = 1;
            emxEnsureCapacity_int32_T(ii, i34);
            b_loop_ub = 0;
            exitg2 = false;
            while ((!exitg2) && (b_loop_ub <= bufferEqual->size[1] - 1)) {
              if (bufferEqual->data[b_loop_ub]) {
                idx = 1;
                ii->data[0] = b_loop_ub + 1;
                exitg2 = true;
              } else {
                b_loop_ub++;
              }
            }

            if (idx == 0) {
              ii->size[0] = 1;
              ii->size[1] = 0;
            }

            b_loop_ub = ii->size[0] * ii->size[1];
            for (i34 = 0; i34 < b_loop_ub; i34++) {
              idR_data[i34] = (unsigned int)ii->data[i34];
            }

            i34 = nextLineVar->size[0] * nextLineVar->size[1];
            nextLineVar->size[0] = 1;
            nextLineVar->size[1] = loop_ub;
            emxEnsureCapacity_uint8_T(nextLineVar, i34);
            for (i34 = 0; i34 < loop_ub; i34++) {
              nextLineVar->data[i34] = 0U;
            }

            if (1 > (int)idR_data[0] - 1) {
              i35 = 0;
            } else {
              i35 = (int)idR_data[0] - 1;
            }

            b_loop_ub = i35 - 1;
            for (i34 = 0; i34 <= b_loop_ub; i34++) {
              nextLineVar->data[i34] = mfInfo2->data[i34];
            }

            if (1.0 > info_maxMFNameLength) {
              b_loop_ub = -1;
            } else {
              b_loop_ub = (int)info_maxMFNameLength - 1;
            }

            for (i34 = 0; i34 <= b_loop_ub; i34++) {
              var->data[i].mf->data[j].name->data[i34] = (signed char)
                nextLineVar->data[i34];
            }

            deblank(var->data[i].mf->data[j].name, mfTemplate_name);
            var->data[i].mf->data[j].origNameLength = mfTemplate_name->size[1];
            i34 = mfInfo3->size[0] * mfInfo3->size[1];
            mfInfo3->size[0] = 1;
            mfInfo3->size[1] = loop_ub;
            emxEnsureCapacity_uint8_T(mfInfo3, i34);
            for (i34 = 0; i34 < loop_ub; i34++) {
              mfInfo3->data[i34] = 0U;
            }

            if (idR_data[0] + 3U > (unsigned int)mfInfo2->size[1]) {
              i34 = 1;
              idx = 0;
            } else {
              i34 = (int)(idR_data[0] + 3U);
              idx = mfInfo2->size[1];
            }

            b_loop_ub = idx - i34;
            for (idx = 0; idx <= b_loop_ub; idx++) {
              mfInfo3->data[idx] = mfInfo2->data[(i34 + idx) - 1];
            }

            i34 = bufferEqual->size[0] * bufferEqual->size[1];
            bufferEqual->size[0] = 1;
            bufferEqual->size[1] = mfInfo3->size[1];
            emxEnsureCapacity_boolean_T(bufferEqual, i34);
            b_loop_ub = mfInfo3->size[0] * mfInfo3->size[1];
            for (i34 = 0; i34 < b_loop_ub; i34++) {
              bufferEqual->data[i34] = (mfInfo3->data[i34] == 39);
            }

            idx = 0;
            i34 = ii->size[0] * ii->size[1];
            ii->size[0] = 1;
            ii->size[1] = 1;
            emxEnsureCapacity_int32_T(ii, i34);
            b_loop_ub = 0;
            exitg2 = false;
            while ((!exitg2) && (b_loop_ub <= bufferEqual->size[1] - 1)) {
              if (bufferEqual->data[b_loop_ub]) {
                idx = 1;
                ii->data[0] = b_loop_ub + 1;
                exitg2 = true;
              } else {
                b_loop_ub++;
              }
            }

            if (idx == 0) {
              ii->size[0] = 1;
              ii->size[1] = 0;
            }

            b_loop_ub = ii->size[0] * ii->size[1];
            for (i34 = 0; i34 < b_loop_ub; i34++) {
              idR_data[i34] = (unsigned int)ii->data[i34];
            }

            i34 = nextLineVar->size[0] * nextLineVar->size[1];
            nextLineVar->size[0] = 1;
            nextLineVar->size[1] = loop_ub;
            emxEnsureCapacity_uint8_T(nextLineVar, i34);
            for (i34 = 0; i34 < loop_ub; i34++) {
              nextLineVar->data[i34] = 0U;
            }

            if (1 > (int)idR_data[0] - 1) {
              i36 = 0;
            } else {
              i36 = (int)idR_data[0] - 1;
            }

            b_loop_ub = i36 - 1;
            for (i34 = 0; i34 <= b_loop_ub; i34++) {
              nextLineVar->data[i34] = mfInfo3->data[i34];
            }

            if (1.0 > info_maxMFTypeLength) {
              b_loop_ub = -1;
            } else {
              b_loop_ub = (int)info_maxMFTypeLength - 1;
            }

            for (i34 = 0; i34 <= b_loop_ub; i34++) {
              var->data[i].mf->data[j].type->data[i34] = (signed char)
                nextLineVar->data[i34];
            }

            deblank(var->data[i].mf->data[j].type, mfTemplate_name);
            var->data[i].mf->data[j].origTypeLength = mfTemplate_name->size[1];
            i34 = nextLineVar->size[0] * nextLineVar->size[1];
            nextLineVar->size[0] = 1;
            nextLineVar->size[1] = loop_ub;
            emxEnsureCapacity_uint8_T(nextLineVar, i34);
            for (i34 = 0; i34 < loop_ub; i34++) {
              nextLineVar->data[i34] = 0U;
            }

            if (idR_data[0] + 3U > (unsigned int)mfInfo3->size[1]) {
              i34 = 1;
              idx = 0;
            } else {
              i34 = (int)(idR_data[0] + 3U);
              idx = mfInfo3->size[1];
            }

            b_loop_ub = idx - i34;
            for (idx = 0; idx <= b_loop_ub; idx++) {
              nextLineVar->data[idx] = mfInfo3->data[(i34 + idx) - 1];
            }

            i34 = bufferEqual->size[0] * bufferEqual->size[1];
            bufferEqual->size[0] = 1;
            bufferEqual->size[1] = nextLineVar->size[1];
            emxEnsureCapacity_boolean_T(bufferEqual, i34);
            b_loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
            for (i34 = 0; i34 < b_loop_ub; i34++) {
              bufferEqual->data[i34] = (nextLineVar->data[i34] == 32);
            }

            nx = bufferEqual->size[1];
            idx = 0;
            i34 = ii->size[0] * ii->size[1];
            ii->size[0] = 1;
            ii->size[1] = bufferEqual->size[1];
            emxEnsureCapacity_int32_T(ii, i34);
            b_loop_ub = 0;
            exitg2 = false;
            while ((!exitg2) && (b_loop_ub <= nx - 1)) {
              if (bufferEqual->data[b_loop_ub]) {
                idx++;
                ii->data[idx - 1] = b_loop_ub + 1;
                if (idx >= nx) {
                  exitg2 = true;
                } else {
                  b_loop_ub++;
                }
              } else {
                b_loop_ub++;
              }
            }

            if (bufferEqual->size[1] == 1) {
              if (idx == 0) {
                ii->size[0] = 1;
                ii->size[1] = 0;
              }
            } else if (1 > idx) {
              ii->size[1] = 0;
            } else {
              i34 = ii->size[0] * ii->size[1];
              ii->size[1] = idx;
              emxEnsureCapacity_int32_T(ii, i34);
            }

            i34 = ids->size[0] * ids->size[1];
            ids->size[0] = 1;
            ids->size[1] = ii->size[1];
            emxEnsureCapacity_uint32_T(ids, i34);
            b_loop_ub = ii->size[0] * ii->size[1];
            for (i34 = 0; i34 < b_loop_ub; i34++) {
              ids->data[i34] = (unsigned int)ii->data[i34];
            }

            i34 = ids->size[1];
            for (nx = 0; nx < i34; nx++) {
              if (1 + nx == ids->size[1]) {
                if (1 + nx == 1) {
                  startIndex = 1U;
                } else {
                  startIndex = ids->data[nx - 1] + 1U;
                }

                if (startIndex > (unsigned int)((int)ids->data[nx] - 1)) {
                  idx = 0;
                  i37 = 0;
                } else {
                  idx = (int)startIndex - 1;
                  i37 = (int)ids->data[nx] - 1;
                }

                i38 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
                b_nextLineVar->size[0] = 1;
                b_loop_ub = i37 - idx;
                b_nextLineVar->size[1] = b_loop_ub;
                emxEnsureCapacity_uint8_T(b_nextLineVar, i38);
                for (i37 = 0; i37 < b_loop_ub; i37++) {
                  b_nextLineVar->data[i37] = nextLineVar->data[idx + i37];
                }

                b_char(b_nextLineVar, mfTemplate_name);
                dc2 = str2double(mfTemplate_name);
                var->data[i].mf->data[j].params->data[nx] = dc2.re;
                if (ids->data[nx] + 1U > (unsigned int)nextLineVar->size[1]) {
                  idx = 0;
                  i37 = 0;
                } else {
                  idx = (int)ids->data[nx];
                  i37 = nextLineVar->size[1];
                }

                i38 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
                b_nextLineVar->size[0] = 1;
                b_loop_ub = i37 - idx;
                b_nextLineVar->size[1] = b_loop_ub;
                emxEnsureCapacity_uint8_T(b_nextLineVar, i38);
                for (i37 = 0; i37 < b_loop_ub; i37++) {
                  b_nextLineVar->data[i37] = nextLineVar->data[idx + i37];
                }

                b_char(b_nextLineVar, mfTemplate_name);
                deblank(mfTemplate_name, mfTemplate_type);
                dc2 = str2double(mfTemplate_type);
                var->data[i].mf->data[j].params->data[nx + 1] = dc2.re;
              } else {
                if (1 + nx == 1) {
                  startIndex = 1U;
                } else {
                  startIndex = ids->data[nx - 1] + 1U;
                }

                if (startIndex > (unsigned int)((int)ids->data[nx] - 1)) {
                  idx = 0;
                  i37 = 0;
                } else {
                  idx = (int)startIndex - 1;
                  i37 = (int)ids->data[nx] - 1;
                }

                i38 = b_nextLineVar->size[0] * b_nextLineVar->size[1];
                b_nextLineVar->size[0] = 1;
                b_loop_ub = i37 - idx;
                b_nextLineVar->size[1] = b_loop_ub;
                emxEnsureCapacity_uint8_T(b_nextLineVar, i38);
                for (i37 = 0; i37 < b_loop_ub; i37++) {
                  b_nextLineVar->data[i37] = nextLineVar->data[idx + i37];
                }

                b_char(b_nextLineVar, mfTemplate_name);
                dc2 = str2double(mfTemplate_name);
                var->data[i].mf->data[j].params->data[nx] = dc2.re;
              }
            }

            var->data[i].mf->data[j].origParamLength = (double)ids->size[1] +
              1.0;
          }
        }
      }
    }
  }

  emxFree_uint8_T(&b_nextLineVar);
  emxFree_int32_T(&ii);
  emxFree_uint32_T(&ids);
  emxFree_uint8_T(&mfInfo3);
  emxFree_uint8_T(&mfInfo2);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&template);
  emxFree_char_T(&mfTemplate_type);
  emxFree_char_T(&mfTemplate_name);
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                double *info_maxInputNameLength
 *                double *info_maxNumMF
 *                double *info_maxMFNameLength
 *                double *info_maxMFTypeLength
 *                double *info_maxMFParamLength
 *                double *info_numVars
 *                boolean_T *info_hasSugenoMFs
 * Return Type  : void
 */
void getVarInfo(double fid, double maxLineLength, double
                *info_maxInputNameLength, double *info_maxNumMF, double
                *info_maxMFNameLength, double *info_maxMFTypeLength, double
                *info_maxMFParamLength, double *info_numVars, boolean_T
                *info_hasSugenoMFs)
{
  emxArray_uint8_T *template;
  int maxInputNameLength;
  int maxMFNameLength;
  int maxMFTypeLength;
  unsigned int maxMFParamLength;
  int i21;
  int loop_ub;
  emxArray_uint8_T *nextLineVar;
  static const unsigned char uv13[6] = { 91U, 73U, 110U, 112U, 117U, 116U };

  emxArray_boolean_T *bufferEqual;
  emxArray_uint8_T *mfInfo2;
  emxArray_uint8_T *mfInfo3;
  emxArray_int32_T *ii;
  emxArray_char_T *r15;
  emxArray_char_T *r16;
  FILE * b_NULL;
  FILE * filestar;
  int exitg1;
  int st;
  int b_loop_ub;
  boolean_T y;
  boolean_T exitg2;
  creal_T dc0;
  int j;
  int i22;
  int idx;
  unsigned int id_data[1];
  int i23;
  int i24;
  int nx;
  unsigned int u0;
  emxInit_uint8_T(&template, 2);
  *info_numVars = 0.0;
  maxInputNameLength = 0;
  *info_maxNumMF = 0.0;
  maxMFNameLength = 0;
  maxMFTypeLength = 0;
  maxMFParamLength = 0U;
  i21 = template->size[0] * template->size[1];
  template->size[0] = 1;
  loop_ub = (int)maxLineLength;
  template->size[1] = loop_ub;
  emxEnsureCapacity_uint8_T(template, i21);
  for (i21 = 0; i21 < loop_ub; i21++) {
    template->data[i21] = 0U;
  }

  for (i21 = 0; i21 < 6; i21++) {
    template->data[i21] = uv13[i21];
  }

  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual, 2);
  emxInit_uint8_T(&mfInfo2, 2);
  emxInit_uint8_T(&mfInfo3, 2);
  emxInit_int32_T(&ii, 2);
  emxInit_char_T(&r15, 2);
  emxInit_char_T(&r16, 2);
  b_NULL = NULL;
  filestar = fileManager(fid);
  do {
    exitg1 = 0;
    if (filestar == b_NULL) {
      i21 = 0;
    } else {
      st = feof(filestar);
      i21 = ((int)st != 0);
    }

    if (i21 == 0) {
      getNextLine(fid, maxLineLength, nextLineVar);
      i21 = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i21);
      b_loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
      for (i21 = 0; i21 < b_loop_ub; i21++) {
        bufferEqual->data[i21] = (nextLineVar->data[i21] == template->data[i21]);
      }

      y = true;
      b_loop_ub = 0;
      exitg2 = false;
      while ((!exitg2) && (b_loop_ub < 6)) {
        if (!bufferEqual->data[b_loop_ub]) {
          y = false;
          exitg2 = true;
        } else {
          b_loop_ub++;
        }
      }

      if (y) {
        (*info_numVars)++;
        findTopic(fid, maxLineLength, nextLineVar);
        b_char(nextLineVar, r15);
        deblank(r15, r16);
        b_loop_ub = r16->size[1];
        if (b_loop_ub > maxInputNameLength) {
          maxInputNameLength = b_loop_ub;
        }

        h_findTopic(fid, maxLineLength, nextLineVar);
        b_char(nextLineVar, r15);
        deblank(r15, r16);
        dc0 = str2double(r16);
        if (dc0.re > *info_maxNumMF) {
          *info_maxNumMF = dc0.re;
        }

        i21 = (int)dc0.re;
        for (j = 0; j < i21; j++) {
          i_findTopic(fid, maxLineLength, nextLineVar);
          i22 = mfInfo2->size[0] * mfInfo2->size[1];
          mfInfo2->size[0] = 1;
          mfInfo2->size[1] = loop_ub;
          emxEnsureCapacity_uint8_T(mfInfo2, i22);
          for (i22 = 0; i22 < loop_ub; i22++) {
            mfInfo2->data[i22] = 0U;
          }

          b_loop_ub = nextLineVar->size[1] - 3;
          for (i22 = 0; i22 <= b_loop_ub; i22++) {
            mfInfo2->data[i22] = nextLineVar->data[2 + i22];
          }

          i22 = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = mfInfo2->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i22);
          b_loop_ub = mfInfo2->size[0] * mfInfo2->size[1];
          for (i22 = 0; i22 < b_loop_ub; i22++) {
            bufferEqual->data[i22] = (mfInfo2->data[i22] == 39);
          }

          idx = 0;
          i22 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = 1;
          emxEnsureCapacity_int32_T(ii, i22);
          b_loop_ub = 0;
          exitg2 = false;
          while ((!exitg2) && (b_loop_ub <= bufferEqual->size[1] - 1)) {
            if (bufferEqual->data[b_loop_ub]) {
              idx = 1;
              ii->data[0] = b_loop_ub + 1;
              exitg2 = true;
            } else {
              b_loop_ub++;
            }
          }

          if (idx == 0) {
            ii->size[0] = 1;
            ii->size[1] = 0;
          }

          b_loop_ub = ii->size[0] * ii->size[1];
          for (i22 = 0; i22 < b_loop_ub; i22++) {
            id_data[i22] = (unsigned int)ii->data[i22];
          }

          i22 = nextLineVar->size[0] * nextLineVar->size[1];
          nextLineVar->size[0] = 1;
          nextLineVar->size[1] = loop_ub;
          emxEnsureCapacity_uint8_T(nextLineVar, i22);
          for (i22 = 0; i22 < loop_ub; i22++) {
            nextLineVar->data[i22] = 0U;
          }

          if (1 > (int)id_data[0] - 1) {
            i23 = 0;
          } else {
            i23 = (int)id_data[0] - 1;
          }

          b_loop_ub = i23 - 1;
          for (i22 = 0; i22 <= b_loop_ub; i22++) {
            nextLineVar->data[i22] = mfInfo2->data[i22];
          }

          b_char(nextLineVar, r15);
          deblank(r15, r16);
          b_loop_ub = r16->size[1];
          if (b_loop_ub > maxMFNameLength) {
            maxMFNameLength = b_loop_ub;
          }

          i22 = mfInfo3->size[0] * mfInfo3->size[1];
          mfInfo3->size[0] = 1;
          mfInfo3->size[1] = loop_ub;
          emxEnsureCapacity_uint8_T(mfInfo3, i22);
          for (i22 = 0; i22 < loop_ub; i22++) {
            mfInfo3->data[i22] = 0U;
          }

          if (id_data[0] + 3U > (unsigned int)mfInfo2->size[1]) {
            i22 = 1;
            idx = 0;
          } else {
            i22 = (int)(id_data[0] + 3U);
            idx = mfInfo2->size[1];
          }

          b_loop_ub = idx - i22;
          for (idx = 0; idx <= b_loop_ub; idx++) {
            mfInfo3->data[idx] = mfInfo2->data[(i22 + idx) - 1];
          }

          i22 = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = mfInfo3->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i22);
          b_loop_ub = mfInfo3->size[0] * mfInfo3->size[1];
          for (i22 = 0; i22 < b_loop_ub; i22++) {
            bufferEqual->data[i22] = (mfInfo3->data[i22] == 39);
          }

          idx = 0;
          i22 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = 1;
          emxEnsureCapacity_int32_T(ii, i22);
          b_loop_ub = 0;
          exitg2 = false;
          while ((!exitg2) && (b_loop_ub <= bufferEqual->size[1] - 1)) {
            if (bufferEqual->data[b_loop_ub]) {
              idx = 1;
              ii->data[0] = b_loop_ub + 1;
              exitg2 = true;
            } else {
              b_loop_ub++;
            }
          }

          if (idx == 0) {
            ii->size[0] = 1;
            ii->size[1] = 0;
          }

          b_loop_ub = ii->size[0] * ii->size[1];
          for (i22 = 0; i22 < b_loop_ub; i22++) {
            id_data[i22] = (unsigned int)ii->data[i22];
          }

          i22 = nextLineVar->size[0] * nextLineVar->size[1];
          nextLineVar->size[0] = 1;
          nextLineVar->size[1] = loop_ub;
          emxEnsureCapacity_uint8_T(nextLineVar, i22);
          for (i22 = 0; i22 < loop_ub; i22++) {
            nextLineVar->data[i22] = 0U;
          }

          if (1 > (int)id_data[0] - 1) {
            i24 = 0;
          } else {
            i24 = (int)id_data[0] - 1;
          }

          b_loop_ub = i24 - 1;
          for (i22 = 0; i22 <= b_loop_ub; i22++) {
            nextLineVar->data[i22] = mfInfo3->data[i22];
          }

          b_char(nextLineVar, r15);
          deblank(r15, r16);
          b_loop_ub = r16->size[1];
          if (b_loop_ub > maxMFTypeLength) {
            maxMFTypeLength = b_loop_ub;
          }

          i22 = nextLineVar->size[0] * nextLineVar->size[1];
          nextLineVar->size[0] = 1;
          nextLineVar->size[1] = loop_ub;
          emxEnsureCapacity_uint8_T(nextLineVar, i22);
          for (i22 = 0; i22 < loop_ub; i22++) {
            nextLineVar->data[i22] = 0U;
          }

          if (id_data[0] + 3U > (unsigned int)mfInfo3->size[1]) {
            i22 = 1;
            idx = 0;
          } else {
            i22 = (int)(id_data[0] + 3U);
            idx = mfInfo3->size[1];
          }

          b_loop_ub = idx - i22;
          for (idx = 0; idx <= b_loop_ub; idx++) {
            nextLineVar->data[idx] = mfInfo3->data[(i22 + idx) - 1];
          }

          i22 = bufferEqual->size[0] * bufferEqual->size[1];
          bufferEqual->size[0] = 1;
          bufferEqual->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_boolean_T(bufferEqual, i22);
          b_loop_ub = nextLineVar->size[0] * nextLineVar->size[1];
          for (i22 = 0; i22 < b_loop_ub; i22++) {
            bufferEqual->data[i22] = (nextLineVar->data[i22] == 32);
          }

          nx = bufferEqual->size[1];
          idx = 0;
          i22 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = bufferEqual->size[1];
          emxEnsureCapacity_int32_T(ii, i22);
          b_loop_ub = 0;
          exitg2 = false;
          while ((!exitg2) && (b_loop_ub <= nx - 1)) {
            if (bufferEqual->data[b_loop_ub]) {
              idx++;
              ii->data[idx - 1] = b_loop_ub + 1;
              if (idx >= nx) {
                exitg2 = true;
              } else {
                b_loop_ub++;
              }
            } else {
              b_loop_ub++;
            }
          }

          if (bufferEqual->size[1] == 1) {
            if (idx == 0) {
              ii->size[0] = 1;
              ii->size[1] = 0;
            }
          } else if (1 > idx) {
            ii->size[1] = 0;
          } else {
            i22 = ii->size[0] * ii->size[1];
            ii->size[1] = idx;
            emxEnsureCapacity_int32_T(ii, i22);
          }

          b_loop_ub = ii->size[1];
          u0 = b_loop_ub + 1U;
          if (u0 > maxMFParamLength) {
            maxMFParamLength = u0;
          }
        }
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_char_T(&r16);
  emxFree_char_T(&r15);
  emxFree_int32_T(&ii);
  emxFree_uint8_T(&mfInfo3);
  emxFree_uint8_T(&mfInfo2);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&template);
  *info_maxInputNameLength = maxInputNameLength;
  *info_maxMFNameLength = maxMFNameLength;
  *info_maxMFTypeLength = maxMFTypeLength;
  *info_maxMFParamLength = maxMFParamLength;
  *info_hasSugenoMFs = false;
}

/*
 * File trailer for readFISAsHomogenousStructure.c
 *
 * [EOF]
 */
