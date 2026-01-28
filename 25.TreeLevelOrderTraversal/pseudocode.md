# Tree Level Order Traversal - Pseudocode

## Problem Statement
Perform level order traversal (Breadth-First Search) on a binary tree.

## Data Structure
```
Node:
  - data: Integer value
  - left: Pointer to left child
  - right: Pointer to right child
```

## Algorithm

### Level Order Traversal (BFS)
```
FUNCTION levelOrderTraversal(root):
    IF root == null:
        PRINT "Tree is empty"
        RETURN
    END IF
    
    queue = empty queue
    queue.enqueue(root)
    
    WHILE queue is not empty:
        node = queue.dequeue()
        PRINT node.data + " "
        
        IF node.left != null:
            queue.enqueue(node.left)
        END IF
        
        IF node.right != null:
            queue.enqueue(node.right)
        END IF
    END WHILE
END FUNCTION
```

### Level Order Traversal by Levels
```
FUNCTION levelOrderTraversalByLevels(root):
    IF root == null:
        PRINT "Tree is empty"
        RETURN
    END IF
    
    result = empty list
    queue = empty queue
    queue.enqueue(root)
    
    WHILE queue is not empty:
        levelSize = queue.size()
        currentLevel = empty list
        
        FOR i = 0 TO levelSize - 1:
            node = queue.dequeue()
            currentLevel.add(node.data)
            
            IF node.left != null:
                queue.enqueue(node.left)
            END IF
            
            IF node.right != null:
                queue.enqueue(node.right)
            END IF
        END FOR
        
        result.add(currentLevel)
    END WHILE
    
    RETURN result
END FUNCTION
```

### Get Tree Height
```
FUNCTION getTreeHeight(root):
    IF root == null:
        RETURN 0
    END IF
    
    queue = empty queue
    queue.enqueue(root)
    height = 0
    
    WHILE queue is not empty:
        levelSize = queue.size()
        height = height + 1
        
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
    
    RETURN height
END FUNCTION
```

### Get Nodes at Specific Level
```
FUNCTION getNodesAtLevel(root, level):
    IF root == null:
        RETURN empty list
    END IF
    
    nodesAtLevel = empty list
    queue = empty queue
    queue.enqueue({root, 0})
    
    WHILE queue is not empty:
        {node, currentLevel} = queue.dequeue()
        
        IF currentLevel == level:
            nodesAtLevel.add(node.data)
        END IF
        
        IF node.left != null:
            queue.enqueue({node.left, currentLevel + 1})
        END IF
        
        IF node.right != null:
            queue.enqueue({node.right, currentLevel + 1})
        END IF
    END WHILE
    
    RETURN nodesAtLevel
END FUNCTION
```

### Count Nodes at Each Level
```
FUNCTION countNodesAtEachLevel(root):
    IF root == null:
        RETURN empty map
    END IF
    
    levelCount = empty map
    queue = empty queue
    queue.enqueue(root)
    level = 0
    
    WHILE queue is not empty:
        levelSize = queue.size()
        levelCount[level] = levelSize
        
        FOR i = 0 TO levelSize - 1:
            node = queue.dequeue()
            
            IF node.left != null:
                queue.enqueue(node.left)
            END IF
            
            IF node.right != null:
                queue.enqueue(node.right)
            END IF
        END FOR
        
        level = level + 1
    END WHILE
    
    RETURN levelCount
END FUNCTION
```

### Zigzag Level Order Traversal
```
FUNCTION zigzagLevelOrderTraversal(root):
    IF root == null:
        RETURN empty list
    END IF
    
    result = empty list
    queue = empty queue
    queue.enqueue(root)
    leftToRight = true
    
    WHILE queue is not empty:
        levelSize = queue.size()
        currentLevel = empty list
        
        FOR i = 0 TO levelSize - 1:
            node = queue.dequeue()
            currentLevel.add(node.data)
            
            IF node.left != null:
                queue.enqueue(node.left)
            END IF
            
            IF node.right != null:
                queue.enqueue(node.right)
            END IF
        END FOR
        
        IF NOT leftToRight:
            reverse(currentLevel)
        END IF
        
        result.add(currentLevel)
        leftToRight = NOT leftToRight
    END WHILE
    
    RETURN result
END FUNCTION
```

### Display Level Order Traversal
```
FUNCTION displayLevelOrderTraversal(root):
    result = levelOrderTraversalByLevels(root)
    
    FOR level = 0 TO result.size() - 1:
        PRINT "Level", level, ": "
        FOR each node in result[level]:
            PRINT node, " "
        END FOR
        PRINT newline
    END FOR
END FUNCTION
```

## Time Complexity
- All operations: O(n) - where n is number of nodes

## Space Complexity
- O(w) - where w is maximum width of tree

## Example
```
Tree:
        1
       / \
      2   3
     / \ / \
    4  5 6  7

Level Order: 1 2 3 4 5 6 7

By Levels:
Level 0: [1]
Level 1: [2, 3]
Level 2: [4, 5, 6, 7]

Zigzag:
Level 0: [1] (left to right)
Level 1: [3, 2] (right to left)
Level 2: [4, 5, 6, 7] (left to right)

Height: 3
```
