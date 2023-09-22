#include "main.h"

/**
* _printf - prints/input into std output
* @format: Format of the string
*
* Return: no of printed bytes
*/

int _printf(const char *format, ...)
{
	int add = 0;
	va_list args;
	char *p, *begin;
	
	pmtrs_t pmtrs = INIT_PMTRS;
	va_start(args, format);
	
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_pmtrs(&pmtrs, args);
		if (*p != '%')
		{
			add += _putchar(*p);
			continue;
		}
		begin = p;
		p++;
		while (flg_get(p, &pmtrs))
		{
			p++;
		}
		p = width_get(p, &pmtrs, args);
		p = prec_get(p, &pmtrs, args);
		if (modi_get(p, &pmtrs))
			p++;
		if (!specifier_get(p))
			add += print_w(begin, p,
					pmtrs.modi_l || pmtrs.modi_h ? p - 1 : 0);
		else
			add += func_get_pr(p, args, &pmtrs);
	}
	_putchar(FREE_BUF);
	va_end(args);
	return (add);
}
