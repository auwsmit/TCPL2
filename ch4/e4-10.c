/*
 * Exercise: An alternative organization uses getline to read an entire input
 * line; this makes getch and ungetch unnecessary. Revise the calculator to use
 * this approach.
 */

#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <ctype.h>

#define MAXOP    100    /* max size of operand or operator */
#define NUMBER   '0'    /* signal that a number was found */
#define BUFSIZE  100
#define MAXVAL   100    /* maximum depth of val stack */

char buf[BUFSIZE];      /* buffer for getline */
int buf_i = 0;          /* index for buf */
int sp = 0;
double val[MAXVAL];     /* value stack */

/* getline_KR: read a line into s, return length */
int getline_KR(char s[], int lim)
{
    int c, i;

    for (i=0; (c=getchar())!=EOF && c!='\n'; ++i)
        if (i<lim-1)
            s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = buf[buf_i++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;       /* not a number */
    i = 0;
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = buf[buf_i++]))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = buf[buf_i++]))
            ;
    s[i] = '\0';
    --buf_i;
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
    int type;
    double op2;
    char s[MAXOP];

    while (getline_KR(buf, BUFSIZE) != 0) {
        buf_i = 0;
        while ((type = getop(s)) != '\0') {
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
                case '%':
                    op2 = pop();
                    if (op2 != 0.0)
                        push((int)pop() % (int)op2);
                    else
                        printf("error: no zero divisor\n");
                    break;
                case '\n':
                    printf("\t%.8g\n", pop());
                    break;
                default:
                    printf("error: unknown command %s\n", s);
                    break;
            }
        }
    }

    return 0;
}
