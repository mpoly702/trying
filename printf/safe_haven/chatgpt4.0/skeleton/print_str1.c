#include "main.h"

/**
* print_string - print the string
* @ap: This is the argument pointer
* @params: this is the structure of the parameter
*
* Return: The no character to be printed
*/
int print_str1(va_list args, pmtrs_t *pmtrs)
{
	char *str = va_arg(args, char *), pad_ch = ' ';
	unsigned int padd = 0, add = 0, i = 0, j;
	(void)pmtrs;
	
	switch ((int)(!str))
	case 1:
		str = STR_NIL;
		j = padd = _strlen(str);
		
		if (pmtrs->precision < padd)
			j = padd = pmtrs->precision;
		if (pmtrs->flg_ms)
		{
			if (pmtrs->precision != UINT_MAX)
				for (i = 0; i < padd; i++)
					add += _putchar(*str++);
			else
				add += _puts(str);
		}
		while (j++ < pmtrs->width)
			add += _putchar(pad_ch);
		if (!pmtrs->flg_ms)
		{
			if (pmtrs->precision != UINT_MAX)
				for (i = 0; i < padd; i++)
					add += _putchar(*str++);
			else
				add += _puts(str);
		}
		return (add);
}
