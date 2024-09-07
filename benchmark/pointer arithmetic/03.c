#include <stdio.h>

int main()
{
    int a = 5;
    int *p = &a;
    int *q = p + 2;
    int *r = q--;

    return 0;
}

// p → a
// q → a + sizeof(int)
// r → a + 2 * sizeof (int)