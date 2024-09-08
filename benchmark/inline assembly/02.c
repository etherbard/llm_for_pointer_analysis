#include <stdio.h>

int main()
{
    int a = 5, b = 10;
    int *ptr1 = &a, *ptr2 = &b;

    asm(
        "mov %1, %%eax;"         // Move ptr1 to eax
        "mov %2, %0;"            // Move ptr2 to ptr1
        "mov %%eax, %1;"         // Move eax (original ptr1) to ptr2
        : "=r"(ptr1), "=r"(ptr2) // Output operands
        : "r"(ptr2), "0"(ptr1)   // Input operands
        : "%eax"                 // Clobbered register
    );
    return 0;
}

//ptr1 → b
//ptr2 → a