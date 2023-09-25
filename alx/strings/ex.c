#include <stdio.h>
#include <string.h>

/**
 * main - this program is use to learn about strings
 * Description - this program describes the different operations of a string
 *
 * Result: 0
 */

int main(void)
{
	char rex [50] = "Report";

	int lent;

	lent = strlen(rex);

	printf("The length of rex is %d\n", lent);

	return(0);
}
