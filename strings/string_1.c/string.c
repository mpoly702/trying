#include <stdio.h>
#include <string.h>

#define MAX 50

int main(void)
{
	char str [MAX] = "The Lord of the Rings";
	char res [MAX];

	strcpy(res, str);

	puts(str);

	return (0);
}
