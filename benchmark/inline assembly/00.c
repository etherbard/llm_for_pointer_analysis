#include <stddef.h> // for offsetof
#include <stdint.h> // for u64

typedef struct data {
    uint64_t a;
    uint64_t b;
    uint64_t c;
} data;

void foo(data *p) {
    uint64_t *ptr = &(p->a);
    
    asm ( "lea (%[base], %[offset]), %[ptr_out]"
    : [ptr_out] "=r" (ptr) 
    : [base] "r" (p), [offset] "i" (offsetof(data, c))
    ); // “ptr” now points to p->c

    *ptr = 42;
}

//ptr → c