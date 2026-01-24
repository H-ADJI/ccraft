#include "commands.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define DEFAULT_ARRAY_CAPACITY 8

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
