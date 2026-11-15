/*
 * File: str2double.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 27-Oct-2020 02:17:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "str2double.h"
#include "opkene_emxutil.h"
#include "char.h"
#include "opkene_data.h"
#include <stdio.h>

/* Function Declarations */
static boolean_T b_copydigits(char s1[3], int *idx, char s, int *k, boolean_T
  allowpoint);
static boolean_T b_copysign(emxArray_char_T *s1, int *idx, const emxArray_char_T
  *s, int *k, int n);
static boolean_T c_copysign(char s1[3], int *idx, char s, int *k);
static boolean_T copydigits(emxArray_char_T *s1, int *idx, const emxArray_char_T
  *s, int *k, int n, boolean_T allowpoint);
static boolean_T copyexponent(emxArray_char_T *s1, int *idx, const
  emxArray_char_T *s, int *k, int n);
static void readNonFinite(const emxArray_char_T *s, int *k, int n, boolean_T
  *b_finite, double *fv);
static void readfloat(emxArray_char_T *s1, int *idx, const emxArray_char_T *s,
                      int *k, int n, boolean_T *isimag, boolean_T *b_finite,
                      double *nfv, boolean_T *success);

/* Function Definitions */

/*
 * Arguments    : char s1[3]
 *                int *idx
 *                char s
 *                int *k
 *                boolean_T allowpoint
 * Return Type  : boolean_T
 */
static boolean_T b_copydigits(char s1[3], int *idx, char s, int *k, boolean_T
  allowpoint)
{
  boolean_T success;
  boolean_T haspoint;
  boolean_T exitg1;
  success = (*k <= 1);
  haspoint = !allowpoint;
  exitg1 = false;
  while ((!exitg1) && (*k <= 1)) {
    if ((s >= '0') && (s <= '9')) {
      s1[*idx - 1] = s;
      (*idx)++;
      (*k)++;
    } else if (s == '.') {
      if (haspoint) {
        success = false;
        exitg1 = true;
      } else {
        s1[*idx - 1] = '.';
        (*idx)++;
        haspoint = true;
        (*k)++;
      }
    } else if (s != ',') {
      exitg1 = true;
    } else {
      (*k)++;
    }
  }

  return success;
}

/*
 * Arguments    : emxArray_char_T *s1
 *                int *idx
 *                const emxArray_char_T *s
 *                int *k
 *                int n
 * Return Type  : boolean_T
 */
static boolean_T b_copysign(emxArray_char_T *s1, int *idx, const emxArray_char_T
  *s, int *k, int n)
{
  boolean_T success;
  boolean_T isneg;
  isneg = false;
  while ((*k <= n) && ((s->data[*k - 1] == '+') || (s->data[*k - 1] == '-') ||
                       bv0[(unsigned char)s->data[*k - 1] & 127])) {
    if (s->data[*k - 1] == '-') {
      isneg = !isneg;
    }

    (*k)++;
  }

  success = (*k <= n);
  if (success && isneg) {
    if ((*idx >= 2) && (s1->data[*idx - 2] == '-')) {
      s1->data[*idx - 2] = ' ';
    } else {
      s1->data[*idx - 1] = '-';
      (*idx)++;
    }
  }

  return success;
}

/*
 * Arguments    : char s1[3]
 *                int *idx
 *                char s
 *                int *k
 * Return Type  : boolean_T
 */
static boolean_T c_copysign(char s1[3], int *idx, char s, int *k)
{
  boolean_T success;
  boolean_T isneg;
  *k = 1;
  isneg = false;
  while ((*k <= 1) && ((s == '+') || (s == '-') || bv0[(unsigned char)s & 127]))
  {
    if (s == '-') {
      isneg = !isneg;
    }

    *k = 2;
  }

  success = (*k <= 1);
  if (success && isneg) {
    if (s1[*idx - 2] == '-') {
      s1[*idx - 2] = ' ';
    } else {
      s1[*idx - 1] = '-';
      (*idx)++;
    }
  }

  return success;
}

/*
 * Arguments    : emxArray_char_T *s1
 *                int *idx
 *                const emxArray_char_T *s
 *                int *k
 *                int n
 *                boolean_T allowpoint
 * Return Type  : boolean_T
 */
