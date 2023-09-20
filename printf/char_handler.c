#include "main.h"

/**
 * print_char - prints a char.
 * @val: arguments.
 * Return: 1.
 */

int print_Char(va_list val) 
{
    char s = va_arg(val, int);
    putchar(s);
    return 1;
}
