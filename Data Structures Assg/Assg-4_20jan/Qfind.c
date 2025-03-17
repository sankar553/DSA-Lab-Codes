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

int findElement(struct linkedlist *head, int x)
{
    struct linkedlist *current = head;
    int position = 1;

    while (current != NULL)
    {
        if (current->data == x)
        {
            return position;
        }
        current = current->next;
        position++;
    }

    printf("Error: Element %d not found\n", x);
    return -1;
}
// upto now i finished the basic code for creating a linkedlist structure rest of the adding of values are done in the body part of the code

void printList(struct linkedlist *head)
{
    struct linkedlist *current = head;
    printf("[ ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("completed");
    printf(" ]\n");
}

int main()
{
    struct linkedlist *head = NULL;
    int n, value, j, x;

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

    printf("Enter the element to find: ");
    scanf("%d", &x);

    int position = findElement(head, x);
    if (position != -1)
    {
        printf("Element %d found at position %d\n", x, position);
        printList(head);
    }
    //hey help me in solving the error?
    return 0;
}
//hey what was wrong in this code?
