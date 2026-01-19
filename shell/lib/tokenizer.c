#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  char **elements; // Pointer to the array of string pointers
  int len;         // Number of actual strings in the array
  int capacity;    // Max Capacity
} StrArray;

StrArray *create_StrArray(int capacity) {
  StrArray *arr = malloc(sizeof(StrArray));
  arr->elements = calloc(capacity, sizeof(char *));
  arr->len = 0;
  arr->capacity = capacity;
  return arr;
}

void append(StrArray *str_array, char str[]) {
  if (str_array->len == str_array->capacity) {
    char **temp_ptr =
        realloc(str_array->elements, str_array->capacity * 2 * sizeof(char *));
    if (temp_ptr == NULL) {
      perror("Capacity Expension failed");
      exit(EXIT_FAILURE);
    }
    str_array->capacity *= 2;
    str_array->elements = temp_ptr;
  }

  str_array->elements[str_array->len] = str;
  str_array->len++;
  for (int i = str_array->len; i < str_array->capacity; i++) {
    str_array->elements[i] = NULL;
  }
}

void free_StrArray(StrArray *str_array) {
  if (str_array->elements) {
    for (int i = 0; i < str_array->len; i++) {
      free(str_array->elements[i]);
    }
    free(str_array->elements);
    str_array->len = 0;
  }
}

StrArray *tokenize(char line[]) {
  StrArray *tokenz = create_StrArray(1);
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
void print_StrArr(StrArray *array) {
  printf("number of elements: %d\n", array->len);
  printf("capacity of the array : %d\n", array->capacity);
  for (int i = 0; i < array->len; i++) {
    printf("%s:%lu  ", array->elements[i], strlen(array->elements[i]));
  }
  printf("\n");
}

char *read_line() {
  size_t buff_size = 0;
  char *line = NULL;
  if (getline(&line, &buff_size, stdin) == -1) {
    if (feof(stdin)) {
      printf("\nExiting shell...\n");
      exit(EXIT_SUCCESS);
    } else {
      perror("error reading line");
      exit(EXIT_FAILURE);
    }
  }
  return line;
}
