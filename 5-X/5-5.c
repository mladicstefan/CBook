
int
strencmp(char *s, char*t, int n)
{
    for (int i = 0; i < n; i++, s++, t++){
        if (*s != *t) { return *s - *t; }

        if (*s == '\0') { return 0; }
    }
    return 0;
}
void strencpy(char *s, char *t, int n) {
    int i = 0;
    while (i < n && (*t != '\0')){
        *s++ = *t++;
        i++;
    }
    while (i < n){
        *s++ = '\0';
        i++;
    }
}