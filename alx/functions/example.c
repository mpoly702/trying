#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#define BUFFERSIZE 1024

extern char** environ;

int main(void)
{
	char *prompt = "$";
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *path = NULL;
	char *token = NULL;
	char **tokens = NULL;
	int i = 0;

	while(1)
	{	
		write(1, prompt, 1);
		nread = getline(&line, &len, stdin);

		tokens = (char **)malloc(sizeof(char *) * BUFFERSIZE);
		if (tokens == NULL)
		{
			perror("memory allocation failed");
			free(tokens);
			free(line);
			return (0);
		}
		token = strtok(line, " ");

		while (token != NULL)
		{
			tokens[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		tokens[i] = NULL;
		

		


	}
	free(line);
	free(tokens);
	return (0);
}
