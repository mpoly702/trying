#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc! = 2)
	{
		fprintf(stderr, "use: readable < x.c\n");
		return EXIT_FAILURE;
	}

	if (!access(argv[1], R_OK)) 
	{
		printf("ok to read %s\n", argv[1])
			return EXIT_SUCCESS;
	}
	else 
	{
		perror(argv[1]);
		return EXIT_FAILURE;
	}
}
