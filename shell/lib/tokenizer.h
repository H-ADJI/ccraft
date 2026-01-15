typedef struct {
  char **strings; // Pointer to the array of string pointers
  int len;        // Number of actual strings in the array
} StringArray;

char *read_line() ;
StringArray *create_string_arrray(int capacity) ;
StringArray *tokenize(char line[]) ;
void free_string_array(StringArray *str_array) ;
void print_tokenz(StringArray *tokenz) ;
