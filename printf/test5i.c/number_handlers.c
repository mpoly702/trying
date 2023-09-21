#include "main.h"

/**
* print_from_to - prints a range of char addresses
* @start: the adress it starts with
* @stop: the adress it stops
* @except: excluding address
*
*
* Return: no of bytes printed
*/
int print_w(char *begin, char *end, char *except)
{
int add = 0;

while (begin <= end)
{
if (begin != end)
add += _putchar(*begin);
begin++;
}
return (add);
}

/**
* print_rev - prints the string reverse
* @ap: string
* @params: parameters struct
*
* Return: no of  bytes printed
*/
int rev_string(va_list args, pmtrs_t *pmtrs)
{
int li, add = 0;
char *str = va_arg(args, char *);
(void)pmtrs;

if (str)
{
for (li = 0; *str; str++)
li++;
str--;
for (; li > 0; li--, str--)
add += _putchar(*str);
}
return (add);
}

/**
* print_root - This prints the string in rot13
* @args: string
* @pmtrs: parameters struct
*
* Return: no of the bytes printed
*/
int print_root(va_list args, pmtrs_t *pmtrs)
{
int i, indice;
int count = 0;
char array[] =
"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
char *a = va_arg(args, char *);
(void)pmtrs;

i = 0;
indice = 0;
while (a[i])
{
if ((a[i] >= 'A' && a[i] <= 'Z')
|| (a[i] >= 'a' && a[i] <= 'z'))
{
indice = a[i] - 65;
count += _putchar(array[index]);
}
else
count += _putchar(a[i]);
i++;
}
return (count);
}
