#include "main.h"

/**
* print_binary - This prints the  unsigned binary no
* @ap: argument pointer
* @params: parameters struct
*
* Return: This is the bytes printed
*/
int binary_out(va_list args, pmtrs_t *pmtrs)
{
	unsigned int x = va_arg(args, unsigned int);
	char *str = transform(x, 2, USG_CONVT, pmtrs);
	int ci = 0;
	
	if (pmtrs->flg_htag && x)
		*--str = '0';
	pmtrs->usg = 1;
	return (ci += print_num(str, pmtrs));
}
