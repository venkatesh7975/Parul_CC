import sys
sys.setrecursionlimit(10000)

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def buildTree(values):
    val = next(values, None)
    if val is None or val == -1:
        return None
    node = Node(val)
    node.left = buildTree(values)
    node.right = buildTree(values)
    return node

def isMirror(t1, t2):
    if not t1 and not t2:
        return True
    if not t1 or not t2:
        return False
    return (t1.data == t2.data and
            isMirror(t1.left, t2.right) and
            isMirror(t1.right, t2.left))


data = list(map(int, sys.stdin.read().split()))
values = iter(data)
tree1 = buildTree(values)
tree2 = buildTree(values)

if isMirror(tree1, tree2):
    print("The two trees are mirrors of each other.")
else:
    print("The two trees are not mirrors of each other.")
