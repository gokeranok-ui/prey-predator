//
// File: getRules.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "getRules.h"
#include "deblank.h"
#include "feof.h"
#include "fileManager.h"
#include "find.h"
#include "frewind.h"
#include "getNextLine.h"
#include "opkene_internal_types.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include "coder_array.h"
#include <cstring>
#include <stdio.h>

// Function Declarations
namespace coder
{
  namespace fuzzy
  {
    namespace internal
    {
      namespace codegen
      {
        static double getNumRules(double fid, double maxLineLength);
      }
    }
  }
}

// Function Definitions
//
// Arguments    : double fid
//                double maxLineLength
// Return Type  : double
//
namespace coder
{
  namespace fuzzy
  {
    namespace internal
    {
      namespace codegen
      {
        static double getNumRules(double fid, double maxLineLength)
        {
          static const char cv[7] = { '[', 'R', 'u', 'l', 'e', 's', ']' };

          array<char, 2U> a;
          array<char, 2U> b_nextLineVar;
          array<unsigned char, 2U> nextLineVar;
          double numRules;
          boolean_T exitg1;
          boolean_T topicFound;
          numRules = 0.0;
          topicFound = false;
          exitg1 = false;
          while ((!exitg1) && (!topicFound)) {
            FILE * b_NULL;
            FILE * filestar;
            int exitg2;
            int ix;
            int st;
            boolean_T exitg3;
            boolean_T y;
            getLine(fid, maxLineLength, nextLineVar);
            do {
              exitg2 = 0;
              y = false;
              ix = 1;
              exitg3 = false;
              while ((!exitg3) && (ix <= nextLineVar.size(1))) {
                if (nextLineVar[ix - 1] == 0) {
                  ix++;
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
              ix = 0;
            } else {
              st = feof(filestar);
              ix = ((int)st != 0);
            }

            if (ix != 0) {
              exitg1 = true;
            } else {
              int loop_ub;
              b_nextLineVar.set_size(1, nextLineVar.size(1));
              loop_ub = nextLineVar.size(1);
              for (ix = 0; ix < loop_ub; ix++) {
                b_nextLineVar[ix] = static_cast<signed char>(nextLineVar[ix]);
              }

              deblank(b_nextLineVar, a);
              y = false;
              if (a.size(1) == 7) {
                ix = 0;
                do {
                  exitg2 = 0;
                  if (ix < 7) {
                    if (a[ix] != cv[ix]) {
                      exitg2 = 1;
                    } else {
                      ix++;
                    }
                  } else {
                    y = true;
                    exitg2 = 1;
                  }
                } while (exitg2 == 0);
              }

              if (y) {
                topicFound = true;
                b_NULL = NULL;
                do {
                  exitg2 = 0;
                  getLine(fid, maxLineLength, nextLineVar);
                  int exitg4;
                  do {
                    exitg4 = 0;
                    y = false;
                    ix = 1;
                    exitg3 = false;
                    while ((!exitg3) && (ix <= nextLineVar.size(1))) {
                      if (nextLineVar[ix - 1] == 0) {
                        ix++;
                      } else {
                        y = true;
                        exitg3 = true;
                      }
                    }

                    if (y) {
                      y = !(static_cast<signed char>(nextLineVar[0]) != '%');
                      if ((!y) && (nextLineVar[0] != 10)) {
                        exitg4 = 1;
                      } else {
                        getLine(fid, maxLineLength, nextLineVar);
                      }
                    } else {
                      exitg4 = 1;
                    }
                  } while (exitg4 == 0);

                  filestar = fileManager(fid);
                  if (filestar == b_NULL) {
                    ix = 0;
                  } else {
                    st = feof(filestar);
                    ix = ((int)st != 0);
                  }

                  if (ix != 0) {
                    exitg2 = 1;
                  } else {
                    y = false;
                    ix = 1;
                    exitg3 = false;
                    while ((!exitg3) && (ix <= nextLineVar.size(1))) {
                      if (nextLineVar[ix - 1] == 0) {
                        ix++;
                      } else {
                        y = true;
                        exitg3 = true;
                      }
                    }

                    if (y && (nextLineVar[0] != 10)) {
                      numRules++;
                    }
                  }
                } while (exitg2 == 0);
              }
            }
          }

          return numRules;
        }

        //
        // Arguments    : double fid
        //                double maxLineLength
        //                double numInputs
        //                double numOutputs
        //                ::coder::array<c_struct_T, 2U> &rules
        // Return Type  : void
        //
        void getRules(double fid, double maxLineLength, double numInputs, double
                      numOutputs, ::coder::array<c_struct_T, 2U> &rules)
        {
          static const char cv[7] = { '[', 'R', 'u', 'l', 'e', 's', ']' };

          array<int, 2U> wt;
          array<char, 2U> a;
          array<unsigned char, 2U> ant;
          array<char, 2U> b_nextLineVar;
          array<unsigned char, 2U> con;
          array<unsigned char, 2U> nextLineVar;
          array<boolean_T, 2U> c_nextLineVar;
          c_struct_T rule;
          double numRules;
          int tmp_size[2];
          int id2_data[1];
          int id_data[1];
          int tmp_data[1];
          int i;
          int loop_ub;
          rule.antecedent.set_size(1, (static_cast<int>(numInputs)));
          loop_ub = static_cast<int>(numInputs);
          for (i = 0; i < loop_ub; i++) {
            rule.antecedent[i] = 0.0;
          }

          rule.consequent.set_size(1, (static_cast<int>(numOutputs)));
          loop_ub = static_cast<int>(numOutputs);
          for (i = 0; i < loop_ub; i++) {
            rule.consequent[i] = 0.0;
          }

          rule.weight = 0.0;
          rule.connection = 0.0;
          numRules = getNumRules(fid, maxLineLength);
          rules.set_size(1, (static_cast<int>(numRules)));
          loop_ub = static_cast<int>(numRules);
          for (i = 0; i < loop_ub; i++) {
            rules[i] = rule;
          }

          if (!(numRules == 0.0)) {
            boolean_T topicFound;
            frewind(fid);
            topicFound = false;
            int exitg2;
            do {
              exitg2 = 0;
              if (!topicFound) {
                double d;
                getNextLine(fid, maxLineLength, nextLineVar);
                d = b_feof(fid);
                if (d != 0.0) {
                  exitg2 = 1;
                } else {
                  boolean_T b_bool;
                  b_nextLineVar.set_size(1, nextLineVar.size(1));
                  loop_ub = nextLineVar.size(1);
                  for (i = 0; i < loop_ub; i++) {
                    b_nextLineVar[i] = static_cast<signed char>(nextLineVar[i]);
                  }

                  deblank(b_nextLineVar, a);
                  b_bool = false;
                  if (a.size(1) == 7) {
                    loop_ub = 0;
                    int exitg3;
                    do {
                      exitg3 = 0;
                      if (loop_ub < 7) {
                        if (a[loop_ub] != cv[loop_ub]) {
                          exitg3 = 1;
                        } else {
                          loop_ub++;
                        }
                      } else {
                        b_bool = true;
                        exitg3 = 1;
                      }
                    } while (exitg3 == 0);
                  }

                  if (b_bool) {
                    int b_i;
                    boolean_T exitg1;
                    topicFound = true;
                    b_i = 0;
                    exitg1 = false;
                    while ((!exitg1) && (b_i <= static_cast<int>(numRules) - 1))
                    {
                      getNextLine(fid, maxLineLength, nextLineVar);
                      d = b_feof(fid);
                      if (d != 0.0) {
                        exitg1 = true;
                      } else {
                        creal_T dc;
                        double startIndex;
                        int i1;
                        int i2;
                        int k;
                        unsigned int unnamed_idx_1;
                        c_nextLineVar.set_size(1, nextLineVar.size(1));
                        loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                        for (i = 0; i < loop_ub; i++) {
                          c_nextLineVar[i] = (nextLineVar[i] == 44);
                        }

                        eml_find(c_nextLineVar, tmp_data, tmp_size);
                        loop_ub = tmp_size[0] * tmp_size[1];
                        if (0 <= loop_ub - 1) {
                          std::memcpy(&id_data[0], &tmp_data[0], loop_ub *
                                      sizeof(int));
                        }

                        ant.set_size(1, (id_data[0] - 1));
                        loop_ub = id_data[0] - 1;
                        for (i = 0; i < loop_ub; i++) {
                          ant[i] = 0U;
                        }

                        if (1.0 > static_cast<double>(id_data[0]) - 1.0) {
                          loop_ub = 0;
                        } else {
                          loop_ub = id_data[0] - 1;
                        }

                        for (i = 0; i < loop_ub; i++) {
                          ant[i] = nextLineVar[i];
                        }

                        loop_ub = id_data[0] + 1;
                        for (i = 0; i < loop_ub; i++) {
                          nextLineVar[i] = 0U;
                        }

                        c_nextLineVar.set_size(1, nextLineVar.size(1));
                        loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                        for (i = 0; i < loop_ub; i++) {
                          c_nextLineVar[i] = (nextLineVar[i] == 40);
                        }

                        eml_find(c_nextLineVar, tmp_data, tmp_size);
                        loop_ub = tmp_size[0] * tmp_size[1];
                        if (0 <= loop_ub - 1) {
                          std::memcpy(&id2_data[0], &tmp_data[0], loop_ub *
                                      sizeof(int));
                        }

                        loop_ub = static_cast<int>((static_cast<double>
                          (id2_data[0]) - 1.0) - (static_cast<double>(id_data[0])
                          + 2.0));
                        con.set_size(1, loop_ub);
                        for (i = 0; i < loop_ub; i++) {
                          con[i] = 0U;
                        }

                        if (static_cast<double>(id_data[0]) + 2.0 > static_cast<
                            double>(id2_data[0]) - 2.0) {
                          i = 0;
                          i1 = 0;
                        } else {
                          i = id_data[0] + 1;
                          i1 = id2_data[0] - 2;
                        }

                        loop_ub = i1 - i;
                        for (i1 = 0; i1 < loop_ub; i1++) {
                          con[i1] = nextLineVar[i + i1];
                        }

                        if (static_cast<double>(id_data[0]) + 2.0 > id2_data[0])
                        {
                          i = -1;
                          i1 = 0;
                        } else {
                          i = id_data[0];
                          i1 = id2_data[0];
                        }

                        loop_ub = (i1 - i) - 1;
                        for (i1 = 0; i1 < loop_ub; i1++) {
                          nextLineVar[(i + i1) + 1] = 0U;
                        }

                        c_nextLineVar.set_size(1, nextLineVar.size(1));
                        loop_ub = nextLineVar.size(0) * nextLineVar.size(1);
                        for (i = 0; i < loop_ub; i++) {
                          c_nextLineVar[i] = (nextLineVar[i] == 41);
                        }

                        eml_find(c_nextLineVar, tmp_data, tmp_size);
                        loop_ub = tmp_size[0] * tmp_size[1];
                        if (0 <= loop_ub - 1) {
                          std::memcpy(&id_data[0], &tmp_data[0], loop_ub *
                                      sizeof(int));
                        }

                        loop_ub = static_cast<int>((static_cast<double>(id_data
                          [0]) - static_cast<double>(id2_data[0])) - 1.0);
                        wt.set_size(1, loop_ub);
                        for (i = 0; i < loop_ub; i++) {
                          wt[i] = 0;
                        }

                        if (static_cast<double>(id2_data[0]) + 1.0 >
                            static_cast<double>(id_data[0]) - 1.0) {
                          i = 0;
                          i1 = 0;
                        } else {
                          i = id2_data[0];
                          i1 = id_data[0] - 1;
                        }

                        loop_ub = i1 - i;
                        for (i1 = 0; i1 < loop_ub; i1++) {
                          wt[i1] = nextLineVar[i + i1];
                        }

                        b_nextLineVar.set_size(1, wt.size(1));
                        loop_ub = wt.size(1);
                        for (i = 0; i < loop_ub; i++) {
                          b_nextLineVar[i] = static_cast<signed char>(wt[i]);
                        }

                        dc = str2double(b_nextLineVar);
                        rules[b_i].weight = dc.re;
                        dc = str2double(static_cast<char>(static_cast<signed
                          char>(nextLineVar[id_data[0] + 3])));
                        rules[b_i].connection = dc.re;
                        c_nextLineVar.set_size(1, ant.size(1));
                        loop_ub = ant.size(0) * ant.size(1);
                        for (i = 0; i < loop_ub; i++) {
                          c_nextLineVar[i] = (ant[i] == 32);
                        }

                        b_eml_find(c_nextLineVar, wt);
                        if (wt.size(1) == 0) {
                          if (1.0 > numInputs) {
                            cfclose(fid);
                            exit(0);
                          }

                          b_nextLineVar.set_size(1, ant.size(1));
                          loop_ub = ant.size(1);
                          for (i = 0; i < loop_ub; i++) {
                            b_nextLineVar[i] = static_cast<signed char>(ant[i]);
                          }

                          dc = str2double(b_nextLineVar);
                          rules[b_i].antecedent[0] = dc.re;
                        } else {
                          i = wt.size(1);
                          for (k = 0; k < i; k++) {
                            if (k + 1 == wt.size(1)) {
                              if (k + 1 == 1) {
                                startIndex = 1.0;
                              } else {
                                startIndex = static_cast<double>(wt[k - 1]) +
                                  1.0;
                              }

                              if (startIndex > static_cast<double>(wt[k]) - 1.0)
                              {
                                i1 = -1;
                                i2 = -1;
                              } else {
                                i1 = static_cast<int>(startIndex) - 2;
                                i2 = wt[k] - 2;
                              }

                              loop_ub = i2 - i1;
                              b_nextLineVar.set_size(1, loop_ub);
                              for (i2 = 0; i2 < loop_ub; i2++) {
                                b_nextLineVar[i2] = static_cast<signed char>
                                  (ant[(i1 + i2) + 1]);
                              }

                              dc = str2double(b_nextLineVar);
                              if ((static_cast<double>(k) + 1.0) + 1.0 >
                                  numInputs) {
                                cfclose(fid);
                                exit(0);
                              }

                              rules[b_i].antecedent[k] = dc.re;
                              if (static_cast<double>(wt[k]) + 1.0 > ant.size(1))
                              {
                                i1 = -1;
                                i2 = -1;
                              } else {
                                i1 = wt[k] - 1;
                                i2 = ant.size(1) - 1;
                              }

                              unnamed_idx_1 = static_cast<unsigned int>(i2 - i1);
                              b_nextLineVar.set_size(1, (static_cast<int>
                                (unnamed_idx_1)));
                              loop_ub = static_cast<int>(unnamed_idx_1);
                              for (i2 = 0; i2 < loop_ub; i2++) {
                                b_nextLineVar[i2] = static_cast<signed char>
                                  (ant[(i1 + i2) + 1]);
                              }

                              deblank(b_nextLineVar, a);
                              dc = str2double(a);
                              rules[b_i].antecedent[k + 1] = dc.re;
                            } else {
                              if (k + 1 == 1) {
                                startIndex = 1.0;
                              } else {
                                startIndex = static_cast<double>(wt[k - 1]) +
                                  1.0;
                              }

                              d = static_cast<double>(wt[k]) - 1.0;
                              if (startIndex > d) {
                                i1 = -1;
                                i2 = -1;
                              } else {
                                i1 = static_cast<int>(startIndex) - 2;
                                i2 = static_cast<int>(d) - 1;
                              }

                              loop_ub = i2 - i1;
                              b_nextLineVar.set_size(1, loop_ub);
                              for (i2 = 0; i2 < loop_ub; i2++) {
                                b_nextLineVar[i2] = static_cast<signed char>
                                  (ant[(i1 + i2) + 1]);
                              }

                              dc = str2double(b_nextLineVar);
                              if (static_cast<double>(k) + 1.0 > numInputs) {
                                cfclose(fid);
                                exit(0);
                              }

                              rules[b_i].antecedent[k] = dc.re;
                            }
                          }
                        }

                        c_nextLineVar.set_size(1, con.size(1));
                        loop_ub = con.size(0) * con.size(1);
                        for (i = 0; i < loop_ub; i++) {
                          c_nextLineVar[i] = (con[i] == 32);
                        }

                        b_eml_find(c_nextLineVar, wt);
                        if (wt.size(1) == 0) {
                          if (1.0 > numOutputs) {
                            cfclose(fid);
                            exit(0);
                          }

                          b_nextLineVar.set_size(1, con.size(1));
                          loop_ub = con.size(1);
                          for (i = 0; i < loop_ub; i++) {
                            b_nextLineVar[i] = static_cast<signed char>(con[i]);
                          }

                          dc = str2double(b_nextLineVar);
                          rules[b_i].consequent[0] = dc.re;
                        } else {
                          i = wt.size(1);
                          for (k = 0; k < i; k++) {
                            if (k + 1 == wt.size(1)) {
                              if (k + 1 == 1) {
                                startIndex = 1.0;
                              } else {
                                startIndex = static_cast<double>(wt[k - 1]) +
                                  1.0;
                              }

                              if (startIndex > static_cast<double>(wt[k]) - 1.0)
                              {
                                i1 = -1;
                                i2 = -1;
                              } else {
                                i1 = static_cast<int>(startIndex) - 2;
                                i2 = wt[k] - 2;
                              }

                              loop_ub = i2 - i1;
                              b_nextLineVar.set_size(1, loop_ub);
                              for (i2 = 0; i2 < loop_ub; i2++) {
                                b_nextLineVar[i2] = static_cast<signed char>
                                  (con[(i1 + i2) + 1]);
                              }

                              dc = str2double(b_nextLineVar);
                              if ((static_cast<double>(k) + 1.0) + 1.0 >
                                  numOutputs) {
                                cfclose(fid);
                                exit(0);
                              }

                              rules[b_i].consequent[k] = dc.re;
                              if (static_cast<double>(wt[k]) + 1.0 > con.size(1))
                              {
                                i1 = -1;
                                i2 = -1;
                              } else {
                                i1 = wt[k] - 1;
                                i2 = con.size(1) - 1;
                              }

                              unnamed_idx_1 = static_cast<unsigned int>(i2 - i1);
                              b_nextLineVar.set_size(1, (static_cast<int>
                                (unnamed_idx_1)));
                              loop_ub = static_cast<int>(unnamed_idx_1);
                              for (i2 = 0; i2 < loop_ub; i2++) {
                                b_nextLineVar[i2] = static_cast<signed char>
                                  (con[(i1 + i2) + 1]);
                              }

                              deblank(b_nextLineVar, a);
                              dc = str2double(a);
                              rules[b_i].consequent[k + 1] = dc.re;
                            } else {
                              if (k + 1 == 1) {
                                startIndex = 1.0;
                              } else {
                                startIndex = static_cast<double>(wt[k - 1]) +
                                  1.0;
                              }

                              d = static_cast<double>(wt[k]) - 1.0;
                              if (startIndex > d) {
                                i1 = -1;
                                i2 = -1;
                              } else {
                                i1 = static_cast<int>(startIndex) - 2;
                                i2 = static_cast<int>(d) - 1;
                              }

                              loop_ub = i2 - i1;
                              b_nextLineVar.set_size(1, loop_ub);
                              for (i2 = 0; i2 < loop_ub; i2++) {
                                b_nextLineVar[i2] = static_cast<signed char>
                                  (con[(i1 + i2) + 1]);
                              }

                              dc = str2double(b_nextLineVar);
                              if (static_cast<double>(k) + 1.0 > numOutputs) {
                                cfclose(fid);
                                exit(0);
                              }

                              rules[b_i].consequent[k] = dc.re;
                            }
                          }
                        }

                        b_i++;
                      }
                    }
                  }
                }
              } else {
                exitg2 = 1;
              }
            } while (exitg2 == 0);
          }
        }
      }
    }
  }
}

//
// File trailer for getRules.cpp
//
// [EOF]
//
