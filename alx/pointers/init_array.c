#include <stdio.h>

int main(void)
{
	int a[5];
	int i;
	int x;

	for (i = 0; i <= 5; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("the exam score of the students are:\n");
	for (i = 0; i <= 5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	for (i = 0; i <= 5; i++)
	{
		x =+ a[i];
	}
	int average;

	average = x / 5;

	printf("the average score of this student is %d.\n", average);
	return (0);
}
