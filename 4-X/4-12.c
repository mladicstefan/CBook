#include <stdio.h>

void itoa(int n, char s[], int* idx){
    
    if (n < 0){
        s[(*idx)++] = '-';
        n = -n;
    }

    if (n / 10)
        itoa(n / 10, s, idx);

    s[(*idx)++] = (n % 10) + '0';
}

int main(void){
    int idx = 0;
    char str[100];
    itoa(2533245, str, &idx);
    str[idx] = '\0';
    printf("%s\n",str);
}