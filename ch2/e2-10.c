/*
 * Exercise: Rewrite the function lower, which converts upper case letters to
 * lowercase, with a conditional expression instead of if-else.
 */

#include <stdio.h>

char lower(char c)
{
    return ((c >= 'A' && c <= 'Z') ? c + ('a'-'A') : c);
}

int main(void)
{
    char str[] = "Hello world!";

    str[0] = lower(str[0]);
    str[3] = lower(str[3]);

    printf("\n%s\n\n", str);

    return 0;
}
