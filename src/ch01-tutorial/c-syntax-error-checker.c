#include <stdio.h>

/*
    1.1 unmatched parentheses    ->  ()
    1.2 unmatched brackets       ->  []
    1.3 unmatched braces         ->  {}

    2.1 quotes single
    2.2 quotes double
    2.3 escape sequences
    
    3.1 comments
*/

#define MAX_IN_CHAR_STACK_DEPTH 10
#define WRONG_SYN_MSG "WRONG SYNTAX \n"

void HandleUnmatchedWrappers(int c, char inCharStack[], int inCharStackIndex);

int main() {
    char inCharStack[MAX_IN_CHAR_STACK_DEPTH] = {0};
    int inCharStackIndex = 0;
    int inDoubleQuotes = 0;
    int inSingleQuotes = 0;

    int c;
    while ((c = getchar()) != EOF) 
    {
        // doesnt really work if you have a double quote in two double quotes.
        if (c == '"') 
        {
            if (inDoubleQuotes == 0 || inSingleQuotes == 0) 
            {
                inDoubleQuotes = 1;
                inCharStack[inCharStackIndex++];
            } 
            else if (inDoubleQuotes == 1)
            {
                --inCharStackIndex;
            }
            continue;
        }

        if (inDoubleQuotes == 1) 
        {
            continue;
        }

        if (c == '\'' && (inDoubleQuotes == 0 || inSingleQuotes == 0)) 
        {
            inSingleQuotes = 1;
            continue;
        }

        HandleUnmatchedWrappers(c, inCharStack, inCharStackIndex);
    }

    return 1;
}

void HandleUnmatchedWrappers(int c, char inCharStack[], int inCharStackIndex) {
    if (c == '(' || c == '[' || c == '{') 
        {
            inCharStack[inCharStackIndex++] = c;
        }

        if (c == ')') 
        {
            if ((inCharStackIndex == 0 || inCharStack[inCharStackIndex - 1] != '(')) 
            {
                printf("%s", WRONG_SYN_MSG);
            } 
            --inCharStackIndex;
        }

        if (c == ']') 
        {
            if ((inCharStackIndex == 0 || inCharStack[inCharStackIndex - 1] != '[')) 
            {
                printf("%s", WRONG_SYN_MSG);
            } 
            --inCharStackIndex;
        } 

        if (c == '}') 
        {
            if ((inCharStackIndex == 0 || inCharStack[inCharStackIndex - 1] != '{')) 
            {
                printf("%s", WRONG_SYN_MSG);
            } 
            --inCharStackIndex;
        }
}