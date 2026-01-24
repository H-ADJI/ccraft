#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef struct {
  char **elements;
  int len;
  int capacity;
} StrArray;
StrArray *create_StrArray(int capacity) {
  StrArray *arr = malloc(sizeof(StrArray));
  arr->elements = calloc(capacity, sizeof(char *));
  arr->len = 0;
  arr->capacity = capacity;
  return arr;
}

void print_StrArr(StrArray *array) {
  printf("number of elements: %d\n", array->len);
  printf("capacity of the array : %d\n", array->capacity);
  for (int i = 0; i < array->len; i++) {
    printf("%s:%lu  ", array->elements[i], strlen(array->elements[i]));
  }
  printf("\n");
}

void append(StrArray *str_array, char str[]) {
  if (str_array->len == str_array->capacity) {
    char **temp_ptr =
        realloc(str_array->elements, str_array->capacity * 2 * sizeof(char *));
    if (temp_ptr == NULL) {
      perror("Capacity Expension failed");
      exit(EXIT_FAILURE);
    }
    str_array->capacity *= 2;
    str_array->elements = temp_ptr;
  }

  str_array->elements[str_array->len] = str;
  str_array->len++;
  for (int i = str_array->len; i < str_array->capacity; i++) {
    str_array->elements[i] = NULL;
  }
}
