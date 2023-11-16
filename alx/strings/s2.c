#include <stdio.h>

int main(void)
{
	char *str = "w3resource.com";
	int i = 0;
	
	while (str[i] != '\0')/*you can use a looping variable to move through a string*/
		i++;

	printf("the length of the string is: %d\n", i);

	return(0);
}
