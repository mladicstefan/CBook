#include <stdint.h>
#include <stdio.h>

int any(const char* s1, const char* s2){
    int i,j;
    char* found;
    for (i = 0; s1[i] != '\0'; i++){
        for(j=0; s2[j] != '\0'; j++){
            if (s1[i] == s2[j]){
                printf("Letter: %c\n",s1[i]);
            }
        }
    }
    return -1;
}

int main(void){
    char* s1 = "If someone sees this when i make it, please message me to delete it";
    char* s2 = "Wagyu beef steak with Tom and Bryan";
    any(s1,s2);
    return 0;
}