#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

int insertSubstring(TrieNode* root, const char* str) {
    TrieNode* curr = root;
    int newNodes = 0;
    for (int i = 0; str[i]; i++) {
        int index = str[i] - 'a';
        if (!curr->children[index]) {
            curr->children[index] = createNode();
            newNodes++;
        }
        curr = curr->children[index];
    }
    return newNodes;
}

int countDistinctSubstrings(const char* s) {
    TrieNode* root = createNode();
    int count = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        count += insertSubstring(root, s + i);
    return count;
}

int main() {
    char s[1000];
    scanf("%s", s);
    printf("%d\n", countDistinctSubstrings(s));
    return 0;
}
