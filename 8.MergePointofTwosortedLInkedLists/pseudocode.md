# Find Merge Point of Two Sorted Linked Lists - Pseudocode

## Problem Statement
Find the node where two sorted linked lists merge into one common list.

## Data Structure
```
Node:
  - data: Integer value
  - next: Pointer to next node
```

## Algorithm - Two Pointer Approach

### Find Merge Point
```
FUNCTION findMergePoint(head1, head2):
    pointer1 = head1
    pointer2 = head2
    
    // Traverse both lists to find merge point
    WHILE pointer1 != pointer2:
        IF pointer1 == null:
            pointer1 = head2
        ELSE:
            pointer1 = pointer1.next
        END IF
        
        IF pointer2 == null:
            pointer2 = head1
        ELSE:
            pointer2 = pointer2.next
        END IF
    END WHILE
    
    IF pointer1 == null:
        PRINT "No merge point found"
        RETURN -1
    END IF
    
    RETURN pointer1.data
END FUNCTION
```

### Alternative Approach - Get Lengths
```
FUNCTION findMergePointByLength(head1, head2):
    length1 = getLength(head1)
    length2 = getLength(head2)
    
    pointer1 = head1
    pointer2 = head2
    
    // Move the pointer of the longer list
    IF length1 > length2:
        FOR i = 0 TO length1 - length2 - 1:
            pointer1 = pointer1.next
        END FOR
    ELSE:
        FOR i = 0 TO length2 - length1 - 1:
            pointer2 = pointer2.next
        END FOR
    END IF
    
    // Move both pointers until they meet
    WHILE pointer1 != pointer2:
        pointer1 = pointer1.next
        pointer2 = pointer2.next
    END WHILE
    
    IF pointer1 == null:
        PRINT "No merge point found"
        RETURN -1
    END IF
    
    RETURN pointer1.data
END FUNCTION
```

### Get Length of List
```
FUNCTION getLength(head):
    length = 0
    current = head
    
    WHILE current != null:
        length = length + 1
        current = current.next
    END WHILE
    
    RETURN length
END FUNCTION
```

## Time Complexity
- Two pointer approach: O(n + m)
- By length approach: O(n + m)

## Space Complexity
O(1)

## Example
```
List 1: 1 -> 2 -> 3 \
                    8 -> 9 -> null
List 2: 4 -> 5 -> 6 -> 7 /

Merge Point: 8
```
