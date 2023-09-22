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
