/*
 * File: opkene_types.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

#ifndef OPKENE_TYPES_H
#define OPKENE_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#include <stdio.h>
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_b_struct_T
#define typedef_b_struct_T

typedef struct {
  emxArray_real_T *antecedent;
  emxArray_real_T *consequent;
  double weight;
  double connection;
} b_struct_T;

#endif                                 /*typedef_b_struct_T*/

#ifndef typedef_b_emxArray_struct_T
#define typedef_b_emxArray_struct_T

typedef struct {
  b_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} b_emxArray_struct_T;

#endif                                 /*typedef_b_emxArray_struct_T*/

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_char_T*/

#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T

typedef struct emxArray_char_T emxArray_char_T;

#endif                                 /*typedef_emxArray_char_T*/

#ifndef typedef_c_struct_T
#define typedef_c_struct_T

typedef struct {
  emxArray_char_T *type;
  int origTypeLength;
  emxArray_real_T *params;
  int origParamLength;
} c_struct_T;

#endif                                 /*typedef_c_struct_T*/

#ifndef typedef_c_emxArray_struct_T
#define typedef_c_emxArray_struct_T

typedef struct {
  c_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} c_emxArray_struct_T;

#endif                                 /*typedef_c_emxArray_struct_T*/

#ifndef typedef_g_struct_T
#define typedef_g_struct_T

typedef struct {
  emxArray_char_T *type;
  emxArray_real_T *params;
} g_struct_T;

#endif                                 /*typedef_g_struct_T*/

#ifndef typedef_g_emxArray_struct_T
#define typedef_g_emxArray_struct_T

typedef struct {
  g_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} g_emxArray_struct_T;

#endif                                 /*typedef_g_emxArray_struct_T*/

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0

typedef struct {
  g_emxArray_struct_T *f1;
} cell_wrap_0;

#endif                                 /*typedef_cell_wrap_0*/

#ifndef typedef_d_struct_T
#define typedef_d_struct_T

typedef struct {
  c_emxArray_struct_T *mf;
  int origNumMF;
} d_struct_T;

#endif                                 /*typedef_d_struct_T*/

#ifndef typedef_d_emxArray_struct_T
#define typedef_d_emxArray_struct_T

typedef struct {
  d_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} d_emxArray_struct_T;

#endif                                 /*typedef_d_emxArray_struct_T*/

#ifndef typedef_e_struct_T
#define typedef_e_struct_T

typedef struct {
  emxArray_char_T *type;
  double origTypeLength;
  emxArray_real_T *params;
  double origParamLength;
} e_struct_T;

#endif                                 /*typedef_e_struct_T*/

#ifndef typedef_e_emxArray_struct_T
#define typedef_e_emxArray_struct_T

typedef struct {
  e_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} e_emxArray_struct_T;

#endif                                 /*typedef_e_emxArray_struct_T*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/

#ifndef typedef_emxArray_cell_wrap_0
#define typedef_emxArray_cell_wrap_0

