#include <stdio.h>

int main(void)
{
	int arr[5];
	int i;
	
	printf("Kindly enter the elements pf the array\n");
	for (i = 0; i <= 4; i++)
	{		
		scanf("%d", &arr[i]);
	}
	
	printf("The elements of the array are:\n");
	for (i = 0; i <= 4; i++)
	{
		printf("%d\t\t\t", arr[i]);
	}
	printf("\n");
	printf("the third element of this array is: %d\n", arr[2]);
	return (0);
}
