#include "shell.h"

/*
 * execute - This function executes commands
 * @args: This array of strings is a parameter for the function
 *
 * Description: This function executes commands
 * Return: 1 an integer that indicates a successful execution
 */

int execute(char **args)
{
	pid_t pid;
	pid_t xpid;

	int status;

	if (args[0] == NULL)
	{
		return (0);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("hsh: command not found");
		return (1);
	}
	else
	{
		do {
			xpid = waitpid(pid, &status, WUNTRACED);
			if (xpid == -1)
			{
				break;
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

	}

	return (1);
}
