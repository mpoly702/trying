#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
	int j = 0;
	char *input = NULL;
	size_t BUFFER = 0;
	ssize_t nread;
	
	printf(">>>");
	nread = getline(&input, &BUFFER, stdin);
	char **inputtoken = tokenizer(input);
	char **pathtoken = extracttoken(path);
	
	for (j = 0; pathtoken[j] != NULL; j++)
	{
		strcat(pathtoken[j], inputtoken[0]);
		printf("%s\n", pathtoken[j]);
	}

	free(inputtoken);
	free(pathtoken);
	return (0);
}
