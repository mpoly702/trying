#include <stdio.h>
#include <string.h>

#define MAX 50

int main(void)
{
	char res [MAX] = "this is the region of rest";
	char fort [MAX];

	strcpy(fort, res);

	printf("%s\n", fort);

	return (0);
}
