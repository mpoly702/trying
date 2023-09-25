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
