/*
 * File: createMamdaniOutputMFCache.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

#ifndef CREATEMAMDANIOUTPUTMFCACHE_H
#define CREATEMAMDANIOUTPUTMFCACHE_H

/* Include Files */
#include "opkene_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void createMamdaniOutputMFCache(const e_emxArray_struct_T *fis_outputMF,
                                int fis_numOutputs,
                                const emxArray_int32_T *fis_numOutputMFs,
                                const emxArray_int32_T *fis_numCumOutputMFs,
                                const emxArray_real_T *outputSamplePoints,
                                emxArray_real_T *outputMFCache);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for createMamdaniOutputMFCache.h
 *
 * [EOF]
 */
