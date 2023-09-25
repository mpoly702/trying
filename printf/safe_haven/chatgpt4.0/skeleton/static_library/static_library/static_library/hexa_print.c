#include "main.h"

/**
* print_hex - prints the  unsigned hex in lowercase
* @ap: argument pointer
* @params: parameters struct
*
* Return: This is the bytes printed
*/
int hexa_print(va_list args, pmtrs_t *pmtrs)
{
	unsigned long li;
	int ci = 0;
	char *str;
	
	if (pmtrs->modi_l)
		li = (unsigned long)va_arg(args, unsigned long);
	else if (pmtrs->modi_h)
		li = (unsigned short int)va_arg(args, unsigned int);
	else
		li = (unsigned int)va_arg(args, unsigned int);
	str = transform(li, 16, USG_CONVT | LOWER_CASE, pmtrs);
	
	if (pmtrs->flg_htag && li)
	{
		*--str = 'x';
		*--str = '0';
	}
	pmtrs->usg = 1;
	return (ci += print_num(str, pmtrs));
}
