#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF 1024
#define BIGGY 1024

int main(void)
{
	char *input = "ls -l";
	char **tokens = NULL;
	char *token = NULL;
	char *path = NULL;
	char *ptok = NULL;
	char **PATH = NULL;
	int i;
	int j;
	int count;
	int k;

	count = 0;
	i = 0;
	j = 0;
	k = 0;

	tokens = (char **)malloc(sizeof(char *) * BUF);

	if (tokens == NULL)
	{
		perror("error: ");
		free(tokens);
		return 1;
	}

	token = strtok(input, " ");
	while (tokens != NULL)
	{
		tokens[i] = token;
		i++;
		strtok(NULL, " ");
	}

	tokens[i] = NULL;
	
	path = getenv("PATH");

	PATH = (char **)malloc(sizeof(char *) * BIGGY);
	if (PATH == NULL)
	{
		perror("allocation failed:");
		free(PATH);
		return 1;
	}
	ptok = strtok(path, ":");

	while (ptok != NULL)
	{
		PATH[j] = ptok;
		j++;
		count++;
		strtok(NULL, ":");
	}
	PATH[j] = NULL;
	
	for (k = 0; k < count; k++)
	{
		strcat(PATH[k], tokens[0]);
		printf("%s\n", PATH[k]);
	}

	free(tokens);
	free(PATH);

	return (0);
}
