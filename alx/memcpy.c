#include <stdio.h>
#include <string.h>

int main(void)
{
	const char source[50] = "https://www.github.com/mpoly/pointers.git";
		char dest[50];
		strcpy(dest, "Hello Namibia");
		printf("%s\n", dest);

		memcpy(dest, source, strlen(source) + 1);
		printf("after memcpy dest became %s\n", dest);
		return (0);
}
