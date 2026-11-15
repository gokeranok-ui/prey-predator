//
// File: readFISAsHomogenousStructure.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//
#ifndef READFISASHOMOGENOUSSTRUCTURE_H
#define READFISASHOMOGENOUSSTRUCTURE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct b_struct_T;

// Function Declarations
namespace coder
{
  namespace fuzzy
  {
    namespace internal
    {
      namespace codegen
      {
        void b_getVar(double fid, double maxLineLength, double
                      info_maxInputNameLength, double info_maxNumMF, double
                      info_maxMFNameLength, double info_maxMFTypeLength, double
                      info_maxMFParamLength, double info_numVars, boolean_T
                      updateOutputRange, ::coder::array<b_struct_T, 2U> &var);
        void b_getVarInfo(double fid, double maxLineLength, boolean_T
                          checkForSugenoMFs, double *info_maxInputNameLength,
                          double *info_maxNumMF, double *info_maxMFNameLength,
                          double *info_maxMFTypeLength, double
                          *info_maxMFParamLength, double *info_numVars,
                          boolean_T *info_hasSugenoMFs);
        void getVar(double fid, double maxLineLength, double
                    info_maxInputNameLength, double info_maxNumMF, double
                    info_maxMFNameLength, double info_maxMFTypeLength, double
                    info_maxMFParamLength, double info_numVars, ::coder::array<
                    b_struct_T, 2U> &var);
        void getVarInfo(double fid, double maxLineLength, double
                        *info_maxInputNameLength, double *info_maxNumMF, double *
                        info_maxMFNameLength, double *info_maxMFTypeLength,
                        double *info_maxMFParamLength, double *info_numVars,
                        boolean_T *info_hasSugenoMFs);
      }
    }
  }
}

#endif

//
// File trailer for readFISAsHomogenousStructure.h
//
// [EOF]
//
