#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

// Custom dprintf function
char* dprintf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    // Calculate the size needed for the formatted string
    int size = vsnprintf(NULL, 0, format, args);
    if (size < 0) {
        va_end(args);
        return NULL; // vsnprintf error
    }

    // Allocate memory for the formatted string
    char* buffer = (char*)malloc((size + 1) * sizeof(char));
    if (buffer == NULL) {
        va_end(args);
        return NULL; // Memory allocation error
    }

    // Format the string into the allocated buffer
    vsnprintf(buffer, size + 1, format, args);

    va_end(args);
    return buffer;
}

int main() {
    // Usage example
    char* result = dprintf("Hello, %s! The answer is %d.\n", "John", 42);
    if (result != NULL) {
        printf("%s", result);
        free(result); // Don't forget to free the allocated memory
    } else {
        printf("Error: Memory allocation or formatting error\n");
    }

    return 0;
}
