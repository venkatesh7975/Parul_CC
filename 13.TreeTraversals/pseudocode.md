# Binary Tree Traversals - Pseudocode

## Problem Statement
Perform various traversals on a binary tree: Inorder, Preorder, Postorder, and Level Order.

## Data Structure
```
Node:
  - data: Integer value
  - left: Pointer to left child
  - right: Pointer to right child
```

## Algorithm

### Inorder Traversal (Left-Root-Right)
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

### Preorder Traversal (Root-Left-Right)
```
FUNCTION preorderTraversal(node):
    IF node == null:
        RETURN
    END IF
    
    PRINT node.data
    preorderTraversal(node.left)
    preorderTraversal(node.right)
END FUNCTION
```

### Postorder Traversal (Left-Right-Root)
```
FUNCTION postorderTraversal(node):
    IF node == null:
        RETURN
    END IF
    
    postorderTraversal(node.left)
    postorderTraversal(node.right)
    PRINT node.data
END FUNCTION
```

### Level Order Traversal (BFS)
```
FUNCTION levelOrderTraversal(root):
    IF root == null:
        RETURN
    END IF
    
    queue = empty queue
    queue.enqueue(root)
    
    WHILE queue is not empty:
        node = queue.dequeue()
        PRINT node.data
        
        IF node.left != null:
            queue.enqueue(node.left)
        END IF
        
        IF node.right != null:
            queue.enqueue(node.right)
        END IF
    END WHILE
END FUNCTION
```

### Inorder Traversal Iterative (Using Stack)
```
FUNCTION inorderTraversalIterative(root):
    stack = empty stack
    current = root
    
    WHILE current != null OR stack is not empty:
        WHILE current != null:
            stack.push(current)
            current = current.left
        END WHILE
        
        current = stack.pop()
        PRINT current.data
        current = current.right
    END WHILE
END FUNCTION
```

## Time Complexity
All traversals: O(n) - where n is the number of nodes

## Space Complexity
- Recursive: O(h) - where h is height (recursion stack)
- Iterative: O(h) - for explicit stack
- Level order: O(w) - where w is maximum width

## Example
```
Tree:
        1
       / \
      2   3
     / \
    4   5

Inorder: 4, 2, 5, 1, 3
Preorder: 1, 2, 4, 5, 3
Postorder: 4, 5, 2, 3, 1
Level Order: 1, 2, 3, 4, 5
```
