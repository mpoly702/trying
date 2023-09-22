#include "main.h"

/**comments**/

int (*specifier_get(char *s))(va_list args, pmtrs_t *pmtrs) {
    ind_t indicators[] = {
        {"c", print_ch},
        {"d", print_integer},
        {"i", print_integer},
        {"s", print_str1},
        {"%", print_per},
        {"b", binary_out},
        {"o", octal_out},
        {"u", usg_print},
        {"x", hexa_print},
        {"X", HEXA_print},
        {"p", print_locate},
        {"S", print_SOS},
        {"r", rev_str},
        {"R", print_root},
        {NULL, NULL}
    };

    int i = 0;

    while (indicators[i].indicator) {
        if (*s == indicators[i].indicator[0]) {
            return (indicators[i].f);
        }
        i++;
    }
    return (NULL);
}
int flg_get(char *s, pmtrs_t *pmtrs) {
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
    return (x);
}
/*comment*/
int modi_get(char *s, pmtrs_t *pmtrs) {
    int i = 0;

    switch (*s) {
        case 'h':
            i = pmtrs->modi_h = 1;
            break;
        case 'l':
            i = pmtrs->modi_l = 1;
            break;
    }
    return (i);
}
/*comments*/
char *width_get(char *s, pmtrs_t *pmtrs, va_list args) {
    int y = 0;

    if (*s == '*') {
        y = va_arg(args, int);
        s++;
    } else {
        while (_Adigit(*s))
            y = y * 10 + (*s++ - '0');
    }
    pmtrs->width = y;
    return (s);
}

