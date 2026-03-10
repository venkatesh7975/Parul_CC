#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 256

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEnd;
} TrieNode;

typedef struct Trie {
    TrieNode *root;
    int count;
} Trie;

TrieNode* createNode() {
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEnd = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

Trie* createTrie() {
    Trie *trie = (Trie*)malloc(sizeof(Trie));
    trie->root = createNode();
    trie->count = 0;
    return trie;
}

void insert(Trie *trie, char *word) {
    TrieNode *node = trie->root;
    for (int i = 0; word[i]; i++) {
        unsigned char c = word[i];
        if (!node->children[c])
            node->children[c] = createNode();
        node = node->children[c];
    }
    if (!node->isEnd) {
        node->isEnd = 1;
        trie->count++;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // to consume newline
    Trie *trie = createTrie();
    char word[1000];
    for (int i = 0; i < n; i++) {
        fgets(word, sizeof(word), stdin);
        word[strcspn(word, "\n")] = '\0';
        insert(trie, word);
    }
    printf("%d\n", trie->count);
    return 0;
}
