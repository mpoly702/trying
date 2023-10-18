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
	int accesscmd;
	char *command_paths = NULL;
	
	printf(">>>");
	nread = getline(&input, &BUFFER, stdin);
	char **inputtoken = tokenizer(input);
	char **pathtoken = extracttoken(path);



	for (i = 0; pathtoken[i] != NULL; i++) 
	{
        int path_len = strlen(pathtoken[i]);
        int cmd_len = strlen(inputtoken[0]);
        char *command_paths[i] = (char *)malloc(path_len + 1 + cmd_len + 1); /* +2 for '/' and NULL*/

        if (command_paths[i] == NULL) 
	{
            perror("Memory allocation error");
            exit(1);
        }

        strcpy(command_paths[i], pathtoken[i]);
        command_paths[i][path_len] = '/';
        strcpy(command_paths[i] + path_len + 1, inputtoken[0]);
        printf("%s\n", command_paths[i]);
    }

    command_paths[i] = NULL;

    free(input);
    free(inputtoken);

    for (int i = 0; pathtoken[i] != NULL; i++) {
        free(command_paths[i]);
    }

    free(pathtoken);
    free(command_paths);
    free(input);
    free(inputtoken);

    return 0;
}







	
	pathtoken[i] = NULL;
	

	free(input);
	free(inputtoken);
	free(pathtoken);
	return (0);
}
