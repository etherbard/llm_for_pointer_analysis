#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;
    for (int i = 0; i < 3; i++)
        p += 1;

    return 0;
}

//p → arr[3]