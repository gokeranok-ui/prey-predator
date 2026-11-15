/*
 * File: getFISCodeGenerationData.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

#ifndef GETFISCODEGENERATIONDATA_H
#define GETFISCODEGENERATIONDATA_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "opkene_types.h"

/* Function Declarations */
extern void getFISCodeGenerationData(const emxArray_char_T *name,
  emxArray_char_T *fis_name, emxArray_char_T *fis_type, emxArray_char_T
  *fis_andMethod, emxArray_char_T *fis_orMethod, emxArray_char_T
  *fis_defuzzMethod, emxArray_char_T *fis_impMethod, emxArray_char_T
  *fis_aggMethod, h_emxArray_struct_T *fis_input, h_emxArray_struct_T
  *fis_output, b_emxArray_struct_T *fis_rule);

#endif

/*
 * File trailer for getFISCodeGenerationData.h
 *
 * [EOF]
 */
