#include "main.h"
/**
* print_S - custom format spec.
* @ap: The argument pointer
* @params: structure of the parameter
*
* Return: no of character printed
*/
int print_SOS(va_list args, pmtrs_t *pmtrs)
{
	char *str = va_arg(args, char *);
	char *hexa;
	int add = 0;
	
	if ((int)(!str))
		return (_puts(STR_NIL));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			add += _putchar('\\');
			add += _putchar('x');
			hexa = transform(*str, 16, 0, pmtrs);
			
			if (!hexa)
				add += _putchar('0');
			add += _puts(hexa);
		}
		else
		{
			add += _putchar(*str);
		}
	}
	return(add);
}
