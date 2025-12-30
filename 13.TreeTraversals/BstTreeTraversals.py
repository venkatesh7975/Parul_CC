# Write your code here!!

import sys
sys.setrecursionlimit(10**7)

class TreeNode:
    def __init__(self, value):
        self.id = value
        self.left = None
        self.right = None


data = list(map(int, sys.stdin.read().split()))
it = iter(data)


def build_tree():
    val = next(it)
    if val == -1:
        return None

    node = TreeNode(val)
    node.left = build_tree()
    node.right = build_tree()
    return node


def preorder(root):
    if root:
        print(root.id, end=" ")
        preorder(root.left)
        preorder(root.right)


def inorder(root):
    if root:
        inorder(root.left)
        print(root.id, end=" ")
        inorder(root.right)


def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.id, end=" ")


root = build_tree()

preorder(root)
print()
inorder(root)
print()
postorder(root)
