#include "main.h"

/**
 * transform - Convert a number to a string representation with custom flags
 * @num: The number to convert
 * @base: The base for conversion (e.g., 10 for decimal, 16 for hexadecimal)
 * @flags: Custom flags (e.g., LOWER_CASE for lowercase hexadecimal)
 * @pmtrs: Parameter structure (not used in this function)
 *
 * Return: The string representation of the number
 */
char *transform(long int num, int base, int flags)
{
    static char buffer[50];
    char *arr = (flags & LOWER_CASE) ? "0123456789abcdef" : "0123456789ABCDEF";
    char *ptr = &buffer[49];
    *ptr = '\0';

    if (num < 0) {
        *ptr = '-';
        num = -num;
    }

    do {
        *--ptr = arr[num % base];
        num /= base;
    } while (num != 0);

    return ptr;
}

/**
 * usg_print - Print an unsigned integer with custom formatting
 * @args: Argument pointer
 * @pmtrs: Parameter structure
 *
 * Return: Number of bytes printed
 */
int usg_print(va_list args, pmtrs_t *pmtrs)
{
    unsigned long int num;
    
    if (pmtrs->modi_l)
        num = va_arg(args, unsigned long);
    else if (pmtrs->modi_h)
        num = (unsigned short int)va_arg(args, unsigned int);
    else
        num = (unsigned int)va_arg(args, unsigned int);

    pmtrs->usg = 1;
    return print_num(transform(num, 10, USG_CONVT, pmtrs), pmtrs);
}

/**
 * print_locate - Print the address of a pointer
 * @args: Argument pointer
 * @pmtrs: Parameter structure
 *
 * Return: Number of bytes printed
 */
int print_locate(va_list args, pmtrs_t *pmtrs)
{
    unsigned long int addr = va_arg(args, unsigned long int);
    char *str;

    if (!addr)
        return _puts("(nil)");

    str = transform(addr, 16, USG_CONVT | LOWER_CASE, pmtrs);
    *--str = 'x';
    *--str = '0';

    return print_num(str, pmtrs);
}
