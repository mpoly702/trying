#include <stdio.h>

int main(void)
{
	int n = 200;
	int *ptr;

	ptr = &n;
	printf("%p is the memory address of n\n", ptr);
	printf("my account balance was $%d\n", n);
	*ptr = 2000000;
	printf("my new account balance is $%d\n", *ptr);
	int **var;
	
	var = &ptr;
	printf("%p is the memory address of ptr\n", var);
	**var = 2000000000;
	printf("this is how my account balance should look like $%d\n", **var);
	return (0);
}
