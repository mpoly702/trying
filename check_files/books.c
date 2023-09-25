#include <stdio.h>
#include "main.h"

int bk_calc(int copies, int pages)
{

	float books;
	int papers;
	float reams;
	float A2;

	papers = copies * (pages / 4);
	reams = papers / 500;
	A2 = reams / 6;
	printf("This book will require: %d sheets of papers to be produced\n", papers);
	printf("This project will require %f reams of A4 paper\n", reams);
	printf("This project will require %f reams of A2 paper\n", A2);

	return (0);

}

int main(void)
{
	
	int i;
	int j;
	int k;

	printf("Enter number of copies to be produced\n");
	scanf("%d", &i);
	printf("Enter number of pages to be in a book\n");
	scanf("%d", &j);

	bk_calc(i, j);

	return (0);
}
