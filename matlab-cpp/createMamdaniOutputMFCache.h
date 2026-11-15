//
// File: createMamdaniOutputMFCache.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//
#ifndef CREATEMAMDANIOUTPUTMFCACHE_H
#define CREATEMAMDANIOUTPUTMFCACHE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct e_struct_T;

// Function Declarations
namespace coder
{
  void createMamdaniOutputMFCache(const ::coder::array<e_struct_T, 2U>
    &fis_outputMF, int fis_numOutputs, const ::coder::array<int, 2U>
    &fis_numOutputMFs, const ::coder::array<int, 2U> &fis_numCumOutputMFs, const
    ::coder::array<double, 2U> &outputSamplePoints, ::coder::array<double, 2U>
    &outputMFCache);
}

#endif

//
// File trailer for createMamdaniOutputMFCache.h
//
// [EOF]
//
