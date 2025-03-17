#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = node->prev = NULL;
    return node;
}

struct Node *reverseInGroups(struct Node *head, int k)
{
    struct Node *current = head;
    struct Node *next = NULL;
    struct Node *prev = NULL;
    int count = 0;

    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        if (prev != NULL)
            prev->prev = current;
        prev = current;
        current = next; 
        count++;
    }

    if (next != NULL)
    {
        head->next = reverseInGroups(next, k);
        if (head->next != NULL)
            head->next->prev = head;
    }

    return prev;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{

    int n, data, k;
    struct Node *head = newNode(1);
    head->next = newNode(2);
    head->next->prev = head;
    head->next->next = newNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = newNode(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    printf("Enter the group size (k): ");
    scanf("%d", &k);

    if (k <= 0)
    {
        printf("Invalid group size.\n");
        return 1;
    }
    printf("The original list is: \t\t");
    printList(head);
    head = reverseInGroups(head, k);

    printf("Reversed list in groups of %d:   ", k);
    printList(head);
    return 0;
}
