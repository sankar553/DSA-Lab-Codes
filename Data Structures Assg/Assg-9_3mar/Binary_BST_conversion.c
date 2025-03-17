#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}



int main()
{
    struct Node *root = createNode(10);
    root->left = createNode(30);
    root->right = createNode(20);
    root->left->left = createNode(5);
    root->left->right = createNode(15);
    root->right->right = createNode(25);
    printf("Inorder Traversal of the given tree is\n");
    inorderTraversal(root);
    return 0;
}