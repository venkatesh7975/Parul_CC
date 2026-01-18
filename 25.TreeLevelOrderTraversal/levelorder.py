import sys
from collections import deque

class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


data = (map(int, sys.stdin.read().split()))

def build_tree(values):
    val = next(values)
    if val == -1:
        return None
    node = Node(val)
    node.left = build_tree(values)
    node.right = build_tree(values)
    return node

def level_order(root):
    q = deque([root])
    while q:
        node = q.popleft()
        print(node.data, end=" ")
        if node.left:
            q.append(node.left)
        if node.right:
            q.append(node.right)


root = build_tree(data)
level_order(root)
