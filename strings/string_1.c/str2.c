#include <stdio.h>
#include <string.h>

#define MAX 50

int main(void)
{
	char rep [MAX] = "This is the blessing of the Lord\n";
	char wat [MAX];

	strcpy(wat, rep);

	puts(wat);

	return (0);

}
