/* Exercise: Suppose that there will never be more than one character of
 * pushback. Modify getch and ungetch accordingly. */

#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <string.h>
#include <ctype.h>

#define MAXOP    100    /* max size of operand or operator */
#define NUMBER   '0'    /* signal that a number was found */
#define BUFSIZE  100
#define MAXVAL   100    /* maximum depth of val stack */

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */
int sp = 0;
double val[MAXVAL];     /* value stack */

/* getch: get a (possibly pushed back) character */
int getch(void)
{
    return (bufp != 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
{
    buf[bufp] = c;
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;       /* not a number */
    i = 0;
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

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

/* reverse Polish calculator */
int main(void)
{
    int type, i;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
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
                    push(pop() - op2);
                else
                    printf("error: no zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s aka '%d'\n", s, s[0]);
                break;
        }
    }
    return 0;
}
