#include "main.h"

/**
 * prec_get - Extract precision value from format string
 * @format: Format string
 * @pmtrs: Parameters structure
 * @args: Argument list
 *
 * Return: Pointer to the new position in the format string
 */
char *prec_get(const char *format, pmtrs_t *pmtrs, va_list args)
{
    int precision = 0;
    const char *p = format;

    if (*p != '.')
        return (char *)p; /*Precision not specified*/

    p++; /*Move past the '.'*/
    
    if (*p == '*') {
        /*Precision is specified by an argument*/
        int arg = va_arg(args, int);
        if (arg >= 0) 
        {
            precision = arg;
        }
        else
        {
            /*Negative precision is treated as no precision*/
            precision = UINT_MAX;
        }
        p++; /*Move past the '*'*/
    }
    else
    {
        /*Precision is specified as a numeric value*/
        while (_Adigit(*p)) 
        {
            precision = precision * 10 + (*p - '0');
            p++;
        }
    }

    pmtrs->precision = precision;
    return (char *)p;
}
