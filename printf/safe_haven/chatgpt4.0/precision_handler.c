#include "main.h"

/**
 * prec_get - get precision
 * @s: string form
 * @pmtrs: parameters structure
 * @args: Argument
 *
 *
 * Return: pointer
 */
char *prec_get(char *s, pmtrs_t *pmtrs, va_list args)
{
	int y = 0;
	
	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		y = va_arg(args, int);
		s++;
	}
	else
	{
		while (_Adigit(*s))
			y = y * 10 + (*s++ - '0');
	}
	pmtrs->precision = y;
	return (s);
}
