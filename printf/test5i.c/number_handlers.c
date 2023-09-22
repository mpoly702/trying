#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 * @begin: starting address
 * @end: end address
 * @except: exclude address
 *
 *
 * Return: bytes to be displayed
 */
int print_w(char *begin, char *end, char *except)
{
	int add = 0;

	while (begin <= end)
	{
		if (begin != except)
			add += _putchar(*begin);
		begin++;
	}
	return (add);
}

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

/**
 * print_root - This prints rot13 string
 * @args: an argument
 * @pmtrs: a parameter
 * Return: return just bytes
 */
int print_root(va_list args, pmtrs_t *pmtrs)
{
	int i, indice;
	int count = 0;
	char array[] = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(args, char *);
	(void)pmtrs;

	i = 0;
	indice = 0;

	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
				|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			indice = a[i] - 65;
			count += _putchar(array[indice]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return(count);
}
