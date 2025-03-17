#include <stdio.h>
#include <stdlib.h>

struct linkedlist
{
    int data;
    struct linkedlist *next;
};

struct linkedlist *createlinkedlist(int value)
{
    struct linkedlist *newlinkedlist = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    newlinkedlist->data = value;
    newlinkedlist->next = NULL;
    return newlinkedlist;
}

void reverseList(struct linkedlist **head)
{
    struct linkedlist *prev = NULL;
    struct linkedlist *current = *head;
    struct linkedlist *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}
void printList(struct linkedlist *head, int n)
{
    int var = 1;
    struct linkedlist *current = head;
    printf("[ ");
    while (current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
        if (var != n)
        {
            printf(" --> ");
            var++;
        }
    }
    printf(" ]\n");
}

int main()
{
    struct linkedlist *head = NULL;
    int n, value, j,k;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the element(s) of the linked list of your wish: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        struct linkedlist *newlinkedlist = createlinkedlist(value);
        if (head == NULL)
        {
            head = newlinkedlist;
        }
        else
        {
            struct linkedlist *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newlinkedlist;
        }
    }

    printf("The entered linked list is: \n");
    printList(head, n);

    reverseList(&head);
    printf("List after reversing: \n");
    printList(head, n);

    return 0;
}