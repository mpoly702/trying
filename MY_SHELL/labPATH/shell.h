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

typedef struct {
    const char *str;
    int (*func)(char **args);
} builtins;

void instance(void);
char *input(void);
char **tokenizer(char *string);
char *get_path(char *command);
int execute(char **args);
int exit_sh(char **args);
int cd_sh(char **args);
int env(char **environ);
int setenv(char **args);
int unsetenv(char **args);
int environSize();

void removeLastDirectory(char *path);
int cd_case_one(void);
int case_cd_two(void);

#endif

