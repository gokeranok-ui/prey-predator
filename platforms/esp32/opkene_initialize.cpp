//
// File: opkene_initialize.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "opkene_initialize.h"
#include "fileManager.h"
#include "opkene_data.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void opkene_initialize()
{
  filedata_init();
  isInitialized_opkene = true;
}

//
// File trailer for opkene_initialize.cpp
//
// [EOF]
//
