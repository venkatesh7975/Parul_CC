#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = v;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int vals[], int *idx, int n) {
    if (*idx >= n || vals[*idx] == -1) {
        (*idx)++;
        return NULL;
    }
    struct Node* root = newNode(vals[*idx]);
    (*idx)++;
    root->left = buildTree(vals, idx, n);
    root->right = buildTree(vals, idx, n);
    return root;
}

void printLeaves(struct Node* root) {
    if (!root) return;
    printLeaves(root->left);
    if (!root->left && !root->right)
        printf("%d ", root->val);
    printLeaves(root->right);
}

void printBoundary(struct Node* root) {
    if (!root) return;
    printf("Boundary Traversal: %d ", root->val);

    // Left boundary
    struct Node* node = root->left;
    while (node) {
        if (node->left || node->right)
            printf("%d ", node->val);
        if (node->left)
            node = node->left;
        else
            node = node->right;
    }

    // Leaf nodes
    printLeaves(root->left);
    printLeaves(root->right);

    // Right boundary (store then print in reverse)
    int rightVals[1000];
    int count = 0;
    node = root->right;
    while (node) {
        if (node->left || node->right)
            rightVals[count++] = node->val;
        if (node->right)
            node = node->right;
        else
            node = node->left;
    }

    for (int i = count - 1; i >= 0; i--)
        printf("%d ", rightVals[i]);
}

int main() {
    int vals[1000], n = 0, x;
    while (scanf("%d", &x) != EOF)
        vals[n++] = x;

    int idx = 0;
    struct Node* root = buildTree(vals, &idx, n);
    printBoundary(root);
    return 0;
}
