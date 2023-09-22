/**
* get_width - retrieves width from  format string
* @s: format string
* @params: parameters structure
* @ap: argument pointer
* Return:a new pointer
*/

char *width_get(char *s, pmtrs_t *pmtrs, va_list args)
{
	int y = 0;
	
	if (*s == '*')
	{
		y = va_arg(args, int);
		s++;
	}
	else
	{
		while (_Adigit(*s))
			y = y * 10 + (*s++ - '0');
	}
	pmtrs->width = y;
	return (s);
}
