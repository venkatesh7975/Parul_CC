# Validate Mirror Trees - Pseudocode

## Problem Statement
Check if two binary trees are mirrors of each other.

## Data Structure
```
Node:
  - data: Integer value
  - left: Pointer to left child
  - right: Pointer to right child
```

## Algorithm

### Check if Trees are Mirrors
```
FUNCTION areMirrors(tree1, tree2):
    RETURN isMirror(tree1, tree2)
END FUNCTION
```

### Is Mirror Helper
```
FUNCTION isMirror(node1, node2):
    // Both nodes are null
    IF node1 == null AND node2 == null:
        RETURN true
    END IF
    
    // One node is null, other is not
    IF node1 == null OR node2 == null:
        RETURN false
    END IF
    
    // Values are different
    IF node1.data != node2.data:
        RETURN false
    END IF
    
    // Check if left of node1 mirrors right of node2
    // AND right of node1 mirrors left of node2
    RETURN isMirror(node1.left, node2.right) AND 
           isMirror(node1.right, node2.left)
END FUNCTION
```

### Create Mirror of Tree
```
FUNCTION createMirror(root):
    IF root == null:
        RETURN null
    END IF
    
    // Create new node with same data
    newNode = new Node(root.data)
    
    // Mirror left and right subtrees
    newNode.left = createMirror(root.right)
    newNode.right = createMirror(root.left)
    
    RETURN newNode
END FUNCTION
```

### Display Tree (Level Order)
```
FUNCTION displayTree(root):
    IF root == null:
        PRINT "Empty tree"
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
    
    PRINT newline
END FUNCTION
```

## Time Complexity
- Checking mirrors: O(n + m) - where n and m are sizes of trees
- Creating mirror: O(n)

## Space Complexity
O(h) - where h is the height (recursion stack)

## Example
```
Tree 1:
        1
       / \
      2   3
     /
    4

Tree 2 (Mirror of Tree 1):
        1
       / \
      3   2
           \
            4

areMirrors(Tree1, Tree2) = true
```
