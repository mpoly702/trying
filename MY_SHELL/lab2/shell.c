#include "shell.h"
	
int main(int argc, char **argv[])
{
	
	char *input = NULL;
	char *instance;
	size_t BUFFER;
	ssize_t nread;
	pid_t pid;
	pid_t wpid;
	int status;
	
	instance = "$";
	BUFFER = 0;

while (1)
{

	write(1, instance, 2);
	nread = getline(&input, &BUFFER, stdin);
	if (nread == -1)
	{
		if(feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Reading_Line");
			free(input);
			exit(EXIT_FAILURE);
		}
	}
	if (input[nread - 1] == "\n");
{
	input[nread - 1] = '\0';
}
	char **inputtoken = tokenizer(input);
	 if (access(inputoken[0], F_OK) == -1)
	{
		perror ("command not found");
	}
	
	free(input);
	free(inputtoken);
}	
	return 0;	
}




