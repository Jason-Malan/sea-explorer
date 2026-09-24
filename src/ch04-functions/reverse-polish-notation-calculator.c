#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP   100  /* max size of operand or operator */
#define NUMBER  '0'  /* signal that a number was found */
#define MAXVAL  100  /* maximum depth of val stack */
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void ungets(char []);
void print_top(void);
double peek(void);
void duplicate(void);
void swap(void);
void clear(void);

double most_recently_printed_value;

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '@':
            push(most_recently_printed_value);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            push(fmod(pop(), op2));
            break;
        case 'S':
            push(sin(pop()));
            break;
        case 'E':
            push(exp(pop()));
            break;
        case 'P':
            op2 = pop();
            push(pow(pop(), op2));
            break;                
        case '\n':
            op2 = pop();
            most_recently_printed_value = op2;
            printf("\t%.8g\n", op2);
            break;
        case 'p':
            print_top();
            break;
        case 'd':
            duplicate();
            break;
        case 's':
            swap();
            break;
        case 'c':
            clear();
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void print_top(void)
{
    double top = peek();
    most_recently_printed_value = top;
    printf("peeked: %f\n", top);
}

double peek(void)
{
    if (sp > 0)
    {
        return val[sp - 1];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void duplicate(void)
{
    if (sp > 0)
    {
        int pos = sp - 1;
        int dup_pos = sp++;
        val[dup_pos] = val[pos];
    } 
    else 
    {
        printf("error: stack empty\n");
    }
}

void swap(void)
{
    if (sp > 1)
    {
        int el_one_idx = sp - 2;
        int el_two_idx = sp - 1;
        double tmp_one_val = val[el_one_idx];
        val[el_one_idx] = val[el_two_idx];
        val[el_two_idx] = tmp_one_val;
    } 
    else if (sp == 1)
    {
        printf("error: only one element, two are needed to perform swap\n");
    } 
    else 
    {
        printf("error: stack empty\n");
    }
}

void clear(void)
{
    sp = 0;
    // dont really see need to zero things out?
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i = 0, c, next;

    while ((s[0] = c = getch()) == ' ' || c == '\t');

    s[0] = c;
    s[1] = '\0';

    if (c == '-') {
        next = getch();

        if (!isdigit(next) && next != '.') {
            if (next != EOF)
                ungetch(next);
            return '-';
        }

        s[++i] = c = next;
    } 
    else if (!isdigit(c) && c != '.') 
    {
        return c;
    }

    if (isdigit(c))  /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')    /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void)  /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungets(char s[])
{
    int i = 0, c;

    while (s[i] != '\0')
    {
        i++;
    }

    while (i > 0)
    {
        ungetch(s[--i]);
    }
}

void ungetch(int c)  /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}