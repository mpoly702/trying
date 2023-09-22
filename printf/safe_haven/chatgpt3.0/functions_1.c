#include "main.h"

int _putchar(char c) {
    static int i = 0;
    static char buf[SIZE_BUF];

    if (c == -1 || i >= SIZE_BUF) {
        write(1, buf, i);
        i = 0;
    }

    if (c != -1)
        buf[i++] = c;

    return 1;
}

int _puts(char *str) {
    char *a = str;
    while (*str)
        _putchar(*str++);

    return str - a;
}

char *transform(long int num, int base, int flags, pmtrs_t *pmtrs) {
    static char buffer[50];
    char *arr;
    char sign = 0;
    char *ptr;
    unsigned long x = num;

    if (!(flags & 0x01) && num < 0) {
        x = -num;
        sign = '-';
    }

    arr = (flags & 0x02) ? "0123456789ABCDEF" : "0123456789abcdef";
    ptr = &buffer[49];
    *ptr = '\0';

    do {
        *--ptr = arr[x % base];
        x /= base;
    } while (x != 0);

    if (sign)
        *--ptr = sign;

    return ptr;
}

void init_pmtrs(pmtrs_t *pmtrs, va_list args) {
    pmtrs->usg = 0;
    pmtrs->flg_pls = 0;
    pmtrs->flg_sp = 0;
    pmtrs->flg_htag = 0;
    pmtrs->flg_z = 0;
    pmtrs->flg_ms = 0;
    pmtrs->width = 0;
    pmtrs->precision = 4294967295U; // Equivalent to UINT_MAX
    pmtrs->modi_h = 0;
    pmtrs->modi_l = 0;
    (void)args;
}



