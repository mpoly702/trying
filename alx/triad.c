#include <stdio.h>

/**
 * main - this program is a PROGRAM indeed
 * Description - This program helps me to comment easily
 *
 * Return: 0
 */

int main(void)
{	
	char i;
	char j;
	int N;

	printf("Enter a number\n");
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= i; j++)
		{
			putchar('*');
		}
	putchar('\n');
	}
	return (0);
}
