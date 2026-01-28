# Swap Nodes Pairwise - Pseudocode

## Problem Statement
Swap adjacent nodes in a linked list pairwise.

## Data Structure
```
Node:
  - data: Integer value
  - next: Pointer to next node
```

## Algorithm - Iterative

### Swap Nodes Pairwise
```
FUNCTION swapNodesPairwise(head):
    IF head == null OR head.next == null:
        RETURN head
    END IF
    
    // Create dummy node
    dummy = new Node(-1)
    dummy.next = head
    prev = dummy
    
    WHILE prev.next != null AND prev.next.next != null:
        // Nodes to be swapped
        first = prev.next
        second = prev.next.next
        
        // Perform swap
        prev.next = second
        first.next = second.next
        second.next = first
        
        // Move prev to next pair
        prev = first
    END WHILE
    
    RETURN dummy.next
END FUNCTION
```

### Swap Nodes Pairwise - Recursive
```
FUNCTION swapNodesPairwiseRecursive(head):
    IF head == null OR head.next == null:
        RETURN head
    END IF
    
    // First node to be swapped
    first = head
    
    // Second node to be swapped
    second = head.next
    
    // Make new connections
    first.next = swapNodesPairwiseRecursive(second.next)
    second.next = first
    
    // Return new head
    RETURN second
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
- Iterative: O(n)
- Recursive: O(n)

## Space Complexity
- Iterative: O(1)
- Recursive: O(n) - for recursion stack

## Example
```
Original: 1 -> 2 -> 3 -> 4 -> 5 -> null
Swapped:  2 -> 1 -> 4 -> 3 -> 5 -> null

Explanation:
- Swap (1, 2)
- Swap (3, 4)
- 5 remains as is (single node)
```
