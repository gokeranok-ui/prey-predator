//
// File: opkene.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "opkene.h"
#include "evaluateFIS.h"
#include "getFISCodeGenerationData.h"
#include "opkene_data.h"
#include "opkene_initialize.h"
#include "opkene_internal_types.h"
#include "opkene_rtwutil.h"
#include "packageAndSetDataType.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "hemen.h"
#include <cmath>
#include <stdio.h>


// Function Definitions
//
// Arguments    : const coder::array<char, 2U> &fileName
//                const coder::array<double, 2U> &x
//                coder::array<double, 2U> &y
// Return Type  : void
//
int opkene(const coder::array<char, 2U> &fileName, const coder::array<double,
            2U> &x, coder::array<double, 2U> &y)
{
  //printf("Arnold=%s\n",fileName);
  static const char cv[7] = { 'm', 'a', 'm', 'd', 'a', 'n', 'i' };
//printf("Sylvester=%c\n",fileName[2]);
  coder::array<b_struct_T, 2U> fis_input;
  coder::array<b_struct_T, 2U> fis_output;
  coder::array<c_struct_T, 2U> fis_rule;
  coder::array<h_struct_T, 2U> r2;
  coder::array<double, 2U> numInputMFs;
  coder::array<double, 2U> numOutputMFs;
  coder::array<double, 2U> r;
  coder::array<double, 2U> r1;
  coder::array<double, 1U> b_x;
  coder::array<char, 2U> expl_temp;
  coder::array<char, 2U> fis_aggMethod;
  coder::array<char, 2U> fis_andMethod;
  coder::array<char, 2U> fis_defuzzMethod;
  coder::array<char, 2U> fis_impMethod;
  coder::array<char, 2U> fis_orMethod;
  coder::array<char, 2U> fis_type;
  f_struct_T b_expl_temp;
  f_struct_T c_expl_temp;
  double b_y[51];
  double d1;
  double delta1;
  int exitg1;
  unsigned int fis_aggSize_idx_1;
  unsigned int fis_orrSize_idx_0;
  int i;
  int i1;
  int loop_ub;
  int varID;
  boolean_T b_bool;
  if (!isInitialized_opkene) {
    opkene_initialize();
  }
//printf("Shwar=%f\n");
  coder::getFISCodeGenerationData(fileName, expl_temp, fis_type, fis_andMethod,
    fis_orMethod, fis_defuzzMethod, fis_impMethod, fis_aggMethod, fis_input,
    fis_output, fis_rule);
  b_expl_temp.inputRange.set_size(fis_input.size(1), 2);
  loop_ub = fis_input.size(1) << 1;
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.inputRange[i] = 0.0;
  }
