#include "main.h"

int process_specifier(char specifier, va_list args, pmtrs_t *pmtrs) {
    int (*f)(va_list, pmtrs_t *) = get_handler(specifier);

    if (f)
        return f(args, pmtrs);

    return 0;
}

int (*get_handler(char specifier))(va_list args, pmtrs_t *pmtrs) {
    struct {
        char indicator;
        int (*f)(va_list args, pmtrs_t *pmtrs);
    } handlers[] = {
        {'c', print_char},
        {'d', print_integer},
        {'i', print_integer},
        {'s', print_string},
        {'%', print_percent},
        {'x', print_hexadecimal},
        {'X', print_hexadecimal},
        {'o', print_octal},
        {'u', print_unsigned},
        {'b', print_binary},
        {'p', print_pointer},
        {'S', print_special_string},
        {'r', print_reverse},
        {'R', print_rot13},
        {0, NULL},
    };

    int i = 0;

    while (handlers[i].indicator) {
        if (specifier == handlers[i].indicator)
            return handlers[i].f;
        i++;
    }

    return NULL;
}

