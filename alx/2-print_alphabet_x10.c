#include "main.h"

/**
 * print_alphabet_x10 - prints alfabets
 * followed by a line as wriiten by Godfrey
 */

void print_alphabet_x10(void)
{
	int i;
	char j;

	for (i = 1; i <= 10; i++)
	{
		for (j = 'a'; j <= 'z'; j++)
		{
			_putchar(j);		
		}
		_putchar('\n');
	}
}
