#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


int isDeadEnd(struct Node* root, int min, int max) {
    if (root == NULL) {
        return 0; 
    }

    if (min == max) {
        return 1; 
    }
 
    return isDeadEnd(root->left, min, root->data - 1) ||
           isDeadEnd(root->right, root->data + 1, max);
}


struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}


int main() {
    struct Node* root = NULL;

    printf("Enter the number of elements you want to add in tree: ");
    int n, data;
    scanf("%d", &n);

    printf("Now enter the elements (any order, they will be inserted into BST):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    
    if (isDeadEnd(root, 1, INT_MAX)) { 
        printf("The BST contains a Dead End.\n");
    } else {
        printf("The BST does not contain any Dead End.\n");
    }

    return 0;
}
