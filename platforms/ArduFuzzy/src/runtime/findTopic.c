/*
 * File: findTopic.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "findTopic.h"
#include "fileManager.h"
#include "find.h"
#include "getNextLine.h"
#include "opkene_data.h"
#include "opkene_emxutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"
#include <stdio.h>

/* Function Definitions */
/*
 * Arguments    : double fid
 *                double maxLineLength
 *                emxArray_uint8_T *topicValue
 * Return Type  : void
 */
void b_findTopic(double fid, double maxLineLength, emxArray_uint8_T *topicValue)
{
  static const unsigned char uv[5] = {84U, 121U, 112U, 101U, 61U};
  FILE *filestar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r;
  emxArray_uint8_T *buffer;
  emxArray_uint8_T *nextLineVar;
  int end;
  int equalId_data;
  int i;
  int *r1;
  unsigned char *buffer_data;
  unsigned char *nextLineVar_data;
  unsigned char *topicValue_data;
  boolean_T *bufferEqual_data;
  emxInit_uint8_T(&buffer, 2);
  i = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  equalId_data = (int)maxLineLength;
  buffer->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(buffer, i);
  buffer_data = buffer->data;
  for (i = 0; i < equalId_data; i++) {
    buffer_data[i] = 0U;
  }
  i = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(topicValue, i);
  topicValue_data = topicValue->data;
  for (i = 0; i < equalId_data; i++) {
    topicValue_data[i] = 0U;
  }
  for (i = 0; i < 5; i++) {
    buffer_data[i] = uv[i];
  }
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual);
  emxInit_int32_T(&r);
  int exitg1;
  do {
    boolean_T exitg3;
    boolean_T y;
    exitg1 = 0;
    getLine(fid, maxLineLength, nextLineVar);
    nextLineVar_data = nextLineVar->data;
    int exitg2;
    do {
      exitg2 = 0;
      y = false;
      equalId_data = 1;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= nextLineVar->size[1])) {
        if (nextLineVar_data[equalId_data - 1] != 0) {
          y = true;
          exitg3 = true;
        } else {
          equalId_data++;
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
    filestar = fileManager(fid);
    if (filestar == NULL) {
      i = 0;
    } else {
      int st;
      st = feof(filestar);
      i = ((int)st != 0);
    }
    if (i != 0) {
      exitg1 = 1;
    } else {
      i = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i);
      bufferEqual_data = bufferEqual->data;
      equalId_data = nextLineVar->size[1];
      for (i = 0; i < equalId_data; i++) {
        bufferEqual_data[i] = (nextLineVar_data[i] == buffer_data[i]);
      }
      y = true;
      equalId_data = 0;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= 4)) {
        if (!bufferEqual_data[equalId_data]) {
          y = false;
          exitg3 = true;
        } else {
          equalId_data++;
        }
      }
      if (y) {
        int equalId_size[2];
        end = nextLineVar->size[1] - 1;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            equalId_data++;
          }
        }
        i = r->size[0] * r->size[1];
        r->size[0] = 1;
        r->size[1] = equalId_data;
        emxEnsureCapacity_int32_T(r, i);
        r1 = r->data;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            r1[equalId_data] = i;
            equalId_data++;
          }
        }
        i = bufferEqual->size[0] * bufferEqual->size[1];
        bufferEqual->size[0] = 1;
        bufferEqual->size[1] = r->size[1];
        emxEnsureCapacity_boolean_T(bufferEqual, i);
        bufferEqual_data = bufferEqual->data;
        equalId_data = r->size[1];
        for (i = 0; i < equalId_data; i++) {
          bufferEqual_data[i] = (nextLineVar_data[r1[i]] == 61);
        }
        eml_find(bufferEqual, (int *)&equalId_data, equalId_size);
        if (equalId_size[1] == 0) {
          if (r->size[1] - 1 < 2) {
            i = 0;
            end = 1;
          } else {
            i = 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        } else {
          if (equalId_data > r->size[1] - 1) {
            i = 0;
            end = 1;
          } else {
            i = equalId_data - 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        }
        exitg1 = 1;
      }
    }
  } while (exitg1 == 0);
  emxFree_int32_T(&r);
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
void c_findTopic(double fid, double maxLineLength, emxArray_uint8_T *topicValue)
{
  static const unsigned char uv[10] = {65U,  110U, 100U, 77U,  101U,
                                       116U, 104U, 111U, 100U, 61U};
  FILE *filestar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r;
  emxArray_uint8_T *buffer;
  emxArray_uint8_T *nextLineVar;
  int end;
  int equalId_data;
  int i;
  int *r1;
  unsigned char *buffer_data;
  unsigned char *nextLineVar_data;
  unsigned char *topicValue_data;
  boolean_T *bufferEqual_data;
  emxInit_uint8_T(&buffer, 2);
  i = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  equalId_data = (int)maxLineLength;
  buffer->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(buffer, i);
  buffer_data = buffer->data;
  for (i = 0; i < equalId_data; i++) {
    buffer_data[i] = 0U;
  }
  i = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(topicValue, i);
  topicValue_data = topicValue->data;
  for (i = 0; i < equalId_data; i++) {
    topicValue_data[i] = 0U;
  }
  for (i = 0; i < 10; i++) {
    buffer_data[i] = uv[i];
  }
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual);
  emxInit_int32_T(&r);
  int exitg1;
  do {
    boolean_T exitg3;
    boolean_T y;
    exitg1 = 0;
    getLine(fid, maxLineLength, nextLineVar);
    nextLineVar_data = nextLineVar->data;
    int exitg2;
    do {
      exitg2 = 0;
      y = false;
      equalId_data = 1;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= nextLineVar->size[1])) {
        if (nextLineVar_data[equalId_data - 1] != 0) {
          y = true;
          exitg3 = true;
        } else {
          equalId_data++;
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
    filestar = fileManager(fid);
    if (filestar == NULL) {
      i = 0;
    } else {
      int st;
      st = feof(filestar);
      i = ((int)st != 0);
    }
    if (i != 0) {
      exitg1 = 1;
    } else {
      i = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i);
      bufferEqual_data = bufferEqual->data;
      equalId_data = nextLineVar->size[1];
      for (i = 0; i < equalId_data; i++) {
        bufferEqual_data[i] = (nextLineVar_data[i] == buffer_data[i]);
      }
      y = true;
      equalId_data = 0;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= 9)) {
        if (!bufferEqual_data[equalId_data]) {
          y = false;
          exitg3 = true;
        } else {
          equalId_data++;
        }
      }
      if (y) {
        int equalId_size[2];
        end = nextLineVar->size[1] - 1;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            equalId_data++;
          }
        }
        i = r->size[0] * r->size[1];
        r->size[0] = 1;
        r->size[1] = equalId_data;
        emxEnsureCapacity_int32_T(r, i);
        r1 = r->data;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            r1[equalId_data] = i;
            equalId_data++;
          }
        }
        i = bufferEqual->size[0] * bufferEqual->size[1];
        bufferEqual->size[0] = 1;
        bufferEqual->size[1] = r->size[1];
        emxEnsureCapacity_boolean_T(bufferEqual, i);
        bufferEqual_data = bufferEqual->data;
        equalId_data = r->size[1];
        for (i = 0; i < equalId_data; i++) {
          bufferEqual_data[i] = (nextLineVar_data[r1[i]] == 61);
        }
        eml_find(bufferEqual, (int *)&equalId_data, equalId_size);
        if (equalId_size[1] == 0) {
          if (r->size[1] - 1 < 2) {
            i = 0;
            end = 1;
          } else {
            i = 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        } else {
          if (equalId_data > r->size[1] - 1) {
            i = 0;
            end = 1;
          } else {
            i = equalId_data - 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        }
        exitg1 = 1;
      }
    }
  } while (exitg1 == 0);
  emxFree_int32_T(&r);
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
  static const unsigned char uv[9] = {79U,  114U, 77U,  101U, 116U,
                                      104U, 111U, 100U, 61U};
  FILE *filestar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r;
  emxArray_uint8_T *buffer;
  emxArray_uint8_T *nextLineVar;
  int end;
  int equalId_data;
  int i;
  int *r1;
  unsigned char *buffer_data;
  unsigned char *nextLineVar_data;
  unsigned char *topicValue_data;
  boolean_T *bufferEqual_data;
  emxInit_uint8_T(&buffer, 2);
  i = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  equalId_data = (int)maxLineLength;
  buffer->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(buffer, i);
  buffer_data = buffer->data;
  for (i = 0; i < equalId_data; i++) {
    buffer_data[i] = 0U;
  }
  i = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(topicValue, i);
  topicValue_data = topicValue->data;
  for (i = 0; i < equalId_data; i++) {
    topicValue_data[i] = 0U;
  }
  for (i = 0; i < 9; i++) {
    buffer_data[i] = uv[i];
  }
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual);
  emxInit_int32_T(&r);
  int exitg1;
  do {
    boolean_T exitg3;
    boolean_T y;
    exitg1 = 0;
    getLine(fid, maxLineLength, nextLineVar);
    nextLineVar_data = nextLineVar->data;
    int exitg2;
    do {
      exitg2 = 0;
      y = false;
      equalId_data = 1;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= nextLineVar->size[1])) {
        if (nextLineVar_data[equalId_data - 1] != 0) {
          y = true;
          exitg3 = true;
        } else {
          equalId_data++;
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
    filestar = fileManager(fid);
    if (filestar == NULL) {
      i = 0;
    } else {
      int st;
      st = feof(filestar);
      i = ((int)st != 0);
    }
    if (i != 0) {
      exitg1 = 1;
    } else {
      i = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i);
      bufferEqual_data = bufferEqual->data;
      equalId_data = nextLineVar->size[1];
      for (i = 0; i < equalId_data; i++) {
        bufferEqual_data[i] = (nextLineVar_data[i] == buffer_data[i]);
      }
      y = true;
      equalId_data = 0;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= 8)) {
        if (!bufferEqual_data[equalId_data]) {
          y = false;
          exitg3 = true;
        } else {
          equalId_data++;
        }
      }
      if (y) {
        int equalId_size[2];
        end = nextLineVar->size[1] - 1;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            equalId_data++;
          }
        }
        i = r->size[0] * r->size[1];
        r->size[0] = 1;
        r->size[1] = equalId_data;
        emxEnsureCapacity_int32_T(r, i);
        r1 = r->data;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            r1[equalId_data] = i;
            equalId_data++;
          }
        }
        i = bufferEqual->size[0] * bufferEqual->size[1];
        bufferEqual->size[0] = 1;
        bufferEqual->size[1] = r->size[1];
        emxEnsureCapacity_boolean_T(bufferEqual, i);
        bufferEqual_data = bufferEqual->data;
        equalId_data = r->size[1];
        for (i = 0; i < equalId_data; i++) {
          bufferEqual_data[i] = (nextLineVar_data[r1[i]] == 61);
        }
        eml_find(bufferEqual, (int *)&equalId_data, equalId_size);
        if (equalId_size[1] == 0) {
          if (r->size[1] - 1 < 2) {
            i = 0;
            end = 1;
          } else {
            i = 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        } else {
          if (equalId_data > r->size[1] - 1) {
            i = 0;
            end = 1;
          } else {
            i = equalId_data - 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        }
        exitg1 = 1;
      }
    }
  } while (exitg1 == 0);
  emxFree_int32_T(&r);
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
  static const unsigned char uv[10] = {73U,  109U, 112U, 77U,  101U,
                                       116U, 104U, 111U, 100U, 61U};
  FILE *filestar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r;
  emxArray_uint8_T *buffer;
  emxArray_uint8_T *nextLineVar;
  int end;
  int equalId_data;
  int i;
  int *r1;
  unsigned char *buffer_data;
  unsigned char *nextLineVar_data;
  unsigned char *topicValue_data;
  boolean_T *bufferEqual_data;
  emxInit_uint8_T(&buffer, 2);
  i = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  equalId_data = (int)maxLineLength;
  buffer->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(buffer, i);
  buffer_data = buffer->data;
  for (i = 0; i < equalId_data; i++) {
    buffer_data[i] = 0U;
  }
  i = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(topicValue, i);
  topicValue_data = topicValue->data;
  for (i = 0; i < equalId_data; i++) {
    topicValue_data[i] = 0U;
  }
  for (i = 0; i < 10; i++) {
    buffer_data[i] = uv[i];
  }
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual);
  emxInit_int32_T(&r);
  int exitg1;
  do {
    boolean_T exitg3;
    boolean_T y;
    exitg1 = 0;
    getLine(fid, maxLineLength, nextLineVar);
    nextLineVar_data = nextLineVar->data;
    int exitg2;
    do {
      exitg2 = 0;
      y = false;
      equalId_data = 1;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= nextLineVar->size[1])) {
        if (nextLineVar_data[equalId_data - 1] != 0) {
          y = true;
          exitg3 = true;
        } else {
          equalId_data++;
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
    filestar = fileManager(fid);
    if (filestar == NULL) {
      i = 0;
    } else {
      int st;
      st = feof(filestar);
      i = ((int)st != 0);
    }
    if (i != 0) {
      exitg1 = 1;
    } else {
      i = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i);
      bufferEqual_data = bufferEqual->data;
      equalId_data = nextLineVar->size[1];
      for (i = 0; i < equalId_data; i++) {
        bufferEqual_data[i] = (nextLineVar_data[i] == buffer_data[i]);
      }
      y = true;
      equalId_data = 0;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= 9)) {
        if (!bufferEqual_data[equalId_data]) {
          y = false;
          exitg3 = true;
        } else {
          equalId_data++;
        }
      }
      if (y) {
        int equalId_size[2];
        end = nextLineVar->size[1] - 1;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            equalId_data++;
          }
        }
        i = r->size[0] * r->size[1];
        r->size[0] = 1;
        r->size[1] = equalId_data;
        emxEnsureCapacity_int32_T(r, i);
        r1 = r->data;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            r1[equalId_data] = i;
            equalId_data++;
          }
        }
        i = bufferEqual->size[0] * bufferEqual->size[1];
        bufferEqual->size[0] = 1;
        bufferEqual->size[1] = r->size[1];
        emxEnsureCapacity_boolean_T(bufferEqual, i);
        bufferEqual_data = bufferEqual->data;
        equalId_data = r->size[1];
        for (i = 0; i < equalId_data; i++) {
          bufferEqual_data[i] = (nextLineVar_data[r1[i]] == 61);
        }
        eml_find(bufferEqual, (int *)&equalId_data, equalId_size);
        if (equalId_size[1] == 0) {
          if (r->size[1] - 1 < 2) {
            i = 0;
            end = 1;
          } else {
            i = 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        } else {
          if (equalId_data > r->size[1] - 1) {
            i = 0;
            end = 1;
          } else {
            i = equalId_data - 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        }
        exitg1 = 1;
      }
    }
  } while (exitg1 == 0);
  emxFree_int32_T(&r);
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
  static const unsigned char uv[10] = {65U,  103U, 103U, 77U,  101U,
                                       116U, 104U, 111U, 100U, 61U};
  FILE *filestar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r;
  emxArray_uint8_T *buffer;
  emxArray_uint8_T *nextLineVar;
  int end;
  int equalId_data;
  int i;
  int *r1;
  unsigned char *buffer_data;
  unsigned char *nextLineVar_data;
  unsigned char *topicValue_data;
  boolean_T *bufferEqual_data;
  emxInit_uint8_T(&buffer, 2);
  i = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  equalId_data = (int)maxLineLength;
  buffer->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(buffer, i);
  buffer_data = buffer->data;
  for (i = 0; i < equalId_data; i++) {
    buffer_data[i] = 0U;
  }
  i = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(topicValue, i);
  topicValue_data = topicValue->data;
  for (i = 0; i < equalId_data; i++) {
    topicValue_data[i] = 0U;
  }
  for (i = 0; i < 10; i++) {
    buffer_data[i] = uv[i];
  }
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual);
  emxInit_int32_T(&r);
  int exitg1;
  do {
    boolean_T exitg3;
    boolean_T y;
    exitg1 = 0;
    getLine(fid, maxLineLength, nextLineVar);
    nextLineVar_data = nextLineVar->data;
    int exitg2;
    do {
      exitg2 = 0;
      y = false;
      equalId_data = 1;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= nextLineVar->size[1])) {
        if (nextLineVar_data[equalId_data - 1] != 0) {
          y = true;
          exitg3 = true;
        } else {
          equalId_data++;
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
    filestar = fileManager(fid);
    if (filestar == NULL) {
      i = 0;
    } else {
      int st;
      st = feof(filestar);
      i = ((int)st != 0);
    }
    if (i != 0) {
      exitg1 = 1;
    } else {
      i = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i);
      bufferEqual_data = bufferEqual->data;
      equalId_data = nextLineVar->size[1];
      for (i = 0; i < equalId_data; i++) {
        bufferEqual_data[i] = (nextLineVar_data[i] == buffer_data[i]);
      }
      y = true;
      equalId_data = 0;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= 9)) {
        if (!bufferEqual_data[equalId_data]) {
          y = false;
          exitg3 = true;
        } else {
          equalId_data++;
        }
      }
      if (y) {
        int equalId_size[2];
        end = nextLineVar->size[1] - 1;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            equalId_data++;
          }
        }
        i = r->size[0] * r->size[1];
        r->size[0] = 1;
        r->size[1] = equalId_data;
        emxEnsureCapacity_int32_T(r, i);
        r1 = r->data;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            r1[equalId_data] = i;
            equalId_data++;
          }
        }
        i = bufferEqual->size[0] * bufferEqual->size[1];
        bufferEqual->size[0] = 1;
        bufferEqual->size[1] = r->size[1];
        emxEnsureCapacity_boolean_T(bufferEqual, i);
        bufferEqual_data = bufferEqual->data;
        equalId_data = r->size[1];
        for (i = 0; i < equalId_data; i++) {
          bufferEqual_data[i] = (nextLineVar_data[r1[i]] == 61);
        }
        eml_find(bufferEqual, (int *)&equalId_data, equalId_size);
        if (equalId_size[1] == 0) {
          if (r->size[1] - 1 < 2) {
            i = 0;
            end = 1;
          } else {
            i = 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        } else {
          if (equalId_data > r->size[1] - 1) {
            i = 0;
            end = 1;
          } else {
            i = equalId_data - 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        }
        exitg1 = 1;
      }
    }
  } while (exitg1 == 0);
  emxFree_int32_T(&r);
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
  static const unsigned char uv[5] = {78U, 97U, 109U, 101U, 61U};
  FILE *filestar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r;
  emxArray_uint8_T *buffer;
  emxArray_uint8_T *nextLineVar;
  int end;
  int equalId_data;
  int i;
  int *r1;
  unsigned char *buffer_data;
  unsigned char *nextLineVar_data;
  unsigned char *topicValue_data;
  boolean_T *bufferEqual_data;
  emxInit_uint8_T(&buffer, 2);
  i = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  equalId_data = (int)maxLineLength;
  buffer->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(buffer, i);
  buffer_data = buffer->data;
  for (i = 0; i < equalId_data; i++) {
    buffer_data[i] = 0U;
  }
  i = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(topicValue, i);
  topicValue_data = topicValue->data;
  for (i = 0; i < equalId_data; i++) {
    topicValue_data[i] = 0U;
  }
  for (i = 0; i < 5; i++) {
    buffer_data[i] = uv[i];
  }
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual);
  emxInit_int32_T(&r);
  int exitg1;
  do {
    boolean_T exitg3;
    boolean_T y;
    exitg1 = 0;
    getLine(fid, maxLineLength, nextLineVar);
    nextLineVar_data = nextLineVar->data;
    int exitg2;
    do {
      exitg2 = 0;
      y = false;
      equalId_data = 1;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= nextLineVar->size[1])) {
        if (nextLineVar_data[equalId_data - 1] != 0) {
          y = true;
          exitg3 = true;
        } else {
          equalId_data++;
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
    filestar = fileManager(fid);
    if (filestar == NULL) {
      i = 0;
    } else {
      int st;
      st = feof(filestar);
      i = ((int)st != 0);
    }
    if (i != 0) {
      exitg1 = 1;
    } else {
      i = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i);
      bufferEqual_data = bufferEqual->data;
      equalId_data = nextLineVar->size[1];
      for (i = 0; i < equalId_data; i++) {
        bufferEqual_data[i] = (nextLineVar_data[i] == buffer_data[i]);
      }
      y = true;
      equalId_data = 0;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= 4)) {
        if (!bufferEqual_data[equalId_data]) {
          y = false;
          exitg3 = true;
        } else {
          equalId_data++;
        }
      }
      if (y) {
        int equalId_size[2];
        end = nextLineVar->size[1] - 1;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            equalId_data++;
          }
        }
        i = r->size[0] * r->size[1];
        r->size[0] = 1;
        r->size[1] = equalId_data;
        emxEnsureCapacity_int32_T(r, i);
        r1 = r->data;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            r1[equalId_data] = i;
            equalId_data++;
          }
        }
        i = bufferEqual->size[0] * bufferEqual->size[1];
        bufferEqual->size[0] = 1;
        bufferEqual->size[1] = r->size[1];
        emxEnsureCapacity_boolean_T(bufferEqual, i);
        bufferEqual_data = bufferEqual->data;
        equalId_data = r->size[1];
        for (i = 0; i < equalId_data; i++) {
          bufferEqual_data[i] = (nextLineVar_data[r1[i]] == 61);
        }
        eml_find(bufferEqual, (int *)&equalId_data, equalId_size);
        if (equalId_size[1] == 0) {
          if (r->size[1] - 1 < 2) {
            i = 0;
            end = 1;
          } else {
            i = 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        } else {
          if (equalId_data > r->size[1] - 1) {
            i = 0;
            end = 1;
          } else {
            i = equalId_data - 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        }
        exitg1 = 1;
      }
    }
  } while (exitg1 == 0);
  emxFree_int32_T(&r);
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
  static const unsigned char uv[13] = {68U,  101U, 102U, 117U, 122U, 122U, 77U,
                                       101U, 116U, 104U, 111U, 100U, 61U};
  FILE *filestar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r;
  emxArray_uint8_T *buffer;
  emxArray_uint8_T *nextLineVar;
  int end;
  int equalId_data;
  int i;
  int *r1;
  unsigned char *buffer_data;
  unsigned char *nextLineVar_data;
  unsigned char *topicValue_data;
  boolean_T *bufferEqual_data;
  emxInit_uint8_T(&buffer, 2);
  i = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  equalId_data = (int)maxLineLength;
  buffer->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(buffer, i);
  buffer_data = buffer->data;
  for (i = 0; i < equalId_data; i++) {
    buffer_data[i] = 0U;
  }
  i = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(topicValue, i);
  topicValue_data = topicValue->data;
  for (i = 0; i < equalId_data; i++) {
    topicValue_data[i] = 0U;
  }
  for (i = 0; i < 13; i++) {
    buffer_data[i] = uv[i];
  }
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual);
  emxInit_int32_T(&r);
  int exitg1;
  do {
    boolean_T exitg3;
    boolean_T y;
    exitg1 = 0;
    getLine(fid, maxLineLength, nextLineVar);
    nextLineVar_data = nextLineVar->data;
    int exitg2;
    do {
      exitg2 = 0;
      y = false;
      equalId_data = 1;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= nextLineVar->size[1])) {
        if (nextLineVar_data[equalId_data - 1] != 0) {
          y = true;
          exitg3 = true;
        } else {
          equalId_data++;
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
    filestar = fileManager(fid);
    if (filestar == NULL) {
      i = 0;
    } else {
      int st;
      st = feof(filestar);
      i = ((int)st != 0);
    }
    if (i != 0) {
      exitg1 = 1;
    } else {
      i = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i);
      bufferEqual_data = bufferEqual->data;
      equalId_data = nextLineVar->size[1];
      for (i = 0; i < equalId_data; i++) {
        bufferEqual_data[i] = (nextLineVar_data[i] == buffer_data[i]);
      }
      y = true;
      equalId_data = 0;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= 12)) {
        if (!bufferEqual_data[equalId_data]) {
          y = false;
          exitg3 = true;
        } else {
          equalId_data++;
        }
      }
      if (y) {
        int equalId_size[2];
        end = nextLineVar->size[1] - 1;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            equalId_data++;
          }
        }
        i = r->size[0] * r->size[1];
        r->size[0] = 1;
        r->size[1] = equalId_data;
        emxEnsureCapacity_int32_T(r, i);
        r1 = r->data;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            r1[equalId_data] = i;
            equalId_data++;
          }
        }
        i = bufferEqual->size[0] * bufferEqual->size[1];
        bufferEqual->size[0] = 1;
        bufferEqual->size[1] = r->size[1];
        emxEnsureCapacity_boolean_T(bufferEqual, i);
        bufferEqual_data = bufferEqual->data;
        equalId_data = r->size[1];
        for (i = 0; i < equalId_data; i++) {
          bufferEqual_data[i] = (nextLineVar_data[r1[i]] == 61);
        }
        eml_find(bufferEqual, (int *)&equalId_data, equalId_size);
        if (equalId_size[1] == 0) {
          if (r->size[1] - 1 < 2) {
            i = 0;
            end = 1;
          } else {
            i = 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        } else {
          if (equalId_data > r->size[1] - 1) {
            i = 0;
            end = 1;
          } else {
            i = equalId_data - 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        }
        exitg1 = 1;
      }
    }
  } while (exitg1 == 0);
  emxFree_int32_T(&r);
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
void h_findTopic(double fid, double maxLineLength, emxArray_uint8_T *topicValue)
{
  static const unsigned char uv[7] = {78U, 117U, 109U, 77U, 70U, 115U, 61U};
  FILE *filestar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r;
  emxArray_uint8_T *buffer;
  emxArray_uint8_T *nextLineVar;
  int i;
  int loop_ub_tmp;
  int *r1;
  unsigned char *buffer_data;
  unsigned char *nextLineVar_data;
  unsigned char *topicValue_data;
  boolean_T exitg1;
  boolean_T topicFound;
  boolean_T *bufferEqual_data;
  emxInit_uint8_T(&buffer, 2);
  i = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  loop_ub_tmp = (int)maxLineLength;
  buffer->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(buffer, i);
  buffer_data = buffer->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    buffer_data[i] = 0U;
  }
  i = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(topicValue, i);
  topicValue_data = topicValue->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    topicValue_data[i] = 0U;
  }
  for (i = 0; i < 7; i++) {
    buffer_data[i] = uv[i];
  }
  topicFound = false;
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual);
  emxInit_int32_T(&r);
  exitg1 = false;
  while ((!exitg1) && (!topicFound)) {
    boolean_T exitg3;
    boolean_T y;
    getLine(fid, maxLineLength, nextLineVar);
    nextLineVar_data = nextLineVar->data;
    int exitg2;
    do {
      exitg2 = 0;
      y = false;
      loop_ub_tmp = 1;
      exitg3 = false;
      while ((!exitg3) && (loop_ub_tmp <= nextLineVar->size[1])) {
        if (nextLineVar_data[loop_ub_tmp - 1] != 0) {
          y = true;
          exitg3 = true;
        } else {
          loop_ub_tmp++;
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
      i = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i);
      bufferEqual_data = bufferEqual->data;
      loop_ub_tmp = nextLineVar->size[1];
      for (i = 0; i < loop_ub_tmp; i++) {
        bufferEqual_data[i] = (nextLineVar_data[i] == buffer_data[i]);
      }
      y = true;
      loop_ub_tmp = 0;
      exitg3 = false;
      while ((!exitg3) && (loop_ub_tmp <= 6)) {
        if (!bufferEqual_data[loop_ub_tmp]) {
          y = false;
          exitg3 = true;
        } else {
          loop_ub_tmp++;
        }
      }
      if (y) {
        int end;
        topicFound = true;
        end = nextLineVar->size[1] - 1;
        loop_ub_tmp = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            loop_ub_tmp++;
          }
        }
        i = r->size[0] * r->size[1];
        r->size[0] = 1;
        r->size[1] = loop_ub_tmp;
        emxEnsureCapacity_int32_T(r, i);
        r1 = r->data;
        loop_ub_tmp = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            r1[loop_ub_tmp] = i;
            loop_ub_tmp++;
          }
        }
        loop_ub_tmp = r->size[1];
        for (i = 0; i < loop_ub_tmp; i++) {
          topicValue_data[i] = nextLineVar_data[r1[i]];
        }
      }
    }
  }
  emxFree_int32_T(&r);
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
void i_findTopic(double fid, double maxLineLength, emxArray_uint8_T *topicValue)
{
  FILE *filestar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r;
  emxArray_uint8_T *buffer;
  emxArray_uint8_T *nextLineVar;
  int end;
  int equalId_data;
  int i;
  int *r1;
  unsigned char *buffer_data;
  unsigned char *nextLineVar_data;
  unsigned char *topicValue_data;
  boolean_T *bufferEqual_data;
  emxInit_uint8_T(&buffer, 2);
  i = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  equalId_data = (int)maxLineLength;
  buffer->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(buffer, i);
  buffer_data = buffer->data;
  for (i = 0; i < equalId_data; i++) {
    buffer_data[i] = 0U;
  }
  i = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(topicValue, i);
  topicValue_data = topicValue->data;
  for (i = 0; i < equalId_data; i++) {
    topicValue_data[i] = 0U;
  }
  buffer_data[0] = 77U;
  buffer_data[1] = 70U;
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual);
  emxInit_int32_T(&r);
  int exitg1;
  do {
    boolean_T exitg3;
    boolean_T y;
    exitg1 = 0;
    getLine(fid, maxLineLength, nextLineVar);
    nextLineVar_data = nextLineVar->data;
    int exitg2;
    do {
      exitg2 = 0;
      y = false;
      equalId_data = 1;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= nextLineVar->size[1])) {
        if (nextLineVar_data[equalId_data - 1] != 0) {
          y = true;
          exitg3 = true;
        } else {
          equalId_data++;
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
    filestar = fileManager(fid);
    if (filestar == NULL) {
      i = 0;
    } else {
      int st;
      st = feof(filestar);
      i = ((int)st != 0);
    }
    if (i != 0) {
      exitg1 = 1;
    } else {
      i = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i);
      bufferEqual_data = bufferEqual->data;
      equalId_data = nextLineVar->size[1];
      for (i = 0; i < equalId_data; i++) {
        bufferEqual_data[i] = (nextLineVar_data[i] == buffer_data[i]);
      }
      y = true;
      equalId_data = 0;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= 1)) {
        if (!bufferEqual_data[equalId_data]) {
          y = false;
          exitg3 = true;
        } else {
          equalId_data++;
        }
      }
      if (y) {
        int equalId_size[2];
        end = nextLineVar->size[1] - 1;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            equalId_data++;
          }
        }
        i = r->size[0] * r->size[1];
        r->size[0] = 1;
        r->size[1] = equalId_data;
        emxEnsureCapacity_int32_T(r, i);
        r1 = r->data;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            r1[equalId_data] = i;
            equalId_data++;
          }
        }
        i = bufferEqual->size[0] * bufferEqual->size[1];
        bufferEqual->size[0] = 1;
        bufferEqual->size[1] = r->size[1];
        emxEnsureCapacity_boolean_T(bufferEqual, i);
        bufferEqual_data = bufferEqual->data;
        equalId_data = r->size[1];
        for (i = 0; i < equalId_data; i++) {
          bufferEqual_data[i] = (nextLineVar_data[r1[i]] == 61);
        }
        eml_find(bufferEqual, (int *)&equalId_data, equalId_size);
        if (equalId_size[1] == 0) {
          if (r->size[1] - 1 < 2) {
            i = 0;
            end = 1;
          } else {
            i = 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        } else {
          if (equalId_data > r->size[1] - 1) {
            i = 0;
            end = 1;
          } else {
            i = equalId_data - 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        }
        exitg1 = 1;
      }
    }
  } while (exitg1 == 0);
  emxFree_int32_T(&r);
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
void j_findTopic(double fid, double maxLineLength, emxArray_uint8_T *topicValue)
{
  static const unsigned char uv[6] = {82U, 97U, 110U, 103U, 101U, 61U};
  FILE *filestar;
  emxArray_boolean_T *bufferEqual;
  emxArray_int32_T *r;
  emxArray_uint8_T *buffer;
  emxArray_uint8_T *nextLineVar;
  int end;
  int equalId_data;
  int i;
  int *r1;
  unsigned char *buffer_data;
  unsigned char *nextLineVar_data;
  unsigned char *topicValue_data;
  boolean_T *bufferEqual_data;
  emxInit_uint8_T(&buffer, 2);
  i = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  equalId_data = (int)maxLineLength;
  buffer->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(buffer, i);
  buffer_data = buffer->data;
  for (i = 0; i < equalId_data; i++) {
    buffer_data[i] = 0U;
  }
  i = topicValue->size[0] * topicValue->size[1];
  topicValue->size[0] = 1;
  topicValue->size[1] = (int)maxLineLength;
  emxEnsureCapacity_uint8_T(topicValue, i);
  topicValue_data = topicValue->data;
  for (i = 0; i < equalId_data; i++) {
    topicValue_data[i] = 0U;
  }
  for (i = 0; i < 6; i++) {
    buffer_data[i] = uv[i];
  }
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_boolean_T(&bufferEqual);
  emxInit_int32_T(&r);
  int exitg1;
  do {
    boolean_T exitg3;
    boolean_T y;
    exitg1 = 0;
    getLine(fid, maxLineLength, nextLineVar);
    nextLineVar_data = nextLineVar->data;
    int exitg2;
    do {
      exitg2 = 0;
      y = false;
      equalId_data = 1;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= nextLineVar->size[1])) {
        if (nextLineVar_data[equalId_data - 1] != 0) {
          y = true;
          exitg3 = true;
        } else {
          equalId_data++;
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
    filestar = fileManager(fid);
    if (filestar == NULL) {
      i = 0;
    } else {
      int st;
      st = feof(filestar);
      i = ((int)st != 0);
    }
    if (i != 0) {
      exitg1 = 1;
    } else {
      i = bufferEqual->size[0] * bufferEqual->size[1];
      bufferEqual->size[0] = 1;
      bufferEqual->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_boolean_T(bufferEqual, i);
      bufferEqual_data = bufferEqual->data;
      equalId_data = nextLineVar->size[1];
      for (i = 0; i < equalId_data; i++) {
        bufferEqual_data[i] = (nextLineVar_data[i] == buffer_data[i]);
      }
      y = true;
      equalId_data = 0;
      exitg3 = false;
      while ((!exitg3) && (equalId_data <= 5)) {
        if (!bufferEqual_data[equalId_data]) {
          y = false;
          exitg3 = true;
        } else {
          equalId_data++;
        }
      }
      if (y) {
        int equalId_size[2];
        end = nextLineVar->size[1] - 1;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            equalId_data++;
          }
        }
        i = r->size[0] * r->size[1];
        r->size[0] = 1;
        r->size[1] = equalId_data;
        emxEnsureCapacity_int32_T(r, i);
        r1 = r->data;
        equalId_data = 0;
        for (i = 0; i <= end; i++) {
          if ((nextLineVar_data[i] != 0) != (buffer_data[i] != 0)) {
            r1[equalId_data] = i;
            equalId_data++;
          }
        }
        i = bufferEqual->size[0] * bufferEqual->size[1];
        bufferEqual->size[0] = 1;
        bufferEqual->size[1] = r->size[1];
        emxEnsureCapacity_boolean_T(bufferEqual, i);
        bufferEqual_data = bufferEqual->data;
        equalId_data = r->size[1];
        for (i = 0; i < equalId_data; i++) {
          bufferEqual_data[i] = (nextLineVar_data[r1[i]] == 61);
        }
        eml_find(bufferEqual, (int *)&equalId_data, equalId_size);
        if (equalId_size[1] == 0) {
          if (r->size[1] - 1 < 2) {
            i = 0;
            end = 1;
          } else {
            i = 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        } else {
          if (equalId_data > r->size[1] - 1) {
            i = 0;
            end = 1;
          } else {
            i = equalId_data - 1;
            end = r->size[1];
          }
          equalId_data = end - i;
          for (end = 0; end <= equalId_data - 2; end++) {
            topicValue_data[end] = nextLineVar_data[r1[i + end]];
          }
        }
        exitg1 = 1;
      }
    }
  } while (exitg1 == 0);
  emxFree_int32_T(&r);
  emxFree_boolean_T(&bufferEqual);
  emxFree_uint8_T(&nextLineVar);
  emxFree_uint8_T(&buffer);
}

/*
 * File trailer for findTopic.c
 *
 * [EOF]
 */
