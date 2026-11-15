//
// File: getFISCodeGenerationData.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "getFISCodeGenerationData.h"
#include "any1.h"
#include "deblank.h"
#include "fileManager.h"
#include "findTopic.h"
#include "frewind.h"
#include "getFileID.h"
#include "getNextLine.h"
#include "getRules.h"
#include "opkene_internal_types.h"
#include "readFISAsHomogenousStructure.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <stdio.h>

// Function Definitions
//
// Arguments    : const ::coder::array<char, 2U> &name
//                ::coder::array<char, 2U> &fis_name
//                ::coder::array<char, 2U> &fis_type
//                ::coder::array<char, 2U> &fis_andMethod
//                ::coder::array<char, 2U> &fis_orMethod
//                ::coder::array<char, 2U> &fis_defuzzMethod
//                ::coder::array<char, 2U> &fis_impMethod
//                ::coder::array<char, 2U> &fis_aggMethod
//                ::coder::array<b_struct_T, 2U> &fis_input
//                ::coder::array<b_struct_T, 2U> &fis_output
//                ::coder::array<c_struct_T, 2U> &fis_rule
// Return Type  : void
//
namespace coder
{
  void getFISCodeGenerationData(const ::coder::array<char, 2U> &name, ::coder::
    array<char, 2U> &fis_name, ::coder::array<char, 2U> &fis_type, ::coder::
    array<char, 2U> &fis_andMethod, ::coder::array<char, 2U> &fis_orMethod, ::
    coder::array<char, 2U> &fis_defuzzMethod, ::coder::array<char, 2U>
    &fis_impMethod, ::coder::array<char, 2U> &fis_aggMethod, ::coder::array<
    b_struct_T, 2U> &fis_input, ::coder::array<b_struct_T, 2U> &fis_output, ::
    coder::array<c_struct_T, 2U> &fis_rule)
  {
    static const char cv[8] = { '[', 'S', 'y', 's', 't', 'e', 'm', ']' };

    static const unsigned char uv2[8] = { 85U, 110U, 116U, 105U, 116U, 108U,
      101U, 100U };

    static const unsigned char uv4[8] = { 99U, 101U, 110U, 116U, 114U, 111U,
      105U, 100U };

    static const unsigned char uv[7] = { 109U, 97U, 109U, 100U, 97U, 110U, 105U
    };

    static const char cv1[6] = { 's', 'u', 'g', 'e', 'n', 'o' };

    static const unsigned char uv1[6] = { 115U, 117U, 103U, 101U, 110U, 111U };

    static const unsigned char uv3[6] = { 112U, 114U, 111U, 98U, 111U, 114U };

    static const unsigned char uv5[6] = { 119U, 116U, 97U, 118U, 101U, 114U };

    array<int, 2U> r;
    array<int, 2U> r1;
    array<int, 2U> r2;
    array<int, 2U> r3;
    array<int, 2U> r4;
    array<int, 2U> r5;
    array<int, 2U> r6;
    array<char, 2U> a;
    array<unsigned char, 2U> aggMethod;
    array<unsigned char, 2U> andMethod;
    array<char, 2U> b_nextLineVar;
    array<unsigned char, 2U> defuzzMethod;
    array<unsigned char, 2U> impMethod;
    array<unsigned char, 2U> nextLineVar;
    array<unsigned char, 2U> orMethod;
    array<unsigned char, 2U> type;
    double fid;
    double inputInfo_maxInputNameLength;
    double inputInfo_maxMFNameLength;
    double inputInfo_maxMFParamLength;
    double inputInfo_maxMFTypeLength;
    double inputInfo_maxNumMF;
    double inputInfo_numVars;
    double maxLineLength;
    double outputInfo_maxInputNameLength;
    double outputInfo_maxMFNameLength;
    double outputInfo_maxMFParamLength;
    double outputInfo_maxMFTypeLength;
    double outputInfo_maxNumMF;
    double outputInfo_numVars;
    int exitg1;
    int i;
    int impMethod_idx_1;
    int loop_ub;
    boolean_T b_bool;
    boolean_T systemSectionHeaderFound;
    fuzzy::internal::codegen::getFileID(name, &fid, &maxLineLength);
    if (maxLineLength < 8.0) {
      maxLineLength = 8.0;
    }

    systemSectionHeaderFound = false;
    int exitg2;
    do {
      exitg2 = 0;
      if (!systemSectionHeaderFound) {
        FILE * b_NULL;
        FILE * filestar;
        boolean_T exitg3;
        fuzzy::internal::codegen::getLine(fid, maxLineLength, nextLineVar);
        exitg3 = false;
        while ((!exitg3) && any(nextLineVar)) {
          b_bool = !(static_cast<signed char>(nextLineVar[0]) != '%');
          if ((!b_bool) && (nextLineVar[0] != 10)) {
            exitg3 = true;
          } else {
            fuzzy::internal::codegen::getLine(fid, maxLineLength, nextLineVar);
          }
        }

        b_NULL = NULL;
        filestar = fileManager(fid);
        if (filestar == b_NULL) {
          impMethod_idx_1 = 0;
        } else {
          int st;
          st = feof(filestar);
          impMethod_idx_1 = ((int)st != 0);
        }

        if (impMethod_idx_1 != 0) {
          exitg2 = 1;
        } else {
          b_nextLineVar.set_size(1, nextLineVar.size(1));
          loop_ub = nextLineVar.size(1);
          for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++)
          {
            b_nextLineVar[impMethod_idx_1] = static_cast<signed char>
              (nextLineVar[impMethod_idx_1]);
          }

          deblank(b_nextLineVar, a);
          systemSectionHeaderFound = false;
          if (a.size(1) == 8) {
            loop_ub = 0;
            do {
              exitg1 = 0;
              if (loop_ub < 8) {
                if (a[loop_ub] != cv[loop_ub]) {
                  exitg1 = 1;
                } else {
                  loop_ub++;
                }
              } else {
                systemSectionHeaderFound = true;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (systemSectionHeaderFound) {
      fuzzy::internal::codegen::findTopic(fid, maxLineLength, nextLineVar);
      fuzzy::internal::codegen::b_findTopic(fid, maxLineLength, type);
      fuzzy::internal::codegen::c_findTopic(fid, maxLineLength, andMethod);
      fuzzy::internal::codegen::d_findTopic(fid, maxLineLength, orMethod);
      fuzzy::internal::codegen::e_findTopic(fid, maxLineLength, impMethod);
      fuzzy::internal::codegen::f_findTopic(fid, maxLineLength, aggMethod);
      fuzzy::internal::codegen::g_findTopic(fid, maxLineLength, defuzzMethod);
    } else {
      nextLineVar.set_size(1, (static_cast<int>(maxLineLength)));
      loop_ub = static_cast<int>(maxLineLength);
      for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
        nextLineVar[impMethod_idx_1] = 0U;
      }

      type.set_size(1, (static_cast<int>(maxLineLength)));
      loop_ub = static_cast<int>(maxLineLength);
      for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
        type[impMethod_idx_1] = 0U;
      }

      andMethod.set_size(1, (static_cast<int>(maxLineLength)));
      loop_ub = static_cast<int>(maxLineLength);
      for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
        andMethod[impMethod_idx_1] = 0U;
      }

      orMethod.set_size(1, (static_cast<int>(maxLineLength)));
      loop_ub = static_cast<int>(maxLineLength);
      for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
        orMethod[impMethod_idx_1] = 0U;
      }

      impMethod.set_size(1, (static_cast<int>(maxLineLength)));
      loop_ub = static_cast<int>(maxLineLength);
      for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
        impMethod[impMethod_idx_1] = 0U;
      }

      aggMethod.set_size(1, (static_cast<int>(maxLineLength)));
      loop_ub = static_cast<int>(maxLineLength);
      for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
        aggMethod[impMethod_idx_1] = 0U;
      }

      defuzzMethod.set_size(1, (static_cast<int>(maxLineLength)));
      loop_ub = static_cast<int>(maxLineLength);
      for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
        defuzzMethod[impMethod_idx_1] = 0U;
      }
    }

    frewind(fid);
    fuzzy::internal::codegen::getVarInfo(fid, maxLineLength,
      &inputInfo_maxInputNameLength, &inputInfo_maxNumMF,
      &inputInfo_maxMFNameLength, &inputInfo_maxMFTypeLength,
      &inputInfo_maxMFParamLength, &inputInfo_numVars, &b_bool);
    frewind(fid);
    if ((!systemSectionHeaderFound) || (!any(type))) {
      b_bool = true;
    } else {
      b_bool = false;
    }

    fuzzy::internal::codegen::b_getVarInfo(fid, maxLineLength, b_bool,
      &outputInfo_maxInputNameLength, &outputInfo_maxNumMF,
      &outputInfo_maxMFNameLength, &outputInfo_maxMFTypeLength,
      &outputInfo_maxMFParamLength, &outputInfo_numVars,
      &systemSectionHeaderFound);
    frewind(fid);
    if (b_bool) {
      if (systemSectionHeaderFound) {
        for (impMethod_idx_1 = 0; impMethod_idx_1 < 6; impMethod_idx_1++) {
          type[impMethod_idx_1] = uv1[impMethod_idx_1];
        }
      } else {
        for (impMethod_idx_1 = 0; impMethod_idx_1 < 7; impMethod_idx_1++) {
          type[impMethod_idx_1] = uv[impMethod_idx_1];
        }
      }
    } else {
      b_nextLineVar.set_size(1, type.size(1));
      loop_ub = type.size(1);
      for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
        b_nextLineVar[impMethod_idx_1] = static_cast<signed char>
          (type[impMethod_idx_1]);
      }

      deblank(b_nextLineVar, a);
      systemSectionHeaderFound = false;
      if (a.size(1) == 6) {
        loop_ub = 0;
        do {
          exitg1 = 0;
          if (loop_ub < 6) {
            if (a[loop_ub] != cv1[loop_ub]) {
              exitg1 = 1;
            } else {
              loop_ub++;
            }
          } else {
            systemSectionHeaderFound = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
    }

    fuzzy::internal::codegen::getVar(fid, maxLineLength,
      inputInfo_maxInputNameLength, inputInfo_maxNumMF,
      inputInfo_maxMFNameLength, inputInfo_maxMFTypeLength,
      inputInfo_maxMFParamLength, inputInfo_numVars, fis_input);
    fuzzy::internal::codegen::b_getVar(fid, maxLineLength,
      outputInfo_maxInputNameLength, outputInfo_maxNumMF,
      outputInfo_maxMFNameLength, outputInfo_maxMFTypeLength,
      outputInfo_maxMFParamLength, outputInfo_numVars, systemSectionHeaderFound,
      fis_output);
    fuzzy::internal::codegen::getRules(fid, maxLineLength, inputInfo_numVars,
      outputInfo_numVars, fis_rule);
    if (!any(nextLineVar)) {
      for (impMethod_idx_1 = 0; impMethod_idx_1 < 8; impMethod_idx_1++) {
        nextLineVar[impMethod_idx_1] = uv2[impMethod_idx_1];
      }
    }

    if (systemSectionHeaderFound) {
      loop_ub = impMethod.size(0);
      impMethod_idx_1 = impMethod.size(1);
      impMethod.set_size(1, impMethod_idx_1);
      loop_ub *= impMethod_idx_1;
      for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
        impMethod[impMethod_idx_1] = 0U;
      }

      impMethod[0] = 112U;
      impMethod[1] = 114U;
      impMethod[2] = 111U;
      impMethod[3] = 100U;
      loop_ub = aggMethod.size(0);
      impMethod_idx_1 = aggMethod.size(1);
      aggMethod.set_size(1, impMethod_idx_1);
      loop_ub *= impMethod_idx_1;
      for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
        aggMethod[impMethod_idx_1] = 0U;
      }

      aggMethod[0] = 115U;
      aggMethod[1] = 117U;
      aggMethod[2] = 109U;
    }

    if (!any(andMethod)) {
      if (systemSectionHeaderFound) {
        andMethod[0] = 112U;
        andMethod[1] = 114U;
        andMethod[2] = 111U;
        andMethod[3] = 100U;
      } else {
        andMethod[0] = 109U;
        andMethod[1] = 105U;
        andMethod[2] = 110U;
      }
    }

    if (!any(orMethod)) {
      if (systemSectionHeaderFound) {
        for (impMethod_idx_1 = 0; impMethod_idx_1 < 6; impMethod_idx_1++) {
          orMethod[impMethod_idx_1] = uv3[impMethod_idx_1];
        }
      } else {
        orMethod[0] = 109U;
        orMethod[1] = 97U;
        orMethod[2] = 120U;
      }
    }

    if ((!any(impMethod)) && (!systemSectionHeaderFound)) {
      impMethod[0] = 109U;
      impMethod[1] = 105U;
      impMethod[2] = 110U;
    }

    if ((!any(aggMethod)) && (!systemSectionHeaderFound)) {
      aggMethod[0] = 109U;
      aggMethod[1] = 97U;
      aggMethod[2] = 120U;
    }

    if (!any(defuzzMethod)) {
      if (systemSectionHeaderFound) {
        for (impMethod_idx_1 = 0; impMethod_idx_1 < 6; impMethod_idx_1++) {
          defuzzMethod[impMethod_idx_1] = uv5[impMethod_idx_1];
        }
      } else {
        for (impMethod_idx_1 = 0; impMethod_idx_1 < 8; impMethod_idx_1++) {
          defuzzMethod[impMethod_idx_1] = uv4[impMethod_idx_1];
        }
      }
    }

    impMethod_idx_1 = nextLineVar.size(1) - 1;
    loop_ub = 0;
    for (i = 0; i <= impMethod_idx_1; i++) {
      if (nextLineVar[i] != 0) {
        loop_ub++;
      }
    }

    r.set_size(1, loop_ub);
    loop_ub = 0;
    for (i = 0; i <= impMethod_idx_1; i++) {
      if (nextLineVar[i] != 0) {
        r[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    fis_name.set_size(1, r.size(1));
    loop_ub = r.size(1);
    for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
      fis_name[impMethod_idx_1] = static_cast<signed char>
        (nextLineVar[r[impMethod_idx_1] - 1]);
    }

    impMethod_idx_1 = type.size(1) - 1;
    loop_ub = 0;
    for (i = 0; i <= impMethod_idx_1; i++) {
      if (type[i] != 0) {
        loop_ub++;
      }
    }

    r1.set_size(1, loop_ub);
    loop_ub = 0;
    for (i = 0; i <= impMethod_idx_1; i++) {
      if (type[i] != 0) {
        r1[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    fis_type.set_size(1, r1.size(1));
    loop_ub = r1.size(1);
    for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
      fis_type[impMethod_idx_1] = static_cast<signed char>
        (type[r1[impMethod_idx_1] - 1]);
    }

    impMethod_idx_1 = andMethod.size(1) - 1;
    loop_ub = 0;
    for (i = 0; i <= impMethod_idx_1; i++) {
      if (andMethod[i] != 0) {
        loop_ub++;
      }
    }

    r2.set_size(1, loop_ub);
    loop_ub = 0;
    for (i = 0; i <= impMethod_idx_1; i++) {
      if (andMethod[i] != 0) {
        r2[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    fis_andMethod.set_size(1, r2.size(1));
    loop_ub = r2.size(1);
    for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
      fis_andMethod[impMethod_idx_1] = static_cast<signed char>
        (andMethod[r2[impMethod_idx_1] - 1]);
    }

    impMethod_idx_1 = orMethod.size(1) - 1;
    loop_ub = 0;
    for (i = 0; i <= impMethod_idx_1; i++) {
      if (orMethod[i] != 0) {
        loop_ub++;
      }
    }

    r3.set_size(1, loop_ub);
    loop_ub = 0;
    for (i = 0; i <= impMethod_idx_1; i++) {
      if (orMethod[i] != 0) {
        r3[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    fis_orMethod.set_size(1, r3.size(1));
    loop_ub = r3.size(1);
    for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
      fis_orMethod[impMethod_idx_1] = static_cast<signed char>
        (orMethod[r3[impMethod_idx_1] - 1]);
    }

    impMethod_idx_1 = defuzzMethod.size(1) - 1;
    loop_ub = 0;
    for (i = 0; i <= impMethod_idx_1; i++) {
      if (defuzzMethod[i] != 0) {
        loop_ub++;
      }
    }

    r4.set_size(1, loop_ub);
    loop_ub = 0;
    for (i = 0; i <= impMethod_idx_1; i++) {
      if (defuzzMethod[i] != 0) {
        r4[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    fis_defuzzMethod.set_size(1, r4.size(1));
    loop_ub = r4.size(1);
    for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
      fis_defuzzMethod[impMethod_idx_1] = static_cast<signed char>
        (defuzzMethod[r4[impMethod_idx_1] - 1]);
    }

    impMethod_idx_1 = impMethod.size(1) - 1;
    loop_ub = 0;
    for (i = 0; i <= impMethod_idx_1; i++) {
      if (impMethod[i] != 0) {
        loop_ub++;
      }
    }

    r5.set_size(1, loop_ub);
    loop_ub = 0;
    for (i = 0; i <= impMethod_idx_1; i++) {
      if (impMethod[i] != 0) {
        r5[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    fis_impMethod.set_size(1, r5.size(1));
    loop_ub = r5.size(1);
    for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
      fis_impMethod[impMethod_idx_1] = static_cast<signed char>
        (impMethod[r5[impMethod_idx_1] - 1]);
    }

    impMethod_idx_1 = aggMethod.size(1) - 1;
    loop_ub = 0;
    for (i = 0; i <= impMethod_idx_1; i++) {
      if (aggMethod[i] != 0) {
        loop_ub++;
      }
    }

    r6.set_size(1, loop_ub);
    loop_ub = 0;
    for (i = 0; i <= impMethod_idx_1; i++) {
      if (aggMethod[i] != 0) {
        r6[loop_ub] = i + 1;
        loop_ub++;
      }
    }

    fis_aggMethod.set_size(1, r6.size(1));
    loop_ub = r6.size(1);
    for (impMethod_idx_1 = 0; impMethod_idx_1 < loop_ub; impMethod_idx_1++) {
      fis_aggMethod[impMethod_idx_1] = static_cast<signed char>
        (aggMethod[r6[impMethod_idx_1] - 1]);
    }

    cfclose(fid);
  }
}

//
// File trailer for getFISCodeGenerationData.cpp
//
// [EOF]
//
