#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *env = getenv("PATH");
	printf("%s", env);
	return (0);
}
