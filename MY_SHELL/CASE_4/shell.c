#include "shell.h"

int main(void)
{

   int (*builtin_func[]) (char **) = {
  &lsh_cd,
  &lsh_help,
  &lsh_exit
};
  lsh_loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS;
}
