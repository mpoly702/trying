#include <stdio.h>

int main(void)
{
	unsigned long x;
	unsigned long y;
	unsigned long z;
	unsigned long i;
	unsigned long j;
	unsigned long x1;
	unsigned long x2;
	unsigned long y1;
	unsigned long y2;
	unsigned long z1;
	unsigned long z2;
	
	x = 1;
	y = 2;
	
	printf("%lu, ", x);
	printf("%lu, ", y);
	for (i = 1; i <= 91; i++)
	{
		for (j = 1; j <= 1; j++)
		{
			z = x + y;
			printf("%lu, ", z); 
		}		
		x = y;
		y = z;
	}

	for (i = 92; i <= 96; i++)
	{	
			for (j = 1; j <= 1; j++)
			{
				x1 = x / 1000000000;
				x2 = x % 1000000000;
				y1 = y / 1000000000;
				y2 = y % 1000000000;
			
				z1 = x1 + y1;
				z2 = x2 + y2;
				printf("%lu, ", z1 + z2 / 1000000000);
				y1 = x1;
				y2 = x2;
			}
	}
	printf("\n");
	return (0);
}
