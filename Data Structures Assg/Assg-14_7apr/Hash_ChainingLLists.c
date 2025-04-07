#include<stdio.h>

typedef struct Node
{
    char key[100];
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

int main() {
    
    return 0;
}