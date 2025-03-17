/*
Now i need to find the logic for finding the 3 different divisors for a given integer...

But one thing was sure that for such input numbers there will be 3 prime-divisors only

*/                
#include <stdio.h>
#include <stdlib.h>

struct linkedlist {
    int data;
    struct linkedlist *next;
};

struct linkedlist *createlinkedlist(int value) {
    struct linkedlist *newlinkedlist = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    newlinkedlist->data = value;
    newlinkedlist->next = NULL;
    return newlinkedlist;
}

void printList(struct linkedlist *head, int n) {
    int var = 1;
    struct linkedlist *current = head;
    printf("[ ");
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (var != n) {
            printf(" --> ");
            var++;
        }
    }
    printf(" ]\n");
}

int findFactors(int n) {
    int count = 0;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            count++;
            int temp = n / i;
            for (int j = 2; j <= temp / 2; j++) {
                if (temp % j == 0 && j != i) {
                    count++;
                    return count;
                }
            }
        }
    }
    return count;
}

int sumOfNodes(struct linkedlist *head) {
    int sum = 0;
    struct linkedlist *current = head;
    while (current != NULL) {
        if (findFactors(current->data) >= 2) {
            sum += current->data;
        }
        current = current->next;
    }
    return sum;
}

int main() {
    struct linkedlist *head = NULL;

    int n, value;
    printf("Enter the size of linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list: ");
    for (int j = 0; j < n; j++) {
        scanf("%d", &value);
        struct linkedlist *newlinkedlist = createlinkedlist(value);
        if (head == NULL) {
            head = newlinkedlist;
        } else {
            struct linkedlist *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newlinkedlist;
        }
    }

    printf("The linked list is: ");
    printList(head, n);

    int sum = sumOfNodes(head);
    printf("The sum of nodes that can be divided into three distinct integers is: %d\n", sum);

    return 0;
}