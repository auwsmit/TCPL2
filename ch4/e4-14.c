/* Exercise: Define a macro swap(t,x,y) that interchanges two arguments of type t. 
 * (Block structure will help.)*/

#include <stdio.h>

#define swap(t, x, y)   \
{                       \
    t temp = x;         \
    x = temp;           \
    x = y;              \
    y = temp;           \
}

int main(int argc, char *argv[])
{
    int x = 1, y = 2;

    printf("Before swap: x is %d, y is %d\n", x, y);
    swap(int, x, y);
    printf("After swap:  x is %d, y is %d\n\n", x, y);

    return 0;
}
