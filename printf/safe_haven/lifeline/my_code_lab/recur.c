#include <stdio.h>

void countdown(int n)
{
	/*base case*/
	if (n == 0)
	{
		printf("get out\n");
	}
	else
	{
		/*recursive condition*/
		printf("%d, \n", n);
		countdown(n - 1); /*recursive call*/
	}

}

int main(void)
{
	int i;
	
	i = 10;
	countdown(i);

	return (0);
}
