#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform in-order traversal and collect values
void inorderTraversal(struct Node *root, int *arr, int *index) {
    if (root == NULL) return;
    inorderTraversal(root->left, arr, index);
    arr[(*index)++] = root->data;
    inorderTraversal(root->right, arr, index);
}

// Function to reconstruct the binary tree from sorted values
struct Node* sortedArrayToBST(int *arr, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    struct Node *node = createNode(arr[mid]);
    node->left = sortedArrayToBST(arr, start, mid - 1);
    node->right = sortedArrayToBST(arr, mid + 1, end);
    return node;
}

// Function to convert binary tree to BST
struct Node* convertToBST(struct Node *root) {
    int arr[100]; // Assuming a maximum of 100 nodes
    int index = 0;
    inorderTraversal(root, arr, &index);
    // Sort the array
    for (int i = 0; i < index - 1; i++) {
        for (int j = 0; j < index - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return sortedArrayToBST(arr, 0, index - 1);
}

int main() {
    struct Node *root = createNode(10);
    root->left = createNode(30);
    root->right = createNode(20);
    root->left->left = createNode(5);
    root->left->right = createNode(15);

    printf("Original Binary Tree:\n");
    printf("In-order Traversal: ");
    int arr[100], index = 0;
    inorderTraversal(root, arr, &index);
    for (int i = 0; i < index; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    struct Node *bstRoot = convertToBST(root);
    printf("Converted Binary Search Tree:\n");
    printf("In-order Traversal: ");
    index = 0;
    inorderTraversal(bstRoot, arr, &index);
    for (int i = 0; i < index; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
