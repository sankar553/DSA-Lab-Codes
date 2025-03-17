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

struct linkedlist *findIntersection(struct linkedlist *head1, struct linkedlist *head2)
{

    int len1 = 0, len2 = 0;
    struct linkedlist *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL)
    {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        len2++;
        temp2 = temp2->next;
    }

    int diff = abs(len1 - len2);
    if (len1 > len2)
    {
        for (int i = 0; i < diff; i++)
        {
            head1 = head1->next;
        }
    }
    else
    {
        for (int i = 0; i < diff; i++)
        {
            head2 = head2->next;
        }
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1 == head2)
        {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

void printCommonPart(struct linkedlist *head1, struct linkedlist *head2)
{
    struct linkedlist *intersectionPoint = findIntersection(head1, head2);
    if (intersectionPoint != NULL)
    {
        printf("The common part of the two linked lists is: [ ");
        while (intersectionPoint != NULL)
        {
            printf("%d", intersectionPoint->data);
            intersectionPoint = intersectionPoint->next;
            if (intersectionPoint != NULL)
            {
                printf(" --> ");
            }
        }
        printf(" ]\n");
    }
    else
    {
        printf("No common part found.\n");
    }
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

    printf("Enter the size of linked list-2: ");
    scanf("%d", &m);
    printf("Enter the elements of the linked list-2: ");
    for (int j = 0; j < m; j++)
    {
        scanf("%d", &value);
        struct linkedlist *newlinkedlist = createlinkedlist(value);
        if (head2 == NULL)
        {
            head2 = newlinkedlist;
        }
        else
        {
            struct linkedlist *temp = head2;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newlinkedlist;
        }
    }

    struct linkedlist *intersection = createlinkedlist(5);
    intersection->next = createlinkedlist(6);
    intersection->next->next = createlinkedlist(7);

    struct linkedlist *temp1 = head1;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = intersection;

    struct linkedlist *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = intersection;

    printf("The linked list-1 is: ");
    printList(head1, n);

    printf("The linked list-2 is: ");
    printList(head2, m);

    printCommonPart(head1, head2);

    return 0;
}