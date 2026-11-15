/*
 * File: createMamdaniOutputMFCache.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

#ifndef CREATEMAMDANIOUTPUTMFCACHE_H
#define CREATEMAMDANIOUTPUTMFCACHE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "opkene_types.h"

/* Function Declarations */
extern void createMamdaniOutputMFCache(const d_emxArray_struct_T *fis_outputMF,
  int fis_numOutputs, const emxArray_int32_T *fis_numOutputMFs, const
  emxArray_int32_T *fis_numCumOutputMFs, const emxArray_real_T
  *outputSamplePoints, emxArray_real_T *outputMFCache);

#endif

/*
 * File trailer for createMamdaniOutputMFCache.h
 *
 * [EOF]
 */
