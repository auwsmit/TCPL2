/*
 * Exercise: Write versions of the standard library functions strncopy, strncat,
 * and strncmp, which operate on at most the first n characters of their
 * argument strings. For example, strncopy(s,t,n) copies at most n characters of
 * t to s. Full descriptions are in Appendix B.
 */

#include <stdio.h>
#define MAXLEN 100  /* max length of destination string buffer */

char *my_strncopy(char *d, const char *s, size_t n)
{
    char *orig = d;
    while (n--)
        if (*s != '\0')
            *d++ = *s++;
        else
            *d++ = *s;
    *d++ = '\0';
    return orig;
}

char *my_strncat(char *s, char *t, size_t n)
{
    char *orig = s;
    for (; *s != '\0'; s++)    /* find end of s */
        ;
    for (; n != 0; n--) {
        *s++ = *t++;
        if (*t == '\0') {
            *s = *t;
            break;
        }
    }
    return orig;
}

int my_strncmp(char *s, char *t, size_t n)
{
    for (; *s == *t; s++, t++) {
        if (*s == '\0')
            return 0;
        if (--n == 0)
            break;
    }
    return *s - *t;
}

int main(void)
{
    char *s_str = "string";
    char d_str[MAXLEN];
    int copy_n = 4;

    char str1[50] = "First string";
    char str2[] = "Second string";
    int cat_n = 10;

    char *str3 = "Strinks"; /* what is a strink? */
    char *str4 = "Strings";
    int cmp_n = 5;

    my_strncopy(d_str, s_str, copy_n);
    printf("\nstrncopy, %d: %s\n", copy_n, d_str);

    my_strncat(str1, str2, cat_n);
    printf("\nstrcatn, %d: %s\n", cat_n, str1);

    printf("\nstrcmp(\"%s\", \"%s\", %d): %d\n\n", str3, str4,
           cmp_n, my_strncmp(str3, str4, cmp_n));

    return 0;
}
