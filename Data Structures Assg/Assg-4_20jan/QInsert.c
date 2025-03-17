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

//upto now i finished the basic code for creating a linkedlist structure rest of the adding of values are done in the body part of the code
void insert(struct linkedlist** head, int j, int x) {
    struct linkedlist* newlinkedlist = createlinkedlist(x);
    struct linkedlist* current = *head;

    if (j == 1) {
        newlinkedlist->next = *head;
        *head = newlinkedlist;
        return;
    }//If the list was having only one element i should be able to 

    for (int k = 1; k < j - 1 && current != NULL; k++) {
        current = current->next;
    }

    if (current == NULL) {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newlinkedlist;
    } else {
        newlinkedlist->next = current->next;
        current->next = newlinkedlist;
    }
}
//This is the important code for this question where i need to insert a new linked list using the insert function

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
    int n, value, j, x;

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

    printf("Enter the position and value to insert: ");
    scanf("%d %d", &j, &x);

    insert(&head, j, x);
    printf("List after insertion: \n");
    printList(head);

    return 0;
}
