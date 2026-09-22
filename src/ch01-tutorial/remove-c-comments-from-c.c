#include <stdio.h>

int main() {
    int c;

    int inComment = 0;
    char prevChar;
    while ((c = getchar()) != EOF) {
        if (c == '*' && prevChar == '/') {
            inComment = 1;
            prevChar = '\0';
            continue;
        }

        if (c == '/' && prevChar == '*') {
            inComment = 0;
            prevChar = '\0';
            continue;
        }

        if (inComment == 0 && prevChar != '\0') {
            putchar(prevChar);
        }

        prevChar = c;
    }

    putchar(prevChar);

    return 1;
}