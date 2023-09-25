#include "main.h"
/**
 * rev_str - prints strings in  reverse
 * @args: variable list argument
 * @pmtrs: a parameter
 * 
 * Return: no of  bytes printed
 */
int rev_str(va_list args, pmtrs_t *pmtrs)
{
	int li, add = 0;
	char *str = va_arg(args, char *);
	(void)pmtrs;

	if (str)
	{
		for (li = 0; *str; str++)
			li++;
		str--;
		for (; li > 0; li--, str--)
			add += _putchar(*str);
	}
	return (add);
}
