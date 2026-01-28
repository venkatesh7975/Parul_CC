# Next Greater Element - Pseudocode

## Problem Statement
For each element in an array, find the next element that is greater than it.

## Algorithm - Using Stack

### Find Next Greater Element
```
FUNCTION findNextGreaterElement(array):
    n = length(array)
    result = array of size n, initialized with -1
    stack = empty stack
    
    FOR i = n-1 DOWN TO 0:
        // Pop elements smaller than current element
        WHILE stack is not empty AND array[stack.top()] < array[i]:
            index = stack.pop()
            result[index] = array[i]
        END WHILE
        
        stack.push(i)
    END FOR
    
    RETURN result
END FUNCTION
```

## Alternative Algorithm - Brute Force

```
FUNCTION findNextGreaterElementBruteForce(array):
    n = length(array)
    result = array of size n
    
    FOR i = 0 TO n-1:
        result[i] = -1
        FOR j = i+1 TO n-1:
            IF array[j] > array[i]:
                result[i] = array[j]
                BREAK
            END IF
        END FOR
    END FOR
    
    RETURN result
END FUNCTION
```

## Time Complexity
- Stack approach: O(n)
- Brute force: O(n²)

## Space Complexity
O(n) - for result array and stack

## Example
```
Array: [4, 5, 2, 25]
Result: [5, 25, 25, -1]

Explanation:
- 4 → 5 (next greater element)
- 5 → 25 (next greater element)
- 2 → 25 (next greater element)
- 25 → -1 (no greater element)
```
