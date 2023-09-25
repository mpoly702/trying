#include <stdio.h>

/**
 * main - fibonacci <3
 *
 * Purpose - no hardcode
 *
 * Return:  (Success)
 */

int main(void)
{
	unsigned long int i;
	unsigned long int prev = 1;
	unsigned long int next = 2;
	unsigned long int l = 1000000000;
	unsigned long int prev1;
	unsigned long int prev2;
	unsigned long int next1;
	unsigned long int next2;

	printf("%lu", prev);

	for (i = 1; i < 91; i++)
	{
		printf(", %lu", next);
		next = next + prev;
		prev = next - prev;
	}

	prev1 = (prev / l);
	prev2 = (prev % l);
	next1 = (next / l);
	next2 = (next % l);

	for (i = 92; i < 99; ++i)
	{
		printf(", %lu", next1 + (next2 / l));
		printf("%lu", next2 % l);
		next1 = next1 + prev1;
		prev1 = next1 - prev1;
		next2 = next2 + prev2;
		prev2 = next2 - prev2;
	}
	printf("\n");
	return (0);
}
