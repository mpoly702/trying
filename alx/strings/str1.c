#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *str = "Welcome, w3resource";

	printf("Before the sync:%s\n", str);

	char **sty;

	sty = (char **)malloc(sizeof(char) * strlen(str));

	*sty = str;
	
	*sty = "I will destroy the world, BLAH BLAH BLAH";
	printf("After the sync: %s\n", str);

	free(sty);
	return (0);
}
