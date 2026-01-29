#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

// Insert into BST
Node* insertBST(Node* root, int val) {
    if (!root) return newNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// Check leaf
int isLeaf(Node* root) {
    return root && !root->left && !root->right;
}

// Left boundary (excluding leaves)
void leftBoundary(Node* root) {
    if (!root) return;
    if (root->left) { printf("%d ", root->val); leftBoundary(root->left); }
    else if (root->right) { printf("%d ", root->val); leftBoundary(root->right); }
}

// Right boundary (excluding leaves) bottom-up
void rightBoundary(Node* root) {
    if (!root) return;
    if (root->right) { rightBoundary(root->right); printf("%d ", root->val); }
    else if (root->left) { rightBoundary(root->left); printf("%d ", root->val); }
}

// Print leaves left to right
void printLeaves(Node* root) {
    if (!root) return;
    printLeaves(root->left);
    if (isLeaf(root)) printf("%d ", root->val);
    printLeaves(root->right);
}

// Boundary traversal
void boundaryTraversal(Node* root) {
    if (!root) return;
    printf("%d ", root->val);  // Root
    leftBoundary(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    rightBoundary(root->right);
}

int main() {
    Node* root = NULL;
    int val;
    while (scanf("%d", &val) == 1 && val != -1) {
        root = insertBST(root, val);
    }
    printf("Boundary Traversal: ");
    boundaryTraversal(root);
    printf("\n");
    return 0;
}
