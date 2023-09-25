#include <stdio.h>

int main(void)
{
	int arr[10];
	int i;
	int num;
	int pos;
	int size = 5;



	printf("enter your data\n");
	for (i = 0; i <= 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("enter the data to be inserted\n");
	scanf("%d", &num);
	printf("enter position\n");
	scanf("%d", &pos);

	for (i = size - 1; i >= pos - 1; i--);
	{
		arr[i + 1] = arr[i];
	}
	arr[pos - 1] = num;
	size++;
	printf("these are the elements\n");
	
	for (i = 0; i <= size; i++)
	{
		printf("%d \n", arr[i]);
	}
	
	if(pos <= 0 || pos > size + 1)
	{
		printf("invalid position\n");
	}	
	return (0);
}
