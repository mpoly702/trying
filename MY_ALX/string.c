#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 * @x: A pointer to the characters string.
 *
 * Return: The length of the character string.
 */
int _strlen(const char *x)
{
	int len = 0;

	if (!x)
		return (len);
	for (len = 0; x[len]; len++)
		;
	return (len);
}

/**
 * _strcpy - Copies the string pointed to by src, including the
 *           terminating null byte, to the buffer pointed by des.
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t j;

	for (j = 0; src[j] != '\0'; j++)
		dest[j] = src[j];
	dest[j] = '\0';
	return (dest);
}

/**
 * _strcat - Concantenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 *
 * Return: Pointer to destination string.
 */
char *_strcat(char *dest, const char *src)
{
	char *dTemp;
	const char *sTemp;

	dTemp = dest;
	sTemp =  src;

	while (*dTemp != '\0')
		dTemp++;

	while (*sTemp != '\0')
		*dTemp++ = *sTemp++;
	*dTemp = '\0';
	return (dest);
}

/**
 * _strncat - Concantenates two strings where n number
 *            of bytes are copied from source.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @x: n bytes to copy from src.
 *
 * Return: Pointer to destination string.
 */
char *_strncat(char *dest, const char *src, size_t x)
{
	size_t d_len = _strlen(dest);
	size_t j;

	for (j = 0; j < x && src[j] != '\0'; j++)
		dest[d_len + j] = src[j];
	dest[d_len + j] = '\0';

	return (dest);
}
