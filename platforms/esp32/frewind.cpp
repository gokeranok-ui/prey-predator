//
// File: frewind.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "frewind.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include <stdio.h>

// Function Definitions
//
// Arguments    : double fileID
// Return Type  : void
//
namespace coder
{
  void frewind(double fileID)
  {
    FILE * b_NULL;
    FILE * filestar;
    b_NULL = NULL;
    filestar = fileManager(fileID);
    if ((!(filestar == b_NULL)) && (!(fileID == 0.0)) && (!(fileID == 1.0)) && (
         !(fileID == 2.0))) {
      fseek(filestar, 0, SEEK_SET);
    }
  }
}

//
// File trailer for frewind.cpp
//
// [EOF]
//
