/*
 * Exercise: Write a recursive version of the function reverse(s), which
 * reverses the string s in place.
 */

#include <stdio.h>

void reverse(char s[])
{
    char c;
    static int i = 0, j = 0;

    if (s[j] != '\0') {
        j++;
        reverse(s);
        if (i < j) {
            c = s[--j];
            s[j] = s[i];
            s[i++] = c;
        }
    }
}

int main(void)
{
    char str[] = "I'm Ethan Bradberry!";

    printf("Before: %s\n", str);
    reverse(str);
    printf("After:  %s\n", str);

    return 0;
}
