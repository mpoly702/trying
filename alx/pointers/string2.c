#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[] = "JANICEY";
	char ch;
	int i;
	int l;

	l = strlen(s1);
	printf("length of array is: %d \n", l);

	for (i = 0; i <= 7 / 2; i++)
	{
		ch = s1[i];
		s1[i] = s1[l - 1 - i];
		s1[l - 1 - i] = ch;
	}
	printf("%s", s1);
	printf("\n");
}
