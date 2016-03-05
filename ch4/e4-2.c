/* Exercise: Extend atof to handle scientific notation of the form
 *      123.45e-6
 * where a floating-point number may be followed by e or E and an optionally
 * val_signed exponent. */

#include <stdio.h>
#include <math.h>

#define BUFSIZE 1000

double atof(char s[])
{
    double val, power, coefficient;
    int i, val_sign, exponent, exp_sign;

    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        ;
    val_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exponent = 0; isdigit(s[i]); i++)
            exponent = 10 * exponent + (s[i] - '0');
        exponent *= exp_sign;
        coefficient = val_sign * val / power;
        return coefficient * pow(10.0, (double)exponent);
    }
    else return val_sign * val / power;
}

int main(void)
{
    char input_string[BUFSIZE];
    double value;

    printf("Enter a value in scientific notation (e.g. 123.45e-6): ");
    fgets(input_string, BUFSIZE, stdin);
    value = atof(input_string);
    printf("\n%.10lf\n\n", value);

    return 0;
}
