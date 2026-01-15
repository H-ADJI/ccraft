#include "lib/tokenizer.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void execute_cmd(char *args[]) {
  pid_t pid = fork();
  if (pid == 0) {
    if (execvp(args[0], args) < 0) {
      perror(args[0]);
      exit(EXIT_FAILURE);
    }
  }
  waitpid(pid, NULL, 0);
}

int main(int argc, char *argv[]) {
  char *line;
  StrArray *tokenz;
  do {
    printf("chell > ");
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
