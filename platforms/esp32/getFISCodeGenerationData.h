//
// File: getFISCodeGenerationData.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//
#ifndef GETFISCODEGENERATIONDATA_H
#define GETFISCODEGENERATIONDATA_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct b_struct_T;
struct c_struct_T;

// Function Declarations
namespace coder
{
  void getFISCodeGenerationData(const ::coder::array<char, 2U> &name, ::coder::
    array<char, 2U> &fis_name, ::coder::array<char, 2U> &fis_type, ::coder::
    array<char, 2U> &fis_andMethod, ::coder::array<char, 2U> &fis_orMethod, ::
    coder::array<char, 2U> &fis_defuzzMethod, ::coder::array<char, 2U>
    &fis_impMethod, ::coder::array<char, 2U> &fis_aggMethod, ::coder::array<
    b_struct_T, 2U> &fis_input, ::coder::array<b_struct_T, 2U> &fis_output, ::
    coder::array<c_struct_T, 2U> &fis_rule);
}

#endif

//
// File trailer for getFISCodeGenerationData.h
//
// [EOF]
//
