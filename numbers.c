#include <stdio.h>

/**
 *  main - This number thing
 *  Description - Describes number
 *  Return: 0
 */

int main(void)
{
	int i;
	int j;

	for (i = '0'; i <= '9'; i++)
	{
		for (j = '0'; j <= '9'; j++)
		{
			if (i < j)
			{
			putchar(i);
			putchar(j);
			if (i != '8' || (i == '8' && j != '9'))
			putchar(',');
			putchar(' ');
			}
		}
	}
	putchar('\n');
}

