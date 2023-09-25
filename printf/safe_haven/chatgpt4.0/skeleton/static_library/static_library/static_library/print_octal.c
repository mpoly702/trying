#include "main.h"

/**
* print_octal - This prints unsigned octal no
* @ap: Argument pointer
* @params: parameters struct
*
* Return:This is  bytes printed
*/
int octal_out(va_list args, pmtrs_t *pmtrs)
{
	unsigned long li;
	char *str;
	int ci = 0;
	
	if (pmtrs->modi_l)
		li = (unsigned long)va_arg(args, unsigned long);
	else if (pmtrs->modi_h)
		li = (unsigned short int)va_arg(args, unsigned int);
	else
		li = (unsigned int)va_arg(args, unsigned int);
	str = transform(li, 8, USG_CONVT, pmtrs);
	
	if (pmtrs->flg_htag && li)
		*--str = '0';
	pmtrs->usg = 1;
	return (ci += print_num(str, pmtrs));
}
