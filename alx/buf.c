#include <stdarg.h>
#include <stdio.h>

// Maximum buffer size for the custom printf function
#define MAX_BUFFER_SIZE 1024

// Custom printf function
void my_printf(const char *format, ...) {
    char buffer[MAX_BUFFER_SIZE];
    int buffer_index = 0;

    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%' && *(format + 1)) {
            format++; // Move past '%'
            switch (*format) {
                case 'd': {
                    int num = va_arg(args, int);
                    int num_chars = sprintf(buffer + buffer_index, "%d", num);
                    buffer_index += num_chars;
                    break;
                }
                case 's': {
                    const char *str = va_arg(args, const char *);
                    int num_chars = sprintf(buffer + buffer_index, "%s", str);
                    buffer_index += num_chars;
                    break;
                }
                default:
                    buffer[buffer_index++] = *format;
            }
        } else {
            buffer[buffer_index++] = *format;
        }
        format++;
    }

    va_end(args);

    // Null-terminate the buffer
    buffer[buffer_index] = '\0';

    // Output the generated string
    printf("%s", buffer);
}

int main() {
    int num = 42;
    const char *text = "Hello, World!";
    my_printf("Number: %d, Text: %s\n", num, text);
    return 0;
}
