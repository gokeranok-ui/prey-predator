/*
 * File: fileManager.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "opkene_types.h"

/* Function Declarations */
extern signed char cfopen(const emxArray_char_T *cfilename, const char
  * cpermission);
extern FILE * fileManager(double varargin_1);
extern void filedata_init(void);

#endif

/*
 * File trailer for fileManager.h
 *
 * [EOF]
 */
