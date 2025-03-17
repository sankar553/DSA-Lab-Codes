#include <stdio.h>

struct linkedlist
{
    int data;
    struct linkedlist *next;
};

struct linkedlist *createlinkedlist(int data)
{
    struct linkedlist *newlinkedlist = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    newlinkedlist->data = data;
    newlinkedlist->next = NULL;
    return newlinkedlist;
}

void printList(struct linkedlist *head, int n)
{
    int var = 1;
    struct linkedlist *current = head;
    printf("");
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
    printf("\n");
}

void removeKthlinkedlist(struct linkedlist **head, int k)
{
    struct linkedlist *current = *head;
    struct linkedlist *next = NULL;
    int count = 1;

    while (current != NULL)
    {
        if (count % k == 0)
        {
            struct linkedlist *temp = current;
            next->next = current->next;
            current = current->next;
            free(temp);
        }
        else
        {
            next = current;
            current = current->next;
        }
        count++;
    }
}

int main()
{
    int n, value;
    struct linkedlist *head = NULL;
    printf("Enter the size of linked list needed : ");
    scanf("%d", &n);
    printf("Enter the elements of the linked list: ");
    for (int j = 0; j < n; j++)
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
    int k = 3;
    removeKthlinkedlist(&head, k);

    printf("List after removing every %dth linkedlist: ", k);
    printList(head, n);

    return 0;
}