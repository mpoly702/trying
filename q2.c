#include <stdio.h>

/**
 * main - This program is a triangle
 * Description - This program draws a triangle of numbers
 *
 * Return: 0
 */

int main(void)
{
	int i;
	int j;
	int n;

	printf("Enter a number\n");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{	
			printf("%d", j);
		}
		printf("\n");
	}
	return (0);
}
