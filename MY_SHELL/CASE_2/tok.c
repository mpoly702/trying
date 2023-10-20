#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *prompt = "$";
	char *input = NULL;
	int nread;
	size_t size = 0;
	char *token = NULL;
	char **arrays = NULL;
	size_t i = 0;
	size_t newBUF;
	char ** narrays = NULL;
	size_t BUF;

	BUF = 64;

	while (1)
	{
		write(1, prompt, strlen(prompt));
		nread = getline(&input, &size, stdin);
		if (nread == -1)
		{
			perror("getline failed");
			free(input);
			return 1;
		}
		else if (nread > 0)
		{
			token = strtok(input, " ");
			arrays = (char **)malloc(BUF * sizeof(char *));		
			while(token != NULL)
			{
				arrays[i] = token;
				i++;

				if (i >= BUF)
				{
					newBUF = 2 * BUF;
					narrays = realloc(arrays, newBUF * sizeof(char *));
					
					if (!arrays)
					{
						perror("reallocation failed");
						exit(EXIT_FAILURE);
					}
					arrays = narrays;
					BUF = newBUF;
				}
			}
			strtok(NULL, " ");
			for (i = 0; i < BUF; i++)
			{
				if (arrays[i] == NULL)
				{
					printf("End of the array at position %ld\n", i);
					break;
				}
				printf("Array%ld: %s\n", i, arrays[i]);
			}
			
		}
		arrays[i] = NULL;
		free(input);
		free(arrays);
		break;
	}
	return (0);
}
