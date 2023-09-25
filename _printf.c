#include "main.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", printf_str1}, {"%c", printf_ch},
		{"%%", printf_crack}
	};

	va_list args;
	int i = 0, len = 0;
	unsigned int j;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			while (j < sizeof(m) / sizeof(m[0]))
			{
				if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
				{
					len += m[j].f(args);
					i = i + 2;
					break;  /*Exit the inner loop when a match is found*/
				}
				j++;
			}
		}
		else
		{
			_putchar(format[i]);
			len++;
			i++;
		}
	}
	va_end(args);
	return (len);
}
