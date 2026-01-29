import sys

values = list(map(int, sys.stdin.read().split()))
# ---------- Node Definition ----------
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


# ---------- Build Tree (Preorder with -1) ----------
def insertBST(root, val):
    if not root:
        return Node(val)
    if val < root.val:
        root.left = insertBST(root.left, val)
    else:
        root.right = insertBST(root.right, val)
    return root

root=None 
for i in values:
    if i==-1:
        break 
    root=insertBST(root,i)

# ---------- Utility ----------
def is_leaf(node):
    return node is not None and node.left is None and node.right is None


# ---------- Left Boundary (excluding leaves) ----------
def add_left_boundary(root, result):
    curr = root
    while curr:
        if not is_leaf(curr):
            result.append(curr.val)
        curr = curr.left if curr.left else curr.right


# ---------- Leaf Nodes (left to right) ----------
def add_leaves(root, result):
    if not root:
        return

    if is_leaf(root):
        result.append(root.val)
        return

    add_leaves(root.left, result)
    add_leaves(root.right, result)


# ---------- Right Boundary (excluding leaves, bottom-up) ----------
def add_right_boundary(root, result):
    stack = []
    curr = root

    while curr:
        if not is_leaf(curr):
            stack.append(curr.val)
        curr = curr.right if curr.right else curr.left

    while stack:
        result.append(stack.pop())


# ---------- Boundary Traversal ----------
def boundary_traversal(root):
    if not root:
        return []

    result = []

    if not is_leaf(root):
        result.append(root.val)

    add_left_boundary(root.left, result)
    add_leaves(root, result)
    add_right_boundary(root.right, result)

    return result

boundary = boundary_traversal(root)
print("Boundary Traversal:",*boundary)


