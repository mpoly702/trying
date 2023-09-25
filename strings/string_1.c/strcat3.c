#include <stdio.h>
#include <string.h>

#define MAX 50

int main(void)
{
	char set [MAX] = "this is impudence ";
	char set2 [MAX] = "exactly as i have expected";

	strcat(set, set2);
	
	printf("%s\n", set);
	return (0);
}
