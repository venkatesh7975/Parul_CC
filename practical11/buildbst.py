values=list(map(int,input().split()))

class Node:
    def __init__(self,value):
        self.data=value 
        self.left=None 
        self.right=None 

root=None 

def insert(root,value):
    if root is None:
        root=Node(value)
    elif value<root.data:
        root.left=insert(root.left,value)
    else:
        root.right=insert(root.right,value)
    return root 

for i in values[:len(values)-1]:
    root=insert(root,i)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.data,end=" ")
        inorder(root.right)
inorder(root)
