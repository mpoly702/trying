#include <stdio.h>
#include <string.h>

/**
 * main - this program uses whitespaces in strings
 * Description - this program is for whitespaces
 *
 * Return: 0
 */

int main(void)
{
	char str [] = "Geeks";

	printf("%s\n", str);

	int length = 0;

	length = strlen(str);
	
	printf("Length of String str is %d\n", length);

	return (0);
}
