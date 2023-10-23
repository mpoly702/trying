#include "shell.h"

/**
 * get_path - Locates a command in the PATH.
 * @command: The command to locate.
 *
 * Return: If an error occurs or the command cannot be located - NULL.
 *         Otherwise - the full pathname of the command.
 */
char *get_path(char *command)
{
    char *path = NULL;
    struct stat st;
    char *path_copy = NULL;
    char *token;
    char *temp;


    path = getenv("PATH");

    if (path == NULL || path[0] == '\0') {
        return NULL;
    }

    path_copy = _strdup(path); /*Make a copy of PATH for modification*/
    token = strtok(path_copy, ":"); /*Split the PATH by colons*/

    while (token != NULL) {
        temp = (char *)malloc(_strlen(token) + _strlen(command) + 2);
        _strcpy(temp, token);
        _strcat(temp, "/");
        _strcat(temp, command);

        if (stat(temp, &st) == 0) 
	{
            free(path_copy); /*Free the copy of PATH*/
            return _strdup(temp); /*Return a duplicate of the found path*/
        }

        token = strtok(NULL, ":");
    }

    free(path_copy); /*Free the copy of PATH*/
    return NULL;
}
