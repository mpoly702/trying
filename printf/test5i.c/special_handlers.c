#include "main.h"

/**
* get_specifier - This finds thefunction of format
* @s: string of format
* Return:no of bytes that was  printed
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

/**
* get_print_func - finds  function format
* @s: string
* @ap: argument pointer
* @params:  parameter struct
* Return: no of bytes printed
*/

int func_get_pr(char *s, va_list args,pmtrs_t *pmtrs)
{
int (*f)(va_list, pmtrs_t *) = specifier_get(s);

if (f)
return (f(args, pmtrs));
return (0);
}

/**
* get_flag - finds flag functions
* @s:  format string
* @params: parameters struct
* Return: if the flag was valid
*/

int flg_get(char *s, pmtrs_t *pmtrs)

{
int i = 0;

switch (*s)
{
case '+':
i = pmtrs->flg_pls = 1;
break;
case ' ':
i = pmtrs->flg_sp = 1;
break;
case '#':
i = pmtrs->flg_htag = 1;
break;
case '-':
i = pmtrs->flg_ms = 1;
break;
case '0':
i = params->flg_z = 1;
break;
}
return (i);
}

/**
* get_modifier - finds  modifier function
* @s: string format
* @params: parameter struct
* Return: if modifier valid
*/

int modif_get(char *s, pmtrs_t *pmtrs)
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
}

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
