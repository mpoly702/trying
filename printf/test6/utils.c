#include "main.h"

/**
* convert - converts func.
* @num: no
* @base: bas
* @flags: argument flag
* @params: paramater structure
*
* Return: The string
*/
char *transform(long int m, int y, int flgs, pmtrs_t *pmtrs)
{
	static char *arr;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long x = m;
	(void)pmtrs;
	
	if (!(flgs & USG_CONVT) && m < 0)
	{
		x = -m;
		sign = '-';
	}
	arr = flgs & LOWER_CASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	
	do
	{
		*--ptr = arr[x % y];
		x /= y;
	}
	while (x != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
* print_unsigned - This prints unsigned integer nos
* @ap: argument pointer
* @params: parameters structure
*
* Return:d  bytes printed
*/
int usg_print(va_list args, pmtrs_t *pmtrs)
{
	unsigned long li;
	
	if (pmtrs->modi_l)
		li = (unsigned long)va_arg(args, unsigned long);
	else if (pmtrs->modi_h)
		li = (unsigned short int)va_arg(args, unsigned int);
	else
		li= (unsigned int)va_arg(args, unsigned int);
	pmtrs->usg = 1;
	return (print_num(transform(li, 10, USG_CONVT, pmtrs), pmtrs));
}


/**
* print_address - This prints the address
* @ap: argument pointer
* @params: parameter structure
*
* Return: This is the byte to be printed
*
*/
int print_locate(va_list args, pmtrs_t *pmtrs)
{
	unsigned long int x = va_arg(args, unsigned long int);
	char *str;
	
	if (!x)
		return (_puts("(nil)"));
	str = transform(x, 16, USG_CONVT | LOWER_CASE, pmtrs);
	*--str = 'x';
	*--str = '0';
	return (print_num(str, pmtrs));
}
