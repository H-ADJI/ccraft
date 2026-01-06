#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  size_t len = 64; // default is 120
  char *line = (char *)malloc(len);
  if (line == NULL) {
    perror("Failed to allocate initial line buffer");
    return EXIT_FAILURE;
  }
  size_t read;
  printf("chell >");
  while ((read = getline(&line, &len, stdin)) != -1) {
    if (read > 0 && line[read - 1] == '\n') {
      line[read - 1] = '\0';
    }
    printf("%s\n", line); // echo back cmd, implement execution later
    printf("chell >");
  }
  if (line) {
    free(line);
  }

  return EXIT_SUCCESS;
}
