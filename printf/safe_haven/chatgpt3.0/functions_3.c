#include "main.h"

int print_hexadecimal(va_list args, pmtrs_t *pmtrs) {
    unsigned long li;
    char *str;
    (void)pmtrs;

    if (pmtrs->modi_l)
        li = (unsigned long)va_arg(args, unsigned long);
    else if (pmtrs->modi_h)
        li = (unsigned short int)va_arg(args, unsigned int);
    else
        li = (unsigned int)va_arg(args, unsigned int);

    str = transform(li, 16, 2, pmtrs);

    if (pmtrs->flg_htag && li) {
        *--str = 'x';
        *--str = '0';
    }

    pmtrs->usg = 1;
    return _puts(str);
}

int print_octal(va_list args, pmtrs_t *pmtrs) {
    unsigned long li;
    char *str;
    (void)pmtrs;

    if (pmtrs->modi_l)
        li = (unsigned long)va_arg(args, unsigned long);
    else if (pmtrs->modi_h)
        li = (unsigned short int)va_arg(args, unsigned int);
    else
        li = (unsigned int)va_arg(args, unsigned int);

    str = transform(li, 8, 2, pmtrs);

    if (pmtrs->flg_htag && li)
        *--str = '0';

    pmtrs->usg = 1;
    return _puts(str);
}

int print_unsigned(va_list args, pmtrs_t *pmtrs) {
    unsigned long li;
    
    if (pmtrs->modi_l)
        li = (unsigned long)va_arg(args, unsigned long);
    else if (pmtrs->modi_h)
        li = (unsigned short int)va_arg(args, unsigned int);
    else
        li = (unsigned int)va_arg(args, unsigned int);

    pmtrs->usg = 1;
    return _puts(transform(li, 10, 2, pmtrs));
}

int print_binary(va_list args, pmtrs_t *pmtrs) {
    unsigned int x = va_arg(args, unsigned int);
    char *str = transform(x, 2, 2, pmtrs);

    if (pmtrs->flg_htag && x)
        *--str = '0';

    pmtrs->usg = 1;
    return _puts(str);
}