printf("generrr=%i\n",fis_output.size(1));
int sayi = fis_output.size(1);
//hemen(sayi);
  i = fis_input.size(1);
  for (varID = 0; varID < i; varID++) {
    b_expl_temp.inputRange[varID] = fis_input[varID].range[0];
    b_expl_temp.inputRange[varID + b_expl_temp.inputRange.size(0)] =
      fis_input[varID].range[1];
  }

  b_expl_temp.outputRange.set_size(fis_output.size(1), 2);
  loop_ub = fis_output.size(1) << 1;
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.outputRange[i] = 0.0;
  }

  i = fis_output.size(1);
  for (varID = 0; varID < i; varID++) {
    b_expl_temp.outputRange[varID] = fis_output[varID].range[0];
    b_expl_temp.outputRange[varID + b_expl_temp.outputRange.size(0)] =
      fis_output[varID].range[1];
  }

  numInputMFs.set_size(1, fis_input.size(1));
  i = fis_input.size(1);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    numInputMFs[loop_ub] = fis_input[loop_ub].origNumMF;
  }

  numOutputMFs.set_size(1, fis_output.size(1));
  i = fis_output.size(1);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    numOutputMFs[loop_ub] = fis_output[loop_ub].origNumMF;
  }

  b_expl_temp.antecedent.set_size(fis_rule.size(1), fis_input.size(1));
  loop_ub = fis_rule.size(1) * fis_input.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.antecedent[i] = 0.0;
  }

  i = fis_rule.size(1);
  for (varID = 0; varID < i; varID++) {
    loop_ub = fis_rule[varID].antecedent.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_expl_temp.antecedent[varID + b_expl_temp.antecedent.size(0) * i1] =
        fis_rule[varID].antecedent[i1];
    }
  }

  b_expl_temp.consequent.set_size(fis_rule.size(1), fis_output.size(1));
  loop_ub = fis_rule.size(1) * fis_output.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.consequent[i] = 0.0;
  }

  i = fis_rule.size(1);
  for (varID = 0; varID < i; varID++) {
    loop_ub = fis_rule[varID].consequent.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_expl_temp.consequent[varID + b_expl_temp.consequent.size(0) * i1] =
        fis_rule[varID].consequent[i1];
    }
  }

  b_expl_temp.connection.set_size(1, fis_rule.size(1));
  loop_ub = fis_rule.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.connection[i] = 0.0;
  }

  i = fis_rule.size(1);
  for (varID = 0; varID < i; varID++) {
    b_expl_temp.connection[varID] = fis_rule[varID].connection;
  }

  b_expl_temp.weight.set_size(1, fis_rule.size(1));
  loop_ub = fis_rule.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.weight[i] = 0.0;
  }

  i = fis_rule.size(1);
  for (varID = 0; varID < i; varID++) {
    b_expl_temp.weight[varID] = fis_rule[varID].weight;
  }

  r.set_size(1, numInputMFs.size(1));
  loop_ub = numInputMFs.size(0) * numInputMFs.size(1);
  for (i = 0; i < loop_ub; i++) {
    r[i] = numInputMFs[i];
  }

  if ((numInputMFs.size(1) != 0) && (numInputMFs.size(1) != 1)) {
    i = numInputMFs.size(1);
    for (loop_ub = 0; loop_ub <= i - 2; loop_ub++) {
      r[loop_ub + 1] = r[loop_ub] + r[loop_ub + 1];
    }
  }

  r1.set_size(1, numOutputMFs.size(1));
  loop_ub = numOutputMFs.size(0) * numOutputMFs.size(1);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = numOutputMFs[i];
  }

  if ((numOutputMFs.size(1) != 0) && (numOutputMFs.size(1) != 1)) {
    i = numOutputMFs.size(1);
    for (loop_ub = 0; loop_ub <= i - 2; loop_ub++) {
      r1[loop_ub + 1] = r1[loop_ub] + r1[loop_ub + 1];
    }
  }

  b_bool = false;
  if (fis_type.size(1) == 7) {
    varID = 0;
    do {
      exitg1 = 0;
      if (varID < 7) {
        if (fis_type[varID] != cv[varID]) {
          exitg1 = 1;
        } else {
          varID++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    b_expl_temp.outputSamplePoints.set_size(fis_output.size(1), 51);
    loop_ub = fis_output.size(1) * 51;
    for (i = 0; i < loop_ub; i++) {
      b_expl_temp.outputSamplePoints[i] = 0.0;
    }

    i = fis_output.size(1);
    for (varID = 0; varID < i; varID++) {
      d1 = fis_output[varID].range[0];
      b_y[50] = fis_output[varID].range[1];
      b_y[0] = fis_output[varID].range[0];
      if (fis_output[varID].range[0] == -fis_output[varID].range[1]) {
        for (loop_ub = 0; loop_ub < 49; loop_ub++) {
          b_y[loop_ub + 1] = fis_output[varID].range[1] * ((2.0 * (static_cast<
            double>(loop_ub) + 2.0) - 52.0) / 50.0);
        }

        b_y[25] = 0.0;
      } else if (((fis_output[varID].range[0] < 0.0) != (fis_output[varID]
                   .range[1] < 0.0)) && ((std::abs(fis_output[varID].range[0]) >
        8.9884656743115785E+307) || (std::abs(fis_output[varID].range[1]) >
                   8.9884656743115785E+307))) {
        double delta2;
        delta1 = fis_output[varID].range[0] / 50.0;
        delta2 = fis_output[varID].range[1] / 50.0;
        for (loop_ub = 0; loop_ub < 49; loop_ub++) {
          b_y[loop_ub + 1] = (d1 + delta2 * (static_cast<double>(loop_ub) + 1.0))
            - delta1 * (static_cast<double>(loop_ub) + 1.0);
        }
      } else {
        delta1 = (fis_output[varID].range[1] - fis_output[varID].range[0]) /
          50.0;
        for (loop_ub = 0; loop_ub < 49; loop_ub++) {
          b_y[loop_ub + 1] = d1 + (static_cast<double>(loop_ub) + 1.0) * delta1;
        }
      }

      for (i1 = 0; i1 < 51; i1++) {
        b_expl_temp.outputSamplePoints[varID +
          b_expl_temp.outputSamplePoints.size(0) * i1] = b_y[i1];
      }
    }
  } else {
    b_expl_temp.outputSamplePoints.set_size(1, 1);
    b_expl_temp.outputSamplePoints[0] = 0.0;
  }

  b_bool = false;
  if (fis_type.size(1) == 7) {
    varID = 0;
    do {
      exitg1 = 0;
      if (varID < 7) {
        if (fis_type[varID] != cv[varID]) {
          exitg1 = 1;
        } else {
          varID++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    fis_orrSize_idx_0 = 51U;
    d1 = static_cast<double>(fis_rule.size(1)) * static_cast<double>
      (fis_output.size(1));
    varID = 51;
    fis_aggSize_idx_1 = static_cast<unsigned int>(fis_output.size(1));
  } else {
    fis_orrSize_idx_0 = static_cast<unsigned int>(fis_rule.size(1));
    d1 = static_cast<unsigned int>(fis_output.size(1));
    varID = 1;
    fis_aggSize_idx_1 = static_cast<unsigned int>(fis_output.size(1));
  }

  b_expl_temp.type.set_size(1, fis_type.size(1));
  loop_ub = fis_type.size(0) * fis_type.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.type[i] = static_cast<unsigned char>(fis_type[i]);
  }

  b_expl_temp.andMethod.set_size(1, fis_andMethod.size(1));
  loop_ub = fis_andMethod.size(0) * fis_andMethod.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.andMethod[i] = static_cast<unsigned char>(fis_andMethod[i]);
  }

  b_expl_temp.orMethod.set_size(1, fis_orMethod.size(1));
  loop_ub = fis_orMethod.size(0) * fis_orMethod.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.orMethod[i] = static_cast<unsigned char>(fis_orMethod[i]);
  }

  b_expl_temp.defuzzMethod.set_size(1, fis_defuzzMethod.size(1));
  loop_ub = fis_defuzzMethod.size(0) * fis_defuzzMethod.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.defuzzMethod[i] = static_cast<unsigned char>(fis_defuzzMethod[i]);
  }

  b_expl_temp.impMethod.set_size(1, fis_impMethod.size(1));
  loop_ub = fis_impMethod.size(0) * fis_impMethod.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.impMethod[i] = static_cast<unsigned char>(fis_impMethod[i]);
  }

  b_expl_temp.aggMethod.set_size(1, fis_aggMethod.size(1));
  loop_ub = fis_aggMethod.size(0) * fis_aggMethod.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.aggMethod[i] = static_cast<unsigned char>(fis_aggMethod[i]);
  }

  coder::fuzzy::internal::codegen::makeHomogenousMF(fis_input, r2);
  coder::fuzzy::internal::codegen::setMFDataType(r2, b_expl_temp.inputMF);
  coder::fuzzy::internal::codegen::makeHomogenousMF(fis_output, r2);
  coder::fuzzy::internal::codegen::setMFDataType(r2, b_expl_temp.outputMF);
  b_expl_temp.numInputMFs.set_size(1, numInputMFs.size(1));
  loop_ub = numInputMFs.size(0) * numInputMFs.size(1);
  for (i = 0; i < loop_ub; i++) {
    delta1 = rt_roundd_snf(numInputMFs[i]);
    if (delta1 < 2.147483648E+9) {
      if (delta1 >= -2.147483648E+9) {
        i1 = static_cast<int>(delta1);
      } else {
        i1 = MIN_int32_T;
      }
    } else if (delta1 >= 2.147483648E+9) {
      i1 = MAX_int32_T;
    } else {
      i1 = 0;
    }

    b_expl_temp.numInputMFs[i] = i1;
  }

  b_expl_temp.numCumInputMFs.set_size(1, r.size(1));
  loop_ub = r.size(0) * r.size(1);
  for (i = 0; i < loop_ub; i++) {
    delta1 = rt_roundd_snf(r[i] - numInputMFs[i]);
    if (delta1 < 2.147483648E+9) {
      if (delta1 >= -2.147483648E+9) {
        i1 = static_cast<int>(delta1);
      } else {
        i1 = MIN_int32_T;
      }
    } else if (delta1 >= 2.147483648E+9) {
      i1 = MAX_int32_T;
    } else {
      i1 = 0;
    }

    b_expl_temp.numCumInputMFs[i] = i1;
  }

  b_expl_temp.numOutputMFs.set_size(1, numOutputMFs.size(1));
  loop_ub = numOutputMFs.size(0) * numOutputMFs.size(1);
  for (i = 0; i < loop_ub; i++) {
    delta1 = rt_roundd_snf(numOutputMFs[i]);
    if (delta1 < 2.147483648E+9) {
      if (delta1 >= -2.147483648E+9) {
        i1 = static_cast<int>(delta1);
      } else {
        i1 = MIN_int32_T;
      }
    } else if (delta1 >= 2.147483648E+9) {
      i1 = MAX_int32_T;
    } else {
      i1 = 0;
    }

    b_expl_temp.numOutputMFs[i] = i1;
  }

  b_expl_temp.numCumOutputMFs.set_size(1, r1.size(1));
  loop_ub = r1.size(0) * r1.size(1);
  for (i = 0; i < loop_ub; i++) {
    delta1 = rt_roundd_snf(r1[i] - numOutputMFs[i]);
    if (delta1 < 2.147483648E+9) {
      if (delta1 >= -2.147483648E+9) {
        i1 = static_cast<int>(delta1);
      } else {
        i1 = MIN_int32_T;
      }
    } else if (delta1 >= 2.147483648E+9) {
      i1 = MAX_int32_T;
    } else {
      i1 = 0;
    }

    b_expl_temp.numCumOutputMFs[i] = i1;
  }

  b_expl_temp.irrSize[0] = fis_rule.size(1);
  b_expl_temp.irrSize[1] = fis_input.size(1);
  b_expl_temp.rfsSize[0] = fis_rule.size(1);
  b_expl_temp.rfsSize[1] = 1;
  if (fis_orrSize_idx_0 < 2147483648U) {
    i = static_cast<int>(fis_orrSize_idx_0);
  } else {
    i = MAX_int32_T;
  }

  b_expl_temp.orrSize[0] = i;
  b_expl_temp.aggSize[0] = varID;
  if (d1 < 2.147483648E+9) {
    if (d1 >= -2.147483648E+9) {
      i1 = static_cast<int>(d1);
    } else {
      i1 = MIN_int32_T;
    }
  } else {
    i1 = MAX_int32_T;
  }

  b_expl_temp.orrSize[1] = i1;
  b_expl_temp.aggSize[1] = static_cast<int>(fis_aggSize_idx_1);
  if (x.size(1) == 1) {
    numInputMFs.set_size(1, fis_input.size(1));
    loop_ub = fis_input.size(1);
    for (i = 0; i < loop_ub; i++) {
      numInputMFs[i] = x[0];
    }

    b_expl_temp.inputFuzzySetType = 1;
    b_expl_temp.sumSize[0] = 1;
    b_expl_temp.sumSize[1] = 1;
    b_expl_temp.numRules = fis_rule.size(1);
    b_expl_temp.numOutputs = fis_output.size(1);
    b_expl_temp.numInputs = fis_input.size(1);
    b_expl_temp.numSamples = 51;
    coder::fuzzy::internal::codegen::evaluateFIS(numInputMFs, &b_expl_temp, r);
    y.set_size(1, r.size(1));
    loop_ub = r.size(0) * r.size(1);
    for (i = 0; i < loop_ub; i++) {
      y[i] = r[i];
    }
  } else if ((1 == fis_input.size(1)) && (x.size(1) != 1)) {
    c_expl_temp.inputFuzzySetType = 1;
    c_expl_temp.sumSize[0] = 1;
    c_expl_temp.rfsSize[0] = fis_rule.size(1);
    c_expl_temp.irrSize[0] = fis_rule.size(1);
    c_expl_temp.aggSize[0] = varID;
    c_expl_temp.orrSize[0] = i;
    c_expl_temp.sumSize[1] = 1;
    c_expl_temp.rfsSize[1] = 1;
    c_expl_temp.irrSize[1] = fis_input.size(1);
    c_expl_temp.aggSize[1] = static_cast<int>(fis_aggSize_idx_1);
    c_expl_temp.orrSize[1] = i1;
    c_expl_temp.outputSamplePoints.set_size(b_expl_temp.outputSamplePoints.size
      (0), b_expl_temp.outputSamplePoints.size(1));
    loop_ub = b_expl_temp.outputSamplePoints.size(0) *
      b_expl_temp.outputSamplePoints.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.outputSamplePoints[i] = b_expl_temp.outputSamplePoints[i];
    }

    c_expl_temp.numCumOutputMFs.set_size(1, b_expl_temp.numCumOutputMFs.size(1));
    loop_ub = b_expl_temp.numCumOutputMFs.size(0) *
      b_expl_temp.numCumOutputMFs.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.numCumOutputMFs[i] = b_expl_temp.numCumOutputMFs[i];
    }

    c_expl_temp.numOutputMFs.set_size(1, b_expl_temp.numOutputMFs.size(1));
    loop_ub = b_expl_temp.numOutputMFs.size(0) * b_expl_temp.numOutputMFs.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.numOutputMFs[i] = b_expl_temp.numOutputMFs[i];
    }

    c_expl_temp.numCumInputMFs.set_size(1, b_expl_temp.numCumInputMFs.size(1));
    loop_ub = b_expl_temp.numCumInputMFs.size(0) *
      b_expl_temp.numCumInputMFs.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.numCumInputMFs[i] = b_expl_temp.numCumInputMFs[i];
    }

    c_expl_temp.numInputMFs.set_size(1, b_expl_temp.numInputMFs.size(1));
    loop_ub = b_expl_temp.numInputMFs.size(0) * b_expl_temp.numInputMFs.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.numInputMFs[i] = b_expl_temp.numInputMFs[i];
    }

    c_expl_temp.numRules = fis_rule.size(1);
    c_expl_temp.numOutputs = fis_output.size(1);
    c_expl_temp.numInputs = fis_input.size(1);
    c_expl_temp.numSamples = 51;
    c_expl_temp.weight.set_size(1, b_expl_temp.weight.size(1));
    loop_ub = b_expl_temp.weight.size(0) * b_expl_temp.weight.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.weight[i] = b_expl_temp.weight[i];
    }

    c_expl_temp.connection.set_size(1, b_expl_temp.connection.size(1));
    loop_ub = b_expl_temp.connection.size(0) * b_expl_temp.connection.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.connection[i] = b_expl_temp.connection[i];
    }

    c_expl_temp.consequent.set_size(b_expl_temp.consequent.size(0),
      b_expl_temp.consequent.size(1));
    loop_ub = b_expl_temp.consequent.size(0) * b_expl_temp.consequent.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.consequent[i] = b_expl_temp.consequent[i];
    }

    c_expl_temp.antecedent.set_size(b_expl_temp.antecedent.size(0),
      b_expl_temp.antecedent.size(1));
    loop_ub = b_expl_temp.antecedent.size(0) * b_expl_temp.antecedent.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.antecedent[i] = b_expl_temp.antecedent[i];
    }

    c_expl_temp.outputMF.set_size(1, b_expl_temp.outputMF.size(1));
    loop_ub = b_expl_temp.outputMF.size(0) * b_expl_temp.outputMF.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.outputMF[i] = b_expl_temp.outputMF[i];
    }

    c_expl_temp.inputMF.set_size(1, b_expl_temp.inputMF.size(1));
    loop_ub = b_expl_temp.inputMF.size(0) * b_expl_temp.inputMF.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.inputMF[i] = b_expl_temp.inputMF[i];
    }

    c_expl_temp.outputRange.set_size(b_expl_temp.outputRange.size(0), 2);
    loop_ub = b_expl_temp.outputRange.size(0) * b_expl_temp.outputRange.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.outputRange[i] = b_expl_temp.outputRange[i];
    }

    c_expl_temp.inputRange.set_size(b_expl_temp.inputRange.size(0), 2);
    loop_ub = b_expl_temp.inputRange.size(0) * b_expl_temp.inputRange.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.inputRange[i] = b_expl_temp.inputRange[i];
    }

    c_expl_temp.aggMethod.set_size(1, b_expl_temp.aggMethod.size(1));
    loop_ub = b_expl_temp.aggMethod.size(0) * b_expl_temp.aggMethod.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.aggMethod[i] = b_expl_temp.aggMethod[i];
    }

    c_expl_temp.impMethod.set_size(1, b_expl_temp.impMethod.size(1));
    loop_ub = b_expl_temp.impMethod.size(0) * b_expl_temp.impMethod.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.impMethod[i] = b_expl_temp.impMethod[i];
    }

    c_expl_temp.defuzzMethod.set_size(1, b_expl_temp.defuzzMethod.size(1));
    loop_ub = b_expl_temp.defuzzMethod.size(0) * b_expl_temp.defuzzMethod.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.defuzzMethod[i] = b_expl_temp.defuzzMethod[i];
    }

    c_expl_temp.orMethod.set_size(1, b_expl_temp.orMethod.size(1));
    loop_ub = b_expl_temp.orMethod.size(0) * b_expl_temp.orMethod.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.orMethod[i] = b_expl_temp.orMethod[i];
    }

    c_expl_temp.andMethod.set_size(1, b_expl_temp.andMethod.size(1));
    loop_ub = b_expl_temp.andMethod.size(0) * b_expl_temp.andMethod.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.andMethod[i] = b_expl_temp.andMethod[i];
    }

    c_expl_temp.type.set_size(1, b_expl_temp.type.size(1));
    loop_ub = b_expl_temp.type.size(0) * b_expl_temp.type.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.type[i] = b_expl_temp.type[i];
    }

    b_x.set_size(x.size(1));
    loop_ub = x.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_x[i] = x[i];
    }

    coder::fuzzy::internal::codegen::evaluateFIS(b_x, &c_expl_temp, y);
  } else {
    c_expl_temp.inputFuzzySetType = 1;
    c_expl_temp.sumSize[0] = 1;
    c_expl_temp.rfsSize[0] = fis_rule.size(1);
    c_expl_temp.irrSize[0] = fis_rule.size(1);
    c_expl_temp.aggSize[0] = varID;
    c_expl_temp.orrSize[0] = i;
    c_expl_temp.sumSize[1] = 1;
    c_expl_temp.rfsSize[1] = 1;
    c_expl_temp.irrSize[1] = fis_input.size(1);
    c_expl_temp.aggSize[1] = static_cast<int>(fis_aggSize_idx_1);
    c_expl_temp.orrSize[1] = i1;
    c_expl_temp.outputSamplePoints.set_size(b_expl_temp.outputSamplePoints.size
      (0), b_expl_temp.outputSamplePoints.size(1));
    loop_ub = b_expl_temp.outputSamplePoints.size(0) *
      b_expl_temp.outputSamplePoints.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.outputSamplePoints[i] = b_expl_temp.outputSamplePoints[i];
    }

    c_expl_temp.numCumOutputMFs.set_size(1, b_expl_temp.numCumOutputMFs.size(1));
    loop_ub = b_expl_temp.numCumOutputMFs.size(0) *
      b_expl_temp.numCumOutputMFs.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.numCumOutputMFs[i] = b_expl_temp.numCumOutputMFs[i];
    }

    c_expl_temp.numOutputMFs.set_size(1, b_expl_temp.numOutputMFs.size(1));
    loop_ub = b_expl_temp.numOutputMFs.size(0) * b_expl_temp.numOutputMFs.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.numOutputMFs[i] = b_expl_temp.numOutputMFs[i];
    }

    c_expl_temp.numCumInputMFs.set_size(1, b_expl_temp.numCumInputMFs.size(1));
    loop_ub = b_expl_temp.numCumInputMFs.size(0) *
      b_expl_temp.numCumInputMFs.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.numCumInputMFs[i] = b_expl_temp.numCumInputMFs[i];
    }

    c_expl_temp.numInputMFs.set_size(1, b_expl_temp.numInputMFs.size(1));
    loop_ub = b_expl_temp.numInputMFs.size(0) * b_expl_temp.numInputMFs.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.numInputMFs[i] = b_expl_temp.numInputMFs[i];
    }

    c_expl_temp.numRules = fis_rule.size(1);
    c_expl_temp.numOutputs = fis_output.size(1);
    c_expl_temp.numInputs = fis_input.size(1);
    c_expl_temp.numSamples = 51;
    c_expl_temp.weight.set_size(1, b_expl_temp.weight.size(1));
    loop_ub = b_expl_temp.weight.size(0) * b_expl_temp.weight.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.weight[i] = b_expl_temp.weight[i];
    }

    c_expl_temp.connection.set_size(1, b_expl_temp.connection.size(1));
    loop_ub = b_expl_temp.connection.size(0) * b_expl_temp.connection.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.connection[i] = b_expl_temp.connection[i];
    }

    c_expl_temp.consequent.set_size(b_expl_temp.consequent.size(0),
      b_expl_temp.consequent.size(1));
    loop_ub = b_expl_temp.consequent.size(0) * b_expl_temp.consequent.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.consequent[i] = b_expl_temp.consequent[i];
    }

    c_expl_temp.antecedent.set_size(b_expl_temp.antecedent.size(0),
      b_expl_temp.antecedent.size(1));
    loop_ub = b_expl_temp.antecedent.size(0) * b_expl_temp.antecedent.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.antecedent[i] = b_expl_temp.antecedent[i];
    }

    c_expl_temp.outputMF.set_size(1, b_expl_temp.outputMF.size(1));
    loop_ub = b_expl_temp.outputMF.size(0) * b_expl_temp.outputMF.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.outputMF[i] = b_expl_temp.outputMF[i];
    }

    c_expl_temp.inputMF.set_size(1, b_expl_temp.inputMF.size(1));
    loop_ub = b_expl_temp.inputMF.size(0) * b_expl_temp.inputMF.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.inputMF[i] = b_expl_temp.inputMF[i];
    }

    c_expl_temp.outputRange.set_size(b_expl_temp.outputRange.size(0), 2);
    loop_ub = b_expl_temp.outputRange.size(0) * b_expl_temp.outputRange.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.outputRange[i] = b_expl_temp.outputRange[i];
    }

    c_expl_temp.inputRange.set_size(b_expl_temp.inputRange.size(0), 2);
    loop_ub = b_expl_temp.inputRange.size(0) * b_expl_temp.inputRange.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.inputRange[i] = b_expl_temp.inputRange[i];
    }

    c_expl_temp.aggMethod.set_size(1, b_expl_temp.aggMethod.size(1));
    loop_ub = b_expl_temp.aggMethod.size(0) * b_expl_temp.aggMethod.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.aggMethod[i] = b_expl_temp.aggMethod[i];
    }

    c_expl_temp.impMethod.set_size(1, b_expl_temp.impMethod.size(1));
    loop_ub = b_expl_temp.impMethod.size(0) * b_expl_temp.impMethod.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.impMethod[i] = b_expl_temp.impMethod[i];
    }

    c_expl_temp.defuzzMethod.set_size(1, b_expl_temp.defuzzMethod.size(1));
    loop_ub = b_expl_temp.defuzzMethod.size(0) * b_expl_temp.defuzzMethod.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.defuzzMethod[i] = b_expl_temp.defuzzMethod[i];
    }

    c_expl_temp.orMethod.set_size(1, b_expl_temp.orMethod.size(1));
    loop_ub = b_expl_temp.orMethod.size(0) * b_expl_temp.orMethod.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.orMethod[i] = b_expl_temp.orMethod[i];
    }

    c_expl_temp.andMethod.set_size(1, b_expl_temp.andMethod.size(1));
    loop_ub = b_expl_temp.andMethod.size(0) * b_expl_temp.andMethod.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.andMethod[i] = b_expl_temp.andMethod[i];
    }

    c_expl_temp.type.set_size(1, b_expl_temp.type.size(1));
    loop_ub = b_expl_temp.type.size(0) * b_expl_temp.type.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_expl_temp.type[i] = b_expl_temp.type[i];
    }

    coder::fuzzy::internal::codegen::evaluateFIS(x, &c_expl_temp, r);
    y.set_size(1, r.size(1));
    loop_ub = r.size(0) * r.size(1);
    for (i = 0; i < loop_ub; i++) {
      y[i] = r[i];
    }
  }
return sayi;
}

//
// File trailer for opkene.cpp
//
// [EOF]
//
