#include <stdio.h>
#include <stdarg.h>


int sum(int argt, ...)
{
	int result = 0;
	int i;
	int num;

	va_list args;

	va_start(args, argt);

	for (i = 0; i < argt; i++)
	{
		num = va_arg(args, int);
		result += num;
	}

	va_end(args);

	return result;
}

int main(void)
{
	int total;

	total = sum(4, 10, 20, 30, 40, 50);
	printf("the sum is: %d\n", total);

	return (0);
}
