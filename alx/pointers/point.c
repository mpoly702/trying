#include <stdio.h>
#include <string.h>
#define MAX 500
int main(void)
{
	char str[] = "Godisgood";
	printf("%p is the address of the entire string\n", str);

	char qty[15] = "Canadian";
	printf("I will love to marry a %s woman\n", qty);

	char my[10] = {'F','R','I','E','N','D','S','H','I','\0'};
	printf("%s\n", my);

	char tye[] = {'g','i','r','d','l','e','\0'};
	printf("%s\n", tye);
	return (0);
}
