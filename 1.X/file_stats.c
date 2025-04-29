#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int ch;
    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;
    int inWord = 0;

    while ((ch = fgetc(file)) != EOF) {
        charCount++; 

        if (ch == '\n') {
            lineCount++;
        }

        if (isspace(ch)) {
            inWord = 0;
        } else if (inWord == 0) { 
            inWord = 1;
            wordCount++;
        }
    }

    fclose(file);

    printf("Characters: %d\n", charCount);
    printf("Words: %d\n", wordCount);
    printf("Lines: %d\n", lineCount);

    return 0;
}

