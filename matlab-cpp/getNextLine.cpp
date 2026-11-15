//
// File: getNextLine.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "getNextLine.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <stddef.h>
#include <stdio.h>

// Function Definitions
//
// Arguments    : double fid
//                double maxLength
//                ::coder::array<unsigned char, 2U> &result
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
        void getLine(double fid, double maxLength, ::coder::array<unsigned char,
                     2U> &result)
        {
          double count;
          int loop_ub;
          unsigned char value_data[1];
          unsigned char buf;
          boolean_T x_data[1];
          boolean_T p;
          result.set_size(1, (static_cast<int>(maxLength)));
          loop_ub = static_cast<int>(maxLength);
          for (int i = 0; i < loop_ub; i++) {
            result[i] = 0U;
          }

          count = 0.0;
          if ((fid != 0.0) && (fid != 1.0) && (fid != 2.0)) {
            p = true;
          } else {
            p = false;
          }

          FILE * filestar;
          int exitg1;
          do {
            exitg1 = 0;
            filestar = fileManager(fid);
            if (!p) {
              filestar = NULL;
            }

            if (filestar == NULL) {
              exitg1 = 1;
            } else {
              size_t numReadSizeT;
              value_data[0] = 0U;
              numReadSizeT = fread(&buf, sizeof(unsigned char), 1, filestar);
              if (0 <= (int)numReadSizeT - 1) {
                value_data[0] = buf;
              }

              if ((int)numReadSizeT + 1 <= 1) {
                value_data[0] = 0U;
              }

              if ((int)numReadSizeT < 1) {
                exitg1 = 1;
              } else {
                boolean_T y;
                x_data[0] = (value_data[0] == 10);
                y = x_data[0];
                if (y) {
                  if (count == 0.0) {
                    result[0] = value_data[0];
                  }

                  exitg1 = 1;
                } else {
                  count++;
                  result[static_cast<int>(count) - 1] = value_data[0];
                }
              }
            }
          } while (exitg1 == 0);
        }

        //
        // Arguments    : double fid
        //                double maxLength
        //                ::coder::array<unsigned char, 2U> &result
        // Return Type  : void
        //
        void getNextLine(double fid, double maxLength, ::coder::array<unsigned
                         char, 2U> &result)
        {
          getLine(fid, maxLength, result);
          int exitg1;
          int ix;
          boolean_T exitg2;
          boolean_T y;
          do {
            exitg1 = 0;
            y = false;
            ix = 1;
            exitg2 = false;
            while ((!exitg2) && (ix <= result.size(1))) {
              if (result[ix - 1] == 0) {
                ix++;
              } else {
                y = true;
                exitg2 = true;
              }
            }

            if (y) {
              y = !(static_cast<signed char>(result[0]) != '%');
              if ((!y) && (result[0] != 10)) {
                exitg1 = 1;
              } else {
                getLine(fid, maxLength, result);
              }
            } else {
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }
      }
    }
  }
}

//
// File trailer for getNextLine.cpp
//
// [EOF]
//
