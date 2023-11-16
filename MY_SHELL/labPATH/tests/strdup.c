#include "main.h"

int main(void)
{
	char *command = "ls";
	char *path = NULL;
	char *pathcpy = NULL;
	char **ptoken = NULL;
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;

	path = getenv("PATH");
	pathcpy = strdup(path);

	printf("%s\n\n\n\n", pathcpy);
	ptoken = pathtokenizer(pathcpy);
	for (i = 0; ptoken[i] != NULL; i++)
	{
		i++;
	}
	printf("%d\n", i);
	for (j = 0; j < i; j++)
	{
		printf("%s\n", ptoken[j]);
		
	}
	ptoken[j] = NULL;

	i = 24;
	for (y = 0; y < i + 1; y++)
	{
		strcat(ptoken[y], "/");
		strcat(ptoken[y], command);
	}

	for (x = 0; x < i; x++)
	{
		printf("%s\n", ptoken[x]);
	}

	free(ptoken);
	free(pathcpy);

	return (0);
}
