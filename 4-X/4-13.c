
#include <string.h>
#include <stdio.h>
char* reverse(char* s, int left_bound, int right_bound) {
    if (left_bound >= right_bound)
        return s;

    char tmp = s[left_bound];
    s[left_bound] = s[right_bound];
    s[right_bound] = tmp;

    return reverse(s, left_bound + 1, right_bound - 1);
}
int main(void){
    char s[] = "I sometimes hate C...";
    reverse(s, 0, strlen(s) - 1);
    printf("Result: %s\n", s);
}