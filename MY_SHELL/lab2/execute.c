#include "shell.h"

int execute(char **args)
{
	pid_t pid;

	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
	} 
	else if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
	
	return 1;
}
