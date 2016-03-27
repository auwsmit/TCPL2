/*
 * Exercise: Write a pointer version of the funcion strcat that we showed in
 * Chapter 2: strca(s,t) copies the string t to the end of s.
 */

#include <stdio.h>

void strcat_new(char s[], char t[])
{
    for (; *s != '\0'; s++)    /* find end of s */
        ;
    while ((*s++ = *t++) != '\0')     /* copy t */
        ;
}

int main(void)
{
    char str1[50] = "First string";
    char str2[] = "Second string";

    strcat_new(str1, str2);
    printf("Concatenated strings: %s\n\n", str1);

    return 0;
}
