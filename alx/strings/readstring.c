#include <stdio.h>
#include <string.h>

/**
 * main - this program print strings
 * Description - this program describes our way around strings
 *
 * Return: 0
 */

int main(void)
{
	char tip [50];

	printf("Enter a name\n");
	scanf("%50s", &tip);

	int lent;

	lent = strlen(tip);
	printf("%s", tip);
	printf("The Length of tip is %d\n", lent);

	return(0);
}
