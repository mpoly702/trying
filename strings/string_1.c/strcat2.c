#include <stdio.h>
#include <string.h>

#define MAX 50

int main(void)
{
	char ret [MAX] = "this is ";
	char ret2 [MAX] = "the Lord's house and am glad to be there";
	
	strcat(ret, ret2);

	puts(ret);
	return (0);
}
