#include "shell.h"

/**
 * execute - Execute shell commands
 * @args: An array of strings representing the command and its arguments
 *
 * Description:
 *   This function takes an array of strings containing a shell command
 *   and its arguments. It forks a new process to execute the command and
 *   waits for the child process to complete. It returns 1 to indicate
 *   successful execution.
 *
 * Return: 1 for successful execution, or an error code.
 */
int execute(char **args)
{
    /* Function code here */

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
			xpid = waitpid(pid, &status, WUNTRACED);
			if (xpid == -1)
			{
				perror("error:wait");
				return (1);
			}
	}

	return (1);
}

