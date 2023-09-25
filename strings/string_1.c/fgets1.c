#include <stdio.h>
#include <strings.h>

#define MAX 100
int main(void)
{
	char str [MAX];

	fgets(str, MAX, stdin);
	
	printf("this string is: %s\n", str);

	return (0);
}
