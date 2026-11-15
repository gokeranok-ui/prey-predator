/*
 * File: getRules.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "getRules.h"
#include "fclose.h"
#include "deblank.h"
#include "feof.h"
#include "fileManager.h"
#include "find.h"
#include "getNextLine.h"
#include "opkene_data.h"
#include "opkene_emxutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include <stdio.h>

/* Function Declarations */
static double getNumRules(double fid, double maxLineLength);

/* Function Definitions */
/*
 * Arguments    : double fid
 *                double maxLineLength
 * Return Type  : double
 */
static double getNumRules(double fid, double maxLineLength)
{
  static const char cv[7] = {'[', 'R', 'u', 'l', 'e', 's', ']'};
  FILE *filestar;
  emxArray_char_T *a;
  emxArray_char_T *b_nextLineVar;
  emxArray_uint8_T *nextLineVar;
  double numRules;
  int i;
  char *b_nextLineVar_data;
  unsigned char *nextLineVar_data;
  boolean_T exitg1;
  boolean_T topicFound;
  numRules = 0.0;
  topicFound = false;
  emxInit_uint8_T(&nextLineVar, 2);
  emxInit_char_T(&a, 2);
  emxInit_char_T(&b_nextLineVar, 2);
  exitg1 = false;
  while ((!exitg1) && (!topicFound)) {
    int st;
    int exitg2;
    int ix;
    boolean_T exitg3;
    boolean_T y;
    getLine(fid, maxLineLength, nextLineVar);
    nextLineVar_data = nextLineVar->data;
    do {
      exitg2 = 0;
      y = false;
      ix = 1;
      exitg3 = false;
      while ((!exitg3) && (ix <= nextLineVar->size[1])) {
        if (nextLineVar_data[ix - 1] != 0) {
          y = true;
          exitg3 = true;
        } else {
          ix++;
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
      st = feof(filestar);
      i = ((int)st != 0);
    }
    if (i != 0) {
      exitg1 = true;
    } else {
      i = b_nextLineVar->size[0] * b_nextLineVar->size[1];
      b_nextLineVar->size[0] = 1;
      b_nextLineVar->size[1] = nextLineVar->size[1];
      emxEnsureCapacity_char_T(b_nextLineVar, i);
      b_nextLineVar_data = b_nextLineVar->data;
      ix = nextLineVar->size[1];
      for (i = 0; i < ix; i++) {
        b_nextLineVar_data[i] = (signed char)nextLineVar_data[i];
      }
      deblank(b_nextLineVar, a);
      b_nextLineVar_data = a->data;
      y = false;
      if (a->size[1] == 7) {
        ix = 0;
        do {
          exitg2 = 0;
          if (ix < 7) {
            if (b_nextLineVar_data[ix] != cv[ix]) {
              exitg2 = 1;
            } else {
              ix++;
            }
          } else {
            y = true;
            exitg2 = 1;
          }
        } while (exitg2 == 0);
      }
      if (y) {
        topicFound = true;
        do {
          exitg2 = 0;
          getLine(fid, maxLineLength, nextLineVar);
          nextLineVar_data = nextLineVar->data;
          int exitg4;
          do {
            exitg4 = 0;
            y = false;
            ix = 1;
            exitg3 = false;
            while ((!exitg3) && (ix <= nextLineVar->size[1])) {
              if (nextLineVar_data[ix - 1] != 0) {
                y = true;
                exitg3 = true;
              } else {
                ix++;
              }
            }
            if (y && (((signed char)nextLineVar_data[0] == '%') ||
                      (nextLineVar_data[0] == 10))) {
              getLine(fid, maxLineLength, nextLineVar);
              nextLineVar_data = nextLineVar->data;
            } else {
              exitg4 = 1;
            }
          } while (exitg4 == 0);
          filestar = fileManager(fid);
          if (filestar == NULL) {
            i = 0;
          } else {
            st = feof(filestar);
            i = ((int)st != 0);
          }
          if (i != 0) {
            exitg2 = 1;
          } else {
            y = false;
            ix = 1;
            exitg3 = false;
            while ((!exitg3) && (ix <= nextLineVar->size[1])) {
              if (nextLineVar_data[ix - 1] != 0) {
                y = true;
                exitg3 = true;
              } else {
                ix++;
              }
            }
            if (y && (nextLineVar_data[0] != 10)) {
              numRules++;
            }
          }
        } while (exitg2 == 0);
      }
    }
  }
  emxFree_char_T(&b_nextLineVar);
  emxFree_char_T(&a);
  emxFree_uint8_T(&nextLineVar);
  return numRules;
}

/*
 * Arguments    : double fid
 *                double maxLineLength
 *                double numInputs
 *                double numOutputs
 *                c_emxArray_struct_T *rules
 * Return Type  : void
 */
void getRules(double fid, double maxLineLength, double numInputs,
              double numOutputs, c_emxArray_struct_T *rules)
{
  static const char cv[7] = {'[', 'R', 'u', 'l', 'e', 's', ']'};
  FILE *filestar;
  c_struct_T rule;
  c_struct_T *rules_data;
  emxArray_boolean_T *c_nextLineVar;
  emxArray_char_T *a;
  emxArray_char_T *b_nextLineVar;
  emxArray_int32_T *wt;
  emxArray_uint8_T *ant;
  emxArray_uint8_T *con;
  emxArray_uint8_T *nextLineVar;
  double numRules;
  int b_i;
  int i;
  int i1;
  int id2_data;
  int id_data;
  int loop_ub;
  int loop_ub_tmp;
  int *wt_data;
  unsigned char *ant_data;
  char *b_nextLineVar_data;
  unsigned char *con_data;
  unsigned char *nextLineVar_data;
  boolean_T *c_nextLineVar_data;
  emxInitStruct_struct_T3(&rule);
  i = rule.antecedent->size[0] * rule.antecedent->size[1];
  rule.antecedent->size[0] = 1;
  loop_ub_tmp = (int)numInputs;
  rule.antecedent->size[1] = (int)numInputs;
  emxEnsureCapacity_real_T(rule.antecedent, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    rule.antecedent->data[i] = 0.0;
  }
  i = rule.consequent->size[0] * rule.consequent->size[1];
  rule.consequent->size[0] = 1;
  loop_ub_tmp = (int)numOutputs;
  rule.consequent->size[1] = (int)numOutputs;
  emxEnsureCapacity_real_T(rule.consequent, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    rule.consequent->data[i] = 0.0;
  }
  rule.weight = 0.0;
  rule.connection = 0.0;
  numRules = getNumRules(fid, maxLineLength);
  i = rules->size[0] * rules->size[1];
  rules->size[0] = 1;
  loop_ub = (int)numRules;
  rules->size[1] = (int)numRules;
  emxEnsureCapacity_struct_T2(rules, i);
  rules_data = rules->data;
  for (i = 0; i < loop_ub; i++) {
    emxCopyStruct_struct_T2(&rules_data[i], &rule);
  }
  emxFreeStruct_struct_T2(&rule);
  if (!(numRules == 0.0)) {
    double startIndex;
    int exitg2;
    filestar = fileManager(fid);
    if ((!(filestar == NULL)) && (!(fid == 0.0)) && (!(fid == 1.0)) &&
        (!(fid == 2.0))) {
      fseek(filestar, 0, SEEK_SET);
    }
    emxInit_uint8_T(&nextLineVar, 2);
    emxInit_uint8_T(&ant, 2);
    emxInit_uint8_T(&con, 2);
    emxInit_int32_T(&wt);
    emxInit_char_T(&a, 2);
    emxInit_char_T(&b_nextLineVar, 2);
    emxInit_boolean_T(&c_nextLineVar);
    do {
      exitg2 = 0;
      getNextLine(fid, maxLineLength, nextLineVar);
      nextLineVar_data = nextLineVar->data;
      startIndex = b_feof(fid);
      if (startIndex != 0.0) {
        exitg2 = 2;
      } else {
        boolean_T b_bool;
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
        b_nextLineVar_data = a->data;
        b_bool = false;
        if (a->size[1] == 7) {
          loop_ub_tmp = 0;
          int exitg3;
          do {
            exitg3 = 0;
            if (loop_ub_tmp < 7) {
              if (b_nextLineVar_data[loop_ub_tmp] != cv[loop_ub_tmp]) {
                exitg3 = 1;
              } else {
                loop_ub_tmp++;
              }
            } else {
              b_bool = true;
              exitg3 = 1;
            }
          } while (exitg3 == 0);
        }
        if (b_bool) {
          b_i = 0;
          exitg2 = 1;
        }
      }
    } while (exitg2 == 0);
    if (exitg2 == 1) {
      boolean_T exitg1;
      exitg1 = false;
      while ((!exitg1) && (b_i <= (int)numRules - 1)) {
        getNextLine(fid, maxLineLength, nextLineVar);
        nextLineVar_data = nextLineVar->data;
        startIndex = b_feof(fid);
        if (startIndex != 0.0) {
          exitg1 = true;
        } else {
          creal_T x;
          int tmp_size[2];
          i = c_nextLineVar->size[0] * c_nextLineVar->size[1];
          c_nextLineVar->size[0] = 1;
          c_nextLineVar->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_boolean_T(c_nextLineVar, i);
          c_nextLineVar_data = c_nextLineVar->data;
          loop_ub = nextLineVar->size[1];
          for (i = 0; i < loop_ub; i++) {
            c_nextLineVar_data[i] = (nextLineVar_data[i] == 44);
          }
          eml_find(c_nextLineVar, (int *)&loop_ub_tmp, tmp_size);
          loop_ub = tmp_size[1];
          for (i = 0; i < loop_ub; i++) {
            id_data = loop_ub_tmp;
          }
          i = ant->size[0] * ant->size[1];
          ant->size[0] = 1;
          ant->size[1] = id_data - 1;
          emxEnsureCapacity_uint8_T(ant, i);
          ant_data = ant->data;
          loop_ub = id_data - 1;
          for (i = 0; i < loop_ub; i++) {
            ant_data[i] = 0U;
          }
          if ((double)id_data - 1.0 < 1.0) {
            loop_ub = 0;
          } else {
            loop_ub = id_data - 1;
          }
          for (i = 0; i < loop_ub; i++) {
            ant_data[i] = nextLineVar_data[i];
          }
          loop_ub_tmp = id_data + 1;
          for (i = 0; i < loop_ub_tmp; i++) {
            nextLineVar_data[i] = 0U;
          }
          i = c_nextLineVar->size[0] * c_nextLineVar->size[1];
          c_nextLineVar->size[0] = 1;
          c_nextLineVar->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_boolean_T(c_nextLineVar, i);
          c_nextLineVar_data = c_nextLineVar->data;
          loop_ub = nextLineVar->size[1];
          for (i = 0; i < loop_ub; i++) {
            c_nextLineVar_data[i] = (nextLineVar_data[i] == 40);
          }
          eml_find(c_nextLineVar, (int *)&loop_ub_tmp, tmp_size);
          loop_ub = tmp_size[1];
          for (i = 0; i < loop_ub; i++) {
            id2_data = loop_ub_tmp;
          }
          i = con->size[0] * con->size[1];
          con->size[0] = 1;
          loop_ub = (int)(((double)id2_data - 1.0) - ((double)id_data + 2.0));
          con->size[1] = loop_ub;
          emxEnsureCapacity_uint8_T(con, i);
          con_data = con->data;
          for (i = 0; i < loop_ub; i++) {
            con_data[i] = 0U;
          }
          if ((double)id_data + 2.0 > (double)id2_data - 2.0) {
            i = 0;
            i1 = 0;
          } else {
            i = id_data + 1;
            i1 = id2_data - 2;
          }
          loop_ub = i1 - i;
          for (i1 = 0; i1 < loop_ub; i1++) {
            con_data[i1] = nextLineVar_data[i + i1];
          }
          if ((double)id_data + 2.0 > id2_data) {
            i = 0;
            i1 = 0;
          } else {
            i = id_data + 1;
            i1 = id2_data;
          }
          loop_ub = i1 - i;
          for (i1 = 0; i1 < loop_ub; i1++) {
            nextLineVar_data[i + i1] = 0U;
          }
          i = c_nextLineVar->size[0] * c_nextLineVar->size[1];
          c_nextLineVar->size[0] = 1;
          c_nextLineVar->size[1] = nextLineVar->size[1];
          emxEnsureCapacity_boolean_T(c_nextLineVar, i);
          c_nextLineVar_data = c_nextLineVar->data;
          loop_ub = nextLineVar->size[1];
          for (i = 0; i < loop_ub; i++) {
            c_nextLineVar_data[i] = (nextLineVar_data[i] == 41);
          }
          eml_find(c_nextLineVar, (int *)&loop_ub_tmp, tmp_size);
          loop_ub = tmp_size[1];
          for (i = 0; i < loop_ub; i++) {
            id_data = loop_ub_tmp;
          }
          i = wt->size[0] * wt->size[1];
          wt->size[0] = 1;
          loop_ub = (int)(((double)id_data - (double)id2_data) - 1.0);
          wt->size[1] = loop_ub;
          emxEnsureCapacity_int32_T(wt, i);
          wt_data = wt->data;
          for (i = 0; i < loop_ub; i++) {
            wt_data[i] = 0;
          }
          if ((double)id2_data + 1.0 > (double)id_data - 1.0) {
            id2_data = 0;
            i = 0;
          } else {
            i = id_data - 1;
          }
          loop_ub = i - id2_data;
          for (i = 0; i < loop_ub; i++) {
            wt_data[i] = nextLineVar_data[id2_data + i];
          }
          i = b_nextLineVar->size[0] * b_nextLineVar->size[1];
          b_nextLineVar->size[0] = 1;
          b_nextLineVar->size[1] = wt->size[1];
          emxEnsureCapacity_char_T(b_nextLineVar, i);
          b_nextLineVar_data = b_nextLineVar->data;
          loop_ub = wt->size[1];
          for (i = 0; i < loop_ub; i++) {
            b_nextLineVar_data[i] = (signed char)wt_data[i];
          }
          x = str2double(b_nextLineVar);
          rules_data[b_i].weight = x.re;
          x = b_str2double((signed char)nextLineVar_data[id_data + 3]);
          rules_data[b_i].connection = x.re;
          i = c_nextLineVar->size[0] * c_nextLineVar->size[1];
          c_nextLineVar->size[0] = 1;
          c_nextLineVar->size[1] = ant->size[1];
          emxEnsureCapacity_boolean_T(c_nextLineVar, i);
          c_nextLineVar_data = c_nextLineVar->data;
          loop_ub = ant->size[1];
          for (i = 0; i < loop_ub; i++) {
            c_nextLineVar_data[i] = (ant_data[i] == 32);
          }
          b_eml_find(c_nextLineVar, wt);
          wt_data = wt->data;
          if (wt->size[1] == 0) {
            if (numInputs < 1.0) {
              b_fclose(fid);
              exit(0);
            }
            i = b_nextLineVar->size[0] * b_nextLineVar->size[1];
            b_nextLineVar->size[0] = 1;
            b_nextLineVar->size[1] = ant->size[1];
            emxEnsureCapacity_char_T(b_nextLineVar, i);
            b_nextLineVar_data = b_nextLineVar->data;
            loop_ub = ant->size[1];
            for (i = 0; i < loop_ub; i++) {
              b_nextLineVar_data[i] = (signed char)ant_data[i];
            }
            x = str2double(b_nextLineVar);
            rules_data[b_i].antecedent->data[0] = x.re;
          } else {
            i = wt->size[1];
            for (loop_ub = 0; loop_ub < i; loop_ub++) {
              if (loop_ub + 1 == wt->size[1]) {
                if (loop_ub + 1 == 1) {
                  startIndex = 1.0;
                } else {
                  startIndex = (double)wt_data[loop_ub - 1] + 1.0;
                }
                i1 = wt_data[loop_ub];
                if (startIndex > (double)i1 - 1.0) {
                  id2_data = -1;
                  id_data = -1;
                } else {
                  id2_data = (int)startIndex - 2;
                  id_data = wt_data[loop_ub] - 2;
                }
                loop_ub_tmp = id_data - id2_data;
                id_data = b_nextLineVar->size[0] * b_nextLineVar->size[1];
                b_nextLineVar->size[0] = 1;
                b_nextLineVar->size[1] = loop_ub_tmp;
                emxEnsureCapacity_char_T(b_nextLineVar, id_data);
                b_nextLineVar_data = b_nextLineVar->data;
                for (id_data = 0; id_data < loop_ub_tmp; id_data++) {
                  b_nextLineVar_data[id_data] =
                      (signed char)ant_data[(id2_data + id_data) + 1];
                }
                x = str2double(b_nextLineVar);
                if (((double)loop_ub + 1.0) + 1.0 > numInputs) {
                  b_fclose(fid);
                  exit(0);
                }
                rules_data[b_i].antecedent->data[loop_ub] = x.re;
                if ((double)i1 + 1.0 > ant->size[1]) {
                  i1 = -1;
                  id2_data = -1;
                } else {
                  i1 = wt_data[loop_ub] - 1;
                  id2_data = ant->size[1] - 1;
                }
                loop_ub_tmp = id2_data - i1;
                id2_data = b_nextLineVar->size[0] * b_nextLineVar->size[1];
                b_nextLineVar->size[0] = 1;
                b_nextLineVar->size[1] = loop_ub_tmp;
                emxEnsureCapacity_char_T(b_nextLineVar, id2_data);
                b_nextLineVar_data = b_nextLineVar->data;
                for (id2_data = 0; id2_data < loop_ub_tmp; id2_data++) {
                  b_nextLineVar_data[id2_data] =
                      (signed char)ant_data[(i1 + id2_data) + 1];
                }
                deblank(b_nextLineVar, a);
                x = str2double(a);
                rules_data[b_i].antecedent->data[loop_ub + 1] = x.re;
              } else {
                if (loop_ub + 1 == 1) {
                  startIndex = 1.0;
                } else {
                  startIndex = (double)wt_data[loop_ub - 1] + 1.0;
                }
                if (startIndex > (double)wt_data[loop_ub] - 1.0) {
                  i1 = -1;
                  id2_data = -1;
                } else {
                  i1 = (int)startIndex - 2;
                  id2_data = wt_data[loop_ub] - 2;
                }
                loop_ub_tmp = id2_data - i1;
                id2_data = b_nextLineVar->size[0] * b_nextLineVar->size[1];
                b_nextLineVar->size[0] = 1;
                b_nextLineVar->size[1] = loop_ub_tmp;
                emxEnsureCapacity_char_T(b_nextLineVar, id2_data);
                b_nextLineVar_data = b_nextLineVar->data;
                for (id2_data = 0; id2_data < loop_ub_tmp; id2_data++) {
                  b_nextLineVar_data[id2_data] =
                      (signed char)ant_data[(i1 + id2_data) + 1];
                }
                x = str2double(b_nextLineVar);
                if ((double)loop_ub + 1.0 > numInputs) {
                  b_fclose(fid);
                  exit(0);
                }
                rules_data[b_i].antecedent->data[loop_ub] = x.re;
              }
            }
          }
          i = c_nextLineVar->size[0] * c_nextLineVar->size[1];
          c_nextLineVar->size[0] = 1;
          c_nextLineVar->size[1] = con->size[1];
          emxEnsureCapacity_boolean_T(c_nextLineVar, i);
          c_nextLineVar_data = c_nextLineVar->data;
          loop_ub = con->size[1];
          for (i = 0; i < loop_ub; i++) {
            c_nextLineVar_data[i] = (con_data[i] == 32);
          }
          b_eml_find(c_nextLineVar, wt);
          wt_data = wt->data;
          if (wt->size[1] == 0) {
            if (numOutputs < 1.0) {
              b_fclose(fid);
              exit(0);
            }
            i = b_nextLineVar->size[0] * b_nextLineVar->size[1];
            b_nextLineVar->size[0] = 1;
            b_nextLineVar->size[1] = con->size[1];
            emxEnsureCapacity_char_T(b_nextLineVar, i);
            b_nextLineVar_data = b_nextLineVar->data;
            loop_ub = con->size[1];
            for (i = 0; i < loop_ub; i++) {
              b_nextLineVar_data[i] = (signed char)con_data[i];
            }
            x = str2double(b_nextLineVar);
            rules_data[b_i].consequent->data[0] = x.re;
          } else {
            i = wt->size[1];
            for (loop_ub = 0; loop_ub < i; loop_ub++) {
              if (loop_ub + 1 == wt->size[1]) {
                if (loop_ub + 1 == 1) {
                  startIndex = 1.0;
                } else {
                  startIndex = (double)wt_data[loop_ub - 1] + 1.0;
                }
                i1 = wt_data[loop_ub];
                if (startIndex > (double)i1 - 1.0) {
                  id2_data = -1;
                  id_data = -1;
                } else {
                  id2_data = (int)startIndex - 2;
                  id_data = wt_data[loop_ub] - 2;
                }
                loop_ub_tmp = id_data - id2_data;
                id_data = b_nextLineVar->size[0] * b_nextLineVar->size[1];
                b_nextLineVar->size[0] = 1;
                b_nextLineVar->size[1] = loop_ub_tmp;
                emxEnsureCapacity_char_T(b_nextLineVar, id_data);
                b_nextLineVar_data = b_nextLineVar->data;
                for (id_data = 0; id_data < loop_ub_tmp; id_data++) {
                  b_nextLineVar_data[id_data] =
                      (signed char)con_data[(id2_data + id_data) + 1];
                }
                x = str2double(b_nextLineVar);
                if (((double)loop_ub + 1.0) + 1.0 > numOutputs) {
                  b_fclose(fid);
                  exit(0);
                }
                rules_data[b_i].consequent->data[loop_ub] = x.re;
                if ((double)i1 + 1.0 > con->size[1]) {
                  i1 = -1;
                  id2_data = -1;
                } else {
                  i1 = wt_data[loop_ub] - 1;
                  id2_data = con->size[1] - 1;
                }
                loop_ub_tmp = id2_data - i1;
                id2_data = b_nextLineVar->size[0] * b_nextLineVar->size[1];
                b_nextLineVar->size[0] = 1;
                b_nextLineVar->size[1] = loop_ub_tmp;
                emxEnsureCapacity_char_T(b_nextLineVar, id2_data);
                b_nextLineVar_data = b_nextLineVar->data;
                for (id2_data = 0; id2_data < loop_ub_tmp; id2_data++) {
                  b_nextLineVar_data[id2_data] =
                      (signed char)con_data[(i1 + id2_data) + 1];
                }
                deblank(b_nextLineVar, a);
                x = str2double(a);
                rules_data[b_i].consequent->data[loop_ub + 1] = x.re;
              } else {
                if (loop_ub + 1 == 1) {
                  startIndex = 1.0;
                } else {
                  startIndex = (double)wt_data[loop_ub - 1] + 1.0;
                }
                if (startIndex > (double)wt_data[loop_ub] - 1.0) {
                  i1 = -1;
                  id2_data = -1;
                } else {
                  i1 = (int)startIndex - 2;
                  id2_data = wt_data[loop_ub] - 2;
                }
                loop_ub_tmp = id2_data - i1;
                id2_data = b_nextLineVar->size[0] * b_nextLineVar->size[1];
                b_nextLineVar->size[0] = 1;
                b_nextLineVar->size[1] = loop_ub_tmp;
                emxEnsureCapacity_char_T(b_nextLineVar, id2_data);
                b_nextLineVar_data = b_nextLineVar->data;
                for (id2_data = 0; id2_data < loop_ub_tmp; id2_data++) {
                  b_nextLineVar_data[id2_data] =
                      (signed char)con_data[(i1 + id2_data) + 1];
                }
                x = str2double(b_nextLineVar);
                if ((double)loop_ub + 1.0 > numOutputs) {
                  b_fclose(fid);
                  exit(0);
                }
                rules_data[b_i].consequent->data[loop_ub] = x.re;
              }
            }
          }
          b_i++;
        }
      }
    }
    emxFree_boolean_T(&c_nextLineVar);
    emxFree_char_T(&b_nextLineVar);
    emxFree_char_T(&a);
    emxFree_int32_T(&wt);
    emxFree_uint8_T(&con);
    emxFree_uint8_T(&ant);
    emxFree_uint8_T(&nextLineVar);
  }
}

/*
 * File trailer for getRules.c
 *
 * [EOF]
 */
