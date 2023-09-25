#include <stdio.h>

/**
 * main - This program counts
 * Desscription - This program describes the counting of numbers
 *
 * Return: 0
 */

int main(void)
{
	int i;
	int j;
	int n;
	int multiply;

	printf("enter the highest number you will like to multiply\n");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%dx%d = %d, ", i,j,i*j);		
		}
		putchar('\n');
	}
	return (0);
}
