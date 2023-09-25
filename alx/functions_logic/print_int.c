#include <stdio.h>
#include <stdlib.h> 

char *itoa(int num)
{
	/*determine the sign of the number*/
	int is_negative = 0;
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	/*calculate the number of digits in the integer*/
	int temp = num;
	int digit_count = 1;
	
	while (temp /= 10)
	{
		digit_count++;
	}

	/*allocate memory for the string (including space for sign and null terminator*/
	int str_len = digit_count + 
}


