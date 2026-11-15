/*
 * File: readFISAsHomogenousStructure.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

#ifndef READFISASHOMOGENOUSSTRUCTURE_H
#define READFISASHOMOGENOUSSTRUCTURE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "opkene_types.h"

/* Type Definitions */

/* Function Declarations */
extern void b_findTopic(double fid, double maxLineLength, emxArray_uint8_T
  *topicValue);
extern void b_getVar(double fid, double maxLineLength, double
                     info_maxInputNameLength, double info_maxNumMF, double
                     info_maxMFNameLength, double info_maxMFTypeLength, double
                     info_maxMFParamLength, double info_numVars, boolean_T
                     updateOutputRange, h_emxArray_struct_T *var);
extern void b_getVarInfo(double fid, double maxLineLength, boolean_T
  checkForSugenoMFs, double *info_maxInputNameLength, double *info_maxNumMF,
  double *info_maxMFNameLength, double *info_maxMFTypeLength, double
  *info_maxMFParamLength, double *info_numVars, boolean_T *info_hasSugenoMFs);
extern void c_findTopic(double fid, double maxLineLength, emxArray_uint8_T
  *topicValue);
extern void d_findTopic(double fid, double maxLineLength, emxArray_uint8_T
  *topicValue);
extern void e_findTopic(double fid, double maxLineLength, emxArray_uint8_T
  *topicValue);
extern void f_findTopic(double fid, double maxLineLength, emxArray_uint8_T
  *topicValue);
extern void findTopic(double fid, double maxLineLength, emxArray_uint8_T
                      *topicValue);
extern void g_findTopic(double fid, double maxLineLength, emxArray_uint8_T
  *topicValue);
extern double getMaxLineLength(double fid);
extern void getNextLine(double fid, double maxLength, emxArray_uint8_T *result);
extern void getRules(double fid, double maxLineLength, double numInputs, double
                     numOutputs, b_emxArray_struct_T *rules);
extern void getVar(double fid, double maxLineLength, double
                   info_maxInputNameLength, double info_maxNumMF, double
                   info_maxMFNameLength, double info_maxMFTypeLength, double
                   info_maxMFParamLength, double info_numVars,
                   h_emxArray_struct_T *var);
extern void getVarInfo(double fid, double maxLineLength, double
  *info_maxInputNameLength, double *info_maxNumMF, double *info_maxMFNameLength,
  double *info_maxMFTypeLength, double *info_maxMFParamLength, double
  *info_numVars, boolean_T *info_hasSugenoMFs);

#endif

/*
 * File trailer for readFISAsHomogenousStructure.h
 *
 * [EOF]
 */
