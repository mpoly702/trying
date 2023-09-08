#include <stdio.h>

/**
 * age - This function checks user's age
 * @N: parameter n helps to take in age
 *
 * Description - N takes in input
 * Return: The integer value of the function age
 */

int age(int N)
{
	printf("Kindly enter your Age\n");
	scanf("%d", &N);

	if (N  <= 50)
	{
		printf("This is person is still a baby\n");
	}
	else if (N > 50 && N <= 120)
	{
		printf("This person is old\n");
	}
	else if (N > 120)
	{
		printf("This person is an ancient of days\n");
	}

}
/**
 * main - The main function is the Baba function
 * Description - does his job
 *
 * Return: Always 0
 */
int main(void)
{

	int i;

	age(i);

	return (0);
}
