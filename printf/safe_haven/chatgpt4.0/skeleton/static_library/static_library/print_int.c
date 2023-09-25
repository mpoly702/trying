#include "main.h"

/**
* print_int - This  prints  d integer
* @ap: argument pointer
* @params: parameters structure
*
* Return: no xter  printed
*/
int print_integer(va_list args, pmtrs_t *pmtrs)
{
	long li;
	
	if (pmtrs->modi_l)
		li = va_arg(args, long);
	else if (pmtrs->modi_h)
		li = (short int)va_arg(args, int);
	else
		li = (int)va_arg(args, int);
	return (print_num(transform(li, 10, 0, pmtrs), pmtrs));
}
