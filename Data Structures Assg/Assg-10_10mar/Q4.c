#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void inorderList(struct Node *root, int *list, int *index)
{
    if (root != NULL)
    {
        inorderList(root->left, list, index);
        list[*index] = root->data;
        (*index)++;
        inorderList(root->right, list, index);
    }
}

int main()
{
    
    return 0;
}
