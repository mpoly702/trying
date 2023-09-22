#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: The input string
 *
 * Return: The length of the string
 */
int _strlen(const char *s) {
    int length = 0;
    
    /*Iterate through the string until the null terminator is encountered*/
    while (s[length] != '\0') {
        length++;
    }
    
    return length;
}

/**
 * print_shift - Print a string with custom formatting and alignment
 * @str: The string to print
 * @pmtrs: Parameter structure
 *
 * Return: Number of bytes printed
 */
int print_shift(char *str, pmtrs_t *pmtrs)
{
    unsigned int x = 0;
    int gen = 0;
    int gen2 = 0;
    unsigned int i = 0;
    char pad_ch = ' ';
    
    /*Calculate the length of the string*/
    while (str[i])
        i++;

    if (pmtrs->flg_z && !pmtrs->flg_ms)
        pad_ch = '0';

    if (!pmtrs->usg && *str == '-') {
        gen = 1;
        str++;
        i--;
    }

    if (gen && i < pmtrs->width && pad_ch == '0' && !pmtrs->flg_ms) {
        str++;
    } else {
        gen = 0;
    }

    if ((pmtrs->flg_pls && !gen2) || (!pmtrs->flg_pls && pmtrs->flg_sp && !gen2)) {
        i++;
    }

    if (gen && pad_ch == '0') {
        x += _putchar('-');
    }

    if (pmtrs->flg_pls && !gen2 && pad_ch == '0' && !pmtrs->usg) {
        x += _putchar('+');
    } else if (!pmtrs->flg_pls && pmtrs->flg_sp && !gen2 && !pmtrs->usg && pmtrs->flg_z) {
        x += _putchar(' ');
    }

    while (i < pmtrs->width) {
        x += _putchar(pad_ch);
        i++;
    }

    if (gen && pad_ch == ' ') {
        x += _putchar('-');
    }

    if (pmtrs->flg_pls && !gen2 && pad_ch == ' ' && !pmtrs->usg) {
        x += _putchar('+');
    } else if (!pmtrs->flg_pls && pmtrs->flg_sp && !gen2 && !pmtrs->usg && !pmtrs->flg_z) {
        x += _putchar(' ');
    }

    /*Print the string character by character*/
    while (*str) {
        x += _putchar(*str);
        str++;
    }

    return x;
}

/**
 * print_num - Print a number with custom formatting and alignment
 * @str: The number as a string
 * @pmtrs: Parameter structure
 *
 * Return: Number of bytes printed
 */
int print_num(char *str, pmtrs_t *pmtrs)
{
    unsigned int i = 0;
    int gen = 0;

    /*Calculate the length of the string*/
    while (str[i])
        i++;

    if (!pmtrs->precision && *str == '0' && !str[1]) {
        str = "";
    }

    if (!pmtrs->usg && *str == '-') {
        gen = 1;
        str++;
        i--;
    }

    if (pmtrs->precision != UINT_MAX) {
        while (i < pmtrs->precision) {
            *--str = '0';
            i++;
        }
    }

    if (gen) {
        *--str = '-';
    }

    if (!pmtrs->flg_ms) {
        return print_shift(str, pmtrs);
    } else {
        return print_left(str, pmtrs);
    }
}

/**
 * print_left - Print a string with left alignment and custom padding
 * @str: The string to print
 * @pmtrs: Parameter structure
 *
 * Return: Number of bytes printed
 */
int print_left(char *str, pmtrs_t *pmtrs)
{
    unsigned int x = 0, gen, gen2, i = 0;
    char pad_ch = ' ';

    /*Calculate the length of the string*/
    while (str[i])
        i++;

    if (pmtrs->flg_z && !pmtrs->flg_ms)
        pad_ch = '0';

    gen = gen2 = (!pmtrs->usg && *str == '-');

    if (gen && i < pmtrs->width && pad_ch == '0' && !pmtrs->flg_ms)
        str++;
    else
        gen = 0;

    if (pmtrs->flg_pls && !gen2 && !pmtrs->usg)
        x += _putchar('+'), i++;
    else if (pmtrs->flg_sp && !gen2 && !pmtrs->usg)
        x += _putchar(' '), i++;

    x += _puts(str);

    while (i++ < pmtrs->width)
        x += _putchar(pad_ch);

    return x;
}

/**
 * _Adigit - Check if a character is a digit
 * @c: The character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int _Adigit(int c)
{
    return (c >= '0' && c <= '9');
}
