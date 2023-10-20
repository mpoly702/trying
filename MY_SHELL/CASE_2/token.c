#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define BUF 24


int main(void)
{
	char string[BUF];
	int i = 0;
	char **args = NULL;

	printf("write your command here>>>>\n");
	scanf("%s", string);

	char *token = strtok(string, " ");
	
	if (token == NULL)
	{
		perror("error:");
		free(string);
		return -1;
	}
	else
	{
		**args = (char **)malloc(sizeof(char *) * 3);
		for (i = 0; i <= strlen(string); i++)
		{
			args[i] = token;
			i++;
			strtok(NULL, " ");
		}
	}
	for (i = 0; i <= strlen(string); i++)
	{
		printf("array %d: %s\n", i, args[i]);
	}
	args[i] = NULL;
	free(args);

	return (0);
}
