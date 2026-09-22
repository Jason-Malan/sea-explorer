#include <stdio.h>

#define TABSTOP 8

int main() {
    int c, column;
    column = 0;
    int space_counter = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t' ) 
        {
            space_counter += 8;
        } 
        else if (c == ' ') 
        {
            space_counter += 1;
        } else {
            if (space_counter > 0) 
            {
                int spaces = TABSTOP - (column % TABSTOP);
            }

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