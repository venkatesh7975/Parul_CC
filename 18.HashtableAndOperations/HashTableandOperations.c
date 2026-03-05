#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
    int key, value;
    struct Node* next;
} Node;

Node* hashTable[SIZE] = {NULL};

int hash(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];  // insert at front
    hashTable[index] = newNode;
    printf("Inserted: (%d,%d)\n", key, value);
}

void deleteKey(int key) {
    int index = hash(key);
    Node* curr = hashTable[index];
    Node* prev = NULL;
    while (curr) {
        if (curr->key == key) {
            if (prev) prev->next = curr->next;
            else hashTable[index] = curr->next;
            free(curr);
            printf("Key %d deleted successfully.\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Key %d not found.\n", key);
}

void search(int key) {
    int index = hash(key);
    Node* curr = hashTable[index];
    while (curr) {
        if (curr->key == key) {
            printf("%d -> %d\n", key, curr->value);
            return;
        }
        curr = curr->next;
    }
    printf("Key %d not found.\n", key);
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i]) {
            printf("Index %d: ", i);
            Node* curr = hashTable[i];
            while (curr) {
                printf("(%d,%d) ", curr->key, curr->value);
                curr = curr->next;
            }
            printf("\n");
        }
    }
}

int main() {
    int choice, key, value;
    while (1) {
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1:
                scanf("%d %d", &key, &value);
                insert(key, value);
                break;
            case 2:
                scanf("%d", &key);
                deleteKey(key);
                break;
            case 3:
                scanf("%d", &key);
                search(key);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exit\n");
                return 0;
        }
    }
    return 0;
}
