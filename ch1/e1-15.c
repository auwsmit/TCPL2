/* Exercise: Rewrite the temperature conversion perogram of Section 1.2 to use
 * a function for conversion. */

#include <stdio.h>

float fahr_to_cels(int f);

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("Fahrenheit  | Celsius\n");
    printf("---------------------\n");

    fahr = lower;
    while (fahr <= upper) {
        celsius = fahr_to_cels(fahr);
        printf("   %3.0f      | %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

float fahr_to_cels(int f)
{
    return (5.0/9.0) * (f-32.0);
}
