# Build Binary Search Tree - Pseudocode

## Problem Statement
Build a Binary Search Tree from a given set of elements.

## Data Structure
```
Node:
  - data: Integer value
  - left: Pointer to left child
  - right: Pointer to right child
```

## Algorithm

### Build BST from Elements
```
FUNCTION buildBST(elements):
    root = null
    
    FOR each element in elements:
        root = insertBST(root, element)
    END FOR
    
    RETURN root
END FUNCTION
```

### Insert Element into BST
```
FUNCTION insertBST(root, element):
    IF root == null:
        newNode = new Node(element)
        RETURN newNode
    END IF
    
    IF element < root.data:
        root.left = insertBST(root.left, element)
    ELSE IF element > root.data:
        root.right = insertBST(root.right, element)
    ELSE:
        // Duplicate element, do not insert
        RETURN root
    END IF
    
    RETURN root
END FUNCTION
```

### Build BST from Sorted Array
```
FUNCTION buildBSTFromSortedArray(sortedArray):
    RETURN buildBSTHelper(sortedArray, 0, length(sortedArray) - 1)
END FUNCTION
```

### Build BST Helper
```
FUNCTION buildBSTHelper(sortedArray, start, end):
    IF start > end:
        RETURN null
    END IF
    
    mid = (start + end) / 2
    
    newNode = new Node(sortedArray[mid])
    newNode.left = buildBSTHelper(sortedArray, start, mid - 1)
    newNode.right = buildBSTHelper(sortedArray, mid + 1, end)
    
    RETURN newNode
END FUNCTION
```

### In-order Traversal (Verify BST)
```
FUNCTION inorderTraversal(node):
    IF node == null:
        RETURN
    END IF
    
    inorderTraversal(node.left)
    PRINT node.data
    inorderTraversal(node.right)
END FUNCTION
```

## Time Complexity
- Building from unsorted array: O(n log n) average, O(n²) worst case
- Building from sorted array: O(n)
- In-order traversal: O(n)

## Space Complexity
O(h) - where h is the height of the tree

## Example
```
Input elements: [5, 3, 7, 2, 4, 6, 8]

Resulting BST:
        5
       / \
      3   7
     / \ / \
    2  4 6  8

In-order: 2, 3, 4, 5, 6, 7, 8
```
