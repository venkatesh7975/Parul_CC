# Node definition
class ListNode:
    def __init__(self, value):
        self.value = value
        self.next = None
 
 
# Create a linked list from input values (skip -1)
def create_linked_list(values):
    dummy = ListNode(0)
    tail = dummy
 
    for v in values:
        if v != -1:
            tail.next = ListNode(v)
            tail = tail.next
 
    return dummy.next
 
 
# Merge two sorted linked lists
def merge_sorted_lists(l1, l2):
    dummy = ListNode(0)
    tail = dummy
 
    p1 = l1
    p2 = l2
 
    while p1 and p2:
        if p1.value <= p2.value:
            tail.next = p1
            p1 = p1.next
        else:
            tail.next = p2
            p2 = p2.next
 
        tail = tail.next
 
    # Attach remaining nodes
    if p1:
        tail.next = p1
    else:
        tail.next = p2
 
    return dummy.next
 
 
# Print the linked list
def print_linked_list(head):
    current = head
    result = []
 
    while current:
        result.append(str(current.value))
        current = current.next
 
    print(" ".join(result))
 
 
# -------- Main Program --------
# Read input
list1 = list(map(int, input().split()))
list2 = list(map(int, input().split()))
 
# Create linked lists
l1 = create_linked_list(list1)
l2 = create_linked_list(list2)
 
# Merge linked lists
merged = merge_sorted_lists(l1, l2)
 
# Output result
print_linked_list(merged)