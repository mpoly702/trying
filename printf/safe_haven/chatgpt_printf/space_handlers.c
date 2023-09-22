/**
 * printNumber - Helper function to print a number with options
 * @str: String representation of the number
 * @pmtrs: Parameters structure
 *
 * Return: Number of characters printed
 */
int printNumber(char *str, pmtrs_t *pmtrs) {
    unsigned int i = _strlen(str);
    int totalPrinted = 0;

    // Handle special cases where precision affects the output
    if (pmtrs->precision != UINT_MAX) {
        while (i++ < pmtrs->precision) {
            totalPrinted += _putchar('0');
        }
    }

    // Handle the sign character
    char sign = *str;
    if (sign == '-' || sign == '+') {
        totalPrinted += _putchar(sign);
        str++;
        i--;
    }

    // Handle zero padding or space padding
    char padChar = (pmtrs->flg_z && !pmtrs->flg_ms) ? '0' : ' ';
    if (pmtrs->width > i) {
        int padding = pmtrs->width - i;
        while (padding--) {
            totalPrinted += _putchar(padChar);
        }
    }

    // Print the actual number
    while (*str) {
        totalPrinted += _putchar(*str++);
    }

    return totalPrinted;
}

/**
 * print_num - Print a number with options
 * @str: String representation of the number
 * @pmtrs: Parameters structure
 *
 * Return: Number of characters printed
 */
int print_num(char *str, pmtrs_t *pmtrs) {
    // Handle the '0' precision case
    if (pmtrs->precision == 0 && *str == '0' && !str[1]) {
        return 0;
    }

    // Determine whether left or right alignment is required
    if (!pmtrs->flg_ms) {
        return printNumber(str, pmtrs);
    } else {
        // Left alignment, simply print the number
        int totalPrinted = 0;
        while (*str) {
            totalPrinted += _putchar(*str++);
        }
        // Add padding on the right if needed
        while (totalPrinted < pmtrs->width) {
            totalPrinted += _putchar(' ');
        }
        return totalPrinted;
    }
}

/**
 * print_shift - Print a number with right alignment
 * @str: String representation of the number
 * @pmtrs: Parameters structure
 *
 * Return: Number of characters printed
 */
int print_shift(char *str, pmtrs_t *pmtrs) {
    // Right alignment
    return printNumber(str, pmtrs);
}

/**
 * print_left - Print a number with left alignment
 * @str: String representation of the number
 * @pmtrs: Parameters structure
 *
 * Return: Number of characters printed
 */
int print_left(char *str, pmtrs_t *pmtrs) {
    // Left alignment
    return printNumber(str, pmtrs);
}

/**comment**/
/**
 * _strlen - Returns the length of a string
 * @s: The input string
 *
 * Return: The length of the string
 */
int _strlen(const char *s) {
    int length = 0;
    
    // Iterate through the string until the null terminator is encountered
    while (s[length] != '\0') {
        length++;
    }
    
    return length;
}


