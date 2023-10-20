#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUF 1024

extern char **environ;

#define BUF 1024

void instance(void);
char *input(void);
char **tokenizer(char *string);
int execute(char **args);

#endif

