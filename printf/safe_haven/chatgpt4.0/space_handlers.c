#include "main.h"

/**
 * _Adigit - char checker
 * @c: character
 *
 * Return: 1 or 0
 */
int _Adigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - length
 * @x: input
*
* Return: integer
*/
int _strlen(char *x)
{
	int i = 0;
	
	while (*x++)
		i++;
	return (i);
}

/**
 * print_num - prints number
 * @str: input
 * @pmtrs: parameter
 *
 * Return: integer
 */
int print_num(char *str, pmtrs_t *pmtrs)
{
	unsigned int i = _strlen(str);
	int gen = (!pmtrs->usg && *str == '-');
	
	if (!pmtrs->precision && *str == '0' && !str[1])
		str = "";
	if (gen)
	{
		str++;
		i--;
	}
	if (pmtrs->precision != UINT_MAX)
		while (i++ < pmtrs->precision)
			*--str = '0';
	if (gen)
		*--str = '-';
	if (!pmtrs->flg_ms)
		return (print_shift(str, pmtrs));
	else
		return (print_left(str, pmtrs));
}

/**
* print_number_right_shift - This prints no with options
* @str:  base no as  string
* @params: parameter structure
*
* Return: xter printed
*/
int print_shift(char *str, pmtrs_t *pmtrs)
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
	if ((pmtrs->flg_pls && !gen2) ||
			(!pmtrs->flg_pls && pmtrs->flg_sp && !gen2))
		i++;
	if (gen && pad_ch == '0')
		x += _putchar('-');
	if (pmtrs->flg_pls && !gen2 && pad_ch == '0' && !pmtrs->usg)
		x += _putchar('+');
	else if (!pmtrs->flg_pls && pmtrs->flg_sp && !gen2 &&
			!pmtrs->usg && pmtrs->flg_z)
		x += _putchar(' ');
	while (i++ < pmtrs->width)
		x += _putchar(pad_ch);
	if (gen && pad_ch == ' ')
		x += _putchar('-');
	if (pmtrs->flg_pls && !gen2 && pad_ch == ' ' && !pmtrs->usg)
		x += _putchar('+');
	else if (!pmtrs->flg_pls && pmtrs->flg_sp && !gen2 &&
			!pmtrs->usg && !pmtrs->flg_z)
		x += _putchar(' ');
	x += _puts(str);
	return (x);
}

/**
 * print_left - prints numbers
 * @str: a string
 * @pmtrs: parameter
 *
 * Return: printed character
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
