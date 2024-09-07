#include <stdio.h>

int main()
{
    int a = 10;
    int *p = &a;
    int *q = p + 1;

    return 0;
}

// p → a
// q → a + sizeof(int)