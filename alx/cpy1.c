#include <stdio.h>
#include <string.h>

int main(void)
{
	char x1[30] = "Dialogue is important";
	char x2[30];

	printf("the content of x1 is: %s\n", x1);

	/*copying x1 to x2*/
	strcpy(x2, x1);

	printf("the contents of x2 is now: %s\n", x2);
	return (0);
}
