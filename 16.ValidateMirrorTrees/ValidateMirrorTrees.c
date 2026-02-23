#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int d) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = d;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree() {
    int val;
    if (scanf("%d", &val) != 1 || val == -1)
        return NULL;
    struct Node* node = newNode(val);
    node->left = buildTree();
    node->right = buildTree();
    return node;
}

int isMirror(struct Node* t1, struct Node* t2) {
    if (!t1 && !t2) return 1;
    if (!t1 || !t2) return 0;
    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

int main() {
    struct Node* tree1 = buildTree();
    struct Node* tree2 = buildTree();
    if (isMirror(tree1, tree2))
        printf("The two trees are mirrors of each other.");
    else
        printf("The two trees are not mirrors of each other.");
    return 0;
}
