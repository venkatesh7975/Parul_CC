#include <stdio.h>
#include <stdlib.h>
 
struct ListNode {
    int value;
    struct ListNode* next;
};
 
struct ListNode* createNode(int value) {
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->value = value;
    node->next = NULL;
    return node;
}
 
// Read integers until -1 and create linked list
struct ListNode* readLinkedList() {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;
 
    int val;
    while (scanf("%d", &val) == 1 && val != -1) {
        tail->next = createNode(val);
        tail = tail->next;
    }
 
    return dummy.next;
}
 
struct ListNode* mergeSortedLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;
 
    while (l1 && l2) {
        if (l1->value <= l2->value) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
 
    tail->next = (l1 != NULL) ? l1 : l2;
    return dummy.next;
}
 
void printLinkedList(struct ListNode* head) {
    int first = 1;
    while (head) {
        if (!first) printf(" ");
        printf("%d", head->value);
        first = 0;
        head = head->next;
    }
    printf("\n");
}
 
int main() {
    // Read two linked lists until -1
    struct ListNode* l1 = readLinkedList();
    struct ListNode* l2 = readLinkedList();
 
    struct ListNode* merged = mergeSortedLists(l1, l2);
    printLinkedList(merged);
 
    return 0;
}