from collections import deque

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.key:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    return root

def leftView(root):
    if not root:
        return []
    res = []
    q = deque([root])
    while q:
        n = len(q)
        res.append(q[0].key)
        for _ in range(n):
            node = q.popleft()
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
    return res

# Main
n = int(input())
root = None
for _ in range(n):
    keyword = input().strip()
    root = insert(root, keyword)

print(*leftView(root))
