
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

    struct Node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(20);

    /*
    struct Node* root = NULL;
    int val;
    printf("Enter value for root: ");
    scanf("%d", &val);
    root = createNode(val);

    printf("Enter left child of %d: ", val);
    scanf("%d", &val);
    root->left = createNode(val);

    printf("Enter right child of %d: ", val);
    scanf("%d", &val);
    root->right = createNode(val);


    */

    int minLeaf = INT_MAX;
    int maxLeaf = INT_MIN;

    findMinMaxLeaf(root, &minLeaf, &maxLeaf);

    printf("Minimum leaf node value: %d\n", minLeaf);
    printf("Maximum leaf node value: %d\n", maxLeaf);

    return 0;
}