#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;
    int *p = &b;
    int *q = p - 1;

    return 0;
}

// p → b
// q → undefined behavior