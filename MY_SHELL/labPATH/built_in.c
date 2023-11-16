#include "shell.h"

int exit_sh(char *args)
{
	int args;

	args = atoi(args[1]);

	if (args <= 48)
	{
		return (0);
	}
	else if (args == 48 || args > 57)
		return (1);
}

int cd_sh(char *args)
{
	size_t pathSize;
	char *cwd = NULL;

	pathSize = 256;
	cwd = (char *)malloc(pathSize);

	switch (args)
	{
		case '..':
		 if (cwd == NULL)
		 {
        		perror("malloc");
        		return (1);
		 }
		if (getcwd(cwd, pathSize) == NULL)
		{
        		perror("getcwd");
        		free(cwd);
			return (1);
		}
		removeLastDirectory(cwd);
		if (chdir(cwd) == -1);
		{
			perror("chdir fail");
			free(cwd);
			return (1);
		}
		return (0);
		
