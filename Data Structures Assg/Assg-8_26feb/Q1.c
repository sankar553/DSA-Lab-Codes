#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct Deque
{
    int arr[SIZE];
    int front, rear;
};

void initDeque(struct Deque *dq)
{
    dq->front = -1;
    dq->rear = -1;
}

int isEmpty(struct Deque *dq)
{
    return (dq->front == -1);
}

int isFull(struct Deque *dq)
{
    return ((dq->rear + 1) % SIZE == dq->front);
}

void insertFront(struct Deque *dq, int value)
{
    if (isFull(dq))
    {
        printf("Deque is full. Cannot insert at front.\n");
        return;
    }

    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else
    {
        dq->front = (dq->front - 1 + SIZE) % SIZE;
    }

    dq->arr[dq->front] = value;
    printf("Inserted %d at front.\n", value);
}

void insertRear(struct Deque *dq, int value)
{
    if (isFull(dq))
    {
        printf("Deque is full. Cannot insert at rear.\n");
        return;
    }

    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else
    {
        dq->rear = (dq->rear + 1) % SIZE;
    }

    dq->arr[dq->rear] = value;
    printf("Inserted %d at rear.\n", value);
}

void deleteFront(struct Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty. Cannot delete from front.\n");
        return;
    }

    printf("Deleted %d from front.\n", dq->arr[dq->front]);

    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1;
    }
    else
    {
        dq->front = (dq->front + 1) % SIZE;
    }
}

void deleteRear(struct Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty. Cannot delete from rear.\n");
        return;
    }

    printf("Deleted %d from rear.\n", dq->arr[dq->rear]);

    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1;
    }
    else
    {
        dq->rear = (dq->rear - 1 + SIZE) % SIZE;
    }
}

int getFront(struct Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty. No front element.\n");
        return -1;
    }
    return dq->arr[dq->front];
}

int getRear(struct Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty. No rear element.\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

void display(struct Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = dq->front;
    while (1)
    {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main()
{
    struct Deque dq;
    initDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    insertFront(&dq, 2);
    display(&dq);

    deleteFront(&dq);
    display(&dq);

    deleteRear(&dq);
    display(&dq);

    printf("Front element: %d\n", getFront(&dq));
    printf("Rear element: %d\n", getRear(&dq));

    return 0;
}
