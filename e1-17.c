/* Exericise: Write a program to print all input lines that are longer than 80
 * characters. */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */
#define MINPRINTLEN 80  /* minimum length of an input line to print */

int getline(char line[], int maxline);

int main(void)
{
    int len;            /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = getline(line, MAXLINE)) > 0)
        if (len > MINPRINTLEN) {
            printf("%s", line);
        }

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for (i=0; (c=getchar())!=EOF && c!='\n'; ++i)
        if (i<lim-1)
            s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
