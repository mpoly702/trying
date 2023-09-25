#include <stdio.h>
#include <strings.h>

#define MAX 50

int main(void)
{
	char ras[MAX];

	fgets(ras, MAX, stdin);

	printf("%s\n", ras);

	return (0);
}
