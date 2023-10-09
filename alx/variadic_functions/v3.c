#include <stdio.h>
#include <stdarg.h>

int div(int nos, ...)
{
	int i;
	int sol;
	int x;

	va_list digits;
	va_start(digits, nos);

	sol = va_arg(digits, int); /*get the first argument*/

	for (i = 1; i < nos; i++)
	{
		x = va_arg(digits, int); /*get the next argument*/
		
		if (x != 0) 
		{
			sol /= x;
		}
		else
		{
			printf("there is an error: dividing by zero\n");
			break;
		}
	}

	va_end(digits);

	return sol;
}

int main(void)
{
	int result;

	result = div(2, 300, 10);
	printf("Result: %d\n", result);

	return(0);
}
