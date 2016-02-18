/* Exercise: Our binary search makes two tests inside the loop, when one would
 * suffice (at the price of more tests outisde). Write a version with only one
 * test inside the loop and measure the difference in run-time. */

/* Result: There was no noticeable difference in run-time between the two. Both
 * ran at roughly 20 milliseconds. I used PowerShell's Measure-Command, which
 * might not have been very accurate. Or it's possible that modern CPU speeds
 * make telling the difference more difficult. */

#include <stdio.h>

int binarysearch_new(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x <= v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return (x == v[low]) ? low : -1;
}

int main(void)
{
    int values[] = { -5, 0, 4, 23, 46, 100, 380, 383, 400, 401, 402, 403, 500 };
    int num_val = 13;
    int x = 0;

    if (binarysearch_new(x, values, num_val) != -1)
        printf("\nFound %d!\n\n");
    else
        printf("\nDidn't find %d..\n\n");

    return 0;
}
