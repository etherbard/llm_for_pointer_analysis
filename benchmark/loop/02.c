#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        p += 1;
        n -= 1;
    }

    return 0;
}

// p → arr[2]