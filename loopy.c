#include <stdio.h>

/**
 *  main - trys to create a loopy reality
 *  Decription - what an important concept that became
 *  Return: 0
 */

int main(void)
{
	char i = 'a';

	while (i <= 'z')
	{
		if (i != 'e' && i != 'z')
		{
		putchar (i);
		}
		i++;
	}
	putchar('\n');
	return (0);
}
