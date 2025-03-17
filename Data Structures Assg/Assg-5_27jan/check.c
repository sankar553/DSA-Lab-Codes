#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int findIntersection(struct Node* head1, struct Node* head2) {
    struct Node *temp1 = head1, *temp2 = head2;
    while (temp1 != temp2) {
        temp1 = temp1 ? temp1->next : head2;
        temp2 = temp2 ? temp2->next : head1;
    }
    return temp1->data;
}

int main() {
    struct Node* head1 = malloc(sizeof(struct Node));
    struct Node* head2 = malloc(sizeof(struct Node));
    
    head1->data = 5;
    head1->next = malloc(sizeof(struct Node));
    head1->next->data = 9;
    head1->next->next = malloc(sizeof(struct Node));
    head1->next->next->data = 6;
    head1->next->next->next = malloc(sizeof(struct Node));
    head1->next->next->next->data = 4;
    head1->next->next->next->next = malloc(sizeof(struct Node));
    head1->next->next->next->next->data = 2;
    head1->next->next->next->next->next = malloc(sizeof(struct Node));
    head1->next->next->next->next->next->data = 3;

    head2->data = 8;
    head2->next = malloc(sizeof(struct Node));
    head2->next->data = 1;
    head2->next->next = malloc(sizeof(struct Node));
    head2->next->next->data = 2;
    head2->next->next->next = malloc(sizeof(struct Node));
    head2->next->next->next->data = 4;
    head2->next->next->next->next = malloc(sizeof(struct Node));
    head2->next->next->next->next->data = 2;
    head2->next->next->next->next->next = malloc(sizeof(struct Node));
    head2->next->next->next->next->next->data = 3;
    
    printf("Intersection Point: %d\n", findIntersection(head1, head2));
    return 0;
}
