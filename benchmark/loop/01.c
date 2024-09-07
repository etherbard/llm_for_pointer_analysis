#include <stdio.h>

int main()
{
    int arr[1000];
    for (int i = 0; i < 1000; i++)
        arr[i] = i;
    int *p = arr;
    for (int i = 0; i < 20; i++)
        p += i;

    return 0;
}

//p → arr[210]