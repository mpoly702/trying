#include "main.h"

/**
* _strlen - returns string length
* @s: string length to check
*
* Return: integer length of string
*/
int _strlen(char *s)
{
	int i = 0;
	
	while (*s++)
		i++;
	return (i);
}
