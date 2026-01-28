# Validate Binary Search Tree - Pseudocode

## Problem Statement
Determine if a given binary tree is a valid Binary Search Tree (BST).

## Data Structure
```
Node:
  - data: Integer value
  - left: Pointer to left child
  - right: Pointer to right child
```

## Algorithm - Range Based Approach

### Validate BST
```
FUNCTION isValidBST(root):
    RETURN validateBSTHelper(root, null, null)
END FUNCTION
```

### Validate BST Helper
```
FUNCTION validateBSTHelper(node, minValue, maxValue):
    IF node == null:
        RETURN true
    END IF
    
    // Check if node value is within valid range
    IF (minValue != null AND node.data <= minValue) OR 
       (maxValue != null AND node.data >= maxValue):
        RETURN false
    END IF
    
    // Recursively validate left and right subtrees
    RETURN validateBSTHelper(node.left, minValue, node.data) AND
           validateBSTHelper(node.right, node.data, maxValue)
END FUNCTION
```

### Alternative - In-order Traversal
```
FUNCTION isValidBSTInorder(root):
    previousValue = null
    RETURN inorderTraversal(root, previousValue)
END FUNCTION
```

### In-order Traversal Validation
```
FUNCTION inorderTraversal(node, previousValue):
    IF node == null:
        RETURN true
    END IF
    
    // Check left subtree
    IF NOT inorderTraversal(node.left, previousValue):
        RETURN false
    END IF
    
    // Check if current node is greater than previous
    IF previousValue != null AND node.data <= previousValue.value:
        RETURN false
    END IF
    
    previousValue.value = node.data
    
    // Check right subtree
    RETURN inorderTraversal(node.right, previousValue)
END FUNCTION
```

## Time Complexity
O(n) - where n is the number of nodes

## Space Complexity
O(h) - where h is the height of the tree (recursion stack)

## Example
```
Valid BST:
        5
       / \
      3   7
     / \
    2   4

Invalid BST:
        5
       / \
      3   8
     / \
    2   6  (6 is not in valid range for right subtree of 5)
```
