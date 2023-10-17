#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"


struct StringFunctionPair {
    char *str;
    void (*func)();
};

char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};

int (*builtin_func[]) (char **);
int lsh_exit(char **args);
int lsh_help(char **args);
int lsh_cd(char **args);
int lsh_num_builtins();
int lsh_execute(char **args);
int lsh_launch(char **args);
void lsh_loop(void);
char *lsh_read_line(void);
char **lsh_split_line(char *line);
int main(void);

#endif
