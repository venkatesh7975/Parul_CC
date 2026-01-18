#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from preorder input
struct Node* buildTree() {
    int val;
    if (scanf("%d", &val) != 1 || val == -1)
        return NULL;
    struct Node* root = newNode(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// Compute maximum depth of binary tree
int maxDepth(struct Node* root) {
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int main() {
    struct Node* root = buildTree();
    printf("%d", maxDepth(root));
    return 0;
}
