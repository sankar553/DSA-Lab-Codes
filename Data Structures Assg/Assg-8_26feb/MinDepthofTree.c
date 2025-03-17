#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node *Newnode(int val)
{
    struct Node *Newnode = (struct Node *)malloc(sizeof(struct Node));
    Newnode->val = val;
    Newnode->left = NULL;
    Newnode->right = NULL;
    return Newnode;
}

int maxDepth(struct Node *root)
{
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth + 1 > rightDepth + 1 ? leftDepth + 1 : rightDepth + 1);
}

int minDepth(struct Node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL)
        return  minDepth(root->right) + 1;
    if (root->right == NULL)
        return  minDepth(root->left) + 1;

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    return (leftDepth < rightDepth ? leftDepth + 1 : rightDepth + 1);
}

int main()
{
    struct Node *root = Newnode(1);
    root->left = Newnode(2);
    root->right = Newnode(3);
    root->left->left = Newnode(4);
    root->left->right = Newnode(5);
    root->right->right = Newnode(90);
    root->left->left->left = Newnode(6);
    root->left->left->left->left = Newnode(7);
    root->left->right->left = Newnode(8);
    root->left->right->left->right = Newnode(9);
    root->left->right->left->right->left = Newnode(10);
    root->left->right->left->right->left->left = Newnode(11);
    root->left->right->left->right->left->left->right = Newnode(13);

    printf("Minimum depth of the tree: %d\n", minDepth(root));
    printf("Maximum depth of the tree: %d\n", maxDepth(root));
    return 0;
}
