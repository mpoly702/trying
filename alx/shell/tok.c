#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char *prompt = "$";
    char *input = NULL;
    size_t size = 0;
    ssize_t nread;
    char **args = NULL;
    char *token = NULL;
    int i = 0;
    int j;

    while (1) {
        size_t y = write(1, prompt, strlen(prompt));
        nread = getline(&input, &size, stdin);

        if (nread == -1) {
            perror("getline failed");
            free(input);
            free(args); // Free 'args' before exiting
            return -1;
        } else if (nread > 0) { // Changed this condition to check if any input was read
            args = (char **)malloc(sizeof(char *));

            if (args == NULL) {
                perror("memory allocation failed");
                free(input);
                return 1;
            }

            for (i = 0, token = strtok(input, " "); token != NULL; i++) {
                args = (char **)realloc(args, (i + 1) * sizeof(char *));

                if (args[i] == NULL) {
                    perror("MEMORY ALLOCATION FAILED");
                    return 1;
                }

                args[i] = (char *)malloc(strlen(token) + 1);

                if (args[i] == NULL) {
                    perror("MEMORY ALLOCATION FAILED");
                    return 1;
                }

                for (j = 0; token[j] != '\0'; j++) {
                    args[i][j] = token[j];
                }
                args[i][j] = '\0';

                token = strtok(NULL, " ");
            }
        }

        // At this point, 'args' contains an array of strings
        for (j = 0; j < i; j++) {
            size_t x = write(1, args[j], strlen(args[j]));
        }

        // Free the memory allocated for 'args'
        for (j = 0; j < i; j++) {
            free(args[j]);
        }
        free(args);

        // Free the memory allocated for 'input'
        free(input);
    }

    return 0;
}
