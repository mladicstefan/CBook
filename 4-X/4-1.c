#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* slice(char* src, int start,int len)
{
    char* result = malloc(len+1);
    if (!result) return NULL;
    strncpy(result,src + start, len);
    result[len] = '\0';
    return result;
}

int strindex(char s[], char t[])
{
    int t_len = strlen(t);
    int last_found = -1;

    for(int i = 0l; s[i] != '\0';i++){
        char* match = slice (s,i,t_len);
        if (!match) continue;

        if (strncmp(match,t,t_len) == 0 && strlen(match) == t_len){
            last_found = i;
        }
        free(match);
    }

    return last_found;
}

int main(void){
    int res = strindex("i love bananas so much", "bananas");
    printf("Index: %d\n", res);
}