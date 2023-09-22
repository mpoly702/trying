#include "main.h"
/**comments for the function here**/
int print_integer(va_list args, pmtrs_t *pmtrs)
{
    long li;
    
    if (pmtrs->modi_l)
        li = va_arg(args, long);
    else if (pmtrs->modi_h)
        li = (short int)va_arg(args, int);
    else
        li = (int)va_arg(args, int);
    
    char *str = transform(li, 10, 0, pmtrs); // Convert integer to string
    int add = _puts(str); // Output the string
    free(str); // Free allocated memory
    
    return add;
}
/**
 * print_ch - Print a character with padding
 * @args: Argument pointer
 * @pmtrs: Parameters structure
 *
 * Return: The number of characters printed
 */
int print_ch(va_list args, pmtrs_t *pmtrs)
{
    char pad_ch = ' ';
    unsigned int padd = 1, add = 0;
    char ch = va_arg(args, int);

    if (pmtrs->flg_ms)
    {
        // Output the character first
        if (pmtrs->width > 1)
        {
            add += _putchar(ch);
            pmtrs->width--;
        }
        else
        {
            return _putchar(ch);
        }
    }

    while (padd++ < pmtrs->width)
        add += _putchar(pad_ch); // Output padding characters

    if (!pmtrs->flg_ms)
    {
        // Output the character last
        if (pmtrs->width > 1)
        {
            add += _putchar(ch);
            pmtrs->width--;
        }
        else
        {
            return _putchar(ch);
        }
    }

    return add;
}

/**
 * print_str1 - Print a string with padding
 * @args: Argument pointer
 * @pmtrs: Parameters structure
 *
 * Return: The number of characters printed
 */
int print_str1(va_list args, pmtrs_t *pmtrs)
{
    char *str = va_arg(args, char *), pad_ch = ' ';
    unsigned int padd = 0, add = 0, i = 0, j;
    
    if (!str)
        str = "(null)";

    padd = _strlen(str);

    if (pmtrs->precision != UINT_MAX && pmtrs->precision < padd)
        padd = pmtrs->precision;

    j = padd;

    if (pmtrs->flg_ms)
    {
        while (i < padd)
        {
            add += _putchar(*str++);
            i++;
        }
    }

    while (j++ < pmtrs->width)
        add += _putchar(pad_ch);

    if (!pmtrs->flg_ms)
    {
        while (i < padd)
        {
            add += _putchar(*str++);
            i++;
        }
    }

    return add;
}

/**comment**/
/**
 * print_SOS - Print a string with escape sequences for non-printable characters
 * @args: Argument pointer
 * @pmtrs: Parameters structure
 *
 * Return: The number of characters printed
 */
int print_SOS(va_list args, pmtrs_t *pmtrs)
{
    char *str = va_arg(args, char *);
    char hexa[3];
    int add = 0;

    if (!str)
        return _puts(STR_NIL);

    while (*str)
    {
        if ((*str > 0 && *str < 32) || *str >= 127)
        {
            add += _putchar('\\');
            add += _putchar('x');

            hexa[0] = '0';
            hexa[1] = '0';
            hexa[2] = '\0';

            transform_hexa(hexa, *str);

            add += _puts(hexa);
        }
        else
        {
            add += _putchar(*str);
        }

        str++;
    }

    return add;
}

/**
 * transform_hexa - Transform an integer to a hexadecimal string
 * @hexa: Hexadecimal string buffer (at least 3 characters)
 * @value: Value to convert to hexadecimal
 */
void transform_hexa(char *hexa, int value)
{
    const char *digits = "0123456789ABCDEF";
    hexa[0] = digits[(value >> 4) & 0xF];
    hexa[1] = digits[value & 0xF];
}
