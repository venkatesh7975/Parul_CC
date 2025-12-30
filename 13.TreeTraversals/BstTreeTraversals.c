#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int arr[100000];
int idx = 0;
int n = 0;

struct Node* buildTree() {
    if (idx >= n)
        return NULL;

    if (arr[idx] == -1) {
        idx++;
        return NULL;
    }

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = arr[idx++];
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    while (scanf("%d", &arr[n]) != EOF) {
        n++;
    }

    struct Node* root = buildTree();

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);

    return 0;
}
