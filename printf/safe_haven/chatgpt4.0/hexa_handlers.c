#include "main.h"

/**
 * hexa_print - 
* @args: argument
* @pmtrs: parameters struct
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

/**
* HEXA_print - prints an hexadecimal
* @args: argument pointer
* @pmtrs: parameters struct
*
* Return: bytes
*/
int HEXA_print(va_list args, pmtrs_t *pmtrs)
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
	str = transform(li, 16, USG_CONVT, pmtrs);
	if (pmtrs->flg_htag && li)
	{
		*--str = 'X';
		*--str = '0';
	}
	pmtrs->usg = 1;
	return (ci += print_num(str, pmtrs));
}
/**
 * binary_out - This prints a binary
 * @args: argument
 * @pmtrs: parameter
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

/**
 * octal_out - This prints unsigned octal no
 * @args: Argument
 * @pmtrs: parameter
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
