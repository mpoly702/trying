#include "shell.h"

/**
 * instance - this function writes a prompt to the terminal
 */

void instance(void)
{
	char *instance;

	instance = "$";

	write(1, instance, 1);
}

