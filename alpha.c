#include <stdio.h>

int main(void)
{
	int i;
	char j;
	
	for (i = 1; i <= 10; i++)
	{
		for (j = 'a'; j <= 'z'; j++)
		{
			putchar(j);
		}
	putchar('\n');
	}
	return (0);
}
