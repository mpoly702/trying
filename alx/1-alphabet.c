#include "main.h"

/**
 * print_alphabet - print all alphabet in lowercase
 */

void print_alphabet(void)
{
	char afabet;

	for (afabet = 'a'; afabet <= 'z'; afabet++)
	{
		_putchar(afabet);
	}
	_putchar('\n');
}
