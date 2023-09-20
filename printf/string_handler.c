#include "main.h"

/**
 * print_string - print a string.
 * @val: argumen t.
 * Return: the length of the string.
 */

int print_String(va_list val) 
{
    int i;
    char *s = va_arg(val, char *);
    /*Default to "(null)" length if s is NULL*/
    int len = (s != NULL) ? _strlen(s) : 6;
    for (i = 0; i < len; i++) 
    {
        _putchar((s != NULL) ? s[i] : "(null)"[i]);
    }
    return len;
}
