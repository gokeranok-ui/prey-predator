//
// File: opkene_internal_types.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//
#ifndef OPKENE_INTERNAL_TYPES_H
#define OPKENE_INTERNAL_TYPES_H

// Include Files
#include "opkene_types.h"
#include "rtwtypes.h"
#include "coder_array.h"

// Type Definitions
struct struct_T
{
  coder::array<char, 2U> name;
  double origNameLength;
  coder::array<char, 2U> type;
  double origTypeLength;
  coder::array<double, 2U> params;
  double origParamLength;
};

struct b_struct_T
{
  coder::array<char, 2U> name;
  double origNameLength;
  double range[2];
  coder::array<struct_T, 2U> mf;
  double origNumMF;
};

struct c_struct_T
{
  coder::array<double, 2U> antecedent;
  coder::array<double, 2U> consequent;
  double weight;
  double connection;
};

struct d_struct_T
{
  coder::array<char, 2U> type;
  int origTypeLength;
  coder::array<double, 2U> params;
  int origParamLength;
};

struct e_struct_T
{
  coder::array<d_struct_T, 2U> mf;
  int origNumMF;
};

struct f_struct_T
{
  coder::array<unsigned char, 2U> type;
  coder::array<unsigned char, 2U> andMethod;
  coder::array<unsigned char, 2U> orMethod;
  coder::array<unsigned char, 2U> defuzzMethod;
  coder::array<unsigned char, 2U> impMethod;
  coder::array<unsigned char, 2U> aggMethod;
  coder::array<double, 2U> inputRange;
  coder::array<double, 2U> outputRange;
  coder::array<e_struct_T, 2U> inputMF;
  coder::array<e_struct_T, 2U> outputMF;
  coder::array<double, 2U> antecedent;
  coder::array<double, 2U> consequent;
  coder::array<double, 2U> connection;
  coder::array<double, 2U> weight;
  int numSamples;
  int numInputs;
  int numOutputs;
  int numRules;
  coder::array<int, 2U> numInputMFs;
  coder::array<int, 2U> numCumInputMFs;
  coder::array<int, 2U> numOutputMFs;
  coder::array<int, 2U> numCumOutputMFs;
  coder::array<double, 2U> outputSamplePoints;
  int orrSize[2];
  int aggSize[2];
  int irrSize[2];
  int rfsSize[2];
  int sumSize[2];
  int inputFuzzySetType;
};

struct g_struct_T
{
  coder::array<char, 2U> type;
  double origTypeLength;
  coder::array<double, 2U> params;
  double origParamLength;
};

struct h_struct_T
{
  coder::array<g_struct_T, 2U> mf;
  double origNumMF;
};

struct i_struct_T
{
  coder::array<char, 2U> type;
  coder::array<double, 2U> params;
};

struct cell_wrap_0
{
  coder::array<i_struct_T, 2U> f1;
};

#endif

//
// File trailer for opkene_internal_types.h
//
// [EOF]
//
