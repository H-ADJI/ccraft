#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int builtin_cd(char **args) { return 0; }
int builtin_exit(char **args) {
  // Implement any cleanup here before exiting
  printf("Exiting shell...\n");
  exit(EXIT_SUCCESS);
  // Unreachable, but good practice to show return type
  return 0;
}
typedef int (*builtin_cmd_ptr)(char **args);

typedef struct {
  char *name;
  builtin_cmd_ptr func;
} builtin_cmd;

builtin_cmd builtin_commands[] = {
    {"exit", builtin_exit},
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

void execute_cmd(char *args[]) {
  if (is_builtin_cmd(args) == EXIT_FAILURE) {
    pid_t pid = fork();
    if (pid == 0) {
      if (execvp(args[0], args) < 0) {
        perror(args[0]);
        exit(EXIT_FAILURE);
      }
    }
    waitpid(pid, NULL, 0);
  }
}
