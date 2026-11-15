/*
 * File: opkene_types.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

#ifndef OPKENE_TYPES_H
#define OPKENE_TYPES_H

#if defined(__GNUC__) && defined(__AVR__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverflow"
#endif

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T
struct emxArray_char_T {
  char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_char_T */
#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T
typedef struct emxArray_char_T emxArray_char_T;
#endif /* typedef_emxArray_char_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

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
#endif /* typedef_struct_T */

#ifndef typedef_emxArray_struct_T
#define typedef_emxArray_struct_T
typedef struct {
  struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_struct_T;
#endif /* typedef_emxArray_struct_T */

#ifndef typedef_b_struct_T
#define typedef_b_struct_T
typedef struct {
  emxArray_char_T *name;
  double origNameLength;
  double range[2];
  emxArray_struct_T *mf;
  double origNumMF;
} b_struct_T;
#endif /* typedef_b_struct_T */

#ifndef typedef_b_emxArray_struct_T
#define typedef_b_emxArray_struct_T
typedef struct {
  b_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} b_emxArray_struct_T;
#endif /* typedef_b_emxArray_struct_T */

#ifndef typedef_c_struct_T
#define typedef_c_struct_T
typedef struct {
  emxArray_real_T *antecedent;
  emxArray_real_T *consequent;
  double weight;
  double connection;
} c_struct_T;
#endif /* typedef_c_struct_T */

#ifndef typedef_c_emxArray_struct_T
#define typedef_c_emxArray_struct_T
typedef struct {
  c_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} c_emxArray_struct_T;
#endif /* typedef_c_emxArray_struct_T */

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T
struct emxArray_uint8_T {
  unsigned char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_uint8_T */
#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T
typedef struct emxArray_uint8_T emxArray_uint8_T;
#endif /* typedef_emxArray_uint8_T */

#ifndef typedef_d_struct_T
#define typedef_d_struct_T
typedef struct {
  emxArray_char_T *type;
  int origTypeLength;
  emxArray_real_T *params;
  int origParamLength;
} d_struct_T;
#endif /* typedef_d_struct_T */

#ifndef typedef_d_emxArray_struct_T
#define typedef_d_emxArray_struct_T
typedef struct {
  d_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} d_emxArray_struct_T;
#endif /* typedef_d_emxArray_struct_T */

#ifndef typedef_e_struct_T
#define typedef_e_struct_T
typedef struct {
  d_emxArray_struct_T *mf;
  int origNumMF;
} e_struct_T;
#endif /* typedef_e_struct_T */

#ifndef typedef_e_emxArray_struct_T
#define typedef_e_emxArray_struct_T
typedef struct {
  e_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} e_emxArray_struct_T;
#endif /* typedef_e_emxArray_struct_T */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int32_T */
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /* typedef_emxArray_int32_T */

#ifndef typedef_f_struct_T
#define typedef_f_struct_T
typedef struct {
  emxArray_char_T *type;
  double origTypeLength;
  emxArray_real_T *params;
  double origParamLength;
} f_struct_T;
#endif /* typedef_f_struct_T */

#ifndef typedef_f_emxArray_struct_T
#define typedef_f_emxArray_struct_T
typedef struct {
  f_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} f_emxArray_struct_T;
#endif /* typedef_f_emxArray_struct_T */

#ifndef typedef_g_struct_T
#define typedef_g_struct_T
typedef struct {
  f_emxArray_struct_T *mf;
  double origNumMF;
} g_struct_T;
#endif /* typedef_g_struct_T */

#ifndef typedef_g_emxArray_struct_T
#define typedef_g_emxArray_struct_T
typedef struct {
  g_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} g_emxArray_struct_T;
#endif /* typedef_g_emxArray_struct_T */

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
struct emxArray_boolean_T {
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_boolean_T */
#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T
typedef struct emxArray_boolean_T emxArray_boolean_T;
#endif /* typedef_emxArray_boolean_T */

#ifndef typedef_h_struct_T
#define typedef_h_struct_T
typedef struct {
  emxArray_char_T *type;
  emxArray_real_T *params;
} h_struct_T;
#endif /* typedef_h_struct_T */

#ifndef typedef_h_emxArray_struct_T
#define typedef_h_emxArray_struct_T
typedef struct {
  h_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} h_emxArray_struct_T;
#endif /* typedef_h_emxArray_struct_T */

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0
typedef struct {
  h_emxArray_struct_T *f1;
} cell_wrap_0;
#endif /* typedef_cell_wrap_0 */

#ifndef typedef_emxArray_cell_wrap_0
#define typedef_emxArray_cell_wrap_0
typedef struct {
  cell_wrap_0 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_0;
#endif /* typedef_emxArray_cell_wrap_0 */

#ifndef typedef_i_struct_T
#define typedef_i_struct_T
typedef struct {
  emxArray_uint8_T *type;
  emxArray_uint8_T *andMethod;
  emxArray_uint8_T *orMethod;
  emxArray_uint8_T *defuzzMethod;
  emxArray_uint8_T *impMethod;
  emxArray_uint8_T *aggMethod;
  emxArray_real_T *inputRange;
  emxArray_real_T *outputRange;
  e_emxArray_struct_T *inputMF;
  e_emxArray_struct_T *outputMF;
  emxArray_real_T *antecedent;
  emxArray_real_T *consequent;
  emxArray_real_T *connection;
  emxArray_real_T *weight;
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
} i_struct_T;
#endif /* typedef_i_struct_T */

#if defined(__GNUC__) && defined(__AVR__)
#pragma GCC diagnostic pop
#endif

#endif
/*
 * File trailer for opkene_types.h
 *
 * [EOF]
 */