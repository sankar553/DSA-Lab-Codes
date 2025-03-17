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

int sumNonDuplicates(struct linkedlist *head) {
    struct linkedlist* temp = head;
    int sum = 0;
    while (temp) {
        int count = 0;
        struct linkedlist* checker = head;
        while (checker) {
            if (checker->data == temp->data) count++;
            checker = checker->next;
        }
        if (count == 1) sum += temp->data;
        temp = temp->next;
    }
    return sum;
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
    struct linkedlist *head1 = NULL, *head2 = NULL;

    int n, m, value;
    printf("Enter the size of linked list-1: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list-1: ");
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &value);
        struct linkedlist *newlinkedlist = createlinkedlist(value);
        if (head1 == NULL)
        {
            head1 = newlinkedlist;
        }
        else
        {
            struct linkedlist *temp = head1;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newlinkedlist;
        }
    }

    printf("The linked list-1 is: ");
    printList(head1, n);
        printf("Sum of non-duplicate linkedlists: %d\n", sumNonDuplicates(head));


    return 0;
}