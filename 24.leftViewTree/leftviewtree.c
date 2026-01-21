#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char key[100];
    struct Node *left, *right;
} Node;

Node* createNode(char *key) {
    Node *node = (Node*)malloc(sizeof(Node));
    strcpy(node->key, key);
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, char *key) {
    if (!root) return createNode(key);
    if (strcmp(key, root->key) < 0)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

typedef struct QueueNode {
    Node* node;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* node) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->node = node;
    temp->next = NULL;
    if (!q->rear) q->front = q->rear = temp;
    else { q->rear->next = temp; q->rear = temp; }
}

Node* dequeue(Queue* q) {
    if (!q->front) return NULL;
    QueueNode* temp = q->front;
    Node* node = temp->node;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return node;
}

int queueSize(Queue* q) {
    int count = 0;
    QueueNode* temp = q->front;
    while (temp) { count++; temp = temp->next; }
    return count;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void leftView(Node* root) {
    if (!root) return;
    Queue* q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        int n = queueSize(q);
        Node* first = q->front->node;
        printf("%s ", first->key);
        for (int i = 0; i < n; i++) {
            Node* node = dequeue(q);
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    Node* root = NULL;
    char keyword[100];
    for (int i = 0; i < n; i++) {
        fgets(keyword, sizeof(keyword), stdin);
        keyword[strcspn(keyword, "\n")] = '\0';
        root = insert(root, keyword);
    }
    leftView(root);
    return 0;
}
