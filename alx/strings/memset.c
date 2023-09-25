#include <stdio.h>
#include <string.h>

int main (void)
{
	char var[50] = {"My name is Stan Shunpike"}
	printf("Before Memset: %s\n", var);

	memset(var + 8, 'x', 8 * sizeof(char));

	printf("After memset(): %s", var[50]);
	return(0);
}
