/* opkene_data.h */
#ifndef OPKENE_DATA_H
#define OPKENE_DATA_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"

#ifndef FIS_MEMFILE_ENABLE_OVERRIDES
#define FIS_MEMFILE_ENABLE_OVERRIDES
#endif
#include "memfile.h"
#include "opkene_types.h"

/* Variable Declarations */
extern FILE * eml_openfiles[20];
extern boolean_T eml_autoflush[20];
extern const boolean_T bv0[128];

#endif /* OPKENE_DATA_H */
