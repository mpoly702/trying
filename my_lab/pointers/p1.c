#include <stdio.h>
#define MAX 5

int main(void)
{	
int a[MAX] = {5,10,15,25,20};
int i;
int *mover;

	mover = a;
	for (i = 0; i < MAX; i++)
	{
		if (*mover == 20)
		{
			printf("element found in index number %d\n", i);
			return (0);
		}
		mover++;
	}
return (0);
}
