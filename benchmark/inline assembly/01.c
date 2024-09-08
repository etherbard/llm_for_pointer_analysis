#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr;

    asm(
        "add $4, %0"
        : "=r"(ptr)
        : "0"(ptr));

    return 0;
}

// ptr → arr[1]