#include <stdio.h>
#include <stdlib.h>

struct linkedlist {
    int data;
    struct linkedlist* next;
};

struct linkedlist* createlinkedlist(int value) {
    struct linkedlist* newlinkedlist = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    newlinkedlist->data = value;
    newlinkedlist->next = NULL;
    return newlinkedlist;
}

void delete(struct linkedlist** head, int j) {
    if (*head == NULL) {
        printf("Error: List is empty\n");
        return;
    }

    struct linkedlist* current = *head;

    // Special case for deleting the first linkedlist
    if (j == 1) {
        *head = current->next;
        free(current);
        return;
    }

    // Traverse to the (j-1)th linkedlist
    for (int k = 1; k < j - 1 && current != NULL; k++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Error: Position %d does not exist\n", j);
    } else {
        struct linkedlist* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

//upto now i finished the basic code for creating a linkedlist structure rest of the adding of values are done in the body part of the code

void printList(struct linkedlist* head) {
    struct linkedlist* current = head;
    printf("[ ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("completed");
    printf(" ]\n");
}

int main() {
    struct linkedlist* head = NULL;
    int n, value, j;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the element(s) of the linked list of your wish: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct linkedlist* newlinkedlist = createlinkedlist(value);
        if (head == NULL) {
            head = newlinkedlist;
        } else {
            struct linkedlist* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newlinkedlist;
        }
    }

    printf("The entered linked list is: \n");
    printList(head);

    printf("Enter the position value to delete from the list: (value can be 1 , 2, 3, ..,%d): ",n);
    scanf( "%d", &j);

    delete(&head,j);
    printf("List after deletion: \n");
    printList(head);

    return 0;
}