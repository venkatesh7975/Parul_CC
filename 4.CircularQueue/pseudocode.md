# Circular Queue - Pseudocode

## Problem Statement
Implement a circular queue with enqueue, dequeue, and display operations.

## Data Structure
```
CircularQueue:
  - array: Array to store elements
  - front: Index of front element
  - rear: Index of rear element
  - capacity: Maximum size
  - size: Current number of elements
```

## Algorithm

### Initialize Queue
```
FUNCTION initialize(capacity):
    array = empty array of size capacity
    front = 0
    rear = -1
    size = 0
    RETURN CircularQueue instance
END FUNCTION
```

### Enqueue Operation
```
FUNCTION enqueue(element):
    IF size == capacity:
        PRINT "Queue Overflow"
        RETURN false
    END IF
    
    rear = (rear + 1) % capacity
    array[rear] = element
    size = size + 1
    
    PRINT "Element enqueued:", element
    RETURN true
END FUNCTION
```

### Dequeue Operation
```
FUNCTION dequeue():
    IF size == 0:
        PRINT "Queue Underflow"
        RETURN null
    END IF
    
    element = array[front]
    front = (front + 1) % capacity
    size = size - 1
    
    PRINT "Element dequeued:", element
    RETURN element
END FUNCTION
```

### Display Queue
```
FUNCTION display():
    IF size == 0:
        PRINT "Queue is empty"
        RETURN
    END IF
    
    PRINT "Queue elements:"
    i = front
    FOR count = 0 TO size-1:
        PRINT array[i]
        i = (i + 1) % capacity
    END FOR
END FUNCTION
```

### Get Front Element
```
FUNCTION getFront():
    IF size == 0:
        PRINT "Queue is empty"
        RETURN null
    END IF
    
    RETURN array[front]
END FUNCTION
```

## Time Complexity
- Enqueue: O(1)
- Dequeue: O(1)
- Display: O(n)

## Space Complexity
O(capacity)
