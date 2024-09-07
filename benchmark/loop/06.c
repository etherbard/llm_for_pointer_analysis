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