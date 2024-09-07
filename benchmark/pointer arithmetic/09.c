#include <stdio.h>
#include <stdlib.h>

struct Point
{
    int x;
    int y;
};

int main()
{
    struct Point *p = (struct Point *)malloc(3 * sizeof(struct Point));
    if (p == NULL)
    {
        return 1;
    }

    p[0].x = 1;
    p[0].y = 2;
    p[1].x = 3;
    p[1].y = 4;
    p[2].x = 5;
    p[2].y = 6;

    struct Point *q = p;
    struct Point *r = p + 2;

    q++;
    r--;

    free(p);

    return 0;
}

//p → p[0]
//q → p[1]
//r → p[1]