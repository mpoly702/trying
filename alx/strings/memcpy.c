#include <stdio.h>
#include <string.h>

int main (void)
{
	const char src[50] = "https://www.tutorialspoint.com";
	char dest[50];
	strcpy(dest, "Helooo!!!");
	printf("Before memcpy dest = %s\n", dest);

	memcpy(dest, src, strlen(src) + 1);
	printf("After memcpy dest = %s\n", dest);

	return(0);
}
