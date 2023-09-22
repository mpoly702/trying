/**
* print_ch - This prints char
* @ap: argument pointer
* @params: parameters structure
*
*
* Return: The no char to be  printed
*/
int print_ch(va_list args, pmtrs_t *pmtrs)
{
	char pad_ch = ' ';
	unsigned int padd = 1, add = 0, ch = va_arg(args, int);
	
	if (pmtrs->flg_ms)
		add += _putchar(ch);
	while (padd++ < pmtrs->width)
		add += _putchar(pad_ch);
	if (!pmtrs->flg_ms)
		add += _putchar(ch);
	return (add);
}
