#include "shell.h"

void removeLastDirectory(char *path)
{
   size_t length;
  size_t i;
  
    /*Find the length of the path*/
    length = strlen(path);

    if (length > 0)
    {
        /*Start from the end of the path*/
        i = length - 1;

        /*Find the last occurrence of the directory separator '/'*/
        while (i > 0 && path[i] != '/') 
        {
            i--;
        }

        /*If the last slash is found, remove the last directory*/
        if (path[i] == '/')
        {
            path[i] = '\0';
        }
    }
}

int cd_case_one(void)
{
   size_t pathSize;
	char *cwd = NULL;

	pathSize = 256;
	cwd = (char *)malloc(pathSize);
		 if (cwd == NULL)
		 {
        		perror("malloc");
        		return (1);
		 }
		if (getcwd(cwd, pathSize) == NULL)
		{
        		perror("getcwd");
        		free(cwd);
			return (1);
		}
		removeLastDirectory(cwd);
		if (chdir(cwd) == -1);
		{
			perror("chdir fail");
			free(cwd);
			return (1);
		}
      free(cwd);   
		return (0);
}
