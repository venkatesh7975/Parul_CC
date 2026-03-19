import heapq 

n=int(input()) 
chars=input().split()
freq=list(map(int,input().split()))

class Node:
    def __init__(self,ch,freq,left=None,right=None):
        self.ch=ch 
        self.freq=freq 
        self.left=left 
        self.right=right 
    
pq=[]
for i in range(n):
    node=Node(chars[i],freq[i])
    heapq.heappush(pq,(freq[i],chars[i],node))

while len(pq)>1:
    f1,c1,left=heapq.heappop(pq)
    f2,c2,right=heapq.heappop(pq) 
    smallest=min(c1,c2)
    merged=Node("$",f1+f2,left,right)
    heapq.heappush(pq,(f1+f2,smallest,merged)) 

root=pq[0][2]
codes={}

def build_codes(root,path,codes):
    if root is None:
        return  
    if root.left is None and root.right is None:
        codes[root.ch]="".join(path)
        return 
    path.append("0")
    build_codes(root.left,path,codes)
    path.pop() 

    path.append("1")
    build_codes(root.right,path,codes)
    path.pop() 

build_codes(root,[],codes)
print("Huffman Codes:")
for c in chars:
    print(f"{c}: {codes[c]}")
