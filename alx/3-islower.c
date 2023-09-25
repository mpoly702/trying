#include "main.h"

/**
 * _islower - checks for cases
 * @c: is the parameter for the function
 * Return: 1 if char is lowercase and 0 if not
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	return (1);
	else
	return (0);
}
