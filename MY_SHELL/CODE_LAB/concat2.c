#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	char x[3][50] = {"tribest", "SOL", "C&I LEASING"};
	char v[] = "/PLC";

	for (i = 0; i < 3; i++)
	{
		strcat(x[i], v);
		printf("String %d: %s\n", i+1, x[i]);
	}

	return (0);
}
