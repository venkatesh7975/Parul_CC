# MinStack - Pseudocode

## Problem Statement
Implement a stack that supports push, pop, and retrieving the minimum element in constant time.

## Data Structure
```
MinStack:
  - mainStack: Array to store all elements
  - minStack: Array to store minimum elements
  - top: Index of top element
  - capacity: Maximum size of stack
```

## Algorithm

### Initialize MinStack
```
FUNCTION initialize(capacity):
    mainStack = empty array of size capacity
    minStack = empty array of size capacity
    top = -1
    RETURN MinStack instance
END FUNCTION
```

### Push Operation
```
FUNCTION push(element):
    IF top == capacity - 1:
        PRINT "Stack Overflow"
        RETURN
    END IF
    
    top = top + 1
    mainStack[top] = element
    
    IF minStack is empty OR element <= minStack.top():
        minStack.push(element)
    END IF
    
    PRINT "Element pushed:", element
END FUNCTION
```

### Pop Operation
```
FUNCTION pop():
    IF top == -1:
        PRINT "Stack Underflow"
        RETURN null
    END IF
    
    element = mainStack[top]
    
    IF element == minStack.top():
        minStack.pop()
    END IF
    
    top = top - 1
    PRINT "Element popped:", element
    RETURN element
END FUNCTION
```

### Get Minimum
```
FUNCTION getMin():
    IF minStack is empty:
        PRINT "Stack is empty"
        RETURN null
    END IF
    
    RETURN minStack.top()
END FUNCTION
```

### Display Stack
```
FUNCTION display():
    IF top == -1:
        PRINT "Stack is empty"
        RETURN
    END IF
    
    PRINT "Stack elements:"
    FOR i = 0 TO top:
        PRINT mainStack[i]
    END FOR
END FUNCTION
```

## Time Complexity
- Push: O(1)
- Pop: O(1)
- Get Min: O(1)
- Display: O(n)

## Space Complexity
O(n) - for storing elements in two stacks
