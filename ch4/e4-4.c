/* Exercise: Add commands to print the top element of the stack without popping,
 * to duplicate it, and to swap the top two elements. Add a command to clear the
 * stack. */

#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <ctype.h>

#define MAXOP    100    /* max size of operand or operator */
#define NUMBER   '0'    /* signal that a number was found */
#define BUFSIZE  100
#define MAXVAL   100    /* maximum depth of val stack */

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */
int sp = 0;
double val[MAXVAL];     /* value stack */

/* get a (possibly pushed back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
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

/* print_top: print the top element of the stack without popping it */
void print_top(void)
{
    if (sp > 0)
        printf("%f\n", val[sp-1]);
    else
        printf("error: can't print, stack empty\n");
}

/* duplicate:
 * return aka "duplicate" the top element of the stack without popping it */
double duplicate(void)
{
    if (sp > 0)
        return(val[sp-1]);
    else {
        printf("error: can't duplicate, stack empty\n");
        return 0.0;
    }
}

/* swap: swap the top two elements of the stack */
void swap(void)
{
    double temp;
    if (sp > 1)
    {
        val[sp-1] = temp;
        val[sp-1] = val[sp-2];
        val[sp-2] = temp;
    }
    else {
        printf("error: can't swap without at least 2 items in the stack\n");
    }
}

/* clears the stack */
void clear(void)
{
    while (sp > 0)
        pop();
}

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch(type) {
        case NUMBER:
            push(atof(s));
            break;
        case 'p':
            print_top();
            break;
        case 'd':
            push(duplicate());
            break;
        case 's':
            swap();
            break;
        case 'c':
            clear();
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
    return 0;
}
