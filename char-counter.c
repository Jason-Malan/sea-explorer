#include <stdio.h>

int blanks_tabs_newlines_counter()
{
    int blanks = 0, tabs = 0, newlines = 0;
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++blanks;
        }
        if (c == '\t')
        {
            ++tabs;
        }
        if (c == '\n')
        {
            ++newlines;
        }
    }

    printf("blanks: %d, tabs: %d, newlines %d", blanks, tabs, newlines);

    return 0;
}

int copy_input_to_output_replacing_special_chars()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            printf("\\t");
        }
        else if (c == '\\')
        {
            printf("\\\\");
        }
        else
        {
            printf("%c", c);
        }
    }

    return 0;
}

int main()
{
    return copy_input_to_output_replacing_special_chars();
}

int counter()
{
    int nc, nl;

    nl = 0;
    while ((nc = getchar()) != EOF)
    {
        if (nc == '\n')
        {
            ++nl;
        }
    }

    printf("%d", nl);

    return 0;
}
