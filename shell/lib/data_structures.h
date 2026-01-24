typedef struct {
  char **elements;
  int len;
  int capacity;
} StrArray;

StrArray *create_StrArray(int capacity) ;
void print_StrArr(StrArray *array) ;
void append(StrArray *str_array, char str[]) ;
