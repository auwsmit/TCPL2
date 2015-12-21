/* Exercise: Write a program to remove trailing blanks and tabs from each line
 * of input, and to delete entirely blank lines. */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int getline(char line[], int maxline);

int main(void)
{
    int len, i;
    char line[MAXLINE];     /* current input line */

    while ((len = getline(line, MAXLINE)) > 0) {
        for (i = len-1; i >= 0; --i)
            if (!(line[i] == ' ' || line[i] == '\t'))
                break;
            else
                line[i] = '\0';
        if (len == 1)
            continue;
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
