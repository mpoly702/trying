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
