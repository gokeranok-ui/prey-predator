/*
 * File: readFISAsHomogenousStructure.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

#ifndef READFISASHOMOGENOUSSTRUCTURE_H
#define READFISASHOMOGENOUSSTRUCTURE_H

/* Include Files */
#include "opkene_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_getVar(double fid, double maxLineLength, double info_maxInputNameLength,
              double info_maxNumMF, double info_maxMFNameLength,
              double info_maxMFTypeLength, double info_maxMFParamLength,
              double info_numVars, boolean_T updateOutputRange,
              b_emxArray_struct_T *var);

double b_getVarInfo(double fid, double maxLineLength,
                    boolean_T checkForSugenoMFs, double *info_maxNumMF,
                    double *info_maxMFNameLength, double *info_maxMFTypeLength,
                    double *info_maxMFParamLength, double *info_numVars,
                    boolean_T *info_hasSugenoMFs);

void getVar(double fid, double maxLineLength, double info_maxInputNameLength,
            double info_maxNumMF, double info_maxMFNameLength,
            double info_maxMFTypeLength, double info_maxMFParamLength,
            double info_numVars, b_emxArray_struct_T *var);

double getVarInfo(double fid, double maxLineLength, double *info_maxNumMF,
                  double *info_maxMFNameLength, double *info_maxMFTypeLength,
                  double *info_maxMFParamLength, double *info_numVars,
                  boolean_T *info_hasSugenoMFs);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for readFISAsHomogenousStructure.h
 *
 * [EOF]
 */
