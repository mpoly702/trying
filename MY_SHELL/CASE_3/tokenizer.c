#include "shell.h"

char **tokenizer(char *input)
{
	int bufsize;
	int i;
	char **tokens = NULL;
	char *token = NULL;

	bufsize = LSH_TOK_BUFSIZE;
	i = 0;
	tokens = (char **)malloc(bufsize * sizeof(char *));

	if (!tokens)
	{
		perror("MEMORY ALLOCATION FAILED");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, LSH_TOK_DELIM);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		if(i >= bufsize)
		{
			bufsize += LSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("reallocation denied");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[i] = NULL;
	return tokens;
}
