#include "shell.h"

/*tokenizer - This function tokenizes the input string
 * @string - This string is the parameter to be tokenized
 *
 * Return - An array of Strings
 */

char **tokenizer(char *string)
{
	int i;
       	char *token = NULL; 
	char **args = NULL; 
	ssize_t BUFZONE;

	BUFZONE = 0;
	i = 0;
	args = (char **)malloc(sizeof(char *) * BUF);
	token = strtok(string, " ");
	if (token == NULL)
	{
		perror("error:");
		free(args);
		return NULL;
	}
	while (token != NULL)
	{
		args[i] = token;
		i++;
		if (i >= BUF) 
		{
      			BUFZONE += BUF * 2;
      			args = realloc(args, BUF * sizeof(char*));
		}
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return args;
}
