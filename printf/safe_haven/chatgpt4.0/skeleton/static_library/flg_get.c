#include "main.h"

/**
 * flg_get - searches out the flag angels
 * @s:  format string
 * @pmtrs: parameter
 *
 * Return: if the flag was valid
 */
int flg_get(char *s, pmtrs_t *pmtrs)
{
	int x = 0;

	switch (*s)
	{
		case '+':
			x = pmtrs->flg_pls = 1;
			break;
		case ' ':
			x = pmtrs->flg_sp = 1;
			break;
		case '#':
			x = pmtrs->flg_htag = 1;
			break;
		case '-':
			x = pmtrs->flg_ms = 1;
			break;
		case '0':
			x = pmtrs->flg_z = 1;
			break;
	}
	return (x);
}
