//
// File: applyMamdaniDefuzzificationMethod.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Feb-2021 19:55:21
//

// Include Files
#include "applyMamdaniDefuzzificationMethod.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &outputSamplePoints
//                double sumAntecedentOutputs
//                const ::coder::array<double, 2U> &aggregatedOutputs
//                const ::coder::array<double, 2U> &fis_outputRange
//                int fis_numOutputs
//                ::coder::array<double, 1U> &defuzzifiedOutputs
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
        void applyMamdaniDefuzzificationMethod(const ::coder::array<double, 2U>
          &outputSamplePoints, double sumAntecedentOutputs, const ::coder::array<
          double, 2U> &aggregatedOutputs, const ::coder::array<double, 2U>
          &fis_outputRange, int fis_numOutputs, ::coder::array<double, 1U>
          &defuzzifiedOutputs)
        {
          double area;
          double y;
          defuzzifiedOutputs.set_size(fis_numOutputs);
          for (int outputID = 0; outputID < fis_numOutputs; outputID++) {
            if (sumAntecedentOutputs == 0.0) {
              defuzzifiedOutputs[outputID] = (fis_outputRange[outputID] +
                fis_outputRange[outputID + fis_outputRange.size(0)]) / 2.0;
            } else {
              int b_i;
              int i;
              y = 0.0;
              area = 0.0;
              i = outputSamplePoints.size(1) - 1;
              for (b_i = 0; b_i <= i; b_i++) {
                area += aggregatedOutputs[b_i + aggregatedOutputs.size(0) *
                  outputID];
              }

              if (area == 0.0) {
                defuzzifiedOutputs[outputID] = (outputSamplePoints[outputID] +
                  outputSamplePoints[outputID + outputSamplePoints.size(0) *
                  (outputSamplePoints.size(1) - 1)]) / 2.0;
              } else {
                for (b_i = 0; b_i <= i; b_i++) {
                  y += outputSamplePoints[outputID + outputSamplePoints.size(0) *
                    b_i] * aggregatedOutputs[b_i + aggregatedOutputs.size(0) *
                    outputID];
                }

                defuzzifiedOutputs[outputID] = y * (1.0 / area);
              }
            }
          }
        }

        //
        // Arguments    : const ::coder::array<double, 2U> &outputSamplePoints
        //                double sumAntecedentOutputs
        //                const ::coder::array<double, 2U> &aggregatedOutputs
        //                const ::coder::array<double, 2U> &fis_outputRange
        //                int fis_numOutputs
        //                ::coder::array<double, 1U> &defuzzifiedOutputs
        // Return Type  : void
        //
        void b_applyMamdaniDefuzzificationMethod(const ::coder::array<double, 2U>
          &outputSamplePoints, double sumAntecedentOutputs, const ::coder::array<
          double, 2U> &aggregatedOutputs, const ::coder::array<double, 2U>
          &fis_outputRange, int fis_numOutputs, ::coder::array<double, 1U>
          &defuzzifiedOutputs)
        {
          double area;
          defuzzifiedOutputs.set_size(fis_numOutputs);
          for (int outputID = 0; outputID < fis_numOutputs; outputID++) {
            if (sumAntecedentOutputs == 0.0) {
              defuzzifiedOutputs[outputID] = (fis_outputRange[outputID] +
                fis_outputRange[outputID + fis_outputRange.size(0)]) / 2.0;
            } else {
              int halfAreaID;
              int k;
              halfAreaID = aggregatedOutputs.size(0);
              if (aggregatedOutputs.size(0) == 0) {
                area = 0.0;
              } else {
                area = aggregatedOutputs[aggregatedOutputs.size(0) * outputID];
                for (k = 2; k <= halfAreaID; k++) {
                  area += aggregatedOutputs[(k + aggregatedOutputs.size(0) *
                    outputID) - 1];
                }
              }

              if (area == 0.0) {
                defuzzifiedOutputs[outputID] = (outputSamplePoints[outputID] +
                  outputSamplePoints[outputID + outputSamplePoints.size(0) *
                  (outputSamplePoints.size(1) - 1)]) / 2.0;
              } else {
                double halfArea;
                boolean_T exitg1;
                halfArea = area / 2.0;
                halfAreaID = 0;
                area = 0.0;
                k = 0;
                exitg1 = false;
                while ((!exitg1) && (k <= outputSamplePoints.size(1) - 1)) {
                  area += aggregatedOutputs[k + aggregatedOutputs.size(0) *
                    outputID];
                  if (area >= halfArea) {
                    halfAreaID = k;
                    exitg1 = true;
                  } else {
                    k++;
                  }
                }

                defuzzifiedOutputs[outputID] = outputSamplePoints[outputID +
                  outputSamplePoints.size(0) * halfAreaID];
              }
            }
          }
        }

        //
        // Arguments    : const ::coder::array<double, 2U> &outputSamplePoints
        //                double sumAntecedentOutputs
        //                const ::coder::array<double, 2U> &aggregatedOutputs
        //                const ::coder::array<double, 2U> &fis_outputRange
        //                int fis_numOutputs
        //                ::coder::array<double, 1U> &defuzzifiedOutputs
        // Return Type  : void
        //
        void c_applyMamdaniDefuzzificationMethod(const ::coder::array<double, 2U>
          &outputSamplePoints, double sumAntecedentOutputs, const ::coder::array<
          double, 2U> &aggregatedOutputs, const ::coder::array<double, 2U>
          &fis_outputRange, int fis_numOutputs, ::coder::array<double, 1U>
          &defuzzifiedOutputs)
        {
          array<double, 1U> aggregatedOutputs_data;
          double b_aggregatedOutputs_data[51];
          double maxValueInX_data[51];
          double sumMaxValueIdsInX;
          double sumMaxValueInX;
          signed char maxValueIdsInX_data[51];
          defuzzifiedOutputs.set_size(fis_numOutputs);
          for (int outputID = 0; outputID < fis_numOutputs; outputID++) {
            if (sumAntecedentOutputs == 0.0) {
              defuzzifiedOutputs[outputID] = (fis_outputRange[outputID] +
                fis_outputRange[outputID + fis_outputRange.size(0)]) / 2.0;
            } else {
              double maxMFValue;
              int aggregatedOutputs_size_idx_0;
              int i;
              int loop_ub;
              loop_ub = aggregatedOutputs.size(0);
              aggregatedOutputs_size_idx_0 = aggregatedOutputs.size(0);
              for (i = 0; i < loop_ub; i++) {
                b_aggregatedOutputs_data[i] = aggregatedOutputs[i +
                  aggregatedOutputs.size(0) * outputID];
              }

              aggregatedOutputs_data.set((&b_aggregatedOutputs_data[0]),
                aggregatedOutputs_size_idx_0);
              maxMFValue = ::coder::internal::maximum(aggregatedOutputs_data);
              loop_ub = outputSamplePoints.size(1);
              loop_ub = static_cast<signed char>(loop_ub);
              if (0 <= loop_ub - 1) {
                std::memset(&maxValueInX_data[0], 0, loop_ub * sizeof(double));
              }

              loop_ub = outputSamplePoints.size(1);
              loop_ub = static_cast<signed char>(loop_ub);
              if (0 <= loop_ub - 1) {
                std::memset(&maxValueIdsInX_data[0], 0, loop_ub * sizeof(signed
                  char));
              }

              sumMaxValueInX = 0.0;
              sumMaxValueIdsInX = 0.0;
              i = aggregatedOutputs.size(0) - 1;
              for (loop_ub = 0; loop_ub <= i; loop_ub++) {
                if (aggregatedOutputs[loop_ub + aggregatedOutputs.size(0) *
                    outputID] == maxMFValue) {
                  maxValueInX_data[loop_ub] = outputSamplePoints[outputID +
                    outputSamplePoints.size(0) * loop_ub];
                  maxValueIdsInX_data[loop_ub] = 1;
                }

                sumMaxValueInX += maxValueInX_data[loop_ub];
                sumMaxValueIdsInX += static_cast<double>
                  (maxValueIdsInX_data[loop_ub]);
              }

              defuzzifiedOutputs[outputID] = sumMaxValueInX * (1.0 /
                sumMaxValueIdsInX);
            }
          }
        }

        //
        // Arguments    : const ::coder::array<double, 2U> &outputSamplePoints
        //                double sumAntecedentOutputs
        //                const ::coder::array<double, 2U> &aggregatedOutputs
        //                const ::coder::array<double, 2U> &fis_outputRange
        //                int fis_numOutputs
        //                ::coder::array<double, 1U> &defuzzifiedOutputs
        // Return Type  : void
        //
        void d_applyMamdaniDefuzzificationMethod(const ::coder::array<double, 2U>
          &outputSamplePoints, double sumAntecedentOutputs, const ::coder::array<
          double, 2U> &aggregatedOutputs, const ::coder::array<double, 2U>
          &fis_outputRange, int fis_numOutputs, ::coder::array<double, 1U>
          &defuzzifiedOutputs)
        {
          array<double, 1U> aggregatedOutputs_data;
          double b_aggregatedOutputs_data[51];
          double varargin_1_data[51];
          defuzzifiedOutputs.set_size(fis_numOutputs);
          for (int outputID = 0; outputID < fis_numOutputs; outputID++) {
            if (sumAntecedentOutputs == 0.0) {
              defuzzifiedOutputs[outputID] = (fis_outputRange[outputID] +
                fis_outputRange[outputID + fis_outputRange.size(0)]) / 2.0;
            } else {
              double d;
              double maxMFValue;
              double refX;
              int aggregatedOutputs_size_idx_0;
              int i;
              int idx;
              int k;
              int loop_ub;
              loop_ub = aggregatedOutputs.size(0);
              aggregatedOutputs_size_idx_0 = aggregatedOutputs.size(0);
              for (i = 0; i < loop_ub; i++) {
                b_aggregatedOutputs_data[i] = aggregatedOutputs[i +
                  aggregatedOutputs.size(0) * outputID];
              }

              aggregatedOutputs_data.set((&b_aggregatedOutputs_data[0]),
                aggregatedOutputs_size_idx_0);
              maxMFValue = ::coder::internal::maximum(aggregatedOutputs_data);
              i = outputSamplePoints.size(1) - 1;
              loop_ub = outputSamplePoints.size(1);
              aggregatedOutputs_size_idx_0 = static_cast<signed char>(loop_ub);
              for (k = 0; k <= i; k++) {
                varargin_1_data[k] = std::abs(outputSamplePoints[outputID +
                  outputSamplePoints.size(0) * k]);
              }

              if (static_cast<signed char>(loop_ub) <= 2) {
                if (static_cast<signed char>(loop_ub) == 1) {
                  refX = varargin_1_data[0];
                  idx = 1;
                } else if ((varargin_1_data[0] < varargin_1_data[1]) || (rtIsNaN
                            (varargin_1_data[0]) && (!rtIsNaN(varargin_1_data[1]))))
                {
                  refX = varargin_1_data[1];
                  idx = 2;
                } else {
                  refX = varargin_1_data[0];
                  idx = 1;
                }
              } else {
                if (!rtIsNaN(varargin_1_data[0])) {
                  idx = 1;
                } else {
                  boolean_T exitg1;
                  idx = 0;
                  k = 2;
                  exitg1 = false;
                  while ((!exitg1) && (k <= static_cast<signed char>(loop_ub)))
                  {
                    if (!rtIsNaN(varargin_1_data[k - 1])) {
                      idx = k;
                      exitg1 = true;
                    } else {
                      k++;
                    }
                  }
                }

                if (idx == 0) {
                  refX = varargin_1_data[0];
                  idx = 1;
                } else {
                  refX = varargin_1_data[idx - 1];
                  i = idx + 1;
                  for (k = i; k <= aggregatedOutputs_size_idx_0; k++) {
                    d = varargin_1_data[k - 1];
                    if (refX < d) {
                      refX = d;
                      idx = k;
                    }
                  }
                }
              }

              defuzzifiedOutputs[outputID] = outputSamplePoints[outputID +
                outputSamplePoints.size(0) * (idx - 1)];
              i = aggregatedOutputs.size(0) - 1;
              for (loop_ub = 0; loop_ub <= i; loop_ub++) {
                if (aggregatedOutputs[loop_ub + aggregatedOutputs.size(0) *
                    outputID] == maxMFValue) {
                  d = std::abs(outputSamplePoints[outputID +
                               outputSamplePoints.size(0) * loop_ub]);
                  if (d < refX) {
                    refX = d;
                    defuzzifiedOutputs[outputID] = outputSamplePoints[outputID +
                      outputSamplePoints.size(0) * loop_ub];
                  }
                }
              }
            }
          }
        }

        //
        // Arguments    : const ::coder::array<double, 2U> &outputSamplePoints
        //                double sumAntecedentOutputs
        //                const ::coder::array<double, 2U> &aggregatedOutputs
        //                const ::coder::array<double, 2U> &fis_outputRange
        //                int fis_numOutputs
        //                ::coder::array<double, 1U> &defuzzifiedOutputs
        // Return Type  : void
        //
        void e_applyMamdaniDefuzzificationMethod(const ::coder::array<double, 2U>
          &outputSamplePoints, double sumAntecedentOutputs, const ::coder::array<
          double, 2U> &aggregatedOutputs, const ::coder::array<double, 2U>
          &fis_outputRange, int fis_numOutputs, ::coder::array<double, 1U>
          &defuzzifiedOutputs)
        {
          array<double, 1U> aggregatedOutputs_data;
          double b_aggregatedOutputs_data[51];
          double varargin_1_data[51];
          defuzzifiedOutputs.set_size(fis_numOutputs);
          for (int outputID = 0; outputID < fis_numOutputs; outputID++) {
            if (sumAntecedentOutputs == 0.0) {
              defuzzifiedOutputs[outputID] = (fis_outputRange[outputID] +
                fis_outputRange[outputID + fis_outputRange.size(0)]) / 2.0;
            } else {
              double d;
              double maxMFValue;
              double refX;
              int aggregatedOutputs_size_idx_0;
              int i;
              int idx;
              int k;
              int loop_ub;
              loop_ub = aggregatedOutputs.size(0);
              aggregatedOutputs_size_idx_0 = aggregatedOutputs.size(0);
              for (i = 0; i < loop_ub; i++) {
                b_aggregatedOutputs_data[i] = aggregatedOutputs[i +
                  aggregatedOutputs.size(0) * outputID];
              }

              aggregatedOutputs_data.set((&b_aggregatedOutputs_data[0]),
                aggregatedOutputs_size_idx_0);
              maxMFValue = ::coder::internal::maximum(aggregatedOutputs_data);
              i = outputSamplePoints.size(1) - 1;
              loop_ub = outputSamplePoints.size(1);
              aggregatedOutputs_size_idx_0 = static_cast<signed char>(loop_ub);
              for (k = 0; k <= i; k++) {
                varargin_1_data[k] = std::abs(outputSamplePoints[outputID +
                  outputSamplePoints.size(0) * k]);
              }

              if (static_cast<signed char>(loop_ub) <= 2) {
                if (static_cast<signed char>(loop_ub) == 1) {
                  refX = varargin_1_data[0];
                  idx = 1;
                } else if ((varargin_1_data[0] > varargin_1_data[1]) || (rtIsNaN
                            (varargin_1_data[0]) && (!rtIsNaN(varargin_1_data[1]))))
                {
                  refX = varargin_1_data[1];
                  idx = 2;
                } else {
                  refX = varargin_1_data[0];
                  idx = 1;
                }
              } else {
                if (!rtIsNaN(varargin_1_data[0])) {
                  idx = 1;
                } else {
                  boolean_T exitg1;
                  idx = 0;
                  k = 2;
                  exitg1 = false;
                  while ((!exitg1) && (k <= static_cast<signed char>(loop_ub)))
                  {
                    if (!rtIsNaN(varargin_1_data[k - 1])) {
                      idx = k;
                      exitg1 = true;
                    } else {
                      k++;
                    }
                  }
                }

                if (idx == 0) {
                  refX = varargin_1_data[0];
                  idx = 1;
                } else {
                  refX = varargin_1_data[idx - 1];
                  i = idx + 1;
                  for (k = i; k <= aggregatedOutputs_size_idx_0; k++) {
                    d = varargin_1_data[k - 1];
                    if (refX > d) {
                      refX = d;
                      idx = k;
                    }
                  }
                }
              }

              defuzzifiedOutputs[outputID] = outputSamplePoints[outputID +
                outputSamplePoints.size(0) * (idx - 1)];
              i = aggregatedOutputs.size(0) - 1;
              for (loop_ub = 0; loop_ub <= i; loop_ub++) {
                if (aggregatedOutputs[loop_ub + aggregatedOutputs.size(0) *
                    outputID] == maxMFValue) {
                  d = std::abs(outputSamplePoints[outputID +
                               outputSamplePoints.size(0) * loop_ub]);
                  if (d > refX) {
                    refX = d;
                    defuzzifiedOutputs[outputID] = outputSamplePoints[outputID +
                      outputSamplePoints.size(0) * loop_ub];
                  }
                }
              }
            }
          }
        }

        //
        // Arguments    : const ::coder::array<double, 2U> &outputSamplePoints
        //                double sumAntecedentOutputs
        //                const ::coder::array<double, 2U> &aggregatedOutputs
        //                const ::coder::array<double, 2U> &fis_outputRange
        //                int fis_numOutputs
        //                ::coder::array<double, 1U> &defuzzifiedOutputs
        // Return Type  : void
        //
        void f_applyMamdaniDefuzzificationMethod(const ::coder::array<double, 2U>
          &outputSamplePoints, double sumAntecedentOutputs, const ::coder::array<
          double, 2U> &aggregatedOutputs, const ::coder::array<double, 2U>
          &fis_outputRange, int fis_numOutputs, ::coder::array<double, 1U>
          &defuzzifiedOutputs)
        {
          double Y_data[51];
          double vn1_data[51];
          signed char jpvt_data[51];
          defuzzifiedOutputs.set_size(fis_numOutputs);
          for (int outputID = 0; outputID < fis_numOutputs; outputID++) {
            if (sumAntecedentOutputs == 0.0) {
              defuzzifiedOutputs[outputID] = (fis_outputRange[outputID] +
                fis_outputRange[outputID + fis_outputRange.size(0)]) / 2.0;
            } else {
              int loop_ub;
              loop_ub = aggregatedOutputs.size(0);
              if (aggregatedOutputs.size(0) == 1) {
                Y_data[0] = 1.0 / aggregatedOutputs[aggregatedOutputs.size(0) *
                  outputID];
              } else {
                double smax;
                int Y_size_idx_1;
                int ix;
                int n;
                int pvt;
                Y_size_idx_1 = aggregatedOutputs.size(0);
                for (pvt = 0; pvt < loop_ub; pvt++) {
                  Y_data[pvt] = aggregatedOutputs[pvt + aggregatedOutputs.size(0)
                    * outputID];
                }

                n = static_cast<signed char>(aggregatedOutputs.size(0));
                loop_ub = static_cast<signed char>(aggregatedOutputs.size(0));
                if (0 <= loop_ub - 1) {
                  std::memset(&jpvt_data[0], 0, loop_ub * sizeof(signed char));
                }

                for (loop_ub = 0; loop_ub < n; loop_ub++) {
                  jpvt_data[loop_ub] = static_cast<signed char>(loop_ub + 1);
                }

                loop_ub = static_cast<signed char>(aggregatedOutputs.size(0));
                if (0 <= loop_ub - 1) {
                  std::memset(&vn1_data[0], 0, loop_ub * sizeof(double));
                }

                for (loop_ub = 0; loop_ub < n; loop_ub++) {
                  vn1_data[loop_ub] = std::abs(aggregatedOutputs[loop_ub +
                    aggregatedOutputs.size(0) * outputID]);
                }

                pvt = 0;
                ix = 0;
                smax = vn1_data[0];
                for (loop_ub = 2; loop_ub <= n; loop_ub++) {
                  ix++;
                  if (vn1_data[ix] > smax) {
                    pvt = loop_ub - 1;
                    smax = vn1_data[ix];
                  }
                }

                if (pvt + 1 != 1) {
                  Y_data[0] = Y_data[pvt];
                  jpvt_data[0] = jpvt_data[pvt];
                }

                pvt = 0;
                smax = std::abs(Y_data[0]);
                if (!(smax <= 2.2204460492503131E-15 * static_cast<double>
                      (Y_size_idx_1) * smax)) {
                  pvt = 1;
                }

                ix = static_cast<signed char>(Y_size_idx_1);
                loop_ub = static_cast<signed char>(Y_size_idx_1);
                if (0 <= loop_ub - 1) {
                  std::memset(&vn1_data[0], 0, loop_ub * sizeof(double));
                }

                if (0 <= pvt - 1) {
                  vn1_data[jpvt_data[0] - 1] = 1.0;
                }

                for (loop_ub = pvt; loop_ub >= 1; loop_ub--) {
                  vn1_data[jpvt_data[0] - 1] /= Y_data[0];
                }

                if (0 <= ix - 1) {
                  std::memcpy(&Y_data[0], &vn1_data[0], ix * sizeof(double));
                }
              }

              defuzzifiedOutputs[outputID] = outputSamplePoints[outputID] *
                Y_data[0];
            }
          }
        }
      }
    }
  }
}

//
// File trailer for applyMamdaniDefuzzificationMethod.cpp
//
// [EOF]
//
