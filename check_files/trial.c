#include <stdio.h>

/**
 * main - This is program is meant for explanation
 * Description - This program describes all the variables and functions
 *
 * Return: 0
 */

int main(void)
{
	int i;
	int j;
	int sum;
	int div;
	int multiply;
	int sub;

	j = 50;
	i = 50;
	sum = i + j;
	div = i / j;
	multiply = i * j;
	sub = i - j; 

	printf("The sum of i and j is %d\n", sum);
	printf("The division of i and j is %d\n", div);
	printf("The multiplication of i and j results in %d\n", multiply);
	printf("The subtraction of i from j is %d\n", sub);

	return (0);
}
