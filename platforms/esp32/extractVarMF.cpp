//
// File: extractVarMF.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "extractVarMF.h"
#include "opkene_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<e_struct_T, 2U> &varin
//                ::coder::array<cell_wrap_0, 2U> &varout
// Return Type  : void
//
namespace coder
{
  namespace fuzzy
  {
    namespace internal
    {
      namespace codegen
      {
        void extractVarMF(const ::coder::array<e_struct_T, 2U> &varin, ::coder::
                          array<cell_wrap_0, 2U> &varout)
        {
          array<i_struct_T, 2U> mf;
          i_struct_T expl_temp;
          int i;
          varout.set_size(1, varin.size(1));
          i = varin.size(1);
          for (int b_i = 0; b_i < i; b_i++) {
            int i1;
            int loop_ub;
            i1 = varin[b_i].origNumMF;
            mf.set_size(1, varin[varin.size(0) * b_i].origNumMF);
            for (int j = 0; j < i1; j++) {
              int b_loop_ub;
              int i2;
              if (1 > varin[b_i].mf[j].origTypeLength) {
                loop_ub = 0;
              } else {
                loop_ub = varin[b_i].mf[j].origTypeLength;
              }

              if (1 > varin[b_i].mf[j].origParamLength) {
                b_loop_ub = 0;
              } else {
                b_loop_ub = varin[b_i].mf[j].origParamLength;
              }

              expl_temp.type.set_size(1, loop_ub);
              for (i2 = 0; i2 < loop_ub; i2++) {
                expl_temp.type[i2] = varin[b_i].mf[j].type[i2];
              }

              expl_temp.params.set_size(1, b_loop_ub);
              for (i2 = 0; i2 < b_loop_ub; i2++) {
                expl_temp.params[i2] = varin[b_i].mf[j].params[i2];
              }

              mf[j] = expl_temp;
            }

            varout[varout.size(0) * b_i].f1.set_size(1, mf.size(1));
            loop_ub = mf.size(0) * mf.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              varout[b_i].f1[i1] = mf[i1];
            }
          }
        }
      }
    }
  }
}

//
// File trailer for extractVarMF.cpp
//
// [EOF]
//
