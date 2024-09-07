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