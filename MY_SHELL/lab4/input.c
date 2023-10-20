#include "shell.h"
	
char *input(void)
{
	char *input = NULL;
	size_t BUFFER;
	ssize_t nread;

	nread = getline(&input, &BUFFER, stdin);
	if (nread == 0)
	{
			free(input);
			return (0);
	}
	else if (nread == -1)
	{
		perror("EXIT");
		free(input);
		exit(EXIT_FAILURE);
	}

	if (input[nread - 1] == '\n')
	{
		input[nread - 1] = '\0';
	}
	return input;
}
	
