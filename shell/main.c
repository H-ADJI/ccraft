#include "lib/tokenizer.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void prompt(void) {
  char *cwd = getcwd(NULL, 0);
  printf("[%s] - cshell > ", cwd);
  free(cwd);
}
int main(int argc, char *argv[]) {
  char *line;
  Command *cmd;
  do {
    prompt();
    line = read_line();
    cmd = tokenize(line);
    execute_cmd(cmd);
    if (line) {
      free(line);
    }
    free_cmd(cmd);
  } while (1);

  return EXIT_SUCCESS;
}
