# Priority Queue - Pseudocode

## Problem Statement
Implement a priority queue with insertion, deletion, and peek operations where elements are ordered by priority.

## Data Structure
```
PriorityQueue:
  - heapArray: Array to store elements
  - size: Current number of elements
  - capacity: Maximum size
```

## Algorithm - Min Heap Based

### Initialize Priority Queue
```
FUNCTION initialize(capacity):
    heapArray = empty array of size capacity
    size = 0
    RETURN PriorityQueue instance
END FUNCTION
```

### Insert Operation
```
FUNCTION insert(element, priority):
    IF size == capacity:
        PRINT "Priority Queue Overflow"
        RETURN false
    END IF
    
    node = new Node(element, priority)
    heapArray[size] = node
    currentIndex = size
    size = size + 1
    
    // Bubble up to maintain heap property
    WHILE currentIndex > 0:
        parentIndex = (currentIndex - 1) / 2
        IF heapArray[currentIndex].priority < heapArray[parentIndex].priority:
            swap(heapArray[currentIndex], heapArray[parentIndex])
            currentIndex = parentIndex
        ELSE:
            BREAK
        END IF
    END WHILE
    
    PRINT "Element inserted:", element, "with priority:", priority
    RETURN true
END FUNCTION
```

### Delete (Extract Min) Operation
```
FUNCTION deleteMin():
    IF size == 0:
        PRINT "Priority Queue Underflow"
        RETURN null
    END IF
    
    minElement = heapArray[0]
    heapArray[0] = heapArray[size - 1]
    size = size - 1
    
    // Bubble down to maintain heap property
    currentIndex = 0
    WHILE true:
        smallestIndex = currentIndex
        leftChild = 2 * currentIndex + 1
        rightChild = 2 * currentIndex + 2
        
        IF leftChild < size AND heapArray[leftChild].priority < heapArray[smallestIndex].priority:
            smallestIndex = leftChild
        END IF
        
        IF rightChild < size AND heapArray[rightChild].priority < heapArray[smallestIndex].priority:
            smallestIndex = rightChild
        END IF
        
        IF smallestIndex != currentIndex:
            swap(heapArray[currentIndex], heapArray[smallestIndex])
            currentIndex = smallestIndex
        ELSE:
            BREAK
        END IF
    END WHILE
    
    RETURN minElement
END FUNCTION
```

### Peek Operation
```
FUNCTION peek():
    IF size == 0:
        PRINT "Priority Queue is empty"
        RETURN null
    END IF
    
    RETURN heapArray[0]
END FUNCTION
```

## Time Complexity
- Insert: O(log n)
- Delete: O(log n)
- Peek: O(1)

## Space Complexity
O(n)
