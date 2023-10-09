#include <stdio.h>

int factorial(int n)
{
	if (n < 0)
	{
		return(-1);
	}
	if (n == 0)
	{
		return(1);
	}
	return (n * factorial(n - 1));
}

int main(void)
{
	int x = 1;
	int y;

	y = factorial(x);

	printf("%d\n", y);

	return (0);
}
