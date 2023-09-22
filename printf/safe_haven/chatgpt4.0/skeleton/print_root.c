/**
 * print_root - This prints rot13 string
 * @args: an argument
 * @pmtrs: a parameter
 * Return: return just bytes
 */
int print_root(va_list args, pmtrs_t *pmtrs)
{
	int i, indice;
	int count = 0;
	char array[] = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
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
			count += _putchar(array[indice]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return(count);
}
