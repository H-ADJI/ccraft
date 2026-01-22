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

char *read_line() ;
StrArray *create_StrArray(int capacity) ;
Command *tokenize(char line[]) ;
void print_StrArr(StrArray *array) ;
void free_cmd(Command *cmd) ;
void execute_cmd(Command *cmd) ;
