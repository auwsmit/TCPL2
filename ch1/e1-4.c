/*
 * Exercise: Write a program to print the corresponding Celsius to Fahrenheit
 * table.
 */

#include <stdio.h>

/* print Celsius-Farenheit table
 *  for fahr = 0, 20, ..., 300; floating-point conversion */
int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("Celsius | Fahrenheit\n");
    printf("--------------------\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = (celsius * (9.0/5.0)) + 32.0;
        printf("  %-5.0f |   %-6.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
