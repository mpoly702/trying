#include "shell.h"

int exit_sh(char **args)
{
	int args;

	args = atoi(args[1]);

	if (args <= 48)
	{
		return (0);
	}
	else if (args > 48)
		return (1);
}

int cd_sh(char **args)
{

	switch (args[1])
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

int env(char **env)
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

void setenv(char **args)
{
	int i;
	size_t currentLength;
	size_t newValueLength;
	size_t newStringLength;
	
    /*Iterate through the environ array to find the element with the given name*/
    for (i = 0; environ[i] != NULL; ++i) 
    {
        /*Check if the current element starts with the given name*/
        if (strncmp(environ[i], args[1], strlen(args[1])) == 0)
	{
            /*If found, append the new value to the existing string*/
            currentLength = strlen(environ[i]);
            newValueLength = strlen(args[2]);
            environ[i] = realloc(environ[i], currentLength + 1 + newValueLength + 1);
            strcat(environ[i], "=");
            strcat(environ[i], args[2]);
            return; /*Exit the function since the update is done*/
        }
    }

    /*If the name is not found, append a new environment variable to the environ array*/
    newStringLength = strlen(args[1]) + 1 + strlen(args[2]) + 1;
	/*+2 for the new element and NULL terminator*/
    environ = realloc(environ, (environSize() + 2) * sizeof(char *));
    environ[environSize()] = malloc(newStringLength);
    strcpy(environ[environSize()], args[1]);
    strcat(environ[environSize()], "=");
    strcat(environ[environSize()], args[2]);
	/*Null terminator for the updated environ array*/
    environ[environSize() + 1] = NULL;
}
