typedef struct {
  char **elements; // Pointer to the array of string pointers
  int len;        // Number of actual strings in the array
  int capacity;   // Max Capacity
} StrArray;

char *read_line() ;
StrArray *create_StrArray(int capacity) ;
StrArray *tokenize(char line[]) ;
void print_StrArr(StrArray *array) ;
void free_StrArray(StrArray *str_array) ;
