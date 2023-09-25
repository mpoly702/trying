#include <stdio.h>
#include <string.h>

int main(void)
{
	int a[2][3];
	int i, j;

	printf("kindly enter your array elements\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	printf("the elements of the array are:\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
	return (0);
}
