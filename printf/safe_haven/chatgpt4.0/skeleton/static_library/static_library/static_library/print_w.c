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
