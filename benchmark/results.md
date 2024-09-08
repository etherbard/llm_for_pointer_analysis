## Pointer Arithmetic

### LLM

#### Overview

**Prompt**: where does variable p and q point to? + code

#### 00

```c
#include <stdio.h>

int main()
{
    int a = 10;
    int *p = &a;
    int *q = p + 1;

    return 0;
}

// p → a
// q → a + sizeof(int)
```

p → a
q → undefined (points to memory location after a)

#### 01 (wrong case)

```c
#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;
    int *p = &b;
    int *q = p - 1;

    return 0;
}

// p → b
// q → undefined behavior
```

p → b
q → a

#### 02

```c
#include <stdio.h>

int main()
{
    int a = 5;
    int *p = &a;
    int *q = p + 2;

    p++;

    return 0;
}

// p → a + sizeof(int)
// q → a + 2 * sizeof (int)
```

p → undefined (points to memory location after `a`)
q → undefined (points to memory location two positions after `a`)

#### 03

```c
#include <stdio.h>

int main()
{
    int a = 5;
    int *p = &a;
    int *q = p + 2;
    int *r = q--;

    return 0;
}

// p → a
// q → a + sizeof(int)
// r → a + 2 * sizeof (int)
```

p → a
q → undefined (points to memory location one position after `a`)
r → undefined (points to memory location two positions after `a`)

#### 04

```c
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
```

p → arr[0] (10)
q → arr[3] (40)
r → arr[3] (40)

#### 05

```c
#include <stdio.h>

int main() {
    float f[] = {1.1, 2.2, 3.3};
    float *p = f;
    float *q = p + 2;

    return 0;
}

//p → f[0]
//q → f[2]
```

p → f[0] (1.1)
q → f[2] (3.3)

#### 06

```c
#include <stdio.h>

struct Point
{
    int x;
    int y;
};

int main()
{
    struct Point p1 = {5, 10};
    struct Point *p = &p1;
    struct Point *q = p + 1;

    return 0;
}

// p → p1
// q → undefined behavior
```

p → p1
q → undefined (points to memory location after `p1`)

#### 07

```c
#include <stdio.h>

struct Point
{
    int x;
    int y;
};

int main()
{
    struct Point points[3] = {{1, 2}, {3, 4}, {5, 6}};
    struct Point *p = points;
    struct Point *q = p + 2;
    struct Point *r = q--;

    return 0;
}

//p → points[0]
//q → points[1]
//r → points[2]
```

p → points[0] ({1, 2})
q → points[1] ({3, 4})
r → points[2] ({5, 6})

#### 08

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = (int *)malloc(3 * sizeof(int));
    if (p == NULL)
    {
        return 1;
    }

    p[0] = 100;
    p[1] = 200;
    p[2] = 300;

    int *q = p + 2;
    int *r = q--;
    int *s = --r;
    
    ++s;

    free(p);

    return 0;
}

// p → p[0]
// q → p[1]
// r → p[1]
// s → p[2]
```

p → dynamically allocated array (100, 200, 300)
q → p[1] (200)
r → p[1] (200)
s → p[2] (300)

#### 09

```c
#include <stdio.h>
#include <stdlib.h>

struct Point
{
    int x;
    int y;
};

int main()
{
    struct Point *p = (struct Point *)malloc(3 * sizeof(struct Point));
    if (p == NULL)
    {
        return 1;
    }

    p[0].x = 1;
    p[0].y = 2;
    p[1].x = 3;
    p[1].y = 4;
    p[2].x = 5;
    p[2].y = 6;

    struct Point *q = p;
    struct Point *r = p + 2;

    q++;
    r--;

    free(p);

    return 0;
}

//p → p[0]
//q → p[1]
//r → p[1]
```

p → p[0] ({1, 2})
q → p[1] ({3, 4})
r → p[1] ({3, 4})

### Traditional Static Analysis (SVF)

### LLM for Code Completion

## Loop

### LLM

#### 00

```c
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
```

p → arr[3]

#### 01

```c
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
```

p → arr[210]

#### 02

```c
#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        p += 1;
        n -= 1;
    }

    return 0;
}

// p → arr[2]
```

p → arr[2]

#### 03

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node * complex_pointer_manipulation(struct Node *head, int n) {
    struct Node *p = head;
    int i = 0;

    while (p != NULL) {
        if (i == n) {
            break;
        }
        p = p->next;
        i++;
    }

    if (p != NULL) {
        struct Node *temp = head;
        while (temp != NULL) {
            if (temp->data == p->data - n) {
                p = temp;
                break;
            }
            temp = temp->next;
        }
    }
    return p;
}

int main() {
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;
    //A linked list is created as “1 -> 2 -> 3”

    struct Node *p = complex_pointer_manipulation(head, 1);
    return 0;
}

//p → data 1
```

p → data 1

#### 04

```c
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
```

p → arr[4]

#### 05

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *reverse_traverse(struct Node *head, int n) {
    struct Node *p = head;
    int count = 0;
    
    while (p != NULL) {
        count++;
        p = p->next;
    }
    
    if (n > count || n <= 0) {
        return NULL;
    }

    p = head;
    for (int i = 0; i < count - n; i++) {
        p = p->next;
    }

    return p;
}

int main() {
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    struct Node *p = reverse_traverse(head, 2);
    return 0;
}

//p → data 2
```

p → data 2

#### 06

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *skip_even(struct Node *head, int n) {
    struct Node *p = head;
    int count = 0;

    while (p != NULL) {
        if (p->data % 2 != 0) {
            count++;
            if (count == n) {
                return p;
            }
        }
        p = p->next;
    }

    return NULL;
}

int main() {
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = NULL;

    struct Node *p = skip_even(head, 2);
    return 0;
}

//p → data 3
```

p → data 3

#### 07

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *alternate_jump(struct Node *head) {
    struct Node *p1 = head;
    struct Node *p2 = head;

    while (p2 != NULL && p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    return p1;
}

int main() {
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;

    struct Node *p = alternate_jump(head);
    return 0;
}

//p1 → data 3
//p2 → null
```

p1 → data 3
p2 → null

## Inline Assembly

### LLM

#### 00

```c
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
```

ptr → c

#### 01

```c
#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr;

    // Inline assembly to increment the pointer
    asm(
        "add $4, %0"
        : "=r"(ptr)
        : "0"(ptr));

    return 0;
}

// ptr → arr[1]
```

ptr → arr + 1

#### 02

```c
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
```

ptr1 → b

ptr2 → a

#### 03

```c
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
```

ptr → y

#### 04

```c
#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr;

    asm(
        "lea 8(%0), %0" // Load the address of the element 8 bytes away (3rd element)
        : "=r"(ptr)     // Output operand: updated ptr
        : "0"(ptr)      // Input operand: initial value of ptr
    );

    return 0;
}

//ptr → arr[2]
```

ptr → arr[2]