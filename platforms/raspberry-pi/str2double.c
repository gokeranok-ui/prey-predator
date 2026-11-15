/*
 * File: str2double.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Aug-2024 22:12:40
 */

/* Include Files */
#include "str2double.h"
#include "opkene_data.h"
#include "opkene_emxutil.h"
#include "opkene_types.h"
#include "rt_nonfinite.h"
#include <stdio.h>

/* Function Declarations */
static boolean_T b_copydigits(char s1[3], int *idx, char s, int *k,
                              boolean_T allowpoint);

static boolean_T b_copyexponent(char s1[3], int *idx, char s, int *k);

static boolean_T b_copysign(emxArray_char_T *s1, int *idx,
                            const emxArray_char_T *s, int *k, int n,
                            boolean_T *success);

static boolean_T b_readNonFinite(char s, int *k, double *fv);

static boolean_T copydigits(emxArray_char_T *s1, int *idx,
                            const emxArray_char_T *s, int *k, int n,
                            boolean_T allowpoint);

static boolean_T copyexponent(emxArray_char_T *s1, int *idx,
                              const emxArray_char_T *s, int *k, int n);

static boolean_T isUnitImag(const emxArray_char_T *s, int k, int n);

static boolean_T readNonFinite(const emxArray_char_T *s, int *k, int n,
                               double *fv);

static boolean_T readfloat(emxArray_char_T *s1, int *idx,
                           const emxArray_char_T *s, int *k, int n,
                           boolean_T *b_finite, double *nfv,
                           boolean_T *foundsign, boolean_T *success);

/* Function Definitions */
/*
 * Arguments    : char s1[3]
 *                int *idx
 *                char s
 *                int *k
 *                boolean_T allowpoint
 * Return Type  : boolean_T
 */
