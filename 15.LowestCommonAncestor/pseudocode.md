# Lowest Common Ancestor - Pseudocode

## Problem Statement
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree or Binary Tree.

## Data Structure
```
Node:
  - data: Integer value
  - left: Pointer to left child
  - right: Pointer to right child
```

## Algorithm - BST Based

### Find LCA in BST
```
FUNCTION findLCAInBST(root, node1, node2):
    IF root == null:
        RETURN null
    END IF
    
    IF node1 < root.data AND node2 < root.data:
        // Both nodes are in left subtree
        RETURN findLCAInBST(root.left, node1, node2)
    END IF
    
    IF node1 > root.data AND node2 > root.data:
        // Both nodes are in right subtree
        RETURN findLCAInBST(root.right, node1, node2)
    END IF
    
    // Nodes are on different sides or one of them is root
    RETURN root.data
END FUNCTION
```

### Find LCA in Binary Tree
```
FUNCTION findLCAInBinaryTree(root, p, q):
    IF root == null:
        RETURN null
    END IF
    
    IF root.data == p OR root.data == q:
        RETURN root.data
    END IF
    
    leftLCA = findLCAInBinaryTree(root.left, p, q)
    rightLCA = findLCAInBinaryTree(root.right, p, q)
    
    IF leftLCA != null AND rightLCA != null:
        // Both nodes found in different subtrees
        RETURN root.data
    END IF
    
    IF leftLCA != null:
        RETURN leftLCA
    ELSE:
        RETURN rightLCA
    END IF
END FUNCTION
```

### Alternative - Find Path and LCA
```
FUNCTION findLCAByPath(root, p, q):
    path1 = new list
    path2 = new list
    
    findPath(root, p, path1)
    findPath(root, q, path2)
    
    lca = null
    
    FOR i = 0 TO min(path1.size(), path2.size()) - 1:
        IF path1[i] == path2[i]:
            lca = path1[i]
        ELSE:
            BREAK
        END IF
    END FOR
    
    RETURN lca
END FUNCTION
```

### Find Path to Node
```
FUNCTION findPath(node, value, path):
    IF node == null:
        RETURN false
    END IF
    
    path.add(node.data)
    
    IF node.data == value:
        RETURN true
    END IF
    
    IF findPath(node.left, value, path) OR findPath(node.right, value, path):
        RETURN true
    END IF
    
    path.remove(path.size() - 1)
    RETURN false
END FUNCTION
```

## Time Complexity
- BST approach: O(h) - where h is height
- Binary tree approach: O(n)
- Path approach: O(n)

## Space Complexity
O(h) - for recursion stack

## Example
```
Tree:
        3
       / \
      5   1
     / \  / \
    6  2 0   8
      / \
     7   4

LCA(5, 1) = 3
LCA(5, 4) = 5
LCA(6, 4) = 5
```
