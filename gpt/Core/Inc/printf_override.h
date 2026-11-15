/**
  ******************************************************************************
  * @file    printf_override.h
  * @brief   Header for printf override functionality
  ******************************************************************************
  */

#ifndef PRINTF_OVERRIDE_H
#define PRINTF_OVERRIDE_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function to enable/disable printf suppression during fuzzy execution */
void printf_override_set_suppress(bool suppress);

#ifdef __cplusplus
}
#endif

#endif /* PRINTF_OVERRIDE_H */




