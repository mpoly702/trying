#include <stdio.h>

int add(int a, int b)
{
	return(a+b);
}

int main(void)
{
	int v = 200;
	int x = 500;
	int y;

	y = add(v, x);
	printf("y = %d\n", y);
	printf("this is the address of v = %p: x = %p: & y: %p\n", &v, &x, &y);
	printf("this is the address of add: %p\n", add);
	return(0);
}
