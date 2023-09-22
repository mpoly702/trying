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
/**comments for function here**/
int print_ch(va_list args, pmtrs_t *pmtrs)
{
    char pad_ch = ' ';
    unsigned int padd = 1, add = 0;
    char ch = va_arg(args, int);
    
    if (pmtrs->flg_ms)
        add += _putchar(ch); // Output the character first
    
    while (padd++ < pmtrs->width)
        add += _putchar(pad_ch); // Output padding characters
    
    if (!pmtrs->flg_ms)
        add += _putchar(ch); // Output the character last
    
    return add;
}
/**comments for function here**/
int print_str1(va_list args, pmtrs_t *pmtrs)
{
    char *str = va_arg(args, char *);
    char pad_ch = ' ';
    unsigned int padd = 0, add = 0, i = 0, j;
    (void)pmtrs;
    
    if (!str)
        str = STR_NIL;
    
    j = padd = _strlen(str);
    if (pmtrs->precision < padd)
        j = padd = pmtrs->precision;
    
    if (pmtrs->flg_ms)
    {
        for (i = 0; i < padd; i++)
            add += _putchar(*str++); // Output characters within precision
    }
    
    while (j++ < pmtrs->width)
        add += _putchar(pad_ch); // Output padding characters based on width
    
    if (!pmtrs->flg_ms)
    {
        str -= padd;
        for (i = 0; i < padd; i++)
            add += _putchar(*str++); // Output characters within precision
    }
    
    return add;
}
/**comment**/
int print_SOS(va_list args, pmtrs_t *pmtrs)
{
    char *str = va_arg(args, char *);
    int add = 0;
    
    if (!str)
        return _puts(STR_NIL); // Handle NULL string
    
    while (*str)
    {
        if ((*str < 32 && *str >= 0) || *str >= 127)
        {
            add += _putchar('\\');
            add += _putchar('x');
            char *hexa = transform(*str, 16, 0, pmtrs); // Convert character to hexadecimal
            
            if (!hexa)
                add += _putchar('0');

