#include "main.h"


int custom_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int printed_chars = 0;
    pmtrs_t pmtrs;

    for (const char *s = format; *s; s++) {
        if (*s != '%') {
            _putchar(*s);
            printed_chars++;
        } else {
            s++;

            init_pmtrs(&pmtrs, args);

            while (get_flags(s, &pmtrs) || get_modifiers(s, &pmtrs) || (*s >= '0' && *s <= '9') || *s == '*' || *s == '.') {
                if (*s == '.') {
                    s = get_precision(s + 1, &pmtrs, args);
                } else if (*s == '*') {
                    pmtrs.width = va_arg(args, int);
                    s++;
                } else {
                    s = get_width(s, &pmtrs, args);
                }
            }

            char specifier = *s;

            if (specifier)
                printed_chars += process_specifier(specifier, args, &pmtrs);
        }
    }

    va_end(args);
    return printed_chars;
}