static boolean_T copydigits(emxArray_char_T *s1, int *idx, const emxArray_char_T
  *s, int *k, int n, boolean_T allowpoint)
{
  boolean_T success;
  boolean_T haspoint;
  boolean_T exitg1;
  success = (*k <= n);
  haspoint = !allowpoint;
  exitg1 = false;
  while ((!exitg1) && (*k <= n)) {
    if ((s->data[*k - 1] >= '0') && (s->data[*k - 1] <= '9')) {
      s1->data[*idx - 1] = s->data[*k - 1];
      (*idx)++;
      (*k)++;
    } else if (s->data[*k - 1] == '.') {
      if (haspoint) {
        success = false;
        exitg1 = true;
      } else {
        s1->data[*idx - 1] = '.';
        (*idx)++;
        haspoint = true;
        (*k)++;
      }
    } else if (s->data[*k - 1] != ',') {
      exitg1 = true;
    } else {
      (*k)++;
    }
  }

  return success;
}

/*
 * Arguments    : emxArray_char_T *s1
 *                int *idx
 *                const emxArray_char_T *s
 *                int *k
 *                int n
 * Return Type  : boolean_T
 */
static boolean_T copyexponent(emxArray_char_T *s1, int *idx, const
  emxArray_char_T *s, int *k, int n)
{
  boolean_T success;
  success = true;
  if ((*k <= n) && ((s->data[*k - 1] == 'E') || (s->data[*k - 1] == 'e'))) {
    s1->data[*idx - 1] = 'e';
    (*idx)++;
    (*k)++;
    if (*k <= n) {
      if (s->data[*k - 1] == '-') {
        s1->data[*idx - 1] = '-';
        (*idx)++;
        (*k)++;
      } else {
        if (s->data[*k - 1] == '+') {
          (*k)++;
        }
      }
    }

    success = copydigits(s1, idx, s, k, n, false);
  }

  return success;
}

/*
 * Arguments    : const emxArray_char_T *s
 *                int *k
 *                int n
 *                boolean_T *b_finite
 *                double *fv
 * Return Type  : void
 */
static void readNonFinite(const emxArray_char_T *s, int *k, int n, boolean_T
  *b_finite, double *fv)
{
  *b_finite = true;
  *fv = 0.0;
  if (*k + 2 <= n) {
    if (((s->data[*k - 1] == 'I') || (s->data[*k - 1] == 'i')) && ((s->data[*k] ==
          'N') || (s->data[*k] == 'n')) && ((s->data[*k + 1] == 'F') || (s->
          data[*k + 1] == 'f'))) {
      *b_finite = false;
      *fv = rtInf;
      *k += 3;
    } else {
      if (((s->data[*k - 1] == 'N') || (s->data[*k - 1] == 'n')) && ((s->data[*k]
            == 'A') || (s->data[*k] == 'a')) && ((s->data[*k + 1] == 'N') ||
           (s->data[*k + 1] == 'n'))) {
        *b_finite = false;
        *fv = rtNaN;
        *k += 3;
      }
    }
  }
}

/*
 * Arguments    : emxArray_char_T *s1
 *                int *idx
 *                const emxArray_char_T *s
 *                int *k
 *                int n
 *                boolean_T *isimag
 *                boolean_T *b_finite
 *                double *nfv
 *                boolean_T *success
 * Return Type  : void
 */
