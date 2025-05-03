#include <stdio.h>
#include <string.h>

void replace_blanks(char *s) {
    if (*s == '\0') 
        return;

    if (*s == ' ' && *(s+1) == ' ') {
        char *p = s+1;
        while (*p) {
            *p = *(p+1);
            p++;
        }
        replace_blanks(s);
    } else {
        replace_blanks(s+1);
    }
}

int main(void) {
    char buf[100];

    if (fgets(buf, sizeof buf, stdin)) {
        buf[strcspn(buf, "\n")] = '\0';
        replace_blanks(buf);
        printf("%s\n", buf);
    }
    return 0;
}
