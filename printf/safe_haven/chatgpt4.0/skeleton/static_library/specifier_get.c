#include "main.h"

/**
 * specifier_get - This finds thefunction of format
 * @s: string of format
 *
 * Return: no of bytes that was  printed
 */

int (*specifier_get(char *s))(va_list args, pmtrs_t *pmtrs)
{
	ind_t indicators[] = {
		{"c", print_ch},
		{"d", print_integer},
		{"i", print_integer},
		{"s", print_str1},
		{"%", print_per},
		{"b", binary_out},
		{"o", octal_out},
		{"u", usg_print},
		{"x", hexa_print},
		{"X", HEXA_print},
		{"p", print_locate},
		{"S", print_SOS},
		{"r", rev_str},
		{"R", print_root},
		{NULL, NULL}
	};
	
	int i = 0;
	
	while (indicators[i].indicator)
	{
		if (*s == indicators[i].indicator[0])
		{
			return (indicators[i].f);
		}
		i++;
	}
	return (NULL);
}
