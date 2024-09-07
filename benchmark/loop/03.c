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
