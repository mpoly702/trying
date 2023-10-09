#include <stdio.h>

int add(int a, int b)
{
	int addy;

	addy = a + b;
	printf("Total for addition: %d\n", addy);
	return addy;
}

int subtract(int a, int b)
{
	int sub;

	sub = a - b;
	printf("Total for subtraction: %d\n", sub);
	return sub;
}

int divide(int a, int b)
{
	int div;

	div = a / b;
	printf("Total for division: %d\n", div);
	return div;
}

int main(void)
{	
	int i;
	int (*operand[3])(int, int);

	/*assign functions to the elements of the Array*/

	operand[0] = &add;
	operand[1] = &subtract;
	operand[2] = &divide;

	for (i = 0; i < 3; i++)
	{
		operand[i](10, 2);
	}

	return (0);
}
