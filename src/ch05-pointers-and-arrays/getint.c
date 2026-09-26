#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int getint(int *pn)
{
    int c, sign, sign_char = 0;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
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

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main(void)
{
	int n, r;

	while ((r = getint(&n)) != EOF) {
		if (r > 0) 
        {
			printf("read %d\n", n);
        }
		else
        {
            int v =  getch();
			printf("(%d) not a number: '%c'\n", r, v);
            if (v == 'x')
            {
                break;
            }
        }
	}

	return 0;
}