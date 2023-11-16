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

void cd_sh(char *args)
{
	size_t pathSize;
	char *cwd = NULL;

	pathSize = 256;
	cwd = (char *)malloc(pathSize);

	switch (args)
	{
		case '..':
		
		
			
}
