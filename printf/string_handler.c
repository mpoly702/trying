#include "main.h"

/**
 * print_string - print a string.
 * @val: argumen t.
 * Return: the length of the string.
 */

int print_String(va_list val) 
{
    char *s = va_arg(val, char *);
    int len = (s != NULL) ? strlen(s) : 6; // Default to "(null)" length if s is NULL

    for (int i = 0; i < len; i++) {
        putchar((s != NULL) ? s[i] : "(null)"[i]);
    }

    return len;
}
