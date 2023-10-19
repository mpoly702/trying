#include "shell.h"
	
char *input(void)
{
	char *input = NULL;
	char *instance;
	size_t BUFFER;
	ssize_t nread;

	write(1, instance, 2);
	nread = getline(&input, &BUFFER, stdin);
	if (nread == 0)
	{
			free(input);
			exit(EXIT_SUCCESS);
	}
	else
	{
		perror("Reading_Line");
		free(input);
		exit(EXIT_FAILURE);
	}

	if (input[nread - 1] == "\n");
	{
		input[nread - 1] = '\0';
	}
	return input;
}
	
