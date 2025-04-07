#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1

void insert(int hashTable[], int size, int key)
{
    int index = key % size;
    int probes = 0;

    while (probes < size)
    {
        if (hashTable[index] == EMPTY)
        {
            hashTable[index] = key;
            printf("Inserted key %d at index %d\n", key, index);
            return;
        }
        index = (index + 1) % size;
        probes++;
    }

    printf("******Hash table is full******. Could not insert key --> %d <--\n", key);
}

void display(int hashTable[], int size)
{
    printf("\nFinal Hash Table State:\n");
    for (int i = 0; i < size; i++)
    {
        if (hashTable[i] != EMPTY)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: EMPTY\n", i);
    }
}

void search(int hashTable[], int size, int key)
{
    int index = key % size;
    int probes = 0;

    while (hashTable[index] != EMPTY && probes < size)
    {
        if (hashTable[index] == key)
        {
            printf("Key %d found at index %d with %d probe(s)\n", key, index, probes + 1);
            return;
        }
        index = (index + 1) % size;
        probes++;
    }

    printf("Key %d not found in the hashtable\n", key);
    display(hashTable, size);
    // printf("Number of probes: %d\n", probes);
}

int main()
{
    int size;
    printf("Enter the size of the hash table: ");
    scanf("%d", &size);

    int *hashTable = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        hashTable[i] = EMPTY;

    int choice, key, option;

    do
    {
        printf("\nMenu:\n1. Insert Key\n2. Search Key\n3. Display Table\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insert(hashTable, size, key);
            printf("Do you want to continue (Yes->1)\n");
            scanf("%d", &option);
            break;
        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            search(hashTable, size, key);
            printf("Do you want to continue (Yes->1)\n");
            scanf("%d", &option);
            break;
        case 3:
            display(hashTable, size);
            printf("Do you want to continue (Yes->1)\n");
            scanf("%d", &option);
            break;
        default:
            printf("Invalid choice. Try again.\n");
            printf("Do you want to continue (Yes->1)\n");
            scanf("%d", &option);
        }
    } while (option != 0);

    return 0;
}