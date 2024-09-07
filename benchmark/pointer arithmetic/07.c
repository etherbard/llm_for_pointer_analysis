#include <stdio.h>

struct Point
{
    int x;
    int y;
};

int main()
{
    struct Point points[3] = {{1, 2}, {3, 4}, {5, 6}};
    struct Point *p = points;
    struct Point *q = p + 2;
    struct Point *r = q--;

    return 0;
}

//p → points[0]
//q → points[1]
//r → points[2]