static void readfloat(emxArray_char_T *s1, int *idx, const emxArray_char_T *s,
                      int *k, int n, boolean_T *isimag, boolean_T *b_finite,
                      double *nfv, boolean_T *success)
{
  int b_idx;
  *isimag = false;
  *b_finite = true;
  *nfv = 0.0;
  b_idx = *idx;
  *success = b_copysign(s1, &b_idx, s, k, n);
  *idx = b_idx;
  if (*success) {
    if ((*k <= n) && ((s->data[*k - 1] == 'j') || ((s->data[*k - 1] == 'i') &&
          ((*k == n) || ((s->data[*k] != 'n') && (s->data[*k] != 'N')))))) {
      *isimag = true;
      (*k)++;
      while ((*k <= n) && bv0[(unsigned char)s->data[*k - 1] & 127]) {
        (*k)++;
      }

      if ((*k <= n) && (s->data[*k - 1] == '*')) {
        (*k)++;
        *success = b_copysign(s1, &b_idx, s, k, n);
        *idx = b_idx;
        if (*success) {
          if ((*k <= n) && ((s->data[*k - 1] == 'j') || ((s->data[*k - 1] == 'i')
                && ((*k == n) || ((s->data[*k] != 'n') && (s->data[*k] != 'N'))))))
          {
            *success = false;
          } else {
            readNonFinite(s, k, n, b_finite, nfv);
            if (*b_finite) {
              *success = copydigits(s1, idx, s, k, n, true);
              if (*success) {
                *success = copyexponent(s1, idx, s, k, n);
              }
            } else {
              if ((b_idx >= 2) && (s1->data[b_idx - 2] == '-')) {
                *idx = b_idx - 1;
                s1->data[b_idx - 2] = ' ';
                *nfv = -*nfv;
              }
            }

            while ((*k <= n) && bv0[(unsigned char)s->data[*k - 1] & 127]) {
              (*k)++;
            }

            if ((*k <= n) && (s->data[*k - 1] == '*')) {
              (*k)++;
              while ((*k <= n) && bv0[(unsigned char)s->data[*k - 1] & 127]) {
                (*k)++;
              }
            }

            if ((*k <= n) && ((s->data[*k - 1] == 'i') || (s->data[*k - 1] ==
                  'j'))) {
              (*k)++;
            }
          }

          while ((*k <= n) && bv0[(unsigned char)s->data[*k - 1] & 127]) {
            (*k)++;
          }
        }
      } else {
        s1->data[b_idx - 1] = '1';
        *idx = b_idx + 1;
      }
    } else {
      readNonFinite(s, k, n, b_finite, nfv);
      if (*b_finite) {
        *success = copydigits(s1, idx, s, k, n, true);
        if (*success) {
          *success = copyexponent(s1, idx, s, k, n);
        }
      } else {
        if ((b_idx >= 2) && (s1->data[b_idx - 2] == '-')) {
          *idx = b_idx - 1;
          s1->data[b_idx - 2] = ' ';
          *nfv = -*nfv;
        }
      }

      while ((*k <= n) && bv0[(unsigned char)s->data[*k - 1] & 127]) {
        (*k)++;
      }

      if ((*k <= n) && (s->data[*k - 1] == '*')) {
        (*k)++;
        while ((*k <= n) && bv0[(unsigned char)s->data[*k - 1] & 127]) {
          (*k)++;
        }
      }

      if ((*k <= n) && ((s->data[*k - 1] == 'i') || (s->data[*k - 1] == 'j'))) {
        (*k)++;
        *isimag = true;
      }
    }

    while ((*k <= n) && bv0[(unsigned char)s->data[*k - 1] & 127]) {
      (*k)++;
    }
  }
}

/*
 * Arguments    : char s
 * Return Type  : creal_T
 */
creal_T b_str2double(char s)
{
  creal_T x;
  boolean_T isimag1;
  int nread;
  int idx;
  char s1[3];
  boolean_T isneg;
  boolean_T success;
  int ntoread;
  double scanned2;
  double scanned1;
  x.re = rtNaN;
  x.im = 0.0;
  isimag1 = false;
  nread = 1;
  idx = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  if ((s == '+') || (s == '-') || bv0[(unsigned char)s & 127]) {
    if (s == '-') {
      isneg = true;
    }

    nread = 2;
  }

  success = (nread <= 1);
  if (success && isneg) {
    s1[0] = '-';
    idx = 2;
  }

  if (success) {
    if ((nread <= 1) && ((s == 'j') || (s == 'i'))) {
      isimag1 = true;
      nread = 2;
      s1[idx - 1] = '1';
      idx++;
    } else {
      success = b_copydigits(s1, &idx, s, &nread, true);
      if (success) {
        success = true;
        if ((nread <= 1) && ((s == 'E') || (s == 'e'))) {
          s1[idx - 1] = 'e';
          idx++;
          nread = 2;
          b_copydigits(s1, &idx, s, &nread, false);
          success = false;
        }
      }

      while ((nread <= 1) && bv0[(unsigned char)s & 127]) {
        nread++;
      }

      if ((nread <= 1) && (s == '*')) {
        nread = 2;
      }

      if ((nread <= 1) && ((s == 'i') || (s == 'j'))) {
        nread = 2;
        isimag1 = true;
      }
    }

    while ((nread <= 1) && bv0[(unsigned char)s & 127]) {
      nread++;
    }
  }

  ntoread = 1;
  if (success && (nread <= 1)) {
    s1[idx - 1] = ' ';
    isneg = false;
    idx++;
    nread = 1;
    success = c_copysign(s1, &idx, s, &nread);
    if (success) {
      if ((nread <= 1) && ((s == 'j') || (s == 'i'))) {
        isneg = true;
        nread = 2;
        s1[idx - 1] = '1';
        idx++;
      } else {
        success = b_copydigits(s1, &idx, s, &nread, true);
        if (success) {
          success = true;
          if ((nread <= 1) && ((s == 'E') || (s == 'e'))) {
            s1[idx - 1] = 'e';
            idx++;
            nread = 2;
            b_copydigits(s1, &idx, s, &nread, false);
            success = false;
          }
        }

        while ((nread <= 1) && bv0[(unsigned char)s & 127]) {
          nread++;
        }

        if ((nread <= 1) && (s == '*')) {
          nread = 2;
        }

        if ((nread <= 1) && ((s == 'i') || (s == 'j'))) {
          nread = 2;
          isneg = true;
        }
      }

      while ((nread <= 1) && bv0[(unsigned char)s & 127]) {
        nread++;
      }
    }

    scanned2 = 0.0;
    ntoread = 2;
    if (success && (nread > 1) && ((isimag1 ^ isneg) != 0)) {
      success = true;
    } else {
      success = false;
    }
  } else {
    scanned2 = 0.0;
  }

  if (success) {
    s1[idx - 1] = '\x00';
    if (ntoread == 2) {
      nread = sscanf(&s1[0], "%lf %lf", &scanned1, &scanned2);
      if (nread != 2) {
        scanned1 = rtNaN;
        scanned2 = rtNaN;
      }
    } else {
      nread = sscanf(&s1[0], "%lf", &scanned1);
      if (nread == 1) {
      } else {
        scanned1 = rtNaN;
      }
    }

    if (isimag1) {
      x.re = scanned2;
      x.im = scanned1;
    } else {
      x.re = scanned1;
      x.im = scanned2;
    }
  }

  return x;
}

