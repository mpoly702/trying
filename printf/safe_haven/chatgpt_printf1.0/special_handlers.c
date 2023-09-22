#include "main.h"

/**
 * specifier_get - This finds thefunction of format
 * @s: string of format
 *
 * Return: no of bytes that was  printed
 */

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
/**
 * flg_get - Parse and set flags based on the format string
 *
 * This function takes a character pointer pointing to a format specifier and
 * updates the flags in the parameter structure based on the flags found in
 * the format specifier.
 *
 * @param s: Pointer to the format specifier.
 * @param pmtrs: Pointer to the parameter structure to update.
 *
 * @return: The number of flags set.
 */
int flg_get(char *s, pmtrs_t *pmtrs)
{
    int x = 0;

    /*Iterate through the format specifier character by character*/
    while (*s)
    {
        switch (*s)
        {
            case '+':
                pmtrs->flg_pls = 1;
                x++;
                break;
            case ' ':
                pmtrs->flg_sp = 1;
                x++;
                break;
            case '#':
                pmtrs->flg_htag = 1;
                x++;
                break;
            case '-':
                pmtrs->flg_ms = 1;
                x++;
                break;
            case '0':
                pmtrs->flg_z = 1;
                x++;
                break;
            default:
                return x; /*Return the number of flags set*/
        }
        s++;
    }

    return x; /*Return the number of flags set*/
}

/**
 * modi_get - Parse and set modifier flags based on the format string
 *
 * This function takes a character pointer pointing to a format specifier and
 * updates the modifier flags in the parameter structure based on the
 * modifiers found in the format specifier.
 *
 * @param s: Pointer to the format specifier.
 * @param pmtrs: Pointer to the parameter structure to update.
 *
 * @return: 1 if a valid modifier was found and set, 0 otherwise.
 */
int modi_get(char *s, pmtrs_t *pmtrs)
{
    int i = 0;

    /*Check for 'h' modifier*/
    if (*s == 'h')
    {
        pmtrs->modi_h = 1;
        i = 1;
    }
    // Check for 'l' modifier
    else if (*s == 'l')
    {
        pmtrs->modi_l = 1;
        i = 1;
    }

    return i; /*Return 1 if a valid modifier was found and set, 0 otherwise.*/
}


/**
 * width_get - Parse and set the width from the format string
 *
 * This function takes a character pointer pointing to a format specifier and
 * extracts the width information from it. It can handle both explicit width
 * values and '*' for dynamic width. The extracted width is stored in the
 * parameter structure.
 *
 * @param s: Pointer to the format specifier.
 * @param pmtrs: Pointer to the parameter structure to update.
 * @param args: Variable argument list.
 *
 * @return: A new pointer pointing to the character after the width specification.
 */
char *width_get(char *s, pmtrs_t *pmtrs, va_list args) {
    int y = 0;

    if (*s == '*') {
        y = va_arg(args, int);
        s++;
    } else {
        while (*s >= '0' && *s <= '9') {
            y = y * 10 + (*s - '0');
            s++;
        }
    }

    pmtrs->width = y;
    return s; // Return a new pointer pointing to the character after the width specification.
}


