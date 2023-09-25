#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[40] = "oliver";
	char s2[40];

	strcpy(s2, s1);
	printf("%s\n", s2);
	return (0);
}
