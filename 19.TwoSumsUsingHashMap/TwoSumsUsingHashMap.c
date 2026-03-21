#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define SIZE 100003
Node* hashTable[SIZE];

int hashFunc(int key) { 
    if (key < 0) key = -key; 
    return key % SIZE; 
}

void insert(int key, int value) {
    int index = hashFunc(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(int key) {
    int index = hashFunc(key);
    Node* curr = hashTable[index];
    while (curr) {
        if (curr->key == key) return curr->value;
        curr = curr->next;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int target;
    scanf("%d", &target);

    printf("Finding two indices whose values add up to %d...\n", target);
    for (int i = 0; i < SIZE; i++) hashTable[i] = NULL;

    int found = 0;
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        int compIndex = search(complement);
        if (compIndex != -1) {
            printf("Indices: %d %d\n", compIndex, i);
            found = 1;
            break;
        }
        insert(arr[i], i);
    }

    if (!found) printf("No solution found\n");
    return 0;
}
