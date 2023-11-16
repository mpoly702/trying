#include <stdio.h>
#include <string.h>
int main(void)
{
	char *str = "w3resource.com";
	int i = 0;
	size_t x;

	x = strlen(str);
	
	for (i = 0; str[i] != '\0'; i++)
	{
		putchar(str[i]);
		putchar(' ');
		putchar(' ');
	}
	putchar('\n');		

	return(0);
}
