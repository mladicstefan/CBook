#include <stdio.h>

#define CHARS 256
// interpets the input via numeric codes
int main(void){
  int c;
  int freq[CHARS] = {0};

  while ((c = getchar()) != EOF){ //to hit EOF and initate counting press CTRL+D (linux) or Ctrl+Z+Enter on Win
    ++freq[(unsigned char) c];
  }

  for (int i = 0; i < CHARS; i++){
    if (freq[i]>0){
      printf("%3d",i);
    }
    if (i == '\n')
      printf("'\\n'");
    else if (i == '\t')
      printf("'\\t'");
    else if (i == ' ')
      printf("' '");
    else if (i >= 32 && i < 127)
      printf(" '%c'", i);
    else
      printf(" '?'");
    
    printf(" | ");
    
    for (int j = 0; j < freq[i]; j++){
      putchar('*');
    }
    putchar('\n');
  }
  return 0;
}
