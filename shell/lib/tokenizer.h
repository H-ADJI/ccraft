typedef struct {
  char **strings; // Pointer to the array of string pointers
  int len;        // Number of actual strings in the array
} StringArray;
StringArray create_string_arrray(int capacity) ;
StringArray tokenize(char line[]) ;
