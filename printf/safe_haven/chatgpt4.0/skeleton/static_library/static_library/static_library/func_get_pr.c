#include "main.h"

/**
 * get_print_func - searches out the format of the function
 * @s: a string
 * @args: argument
 * @pmtrs: parameter
 *
 *
 * Return: no of bytes printed
 */

int func_get_pr(char *s, va_list args,pmtrs_t *pmtrs)
{
	int (*f)(va_list, pmtrs_t *) = specifier_get(s);
	if (f)
		return (f(args, pmtrs));
	return (0);
}
