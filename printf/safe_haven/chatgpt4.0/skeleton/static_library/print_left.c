#include "main.h"

/**
* print_number_left_shift - prints no with options
* @str:  base no as string
* @params: parameter structure
*
* Return: printed xter
*/
int print_left(char *str, pmtrs_t *pmtrs)
{
	unsigned int x = 0, gen, gen2, i = _strlen(str);
	char pad_ch = ' ';
	
	if (pmtrs->flg_z && !pmtrs->flg_ms)
		pad_ch = '0';
	gen = gen2 = (!pmtrs->usg && *str == '-');
	if (gen && i < pmtrs->width && pad_ch == '0' && !pmtrs->flg_ms)
		str++;
	else
		gen = 0;
	if (pmtrs->flg_pls && !gen2 && !pmtrs->usg)
		x += _putchar('+'), i++;
	else if (pmtrs->flg_sp && !gen2 && !pmtrs->usg)
		x += _putchar(' '), i++;
	x += _puts(str);
	while (i++ < pmtrs->width)
		x += _putchar(pad_ch);
	return (x);
}
