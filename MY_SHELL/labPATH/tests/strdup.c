#include "main.h"

int main(void)
{
	char *command = "ls";
	char *path = NULL;
	char *pathcpy = NULL;
	char **ptoken = NULL;
	char **new_path = NULL;
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
		if (j == i)
		{
			ptoken[j] = NULL;
		}
		printf("%s\n", ptoken[j]);
		
	}

		new_path = (char **)malloc((i + 1) * sizeof(char *));
		/*init every element of the array..malloc for each of them*/
		for (y = 0; y < i; y++)
		{
			new_path[y] = (char *)malloc(strlen(ptoken[y]) + 2 + strlen(command) + 1);
			strcpy(new_path[y], ptoken[y]);
			strcat(new_path[y], "/");
			strcat(new_path[y], command);
		}
		new_path[y] ='\0';

	for (x = 0; x < i; x++)
	{
		printf("%s\n", new_path[x]);
	}

	for (x = 0; x < i; x++)
	{
		free(new_path[x]);
	}

	free(new_path);
	free(ptoken);
	free(pathcpy);

	return (0);
}
