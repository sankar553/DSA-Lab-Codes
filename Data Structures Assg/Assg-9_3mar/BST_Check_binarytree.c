/*Ok the basic logic was A Binary Search Tree (BST) is a node-based binary tree data structure with the following properties.  All keys in the left subtree are smaller than the root and all keys in the right subtree are greater. Both the left and right subtrees must also be binary search trees. Each key must be distinct
let's make a complete c code for the Quesion
Write a program to  Check if a Binary Tree is BST or not.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int BSThelper(struct Node *root, int min, int max) 
{
    if (root == NULL)
    {
        return 1;
    }
    if (root->data < min || root->data > max)
    {
        return 0;
    }
    return (BSThelper(root->left, min, root->data - 1) && BSThelper(root->right, root->data + 1, max));
}

int isBST(struct Node *root)
{
    return BSThelper(root, INT_MIN, INT_MAX);
}

int main()
{

    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter a value for node-%d\n", i);
        scanf("%d", &arr[i]);
    }
    struct Node *root = createNode(arr[0]);
    root->left = createNode(arr[1]);
    root->right = createNode(arr[2]);
    root->left->left = createNode(arr[3]);
    root->left->right = createNode(arr[4]);

    if (isBST(root))
    {
        printf("The given Binary tree is a BST\nAs All keys in the left subtree are smaller than the root and all keys in the right subtree are greater. Both the left and right subtrees must also be binary search trees. Each key must be distinct.\n\n");
    }
    else
        printf("The given Binary tree is not a BST\n");

    return 0;
}