#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int key, value;
    struct Node* next;
};

struct Node* table[SIZE] = {NULL};

int hashFunc(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    int index = hashFunc(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if (table[index] == NULL)
        table[index] = newNode;
    else {
        struct Node* curr = table[index];
        while (curr->next)
            curr = curr->next;
        curr->next = newNode;
    }
    printf("Inserted: (%d,%d)\n", key, value);
}

void get(int key) {
    int index = hashFunc(key);
    struct Node* curr = table[index];
    while (curr) {
        if (curr->key == key) {
            printf("%d -> %d\n", key, curr->value);
            return;
        }
        curr = curr->next;
    }
    printf("%d not found\n", key);
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        struct Node* curr = table[i];
        if (!curr)
            printf("NULL\n");
        else {
            while (curr) {
                printf("(%d,%d)-> ", curr->key, curr->value);
                curr = curr->next;
            }
            printf("NULL\n");
        }
    }
}

int main() {
    int op, key, value;
    while (1) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d", &key, &value);
            insert(key, value);
        } else if (op == 2) {
            scanf("%d", &key);
            get(key);
        } else if (op == 3) {
            display();
        } else if (op == 4) {
            printf("Exit\n");
            break;
        }
    }
    return 0;
}
