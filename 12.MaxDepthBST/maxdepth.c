#include <stdio.h>
#include <stdlib.h>

typedef struct Device {
    int id;
    struct Device *left, *right;
} Device;

Device* createDevice(int val) {
    Device* d = (Device*)malloc(sizeof(Device));
    d->id = val;
    d->left = d->right = NULL;
    return d;
}

Device* buildNetwork() {
    int val;
    if (scanf("%d", &val) != 1) return NULL;
    if (val == -1) return NULL;
    Device* d = createDevice(val);
    d->left = buildNetwork();
    d->right = buildNetwork();
    return d;
}

typedef struct QueueNode {
    Device* device;
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

void enqueue(Queue* q, Device* device) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->device = device;
    temp->next = NULL;
    if (!q->rear) q->front = q->rear = temp;
    else { q->rear->next = temp; q->rear = temp; }
}

Device* dequeue(Queue* q) {
    if (!q->front) return NULL;
    QueueNode* temp = q->front;
    Device* device = temp->device;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return device;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void levelOrder(Device* root) {
    if (!root) return;
    Queue* q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        Device* d = dequeue(q);
        printf("%d ", d->id);
        if (d->left) enqueue(q, d->left);
        if (d->right) enqueue(q, d->right);
    }
}

int main() {
    Device* root = buildNetwork();
    levelOrder(root);
    return 0;
}
