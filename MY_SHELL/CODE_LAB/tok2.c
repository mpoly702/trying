#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define BUF 1024


char **extracttoken(char *string)
{
	int i = 0;
	char *token = NULL;
	char **args = NULL;
	ssize_t BUFZONE = 0;

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

char **tokenizer(char *string)
{
	int i = 0;
	char *token = NULL;
	char **args = NULL;
	ssize_t BUFZONE = 0;

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
      		if (token == NULL)
		{
			perror("reallocation failed");
			free(args);
			return NULL;
		}
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return args;
}



int main(void)
{
	char *path = getenv("PATH");
	char *input = NULL;
	size_t BUFFER = 0;
	int i = 0;
	int j;
	j = 0;
	ssize_t nread;
	
	printf(">>>");
	nread = getline(&input, &BUFFER, stdin);
	char **inputtoken = tokenizer(input);
	char **pathtoken = extracttoken(path);
	
	


    	free(pathtoken);
    	free(input);
    	free(inputtoken);

    return 0;
}
