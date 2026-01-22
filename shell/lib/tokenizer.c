#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define DEFAULT_ARRAY_CAPACITY 8

typedef struct {
  char **elements;
  int len;
  int capacity;
} StrArray;

typedef struct {
  StrArray *args;
  char *input;
  char *output;
} Command;

StrArray *create_StrArray(int capacity) {
  StrArray *arr = malloc(sizeof(StrArray));
  arr->elements = calloc(capacity, sizeof(char *));
  arr->len = 0;
  arr->capacity = capacity;
  return arr;
}

void print_StrArr(StrArray *array) {
  printf("number of elements: %d\n", array->len);
  printf("capacity of the array : %d\n", array->capacity);
  for (int i = 0; i < array->len; i++) {
    printf("%s:%lu  ", array->elements[i], strlen(array->elements[i]));
  }
  printf("\n");
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

void free_cmd(Command *cmd) {
  StrArray *array = cmd->args;
  if (array->elements) {
    for (int i = 0; i < array->len; i++) {
      free(array->elements[i]);
    }
    free(array->elements);
    array->len = 0;
  }
  free(array);
  if (cmd->output) {
    free(cmd->output);
  }
  if (cmd->input) {
    free(cmd->input);
  }
  free(cmd);
}
typedef struct ScannerToken {
  char *token;
  int updated_start_index;
} ScannerToken;

ScannerToken consume_token(char line[], int scaner_start_index) {
  ScannerToken token;
  char current_char = line[scaner_start_index];
  int scaner_end_index = scaner_start_index;
  while (!(current_char == ' ' || current_char == '\t' ||
           current_char == '\n' || current_char == '\0' ||
           current_char == '#')) {
    scaner_end_index++;
    current_char = line[scaner_end_index];
  }
  int token_size = scaner_end_index - scaner_start_index;
  token.token = malloc((token_size + 1) * sizeof(char));
  strncpy(token.token, line + sizeof(char) * scaner_start_index, token_size);
  token.token[token_size] = '\0';
  token.updated_start_index = scaner_end_index;
  return token;
}
Command *tokenize(char line[]) {
  StrArray *args = create_StrArray(DEFAULT_ARRAY_CAPACITY);
  Command *cmd = malloc(sizeof(Command));
  ScannerToken token;
  cmd->output = NULL;
  cmd->input = NULL;
  int scaner_index = 0;
  int line_length = strlen(line);
  char current_char;

  while (scaner_index < line_length) {
    current_char = line[scaner_index];
    if (current_char == ' ' || current_char == '\t' || current_char == '\n' ||
        current_char == '\0') {
      scaner_index++;
    } else if (current_char == '<') {
      // TODO: handle list of IO redirct
      scaner_index++;
      token = consume_token(line, scaner_index);
      cmd->input = token.token;
      scaner_index = token.updated_start_index;

    } else if (current_char == '>') {
      // TODO: handle list of IO redirct
      scaner_index++;
      token = consume_token(line, scaner_index);
      cmd->output = token.token;
      scaner_index = token.updated_start_index;
    } else if (current_char == '#') {
      break;
    } else {
      token = consume_token(line, scaner_index);
      append(args, token.token);
      scaner_index = token.updated_start_index;
    }
  }
  cmd->args = args;
  return cmd;
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
