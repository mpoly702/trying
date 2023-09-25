#include <stdio.h>

/**
 * main - this program draws a triangle
 * Description - This program explains the for loop
 *
 * Return: 0
 */

int main(void)
{
	int i;
	int j;
	int n;

	printf("ENTER A NUMBER\n");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
