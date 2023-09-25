#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[] = "Ripple";
	char s2[] = "b29";
	char s3[] = "i24";
	char *r, *t;

	r = strpbrk(s1, s2);
	t = strpbrk(s1, s3);

	if (r != 0)
		printf("this is a landslide victory\n");
	else
		printf("try again next time\n");

	if (t != 0)
		printf("Congratulations! you are the winner\n");
	else
		printf("Better luck next time\n");

	return (0);
}
