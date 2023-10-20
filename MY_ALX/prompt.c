#include "shell.h"

/**
 * instance - this function writes a prompt to the terminal
 */

void instance(void)
{
	char *instance;

	instance = "$";

	write(1, instance, 1);
}

/**
* _strdup - duplicates string in heap memo.
* @x: Type xter pointer string
* Return: duplicated string
*/
char *_strdup(const char *x)
{
char *update;
size_t length;

length = _strlen(x);
update = malloc(sizeof(char) * (length + 1));
if (update == NULL)
return (NULL);
_memcpy(update, x, length + 1);
return (update);
}

/**
* _memcpy - copies inf. b/t void pointers
* @newptr: The destination of the pointer
* @ptr: source  of pointer
* @size: size of new pointer
*
* Return: none
*/
void _memcpy(void *n, const void *p, unsigned int buf)
{
char *char_p = (char *)p;
char *char_n = (char *)n;
unsigned int i;

for (i = 0; i < buf; i++)
char_n[i] = char_p[i];
}
