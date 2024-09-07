#include <stdio.h>

struct Point
{
    int x;
    int y;
};

int main()
{
    struct Point p1 = {5, 10};
    struct Point *p = &p1;
    struct Point *q = p + 1;

    return 0;
}

// p → p1
// q → undefined behavior