/*
 * Arguments    : const emxArray_char_T *s
 * Return Type  : creal_T
 */
creal_T str2double(const emxArray_char_T *s)
{
  creal_T x;
  emxArray_real_T *r18;
  int ntoread;
  int nread;
  int idx;
  emxArray_char_T *s1;
  boolean_T isimag1;
  boolean_T isfinite1;
  double scanned1;
  boolean_T success;
  double scanned2;
  boolean_T isimag2;
  boolean_T isfinite2;
  double b_scanned1;
  x.re = rtNaN;
  x.im = 0.0;
  if (s->size[1] >= 1) {
    emxInit_real_T(&r18, 2);
    ntoread = 0;
    nread = r18->size[0] * r18->size[1];
    r18->size[0] = 1;
    r18->size[1] = s->size[1] + 2;
    emxEnsureCapacity_real_T(r18, nread);
    idx = s->size[1] + 2;
    for (nread = 0; nread < idx; nread++) {
      r18->data[nread] = 0.0;
    }

    emxInit_char_T(&s1, 2);
    c_char(r18, s1);
    idx = 1;
    nread = 1;
    readfloat(s1, &idx, s, &nread, s->size[1], &isimag1, &isfinite1, &scanned1,
              &success);
    emxFree_real_T(&r18);
    if (isfinite1) {
      ntoread = 1;
    }

    if (success && (nread <= s->size[1])) {
      s1->data[idx - 1] = ' ';
      idx++;
      readfloat(s1, &idx, s, &nread, s->size[1], &isimag2, &isfinite2, &scanned2,
                &success);
      if (isfinite2) {
        ntoread++;
      }

      if (success && (nread > s->size[1]) && ((isimag1 ^ isimag2) != 0)) {
        success = true;
      } else {
        success = false;
      }
    } else {
      scanned2 = 0.0;
    }

    if (success) {
      s1->data[idx - 1] = '\x00';
      if (ntoread == 2) {
        nread = sscanf(&s1->data[0], "%lf %lf", &scanned1, &scanned2);
        if (nread != 2) {
          scanned1 = rtNaN;
          scanned2 = rtNaN;
        }
      } else {
        if (ntoread == 1) {
          nread = sscanf(&s1->data[0], "%lf", &b_scanned1);
          if (nread == 1) {
          } else {
            b_scanned1 = rtNaN;
          }

          if (isfinite1) {
            scanned1 = b_scanned1;
          } else {
            scanned2 = b_scanned1;
          }
        }
      }

      if (isimag1) {
        x.re = scanned2;
        x.im = scanned1;
      } else {
        x.re = scanned1;
        x.im = scanned2;
      }
    }

    emxFree_char_T(&s1);
  }

  return x;
}

/*
 * File trailer for str2double.c
 *
 * [EOF]
 */
