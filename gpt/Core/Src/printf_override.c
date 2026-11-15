/**
  ******************************************************************************
  * @file    printf_override.c
  * @brief   Override _write() to conditionally disable printf output
  ******************************************************************************
  * 
  * On STM32, printf() goes through _write() which calls __io_putchar().
  * We override _write() to conditionally suppress output when a flag is set.
  * This allows us to disable MATLAB-generated debug prints during fuzzy execution
  * while still allowing result printing.
  * 
  * To enable all debug output, define FUZZY_DEBUG=1 in your build configuration.
  */

#include "printf_override.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

/* Forward declaration */
extern int __io_putchar(int ch);

/* Check if debug is disabled */
#ifndef FUZZY_DEBUG
#define FUZZY_DEBUG 0
#endif

/* Global flag to suppress printf output during fuzzy execution */
/* Use volatile to prevent compiler optimization from removing the check */
static volatile bool g_suppress_printf = false;

/* Function to enable/disable printf suppression */
void printf_override_set_suppress(bool suppress)
{
    g_suppress_printf = suppress;
}

#if !FUZZY_DEBUG
/* Override _write() to conditionally suppress output */
/* _write() is marked as weak in syscalls.c, so our version will override it */
/* We don't mark it as weak ourselves - we want to override the weak version */
int _write(int file, char *ptr, int len)
{
    /* If suppression is enabled, return immediately without writing */
    if (g_suppress_printf)
    {
        (void)file;
        (void)ptr;
        (void)len;
        return len;  // Return success but don't write anything
    }
    
    /* Otherwise, write normally using __io_putchar */
    /* This is the same implementation as syscalls.c, but we control it */
    for (int i = 0; i < len; i++)
    {
        __io_putchar(ptr[i]);
    }
    return len;
}
#endif /* !FUZZY_DEBUG */
