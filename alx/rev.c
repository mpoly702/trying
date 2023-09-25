#include <stdio.h>
#include <string.h>

int main(void)
{
	char x[35] = "GODFREY";
	int i, len;
	char ch;

	len = strlen(x);

	for (i = 0; i < len / 2; i++)
	{
		ch = x[i];
		x[i] = x[len - 1 - i];
		x[len - 1 - i] = ch;
	}
	printf("the reverse string is: %s\n", x);
	printf("His name has %d letters.\n", len);

	return (0);
}
