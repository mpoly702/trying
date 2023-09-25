#include <stdio.h>
#include <strings.h>

#define MAX 50

int main(void)
{
	char res [MAX];

	printf("Enter a new word\n");
	gets(res);

	printf("%s", res);

	return (0);
}
