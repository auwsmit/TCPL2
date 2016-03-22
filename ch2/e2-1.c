/*
 * Exercise: Write a program to determine the ranges of char, short, int, and
 * long variables, both signed and unsigned, by printing appropriate values from
 * standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("Ranges of data types:\n\n");
    printf("signed char:   %4d - %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: %4d - %d\n\n", 0, UCHAR_MAX);
    printf("signed short:   %6d - %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: %6d - %d\n\n", 0, USHRT_MAX);
    printf("signed int:   %12d - %llu\n", INT_MIN, (unsigned long long)INT_MAX);
    printf("unsigned int: %12d - %llu\n\n", 0, (unsigned long long)UINT_MAX);
    printf("signed long:   %12d - %llu\n", LONG_MIN, (unsigned long long)LONG_MAX);
    printf("unsigned long: %12d - %llu\n\n", 0, (unsigned long long)ULONG_MAX);
    printf("float:       %12g - %g\n", FLT_MIN, FLT_MAX);
    printf("double:      %12g - %g\n", DBL_MIN, DBL_MAX);
    printf("long double: %12Lg - %Lg\n\n", LDBL_MIN, LDBL_MAX);
    return 0;
}
