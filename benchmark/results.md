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

#### 01

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

### LLM with Code Completion