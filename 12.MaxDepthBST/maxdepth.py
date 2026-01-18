import sys
sys.setrecursionlimit(10000)

class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


def build_tree(values):
    val = next(values)
    if val == -1:
        return None
    node = Node(val)
    node.left = build_tree(values)
    node.right = build_tree(values)
    return node


def max_depth(root):
    if not root:
        return 0
    left_depth = max_depth(root.left)
    right_depth = max_depth(root.right)
    return max(left_depth, right_depth) + 1



data = list(map(int, sys.stdin.read().split()))
root = build_tree(iter(data))
print(max_depth(root))
