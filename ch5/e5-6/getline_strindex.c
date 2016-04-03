/* see README */
/* from e4-1  */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

char *pattern = "ould";

int getline_KR(char *s, int lim)
{
    char c, *orig = s;

    for (; (c=getchar())!=EOF && c!='\n' && lim; s++, lim--)
        *s = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - orig;
}

int strindex(char *s, char *t)
{
    char *orig = s;
    char *S, *T;
    for (s = s + strlen(s)-1; s >= orig; --s) {
        for (S=s, T=t; *T!='\0' && *S==*T; S++, T++)
            ;
        if (T > t && *T == '\0')
            return s - orig;
    }
    return -1;
}

int main(void)
{
    char line[MAXLINE];
    int found = 0, check;

    printf("Enter a string to find pattern \"%s\": ", pattern);

    while (getline_KR(line, MAXLINE) > 0) {
        if ((check = strindex(line, pattern)) >= 0) {
            printf("Pattern found at position: %d\n", check);
            found++;
        }
        else {
            printf("Pattern not found\n");
        }
    }

    return found;
}
