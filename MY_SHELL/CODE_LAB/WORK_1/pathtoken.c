"shell.h"

char **pathtoken(char *string)
{
	int i = 0;
	char *token = NULL;
	char **args = NULL;
	ssize_t BUFZONE;
	
	BUFZONE = 0;

	args = (char **)malloc(sizeof(char *) * BUF);
	token = strtok(string, ":");

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
      		if (token == NULL)
		{
			perror("reallocation failed");
			free(args);
			return NULL;
		}
		token = strtok(NULL, ":");
	}
	args[i] = NULL;
	return args;
}
