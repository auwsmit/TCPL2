#include <stdio.h>
#include <string.h>
#include "alloc.h"

#define MAXLINES 5000       /* max #lines to be sorted */
#define MAXLEN 1000         /* max length of any input line */

char *lineptr[MAXLINES];    /* pointers to text lines */

int getline_KR(char *s, int lim);
int readlines(char *lineptr[], int nlines, char *storage);
void writelines(char *lineptr[], int nlines);
void qsort_KR(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);

/* sort input lines */
int main(void)
{
    int nlines;     /* number of input lines read */
    char *storage;
    if ((storage = alloc(MAXLINES * MAXLEN)) == 0) {
        printf("error: alloc is too small you dumb piece of shit\n");
        return 'f'+'u'+'c'+'k'+'y'+'o'+'u';
    }

    if ((nlines = readlines(lineptr, MAXLINES, storage)) >= 0) {
        qsort_KR(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* getline: read one line of input into *s */
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

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *storage)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline_KR(line, MAXLEN)) > 0)
        if (nlines >= maxlines)
            return 1;
        else {
            p = storage + (nlines * MAXLEN);
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* qsort_KR: v[left]...v[right] into increasing order */
void qsort_KR(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)  /* do nothing if array contains */
        return;         /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort_KR(v, left, last-1);
    qsort_KR(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
