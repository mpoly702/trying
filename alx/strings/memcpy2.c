#include <stdio.h>
#include <string.h>

int main(void)
{
	int arr[55];
	int i;
	int dest[55];

	for (i = 0; i <= 15; i++)
	{
		arr[i] = i;
	}
	printf("the elements of the array arr are:\n");

	for (i = 0; i <= 15; i++)
	{
		printf("%d\t\n", arr[i]);
	}
	printf("the elements of the array dest now contains the elements of arr and are shown below\n");
	memcpy(dest, arr, sizeof(int) * 16);
	for (i = 0; i <= 15; i++)
	{
		printf("%d ", dest[i]);
	}
	printf("\n");
	return(0);
}
