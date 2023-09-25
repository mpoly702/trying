#include <stdio.h>
#include "main.h"

/**
 * age - this function tells us the president
 * @x: this parameter represents an input
 * 
 *
 * Description - parameter x takes in a char.
 * Return: 
 */

int age(int x)
{
	
	printf("Enter your age\n");
	scanf("%d", &x);

	if (x >= 0 && x <= 35)
	{
		printf("this person is a young person\n");
	}
	else if (x >= 36 && x <= 55);
	{
		printf("this person is middle age\n");
	}
	if (x >= 56 && x <= 120)
	{
		printf("this person is an ancient of days\n");
	}
}	
 

/**
 * main - the program functions
 * Description - This program talks about functions
 *
 * Return: 0
 */

int main(void)
{
	char N;

	age(N);
	return (0);
}


