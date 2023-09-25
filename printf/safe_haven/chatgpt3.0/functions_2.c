#include "main.h"


int print_integer(va_list args, pmtrs_t *pmtrs) {
    long li;

    if (pmtrs->modi_l)
        li = va_arg(args, long);
    else if (pmtrs->modi_h)
        li = (short int)va_arg(args, int);
    else
        li = (int)va_arg(args, int);

    return _puts(transform(li, 10, 0, pmtrs));
}

int print_char(va_list args, pmtrs_t *pmtrs) {
    char pad_ch = ' ';
    int padd = 1, add = 0, ch = va_arg(args, int);

    if (pmtrs->flg_ms)
        add += _putchar(ch);

    while (padd++ < pmtrs->width)
        add += _putchar(pad_ch);

    if (!pmtrs->flg_ms)
        add += _putchar(ch);

    return add;
}

int print_string(va_list args, pmtrs_t *pmtrs) {
    char *str = va_arg(args, char *);
    char pad_ch = ' ';
    unsigned int padd = 0, add = 0, i = 0, j;
    (void)pmtrs;

    switch ((int)(!str)) {
        case 1:
            str = STR_NIL;
            j = padd = _puts(str);

            if (pmtrs->precision < padd)
                j = padd = pmtrs->precision;

            if (pmtrs->flg_ms) {
                if (pmtrs->precision != 4294967295U)
                    for (i = 0; i < padd; i++)
                        add += _putchar(*str++);
                else
                    add += _puts(str);
            }

            while (j++ < pmtrs->width)
                add += _putchar(pad_ch);

            if (!pmtrs->flg_ms) {
                if (pmtrs->precision != 4294967295U)
                    for (i = 0; i < padd; i++)
                        add += _putchar(*str++);
                else
                    add += _puts(str);
            }

            return add;
    }

    return add;
}

int print_percent(va_list args, pmtrs_t *pmtrs) {
    (void)args;
    (void)pmtrs;
    return _putchar('%');
}



