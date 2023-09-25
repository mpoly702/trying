#include <stdio.h>

/**
 * main - this program was found in an huddle
 * Description - i want to learn a thing or two about strings
 *
 * Return: 0
 */
int str_length(char *str);

int main(void)
{
	
	char *string = "ALX SCHOOL";
	int length;
	
	length = str_length(string);
	printf("%d\n", length);
	str_length(string);

	return (0);
}

/**
 * this function copies a string and return the address of 
 * the string
 */

int str_length(char *str)
{
	int i;
	int size = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		size = size + 1;
	}
	return size;
}
