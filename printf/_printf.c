#include "main.h"

typedef int (*PrintfFunction)(va_list);

typedef struct {
    const char *id;
    PrintfFunction f;
} ConvertMatch;

int _printf(const char *const format, ...) {
    ConvertMatch m[] = {
        {"%s", printf_string}, {"%c", printf_char},
        {"%%", printf_37}, {"%i", printf_int},
        {"%d", printf_dec}, {"%r", printf_srev},
        {"%R", printf_rot13}, {"%b", printf_bin},
        {"%u", printf_unsigned}, {"%o", printf_oct},
        {"%x", printf_hex}, {"%X", printf_HEX},
        {"%S", printf_exclusive_string}, {"%p", printf_pointer}
    };

    va_list args;
    int i = 0, j, len = 0;

    va_start(args, format);

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    while (format[i] != '\0') {
        int match_found = 0;
        j = 13;

        while (j >= 0) {
            if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1]) {
                len += m[j].f(args);
                i = i + 2;
                match_found = 1;
                break;
            }
            j--;
        }

        if (!match_found) {
            _putchar(format[i]);
            len++;
            i++;
        }
    }

    va_end(args);
    return (len);
}
