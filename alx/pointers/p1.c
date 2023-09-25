#include <stdio.h>

/**
 * main - this program works on pointers
 * Description - this program describes pointers
 *
 * Return: 0
 */

int main(void)
{
	int v = 20;
	int *p;

	printf("%x is the memory address of v\n",  &v);
	p = &v;
	*p = 35;
	
	printf("%d is the value of v\n", v);
	return (0);
}
