#include "shell.h"

/**
 * _strchr - Locates a character in a string.
 * @x: The string to be searched.
 * @y: The character to be located.
 *
 * Return: If y is found - a pointer to the first occurence.
 *         If y is not found - NULL.
 */
char *_strchr(char *x, char y)
{
	int i;

	for (i = 0; x[i]; i++)
	{
		if (x[i] == y)
			return (x + i);
	}

	return (NULL);
}

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The string to be searched.
 * @acc: The prefix to be measured.
 *
 * Return: The number of bytes in s which
 *         consist only of bytes from accept.
 */
int _strspn(char *x, char *acc)
{
	int i = 0;
	int j;

	while (*x)
	{
		for (j = 0; acc[j]; j++)
		{
			if (*x == acc[j])
			{
				i++;
				break;
			}
		}
		x++;
	}
	return (i);
}

/**
 * _strcmp - Compares two strings.
 * @x1: The first string to be compared.
 * @x2: The second string to be compared.
 *
 * Return: Positive byte difference if x1 > x2
 *         0 if x1 = x2
 *         Negative byte difference if x1 < x2
 */
int _strcmp(char *x1, char *x2)
{
	while (*x1 && *x2 && *x1 == *x2)
	{
		x1++;
		x2++;
	}

	if (*x1 != *x2)
		return (*x1 - *x2);

	return (0);
}

/**
 * _strncmp - Compare two strings.
 * @x1: Pointer to a string.
 * @x2: Pointer to a string.
 * @y: The first n bytes of the strings to compare.
 *
 * Return: Less than 0 if x1 is shorter than x2.
 *         0 if x1 and x2 match.
 *         Greater than 0 if x1 is longer than x2.
 */
int _strncmp(const char *x1, const char *x2, size_t y)
{
	size_t j;

	for (j = 0; x1[j] && x2[j] && j < y; j++)
	{
		if (x1[j] > x2[j])
			return (x1[j] - x2[j]);
		else if (x1[j] < x2[j])
			return (x1[j] - x2[j]);
	}
	if (j == y)
		return (0);
	else
		return (-15);
}
