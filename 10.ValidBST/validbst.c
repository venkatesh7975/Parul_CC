#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int arr[200000];
int idx = 0;
int n = 0;

/* Build tree from preorder input with -1 as NULL */
struct Node* buildTree() {
    if (idx >= n)
        return NULL;

    int val = arr[idx++];
    if (val == -1)
        return NULL;

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = buildTree();
    node->right = buildTree();

    return node;
}

/* Validate BST using range */
int isValidBST(struct Node* root, int min, int max) {
    if (root == NULL)
        return 1;

    if (root->data <= min || root->data >= max)
        return 0;

    return isValidBST(root->left, min, root->data) &&
           isValidBST(root->right, root->data, max);
}

int main() {
    /* Read input until EOF */
    while (scanf("%d", &arr[n]) != EOF) {
        n++;
    }

    struct Node* root = buildTree();

    /* Value range: -10^5 to 10^5 */
    if (isValidBST(root, -100001, 100001))
        printf("True");
    else
        printf("False");

    return 0;
}
