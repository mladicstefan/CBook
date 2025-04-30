#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAP 64
//A very VERY over-engineered solution for the 1-19 exercise

typedef struct{
  char* data; //pointer to char buffer
  size_t len;
  size_t cap;
} Array;

void array_reserve(Array* a, size_t min_cap){
  if (a->cap >= min_cap)
    return;
  size_t new_cap = a->cap ? a->cap *2 : INITIAL_CAP;
  if (new_cap < min_cap)
    new_cap = min_cap;

  char* tmp = realloc(a->data,new_cap);
  if (!tmp) {
    perror("realloc");
    exit(1);
  }
  a->data = tmp;
  a->cap = new_cap;
}

void array_push(Array *a, char c){
  array_reserve(a, a->len + 1);
  a->data[a->len++] = c;
}

void array_clear(Array *a){
  a->len = 0;
}

void array_free(Array *a){
  free(a->data);
  a->data = NULL; //no dangling pointers this time ;)
  a->len = a->cap = 0;
}

void reverse(Array *a){
  size_t i = 0;
  size_t j = a->len ? a->len - 1 : 0;

  while (i < j){
    char tmp    = a->data[i];
    a->data[i]  = a->data[j];
    a->data[j]  = tmp;
    i++;
    j--;
  }
}

int main(void){

  Array line = {
    .data = NULL,
    .len = 0,
    .cap = 0
  };
  int c;

  while ((c = getchar()) != EOF){
    array_push(&line, (char)c);
    if (c == '\n'){
      line.len--;
      reverse(&line);
    
      fwrite(line.data,1,line.len,stdout);
      array_clear(&line);
    }
  }

  if (line.len){
    reverse(&line);
    fwrite(line.data, 1, line.len, stdout);
  }
  array_free(&line);
  return 0;

}
