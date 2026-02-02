#include "data_structures.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct {
  StrArray *args;
  char *input;
  char *output;
} Command;

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
int builtin_cd(char **args) {
  char *target_dir;
  if (args[1] == NULL) {
    target_dir = getenv("HOME");
  } else {
    target_dir = args[1];
  }
  int result = chdir(target_dir);

  if (result == -1) {
    perror("Cannot change directory");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
int builtin_exit(char **args) {
  // TODO: Implement any cleanup here before exiting
  printf("Exiting shell...\n");
  exit(EXIT_SUCCESS);
  return 0;
}
typedef int (*builtin_cmd_ptr)(char **args);

typedef struct {
  char *name;
  builtin_cmd_ptr func;
} builtin_cmd;

builtin_cmd builtin_commands[] = {
    {"exit", builtin_exit},
    {"cd", builtin_cd},
};
int builtin_cmd_count = sizeof(builtin_commands) / sizeof(builtin_commands[0]);

int is_builtin_cmd(char **args) {
  char *cmd = args[0];
  for (int i = 0; i < builtin_cmd_count; i++) {
    if (strcmp(cmd, builtin_commands[i].name) == 0) {
      return builtin_commands[i].func(args);
    }
  }
  return EXIT_FAILURE;
}

void execute_cmd(Command *cmd) {
  char **args = cmd->args->elements;
  if (is_builtin_cmd(args) == EXIT_FAILURE) {
    pid_t pid = fork();
    if (pid == 0) {

      if (cmd->output) {
        mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
        int out = open(cmd->output, O_WRONLY | O_CREAT | O_TRUNC, mode);
        if (out == -1) {
          perror("Cannot open file for writing");
          exit(EXIT_FAILURE);
        }
        dup2(out, STDOUT_FILENO);
      }
      if (cmd->input) {
        int in = open(cmd->input, O_RDONLY);
        if (in == -1) {
          perror("Cannot open file for reading");
          exit(EXIT_FAILURE);
        }
        dup2(in, STDIN_FILENO);
      }

      if (execvp(args[0], args) < 0) {
        perror(args[0]);
        exit(EXIT_FAILURE);
      }
    }
    waitpid(pid, NULL, 0);
  }
}
