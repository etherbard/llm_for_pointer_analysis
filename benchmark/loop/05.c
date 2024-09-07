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