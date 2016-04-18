/* Add commands for handling variables. (It's easy to provide twenty-six
 * variables with single-letter names.) Add a variable for the most recently
 * printed value. */

#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <ctype.h>

#define MAXOP    100    /* max size of operand or operator */
#define NUMBER   '0'    /* signal that a number was found */
#define VARIABLE '1'    /* signal that a variable was found */
#define BUFSIZE  100
#define MAXVAL   100    /* maximum depth of val stack */

/* dat bool */
typedef enum { false, true } bool;

typedef struct variable
{
    double value;
    bool set;
} variable;

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */
int sp = 0;
double val[MAXVAL];     /* value stack */
variable var[26];       /* variables a through z */
variable last;          /* variable for the most
                           recently printed value */

/* getch: get a (possibly pushed back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
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
    if (isalpha(c))
        return VARIABLE;
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

/* use_var: Pops and stores a value in a variable when empty,
 *          and otherwise pushes that variable to the stack.
 * returns 1 if a variable is pushed, and 0 otherwise */
int process_var(int v)
{
    v = tolower(v) - 'a';
    if (sp == 0) {
        return 0;   /* stack is empty */
    }
    else if (var[v].set == false) {
        var[v].value = pop();
        printf("stored %.2f in %c\n", var[v].value, v + 'a');
        var[v].set = true;
        return 1;
    }
    else {
        push(var[v].value);
        var[v].set = false;
        return 0;
    }
}

/* reverse Polish calculator */
int main(void)
{
    int type, i;
    double op2;
    char s[MAXOP];
    bool was_set = false;

    /* set variables as unset */
    for (i = 0; i < 26; ++i) {
        var[i].set = false;
    }

    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
            case VARIABLE:
                if (process_var(type))
                    was_set = true;
            case '~':
                if (last.set == true) {
                    push(last.value);
                    last.set = false;
                }
                else
                    printf("error: no value has been printed yet\n");
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
                if (was_set == false) {
                    printf("\t%.8g\n", last.value = pop());
                    last.set = true;
                }
                was_set = false;
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
