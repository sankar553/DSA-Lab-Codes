// The Question was to find the maximum depth of a binary tree. The maximum depth of a binary tree is the number of edges in the tree from root to the deepest node
// Let's start coding
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int maxDepth(struct Node *root)
{
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth + 1 > rightDepth + 1 ? leftDepth + 1 : rightDepth + 1);
}

int main()
{
    // I think i have to give the input in the code itself and then print the output
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(7);
    root->left->right->left = newNode(8);
    root->left->right->left->right = newNode(9);
    root->left->right->left->right->left = newNode(10);
    root->left->right->left->right->left->left = newNode(11);

    // char operator = 'y';
    // int value;
    // while(operator == 'n'){
    //     printf("Enter the data value you want to add: ");
    //     scanf("%d",&value);
    // }
    printf("Maximum depth of the tree: %d\n", maxDepth(root));
    return 0;
}