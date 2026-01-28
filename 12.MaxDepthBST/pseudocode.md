# Maximum Depth of Binary Tree - Pseudocode

## Problem Statement
Find the maximum depth (height) of a binary tree.

## Data Structure
```
Node:
  - data: Integer value
  - left: Pointer to left child
  - right: Pointer to right child
```

## Algorithm - Recursive

### Get Maximum Depth
```
FUNCTION getMaxDepth(root):
    IF root == null:
        RETURN 0
    END IF
    
    leftDepth = getMaxDepth(root.left)
    rightDepth = getMaxDepth(root.right)
    
    RETURN max(leftDepth, rightDepth) + 1
END FUNCTION
```

### Get Maximum Depth - Iterative (Level Order Traversal)
```
FUNCTION getMaxDepthIterative(root):
    IF root == null:
        RETURN 0
    END IF
    
    queue = empty queue
    queue.enqueue(root)
    maxDepth = 0
    
    WHILE queue is not empty:
        levelSize = queue.size()
        maxDepth = maxDepth + 1
        
        FOR i = 0 TO levelSize - 1:
            node = queue.dequeue()
            
            IF node.left != null:
                queue.enqueue(node.left)
            END IF
            
            IF node.right != null:
                queue.enqueue(node.right)
            END IF
        END FOR
    END WHILE
    
    RETURN maxDepth
END FUNCTION
```

### Get Minimum Depth
```
FUNCTION getMinDepth(root):
    IF root == null:
        RETURN 0
    END IF
    
    IF root.left == null:
        RETURN getMinDepth(root.right) + 1
    END IF
    
    IF root.right == null:
        RETURN getMinDepth(root.left) + 1
    END IF
    
    RETURN min(getMinDepth(root.left), getMinDepth(root.right)) + 1
END FUNCTION
```

## Time Complexity
- Recursive: O(n) - visit each node once
- Iterative: O(n) - visit each node once

## Space Complexity
- Recursive: O(h) - where h is height (recursion stack)
- Iterative: O(w) - where w is maximum width (queue)

## Example
```
Tree:
        1
       / \
      2   3
     /
    4

Maximum Depth: 3
Minimum Depth: 2
```
