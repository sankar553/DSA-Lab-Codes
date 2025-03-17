
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

void findMinMaxLeaf(struct Node *root, int *minLeaf, int *maxLeaf)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        if (root->data < *minLeaf)
            *minLeaf = root->data;

        if (root->data > *maxLeaf)
            *maxLeaf = root->data;

        return;
    }
    findMinMaxLeaf(root->left, minLeaf, maxLeaf);
    findMinMaxLeaf(root->right, minLeaf, maxLeaf);
}

int main()
{
    int minLeaf = INT_MAX;
    int maxLeaf = INT_MIN;

    struct Node *root = createNode(1);
    root->left = createNode(304);
    root->right = createNode(34);
    root->left->left = createNode(-3);
    root->left->right = createNode(6);
    root->right->left = createNode(3);
    root->right->right = createNode(1);
    root->right->left->right = createNode(30);
    root->right->right->left = createNode(100);

    findMinMaxLeaf(root, &minLeaf, &maxLeaf);
    printf("Minimum leaf node value: %d\n", minLeaf);
    printf("Maximum leaf node value: %d\n", maxLeaf);

    return 0;
}