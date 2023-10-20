#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *input;
	char *prompt = ">";
	size_t size = 0;
	ssize_t nread;

	write(1, prompt, 2);
	nread = getline(&input, &size, stdin);
	write(1, input, nread);
	free(input);

	return (0);		
}
