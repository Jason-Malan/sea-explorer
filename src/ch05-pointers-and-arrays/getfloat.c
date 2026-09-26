#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

float getfloat(float *pn) 
{
    int c, sign, sign_char = 0;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        sign_char = c;
        c = getch();

        if (!isdigit(c)) {
            if (c != EOF)
                ungetch(c);

            ungetch(sign_char);
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    
    // this is probs wrong but oh well.
    int decimal_counter = 0;
    if (c == '.') 
    {
        while (isdigit((c = getch())))
        {
            *pn = 10 * *pn + (c - '0');
            decimal_counter++;
        }
    }

    while (decimal_counter-- != 0)
    {
        *pn /= 10;
    }

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main(void) 
{
    float float_value;
    getfloat(&float_value);
    printf("%f", float_value);
}