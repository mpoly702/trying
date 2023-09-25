 #include <stdio.h>

/**
 * main - prints a triangle
 *
 * Return: 0
 */

int main(void)
{
	int i, j, k;

	printf("enter a number\n");
	scanf("%d", &k);

	for (i = 1; i <= k; i++)
	{
		for (j = k; j >= i; j--)
		{
			if (j >= k - i)
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		
		}
	printf("\n");
	}
	return (0);
}
