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

	switch (args)
	{
		case '..':
		 	case_cd_one();
			break;
		case '-':
			case_cd_two();
			break;
		default:
			return (1);
	}
		return (1);
}

int env()
{
	char **env = NULL;
	
    /*Iterate through environ to access environment variables*/
    for (env = environ; *env != NULL; env++)
    {
        /*Use the write function to print each string to standard output*/
        write(STDOUT_FILENO, *env, strlen(*env));
        write(STDOUT_FILENO, "\n", 1);
    }

    return (1);
}
