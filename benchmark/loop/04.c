#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int *p = arr;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            p += 1;

    return 0;
}

// p → arr[4]