#include <stdio.h>

/**
 * main - this program is for ARRAYS
 * Description - learning how to initialize an array
 *
 * Result: 0
 */

int main(void)
{
	int arr[50];
	int N;
	int i;

	printf("How many subjects does the student studies\n");
	scanf("%d", &N);

	printf("Enter student's score here\n");

	for (i = 0; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("****************\n****STUDENT'S SCORE******\n*********************\n");
	for (i = 0; i <= N; i++)
	{
		printf("%d - ", arr[i]);
	}
	return (0);
}

