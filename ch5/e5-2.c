/*
 * Exercise: Write getfloat, the doubleing point analog of getfloat. What type does
 * getfloat return as its function value?
 *
 * Answer: The double value will be calculated through a double pointer parameter
 * (*fp).  So same as getfloat, an int will be returned because the return value
 * is still based on characters, and that still works just fine.
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>   /* for pow() */
#define BUFSIZE  100

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int getch(void);
void ungetch(int c);

/* getfloat: get next integer from input into *pf */
int getfloat(double *pf);

int main(void)
{
    double number;

    printf("Enter a float (scientific notation works too!): ");
    if (getfloat(&number) != 0)
        printf("Valid float found: %.10lf\n\n", number);
    else
        printf("No valid float found!\n\n");

    return 0;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else if (c != EOF)
        buf[bufp++] = c;
}

int getfloat(double *pf)
{
    double val, power, coefficient;
    int c, val_sign, exponent, exp_sign;

    while (isspace(c = getch()))    /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);     /* it's not a number */
        return 0;
    }
    val_sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    else if (!isdigit(c)) {
        ungetch(c);     /* + or - without a digit is not a number */
        return 0;
    }
    for (val = 0; isdigit(c); c = getch())
        val = 10 * val + (c - '0');

    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
        val = 10.0 * val + (c - '0');
        power *= 10.0;
    }
    if (c == 'e' || c == 'E') {
        c = getch();
        exp_sign = (c == '-') ? -1 : 1;
        if (c == '+' || c == '-')
            c = getch();
        for (exponent = 0; isdigit(c); c = getch())
            exponent = 10 * exponent + (c - '0');
        exponent *= exp_sign;
        coefficient = val_sign * val / power;
        *pf = coefficient * pow(10.0, (double)exponent);
    }
    else *pf = val_sign * val / power;

    if (c != EOF)
        ungetch(c);
    return c;
}
