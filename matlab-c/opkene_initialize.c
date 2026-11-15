/*
 * File: opkene_initialize.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "opkene_initialize.h"
#include "fileManager.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void opkene_initialize(void)
{
  rt_InitInfAndNaN(8U);
  filedata_init();
}

/*
 * File trailer for opkene_initialize.c
 *
 * [EOF]
 */
