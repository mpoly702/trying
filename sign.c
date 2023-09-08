#include <stdio.h>
#include "main.h"

int sign(int N)
{
	if (N > 0)
	{
		putchar('+');
		putchar('\n');
		return (1);
	}
	else if (N == 0)
	{
		putchar(48);
		putchar('\n');
		return (0);
	}
	else if (N < 0)
	{
		putchar('-');
		putchar('\n');
		return (-1);
	}
}

int main(void)
{
	int i;

	printf("Enter a number\n");
	scanf("%d", &i);
	
	sign(i);
}
