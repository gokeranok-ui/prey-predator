/* fileManager.c */
#include "rt_nonfinite.h"
#include "opkene.h"
#include "fileManager.h"
#include "applyMamdaniImplicationMethod.h"
#include "opkene_emxutil.h"
#include "opkene_rtwutil.h"
#include "opkene_data.h"
#include "fis_virtual_fs.h"
#include <stdio.h>

/* Function Declarations */
static signed char filedata(void);

/* Function Definitions */
static signed char filedata(void)
{
  signed char success;
  int k;
  success = 0;
  k = 0;
  while ((success == 0) && (k < 20)) {
    if (eml_openfiles[k] == NULL) {
      success = (signed char)(k + 1);
    }

    k++;
  }

  return success;
}

/*
 * Arguments    : const emxArray_char_T *cfilename
 *                const char * cpermission
 * Return Type  : signed char
 */
signed char cfopen(const emxArray_char_T *cfilename, const char * cpermission)
{
  signed char fileid;
  signed char j;
  emxArray_char_T *ccfilename;
  int i1;
  int loop_ub;
  FILE * filestar;
  fileid = -1;
  j = filedata();
  if (j >= 1) {
    emxInit_char_T(&ccfilename, 2);
    i1 = ccfilename->size[0] * ccfilename->size[1];
    ccfilename->size[0] = 1;
    ccfilename->size[1] = cfilename->size[1] + 1;
    emxEnsureCapacity_char_T(ccfilename, i1);
    loop_ub = cfilename->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      ccfilename->data[i1] = cfilename->data[i1];
    }

    ccfilename->data[cfilename->size[1]] = '\x00';
    filestar = fis_virtual_fs_cfopen(&ccfilename->data[0], cpermission, j - 1);
    if (filestar == NULL) {
      filestar = fopen(&ccfilename->data[0], cpermission);
    }

    emxFree_char_T(&ccfilename);
    if (filestar != NULL) {
      eml_openfiles[j - 1] = filestar;
      eml_autoflush[j - 1] = true;
      i1 = j + 2;
      if (i1 > 127) {
        i1 = 127;
      }

      fileid = (signed char)i1;
    }
  }

  return fileid;
}

/*
 * Arguments    : double varargin_1
 * Return Type  : FILE *
 */
FILE * fileManager(double varargin_1)
{
  FILE * f;
  signed char fileid;
  fileid = (signed char)rt_roundd_snf(varargin_1);
  if ((fileid < 0) || (varargin_1 != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = eml_openfiles[fileid - 3];
  } else if (fileid == 0) {
    f = stdin;
  } else if (fileid == 1) {
    f = stdout;
  } else if (fileid == 2) {
    f = stderr;
  } else {
    f = NULL;
  }

  return f;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void filedata_init(void)
{
  FILE * a;
  int i;
  a = NULL;
  for (i = 0; i < 20; i++) {
    eml_autoflush[i] = false;
    eml_openfiles[i] = a;
  }

  fis_virtual_fs_init();
}
