#include <stdio.h>

/**
 * main - This program is for operators
 * Description - This program helps to explain Relational operators
 *
 * Return: 0
 */

int main(void)
{
	int i;

	printf("Please enter amount of money you have for tfare\n");
	scanf("%d", &i);

	if (i >= 30 )
	{
		printf("your money is sufficient\n");
	}
	else if (i < 30)
	{
		printf("Insufficient funds\n");
	}
	return 0;
}
