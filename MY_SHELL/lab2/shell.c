#include "shell.h"

int main(void)
{
	char *in;
	do
	{
		in = input();

		free(in);
	}
	while (1);

	return (0);
}
