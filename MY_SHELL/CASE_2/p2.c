#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char *input = NULL;
	size_t size = 0;
	ssize_t nread;
	char *prompt = "$";

	while (1)
	{
		write(1, prompt, strlen(prompt));
		nread = getline(&input, &size, stdin);

		if (nread == -1)
		{
			perror("getline failed");
			free(input);
			return -1;
		}
		else if (nread > 0)
		{
			write(1, input, strlen(input));
		}
		else
		{
			write(1, "\n", 1);
		}
		free(input);
	}
	return(0);
}

