# Write your code here!!

import sys
sys.setrecursionlimit(10**7)

class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


# Read input like Scanner.hasNextInt()
data = list(map(int, sys.stdin.read().split()))
it = iter(data)


def build_tree():
    try:
        val = next(it)
    except StopIteration:
        return None

    if val == -1:
        return None

    node = Node(val)
    node.left = build_tree()
    node.right = build_tree()
    return node


def is_valid_bst(root, min_val, max_val):
    if root is None:
        return True

    if not (min_val < root.data < max_val):
        return False

    return (is_valid_bst(root.left, min_val, root.data) and
            is_valid_bst(root.right, root.data, max_val))


# Build tree
root = build_tree()

# Validate BST using given constraints
print("True" if is_valid_bst(root, -100001, 100001) else "False")
