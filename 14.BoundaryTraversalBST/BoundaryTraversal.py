import sys
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        
def build_tree(values):
    try:
        val = next(values)
    except StopIteration:
        return None

    if val == -1:
        return None

    node = Node(val)
    node.left = build_tree(values)
    node.right = build_tree(values)
    return node



def printLeaves(root, res):
    if not root:
        return
    printLeaves(root.left, res)
    if not root.left and not root.right:
        res.append(root.val)
    printLeaves(root.right, res)

def boundaryTraversal(root):
    res = []
    if not root:
        return res
    res.append(root.val)

    # Left boundary
    node = root.left
    while node:
        if node.left or node.right:
            res.append(node.val)
        node = node.left if node.left else node.right

    # Leaves
    printLeaves(root.left, res)
    printLeaves(root.right, res)

    # Right boundary
    node = root.right
    rightNodes = []
    while node:
        if node.left or node.right:
            rightNodes.append(node.val)
        node = node.right if node.right else node.left
    res.extend(reversed(rightNodes))

    return res



vals = (map(int, sys.stdin.read().split()))

root = build_tree(vals)
ans = boundaryTraversal(root)
print("Boundary Traversal:", *ans)
