//
// File: packageAndSetDataType.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "packageAndSetDataType.h"
#include "opkene_internal_types.h"
#include "opkene_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<b_struct_T, 2U> &in
//                ::coder::array<h_struct_T, 2U> &out
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
        void makeHomogenousMF(const ::coder::array<b_struct_T, 2U> &in, ::coder::
                              array<h_struct_T, 2U> &out)
        {
          g_struct_T mfStruct;
          h_struct_T varStruct;
          double maxMFParamLength;
          double maxMFTypeLength;
          double maxNumMF;
          int b_loop_ub;
          int i;
          int i1;
          int loop_ub;
          int mfID;
          int out_idx_1;
          int outsize_idx_1;
          int varID;
          mfStruct.type.set_size(1, 1);
          mfStruct.type[0] = '\x00';
          mfStruct.origTypeLength = 0.0;
          mfStruct.params.set_size(1, 1);
          mfStruct.params[0] = 0.0;
          mfStruct.origParamLength = 0.0;
          varStruct.mf.set_size(1, 1);
          varStruct.mf[0] = mfStruct;
          varStruct.origNumMF = 0.0;
          out.set_size(1, in.size(1));
          loop_ub = in.size(1);
          for (i = 0; i < loop_ub; i++) {
            out[i] = varStruct;
          }

          maxNumMF = 0.0;
          maxMFTypeLength = 0.0;
          maxMFParamLength = 0.0;
          i = in.size(1);
          for (varID = 0; varID < i; varID++) {
            if (maxNumMF < in[varID].origNumMF) {
              maxNumMF = in[varID].origNumMF;
            }

            out_idx_1 = static_cast<int>(in[varID].origNumMF);
            for (mfID = 0; mfID < out_idx_1; mfID++) {
              if (maxMFTypeLength < in[varID].mf[mfID].origTypeLength) {
                maxMFTypeLength = in[varID].mf[mfID].origTypeLength;
              }

              if (maxMFParamLength < in[varID].mf[mfID].origParamLength) {
                maxMFParamLength = in[varID].mf[mfID].origParamLength;
              }
            }
          }

          i = in.size(1);
          if (0 <= in.size(1) - 1) {
            outsize_idx_1 = static_cast<int>(maxNumMF);
            b_loop_ub = static_cast<int>(maxNumMF) - 1;
            i1 = static_cast<int>(maxNumMF);
          }

          for (varID = 0; varID < i; varID++) {
            out[varID].origNumMF = in[varID].origNumMF;
            out[out.size(0) * varID].mf.set_size(1, outsize_idx_1);
            for (out_idx_1 = 0; out_idx_1 <= b_loop_ub; out_idx_1++) {
              out[varID].mf[out_idx_1] = mfStruct;
            }

            for (mfID = 0; mfID < i1; mfID++) {
              out[out.size(0) * varID].mf[out[out.size(0) * varID].mf.size(0) *
                mfID].type.set_size(1, (static_cast<int>(maxMFTypeLength)));
              loop_ub = out[varID].mf[mfID].type.size(0);
              out_idx_1 = out[varID].mf[mfID].type.size(1);
              out[out.size(0) * varID].mf[out[out.size(0) * varID].mf.size(0) *
                mfID].type.set_size(1, out_idx_1);
              loop_ub *= out_idx_1;
              for (out_idx_1 = 0; out_idx_1 < loop_ub; out_idx_1++) {
                out[varID].mf[mfID].type[out_idx_1] = '\x00';
              }

              loop_ub = static_cast<int>(maxMFParamLength) - 1;
              out[out.size(0) * varID].mf[out[out.size(0) * varID].mf.size(0) *
                mfID].params.set_size(1, (static_cast<int>(maxMFParamLength)));
              for (out_idx_1 = 0; out_idx_1 <= loop_ub; out_idx_1++) {
                out[varID].mf[mfID].params[out_idx_1] = 0.0;
              }

              out[varID].mf[mfID].origTypeLength = 0.0;
              out[varID].mf[mfID].origParamLength = 0.0;
              if (static_cast<double>(mfID) + 1.0 <= out[varID].origNumMF) {
                loop_ub = in[varID].mf[mfID].type.size(0) * in[varID].mf[mfID].
                  type.size(1) - 1;
                out[out.size(0) * varID].mf[out[out.size(0) * varID].mf.size(0) *
                  mfID].type.set_size(1, in[in.size(0) * varID].mf[in[in.size(0)
                                      * varID].mf.size(0) * mfID].type.size(1));
                for (out_idx_1 = 0; out_idx_1 <= loop_ub; out_idx_1++) {
                  out[varID].mf[mfID].type[out_idx_1] = in[varID].mf[mfID]
                    .type[out_idx_1];
                }

                out[varID].mf[mfID].origTypeLength = in[varID].mf[mfID].
                  origTypeLength;
                loop_ub = in[varID].mf[mfID].params.size(0) * in[varID].mf[mfID]
                  .params.size(1) - 1;
                out[out.size(0) * varID].mf[out[out.size(0) * varID].mf.size(0) *
                  mfID].params.set_size(1, in[in.size(0) * varID].mf[in[in.size
                  (0) * varID].mf.size(0) * mfID].params.size(1));
                for (out_idx_1 = 0; out_idx_1 <= loop_ub; out_idx_1++) {
                  out[varID].mf[mfID].params[out_idx_1] = in[varID].mf[mfID].
                    params[out_idx_1];
                }

                out[varID].mf[mfID].origParamLength = in[varID].mf[mfID].
                  origParamLength;
              }
            }
          }
        }

        //
        // Arguments    : const ::coder::array<h_struct_T, 2U> &in
        //                ::coder::array<e_struct_T, 2U> &out
        // Return Type  : void
        //
        void setMFDataType(const ::coder::array<h_struct_T, 2U> &in, ::coder::
                           array<e_struct_T, 2U> &out)
        {
          d_struct_T mfStruct;
          e_struct_T varStruct;
          int i;
          int loop_ub;
          mfStruct.type.set_size(1, in[0].mf[0].type.size(1));
          loop_ub = in[0].mf[0].type.size(1);
          for (i = 0; i < loop_ub; i++) {
            mfStruct.type[i] = '\x00';
          }

          mfStruct.origTypeLength = 0;
          mfStruct.params.set_size(1, in[0].mf[0].params.size(1));
          loop_ub = in[0].mf[0].params.size(1);
          for (i = 0; i < loop_ub; i++) {
            mfStruct.params[i] = 0.0;
          }

          mfStruct.origParamLength = 0;
          varStruct.mf.set_size(1, in[0].mf.size(1));
          loop_ub = in[0].mf.size(1);
          for (i = 0; i < loop_ub; i++) {
            varStruct.mf[i] = mfStruct;
          }

          varStruct.origNumMF = 0;
          out.set_size(1, in.size(1));
          loop_ub = in.size(1);
          for (i = 0; i < loop_ub; i++) {
            out[i] = varStruct;
          }

          i = in.size(1);
          for (int varID = 0; varID < i; varID++) {
            double d;
            int i1;
            d = rt_roundd_snf(in[varID].origNumMF);
            if (d < 2.147483648E+9) {
              if (d >= -2.147483648E+9) {
                i1 = static_cast<int>(d);
              } else {
                i1 = MIN_int32_T;
              }
            } else if (d >= 2.147483648E+9) {
              i1 = MAX_int32_T;
            } else {
              i1 = 0;
            }

            out[varID].origNumMF = i1;
            i1 = in[0].mf.size(1);
            for (int mfID = 0; mfID < i1; mfID++) {
              int i2;
              loop_ub = in[varID].mf[mfID].type.size(0) * in[varID].mf[mfID].
                type.size(1) - 1;
              out[out.size(0) * varID].mf[out[out.size(0) * varID].mf.size(0) *
                mfID].type.set_size(1, in[in.size(0) * varID].mf[in[in.size(0) *
                                    varID].mf.size(0) * mfID].type.size(1));
              for (i2 = 0; i2 <= loop_ub; i2++) {
                out[varID].mf[mfID].type[i2] = in[varID].mf[mfID].type[i2];
              }

              loop_ub = in[varID].mf[mfID].params.size(0) * in[varID].mf[mfID].
                params.size(1) - 1;
              out[out.size(0) * varID].mf[out[out.size(0) * varID].mf.size(0) *
                mfID].params.set_size(1, in[in.size(0) * varID].mf[in[in.size(0)
                * varID].mf.size(0) * mfID].params.size(1));
              for (i2 = 0; i2 <= loop_ub; i2++) {
                out[varID].mf[mfID].params[i2] = in[varID].mf[mfID].params[i2];
              }

              d = rt_roundd_snf(in[varID].mf[mfID].origTypeLength);
              if (d < 2.147483648E+9) {
                if (d >= -2.147483648E+9) {
                  i2 = static_cast<int>(d);
                } else {
                  i2 = MIN_int32_T;
                }
              } else if (d >= 2.147483648E+9) {
                i2 = MAX_int32_T;
              } else {
                i2 = 0;
              }

              out[varID].mf[mfID].origTypeLength = i2;
              d = rt_roundd_snf(in[varID].mf[mfID].origParamLength);
              if (d < 2.147483648E+9) {
                if (d >= -2.147483648E+9) {
                  i2 = static_cast<int>(d);
                } else {
                  i2 = MIN_int32_T;
                }
              } else if (d >= 2.147483648E+9) {
                i2 = MAX_int32_T;
              } else {
                i2 = 0;
              }

              out[varID].mf[mfID].origParamLength = i2;
            }
          }
        }
      }
    }
  }
}

//
// File trailer for packageAndSetDataType.cpp
//
// [EOF]
//
