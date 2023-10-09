#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  str_dupli(char *x, char **y)
{
	size_t length = strlen(x);

	*y = (char*)malloc((length + 1) * sizeof(char));

	if (*y == NULL)
	{
		fprintf(stderr, "failed Memory allocation\n");
		exit(1);
	}
	
	strcpy(*y, x);
}

int main(void)
{
	char *src = "What a Week?";
	char *des = NULL;

	str_dupli(src, &des);

	printf("contents of new string: %s\n", des);

	free(des);

	return(0);
}
