#include "main.h"

int get_flags(const char *s, pmtrs_t *pmtrs) {
    int x = 0;

    switch (*s) {
        case '+':
            x = pmtrs->flg_pls = 1;
            break;
        case ' ':
            x = pmtrs->flg_sp = 1;
            break;
        case '#':
            x = pmtrs->flg_htag = 1;
            break;
        case '-':
            x = pmtrs->flg_ms = 1;
            break;
        case '0':
            x = pmtrs->flg_z = 1;
            break;
    }

    return x;
}

int get_modifiers(const char *s, pmtrs_t *pmtrs) {
    int i = 0;

    switch (*s) {
        case 'h':
            i = pmtrs->modi_h = 1;
            break;
        case 'l':
            i = pmtrs->modi_l = 1;
            break;
    }

    return i;
}

const char *get_width(const char *s, pmtrs_t *pmtrs, va_list args) {
    int y = 0;

    if (*s == '*') {
        y = va_arg(args, int);
        s++;
    } else {
        while (*s >= '0' && *s <= '9')
            y = y * 10 + (*s++ - '0');
    }

    pmtrs->width = y;
    return s;
}

const char *get_precision(const char *s, pmtrs_t *pmtrs, va_list args) {
    int y = 0;

    if (*s != '.')
        return s;

    s++;

    if (*s == '*') {
        y = va_arg(args, int);
        s++;
    } else {
        while (*s >= '0' && *s <= '9')
            y = y * 10 + (*s++ - '0');
    }

    pmtrs->precision = y;
    return s;
}
