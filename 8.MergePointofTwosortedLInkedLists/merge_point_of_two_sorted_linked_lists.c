#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* build_list(Node* node_map[1000]) {  // Simple array as map (data 0-999)
    char input[1000];
    fgets(input, sizeof(input), stdin);
    
    char* token = strtok(input, " ");
    Node* head = NULL;
    Node* tail = NULL;
    
    while (token != NULL) {
        int x = atoi(token);
        if (x == -1) break;
        
        Node* new_node;
        if (node_map[x] != NULL) {
            new_node = node_map[x];  // Reuse existing node
        } else {
            new_node = (Node*)malloc(sizeof(Node));
            new_node->data = x;
            new_node->next = NULL;
            node_map[x] = new_node;
        }
        
        if (head == NULL) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        
        token = strtok(NULL, " ");
    }
    return head;
}

int get_length(Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

int find_merge_point(Node* a, Node* b) {
    int len1 = get_length(a);
    int len2 = get_length(b);
    
    int diff = abs(len1 - len2);
    
    if (len1 > len2) {
        while (diff > 0) {
            a = a->next;
            diff--;
        }
    } else {
        while (diff > 0) {
            b = b->next;
            diff--;
        }
    }
    
    while (a != NULL && b != NULL) {
        if (a == b) {  // Pointer comparison (same address)
            return a->data;
        }
        a = a->next;
        b = b->next;
    }
    
    return -1;
}

int main() {
    Node* node_map[1000] = {0};  // Simple hash map (NULL initialized)
    
    Node* head1 = build_list(node_map);
    Node* head2 = build_list(node_map);
    
    printf("%d\n", find_merge_point(head1, head2));
    
    // TODO: Free memory (not shown for brevity)
    return 0;
}
