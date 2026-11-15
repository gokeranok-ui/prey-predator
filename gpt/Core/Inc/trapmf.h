/*
 * File: trapmf.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

#ifndef TRAPMF_H
#define TRAPMF_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "opkene_types.h"

/* Function Declarations */
extern double b_trapmf(double x, const emxArray_real_T *params);
extern void trapmf(const double x_data[], const int x_size[2], const
                   emxArray_real_T *params, double y_data[], int y_size[2]);

#endif

/*
 * File trailer for trapmf.h
 *
 * [EOF]
 */
