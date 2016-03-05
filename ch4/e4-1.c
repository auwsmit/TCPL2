/* Exercise: Write the function strrindex(s,t), which returns the position of
 * the rightmost occurrence of t in s, or -1 if there is none. */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

char pattern[] = "ould";

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

int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = strlen(s)-1; i >= 0; --i) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int main(void)
{
    char line[MAXLINE];
    int found = 0, check;

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
