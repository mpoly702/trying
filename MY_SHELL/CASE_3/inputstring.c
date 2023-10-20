#include "shell.h"

char *input()
{
	char *input = NULL;
	size_t buffersize = 0;
	char *prompt = "$";

	write(1,prompt,1);
	nread = getline(&input, &buffersize, stdin);
	if (nread == -1)
	{
		perror("error getting input");
		free(input);
		exit(EXIT_FAILURE);
	}
	else
		return input;
}
