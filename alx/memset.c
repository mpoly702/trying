#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[50] = "Godfrey is an elite developer";
	printf("this is before memset(): %s\n", str);

	memset(str + 7, 'x', 7 * sizeof(char));
	printf("Aftermath of memset: %s\n", str);
	return (0);
}
