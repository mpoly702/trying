#include "main.h"
/**
* print_octal - This prints unsigned octal no
* @args: Argument
* @pmtrs: parameters
*
* Return:This is  bytes printed
*/
int octal_out(va_list args, pmtrs_t *pmtrs)
{
    unsigned long li;
    char buffer[12]; /* Assuming a maximum of 11 characters for octal representation + '\0' */
    char *str = buffer;
    int ci = 0;

    /* Retrieve the argument and convert it to octal manually */
    if (pmtrs->modi_l)
        li = (unsigned long)va_arg(args, unsigned long);
    else if (pmtrs->modi_h)
        li = (unsigned short int)va_arg(args, unsigned int);
    else
        li = (unsigned int)va_arg(args, unsigned int);

    /* Handle '0' prefix if '#' flag is set and the number is not zero */
    if (pmtrs->flg_htag && li != 0)
    {
        *str++ = '0';
    }

    /* Convert to octal manually */
    if (li == 0)
    {
        *str++ = '0';
    }
    else
    {
        while (li != 0)
        {
            *str++ = (char)('0' + (li % 8));
            li /= 8;
        }
    }

    *str = '\0';

    /* Reverse the octal string */
    int str_len;
    char *start;
    char *end;
    
    str_len = _strlen(buffer);
    *start = buffer;
    *end = buffer + str_len - 1;
    while (start < end)
    {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }

    /* Handle width manually */
    int padding;
    char pad_ch;
  
   padding = pmtrs->width - str_len;
   pad_ch = (pmtrs->flg_z && !pmtrs->flg_ms) ? '0' : ' ';
    while (padding > 0)
    {
        ci += _putchar(pad_ch);
        padding--;
    }

    /* Print the octal string */
    str = buffer; /*Reset str to the beginning of the buffer*/
    while (*str != '\0')
    {
        ci += _putchar(*str);
        str++;
    }

    pmtrs->usg = 1;
    return ci;
}


/**
* binary_out - This prints the  unsigned binary no
* @args: argument
* @pmtrs: parameter
*
* Return: This is the bytes printed
*/
int binary_out(va_list args, pmtrs_t *pmtrs)
{
    unsigned int x = va_arg(args, unsigned int);
    char buffer[33]; /*Assuming a maximum of 32-bit binary representation + '\0'*/
    char *str = buffer;
    int ci = 0;
    int i;

    /*Convert the integer to binary manually*/
    for (i = 31; i >= 0; i--)
    {
        buffer[i] = (x & 1) ? '1' : '0';
        x >>= 1;
    }
    buffer[32] = '\0';

    /*Skip leading zeros if precision is set*/
    if (pmtrs->precision != UINT_MAX)
    {
        while (*str == '0' && *(str + 1) != '\0')
        {
            str++;
        }
    }

    /*Add '0' prefix if the '#' flag is set and the number is not zero*/
    if (pmtrs->flg_htag && str[0] != '0')
    {
        ci += _putchar('0');
    }

    /*Handle width manually*/
    unsigned int str_len; 
    char pad_ch;

    str_len = _strlen(str);
    pad_ch = (pmtrs->flg_z && !pmtrs->flg_ms) ? '0' : ' ';
    while (str_len < pmtrs->width)
    {
        ci += _putchar(pad_ch);
        str_len++;
    }

    /*Print the binary string*/
    while (*str != '\0')
    {
        ci += _putchar(*str);
        str++;
    }

    pmtrs->usg = 1;
    return ci;
}

}

/**
* print_HEX - prints the unsigned hex no in uppercase
* @args: argument pointer
* @pmtrs: parameters struct
*
* Return: This is the bytes printed
*/
int HEXA_print(va_list args, pmtrs_t *pmtrs)
{
    unsigned long li;
    int ci = 0;
    char buffer[32]; /*Assuming a maximum of 32 characters for the hexadecimal representation*/
    char *str = buffer;
    
    if (pmtrs->modi_l)
        li = (unsigned long)va_arg(args, unsigned long);
    else if (pmtrs->modi_h)
        li = (unsigned short int)va_arg(args, unsigned int);
    else
        li = (unsigned int)va_arg(args, unsigned int);

    /*Convert the integer to uppercase hexadecimal manually*/
    unsigned long x = li;
    char *hex_digits = "0123456789ABCDEF";
    int digit_count = 0;
    
    do
    {
        buffer[digit_count++] = hex_digits[x % 16];
        x /= 16;
    } while (x > 0);
    
    /*Add '0X' prefix if the '#' flag is set and the number is not zero*/
    if (pmtrs->flg_htag && li != 0)
    {
        buffer[digit_count++] = 'X';
        buffer[digit_count++] = '0';
    }
    
    /*Handle width and precision manually if needed*/
    
    /*Add leading zeros based on precision*/
    while (digit_count < pmtrs->precision)
    {
        buffer[digit_count++] = '0';
    }

    /*Add padding characters for width*/
    char pad_ch = (pmtrs->flg_z && !pmtrs->flg_ms) ? '0' : ' ';
    while (digit_count < pmtrs->width)
    {
        buffer[digit_count++] = pad_ch;
    }
    
    /*Reverse the buffer and print the characters*/
    for (int i = digit_count - 1; i >= 0; i--)
    {
        ci += _putchar(buffer[i]);
    }

    pmtrs->usg = 1;
    return ci;
}

/**
* print_hex - prints the  unsigned hex in lowercase
* @args: argument pointer
* @*pmtrs: parameters struct
*
* Return: This is the bytes printed
*/
int hexa_print(va_list args, pmtrs_t *pmtrs)
{
    unsigned long li;
    int ci = 0;
    char buffer[32]; /*Assuming a maximum of 32 characters for the hexadecimal representation*/
    char *str = buffer;
    
    if (pmtrs->modi_l)
        li = (unsigned long)va_arg(args, unsigned long);
    else if (pmtrs->modi_h)
        li = (unsigned short int)va_arg(args, unsigned int);
    else
        li = (unsigned int)va_arg(args, unsigned int);

    /*Convert the integer to hexadecimal manually*/
    unsigned long x = li;
    char *hex_digits = "0123456789abcdef";
    int digit_count = 0;
    
    do
    {
        buffer[digit_count++] = hex_digits[x % 16];
        x /= 16;
    } while (x > 0);
    
    /*Add '0x' prefix if the '#' flag is set and the number is not zero*/
    if (pmtrs->flg_htag && li != 0)
    {
        buffer[digit_count++] = 'x';
        buffer[digit_count++] = '0';
    }
    
    /*Handle width and precision manually if needed*/
    
    /*Add leading zeros based on precision*/
    while (digit_count < pmtrs->precision)
    {
        buffer[digit_count++] = '0';
    }

    /*Add padding characters for width*/
    char pad_ch = (pmtrs->flg_z && !pmtrs->flg_ms) ? '0' : ' ';
    while (digit_count < pmtrs->width)
    {
        buffer[digit_count++] = pad_ch;
    }
    
    /*Reverse the buffer and print the characters*/
    for (int i = digit_count - 1; i >= 0; i--)
    {
        ci += _putchar(buffer[i]);
    }

    pmtrs->usg = 1;
    return ci;
}
