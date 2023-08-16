#include <stdio.h>

/**
 *  main - this reverses the alphabet
 *  Description - this showcase for loop
 *  Return: 0
 */

int main(void)
{
	char you;

	for (you = 'z'; you >= 'a'; you--)
	{
	putchar(you);
	}
	putchar('\n');
	return (0);
}
