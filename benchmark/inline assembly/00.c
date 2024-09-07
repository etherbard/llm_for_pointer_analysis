typedef struct data {u64 a; u64 b; u64 c} data;

void foo(data *p) {
    u64 *ptr = &(p->a);
    
    asm ( "lea (%[base],%[offset]), %[ptr_out]" 
    : [ptr_out] "=r" (ptr) 
    : [base] "r" (p), [offset] "i" (offsetof(struct my_struct, c))
    ); // “ptr” now points to p->c

    *ptr = 42;
}

//p → c