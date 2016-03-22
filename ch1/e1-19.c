/*
 * Exercise: Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

void reverse(char line[], int linelen);
int getline_KR(char line[], int maxline);

int main(void)
{
    int len, i;
    char line[MAXLINE];     /* current input line */

    while ((len = getline_KR(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s", line);
    }

    return 0;
}

void reverse(char s[], int len)
{
    int i, j;
    char temp;
    for (i = 0, j = len-1; i < len/2; ++i, --j) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}

/* getline_KR: read a line into s, return length */
int getline_KR(char s[], int lim)
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
