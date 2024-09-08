#include <stdio.h>

int main()
{
    int x = 100, y = 200;
    int *ptr = &x;

    asm(
        "mov %1, %0" // Move the address of y into ptr
        : "=r"(ptr)  // Output operand: updated ptr
        : "r"(&y)    // Input operand: address of y
    );

    return 0;
}

//ptr → y