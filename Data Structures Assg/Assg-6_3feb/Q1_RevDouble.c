#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void reverse(struct node **head)
{
    struct node *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }

    *head = prev;
}

void printList(struct node *node)
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

int main()
{
    struct node *head = NULL, *current = NULL, *next = NULL;
    int i = 0, n;

    printf("Enter the number of items required in the linked list: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        current = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data into the list[%d]: ", i + 1);
        scanf("%d", &current->data);
        current->next = NULL;
        current->prev = NULL;

        if (head == NULL)
        {
            head = current;
        }
        else
        {
            next = head;
            while (next->next != NULL)
            {
                next = next->next;
            }
            next->next = current;
            current->prev = next;
        }
    }

    printf("Entered Linked List: ");
    printList(head);

    reverse(&head);

    printf("Reversed Linked List: ");
    printList(head);

    return 0;
}
