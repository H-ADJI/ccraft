#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char *builtin_commands[] = {"cd", "exit"};

int is_builtin_cmd(char *cmd) {
  int n = sizeof(builtin_commands) / sizeof(builtin_commands[0]);
  for (int i = 0; i < n; i++) {
    if (strcmp(cmd, builtin_commands[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

void execute_cmd(char *args[]) {
  pid_t pid = fork();
  if (pid == 0) {
    if (execvp(args[0], args) < 0) {
      perror(args[0]);
      exit(EXIT_FAILURE);
    }
  }
  waitpid(pid, NULL, 0);
}
