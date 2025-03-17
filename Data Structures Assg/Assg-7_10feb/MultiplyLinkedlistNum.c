// Here i need to store two numbers in 2 linked lists(this will be given by user) and then using a function i need to find the value of the number Let say The number is 1234 then in linked list-1 it will be stored as 1->2->3->4 and in linked list-2 it will be stored as 2->3 which resembles 23
// Let's start coding
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

int Multiplylist(struct linkedlist *head1, int n1, struct linkedlist *head2, int n2)
{
    int num1 = 0, num2 = 0;
    struct linkedlist *current1 = head1;
    struct linkedlist *current2 = head2;
    int i = 0, j = 0;
    while (current1 != NULL && i < n1)
    {
        num1 = num1 * 10 + current1->data;
        current1 = current1->next;
    }
    while (current2 != NULL && j < n2)
    {
        num2 = num2 * 10 + current2->data;
        current2 = current2->next;
    }
    return num1 * num2;
}

int Addlist(struct linkedlist *head1, int n1, struct linkedlist *head2, int n2)
{
    int num1 = 0, num2 = 0;
    struct linkedlist *current1 = head1;
    struct linkedlist *current2 = head2;
    int i = 0, j = 0;
    while (current1 != NULL && i < n1)
    {
        num1 = num1 * 10 + current1->data;
        current1 = current1->next;
    }
    while (current2 != NULL && j < n2)
    {
        num2 = num2 * 10 + current2->data;
        current2 = current2->next;
    }
    return num1 + num2;
}
int main()
{
    struct linkedlist *head1 = NULL;
    struct linkedlist *head2 = NULL;
    int num1, num2, n, value;
    printf("Enter the number of digits in 1st number\n");
    scanf("%d", &num1);
    printf("Enter the elements of the linked list: ");
    for (int j = 0; j < num1; j++)
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
    printf("The number is %d and it is stored in linked list -1 as: \n", num1);
    printList(head1, num1);

    // Same Process for another linked list too now i need to write a function so that we get the number from the linked list data and then product them
    printf("Enter the number of digits in 2nd number\n");
    scanf("%d", &num2);
    printf("Enter the elements of the linked list: ");

    for (int j = 0; j < num2; j++)
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
    printf("The number is %d and it is stored in linked list -2 as: \n", num2);
    printList(head2, num2);
    printf("The product of the numbers in both linked lists is : %d\n",Multiplylist(head1,num1,head2,num2));
    printf("The Sum of the numbers in both linked lists is : %d\n",Addlist(head1,num1,head2,num2));

    return 0;
}