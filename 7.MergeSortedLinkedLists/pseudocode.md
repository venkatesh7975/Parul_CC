# Merge Sorted Linked Lists - Pseudocode

## Problem Statement
Merge two sorted linked lists into a single sorted linked list.

## Data Structure
```
Node:
  - data: Integer value
  - next: Pointer to next node

LinkedList:
  - head: Pointer to first node
```

## Algorithm

### Merge Two Sorted Lists
```
FUNCTION mergeSortedLists(head1, head2):
    // Create dummy node
    dummy = new Node(-1)
    current = dummy
    
    // Traverse both lists
    WHILE head1 != null AND head2 != null:
        IF head1.data <= head2.data:
            current.next = head1
            head1 = head1.next
        ELSE:
            current.next = head2
            head2 = head2.next
        END IF
        
        current = current.next
    END WHILE
    
    // Attach remaining nodes
    IF head1 != null:
        current.next = head1
    ELSE:
        current.next = head2
    END IF
    
    RETURN dummy.next
END FUNCTION
```

### Merge Recursively
```
FUNCTION mergeSortedListsRecursive(head1, head2):
    IF head1 == null:
        RETURN head2
    END IF
    
    IF head2 == null:
        RETURN head1
    END IF
    
    IF head1.data <= head2.data:
        head1.next = mergeSortedListsRecursive(head1.next, head2)
        RETURN head1
    ELSE:
        head2.next = mergeSortedListsRecursive(head1, head2.next)
        RETURN head2
    END IF
END FUNCTION
```

### Display List
```
FUNCTION displayList(head):
    current = head
    PRINT "List: "
    WHILE current != null:
        PRINT current.data + " -> "
        current = current.next
    END WHILE
    PRINT "null"
END FUNCTION
```

## Time Complexity
O(n + m) - where n and m are lengths of the two lists

## Space Complexity
- Iterative: O(1)
- Recursive: O(n + m) - for recursion stack

## Example
```
List 1: 1 -> 3 -> 5 -> null
List 2: 2 -> 4 -> 6 -> null
Merged: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null
```
