//
// File: readFISAsHomogenousStructure.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "readFISAsHomogenousStructure.h"
#include "all.h"
#include "deblank.h"
#include "fileManager.h"
#include "find.h"
#include "findTopic.h"
#include "getNextLine.h"
#include "opkene_internal_types.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include "coder_array.h"
#include <stdio.h>

// Function Definitions
//
// Arguments    : double fid
//                double maxLineLength
//                double info_maxInputNameLength
//                double info_maxNumMF
//                double info_maxMFNameLength
//                double info_maxMFTypeLength
//                double info_maxMFParamLength
//                double info_numVars
//                boolean_T updateOutputRange
//                ::coder::array<b_struct_T, 2U> &var
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
        void b_getVar(double fid, double maxLineLength, double
                      info_maxInputNameLength, double info_maxNumMF, double
                      info_maxMFNameLength, double info_maxMFTypeLength, double
                      info_maxMFParamLength, double info_numVars, boolean_T
                      updateOutputRange, ::coder::array<b_struct_T, 2U> &var)
        {
          static const unsigned char uv[7] = { 91U, 79U, 117U, 116U, 112U, 117U,
            116U };

          array<int, 2U> ids;
          array<char, 2U> b_nextLineVar;
          array<unsigned char, 2U> b_template;
          array<unsigned char, 2U> mfInfo2;
          array<unsigned char, 2U> mfInfo3;
          array<unsigned char, 2U> nextLineVar;
          array<char, 2U> r;
          array<boolean_T, 2U> bufferEqual;
          b_struct_T varTemplate;
          struct_T mfTemplate;
          int idR_size[2];
          int idR_data[1];
          int b_loop_ub;
          int c_loop_ub;
          int d_loop_ub;
          int e_loop_ub;
          int f_loop_ub;
          int g_loop_ub;
          int h_loop_ub;
          int i;
          int loop_ub;
          mfTemplate.name.set_size(1, (static_cast<int>(info_maxMFNameLength)));
          loop_ub = static_cast<int>(info_maxMFNameLength);
          for (i = 0; i < loop_ub; i++) {
            mfTemplate.name[i] = '\x00';
          }

          mfTemplate.origNameLength = 0.0;
          mfTemplate.type.set_size(1, (static_cast<int>(info_maxMFTypeLength)));
          loop_ub = static_cast<int>(info_maxMFTypeLength);
          for (i = 0; i < loop_ub; i++) {
            mfTemplate.type[i] = '\x00';
          }

          mfTemplate.origTypeLength = 0.0;
          mfTemplate.params.set_size(1, (static_cast<int>(info_maxMFParamLength)));
          loop_ub = static_cast<int>(info_maxMFParamLength);
          for (i = 0; i < loop_ub; i++) {
            mfTemplate.params[i] = 0.0;
          }

          mfTemplate.origParamLength = 0.0;
          varTemplate.name.set_size(1, (static_cast<int>(info_maxInputNameLength)));
          loop_ub = static_cast<int>(info_maxInputNameLength);
          for (i = 0; i < loop_ub; i++) {
            varTemplate.name[i] = '\x00';
          }

          varTemplate.origNameLength = 0.0;
          varTemplate.range[0] = 0.0;
          varTemplate.range[1] = 0.0;
          varTemplate.mf.set_size(1, (static_cast<int>(info_maxNumMF)));
          loop_ub = static_cast<int>(info_maxNumMF);
          for (i = 0; i < loop_ub; i++) {
            varTemplate.mf[i] = mfTemplate;
          }

          varTemplate.origNumMF = 0.0;
          var.set_size(1, (static_cast<int>(info_numVars)));
          loop_ub = static_cast<int>(info_numVars);
          for (i = 0; i < loop_ub; i++) {
            var[i] = varTemplate;
          }

          i = static_cast<int>(info_numVars);
          for (int b_i = 0; b_i < i; b_i++) {
            int i1;
            boolean_T exitg1;
            boolean_T topicFound;
            b_template.set_size(1, (static_cast<int>(maxLineLength)));
            loop_ub = static_cast<int>(maxLineLength);
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_template[i1] = 0U;
            }

            for (i1 = 0; i1 < 7; i1++) {
              b_template[i1] = uv[i1];
            }

            topicFound = false;
            exitg1 = false;
            while ((!exitg1) && (!topicFound)) {
              FILE * b_NULL;
              FILE * filestar;
              getNextLine(fid, maxLineLength, nextLineVar);
              b_NULL = NULL;
              filestar = fileManager(fid);
              if (filestar == b_NULL) {
                i1 = 0;
              } else {
                int st;
                st = feof(filestar);
                i1 = ((int)st != 0);
              }

              if (i1 != 0) {
                exitg1 = true;
              } else {
                bufferEqual.set_size(1, nextLineVar.size(1));
                loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                for (i1 = 0; i1 < loop_ub; i1++) {
                  bufferEqual[i1] = (nextLineVar[i1] == b_template[i1]);
                }

                if (b_all(*(boolean_T (*)[7])&bufferEqual[0])) {
                  creal_T dc;
                  int i2;
                  unsigned int unnamed_idx_1;
                  topicFound = true;
                  findTopic(fid, maxLineLength, nextLineVar);
                  if (1.0 > info_maxInputNameLength) {
                    loop_ub = 0;
                  } else {
                    loop_ub = static_cast<int>(info_maxInputNameLength);
                  }

                  for (i1 = 0; i1 < loop_ub; i1++) {
                    var[b_i].name[i1] = static_cast<signed char>(nextLineVar[i1]);
                  }

                  deblank(var[b_i].name, r);
                  var[b_i].origNameLength = r.size(1);
                  j_findTopic(fid, maxLineLength, nextLineVar);
                  bufferEqual.set_size(1, nextLineVar.size(1));
                  loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    bufferEqual[i1] = (nextLineVar[i1] == 32);
                  }

                  eml_find(bufferEqual, idR_data, idR_size);
                  if (1.0 > static_cast<double>(idR_data[0]) - 1.0) {
                    loop_ub = 0;
                  } else {
                    loop_ub = idR_data[0] - 1;
                  }

                  b_nextLineVar.set_size(1, loop_ub);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    b_nextLineVar[i1] = static_cast<signed char>(nextLineVar[i1]);
                  }

                  deblank(b_nextLineVar, r);
                  dc = str2double(r);
                  var[b_i].range[0] = dc.re;
                  if (static_cast<double>(idR_data[0]) + 1.0 > nextLineVar.size
                      (1)) {
                    i1 = -1;
                    i2 = -1;
                  } else {
                    i1 = idR_data[0] - 1;
                    i2 = nextLineVar.size(1) - 1;
                  }

                  unnamed_idx_1 = static_cast<unsigned int>(i2 - i1);
                  b_nextLineVar.set_size(1, (static_cast<int>(unnamed_idx_1)));
                  loop_ub = static_cast<int>(unnamed_idx_1);
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    b_nextLineVar[i2] = static_cast<signed char>(nextLineVar[(i1
                      + i2) + 1]);
                  }

                  deblank(b_nextLineVar, r);
                  dc = str2double(r);
                  var[b_i].range[1] = dc.re;
                  if (updateOutputRange && (var[b_i].range[1] <= var[b_i].range
                       [0])) {
                    var[b_i].range[1] = var[b_i].range[0] + 1.0;
                  }

                  h_findTopic(fid, maxLineLength, nextLineVar);
                  b_nextLineVar.set_size(1, nextLineVar.size(1));
                  loop_ub = nextLineVar.size(1);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    b_nextLineVar[i1] = static_cast<signed char>(nextLineVar[i1]);
                  }

                  deblank(b_nextLineVar, r);
                  dc = str2double(r);
                  var[b_i].origNumMF = dc.re;
                  i1 = static_cast<int>(dc.re);
                  if (0 <= static_cast<int>(dc.re) - 1) {
                    b_loop_ub = static_cast<int>(maxLineLength);
                    c_loop_ub = static_cast<int>(maxLineLength);
                    if (1.0 > info_maxMFNameLength) {
                      d_loop_ub = 0;
                    } else {
                      d_loop_ub = static_cast<int>(info_maxMFNameLength);
                    }

                    e_loop_ub = static_cast<int>(maxLineLength);
                    f_loop_ub = static_cast<int>(maxLineLength);
                    if (1.0 > info_maxMFTypeLength) {
                      g_loop_ub = 0;
                    } else {
                      g_loop_ub = static_cast<int>(info_maxMFTypeLength);
                    }

                    h_loop_ub = static_cast<int>(maxLineLength);
                  }

                  for (int j = 0; j < i1; j++) {
                    int i3;
                    i_findTopic(fid, maxLineLength, nextLineVar);
                    mfInfo2.set_size(1, (static_cast<int>(maxLineLength)));
                    for (i2 = 0; i2 < b_loop_ub; i2++) {
                      mfInfo2[i2] = 0U;
                    }

                    loop_ub = nextLineVar.size(1) - 3;
                    for (i2 = 0; i2 <= loop_ub; i2++) {
                      mfInfo2[i2] = nextLineVar[i2 + 2];
                    }

                    bufferEqual.set_size(1, mfInfo2.size(1));
                    loop_ub = mfInfo2.size(0) * mfInfo2.size(1);
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      bufferEqual[i2] = (mfInfo2[i2] == 39);
                    }

                    eml_find(bufferEqual, idR_data, idR_size);
                    nextLineVar.set_size(1, (static_cast<int>(maxLineLength)));
                    for (i2 = 0; i2 < c_loop_ub; i2++) {
                      nextLineVar[i2] = 0U;
                    }

                    if (1.0 > static_cast<double>(idR_data[0]) - 1.0) {
                      loop_ub = 0;
                    } else {
                      loop_ub = idR_data[0] - 1;
                    }

                    for (i2 = 0; i2 < loop_ub; i2++) {
                      nextLineVar[i2] = mfInfo2[i2];
                    }

                    for (i2 = 0; i2 < d_loop_ub; i2++) {
                      var[b_i].mf[j].name[i2] = static_cast<signed char>
                        (nextLineVar[i2]);
                    }

                    deblank(var[b_i].mf[j].name, r);
                    var[b_i].mf[j].origNameLength = r.size(1);
                    mfInfo3.set_size(1, (static_cast<int>(maxLineLength)));
                    for (i2 = 0; i2 < e_loop_ub; i2++) {
                      mfInfo3[i2] = 0U;
                    }

                    if (static_cast<double>(idR_data[0]) + 3.0 > mfInfo2.size(1))
                    {
                      i2 = 0;
                      i3 = 0;
                    } else {
                      i2 = idR_data[0] + 2;
                      i3 = mfInfo2.size(1);
                    }

                    loop_ub = i3 - i2;
                    for (i3 = 0; i3 < loop_ub; i3++) {
                      mfInfo3[i3] = mfInfo2[i2 + i3];
                    }

                    bufferEqual.set_size(1, mfInfo3.size(1));
                    loop_ub = mfInfo3.size(0) * mfInfo3.size(1);
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      bufferEqual[i2] = (mfInfo3[i2] == 39);
                    }

                    eml_find(bufferEqual, idR_data, idR_size);
                    nextLineVar.set_size(1, (static_cast<int>(maxLineLength)));
                    for (i2 = 0; i2 < f_loop_ub; i2++) {
                      nextLineVar[i2] = 0U;
                    }

                    if (1.0 > static_cast<double>(idR_data[0]) - 1.0) {
                      loop_ub = 0;
                    } else {
                      loop_ub = idR_data[0] - 1;
                    }

                    for (i2 = 0; i2 < loop_ub; i2++) {
                      nextLineVar[i2] = mfInfo3[i2];
                    }

                    for (i2 = 0; i2 < g_loop_ub; i2++) {
                      var[b_i].mf[j].type[i2] = static_cast<signed char>
                        (nextLineVar[i2]);
                    }

                    deblank(var[b_i].mf[j].type, r);
                    var[b_i].mf[j].origTypeLength = r.size(1);
                    nextLineVar.set_size(1, (static_cast<int>(maxLineLength)));
                    for (i2 = 0; i2 < h_loop_ub; i2++) {
                      nextLineVar[i2] = 0U;
                    }

                    if (static_cast<double>(idR_data[0]) + 3.0 > mfInfo3.size(1))
                    {
                      i2 = 0;
                      i3 = 0;
                    } else {
                      i2 = idR_data[0] + 2;
                      i3 = mfInfo3.size(1);
                    }

                    loop_ub = i3 - i2;
                    for (i3 = 0; i3 < loop_ub; i3++) {
                      nextLineVar[i3] = mfInfo3[i2 + i3];
                    }

                    bufferEqual.set_size(1, nextLineVar.size(1));
                    loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      bufferEqual[i2] = (nextLineVar[i2] == 32);
                    }

                    b_eml_find(bufferEqual, ids);
                    i2 = ids.size(1);
                    for (int k = 0; k < i2; k++) {
                      if (k + 1 == ids.size(1)) {
                        double startIndex;
                        int i4;
                        if (k + 1 == 1) {
                          startIndex = 1.0;
                        } else {
                          startIndex = static_cast<double>(ids[k - 1]) + 1.0;
                        }

                        if (startIndex > static_cast<double>(ids[k]) - 1.0) {
                          i3 = -1;
                          i4 = -1;
                        } else {
                          i3 = static_cast<int>(startIndex) - 2;
                          i4 = ids[k] - 2;
                        }

                        loop_ub = i4 - i3;
                        b_nextLineVar.set_size(1, loop_ub);
                        for (i4 = 0; i4 < loop_ub; i4++) {
                          b_nextLineVar[i4] = static_cast<signed char>
                            (nextLineVar[(i3 + i4) + 1]);
                        }

                        dc = str2double(b_nextLineVar);
                        var[b_i].mf[j].params[k] = dc.re;
                        if (static_cast<double>(ids[k]) + 1.0 > nextLineVar.size
                            (1)) {
                          i3 = -1;
                          i4 = -1;
                        } else {
                          i3 = ids[k] - 1;
                          i4 = nextLineVar.size(1) - 1;
                        }

                        unnamed_idx_1 = static_cast<unsigned int>(i4 - i3);
                        b_nextLineVar.set_size(1, (static_cast<int>
                          (unnamed_idx_1)));
                        loop_ub = static_cast<int>(unnamed_idx_1);
                        for (i4 = 0; i4 < loop_ub; i4++) {
                          b_nextLineVar[i4] = static_cast<signed char>
                            (nextLineVar[(i3 + i4) + 1]);
                        }

                        deblank(b_nextLineVar, r);
                        dc = str2double(r);
                        var[b_i].mf[j].params[k + 1] = dc.re;
                      } else {
                        double d;
                        double startIndex;
                        int i4;
                        if (k + 1 == 1) {
                          startIndex = 1.0;
                        } else {
                          startIndex = static_cast<double>(ids[k - 1]) + 1.0;
                        }

                        d = static_cast<double>(ids[k]) - 1.0;
                        if (startIndex > d) {
                          i3 = -1;
                          i4 = -1;
                        } else {
                          i3 = static_cast<int>(startIndex) - 2;
                          i4 = static_cast<int>(d) - 1;
                        }

                        loop_ub = i4 - i3;
                        b_nextLineVar.set_size(1, loop_ub);
                        for (i4 = 0; i4 < loop_ub; i4++) {
                          b_nextLineVar[i4] = static_cast<signed char>
                            (nextLineVar[(i3 + i4) + 1]);
                        }

                        dc = str2double(b_nextLineVar);
                        var[b_i].mf[j].params[k] = dc.re;
                      }
                    }

                    var[b_i].mf[j].origParamLength = static_cast<double>
                      (ids.size(1)) + 1.0;
                  }
                }
              }
            }
          }
        }

        //
        // Arguments    : double fid
        //                double maxLineLength
        //                boolean_T checkForSugenoMFs
        //                double *info_maxInputNameLength
        //                double *info_maxNumMF
        //                double *info_maxMFNameLength
        //                double *info_maxMFTypeLength
        //                double *info_maxMFParamLength
        //                double *info_numVars
        //                boolean_T *info_hasSugenoMFs
        // Return Type  : void
        //
        void b_getVarInfo(double fid, double maxLineLength, boolean_T
                          checkForSugenoMFs, double *info_maxInputNameLength,
                          double *info_maxNumMF, double *info_maxMFNameLength,
                          double *info_maxMFTypeLength, double
                          *info_maxMFParamLength, double *info_numVars,
                          boolean_T *info_hasSugenoMFs)
        {
          static const char cv[8] = { 'c', 'o', 'n', 's', 't', 'a', 'n', 't' };

          static const unsigned char uv[7] = { 91U, 79U, 117U, 116U, 112U, 117U,
            116U };

          static const char cv1[6] = { 'l', 'i', 'n', 'e', 'a', 'r' };

          FILE * b_NULL;
          array<int, 2U> r;
          array<char, 2U> a;
          array<char, 2U> b_nextLineVar;
          array<unsigned char, 2U> b_template;
          array<unsigned char, 2U> mfInfo2;
          array<unsigned char, 2U> mfInfo3;
          array<unsigned char, 2U> nextLineVar;
          array<boolean_T, 2U> bufferEqual;
          int id_size[2];
          int id_data[1];
          int b_loop_ub;
          int c_loop_ub;
          int d_loop_ub;
          int e_loop_ub;
          int f_loop_ub;
          int i;
          int loop_ub;
          int maxInputNameLength;
          int maxMFNameLength;
          unsigned int maxMFParamLength;
          int maxMFTypeLength;
          *info_numVars = 0.0;
          maxInputNameLength = 0;
          *info_maxNumMF = 0.0;
          maxMFNameLength = 0;
          maxMFTypeLength = 0;
          maxMFParamLength = 0U;
          *info_hasSugenoMFs = false;
          b_template.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            b_template[i] = 0U;
          }

          for (i = 0; i < 7; i++) {
            b_template[i] = uv[i];
          }

          b_NULL = NULL;
          FILE * filestar;
          int exitg1;
          do {
            exitg1 = 0;
            filestar = fileManager(fid);
            if (filestar == b_NULL) {
              i = 0;
            } else {
              int st;
              st = feof(filestar);
              i = ((int)st != 0);
            }

            if (i == 0) {
              boolean_T exitg2;
              boolean_T y;
              getNextLine(fid, maxLineLength, nextLineVar);
              bufferEqual.set_size(1, nextLineVar.size(1));
              loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
              for (i = 0; i < loop_ub; i++) {
                bufferEqual[i] = (nextLineVar[i] == b_template[i]);
              }

              y = true;
              loop_ub = 0;
              exitg2 = false;
              while ((!exitg2) && (loop_ub <= 6)) {
                if (!bufferEqual[loop_ub]) {
                  y = false;
                  exitg2 = true;
                } else {
                  loop_ub++;
                }
              }

              if (y) {
                creal_T dc;
                (*info_numVars)++;
                findTopic(fid, maxLineLength, nextLineVar);
                b_nextLineVar.set_size(1, nextLineVar.size(1));
                loop_ub = nextLineVar.size(1);
                for (i = 0; i < loop_ub; i++) {
                  b_nextLineVar[i] = static_cast<signed char>(nextLineVar[i]);
                }

                deblank(b_nextLineVar, a);
                if (a.size(1) > maxInputNameLength) {
                  maxInputNameLength = a.size(1);
                }

                h_findTopic(fid, maxLineLength, nextLineVar);
                b_nextLineVar.set_size(1, nextLineVar.size(1));
                loop_ub = nextLineVar.size(1);
                for (i = 0; i < loop_ub; i++) {
                  b_nextLineVar[i] = static_cast<signed char>(nextLineVar[i]);
                }

                deblank(b_nextLineVar, a);
                dc = str2double(a);
                if (dc.re > *info_maxNumMF) {
                  *info_maxNumMF = dc.re;
                }

                i = static_cast<int>(dc.re);
                if (0 <= static_cast<int>(dc.re) - 1) {
                  b_loop_ub = static_cast<int>(maxLineLength);
                  c_loop_ub = static_cast<int>(maxLineLength);
                  d_loop_ub = static_cast<int>(maxLineLength);
                  e_loop_ub = static_cast<int>(maxLineLength);
                  f_loop_ub = static_cast<int>(maxLineLength);
                }

                for (int j = 0; j < i; j++) {
                  int i1;
                  int i2;
                  i_findTopic(fid, maxLineLength, nextLineVar);
                  mfInfo2.set_size(1, (static_cast<int>(maxLineLength)));
                  for (i1 = 0; i1 < b_loop_ub; i1++) {
                    mfInfo2[i1] = 0U;
                  }

                  loop_ub = nextLineVar.size(1) - 3;
                  for (i1 = 0; i1 <= loop_ub; i1++) {
                    mfInfo2[i1] = nextLineVar[i1 + 2];
                  }

                  bufferEqual.set_size(1, mfInfo2.size(1));
                  loop_ub = mfInfo2.size(0) * mfInfo2.size(1);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    bufferEqual[i1] = (mfInfo2[i1] == 39);
                  }

                  eml_find(bufferEqual, id_data, id_size);
                  nextLineVar.set_size(1, (static_cast<int>(maxLineLength)));
                  for (i1 = 0; i1 < c_loop_ub; i1++) {
                    nextLineVar[i1] = 0U;
                  }

                  if (1.0 > static_cast<double>(id_data[0]) - 1.0) {
                    loop_ub = 0;
                  } else {
                    loop_ub = id_data[0] - 1;
                  }

                  for (i1 = 0; i1 < loop_ub; i1++) {
                    nextLineVar[i1] = mfInfo2[i1];
                  }

                  loop_ub = nextLineVar.size(1);
                  b_nextLineVar.set_size(1, nextLineVar.size(1));
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    b_nextLineVar[i1] = static_cast<signed char>(nextLineVar[i1]);
                  }

                  deblank(b_nextLineVar, a);
                  if (a.size(1) > maxMFNameLength) {
                    maxMFNameLength = a.size(1);
                  }

                  mfInfo3.set_size(1, (static_cast<int>(maxLineLength)));
                  for (i1 = 0; i1 < d_loop_ub; i1++) {
                    mfInfo3[i1] = 0U;
                  }

                  if (static_cast<double>(id_data[0]) + 3.0 > mfInfo2.size(1)) {
                    i1 = 0;
                    i2 = 0;
                  } else {
                    i1 = id_data[0] + 2;
                    i2 = mfInfo2.size(1);
                  }

                  loop_ub = i2 - i1;
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    mfInfo3[i2] = mfInfo2[i1 + i2];
                  }

                  bufferEqual.set_size(1, mfInfo3.size(1));
                  loop_ub = mfInfo3.size(0) * mfInfo3.size(1);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    bufferEqual[i1] = (mfInfo3[i1] == 39);
                  }

                  eml_find(bufferEqual, id_data, id_size);
                  nextLineVar.set_size(1, (static_cast<int>(maxLineLength)));
                  for (i1 = 0; i1 < e_loop_ub; i1++) {
                    nextLineVar[i1] = 0U;
                  }

                  if (1.0 > static_cast<double>(id_data[0]) - 1.0) {
                    loop_ub = 0;
                  } else {
                    loop_ub = id_data[0] - 1;
                  }

                  for (i1 = 0; i1 < loop_ub; i1++) {
                    nextLineVar[i1] = mfInfo3[i1];
                  }

                  loop_ub = nextLineVar.size(1);
                  b_nextLineVar.set_size(1, nextLineVar.size(1));
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    b_nextLineVar[i1] = static_cast<signed char>(nextLineVar[i1]);
                  }

                  deblank(b_nextLineVar, a);
                  if (a.size(1) > maxMFTypeLength) {
                    maxMFTypeLength = a.size(1);
                  }

                  if (checkForSugenoMFs && (!*info_hasSugenoMFs)) {
                    int exitg3;
                    loop_ub = nextLineVar.size(1);
                    b_nextLineVar.set_size(1, nextLineVar.size(1));
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      b_nextLineVar[i1] = static_cast<signed char>
                        (nextLineVar[i1]);
                    }

                    deblank(b_nextLineVar, a);
                    y = false;
                    if (a.size(1) == 8) {
                      loop_ub = 0;
                      do {
                        exitg3 = 0;
                        if (loop_ub < 8) {
                          if (a[loop_ub] != cv[loop_ub]) {
                            exitg3 = 1;
                          } else {
                            loop_ub++;
                          }
                        } else {
                          y = true;
                          exitg3 = 1;
                        }
                      } while (exitg3 == 0);
                    }

                    if (y) {
                      *info_hasSugenoMFs = true;
                    } else {
                      loop_ub = nextLineVar.size(1);
                      b_nextLineVar.set_size(1, nextLineVar.size(1));
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_nextLineVar[i1] = static_cast<signed char>
                          (nextLineVar[i1]);
                      }

                      deblank(b_nextLineVar, a);
                      y = false;
                      if (a.size(1) == 6) {
                        loop_ub = 0;
                        do {
                          exitg3 = 0;
                          if (loop_ub < 6) {
                            if (a[loop_ub] != cv1[loop_ub]) {
                              exitg3 = 1;
                            } else {
                              loop_ub++;
                            }
                          } else {
                            y = true;
                            exitg3 = 1;
                          }
                        } while (exitg3 == 0);
                      }

                      if (y) {
                        *info_hasSugenoMFs = true;
                      }
                    }
                  }

                  nextLineVar.set_size(1, (static_cast<int>(maxLineLength)));
                  for (i1 = 0; i1 < f_loop_ub; i1++) {
                    nextLineVar[i1] = 0U;
                  }

                  if (static_cast<double>(id_data[0]) + 3.0 > mfInfo3.size(1)) {
                    i1 = 0;
                    i2 = 0;
                  } else {
                    i1 = id_data[0] + 2;
                    i2 = mfInfo3.size(1);
                  }

                  loop_ub = i2 - i1;
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    nextLineVar[i2] = mfInfo3[i1 + i2];
                  }

                  bufferEqual.set_size(1, nextLineVar.size(1));
                  loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    bufferEqual[i1] = (nextLineVar[i1] == 44);
                  }

                  eml_find(bufferEqual, id_data, id_size);
                  if (id_size[1] != 0) {
                    cfclose(fid);
                    exit(0);
                  }

                  bufferEqual.set_size(1, nextLineVar.size(1));
                  loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    bufferEqual[i1] = (nextLineVar[i1] == 32);
                  }

                  b_eml_find(bufferEqual, r);
                  if (r.size(1) + 1U > maxMFParamLength) {
                    maxMFParamLength = r.size(1) + 1U;
                  }
                }
              }
            } else {
              exitg1 = 1;
            }
          } while (exitg1 == 0);

          *info_maxInputNameLength = maxInputNameLength;
          *info_maxMFNameLength = maxMFNameLength;
          *info_maxMFTypeLength = maxMFTypeLength;
          *info_maxMFParamLength = maxMFParamLength;
        }

        //
        // Arguments    : double fid
        //                double maxLineLength
        //                double info_maxInputNameLength
        //                double info_maxNumMF
        //                double info_maxMFNameLength
        //                double info_maxMFTypeLength
        //                double info_maxMFParamLength
        //                double info_numVars
        //                ::coder::array<b_struct_T, 2U> &var
        // Return Type  : void
        //
        void getVar(double fid, double maxLineLength, double
                    info_maxInputNameLength, double info_maxNumMF, double
                    info_maxMFNameLength, double info_maxMFTypeLength, double
                    info_maxMFParamLength, double info_numVars, ::coder::array<
                    b_struct_T, 2U> &var)
        {
          static const unsigned char uv[6] = { 91U, 73U, 110U, 112U, 117U, 116U
          };

          array<int, 2U> ids;
          array<char, 2U> b_nextLineVar;
          array<unsigned char, 2U> b_template;
          array<unsigned char, 2U> mfInfo2;
          array<unsigned char, 2U> mfInfo3;
          array<unsigned char, 2U> nextLineVar;
          array<char, 2U> r;
          array<boolean_T, 2U> bufferEqual;
          b_struct_T varTemplate;
          struct_T mfTemplate;
          int idR_size[2];
          int idR_data[1];
          int b_loop_ub;
          int c_loop_ub;
          int d_loop_ub;
          int e_loop_ub;
          int f_loop_ub;
          int g_loop_ub;
          int h_loop_ub;
          int i;
          int loop_ub;
          mfTemplate.name.set_size(1, (static_cast<int>(info_maxMFNameLength)));
          loop_ub = static_cast<int>(info_maxMFNameLength);
          for (i = 0; i < loop_ub; i++) {
            mfTemplate.name[i] = '\x00';
          }

          mfTemplate.origNameLength = 0.0;
          mfTemplate.type.set_size(1, (static_cast<int>(info_maxMFTypeLength)));
          loop_ub = static_cast<int>(info_maxMFTypeLength);
          for (i = 0; i < loop_ub; i++) {
            mfTemplate.type[i] = '\x00';
          }

          mfTemplate.origTypeLength = 0.0;
          mfTemplate.params.set_size(1, (static_cast<int>(info_maxMFParamLength)));
          loop_ub = static_cast<int>(info_maxMFParamLength);
          for (i = 0; i < loop_ub; i++) {
            mfTemplate.params[i] = 0.0;
          }

          mfTemplate.origParamLength = 0.0;
          varTemplate.name.set_size(1, (static_cast<int>(info_maxInputNameLength)));
          loop_ub = static_cast<int>(info_maxInputNameLength);
          for (i = 0; i < loop_ub; i++) {
            varTemplate.name[i] = '\x00';
          }

          varTemplate.origNameLength = 0.0;
          varTemplate.range[0] = 0.0;
          varTemplate.range[1] = 0.0;
          varTemplate.mf.set_size(1, (static_cast<int>(info_maxNumMF)));
          loop_ub = static_cast<int>(info_maxNumMF);
          for (i = 0; i < loop_ub; i++) {
            varTemplate.mf[i] = mfTemplate;
          }

          varTemplate.origNumMF = 0.0;
          var.set_size(1, (static_cast<int>(info_numVars)));
          loop_ub = static_cast<int>(info_numVars);
          for (i = 0; i < loop_ub; i++) {
            var[i] = varTemplate;
          }

          i = static_cast<int>(info_numVars);
          for (int b_i = 0; b_i < i; b_i++) {
            int i1;
            boolean_T exitg1;
            boolean_T topicFound;
            b_template.set_size(1, (static_cast<int>(maxLineLength)));
            loop_ub = static_cast<int>(maxLineLength);
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_template[i1] = 0U;
            }

            for (i1 = 0; i1 < 6; i1++) {
              b_template[i1] = uv[i1];
            }

            topicFound = false;
            exitg1 = false;
            while ((!exitg1) && (!topicFound)) {
              FILE * b_NULL;
              FILE * filestar;
              getNextLine(fid, maxLineLength, nextLineVar);
              b_NULL = NULL;
              filestar = fileManager(fid);
              if (filestar == b_NULL) {
                i1 = 0;
              } else {
                int st;
                st = feof(filestar);
                i1 = ((int)st != 0);
              }

              if (i1 != 0) {
                exitg1 = true;
              } else {
                bufferEqual.set_size(1, nextLineVar.size(1));
                loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                for (i1 = 0; i1 < loop_ub; i1++) {
                  bufferEqual[i1] = (nextLineVar[i1] == b_template[i1]);
                }

                if (all(*(boolean_T (*)[6])&bufferEqual[0])) {
                  creal_T dc;
                  int i2;
                  unsigned int unnamed_idx_1;
                  topicFound = true;
                  findTopic(fid, maxLineLength, nextLineVar);
                  if (1.0 > info_maxInputNameLength) {
                    loop_ub = 0;
                  } else {
                    loop_ub = static_cast<int>(info_maxInputNameLength);
                  }

                  for (i1 = 0; i1 < loop_ub; i1++) {
                    var[b_i].name[i1] = static_cast<signed char>(nextLineVar[i1]);
                  }

                  deblank(var[b_i].name, r);
                  var[b_i].origNameLength = r.size(1);
                  j_findTopic(fid, maxLineLength, nextLineVar);
                  bufferEqual.set_size(1, nextLineVar.size(1));
                  loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    bufferEqual[i1] = (nextLineVar[i1] == 32);
                  }

                  eml_find(bufferEqual, idR_data, idR_size);
                  if (1.0 > static_cast<double>(idR_data[0]) - 1.0) {
                    loop_ub = 0;
                  } else {
                    loop_ub = idR_data[0] - 1;
                  }

                  b_nextLineVar.set_size(1, loop_ub);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    b_nextLineVar[i1] = static_cast<signed char>(nextLineVar[i1]);
                  }

                  deblank(b_nextLineVar, r);
                  dc = str2double(r);
                  var[b_i].range[0] = dc.re;
                  if (static_cast<double>(idR_data[0]) + 1.0 > nextLineVar.size
                      (1)) {
                    i1 = -1;
                    i2 = -1;
                  } else {
                    i1 = idR_data[0] - 1;
                    i2 = nextLineVar.size(1) - 1;
                  }

                  unnamed_idx_1 = static_cast<unsigned int>(i2 - i1);
                  b_nextLineVar.set_size(1, (static_cast<int>(unnamed_idx_1)));
                  loop_ub = static_cast<int>(unnamed_idx_1);
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    b_nextLineVar[i2] = static_cast<signed char>(nextLineVar[(i1
                      + i2) + 1]);
                  }

                  deblank(b_nextLineVar, r);
                  dc = str2double(r);
                  var[b_i].range[1] = dc.re;
                  h_findTopic(fid, maxLineLength, nextLineVar);
                  b_nextLineVar.set_size(1, nextLineVar.size(1));
                  loop_ub = nextLineVar.size(1);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    b_nextLineVar[i1] = static_cast<signed char>(nextLineVar[i1]);
                  }

                  deblank(b_nextLineVar, r);
                  dc = str2double(r);
                  var[b_i].origNumMF = dc.re;
                  i1 = static_cast<int>(dc.re);
                  if (0 <= static_cast<int>(dc.re) - 1) {
                    b_loop_ub = static_cast<int>(maxLineLength);
                    c_loop_ub = static_cast<int>(maxLineLength);
                    if (1.0 > info_maxMFNameLength) {
                      d_loop_ub = 0;
                    } else {
                      d_loop_ub = static_cast<int>(info_maxMFNameLength);
                    }

                    e_loop_ub = static_cast<int>(maxLineLength);
                    f_loop_ub = static_cast<int>(maxLineLength);
                    if (1.0 > info_maxMFTypeLength) {
                      g_loop_ub = 0;
                    } else {
                      g_loop_ub = static_cast<int>(info_maxMFTypeLength);
                    }

                    h_loop_ub = static_cast<int>(maxLineLength);
                  }

                  for (int j = 0; j < i1; j++) {
                    int i3;
                    i_findTopic(fid, maxLineLength, nextLineVar);
                    mfInfo2.set_size(1, (static_cast<int>(maxLineLength)));
                    for (i2 = 0; i2 < b_loop_ub; i2++) {
                      mfInfo2[i2] = 0U;
                    }

                    loop_ub = nextLineVar.size(1) - 3;
                    for (i2 = 0; i2 <= loop_ub; i2++) {
                      mfInfo2[i2] = nextLineVar[i2 + 2];
                    }

                    bufferEqual.set_size(1, mfInfo2.size(1));
                    loop_ub = mfInfo2.size(0) * mfInfo2.size(1);
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      bufferEqual[i2] = (mfInfo2[i2] == 39);
                    }

                    eml_find(bufferEqual, idR_data, idR_size);
                    nextLineVar.set_size(1, (static_cast<int>(maxLineLength)));
                    for (i2 = 0; i2 < c_loop_ub; i2++) {
                      nextLineVar[i2] = 0U;
                    }

                    if (1.0 > static_cast<double>(idR_data[0]) - 1.0) {
                      loop_ub = 0;
                    } else {
                      loop_ub = idR_data[0] - 1;
                    }

                    for (i2 = 0; i2 < loop_ub; i2++) {
                      nextLineVar[i2] = mfInfo2[i2];
                    }

                    for (i2 = 0; i2 < d_loop_ub; i2++) {
                      var[b_i].mf[j].name[i2] = static_cast<signed char>
                        (nextLineVar[i2]);
                    }

                    deblank(var[b_i].mf[j].name, r);
                    var[b_i].mf[j].origNameLength = r.size(1);
                    mfInfo3.set_size(1, (static_cast<int>(maxLineLength)));
                    for (i2 = 0; i2 < e_loop_ub; i2++) {
                      mfInfo3[i2] = 0U;
                    }

                    if (static_cast<double>(idR_data[0]) + 3.0 > mfInfo2.size(1))
                    {
                      i2 = 0;
                      i3 = 0;
                    } else {
                      i2 = idR_data[0] + 2;
                      i3 = mfInfo2.size(1);
                    }

                    loop_ub = i3 - i2;
                    for (i3 = 0; i3 < loop_ub; i3++) {
                      mfInfo3[i3] = mfInfo2[i2 + i3];
                    }

                    bufferEqual.set_size(1, mfInfo3.size(1));
                    loop_ub = mfInfo3.size(0) * mfInfo3.size(1);
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      bufferEqual[i2] = (mfInfo3[i2] == 39);
                    }

                    eml_find(bufferEqual, idR_data, idR_size);
                    nextLineVar.set_size(1, (static_cast<int>(maxLineLength)));
                    for (i2 = 0; i2 < f_loop_ub; i2++) {
                      nextLineVar[i2] = 0U;
                    }

                    if (1.0 > static_cast<double>(idR_data[0]) - 1.0) {
                      loop_ub = 0;
                    } else {
                      loop_ub = idR_data[0] - 1;
                    }

                    for (i2 = 0; i2 < loop_ub; i2++) {
                      nextLineVar[i2] = mfInfo3[i2];
                    }

                    for (i2 = 0; i2 < g_loop_ub; i2++) {
                      var[b_i].mf[j].type[i2] = static_cast<signed char>
                        (nextLineVar[i2]);
                    }

                    deblank(var[b_i].mf[j].type, r);
                    var[b_i].mf[j].origTypeLength = r.size(1);
                    nextLineVar.set_size(1, (static_cast<int>(maxLineLength)));
                    for (i2 = 0; i2 < h_loop_ub; i2++) {
                      nextLineVar[i2] = 0U;
                    }

                    if (static_cast<double>(idR_data[0]) + 3.0 > mfInfo3.size(1))
                    {
                      i2 = 0;
                      i3 = 0;
                    } else {
                      i2 = idR_data[0] + 2;
                      i3 = mfInfo3.size(1);
                    }

                    loop_ub = i3 - i2;
                    for (i3 = 0; i3 < loop_ub; i3++) {
                      nextLineVar[i3] = mfInfo3[i2 + i3];
                    }

                    bufferEqual.set_size(1, nextLineVar.size(1));
                    loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      bufferEqual[i2] = (nextLineVar[i2] == 32);
                    }

                    b_eml_find(bufferEqual, ids);
                    i2 = ids.size(1);
                    for (int k = 0; k < i2; k++) {
                      if (k + 1 == ids.size(1)) {
                        double startIndex;
                        int i4;
                        if (k + 1 == 1) {
                          startIndex = 1.0;
                        } else {
                          startIndex = static_cast<double>(ids[k - 1]) + 1.0;
                        }

                        if (startIndex > static_cast<double>(ids[k]) - 1.0) {
                          i3 = -1;
                          i4 = -1;
                        } else {
                          i3 = static_cast<int>(startIndex) - 2;
                          i4 = ids[k] - 2;
                        }

                        loop_ub = i4 - i3;
                        b_nextLineVar.set_size(1, loop_ub);
                        for (i4 = 0; i4 < loop_ub; i4++) {
                          b_nextLineVar[i4] = static_cast<signed char>
                            (nextLineVar[(i3 + i4) + 1]);
                        }

                        dc = str2double(b_nextLineVar);
                        var[b_i].mf[j].params[k] = dc.re;
                        if (static_cast<double>(ids[k]) + 1.0 > nextLineVar.size
                            (1)) {
                          i3 = -1;
                          i4 = -1;
                        } else {
                          i3 = ids[k] - 1;
                          i4 = nextLineVar.size(1) - 1;
                        }

                        unnamed_idx_1 = static_cast<unsigned int>(i4 - i3);
                        b_nextLineVar.set_size(1, (static_cast<int>
                          (unnamed_idx_1)));
                        loop_ub = static_cast<int>(unnamed_idx_1);
                        for (i4 = 0; i4 < loop_ub; i4++) {
                          b_nextLineVar[i4] = static_cast<signed char>
                            (nextLineVar[(i3 + i4) + 1]);
                        }

                        deblank(b_nextLineVar, r);
                        dc = str2double(r);
                        var[b_i].mf[j].params[k + 1] = dc.re;
                      } else {
                        double d;
                        double startIndex;
                        int i4;
                        if (k + 1 == 1) {
                          startIndex = 1.0;
                        } else {
                          startIndex = static_cast<double>(ids[k - 1]) + 1.0;
                        }

                        d = static_cast<double>(ids[k]) - 1.0;
                        if (startIndex > d) {
                          i3 = -1;
                          i4 = -1;
                        } else {
                          i3 = static_cast<int>(startIndex) - 2;
                          i4 = static_cast<int>(d) - 1;
                        }

                        loop_ub = i4 - i3;
                        b_nextLineVar.set_size(1, loop_ub);
                        for (i4 = 0; i4 < loop_ub; i4++) {
                          b_nextLineVar[i4] = static_cast<signed char>
                            (nextLineVar[(i3 + i4) + 1]);
                        }

                        dc = str2double(b_nextLineVar);
                        var[b_i].mf[j].params[k] = dc.re;
                      }
                    }

                    var[b_i].mf[j].origParamLength = static_cast<double>
                      (ids.size(1)) + 1.0;
                  }
                }
              }
            }
          }
        }

        //
        // Arguments    : double fid
        //                double maxLineLength
        //                double *info_maxInputNameLength
        //                double *info_maxNumMF
        //                double *info_maxMFNameLength
        //                double *info_maxMFTypeLength
        //                double *info_maxMFParamLength
        //                double *info_numVars
        //                boolean_T *info_hasSugenoMFs
        // Return Type  : void
        //
        void getVarInfo(double fid, double maxLineLength, double
                        *info_maxInputNameLength, double *info_maxNumMF, double *
                        info_maxMFNameLength, double *info_maxMFTypeLength,
                        double *info_maxMFParamLength, double *info_numVars,
                        boolean_T *info_hasSugenoMFs)
        {
          static const unsigned char uv[6] = { 91U, 73U, 110U, 112U, 117U, 116U
          };

          FILE * b_NULL;
          array<int, 2U> r1;
          array<char, 2U> b_nextLineVar;
          array<unsigned char, 2U> b_template;
          array<unsigned char, 2U> mfInfo2;
          array<unsigned char, 2U> mfInfo3;
          array<unsigned char, 2U> nextLineVar;
          array<char, 2U> r;
          array<boolean_T, 2U> bufferEqual;
          int id_size[2];
          int id_data[1];
          int b_loop_ub;
          int c_loop_ub;
          int d_loop_ub;
          int e_loop_ub;
          int f_loop_ub;
          int i;
          int loop_ub;
          int maxInputNameLength;
          int maxMFNameLength;
          unsigned int maxMFParamLength;
          int maxMFTypeLength;
          *info_numVars = 0.0;
          maxInputNameLength = 0;
          *info_maxNumMF = 0.0;
          maxMFNameLength = 0;
          maxMFTypeLength = 0;
          maxMFParamLength = 0U;
          b_template.set_size(1, (static_cast<int>(maxLineLength)));
          loop_ub = static_cast<int>(maxLineLength);
          for (i = 0; i < loop_ub; i++) {
            b_template[i] = 0U;
          }

          for (i = 0; i < 6; i++) {
            b_template[i] = uv[i];
          }

          b_NULL = NULL;
          FILE * filestar;
          int exitg1;
          do {
            exitg1 = 0;
            filestar = fileManager(fid);
            if (filestar == b_NULL) {
              i = 0;
            } else {
              int st;
              st = feof(filestar);
              i = ((int)st != 0);
            }

            if (i == 0) {
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

              bufferEqual.set_size(1, nextLineVar.size(1));
              loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
              for (i = 0; i < loop_ub; i++) {
                bufferEqual[i] = (nextLineVar[i] == b_template[i]);
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
                creal_T dc;
                (*info_numVars)++;
                findTopic(fid, maxLineLength, nextLineVar);
                b_nextLineVar.set_size(1, nextLineVar.size(1));
                loop_ub = nextLineVar.size(1);
                for (i = 0; i < loop_ub; i++) {
                  b_nextLineVar[i] = static_cast<signed char>(nextLineVar[i]);
                }

                deblank(b_nextLineVar, r);
                if (r.size(1) > maxInputNameLength) {
                  maxInputNameLength = r.size(1);
                }

                h_findTopic(fid, maxLineLength, nextLineVar);
                b_nextLineVar.set_size(1, nextLineVar.size(1));
                loop_ub = nextLineVar.size(1);
                for (i = 0; i < loop_ub; i++) {
                  b_nextLineVar[i] = static_cast<signed char>(nextLineVar[i]);
                }

                deblank(b_nextLineVar, r);
                dc = str2double(r);
                if (dc.re > *info_maxNumMF) {
                  *info_maxNumMF = dc.re;
                }

                i = static_cast<int>(dc.re);
                if (0 <= static_cast<int>(dc.re) - 1) {
                  b_loop_ub = static_cast<int>(maxLineLength);
                  c_loop_ub = static_cast<int>(maxLineLength);
                  d_loop_ub = static_cast<int>(maxLineLength);
                  e_loop_ub = static_cast<int>(maxLineLength);
                  f_loop_ub = static_cast<int>(maxLineLength);
                }

                for (int j = 0; j < i; j++) {
                  int i1;
                  int i2;
                  i_findTopic(fid, maxLineLength, nextLineVar);
                  mfInfo2.set_size(1, (static_cast<int>(maxLineLength)));
                  for (i1 = 0; i1 < b_loop_ub; i1++) {
                    mfInfo2[i1] = 0U;
                  }

                  loop_ub = nextLineVar.size(1) - 3;
                  for (i1 = 0; i1 <= loop_ub; i1++) {
                    mfInfo2[i1] = nextLineVar[i1 + 2];
                  }

                  bufferEqual.set_size(1, mfInfo2.size(1));
                  loop_ub = mfInfo2.size(0) * mfInfo2.size(1);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    bufferEqual[i1] = (mfInfo2[i1] == 39);
                  }

                  eml_find(bufferEqual, id_data, id_size);
                  nextLineVar.set_size(1, (static_cast<int>(maxLineLength)));
                  for (i1 = 0; i1 < c_loop_ub; i1++) {
                    nextLineVar[i1] = 0U;
                  }

                  if (1.0 > static_cast<double>(id_data[0]) - 1.0) {
                    loop_ub = 0;
                  } else {
                    loop_ub = id_data[0] - 1;
                  }

                  for (i1 = 0; i1 < loop_ub; i1++) {
                    nextLineVar[i1] = mfInfo2[i1];
                  }

                  loop_ub = nextLineVar.size(1);
                  b_nextLineVar.set_size(1, nextLineVar.size(1));
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    b_nextLineVar[i1] = static_cast<signed char>(nextLineVar[i1]);
                  }

                  deblank(b_nextLineVar, r);
                  if (r.size(1) > maxMFNameLength) {
                    maxMFNameLength = r.size(1);
                  }

                  mfInfo3.set_size(1, (static_cast<int>(maxLineLength)));
                  for (i1 = 0; i1 < d_loop_ub; i1++) {
                    mfInfo3[i1] = 0U;
                  }

                  if (static_cast<double>(id_data[0]) + 3.0 > mfInfo2.size(1)) {
                    i1 = 0;
                    i2 = 0;
                  } else {
                    i1 = id_data[0] + 2;
                    i2 = mfInfo2.size(1);
                  }

                  loop_ub = i2 - i1;
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    mfInfo3[i2] = mfInfo2[i1 + i2];
                  }

                  bufferEqual.set_size(1, mfInfo3.size(1));
                  loop_ub = mfInfo3.size(0) * mfInfo3.size(1);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    bufferEqual[i1] = (mfInfo3[i1] == 39);
                  }

                  eml_find(bufferEqual, id_data, id_size);
                  nextLineVar.set_size(1, (static_cast<int>(maxLineLength)));
                  for (i1 = 0; i1 < e_loop_ub; i1++) {
                    nextLineVar[i1] = 0U;
                  }

                  if (1.0 > static_cast<double>(id_data[0]) - 1.0) {
                    loop_ub = 0;
                  } else {
                    loop_ub = id_data[0] - 1;
                  }

                  for (i1 = 0; i1 < loop_ub; i1++) {
                    nextLineVar[i1] = mfInfo3[i1];
                  }

                  loop_ub = nextLineVar.size(1);
                  b_nextLineVar.set_size(1, nextLineVar.size(1));
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    b_nextLineVar[i1] = static_cast<signed char>(nextLineVar[i1]);
                  }

                  deblank(b_nextLineVar, r);
                  if (r.size(1) > maxMFTypeLength) {
                    maxMFTypeLength = r.size(1);
                  }

                  nextLineVar.set_size(1, (static_cast<int>(maxLineLength)));
                  for (i1 = 0; i1 < f_loop_ub; i1++) {
                    nextLineVar[i1] = 0U;
                  }

                  if (static_cast<double>(id_data[0]) + 3.0 > mfInfo3.size(1)) {
                    i1 = 0;
                    i2 = 0;
                  } else {
                    i1 = id_data[0] + 2;
                    i2 = mfInfo3.size(1);
                  }

                  loop_ub = i2 - i1;
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    nextLineVar[i2] = mfInfo3[i1 + i2];
                  }

                  bufferEqual.set_size(1, nextLineVar.size(1));
                  loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    bufferEqual[i1] = (nextLineVar[i1] == 44);
                  }

                  eml_find(bufferEqual, id_data, id_size);
                  if (id_size[1] != 0) {
                    cfclose(fid);
                    exit(0);
                  }

                  bufferEqual.set_size(1, nextLineVar.size(1));
                  loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    bufferEqual[i1] = (nextLineVar[i1] == 32);
                  }

                  b_eml_find(bufferEqual, r1);
                  if (r1.size(1) + 1U > maxMFParamLength) {
                    maxMFParamLength = r1.size(1) + 1U;
                  }
                }
              }
            } else {
              exitg1 = 1;
            }
          } while (exitg1 == 0);

          *info_maxInputNameLength = maxInputNameLength;
          *info_maxMFNameLength = maxMFNameLength;
          *info_maxMFTypeLength = maxMFTypeLength;
          *info_maxMFParamLength = maxMFParamLength;
          *info_hasSugenoMFs = false;
        }
      }
    }
  }
}

//
// File trailer for readFISAsHomogenousStructure.cpp
//
// [EOF]
//
