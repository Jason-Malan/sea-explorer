#include <stdio.h>

#define LINE_STOP 39 // 0 indexed
#define MAX_WORD 100

// All the chars before the last empty space before the line_stop count.
int main() {
    int column = 0;
    int word_buffer[MAX_WORD];
    int word_buffer_length = 0;

    int c;
    while ((c = getchar()) != EOF) 
    {
        if (column == LINE_STOP) 
        {
            if (c == ' ') 
            {
                putchar('\n');
                column = 0;
            }
            else 
            {
                putchar('\n');
                column = word_buffer_length;
            }

            continue;
        }

        if (c == '\n') 
        {
            if (word_buffer_length > 0) 
            {
                for (int i = 0; i < word_buffer_length; ++i) 
                {
                    putchar(word_buffer[i]);
                }
                word_buffer_length = 0;
            }
            column = 0;
            putchar('\n');
            continue;
        }

        if (c == ' ')
        {
            if (word_buffer_length > 0) 
            {
                for (int i = 0; i < word_buffer_length; ++i) 
                {
                    putchar(word_buffer[i]);
                }
                word_buffer_length = 0;
            }
            putchar(' ');
            column++;
        } 
        else
        {
            //probs check max word here...
            word_buffer[word_buffer_length++] = c;
            column++;
        }
    }    

    return 1;
}