typedef struct {
  cell_wrap_0 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_0;

#endif                                 /*typedef_emxArray_cell_wrap_0*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_int8_T
#define struct_emxArray_int8_T

struct emxArray_int8_T
{
  signed char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int8_T*/

#ifndef typedef_emxArray_int8_T
#define typedef_emxArray_int8_T

typedef struct emxArray_int8_T emxArray_int8_T;

#endif                                 /*typedef_emxArray_int8_T*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  emxArray_char_T *name;
  double origNameLength;
  emxArray_char_T *type;
  double origTypeLength;
  emxArray_real_T *params;
  double origParamLength;
} struct_T;

#endif                                 /*typedef_struct_T*/

#ifndef typedef_emxArray_struct_T
#define typedef_emxArray_struct_T

typedef struct {
  struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_struct_T;

#endif                                 /*typedef_emxArray_struct_T*/

#ifndef struct_emxArray_uint32_T
#define struct_emxArray_uint32_T

struct emxArray_uint32_T
{
  unsigned int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint32_T*/

#ifndef typedef_emxArray_uint32_T
#define typedef_emxArray_uint32_T

typedef struct emxArray_uint32_T emxArray_uint32_T;

#endif                                 /*typedef_emxArray_uint32_T*/

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T

struct emxArray_uint8_T
{
  unsigned char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint8_T*/

#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T

typedef struct emxArray_uint8_T emxArray_uint8_T;

#endif                                 /*typedef_emxArray_uint8_T*/

#ifndef typedef_f_struct_T
#define typedef_f_struct_T

typedef struct {
  e_emxArray_struct_T *mf;
  double origNumMF;
} f_struct_T;

#endif                                 /*typedef_f_struct_T*/

#ifndef typedef_f_emxArray_struct_T
#define typedef_f_emxArray_struct_T

typedef struct {
  f_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} f_emxArray_struct_T;

#endif                                 /*typedef_f_emxArray_struct_T*/

#ifndef typedef_h_struct_T
#define typedef_h_struct_T

typedef struct {
  emxArray_char_T *name;
  double origNameLength;
  double range[2];
  emxArray_struct_T *mf;
  double origNumMF;
} h_struct_T;

#endif                                 /*typedef_h_struct_T*/

#ifndef typedef_h_emxArray_struct_T
#define typedef_h_emxArray_struct_T

typedef struct {
  h_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} h_emxArray_struct_T;

#endif                                 /*typedef_h_emxArray_struct_T*/

#ifndef struct_s9XVIEp5tjzPrYZRPJjLK5C_tag
#define struct_s9XVIEp5tjzPrYZRPJjLK5C_tag

struct s9XVIEp5tjzPrYZRPJjLK5C_tag
{
  emxArray_uint8_T *type;
  emxArray_uint8_T *andMethod;
  emxArray_uint8_T *orMethod;
  emxArray_uint8_T *defuzzMethod;
  emxArray_uint8_T *impMethod;
  emxArray_uint8_T *aggMethod;
  emxArray_real_T *inputRange;
  emxArray_real_T *outputRange;
  d_emxArray_struct_T *inputMF;
  d_emxArray_struct_T *outputMF;
  emxArray_real_T *antecedent;
  emxArray_real_T *consequent;
  emxArray_real_T *connection;
  emxArray_real_T *weight;
  int numSamples;
  int numInputs;
  int numOutputs;
  int numRules;
  emxArray_int32_T *numInputMFs;
  emxArray_int32_T *numCumInputMFs;
  emxArray_int32_T *numOutputMFs;
  emxArray_int32_T *numCumOutputMFs;
  emxArray_real_T *outputSamplePoints;
  int orrSize[2];
  int aggSize[2];
};

#endif                                 /*struct_s9XVIEp5tjzPrYZRPJjLK5C_tag*/

#ifndef typedef_i_struct_T
#define typedef_i_struct_T

typedef struct s9XVIEp5tjzPrYZRPJjLK5C_tag i_struct_T;

#endif                                 /*typedef_i_struct_T*/

#ifndef struct_sDnhv42Yb3NV2QEIN2inu6G_tag
#define struct_sDnhv42Yb3NV2QEIN2inu6G_tag

struct sDnhv42Yb3NV2QEIN2inu6G_tag
{
  emxArray_char_T *type;
  emxArray_char_T *andMethod;
  emxArray_char_T *orMethod;
  emxArray_char_T *defuzzMethod;
  emxArray_char_T *impMethod;
  emxArray_char_T *aggMethod;
  f_emxArray_struct_T *inputMF;
  f_emxArray_struct_T *outputMF;
  emxArray_real_T *inputRange;
  emxArray_real_T *outputRange;
  emxArray_real_T *antecedent;
  emxArray_real_T *consequent;
  emxArray_real_T *connection;
  emxArray_real_T *weight;
  double numSamples;
  double numInputs;
  double numOutputs;
  double numRules;
  emxArray_real_T *numInputMFs;
  emxArray_real_T *numCumInputMFs;
  emxArray_real_T *numOutputMFs;
  emxArray_real_T *numCumOutputMFs;
  emxArray_real_T *outputSamplePoints;
  double orrSize[2];
  double aggSize[2];
};

#endif                                 /*struct_sDnhv42Yb3NV2QEIN2inu6G_tag*/

#ifndef typedef_j_struct_T
#define typedef_j_struct_T

typedef struct sDnhv42Yb3NV2QEIN2inu6G_tag j_struct_T;

#endif                                 /*typedef_j_struct_T*/
#endif

/*
 * File trailer for opkene_types.h
 *
 * [EOF]
 */
