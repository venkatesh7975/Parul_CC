import sys

class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

def build_tree(node_iter):
    try:
        val = next(node_iter)
        if val == -1:
            return None
        root = Node(val)
        root.left = build_tree(node_iter)
        root.right = build_tree(node_iter)
        return root
    except StopIteration:
        return None

def find_lca(root, n1, n2):
    while root:
        # If both values are smaller than root, LCA is in the left
        if root.data > n1 and root.data > n2:
            root = root.left
        # If both values are larger than root, LCA is in the right
        elif root.data < n1 and root.data < n2:
            root = root.right
        # This is the split point
        else:
            return root
    return None


# Read first line and convert to list of integers
preorder_input = list(map(int, sys.stdin.readline().split()))
# Read second line for target nodes
n1, n2 = map(int, sys.stdin.readline().split())

# Use an iterator to track progress through the list
node_iter = iter(preorder_input)
root = build_tree(node_iter)

lca = find_lca(root, n1, n2)

if lca:
    print(f"The Lowest Common Ancestor of {n1} and {n2} is {lca.data}.")

