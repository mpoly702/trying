#include "main.h"

/**
 * print_integer - This  prints  d integer
 * @args: argument
 * @pmtrs: parameters structure
 *
 * Return: prints character
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

/**
 * print_ch - This prints characters
 * @args: argument
 * @pmtrs: parameter
 *
 * Return: The no char to be  printed
 */
int print_ch(va_list args, pmtrs_t *pmtrs)
{
	char pad_ch = ' ';
	unsigned int padd = 1, add = 0, ch = va_arg(args, int);
	
	if (pmtrs->flg_ms)
		add += _putchar(ch);
	while (padd++ < pmtrs->width)
		add += _putchar(pad_ch);
	if (!pmtrs->flg_ms)
		add += _putchar(ch);
	return (add);
}

/**
 * print_string - print the string
 * @args: argument
 * @pmtrs: parameter
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

/**
 * print_SOS - custom format spec.
 * @args: The argument
 * @pmtrs: parameter
 *
 * Return: no of character printed
 */
int print_SOS(va_list args, pmtrs_t *pmtrs)
{
	char *str = va_arg(args, char *);
	char *hexa;
	int add = 0;
	
	if ((int)(!str))
		return (_puts(STR_NIL));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			add += _putchar('\\');
			add += _putchar('x');
			hexa = transform(*str, 16, 0, pmtrs);
			
			if (!hexa)
				add += _putchar('0');
			add += _puts(hexa);
		}
		else
		{
			add += _putchar(*str);
		}
	}
	return(add);
}

/**
 * print_percent - This is to  string
 * @args: The argument pointer
 * @params: parameters structure
 *
 * Return: count of characters
 */
int print_per(va_list args, pmtrs_t *pmtrs)
{
	(void)args;
	(void)pmtrs;
	return (_putchar('%'));
}
