#include <stdio.h>

#include "fis_virtual_fs.h"

#if defined(ARDUINO)

FILE *fopen(const char *path, const char *mode)
{
    return fis_virtual_fs_cfopen(path, mode, -1);
}

#endif /* ARDUINO */

