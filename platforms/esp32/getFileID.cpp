//
// File: getFileID.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "getFileID.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <stddef.h>
#include <stdio.h>

// Function Definitions
//
// Arguments    : const ::coder::array<char, 2U> &name
//                double *fid
//                double *maxLineLength
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
        void getFileID(const ::coder::array<char, 2U> &name, double *fid, double
                       *maxLineLength)
        {
          FILE * b_NULL;
          FILE * filestar;
          size_t nBytes;
          array<unsigned char, 2U> At;
          array<unsigned char, 1U> contents;
          int c;
          int i;
          int loop_ub;
          int numRead;
          unsigned char tbuf[1024];
          signed char fileid;
          fileid = cfopen(name, "rb");
          *fid = fileid;
          if (fileid < 0) {
            exit(0);
          }

          nBytes = sizeof(unsigned char);
          filestar = fileManager(static_cast<double>(fileid));
          if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
            filestar = NULL;
          }

          At.set_size(0, 1);
          if (!(filestar == NULL)) {
            c = 1;
            while (c > 0) {
              c = 0;
              numRead = 1;
              while ((c < 1024) && (numRead > 0)) {
                size_t numReadSizeT;
                numReadSizeT = fread(&tbuf[c], nBytes, 1024 - c, filestar);
                numRead = (int)numReadSizeT;
                c += (int)numReadSizeT;
              }

              if (1 > c) {
                numRead = 0;
              } else {
                numRead = c;
              }

              contents.set_size((At.size(0) + numRead));
              loop_ub = At.size(0);
              for (i = 0; i < loop_ub; i++) {
                contents[i] = At[i];
              }

              for (i = 0; i < numRead; i++) {
                contents[i + At.size(0)] = tbuf[i];
              }

              At.set_size(contents.size(0), 1);
              numRead = contents.size(0);
              for (i = 0; i < numRead; i++) {
                At[i] = contents[i];
              }
            }
          }

          contents.set_size(At.size(0));
          numRead = At.size(0);
          for (i = 0; i < numRead; i++) {
            contents[i] = At[i];
          }

          *maxLineLength = 0.0;
          numRead = 0;
          i = contents.size(0);
          for (c = 0; c < i; c++) {
            if (contents[c] == 10) {
              loop_ub = c - numRead;
              if (loop_ub > static_cast<int>(*maxLineLength)) {
                *maxLineLength = loop_ub;
                numRead = c;
              }
            }
          }

          if (*maxLineLength == 0.0) {
            cfclose(static_cast<double>(fileid));
            exit(0);
          }

          b_NULL = NULL;
          filestar = fileManager(static_cast<double>(fileid));
          if ((!(filestar == b_NULL)) && (fileid != 0) && (fileid != 1) &&
              (fileid != 2)) {
            fseek(filestar, 0, SEEK_SET);
          }
        }
      }
    }
  }
}

//
// File trailer for getFileID.cpp
//
// [EOF]
//

// File trailer for getFileID.cpp
//
// [EOF]
//
