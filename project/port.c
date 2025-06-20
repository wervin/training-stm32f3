#include <stdio.h>
#include "ll/usart.h"

static int _putc(char c, FILE *file)
{
    (void)file;
    ll_usart_putc(USART1, c);
    return c;
}

static int _getc(FILE *file)
{
    unsigned char c;
    (void)file;
    c = ll_usart_getc(USART1);
    return c;
}

static FILE __stdio = FDEV_SETUP_STREAM(_putc,
                                        _getc,
                                        NULL,
                                        _FDEV_SETUP_RW);

FILE *const stdin = &__stdio;
__strong_reference(stdin, stdout);
__strong_reference(stdin, stderr);
