#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

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
  do {
    printf("chell >");
    line = read_line();
    printf("%s\n", line);

  } while (1);

  if (line) {
    free(line);
  }
  return EXIT_SUCCESS;
}
