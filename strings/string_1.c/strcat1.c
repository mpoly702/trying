#include <stdio.h>
#include <string.h>

#define MAX 50

int main(void)
{
	char ret [MAX] = "this is ";
	char ret2 [MAX] = "the lord's doing and its marvelous in our sight";

	strcat(ret, ret2);

	printf("%s\n", ret);
	
		return (0);
}
