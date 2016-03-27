/*
 * Exercise: Write the function strend(s,t), which returns 1 if the string t
 * occurs at the end of the string s, and zero otherwise.
 */

#include <stdio.h>

int strend(char *s, char *t)
{
    char *t_begin = t;
    char *s_old_index;
    for (; *s != '\0'; s++) {
        if (*s == *t) {
            s_old_index = s;
            while (*s == *t) {
                if (*s == '\0')
                    return 1;
                s++, t++;
            }
            t = t_begin;
            s = s_old_index;
        }
    }
    return 0;
}

int main(void)
{
    char *string1 = "Here's a string!";
    char *string2 = "string!";

    if (strend(string1, string2))
        printf("String found!\n\n");
    else
        printf("String not found!\n\n");

    return 0;
}
