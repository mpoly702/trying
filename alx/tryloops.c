#include <stdio.h>

/**
 * main - this program attempts different kinds of loop
 * Description - this program is a loop inventor
 *
 * Return: 0
 */

int main(void)
{
	int i, j, x, y;

	printf("Enter a number\n");
	scanf("%d", &x);

	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= x - i; j++)
		{
			printf(" ");

			if (j >= x - i)
			{
				for (y = 1; y <= i; y++)
				{
					printf("*");
				}	
			}
			
		}
		printf("\n");
	}
	return (0);
}
