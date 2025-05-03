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

int getint(int* pn){
    int c, sign;

    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c!= '+' && c != '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-'){
        int next = getch();
        if (!isdigit(next)){
            ungetch(next);
            ungetch(c);
            return 0;

        }
        c = next;
    }
        
        
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main(void) {
    int num;
    int result;

    printf("Enter a number: ");
    result = getint(&num);

    if (result > 0 || result == '\n')  // something was read
        printf("You entered: %d\n", num);
    else if (result == 0)
        printf("Invalid input.\n");
    else if (result == EOF)
        printf("End of input.\n");

    return 0;
}
