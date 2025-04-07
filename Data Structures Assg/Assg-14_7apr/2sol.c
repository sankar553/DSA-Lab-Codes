#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100


typedef struct Node
{
    char key[MAX_LEN];
    struct Node *next;
} Node;


Node *createNode(char *key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->next = NULL;
    return newNode;
}


int hashFunction(char *key, int size)
{
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++)
        hash += key[i];
    return hash % size;
}


void insert(Node *hashTable[], int size, char *key)
{
    int index = hashFunction(key, size);
    Node *newNode = createNode(key);

    if (hashTable[index] == NULL)
    {
        hashTable[index] = newNode;
    }
    else
    {
        Node *temp = hashTable[index];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Inserted key \"%s\" at bucket %d\n", key, index);
}


void display(Node *hashTable[], int size)
{
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Bucket %d:", i);
        Node *temp = hashTable[i];
        if (!temp)
        {
            printf(" NULL");
        }
        while (temp != NULL)
        {
            printf(" -> %s", temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
}


void search(Node *hashTable[], int size, char *key)
{
    int index = hashFunction(key, size);
    Node *temp = hashTable[index];
    int position = 0;

    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
        {
            printf("Key \"%s\" found at bucket %d, node position %d\n", key, index, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Key \"%s\" not found in the hash table.\n", key);
}

int main()
{
    int size, choice;
    char key[MAX_LEN];

    printf("Enter size of hash table: ");
    scanf("%d", &size);

    Node **hashTable = (Node **)calloc(size, sizeof(Node *));

    while (1)
    {
        printf("\nMenu:\n1. Insert Key\n2. Search Key\n3. Display Table\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            fgets(key, MAX_LEN, stdin);
            key[strcspn(key, "\n")] = 0; 
            insert(hashTable, size, key);
            break;
        case 2:
            printf("Enter key to search: ");
            fgets(key, MAX_LEN, stdin);
            key[strcspn(key, "\n")] = 0;
            search(hashTable, size, key);
            break;
        case 3:
            display(hashTable, size);
            break;
        case 4:
            
            for (int i = 0; i < size; i++)
            {
                Node *temp = hashTable[i];
                while (temp != NULL)
                {
                    Node *toDelete = temp;
                    temp = temp->next;
                    free(toDelete);
                }
            }
            free(hashTable);
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
