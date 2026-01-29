import sys

# ---------- Node Definition ----------
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


# ---------- Build Tree (Preorder with -1) ----------
def build_tree(values):
    try:
        val = next(values)
    except StopIteration:
        return None

    if val == -1:
        return None

    root = Node(val)
    root.left = build_tree(values)
    root.right = build_tree(values)
    return root


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



values = map(int, sys.stdin.read().split())
root = build_tree(values)

boundary = boundary_traversal(root)
print("Boundary Traversal:",*boundary)


