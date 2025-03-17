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

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void GreaterSumTree(struct Node *root, int *sum)
{
    if (root == NULL)
        return;

    GreaterSumTree(root->right, sum);

    *sum += root->data;
    root->data = *sum - root->data;

    GreaterSumTree(root->left, sum);
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    struct Node *root = NULL;
    printf("Enter the number of elements you want to add in tree\n");
    int n, data;
    scanf("%d", &n);
    printf("now enter the elements in Preorder traversal\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Inorder traversal before transformation: \n");
    inorder(root);
    printf("\n");

    int sum = 0;
    GreaterSumTree(root, &sum);

    printf("Inorder traversal after transformation: \n");
    inorder(root);
    printf("\n");

    return 0;
}
