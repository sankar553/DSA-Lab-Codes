#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct Queue {
    struct node* front;
    struct node* rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

void enqueue(struct Queue* q, int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = q->rear;

    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }

    q->rear->next = new_node;
    q->rear = new_node;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) return -1;

    struct node* temp = q->front;
    int value = temp->data;

    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);

    return value;
}

void printQueue(struct Queue* q) {
    struct node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    int n, value;
    printf("Enter the number of items to enqueue: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        enqueue(&q, value);
    }

    printf("Queue: ");
    printQueue(&q);

    return 0;
}
