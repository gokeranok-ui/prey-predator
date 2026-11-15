/*
 * File: packageAndSetDataType.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

#ifndef PACKAGEANDSETDATATYPE_H
#define PACKAGEANDSETDATATYPE_H

/* Include Files */
#include "opkene_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_binary_expand_op(i_struct_T *in1, const emxArray_real_T *in2,
                        const emxArray_real_T *in3);

void binary_expand_op(i_struct_T *in1, const emxArray_real_T *in2,
                      const emxArray_real_T *in3);

void makeHomogenousMF(const b_emxArray_struct_T *in, g_emxArray_struct_T *out);

void setMFDataType(const g_emxArray_struct_T *in, e_emxArray_struct_T *out);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for packageAndSetDataType.h
 *
 * [EOF]
 */
