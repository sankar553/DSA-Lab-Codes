#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct Stack {
    struct node* top;
};

void InitializeStack(struct Stack* s) {
    s->top = NULL;
}

int isEmpty(struct Stack* s) {
    return s->top == NULL;
}

void push(struct Stack* s, int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = s->top;
    new_node->prev = NULL;

    if (s->top != NULL) {
        s->top->prev = new_node;
    }
    s->top = new_node;
}

int pop(struct Stack* s) {
    if (isEmpty(s))
        return -1;

    struct node* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    if (s->top != NULL) {
        s->top->prev = NULL;
    }
    free(temp);

    return value;
}

void PrintStack(struct Stack* s) {
    struct node* temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack1;
    InitializeStack(&stack1);
    int choice = 1, data,index=0;
    while (choice != 0) {
        printf("Enter the value of data-%d: ",index);
        scanf("%d", &data);
        push(&stack1, data);
        index++;
        printf("Do you want to add one more (enter non-zero value): ");
        scanf("%d", &choice);
    }

    printf("Stack(created using the Linked Lists): ");
    PrintStack(&stack1);

    return 0;
}
