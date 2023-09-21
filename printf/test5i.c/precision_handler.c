#include "main.h"

/**
* get_precision - gets precision from format string
* @s: string form
* @params: parameters structure
* @ap: Argument pointer
* Return:the  new pointer
*/

char *prec_get(char *s, params_t *params, va_list args)
{
int y = 0;

if (*s != '.')
return (s);
s++;
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
params->precision = y;
return (s);
}
