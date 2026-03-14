#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char ch;
    int freq;
    char smallestChar;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char ch, int freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->ch = ch;
    node->freq = freq;
    node->smallestChar = ch;
    node->left = node->right = NULL;
    return node;
}

void swap(struct Node** a, struct Node** b) {
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct Node* heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size &&
        (heap[left]->freq < heap[smallest]->freq ||
        (heap[left]->freq == heap[smallest]->freq &&
         heap[left]->smallestChar < heap[smallest]->smallestChar)))
        smallest = left;

    if (right < size &&
        (heap[right]->freq < heap[smallest]->freq ||
        (heap[right]->freq == heap[smallest]->freq &&
         heap[right]->smallestChar < heap[smallest]->smallestChar)))
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

struct Node* extractMin(struct Node* heap[], int* size) {
    struct Node* root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size, 0);
    return root;
}

void insertHeap(struct Node* heap[], int* size, struct Node* node) {
    int i = (*size)++;
    heap[i] = node;

    while (i && (heap[(i-1)/2]->freq > heap[i]->freq ||
        (heap[(i-1)/2]->freq == heap[i]->freq &&
         heap[(i-1)/2]->smallestChar > heap[i]->smallestChar))) {

        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void buildCodes(struct Node* root, char code[], int depth, char codes[256][256]) {
    if (!root) return;

    if (!root->left && !root->right) {
        code[depth] = '\0';
        strcpy(codes[(int)root->ch], code);
        return;
    }

    code[depth] = '0';
    buildCodes(root->left, code, depth+1, codes);

    code[depth] = '1';
    buildCodes(root->right, code, depth+1, codes);
}

int main() {
    int n;
    scanf("%d", &n);

    char chars[n];
    int freq[n];

    for(int i=0;i<n;i++) scanf(" %c",&chars[i]);
    for(int i=0;i<n;i++) scanf("%d",&freq[i]);

    struct Node* heap[2*n];
    int size = 0;

    for(int i=0;i<n;i++)
        insertHeap(heap, &size, createNode(chars[i], freq[i]));

    while(size > 1) {
        struct Node* left = extractMin(heap, &size);
        struct Node* right = extractMin(heap, &size);

        struct Node* merged = createNode('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        merged->smallestChar = left->smallestChar < right->smallestChar ?
                               left->smallestChar : right->smallestChar;

        insertHeap(heap, &size, merged);
    }

    struct Node* root = heap[0];

    char codes[256][256] = {0};
    char code[256];

    buildCodes(root, code, 0, codes);

    printf("Huffman Codes:\n");

    for(int i=0;i<n;i++)
        printf("%c: %s\n", chars[i], codes[(int)chars[i]]);

    return 0;
}
