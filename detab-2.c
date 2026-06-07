#include <stdio.h>

#define TABSTOP 8

int main() {
    int c, column;
    column = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = TABSTOP - (column % TABSTOP);
            for (int i = 0; i < spaces; ++i) {
                putchar(' ');
                ++column;
            }
        } else {
            putchar(c);
            if (c == '\n') {
                column = 0;
            } else {
                ++column;
            }
        }
    }

    return 0;
}