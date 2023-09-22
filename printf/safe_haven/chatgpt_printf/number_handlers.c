#include "main.h"

int print_w(char *begin, char *end, char *except)
{
    int add = 0;

    while (begin <= end)
    {
        if (begin != except)
        {
            _putchar(*begin); // Output the character
            add++;
        }
        begin++;
    }
    return (add); // Return the number of characters displayed
}

/**comments here for next function**/

int rev_str(va_list args, pmtrs_t *pmtrs)
{
    int li, add = 0;
    char *str = va_arg(args, char *);
    (void)pmtrs;

    if (str)
    {
        for (li = 0; *str; str++)
            li++;
        str--;
        for (; li > 0; li--, str--)
        {
            _putchar(*str); // Output the character in reverse order
            add++;
        }
    }
    return (add); // Return the number of bytes printed
}

/**comments here for next function**/

int print_root(va_list args, pmtrs_t *pmtrs)
{
    int i, count = 0;
    char array[] = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
    char *a = va_arg(args, char *);
    (void)pmtrs;

    i = 0;

    while (a[i])
    {
        if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
        {
            int index = (a[i] >= 'A' && a[i] <= 'Z') ? (a[i] - 'A') : (a[i] - 'a' + 26);
            _putchar(array[index]); // Output ROT13 encoded character
            count++;
        }
        else
        {
            _putchar(a[i]); // Output character as is
            count++;
        }
        i++;
    }
    return (count); // Return the number of bytes printed
}
/**comments here for next function**/


