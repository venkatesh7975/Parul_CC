#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_SIZE 128

typedef struct TrieNode {
    struct TrieNode* children[CHAR_SIZE];
    int isEnd;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEnd = 0;
    for (int i = 0; i < CHAR_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(TrieNode* root, char* word) {
    TrieNode* curr = root;
    for (int i = 0; i < strlen(word); i++) {
        if (curr->children[(int)word[i]] == NULL)
            curr->children[(int)word[i]] = createNode();
        curr = curr->children[(int)word[i]];
    }
    curr->isEnd = 1;
    printf("Inserted: %s\n", word);
}

int search(TrieNode* root, char* word) {
    TrieNode* curr = root;
    for (int i = 0; i < strlen(word); i++) {
        if (curr->children[(int)word[i]] == NULL)
            return 0;
        curr = curr->children[(int)word[i]];
    }
    return curr->isEnd;
}

int removeHelper(TrieNode* node, char* word, int depth) {
    if (node == NULL) return 0;
    if (depth == strlen(word)) {
        if (!node->isEnd) return 0;
        node->isEnd = 0;
        for (int i = 0; i < CHAR_SIZE; i++)
            if (node->children[i]) return 0;
        return 1;
    }
    int index = (int)word[depth];
    if (removeHelper(node->children[index], word, depth + 1)) {
        free(node->children[index]);
        node->children[index] = NULL;
        if (!node->isEnd) {
            for (int i = 0; i < CHAR_SIZE; i++)
                if (node->children[i]) return 0;
            return 1;
        }
    }
    return 0;
}

void removeWord(TrieNode* root, char* word) {
    if (!search(root, word))
        printf("Not found: %s\n", word);
    else {
        removeHelper(root, word, 0);
        printf("Removed: %s\n", word);
    }
}

int main() {
    TrieNode* root = createNode();
    int choice;
    char word[100];

    while (scanf("%d", &choice) != EOF) {
        if (choice == 4) break;
        switch (choice) {
            case 1:
                scanf("%s", word);
                insert(root, word);
                break;
            case 2:
                scanf("%s", word);
                printf("%s: %s\n", search(root, word) ? "Found" : "Not found", word);
                break;
            case 3:
                scanf("%s", word);
                removeWord(root, word);
                break;
        }
    }
    return 0;
}
