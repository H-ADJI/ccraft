#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char **strings; // Pointer to the array of string pointers
  int len;        // Number of actual strings in the array
} StringArray;

// TODO: function to free tokenz memory
StringArray *create_string_arrray(int capacity) {
  StringArray *arr = malloc(sizeof(StringArray));
  arr->strings = calloc(capacity, sizeof(char *));
  arr->len = 0;
  return arr;
}
void append(StringArray *str_array, char str[]) {
  // TODO: dynamic resizing
  str_array->strings[str_array->len] = str;
  str_array->len++;
}
void free_string_array(StringArray *str_array) {
  if (str_array->strings) {
    for (int i = 0; i < str_array->len; i++) {
      free(str_array->strings[i]);
    }
    free(str_array->strings);
    str_array->len = 0;
  }
}

StringArray *tokenize(char line[]) {
  // TODO: smarter memory alloc
  StringArray *tokenz = create_string_arrray(8);
  int scaner_start_idx = 0;
  int scaner_end_idx = 0;
  char *current_token = NULL;
  int token_size = 0;
  int line_length = strlen(line);

  while (scaner_end_idx < line_length) {

    char current_char = line[scaner_end_idx];
    token_size = scaner_end_idx - scaner_start_idx;
    if (current_char == ' ' || current_char == '\t' || current_char == '\n' ||
        current_char == '\0') {
      if (scaner_end_idx > scaner_start_idx) {
        current_token = malloc((token_size + 1) * sizeof(char));
        strncpy(current_token, line + sizeof(char) * scaner_start_idx,
                token_size);
        current_token[token_size] = '\0';
        append(tokenz, current_token);
      }
      scaner_end_idx++;
      scaner_start_idx = scaner_end_idx;
    } else {
      scaner_end_idx++;
    }
  }
  return tokenz;
}
void print_tokenz(StringArray *tokenz) {
  printf("number of tokenz : %d\n", tokenz->len);
  for (int i = 0; i < tokenz->len; i++) {
    printf("%s:%lu\n", tokenz->strings[i], strlen(tokenz->strings[i]));
  }
}

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
