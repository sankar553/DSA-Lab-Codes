#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void deleteNthAfterM(struct Node **head, int M, int N)
{
    struct Node *current = *head;
    struct Node *temp;

    for (int i = 1; current != NULL && i < M; i++)
    {
        current = current->next;
    }

    if (current == NULL || current->next == NULL)
        return;

    for (int i = 0; current->next != NULL && i < N; i++)
    {
        temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

void printList(struct Node *node)
{
    if (node == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("[ ");
    while (node != NULL)
    {
        printf("%d", node->data);
        node = node->next;
        if (node != NULL)
        {
            printf(" --> ");
        }
    }
    printf(" ]\n");
}

void append(struct Node **head, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
}

int main()
{
    struct Node *head = NULL;

    int n;

    printf("Enter the number of elements in list ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int var;
        printf("Enter the data into the list[%d]: ", i + 1);
        scanf("%d", &var);
        append(&head, var);
    }

    printf("Original List: ");
    printList(head);
    int N, M;
    
    printf("Enter the value of Node N to start the deletion\n");
    scanf("%d", &N);
    printf("Enter the value of number of Nodes M to delete after the selected node\n");
    scanf("%d", &M);

    deleteNthAfterM(&head, N, M);
    printf("Singly linked List after deletion of Node Indices[ ");
    for (int i = N + 1; i < M + 1 + N; i++)
    {
        printf("%d ", i);
    }
    printf("]: ");
    printList(head);

    return 0;
}
