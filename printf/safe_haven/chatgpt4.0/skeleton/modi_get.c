#include "main.h"

/**
* get_modifier - finds  modifier function
* @s: string format
* @params: parameter struct
* Return: if modifier valid
*/
int modi_get(char *s, pmtrs_t *pmtrs)
{
	int i = 0;
	
	switch (*s)
	{
		case 'h':
			i = pmtrs->modi_h = 1;
			break;
		case 'l':
			i = pmtrs->modi_l = 1;
			break;
	}
	return (i);
