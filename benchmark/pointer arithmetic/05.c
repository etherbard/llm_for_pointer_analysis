#include <stdio.h>

int main() {
    float f[] = {1.1, 2.2, 3.3};
    float *p = f;
    float *q = p + 2;

    return 0;
}

//p → f[0]
//q → f[2]