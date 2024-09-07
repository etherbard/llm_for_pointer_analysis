#include <stdio.h>

int main()
{
    int a = 5;
    int *p = &a;
    int *q = p + 2;

    p++;

    return 0;
}

// p → a + sizeof(int)
// q → a + 2 * sizeof (int)