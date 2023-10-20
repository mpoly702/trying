#include "shell.h"

int main(void)
{
	char *in;
	char **tokens;
	int state;
	char *prompt;
	
	prompt = ">>>>";
	do
	{
		write(1, prompt, 2);
		in = input();
		tokens = tokenizer(in);
		state = execute(tokens);

		free(in);
		free(tokens);
	}
	while (state);

	return (0);
}
