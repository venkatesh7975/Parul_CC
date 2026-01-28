# Left View of Binary Tree - Pseudocode

## Problem Statement
Print the left view of a binary tree (visible nodes when looking from the left side).

## Data Structure
```
Node:
  - data: Integer value
  - left: Pointer to left child
  - right: Pointer to right child
```

## Algorithm - Using Level Order Traversal

### Get Left View - Level Order
```
FUNCTION getLeftView(root):
    IF root == null:
        RETURN
    END IF
    
    leftView = empty list
    queue = empty queue
    queue.enqueue(root)
    
    WHILE queue is not empty:
        levelSize = queue.size()
        
        FOR i = 0 TO levelSize - 1:
            node = queue.dequeue()
            
            // Add first node of each level
            IF i == 0:
                leftView.add(node.data)
            END IF
            
            IF node.left != null:
                queue.enqueue(node.left)
            END IF
            
            IF node.right != null:
                queue.enqueue(node.right)
            END IF
        END FOR
    END WHILE
    
    RETURN leftView
END FUNCTION
```

### Get Left View - Using Recursion
```
FUNCTION getLeftViewRecursive(root):
    leftView = empty list
    maxLevel = [-1]  // Track maximum level seen
    
    getLeftViewHelper(root, 0, leftView, maxLevel)
    
    RETURN leftView
END FUNCTION
```

### Get Left View Recursive Helper
```
FUNCTION getLeftViewHelper(node, level, leftView, maxLevel):
    IF node == null:
        RETURN
    END IF
    
    // If this is the first node of this level
    IF level > maxLevel[0]:
        leftView.add(node.data)
        maxLevel[0] = level
    END IF
    
    // First traverse left, then right
    getLeftViewHelper(node.left, level + 1, leftView, maxLevel)
    getLeftViewHelper(node.right, level + 1, leftView, maxLevel)
END FUNCTION
```

### Get Right View
```
FUNCTION getRightView(root):
    IF root == null:
        RETURN
    END IF
    
    rightView = empty list
    queue = empty queue
    queue.enqueue(root)
    
    WHILE queue is not empty:
        levelSize = queue.size()
        
        FOR i = 0 TO levelSize - 1:
            node = queue.dequeue()
            
            // Add last node of each level
            IF i == levelSize - 1:
                rightView.add(node.data)
            END IF
            
            IF node.left != null:
                queue.enqueue(node.left)
            END IF
            
            IF node.right != null:
                queue.enqueue(node.right)
            END IF
        END FOR
    END WHILE
    
    RETURN rightView
END FUNCTION
```

### Get Top View
```
FUNCTION getTopView(root):
    IF root == null:
        RETURN
    END IF
    
    topView = empty map (horizontal distance -> node value)
    queue = empty queue of {node, distance}
    
    queue.enqueue({root, 0})
    
    WHILE queue is not empty:
        {node, distance} = queue.dequeue()
        
        // If this is first node at this distance
        IF distance not in topView:
            topView[distance] = node.data
        END IF
        
        IF node.left != null:
            queue.enqueue({node.left, distance - 1})
        END IF
        
        IF node.right != null:
            queue.enqueue({node.right, distance + 1})
        END IF
    END WHILE
    
    // Sort by distance and return values
    RETURN sortAndExtractValues(topView)
END FUNCTION
```

### Display Results
```
FUNCTION displayView(viewName, viewList):
    PRINT viewName, ":"
    FOR each element in viewList:
        PRINT element, " "
    END FOR
    PRINT newline
END FUNCTION
```

## Time Complexity
- Level order approach: O(n)
- Recursive approach: O(n)

## Space Complexity
- Level order: O(w) - where w is maximum width
- Recursive: O(h) - where h is height

## Example
```
Tree:
        1
       / \
      2   3
     / \ / \
    4  5 6  7
   /
  8

Left View: [1, 2, 4, 8]
Right View: [1, 3, 7]
Top View: [4, 2, 1, 3, 7]
Bottom View: [4, 8, 5, 6, 7]
```
