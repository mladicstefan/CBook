#include <stdio.h>
void toUpper(char* c)
{
    for (int i = 0; c[i] != '\0'; i++){
        if (c[i] >= 'a' && c[i] <='z'){
            c[i] += ('A' - 'a');
        };
        
    }
    printf("%s\n", c);

}

int main (void){
    char input[] = "waDaSAdDDDd";
    toUpper(input);

}