/*
 * File: opkene_initialize.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "opkene_initialize.h"
#include "fileManager.h"
#include "opkene_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void opkene_initialize(void)
{
  filedata_init();
  isInitialized_opkene = true;
}

/*
 * File trailer for opkene_initialize.c
 *
 * [EOF]
 */
