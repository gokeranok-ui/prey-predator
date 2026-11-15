//
// File: findTopic.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "findTopic.h"
#include "fileManager.h"
#include "getNextLine.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <stdio.h>

// Function Definitions
//
// Arguments    : double fid
//                double maxLineLength
//                ::coder::array<unsigned char, 2U> &topicValue
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
        void b_findTopic(double fid, double maxLineLength, ::coder::array<
                         unsigned char, 2U> &topicValue)
        {
          static const unsigned char uv[5] = { 84U, 121U, 112U, 101U, 61U };

          array<int, 2U> r;
          array<unsigned char, 2U> buffer;
          array<unsigned char, 2U> nextLineVar;
          array<boolean_T, 2U> bufferEqual;
          int i;
          int loop_ub;
          boolean_T exitg1;
          boolean_T topicFound;
          buffer.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            buffer[i] = 0U;
          }

          topicValue.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            topicValue[i] = 0U;
          }

          for (i = 0; i < 5; i++) {
            buffer[i] = uv[i];
          }

          topicFound = false;
          exitg1 = false;
          while ((!exitg1) && (!topicFound)) {
            FILE * b_NULL;
            FILE * filestar;
            boolean_T exitg3;
            boolean_T y;
            getLine(fid, maxLineLength, nextLineVar);
            int exitg2;
            do {
              exitg2 = 0;
              y = false;
              loop_ub = 1;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= nextLineVar.size(1))) {
                if (nextLineVar[loop_ub - 1] == 0) {
                  loop_ub++;
                } else {
                  y = true;
                  exitg3 = true;
                }
              }

              if (y) {
                y = !(static_cast<signed char>(nextLineVar[0]) != '%');
                if ((!y) && (nextLineVar[0] != 10)) {
                  exitg2 = 1;
                } else {
                  getLine(fid, maxLineLength, nextLineVar);
                }
              } else {
                exitg2 = 1;
              }
            } while (exitg2 == 0);

            b_NULL = NULL;
            filestar = fileManager(fid);
            if (filestar == b_NULL) {
              i = 0;
            } else {
              int st;
              st = feof(filestar);
              i = ((int)st != 0);
            }

            if (i != 0) {
              exitg1 = true;
            } else {
              bufferEqual.set_size(1, nextLineVar.size(1));
              loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
              for (i = 0; i < loop_ub; i++) {
                bufferEqual[i] = (nextLineVar[i] == buffer[i]);
              }

              y = true;
              loop_ub = 0;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= 4)) {
                if (!bufferEqual[loop_ub]) {
                  y = false;
                  exitg3 = true;
                } else {
                  loop_ub++;
                }
              }

              if (y) {
                int b_i;
                int end;
                int i1;
                topicFound = true;
                bufferEqual.set_size(1, nextLineVar.size(1));
                loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                for (i = 0; i < loop_ub; i++) {
                  bufferEqual[i] = ((nextLineVar[i] != 0) != (buffer[i] != 0));
                }

                end = bufferEqual.size(1);
                loop_ub = 0;
                for (b_i = 0; b_i < end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                if (2.0 > static_cast<double>(loop_ub) - 1.0) {
                  i = 0;
                  i1 = 0;
                } else {
                  i = 1;
                  i1 = loop_ub - 1;
                }

                end = bufferEqual.size(1) - 1;
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                r.set_size(1, loop_ub);
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    r[loop_ub] = b_i + 1;
                    loop_ub++;
                  }
                }

                loop_ub = i1 - i;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  topicValue[i1] = nextLineVar[r[i + i1] - 1];
                }
              }
            }
          }
        }

        //
        // Arguments    : double fid
        //                double maxLineLength
        //                ::coder::array<unsigned char, 2U> &topicValue
        // Return Type  : void
        //
        void c_findTopic(double fid, double maxLineLength, ::coder::array<
                         unsigned char, 2U> &topicValue)
        {
          static const unsigned char uv[10] = { 65U, 110U, 100U, 77U, 101U, 116U,
            104U, 111U, 100U, 61U };

          array<int, 2U> r;
          array<unsigned char, 2U> buffer;
          array<unsigned char, 2U> nextLineVar;
          array<boolean_T, 2U> bufferEqual;
          int i;
          int loop_ub;
          boolean_T exitg1;
          boolean_T topicFound;
          buffer.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            buffer[i] = 0U;
          }

          topicValue.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            topicValue[i] = 0U;
          }

          for (i = 0; i < 10; i++) {
            buffer[i] = uv[i];
          }

          topicFound = false;
          exitg1 = false;
          while ((!exitg1) && (!topicFound)) {
            FILE * b_NULL;
            FILE * filestar;
            boolean_T exitg3;
            boolean_T y;
            getLine(fid, maxLineLength, nextLineVar);
            int exitg2;
            do {
              exitg2 = 0;
              y = false;
              loop_ub = 1;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= nextLineVar.size(1))) {
                if (nextLineVar[loop_ub - 1] == 0) {
                  loop_ub++;
                } else {
                  y = true;
                  exitg3 = true;
                }
              }

              if (y) {
                y = !(static_cast<signed char>(nextLineVar[0]) != '%');
                if ((!y) && (nextLineVar[0] != 10)) {
                  exitg2 = 1;
                } else {
                  getLine(fid, maxLineLength, nextLineVar);
                }
              } else {
                exitg2 = 1;
              }
            } while (exitg2 == 0);

            b_NULL = NULL;
            filestar = fileManager(fid);
            if (filestar == b_NULL) {
              i = 0;
            } else {
              int st;
              st = feof(filestar);
              i = ((int)st != 0);
            }

            if (i != 0) {
              exitg1 = true;
            } else {
              bufferEqual.set_size(1, nextLineVar.size(1));
              loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
              for (i = 0; i < loop_ub; i++) {
                bufferEqual[i] = (nextLineVar[i] == buffer[i]);
              }

              y = true;
              loop_ub = 0;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= 9)) {
                if (!bufferEqual[loop_ub]) {
                  y = false;
                  exitg3 = true;
                } else {
                  loop_ub++;
                }
              }

              if (y) {
                int b_i;
                int end;
                int i1;
                topicFound = true;
                bufferEqual.set_size(1, nextLineVar.size(1));
                loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                for (i = 0; i < loop_ub; i++) {
                  bufferEqual[i] = ((nextLineVar[i] != 0) != (buffer[i] != 0));
                }

                end = bufferEqual.size(1);
                loop_ub = 0;
                for (b_i = 0; b_i < end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                if (2.0 > static_cast<double>(loop_ub) - 1.0) {
                  i = 0;
                  i1 = 0;
                } else {
                  i = 1;
                  i1 = loop_ub - 1;
                }

                end = bufferEqual.size(1) - 1;
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                r.set_size(1, loop_ub);
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    r[loop_ub] = b_i + 1;
                    loop_ub++;
                  }
                }

                loop_ub = i1 - i;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  topicValue[i1] = nextLineVar[r[i + i1] - 1];
                }
              }
            }
          }
        }

        //
        // Arguments    : double fid
        //                double maxLineLength
        //                ::coder::array<unsigned char, 2U> &topicValue
        // Return Type  : void
        //
        void d_findTopic(double fid, double maxLineLength, ::coder::array<
                         unsigned char, 2U> &topicValue)
        {
          static const unsigned char uv[9] = { 79U, 114U, 77U, 101U, 116U, 104U,
            111U, 100U, 61U };

          array<int, 2U> r;
          array<unsigned char, 2U> buffer;
          array<unsigned char, 2U> nextLineVar;
          array<boolean_T, 2U> bufferEqual;
          int i;
          int loop_ub;
          boolean_T exitg1;
          boolean_T topicFound;
          buffer.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            buffer[i] = 0U;
          }

          topicValue.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            topicValue[i] = 0U;
          }

          for (i = 0; i < 9; i++) {
            buffer[i] = uv[i];
          }

          topicFound = false;
          exitg1 = false;
          while ((!exitg1) && (!topicFound)) {
            FILE * b_NULL;
            FILE * filestar;
            boolean_T exitg3;
            boolean_T y;
            getLine(fid, maxLineLength, nextLineVar);
            int exitg2;
            do {
              exitg2 = 0;
              y = false;
              loop_ub = 1;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= nextLineVar.size(1))) {
                if (nextLineVar[loop_ub - 1] == 0) {
                  loop_ub++;
                } else {
                  y = true;
                  exitg3 = true;
                }
              }

              if (y) {
                y = !(static_cast<signed char>(nextLineVar[0]) != '%');
                if ((!y) && (nextLineVar[0] != 10)) {
                  exitg2 = 1;
                } else {
                  getLine(fid, maxLineLength, nextLineVar);
                }
              } else {
                exitg2 = 1;
              }
            } while (exitg2 == 0);

            b_NULL = NULL;
            filestar = fileManager(fid);
            if (filestar == b_NULL) {
              i = 0;
            } else {
              int st;
              st = feof(filestar);
              i = ((int)st != 0);
            }

            if (i != 0) {
              exitg1 = true;
            } else {
              bufferEqual.set_size(1, nextLineVar.size(1));
              loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
              for (i = 0; i < loop_ub; i++) {
                bufferEqual[i] = (nextLineVar[i] == buffer[i]);
              }

              y = true;
              loop_ub = 0;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= 8)) {
                if (!bufferEqual[loop_ub]) {
                  y = false;
                  exitg3 = true;
                } else {
                  loop_ub++;
                }
              }

              if (y) {
                int b_i;
                int end;
                int i1;
                topicFound = true;
                bufferEqual.set_size(1, nextLineVar.size(1));
                loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                for (i = 0; i < loop_ub; i++) {
                  bufferEqual[i] = ((nextLineVar[i] != 0) != (buffer[i] != 0));
                }

                end = bufferEqual.size(1);
                loop_ub = 0;
                for (b_i = 0; b_i < end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                if (2.0 > static_cast<double>(loop_ub) - 1.0) {
                  i = 0;
                  i1 = 0;
                } else {
                  i = 1;
                  i1 = loop_ub - 1;
                }

                end = bufferEqual.size(1) - 1;
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                r.set_size(1, loop_ub);
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    r[loop_ub] = b_i + 1;
                    loop_ub++;
                  }
                }

                loop_ub = i1 - i;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  topicValue[i1] = nextLineVar[r[i + i1] - 1];
                }
              }
            }
          }
        }

        //
        // Arguments    : double fid
        //                double maxLineLength
        //                ::coder::array<unsigned char, 2U> &topicValue
        // Return Type  : void
        //
        void e_findTopic(double fid, double maxLineLength, ::coder::array<
                         unsigned char, 2U> &topicValue)
        {
          static const unsigned char uv[10] = { 73U, 109U, 112U, 77U, 101U, 116U,
            104U, 111U, 100U, 61U };

          array<int, 2U> r;
          array<unsigned char, 2U> buffer;
          array<unsigned char, 2U> nextLineVar;
          array<boolean_T, 2U> bufferEqual;
          int i;
          int loop_ub;
          boolean_T exitg1;
          boolean_T topicFound;
          buffer.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            buffer[i] = 0U;
          }

          topicValue.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            topicValue[i] = 0U;
          }

          for (i = 0; i < 10; i++) {
            buffer[i] = uv[i];
          }

          topicFound = false;
          exitg1 = false;
          while ((!exitg1) && (!topicFound)) {
            FILE * b_NULL;
            FILE * filestar;
            boolean_T exitg3;
            boolean_T y;
            getLine(fid, maxLineLength, nextLineVar);
            int exitg2;
            do {
              exitg2 = 0;
              y = false;
              loop_ub = 1;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= nextLineVar.size(1))) {
                if (nextLineVar[loop_ub - 1] == 0) {
                  loop_ub++;
                } else {
                  y = true;
                  exitg3 = true;
                }
              }

              if (y) {
                y = !(static_cast<signed char>(nextLineVar[0]) != '%');
                if ((!y) && (nextLineVar[0] != 10)) {
                  exitg2 = 1;
                } else {
                  getLine(fid, maxLineLength, nextLineVar);
                }
              } else {
                exitg2 = 1;
              }
            } while (exitg2 == 0);

            b_NULL = NULL;
            filestar = fileManager(fid);
            if (filestar == b_NULL) {
              i = 0;
            } else {
              int st;
              st = feof(filestar);
              i = ((int)st != 0);
            }

            if (i != 0) {
              exitg1 = true;
            } else {
              bufferEqual.set_size(1, nextLineVar.size(1));
              loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
              for (i = 0; i < loop_ub; i++) {
                bufferEqual[i] = (nextLineVar[i] == buffer[i]);
              }

              y = true;
              loop_ub = 0;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= 9)) {
                if (!bufferEqual[loop_ub]) {
                  y = false;
                  exitg3 = true;
                } else {
                  loop_ub++;
                }
              }

              if (y) {
                int b_i;
                int end;
                int i1;
                topicFound = true;
                bufferEqual.set_size(1, nextLineVar.size(1));
                loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                for (i = 0; i < loop_ub; i++) {
                  bufferEqual[i] = ((nextLineVar[i] != 0) != (buffer[i] != 0));
                }

                end = bufferEqual.size(1);
                loop_ub = 0;
                for (b_i = 0; b_i < end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                if (2.0 > static_cast<double>(loop_ub) - 1.0) {
                  i = 0;
                  i1 = 0;
                } else {
                  i = 1;
                  i1 = loop_ub - 1;
                }

                end = bufferEqual.size(1) - 1;
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                r.set_size(1, loop_ub);
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    r[loop_ub] = b_i + 1;
                    loop_ub++;
                  }
                }

                loop_ub = i1 - i;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  topicValue[i1] = nextLineVar[r[i + i1] - 1];
                }
              }
            }
          }
        }

        //
        // Arguments    : double fid
        //                double maxLineLength
        //                ::coder::array<unsigned char, 2U> &topicValue
        // Return Type  : void
        //
        void f_findTopic(double fid, double maxLineLength, ::coder::array<
                         unsigned char, 2U> &topicValue)
        {
          static const unsigned char uv[10] = { 65U, 103U, 103U, 77U, 101U, 116U,
            104U, 111U, 100U, 61U };

          array<int, 2U> r;
          array<unsigned char, 2U> buffer;
          array<unsigned char, 2U> nextLineVar;
          array<boolean_T, 2U> bufferEqual;
          int i;
          int loop_ub;
          boolean_T exitg1;
          boolean_T topicFound;
          buffer.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            buffer[i] = 0U;
          }

          topicValue.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            topicValue[i] = 0U;
          }

          for (i = 0; i < 10; i++) {
            buffer[i] = uv[i];
          }

          topicFound = false;
          exitg1 = false;
          while ((!exitg1) && (!topicFound)) {
            FILE * b_NULL;
            FILE * filestar;
            boolean_T exitg3;
            boolean_T y;
            getLine(fid, maxLineLength, nextLineVar);
            int exitg2;
            do {
              exitg2 = 0;
              y = false;
              loop_ub = 1;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= nextLineVar.size(1))) {
                if (nextLineVar[loop_ub - 1] == 0) {
                  loop_ub++;
                } else {
                  y = true;
                  exitg3 = true;
                }
              }

              if (y) {
                y = !(static_cast<signed char>(nextLineVar[0]) != '%');
                if ((!y) && (nextLineVar[0] != 10)) {
                  exitg2 = 1;
                } else {
                  getLine(fid, maxLineLength, nextLineVar);
                }
              } else {
                exitg2 = 1;
              }
            } while (exitg2 == 0);

            b_NULL = NULL;
            filestar = fileManager(fid);
            if (filestar == b_NULL) {
              i = 0;
            } else {
              int st;
              st = feof(filestar);
              i = ((int)st != 0);
            }

            if (i != 0) {
              exitg1 = true;
            } else {
              bufferEqual.set_size(1, nextLineVar.size(1));
              loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
              for (i = 0; i < loop_ub; i++) {
                bufferEqual[i] = (nextLineVar[i] == buffer[i]);
              }

              y = true;
              loop_ub = 0;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= 9)) {
                if (!bufferEqual[loop_ub]) {
                  y = false;
                  exitg3 = true;
                } else {
                  loop_ub++;
                }
              }

              if (y) {
                int b_i;
                int end;
                int i1;
                topicFound = true;
                bufferEqual.set_size(1, nextLineVar.size(1));
                loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                for (i = 0; i < loop_ub; i++) {
                  bufferEqual[i] = ((nextLineVar[i] != 0) != (buffer[i] != 0));
                }

                end = bufferEqual.size(1);
                loop_ub = 0;
                for (b_i = 0; b_i < end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                if (2.0 > static_cast<double>(loop_ub) - 1.0) {
                  i = 0;
                  i1 = 0;
                } else {
                  i = 1;
                  i1 = loop_ub - 1;
                }

                end = bufferEqual.size(1) - 1;
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                r.set_size(1, loop_ub);
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    r[loop_ub] = b_i + 1;
                    loop_ub++;
                  }
                }

                loop_ub = i1 - i;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  topicValue[i1] = nextLineVar[r[i + i1] - 1];
                }
              }
            }
          }
        }

        //
        // Arguments    : double fid
        //                double maxLineLength
        //                ::coder::array<unsigned char, 2U> &topicValue
        // Return Type  : void
        //
        void findTopic(double fid, double maxLineLength, ::coder::array<unsigned
                       char, 2U> &topicValue)
        {
          static const unsigned char uv[5] = { 78U, 97U, 109U, 101U, 61U };

          array<int, 2U> r;
          array<unsigned char, 2U> buffer;
          array<unsigned char, 2U> nextLineVar;
          array<boolean_T, 2U> bufferEqual;
          int i;
          int loop_ub;
          boolean_T exitg1;
          boolean_T topicFound;
          buffer.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            buffer[i] = 0U;
          }

          topicValue.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            topicValue[i] = 0U;
          }

          for (i = 0; i < 5; i++) {
            buffer[i] = uv[i];
          }

          topicFound = false;
          exitg1 = false;
          while ((!exitg1) && (!topicFound)) {
            FILE * b_NULL;
            FILE * filestar;
            boolean_T exitg3;
            boolean_T y;
            getLine(fid, maxLineLength, nextLineVar);
            int exitg2;
            do {
              exitg2 = 0;
              y = false;
              loop_ub = 1;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= nextLineVar.size(1))) {
                if (nextLineVar[loop_ub - 1] == 0) {
                  loop_ub++;
                } else {
                  y = true;
                  exitg3 = true;
                }
              }

              if (y) {
                y = !(static_cast<signed char>(nextLineVar[0]) != '%');
                if ((!y) && (nextLineVar[0] != 10)) {
                  exitg2 = 1;
                } else {
                  getLine(fid, maxLineLength, nextLineVar);
                }
              } else {
                exitg2 = 1;
              }
            } while (exitg2 == 0);

            b_NULL = NULL;
            filestar = fileManager(fid);
            if (filestar == b_NULL) {
              i = 0;
            } else {
              int st;
              st = feof(filestar);
              i = ((int)st != 0);
            }

            if (i != 0) {
              exitg1 = true;
            } else {
              bufferEqual.set_size(1, nextLineVar.size(1));
              loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
              for (i = 0; i < loop_ub; i++) {
                bufferEqual[i] = (nextLineVar[i] == buffer[i]);
              }

              y = true;
              loop_ub = 0;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= 4)) {
                if (!bufferEqual[loop_ub]) {
                  y = false;
                  exitg3 = true;
                } else {
                  loop_ub++;
                }
              }

              if (y) {
                int b_i;
                int end;
                int i1;
                topicFound = true;
                bufferEqual.set_size(1, nextLineVar.size(1));
                loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                for (i = 0; i < loop_ub; i++) {
                  bufferEqual[i] = ((nextLineVar[i] != 0) != (buffer[i] != 0));
                }

                end = bufferEqual.size(1);
                loop_ub = 0;
                for (b_i = 0; b_i < end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                if (2.0 > static_cast<double>(loop_ub) - 1.0) {
                  i = 0;
                  i1 = 0;
                } else {
                  i = 1;
                  i1 = loop_ub - 1;
                }

                end = bufferEqual.size(1) - 1;
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                r.set_size(1, loop_ub);
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    r[loop_ub] = b_i + 1;
                    loop_ub++;
                  }
                }

                loop_ub = i1 - i;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  topicValue[i1] = nextLineVar[r[i + i1] - 1];
                }
              }
            }
          }
        }

        //
        // Arguments    : double fid
        //                double maxLineLength
        //                ::coder::array<unsigned char, 2U> &topicValue
        // Return Type  : void
        //
        void g_findTopic(double fid, double maxLineLength, ::coder::array<
                         unsigned char, 2U> &topicValue)
        {
          static const unsigned char uv[13] = { 68U, 101U, 102U, 117U, 122U,
            122U, 77U, 101U, 116U, 104U, 111U, 100U, 61U };

          array<int, 2U> r;
          array<unsigned char, 2U> buffer;
          array<unsigned char, 2U> nextLineVar;
          array<boolean_T, 2U> bufferEqual;
          int i;
          int loop_ub;
          boolean_T exitg1;
          boolean_T topicFound;
          buffer.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            buffer[i] = 0U;
          }

          topicValue.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            topicValue[i] = 0U;
          }

          for (i = 0; i < 13; i++) {
            buffer[i] = uv[i];
          }

          topicFound = false;
          exitg1 = false;
          while ((!exitg1) && (!topicFound)) {
            FILE * b_NULL;
            FILE * filestar;
            boolean_T exitg3;
            boolean_T y;
            getLine(fid, maxLineLength, nextLineVar);
            int exitg2;
            do {
              exitg2 = 0;
              y = false;
              loop_ub = 1;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= nextLineVar.size(1))) {
                if (nextLineVar[loop_ub - 1] == 0) {
                  loop_ub++;
                } else {
                  y = true;
                  exitg3 = true;
                }
              }

              if (y) {
                y = !(static_cast<signed char>(nextLineVar[0]) != '%');
                if ((!y) && (nextLineVar[0] != 10)) {
                  exitg2 = 1;
                } else {
                  getLine(fid, maxLineLength, nextLineVar);
                }
              } else {
                exitg2 = 1;
              }
            } while (exitg2 == 0);

            b_NULL = NULL;
            filestar = fileManager(fid);
            if (filestar == b_NULL) {
              i = 0;
            } else {
              int st;
              st = feof(filestar);
              i = ((int)st != 0);
            }

            if (i != 0) {
              exitg1 = true;
            } else {
              bufferEqual.set_size(1, nextLineVar.size(1));
              loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
              for (i = 0; i < loop_ub; i++) {
                bufferEqual[i] = (nextLineVar[i] == buffer[i]);
              }

              y = true;
              loop_ub = 0;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= 12)) {
                if (!bufferEqual[loop_ub]) {
                  y = false;
                  exitg3 = true;
                } else {
                  loop_ub++;
                }
              }

              if (y) {
                int b_i;
                int end;
                int i1;
                topicFound = true;
                bufferEqual.set_size(1, nextLineVar.size(1));
                loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                for (i = 0; i < loop_ub; i++) {
                  bufferEqual[i] = ((nextLineVar[i] != 0) != (buffer[i] != 0));
                }

                end = bufferEqual.size(1);
                loop_ub = 0;
                for (b_i = 0; b_i < end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                if (2.0 > static_cast<double>(loop_ub) - 1.0) {
                  i = 0;
                  i1 = 0;
                } else {
                  i = 1;
                  i1 = loop_ub - 1;
                }

                end = bufferEqual.size(1) - 1;
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                r.set_size(1, loop_ub);
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    r[loop_ub] = b_i + 1;
                    loop_ub++;
                  }
                }

                loop_ub = i1 - i;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  topicValue[i1] = nextLineVar[r[i + i1] - 1];
                }
              }
            }
          }
        }

        //
        // Arguments    : double fid
        //                double maxLineLength
        //                ::coder::array<unsigned char, 2U> &topicValue
        // Return Type  : void
        //
        void h_findTopic(double fid, double maxLineLength, ::coder::array<
                         unsigned char, 2U> &topicValue)
        {
          static const unsigned char uv[7] = { 78U, 117U, 109U, 77U, 70U, 115U,
            61U };

          array<int, 2U> r;
          array<unsigned char, 2U> buffer;
          array<unsigned char, 2U> nextLineVar;
          array<boolean_T, 2U> bufferEqual;
          int end;
          int loop_ub;
          boolean_T exitg1;
          boolean_T topicFound;
          buffer.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (end = 0; end < loop_ub; end++) {
            buffer[end] = 0U;
          }

          topicValue.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (end = 0; end < loop_ub; end++) {
            topicValue[end] = 0U;
          }

          for (end = 0; end < 7; end++) {
            buffer[end] = uv[end];
          }

          topicFound = false;
          exitg1 = false;
          while ((!exitg1) && (!topicFound)) {
            FILE * b_NULL;
            FILE * filestar;
            boolean_T exitg3;
            boolean_T y;
            getLine(fid, maxLineLength, nextLineVar);
            int exitg2;
            do {
              exitg2 = 0;
              y = false;
              loop_ub = 1;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= nextLineVar.size(1))) {
                if (nextLineVar[loop_ub - 1] == 0) {
                  loop_ub++;
                } else {
                  y = true;
                  exitg3 = true;
                }
              }

              if (y) {
                y = !(static_cast<signed char>(nextLineVar[0]) != '%');
                if ((!y) && (nextLineVar[0] != 10)) {
                  exitg2 = 1;
                } else {
                  getLine(fid, maxLineLength, nextLineVar);
                }
              } else {
                exitg2 = 1;
              }
            } while (exitg2 == 0);

            b_NULL = NULL;
            filestar = fileManager(fid);
            if (filestar == b_NULL) {
              end = 0;
            } else {
              int st;
              st = feof(filestar);
              end = ((int)st != 0);
            }

            if (end != 0) {
              exitg1 = true;
            } else {
              bufferEqual.set_size(1, nextLineVar.size(1));
              loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
              for (end = 0; end < loop_ub; end++) {
                bufferEqual[end] = (nextLineVar[end] == buffer[end]);
              }

              y = true;
              loop_ub = 0;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= 6)) {
                if (!bufferEqual[loop_ub]) {
                  y = false;
                  exitg3 = true;
                } else {
                  loop_ub++;
                }
              }

              if (y) {
                int i;
                topicFound = true;
                bufferEqual.set_size(1, nextLineVar.size(1));
                loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                for (end = 0; end < loop_ub; end++) {
                  bufferEqual[end] = ((nextLineVar[end] != 0) != (buffer[end] !=
                    0));
                }

                end = bufferEqual.size(1) - 1;
                loop_ub = 0;
                for (i = 0; i <= end; i++) {
                  if (bufferEqual[i]) {
                    loop_ub++;
                  }
                }

                r.set_size(1, loop_ub);
                loop_ub = 0;
                for (i = 0; i <= end; i++) {
                  if (bufferEqual[i]) {
                    r[loop_ub] = i + 1;
                    loop_ub++;
                  }
                }

                loop_ub = r.size(1);
                for (end = 0; end < loop_ub; end++) {
                  topicValue[end] = nextLineVar[r[end] - 1];
                }
              }
            }
          }
        }

        //
        // Arguments    : double fid
        //                double maxLineLength
        //                ::coder::array<unsigned char, 2U> &topicValue
        // Return Type  : void
        //
        void i_findTopic(double fid, double maxLineLength, ::coder::array<
                         unsigned char, 2U> &topicValue)
        {
          array<int, 2U> r;
          array<unsigned char, 2U> buffer;
          array<unsigned char, 2U> nextLineVar;
          array<boolean_T, 2U> bufferEqual;
          int i;
          int loop_ub;
          boolean_T exitg1;
          boolean_T topicFound;
          buffer.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            buffer[i] = 0U;
          }

          topicValue.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            topicValue[i] = 0U;
          }

          buffer[0] = 77U;
          buffer[1] = 70U;
          topicFound = false;
          exitg1 = false;
          while ((!exitg1) && (!topicFound)) {
            FILE * b_NULL;
            FILE * filestar;
            boolean_T exitg3;
            boolean_T y;
            getLine(fid, maxLineLength, nextLineVar);
            int exitg2;
            do {
              exitg2 = 0;
              y = false;
              loop_ub = 1;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= nextLineVar.size(1))) {
                if (nextLineVar[loop_ub - 1] == 0) {
                  loop_ub++;
                } else {
                  y = true;
                  exitg3 = true;
                }
              }

              if (y) {
                y = !(static_cast<signed char>(nextLineVar[0]) != '%');
                if ((!y) && (nextLineVar[0] != 10)) {
                  exitg2 = 1;
                } else {
                  getLine(fid, maxLineLength, nextLineVar);
                }
              } else {
                exitg2 = 1;
              }
            } while (exitg2 == 0);

            b_NULL = NULL;
            filestar = fileManager(fid);
            if (filestar == b_NULL) {
              i = 0;
            } else {
              int st;
              st = feof(filestar);
              i = ((int)st != 0);
            }

            if (i != 0) {
              exitg1 = true;
            } else {
              bufferEqual.set_size(1, nextLineVar.size(1));
              loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
              for (i = 0; i < loop_ub; i++) {
                bufferEqual[i] = (nextLineVar[i] == buffer[i]);
              }

              y = true;
              loop_ub = 0;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= 1)) {
                if (!bufferEqual[loop_ub]) {
                  y = false;
                  exitg3 = true;
                } else {
                  loop_ub++;
                }
              }

              if (y) {
                int b_i;
                int end;
                int i1;
                topicFound = true;
                bufferEqual.set_size(1, nextLineVar.size(1));
                loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                for (i = 0; i < loop_ub; i++) {
                  bufferEqual[i] = ((nextLineVar[i] != 0) != (buffer[i] != 0));
                }

                end = bufferEqual.size(1);
                loop_ub = 0;
                for (b_i = 0; b_i < end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                if (2.0 > static_cast<double>(loop_ub) - 1.0) {
                  i = 0;
                  i1 = 0;
                } else {
                  i = 1;
                  i1 = loop_ub - 1;
                }

                end = bufferEqual.size(1) - 1;
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                r.set_size(1, loop_ub);
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    r[loop_ub] = b_i + 1;
                    loop_ub++;
                  }
                }

                loop_ub = i1 - i;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  topicValue[i1] = nextLineVar[r[i + i1] - 1];
                }
              }
            }
          }
        }

        //
        // Arguments    : double fid
        //                double maxLineLength
        //                ::coder::array<unsigned char, 2U> &topicValue
        // Return Type  : void
        //
        void j_findTopic(double fid, double maxLineLength, ::coder::array<
                         unsigned char, 2U> &topicValue)
        {
          static const unsigned char uv[6] = { 82U, 97U, 110U, 103U, 101U, 61U };

          array<int, 2U> r;
          array<unsigned char, 2U> buffer;
          array<unsigned char, 2U> nextLineVar;
          array<boolean_T, 2U> bufferEqual;
          int i;
          int loop_ub;
          boolean_T exitg1;
          boolean_T topicFound;
          buffer.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            buffer[i] = 0U;
          }

          topicValue.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            topicValue[i] = 0U;
          }

          for (i = 0; i < 6; i++) {
            buffer[i] = uv[i];
          }

          topicFound = false;
          exitg1 = false;
          while ((!exitg1) && (!topicFound)) {
            FILE * b_NULL;
            FILE * filestar;
            boolean_T exitg3;
            boolean_T y;
            getLine(fid, maxLineLength, nextLineVar);
            int exitg2;
            do {
              exitg2 = 0;
              y = false;
              loop_ub = 1;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= nextLineVar.size(1))) {
                if (nextLineVar[loop_ub - 1] == 0) {
                  loop_ub++;
                } else {
                  y = true;
                  exitg3 = true;
                }
              }

              if (y) {
                y = !(static_cast<signed char>(nextLineVar[0]) != '%');
                if ((!y) && (nextLineVar[0] != 10)) {
                  exitg2 = 1;
                } else {
                  getLine(fid, maxLineLength, nextLineVar);
                }
              } else {
                exitg2 = 1;
              }
            } while (exitg2 == 0);

            b_NULL = NULL;
            filestar = fileManager(fid);
            if (filestar == b_NULL) {
              i = 0;
            } else {
              int st;
              st = feof(filestar);
              i = ((int)st != 0);
            }

            if (i != 0) {
              exitg1 = true;
            } else {
              bufferEqual.set_size(1, nextLineVar.size(1));
              loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
              for (i = 0; i < loop_ub; i++) {
                bufferEqual[i] = (nextLineVar[i] == buffer[i]);
              }

              y = true;
              loop_ub = 0;
              exitg3 = false;
              while ((!exitg3) && (loop_ub <= 5)) {
                if (!bufferEqual[loop_ub]) {
                  y = false;
                  exitg3 = true;
                } else {
                  loop_ub++;
                }
              }

              if (y) {
                int b_i;
                int end;
                int i1;
                topicFound = true;
                bufferEqual.set_size(1, nextLineVar.size(1));
                loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                for (i = 0; i < loop_ub; i++) {
                  bufferEqual[i] = ((nextLineVar[i] != 0) != (buffer[i] != 0));
                }

                end = bufferEqual.size(1);
                loop_ub = 0;
                for (b_i = 0; b_i < end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                if (2.0 > static_cast<double>(loop_ub) - 1.0) {
                  i = 0;
                  i1 = 0;
                } else {
                  i = 1;
                  i1 = loop_ub - 1;
                }

                end = bufferEqual.size(1) - 1;
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    loop_ub++;
                  }
                }

                r.set_size(1, loop_ub);
                loop_ub = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (bufferEqual[b_i]) {
                    r[loop_ub] = b_i + 1;
                    loop_ub++;
                  }
                }

                loop_ub = i1 - i;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  topicValue[i1] = nextLineVar[r[i + i1] - 1];
                }
              }
            }
          }
        }
      }
    }
  }
}

//
// File trailer for findTopic.cpp
//
// [EOF]
//
