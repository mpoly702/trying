#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	char array[3][50] = {"Hello, ", "Goodbye, ", "Welcome, "};
	char toConcat[] = "World";

	for (i = 0; i < 3; i++)
	{
		strcat(array[i], toConcat);
	}

	for (i = 0; i < 3; i++)
	{
		printf("Concatenated string %d: %s\n", i+1, array[i]);
	}

	return (0);
}
