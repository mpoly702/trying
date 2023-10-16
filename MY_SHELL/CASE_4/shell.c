#include "shell.h"

int main(void)
{

char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};
  
  int (*builtin_func[]) (char **) = {
  &lsh_cd,
  &lsh_help,
  &lsh_exit
};
  lsh_loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS;
}
