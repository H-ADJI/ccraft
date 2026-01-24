#include "data_structures.h"

typedef struct {
  StrArray *args;
  char *input;
  char *output;
} Command;

void free_cmd(Command *cmd) ;
void execute_cmd(Command *cmd) ;
