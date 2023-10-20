#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * get_location - Locates a command in the PATH.
 * @command: The command to locate.
 *
 * Return: If an error occurs or the command cannot be located - NULL.
 *         Otherwise - the full pathname of the command.
 */
char *get_location(char *command)
{
    char *path = getenv("PATH");
    struct stat st;

    if (path == NULL || path[0] == '\0') {
        return NULL;
    }

    char *path_copy = strdup(path); // Make a copy of PATH for modification
    char *token = strtok(path_copy, ":"); // Split the PATH by colons

    while (token != NULL) {
        char temp[strlen(token) + strlen(command) + 2];
        strcpy(temp, token);
        strcat(temp, "/");
        strcat(temp, command);

        if (stat(temp, &st) == 0) {
            free(path_copy); // Free the copy of PATH
            return strdup(temp); // Return a duplicate of the found path
        }

        token = strtok(NULL, ":");
    }

    free(path_copy); // Free the copy of PATH
    return NULL;
}

int main() {
    char *command = "ls"; // Change this to the command you want to locate
    char *location = get_location(command);

    if (location != NULL) {
        printf("Location of %s: %s\n", command, location);
        free(location); // Free the allocated memory
    } else {
        printf("%s not found in PATH\n", command);
    }

    return 0;
}
