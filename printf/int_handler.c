#include <stdarg.h>

void printIntegerFromVarArgs(va_list args) {
    int num = va_arg(args, int);
    char buffer[12]; // Assuming a maximum of 11 digits for an integer (+1 for null-terminator)

    // Handle negative numbers
    if (num < 0) {
        putchar('-');
        num = -num;
    }

    // Convert the integer to a character array
    int i = 10;
    buffer[11] = '\0'; // Null-terminate the string
    do {
        buffer[i--] = '0' + (num % 10);
        num /= 10;
    } while (num > 0);

    // Print the character array
    while (buffer[++i] != '\0') {
        putchar(buffer[i]);
    }
}

int main() {
    int num = 42;

    // Pass the integer as an argument to the function
    printIntegerFromVarArgs(num);

    return 0;
}

