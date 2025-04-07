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

    printf("Enter the elements to insert in the Hash Table (you can only add %d elements)\n", size);
    int i = 0;
    do
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &hashTable[i]); // Inserting elements
        i++;
    } while (i < size);
    printf("You can stop now as Hash table is finished\n");

    display(hashTable, size);

    printf("Enter the key to search: ");
    scanf("%d", &key);
    search(hashTable, size, key);


    return 0;
}