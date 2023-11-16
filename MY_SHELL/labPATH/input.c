#include "shell.h"
/**
 * input - Handles input processing
 *
 * Description:
 *   This function reads input from the standard input (stdin) and
 *   processes it. It allocates memory for the input and adjusts the
 *   string as needed.
 *
 * Return: A pointer to the processed input or NULL in case of failure.
 */

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
		perror("exiting shell...");
		free(input);
		exit(EXIT_SUCCESS);
	}

	if (input[nread - 1] == '\n')
	{
	input[nread - 1] = '\0';
	}
	return (input);
}

