#include "main.h"

int print_pointer(va_list args, pmtrs_t *pmtrs) {
    unsigned long int x = va_arg(args, unsigned long int);
    char *str;

    if (!x)
        return _puts("(nil)");

    str = transform(x, 16, 3, pmtrs);
    *--str = 'x';
    *--str = '0';

    return _puts(str);
}

int print_special_string(va_list args, pmtrs_t *pmtrs) {
    char *str = va_arg(args, char *);
    char *hexa;
    int add = 0;

    if ((int)(!str))
        return _puts(STR_NIL);

    for (; *str; str++) {
        if ((*str > 0 && *str < 32) || *str >= 127) {
            add += _putchar('\\');
            add += _putchar('x');
            hexa = transform(*str, 16, 0, pmtrs);

            if (!hexa)
                add += _putchar('0');

            add += _puts(hexa);
        } else {
            add += _putchar(*str);
        }
    }

    return add;
}

int print_reverse(va_list args, pmtrs_t *pmtrs) {
    int li, add = 0;
    char *str = va_arg(args, char *);
    (void)pmtrs;

    if (str) {
        for (li = 0; *str; str++)
            li++;

        str--;

        for (; li > 0; li--, str--)
            add += _putchar(*str);
    }

    return add;
}

int print_rot13(va_list args, pmtrs_t *pmtrs) {
    int i, indice;
    int count = 0;
    char array[] = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
    char *a = va_arg(args, char *);
    (void)pmtrs;

    i = 0;
    indice = 0;

    while (a[i]) {
        if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z')) {
            indice = a[i] - 65;
            count += _putchar(array[indice]);
        } else
            count += _putchar(a[i]);

        i++;
    }

    return count;
}
