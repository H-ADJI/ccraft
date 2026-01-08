#include "lib/tokenizer.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_line() {
  size_t buff_size = 0;
  char *line = NULL;
  if (getline(&line, &buff_size, stdin) == -1) {
    if (feof(stdin)) {
      printf("\nEOF, bye\n");
      exit(EXIT_SUCCESS);
    } else {
      perror("error reading line");
      exit(EXIT_FAILURE);
    }
  }
  return line;
}

int main(int argc, char *argv[]) {
  char *line;
  StringArray tokenz;
  do {
    printf("chell >");
    line = read_line();
    tokenz = tokenize(line);
    printf("number of tokenz : %d\n", tokenz.len);
    for (int i = 0; i < tokenz.len; i++) {
      printf("%s:%lu\n", tokenz.strings[i], strlen(tokenz.strings[i]));
    }

  } while (1);

  if (line) {
    free(line);
  }
  return EXIT_SUCCESS;
}
