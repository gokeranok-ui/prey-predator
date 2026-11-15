/*
 * File: packageAndSetDataType.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

#ifndef PACKAGEANDSETDATATYPE_H
#define PACKAGEANDSETDATATYPE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "opkene_types.h"

/* Function Declarations */
extern void packageData(const emxArray_char_T *fisin_type, const emxArray_char_T
  *fisin_andMethod, const emxArray_char_T *fisin_orMethod, const emxArray_char_T
  *fisin_defuzzMethod, const emxArray_char_T *fisin_impMethod, const
  emxArray_char_T *fisin_aggMethod, const h_emxArray_struct_T *fisin_input,
  const h_emxArray_struct_T *fisin_output, const b_emxArray_struct_T *fisin_rule,
  j_struct_T *fisout);
extern void setMFDataType(const f_emxArray_struct_T *in, d_emxArray_struct_T
  *out);

#endif

/*
 * File trailer for packageAndSetDataType.h
 *
 * [EOF]
 */
