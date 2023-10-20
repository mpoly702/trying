#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

#define BUF 1024

extern char **environ;

void instance(void);
char *input(void);
char **tokenizer(char *string);
char *get_path(char *command);
int execute(char **args);

/*string functions*/
int _strlen(const char *x);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t x);
char *_strchr(char *x, char y);
int _strspn(char *x, char *acc);
int _strcmp(char *x1, char *x2);
int _strncmp(const char *x1, const char *x2, size_t y);
char *_strdup(const char *x);
void _memcpy(void *n, const void *p, unsigned int buf);


#endif