static boolean_T b_copydigits(char s1[3], int *idx, char s, int *k,
                              boolean_T allowpoint)
{
  boolean_T exitg1;
  boolean_T haspoint;
  boolean_T success;
  success = (*k <= 1);
  haspoint = false;
  exitg1 = false;
  while ((!exitg1) && (success && (*k <= 1))) {
    if ((s >= '0') && (s <= '9')) {
      s1[*idx - 1] = s;
      (*idx)++;
      *k = 2;
    } else if (s == '.') {
      if (allowpoint && (!haspoint)) {
        success = true;
      } else {
        success = false;
      }
      if (success) {
        s1[*idx - 1] = '.';
        (*idx)++;
        haspoint = true;
      }
      *k = 2;
    } else if (s == ',') {
      *k = 2;
    } else {
      exitg1 = true;
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
static boolean_T b_copyexponent(char s1[3], int *idx, char s, int *k)
{
  boolean_T success;
  success = true;
  if ((*k <= 1) && ((s == 'E') || (s == 'e'))) {
    boolean_T b_success;
    s1[*idx - 1] = 'e';
    (*idx)++;
    *k = 2;
    b_success = b_copydigits(s1, idx, s, k, false);
    if ((!b_success) || (*k <= 2)) {
      success = false;
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
 *                boolean_T *success
 * Return Type  : boolean_T
 */
static boolean_T b_copysign(emxArray_char_T *s1, int *idx,
                            const emxArray_char_T *s, int *k, int n,
                            boolean_T *success)
{
  const char *s_data;
  char *s1_data;
  boolean_T exitg1;
  boolean_T foundsign;
  boolean_T isneg;
  s_data = s->data;
  s1_data = s1->data;
  isneg = false;
  foundsign = false;
  exitg1 = false;
  while ((!exitg1) && (*k <= n)) {
    char c;
    c = s_data[*k - 1];
    if (c == '-') {
      isneg = !isneg;
      foundsign = true;
      (*k)++;
    } else if (c == ',') {
      (*k)++;
    } else if (c == '+') {
      foundsign = true;
      (*k)++;
    } else if (!bv[(unsigned char)c & 127]) {
      exitg1 = true;
    } else {
      (*k)++;
    }
  }
  *success = (*k <= n);
  if ((*success) && isneg) {
    if ((*idx >= 2) && (s1_data[*idx - 2] == '-')) {
      s1_data[*idx - 2] = ' ';
    } else {
      s1_data[*idx - 1] = '-';
      (*idx)++;
    }
  }
  return foundsign;
}

/*
 * Arguments    : char s
 *                int *k
 *                double *fv
 * Return Type  : boolean_T
 */
static boolean_T b_readNonFinite(char s, int *k, double *fv)
{
  int ksaved;
  char c_idx_0;
  char c_idx_1;
  char c_idx_2;
  boolean_T b_finite;
  ksaved = *k;
  c_idx_0 = '\x00';
  while ((*k <= 1) && (s == ',')) {
    *k = 2;
  }
  if (*k <= 1) {
    c_idx_0 = s;
  }
  (*k)++;
  c_idx_1 = '\x00';
  while ((*k <= 1) && (s == ',')) {
    *k = 2;
  }
  if (*k <= 1) {
    c_idx_1 = s;
  }
  (*k)++;
  c_idx_2 = '\x00';
  while ((*k <= 1) && (s == ',')) {
    *k = 2;
  }
  if (*k <= 1) {
    c_idx_2 = s;
  }
  (*k)++;
  if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) &&
      ((c_idx_1 == 'N') || (c_idx_1 == 'n')) &&
      ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) {
    b_finite = false;
    *fv = rtInf;
  } else if (((c_idx_0 == 'N') || (c_idx_0 == 'n')) &&
             ((c_idx_1 == 'A') || (c_idx_1 == 'a')) &&
             ((c_idx_2 == 'N') || (c_idx_2 == 'n'))) {
    b_finite = false;
    *fv = rtNaN;
  } else {
    b_finite = true;
    *fv = 0.0;
    *k = ksaved;
  }
  return b_finite;
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
static boolean_T copydigits(emxArray_char_T *s1, int *idx,
                            const emxArray_char_T *s, int *k, int n,
                            boolean_T allowpoint)
{
  const char *s_data;
  char *s1_data;
  boolean_T exitg1;
  boolean_T haspoint;
  boolean_T success;
  s_data = s->data;
  s1_data = s1->data;
  success = (*k <= n);
  haspoint = false;
  exitg1 = false;
  while ((!exitg1) && (success && (*k <= n))) {
    char c;
    c = s_data[*k - 1];
    if ((c >= '0') && (c <= '9')) {
      s1_data[*idx - 1] = c;
      (*idx)++;
      (*k)++;
    } else if (c == '.') {
      if (allowpoint && (!haspoint)) {
        success = true;
      } else {
        success = false;
      }
      if (success) {
        s1_data[*idx - 1] = '.';
        (*idx)++;
        haspoint = true;
      }
      (*k)++;
    } else if (c == ',') {
      (*k)++;
    } else {
      exitg1 = true;
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
static boolean_T copyexponent(emxArray_char_T *s1, int *idx,
                              const emxArray_char_T *s, int *k, int n)
{
  const char *s_data;
  char *s1_data;
  boolean_T success;
  s_data = s->data;
  s1_data = s1->data;
  success = true;
  if (*k <= n) {
    char c;
    c = s_data[*k - 1];
    if ((c == 'E') || (c == 'e')) {
      int kexp;
      boolean_T b_success;
      s1_data[*idx - 1] = 'e';
      (*idx)++;
      (*k)++;
      while ((*k <= n) && (s_data[*k - 1] == ',')) {
        (*k)++;
      }
      if (*k <= n) {
        c = s_data[*k - 1];
        if (c == '-') {
          s1_data[*idx - 1] = '-';
          (*idx)++;
          (*k)++;
        } else if (c == '+') {
          (*k)++;
        }
      }
      kexp = *k;
      b_success = copydigits(s1, idx, s, k, n, false);
      if ((!b_success) || (*k <= kexp)) {
        success = false;
      }
    }
  }
  return success;
}

/*
 * Arguments    : const emxArray_char_T *s
 *                int k
 *                int n
 * Return Type  : boolean_T
 */
static boolean_T isUnitImag(const emxArray_char_T *s, int k, int n)
{
  const char *s_data;
  boolean_T p;
  s_data = s->data;
  p = false;
  if (k <= n) {
    char c_idx_0;
    c_idx_0 = s_data[k - 1];
    if (c_idx_0 == 'j') {
      p = true;
    } else if (c_idx_0 == 'i') {
      if (k >= n - 1) {
        p = true;
      } else {
        int b_k;
        char c_idx_1;
        char c_idx_2;
        b_k = k;
        c_idx_0 = '\x00';
        while ((b_k <= n) && (s_data[b_k - 1] == ',')) {
          b_k++;
        }
        if (b_k <= n) {
          c_idx_0 = s_data[b_k - 1];
        }
        b_k++;
        c_idx_1 = '\x00';
        while ((b_k <= n) && (s_data[b_k - 1] == ',')) {
          b_k++;
        }
        if (b_k <= n) {
          c_idx_1 = s_data[b_k - 1];
        }
        b_k++;
        c_idx_2 = '\x00';
        while ((b_k <= n) && (s_data[b_k - 1] == ',')) {
          b_k++;
        }
        if (b_k <= n) {
          c_idx_2 = s_data[b_k - 1];
        }
        if ((((c_idx_0 != 'I') && (c_idx_0 != 'i')) ||
             ((c_idx_1 != 'N') && (c_idx_1 != 'n')) ||
             ((c_idx_2 != 'F') && (c_idx_2 != 'f'))) &&
            (((c_idx_0 != 'N') && (c_idx_0 != 'n')) ||
             ((c_idx_1 != 'A') && (c_idx_1 != 'a')) ||
             ((c_idx_2 != 'N') && (c_idx_2 != 'n')))) {
          p = true;
        }
      }
    }
  }
  return p;
}

/*
 * Arguments    : const emxArray_char_T *s
 *                int *k
 *                int n
 *                double *fv
 * Return Type  : boolean_T
 */
static boolean_T readNonFinite(const emxArray_char_T *s, int *k, int n,
                               double *fv)
{
  int ksaved;
  const char *s_data;
  char c_idx_0;
  char c_idx_1;
  char c_idx_2;
  boolean_T b_finite;
  s_data = s->data;
  ksaved = *k;
  c_idx_0 = '\x00';
  while ((*k <= n) && (s_data[*k - 1] == ',')) {
    (*k)++;
  }
  if (*k <= n) {
    c_idx_0 = s_data[*k - 1];
  }
  (*k)++;
  c_idx_1 = '\x00';
  while ((*k <= n) && (s_data[*k - 1] == ',')) {
    (*k)++;
  }
  if (*k <= n) {
    c_idx_1 = s_data[*k - 1];
  }
  (*k)++;
  c_idx_2 = '\x00';
  while ((*k <= n) && (s_data[*k - 1] == ',')) {
    (*k)++;
  }
  if (*k <= n) {
    c_idx_2 = s_data[*k - 1];
  }
  (*k)++;
  if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) &&
      ((c_idx_1 == 'N') || (c_idx_1 == 'n')) &&
      ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) {
    b_finite = false;
    *fv = rtInf;
  } else if (((c_idx_0 == 'N') || (c_idx_0 == 'n')) &&
             ((c_idx_1 == 'A') || (c_idx_1 == 'a')) &&
             ((c_idx_2 == 'N') || (c_idx_2 == 'n'))) {
    b_finite = false;
    *fv = rtNaN;
  } else {
    b_finite = true;
    *fv = 0.0;
    *k = ksaved;
  }
  return b_finite;
}

/*
 * Arguments    : emxArray_char_T *s1
 *                int *idx
 *                const emxArray_char_T *s
 *                int *k
 *                int n
 *                boolean_T *b_finite
 *                double *nfv
 *                boolean_T *foundsign
 *                boolean_T *success
 * Return Type  : boolean_T
 */
static boolean_T readfloat(emxArray_char_T *s1, int *idx,
                           const emxArray_char_T *s, int *k, int n,
                           boolean_T *b_finite, double *nfv,
                           boolean_T *foundsign, boolean_T *success)
{
  int b_idx;
  const char *s_data;
  char *s1_data;
  boolean_T isimag;
  s_data = s->data;
  isimag = false;
  *b_finite = true;
  *nfv = 0.0;
  b_idx = *idx;
  *foundsign = b_copysign(s1, &b_idx, s, k, n, success);
  s1_data = s1->data;
  *idx = b_idx;
  if (*success) {
    char c;
    if (isUnitImag(s, *k, n)) {
      boolean_T exitg4;
      isimag = true;
      (*k)++;
      exitg4 = false;
      while ((!exitg4) && (*k <= n)) {
        c = s_data[*k - 1];
        if (bv[(unsigned char)c & 127] || (c == '\x00') || (c == ',')) {
          (*k)++;
        } else {
          exitg4 = true;
        }
      }
      if ((*k <= n) && (s_data[*k - 1] == '*')) {
        (*k)++;
        b_copysign(s1, &b_idx, s, k, n, success);
        s1_data = s1->data;
        *idx = b_idx;
        if (*success) {
          if (isUnitImag(s, *k, n)) {
            *success = false;
          } else {
            *b_finite = readNonFinite(s, k, n, nfv);
            if (*b_finite) {
              *success = copydigits(s1, idx, s, k, n, true);
              if (*success) {
                *success = copyexponent(s1, idx, s, k, n);
              }
            } else if ((b_idx >= 2) && (s1_data[b_idx - 2] == '-')) {
              *idx = b_idx - 1;
              s1_data[b_idx - 2] = ' ';
              *nfv = -*nfv;
            }
            exitg4 = false;
            while ((!exitg4) && (*k <= n)) {
              c = s_data[*k - 1];
              if (bv[(unsigned char)c & 127] || (c == '\x00') || (c == ',')) {
                (*k)++;
              } else {
                exitg4 = true;
              }
            }
            if ((*k <= n) && (s_data[*k - 1] == '*')) {
              (*k)++;
              exitg4 = false;
              while ((!exitg4) && (*k <= n)) {
                c = s_data[*k - 1];
                if (bv[(unsigned char)c & 127] || (c == '\x00') || (c == ',')) {
                  (*k)++;
                } else {
                  exitg4 = true;
                }
              }
            }
            if (*k <= n) {
              c = s_data[*k - 1];
              if ((c == 'i') || (c == 'j')) {
                (*k)++;
              }
            }
          }
          int exitg3;
          do {
            exitg3 = 0;
            if (*k <= n) {
              c = s_data[*k - 1];
              if (bv[(unsigned char)c & 127] || (c == '\x00') || (c == ',')) {
                (*k)++;
              } else {
                exitg3 = 1;
              }
            } else {
              exitg3 = 2;
            }
          } while (exitg3 == 0);
        }
      } else {
        s1_data[b_idx - 1] = '1';
        *idx = b_idx + 1;
      }
    } else {
      boolean_T exitg4;
      *b_finite = readNonFinite(s, k, n, nfv);
      if (*b_finite) {
        *success = copydigits(s1, idx, s, k, n, true);
        if (*success) {
          *success = copyexponent(s1, idx, s, k, n);
        }
      } else if ((b_idx >= 2) && (s1_data[b_idx - 2] == '-')) {
        *idx = b_idx - 1;
        s1_data[b_idx - 2] = ' ';
        *nfv = -*nfv;
      }
      exitg4 = false;
      while ((!exitg4) && (*k <= n)) {
        c = s_data[*k - 1];
        if (bv[(unsigned char)c & 127] || (c == '\x00') || (c == ',')) {
          (*k)++;
        } else {
          exitg4 = true;
        }
      }
      if ((*k <= n) && (s_data[*k - 1] == '*')) {
        (*k)++;
        exitg4 = false;
        while ((!exitg4) && (*k <= n)) {
          c = s_data[*k - 1];
          if (bv[(unsigned char)c & 127] || (c == '\x00') || (c == ',')) {
            (*k)++;
          } else {
            exitg4 = true;
          }
        }
      }
      if (*k <= n) {
        c = s_data[*k - 1];
        if ((c == 'i') || (c == 'j')) {
          (*k)++;
          isimag = true;
        }
      }
    }
    int exitg2;
    do {
      exitg2 = 0;
      if (*k <= n) {
        c = s_data[*k - 1];
        if (bv[(unsigned char)c & 127] || (c == '\x00') || (c == ',')) {
          (*k)++;
        } else {
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }
  return isimag;
}

/*
 * Arguments    : char s
 * Return Type  : creal_T
 */
creal_T b_str2double(char s)
{
  creal_T x;
  double scanned1;
  double scanned2;
  int idx;
  int k;
  int ntoread;
  char s1[3];
  boolean_T b;
  boolean_T b_finite;
  boolean_T exitg1;
  boolean_T isimag1;
  boolean_T isneg;
  boolean_T success;
  x.re = rtNaN;
  x.im = 0.0;
  ntoread = 0;
  k = 1;
  b = bv[(unsigned char)s & 127];
  if (b || (s == '\x00')) {
    k = 2;
  }
  isimag1 = false;
  b_finite = true;
  scanned1 = 0.0;
  idx = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (k <= 1)) {
    if (s == '-') {
      isneg = !isneg;
      k = 2;
    } else if ((s == ',') || (s == '+') || b) {
      k = 2;
    } else {
      exitg1 = true;
    }
  }
  success = (k <= 1);
  if (success && isneg) {
    s1[0] = '-';
    idx = 2;
  }
  if (success) {
    isneg = false;
    if (k <= 1) {
      isneg = ((s == 'j') || (s == 'i'));
    }
    if (isneg) {
      isimag1 = true;
      k++;
      s1[idx - 1] = '1';
      idx++;
    } else {
      b_finite = b_readNonFinite(s, &k, &scanned1);
      if (b_finite) {
        success = b_copydigits(s1, &idx, s, &k, true);
        if (success) {
          success = b_copyexponent(s1, &idx, s, &k);
        }
      } else if ((idx >= 2) && (s1[0] == '-')) {
        idx = 1;
        s1[0] = ' ';
        scanned1 = -scanned1;
      }
      while ((k <= 1) && (b || (s == '\x00') || (s == ','))) {
        k++;
      }
      if ((k <= 1) && (s == '*')) {
        k = 2;
      }
      if ((k <= 1) && ((s == 'i') || (s == 'j'))) {
        k = 2;
        isimag1 = true;
      }
    }
    while ((k <= 1) && (b || (s == '\x00') || (s == ','))) {
      k++;
    }
  }
  if (b_finite) {
    ntoread = 1;
  }
  if (success && (k <= 1)) {
    int b_idx;
    boolean_T c_finite;
    boolean_T foundsign;
    boolean_T isimag2;
    s1[idx - 1] = ' ';
    isimag2 = false;
    c_finite = true;
    scanned2 = 0.0;
    b_idx = idx;
    k = 1;
    isneg = false;
    foundsign = false;
    if (s == '-') {
      isneg = true;
      foundsign = true;
      k = 2;
    } else if (s == ',') {
      k = 2;
    } else if (s == '+') {
      foundsign = true;
      k = 2;
    } else if (b) {
      k = 2;
    }
    success = (k <= 1);
    if (success && isneg) {
      if (s1[idx - 1] == '-') {
        s1[idx - 1] = ' ';
      } else {
        s1[idx] = '-';
        b_idx = idx + 1;
      }
    }
    idx = b_idx + 1;
    if (success) {
      isneg = false;
      if (k <= 1) {
        isneg = ((s == 'j') || (s == 'i'));
      }
      if (isneg) {
        isimag2 = true;
        k++;
        s1[b_idx] = '1';
        idx = b_idx + 2;
      } else {
        c_finite = b_readNonFinite(s, &k, &scanned2);
        if (c_finite) {
          success = b_copydigits(s1, &idx, s, &k, true);
          if (success) {
            success = b_copyexponent(s1, &idx, s, &k);
          }
        } else if (s1[b_idx - 1] == '-') {
          idx = b_idx;
          s1[b_idx - 1] = ' ';
          scanned2 = -scanned2;
        }
        while ((k <= 1) && (b || (s == '\x00') || (s == ','))) {
          k++;
        }
        if ((k <= 1) && (s == '*')) {
          k = 2;
        }
        if ((k <= 1) && ((s == 'i') || (s == 'j'))) {
          k = 2;
          isimag2 = true;
        }
      }
      while ((k <= 1) && (b || (s == '\x00') || (s == ','))) {
        k++;
      }
    }
    if (c_finite) {
      ntoread++;
    }
    if (success && (k > 1) && ((boolean_T)(isimag1 ^ isimag2)) && foundsign) {
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
      ntoread = sscanf(&s1[0], "%lf %lf", &scanned1, &scanned2);
      if (ntoread != 2) {
        scanned1 = rtNaN;
        scanned2 = rtNaN;
      }
    } else if (ntoread == 1) {
      double b_scanned1;
      ntoread = sscanf(&s1[0], "%lf", &b_scanned1);
      if (ntoread != 1) {
        b_scanned1 = rtNaN;
      }
      if (b_finite) {
        scanned1 = b_scanned1;
      } else {
        scanned2 = b_scanned1;
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
  emxArray_char_T *s1;
  creal_T x;
  double scanned1;
  double scanned2;
  int i;
  int idx;
  int k;
  const char *s_data;
  char *s1_data;
  boolean_T a__1;
  boolean_T foundsign;
  boolean_T isfinite1;
  boolean_T isfinite2;
  boolean_T success;
  s_data = s->data;
  x.re = rtNaN;
  x.im = 0.0;
  if (s->size[1] >= 1) {
    int ntoread;
    boolean_T exitg1;
    boolean_T isimag1;
    emxInit_char_T(&s1, 2);
    ntoread = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (k <= s->size[1])) {
      char c;
      c = s_data[k - 1];
      if (bv[(unsigned char)c & 127] || (c == '\x00')) {
        k++;
      } else {
        exitg1 = true;
      }
    }
    i = s1->size[0] * s1->size[1];
    s1->size[0] = 1;
    s1->size[1] = s->size[1] + 2;
    emxEnsureCapacity_char_T(s1, i);
    s1_data = s1->data;
    idx = s->size[1] + 2;
    for (i = 0; i < idx; i++) {
      s1_data[i] = '\x00';
    }
    idx = 1;
    isimag1 = readfloat(s1, &idx, s, &k, s->size[1], &isfinite1, &scanned1,
                        &a__1, &success);
    s1_data = s1->data;
    if (isfinite1) {
      ntoread = 1;
    }
    if (success && (k <= s->size[1])) {
      s1_data[idx - 1] = ' ';
      idx++;
      a__1 = readfloat(s1, &idx, s, &k, s->size[1], &isfinite2, &scanned2,
                       &foundsign, &success);
      s1_data = s1->data;
      if (isfinite2) {
        ntoread++;
      }
      if (success && (k > s->size[1]) && ((boolean_T)(isimag1 ^ a__1)) &&
          foundsign) {
        success = true;
      } else {
        success = false;
      }
    } else {
      scanned2 = 0.0;
    }
    if (success) {
      s1_data[idx - 1] = '\x00';
      if (ntoread == 2) {
        idx = sscanf(&s1_data[0], "%lf %lf", &scanned1, &scanned2);
        if (idx != 2) {
          scanned1 = rtNaN;
          scanned2 = rtNaN;
        }
      } else if (ntoread == 1) {
        double b_scanned1;
        idx = sscanf(&s1_data[0], "%lf", &b_scanned1);
        if (idx != 1) {
          b_scanned1 = rtNaN;
        }
        if (isfinite1) {
          scanned1 = b_scanned1;
        } else {
          scanned2 = b_scanned1;
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
