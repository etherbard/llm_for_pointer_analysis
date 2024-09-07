#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;
    int *q = p + 2;
    int* r = ++q;

    return 0;
}

//p → arr[0]
//q → arr[3]
//r → arr[3]