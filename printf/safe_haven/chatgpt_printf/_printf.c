#include "main.h"


/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
    int add = 0;  /*Counter for printed characters*/
    va_list args; /*Variable argument list*/
    char *p, *begin; /*Pointers to navigate the format string*/

    /*Initialize the pmtrs_t structure and variable argument list*/
    pmtrs_t pmtrs = INIT_PMTRS;
    va_start(args, format);

    /*Check for NULL format or empty format with '%' and ' ' (error conditions)*/
    if (!format || (format[0] == '%' && !format[1]))
        return (-1);
    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1);

    /*Loop through the format string*/
    for (p = (char *)format; *p; p++)
    {
        /*Initialize pmtrs structure for each format specifier*/
        init_pmtrs(&pmtrs, args);

        /*If not a '%', print the character and continue*/
        if (*p != '%')
        {
            if (_putchar(*p) == -1)
                return -1;
            add++;
            continue;
        }

        /*Store the beginning of the format specifier*/
        begin = p;
        p++;

        /*Loop through and process flags*/
        while (flg_get(p, &pmtrs))
        {
            p++;
        }

        /*Get width and precision values*/
        p = width_get(p, &pmtrs, args);
        p = prec_get(p, &pmtrs, args);

        /*Check for modifier and move the pointer accordingly*/
        if (modi_get(p, &pmtrs))
            p++;

        /*If there's no specifier, print the format as-is*/
        if (!specifier_get(p))
        {
            if (print_w(begin, p, pmtrs.modi_l || pmtrs.modi_h ? p - 1 : 0) == -1)
                return -1;
            add += p - begin;
        }
        else
        {
            /*Handle the format specifier and arguments*/
            add += func_get_pr(p, args, &pmtrs);
        }
    }

    /*Free any allocated buffers and clean up*/
    if (_putchar(FREE_BUF) == -1)
        return -1;
    va_end(args);

    /*Return the total number of characters printed*/
    return (add);
