#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

#define BUF 1024

char **tokenizer(char *string);
int main(int argc, char **argv[]);
char *input(void);

#endif
