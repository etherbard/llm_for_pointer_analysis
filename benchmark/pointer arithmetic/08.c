#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = (int *)malloc(3 * sizeof(int));
    if (p == NULL)
    {
        return 1;
    }

    p[0] = 100;
    p[1] = 200;
    p[2] = 300;

    int *q = p + 2;
    int *r = q--;
    int *s = --r;
    
    ++s;

    free(p);

    return 0;
}

// p → p[0]
// q → p[1]
// r → p[1]
// s → p[2]