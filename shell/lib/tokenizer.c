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
char *consume_token(char line[], int scaner_start_idx, int scaner_end_idx) {
  int token_size = scaner_end_idx - scaner_start_idx;
  if (token_size == 0) {
    return NULL;
  }
  char *current_token = malloc((token_size + 1) * sizeof(char));
  strncpy(current_token, line + sizeof(char) * scaner_start_idx, token_size);
  current_token[token_size] = '\0';
  return current_token;
}
Command *tokenize(char line[]) {
  StrArray *tokenz = create_StrArray(DEFAULT_ARRAY_CAPACITY);
  Command *cmd = malloc(sizeof(Command));
  cmd->output = NULL;
  cmd->input = NULL;
  int scaner_start_idx = 0;
  int scaner_end_idx = 0;
  char *current_token = NULL;
  int token_size = 0;
  int line_length = strlen(line);
  int input_token = 0;
  int output_token = 0;

  while (scaner_end_idx < line_length) {

    char current_char = line[scaner_end_idx];
    if (current_char == ' ' || current_char == '\t' || current_char == '\n' ||
        current_char == '\0') {
      current_token = consume_token(line, scaner_start_idx, scaner_end_idx);
      // TODO: refactor output / input token consumption since flag stays 1 and
      // forever for the rest of the loop
      if (current_token) {
        if (output_token) {
          cmd->output = current_token;
        } else if (input_token) {
          cmd->input = current_token;
        } else {
          append(tokenz, current_token);
        }
      }
      scaner_end_idx++;
      scaner_start_idx = scaner_end_idx;
    } else if (current_char == '>') {
      if (output_token) {
        // TODO: handle a list of redirection
        perror("syntax error, only one output redirection allowed");
        exit(EXIT_FAILURE);
      }
      output_token = 1;
      scaner_end_idx++;
    } else if (current_char == '<') {
      if (input_token) {
        // TODO: handle a list of redirection
        perror("syntax error, only one input redirection allowed");
        exit(EXIT_FAILURE);
      }
      input_token = 1;
      scaner_end_idx++;
    } else if (current_char == '#') {
      current_token = consume_token(line, scaner_start_idx, scaner_end_idx);
      if (current_token) {
        append(tokenz, current_token);
      }
      break;
    } else {
      scaner_end_idx++;
    }
  }
  cmd->args = tokenz;
  return cmd;
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
