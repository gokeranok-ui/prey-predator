//
// File: packageAndSetDataType.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//
#ifndef PACKAGEANDSETDATATYPE_H
#define PACKAGEANDSETDATATYPE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct b_struct_T;
struct h_struct_T;
struct e_struct_T;

// Function Declarations
namespace coder
{
  namespace fuzzy
  {
    namespace internal
    {
      namespace codegen
      {
        void makeHomogenousMF(const ::coder::array<b_struct_T, 2U> &in, ::coder::
                              array<h_struct_T, 2U> &out);
        void setMFDataType(const ::coder::array<h_struct_T, 2U> &in, ::coder::
                           array<e_struct_T, 2U> &out);
      }
    }
  }
}

#endif

//
// File trailer for packageAndSetDataType.h
//
// [EOF]
//
