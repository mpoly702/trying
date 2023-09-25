#include "main.h"
#define FREE_BUFF -1
/**
 * _puts - string printer
 * @str: string
 *
 * Return:( str-a)
 */
int _puts(char *str)
{
	char *a = str;/*declaration of variables*/

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - writes char writer
 * @x: parameter
 *
 * Return: 1 or -1
 */
int _putchar(int x)
{
	static int i;
	static char buf[SIZE_BUF];

	if (x == FREE_BUF || i >= SIZE_BUF)
	{
		write(1, buf, i);
		i = 0;
	}
	if (x != FREE_BUF)
		buf[i++] = x;
	return (1);
}
