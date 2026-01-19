#include "lib/commands.h"
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
  StrArray *tokenz;
  do {
    prompt();
    line = read_line();
    tokenz = tokenize(line);
    execute_cmd(tokenz->elements);
    if (line) {
      free(line);
    }
    free_StrArray(tokenz);
  } while (1);

  return EXIT_SUCCESS;
}
