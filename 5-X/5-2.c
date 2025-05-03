#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];   
int bufp = 0;        

int getch(void)  
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getfloat(float *pn) {
    int c, sign;
    float power;
    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        int next = getch();
        if (!isdigit(next) && next != '.') {
            ungetch(next);
            ungetch(c);
            return 0;
        }
        c = next;
    }

    *pn = 0.0f;

    while (isdigit(c)) {
        *pn = 10.0f * *pn + (c - '0');
        c = getch();
    }

    if (c == '.') {
        c = getch();
        power = 1.0f;
        while (isdigit(c)) {
            *pn = 10.0f * *pn + (c - '0');
            power *= 10.0f;
            c = getch();
        }
        *pn /= power;
    }

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main(void) {
    float num;
    int result;

    printf("Enter a number: ");
    result = getfloat(&num);

    if (result > 0 || result == '\n')  // something was read
        printf("You entered: %f\n", num);
    else if (result == 0)
        printf("Invalid input.\n");
    else if (result == EOF)
        printf("End of input.\n");

    return 0;
}
