/*
 * File: evaluateFIS.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

#ifndef EVALUATEFIS_H
#define EVALUATEFIS_H

/* Include Files */
#include "opkene_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_evaluateFIS(const emxArray_real_T *inputs, const i_struct_T *fis,
                   emxArray_real_T *y);

void evaluateFIS(const emxArray_real_T *inputs, const i_struct_T *fis,
                 emxArray_real_T *y);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for evaluateFIS.h
 *
 * [EOF]
 */
