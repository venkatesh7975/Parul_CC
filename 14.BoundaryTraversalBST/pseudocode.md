# Boundary Traversal of Binary Tree - Pseudocode

## Problem Statement
Traverse the boundary of a binary tree: left boundary, bottom nodes, and right boundary.

## Data Structure
```
Node:
  - data: Integer value
  - left: Pointer to left child
  - right: Pointer to right child
```

## Algorithm

### Boundary Traversal
```
FUNCTION boundaryTraversal(root):
    IF root == null:
        RETURN
    END IF
    
    result = empty list
    
    // Add root
    result.add(root.data)
    
    // Add left boundary
    addLeftBoundary(root.left, result)
    
    // Add bottom nodes
    addBottomNodes(root.left, result)
    addBottomNodes(root.right, result)
    
    // Add right boundary (in reverse)
    rightBoundary = empty list
    addRightBoundary(root.right, rightBoundary)
    reverse(rightBoundary)
    result.addAll(rightBoundary)
    
    RETURN result
END FUNCTION
```

### Add Left Boundary
```
FUNCTION addLeftBoundary(node, result):
    IF node == null:
        RETURN
    END IF
    
    IF isLeaf(node):
        RETURN
    END IF
    
    result.add(node.data)
    
    IF node.left != null:
        addLeftBoundary(node.left, result)
    ELSE:
        addLeftBoundary(node.right, result)
    END IF
END FUNCTION
```

### Add Bottom Nodes
```
FUNCTION addBottomNodes(node, result):
    IF node == null:
        RETURN
    END IF
    
    IF isLeaf(node):
        result.add(node.data)
        RETURN
    END IF
    
    addBottomNodes(node.left, result)
    addBottomNodes(node.right, result)
END FUNCTION
```

### Add Right Boundary
```
FUNCTION addRightBoundary(node, result):
    IF node == null:
        RETURN
    END IF
    
    IF isLeaf(node):
        RETURN
    END IF
    
    IF node.right != null:
        addRightBoundary(node.right, result)
    ELSE:
        addRightBoundary(node.left, result)
    END IF
    
    result.add(node.data)
END FUNCTION
```

### Check if Node is Leaf
```
FUNCTION isLeaf(node):
    IF node == null:
        RETURN false
    END IF
    
    RETURN node.left == null AND node.right == null
END FUNCTION
```

## Time Complexity
O(n) - where n is the number of nodes

## Space Complexity
O(h) - where h is the height (recursion stack)

## Example
```
Tree:
        1
       / \
      2   3
     / \   \
    4   5   6
       / \
      7   8

Boundary Traversal: 1, 2, 4, 7, 5, 8, 6, 3
```
