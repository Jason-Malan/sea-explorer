#include <stdio.h>

void escape(char s[], char t[]);
void escape_the_escapable(char s[], char t[]);

int main() 
{
    char s[100] = "This is a \t weird \n input", t[100];

    escape(s, t);
    int i = 0;
    while (t[i] != '\0')
    {
        putchar(t[i++]);
    }
    putchar('\n');

    escape_the_escapable(t, s);
    i = 0;
    while (s[i] != '\0')
    {
        putchar(s[i++]);
    }

    return 0;
}

void escape(char s[], char t[])
{
    int i = 0, ti = 0, c;
    while ((c = s[i]) != '\0')
    {
        switch (c) {
            case '\t':
                t[ti++] = '\\';
                t[ti++] = 't';  
                break;
            case '\n':
                t[ti++] = '\\';
                t[ti++] = 'n';  
                break;
            default:
                t[ti++] = c;
                break;
        }
        i++;
    }
    t[ti] = '\0';
}

void escape_the_escapable(char s[], char t[])
{
    int i = 0, ti = 0, c;
    while ((c = s[i]) != '\0')
    {
        switch (c) {
            case '\\':
                switch (s[++i]) {
                    case 't':
                        t[ti++] = '\t';
                        i++;
                        break;
                    case 'n':
                        t[ti++] = '\n';
                        i++;
                        break;
                    default:
                        break; 
                }
                break;
            default:
                t[ti++] = c;
                break;
        }
        i++;
    }
    t[ti] = '\0';
}