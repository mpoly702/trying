#include "main.h"

int print_w(char *begin, char *end, char *except)
{
    int add = 0;

    while (begin <= end)
    {
        if (begin != except)
        {
            char ch = *begin;
            // Output the character
            add += _putchar(ch);
        }
        begin++;
    }
    return add;
}

/**comments here for next function**/

int rev_str(va_list args, pmtrs_t *pmtrs)
{
    int add = 0;
    char *str = va_arg(args, char *);
    (void)pmtrs;

    if (str)
    {
        // Calculate the length of the string
        int len = 0;
        while (str[len] != '\0')
        {
            len++;
        }

        // Output characters in reverse order
        for (int i = len - 1; i >= 0; i--)
        {
            add += _putchar(str[i]);
        }
    }

    return add;
}

/**comments here for next function**/

int print_root(va_list args, pmtrs_t *pmtrs)
{
    int i, indice;
    int count = 0;
    char array[] = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
    char *a = va_arg(args, char *);
    (void)pmtrs;

    i = 0;
    indice = 0;

    while (a[i])
    {
        if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
        {
            if (a[i] >= 'A' && a[i] <= 'Z')
                indice = a[i] - 'A';
            else
                indice = a[i] - 'a' + 26;

            count += _putchar(array[indice]);
        }
        else
        {
            count += _putchar(a[i]);
        }
        i++;
    }
    return count;
}
