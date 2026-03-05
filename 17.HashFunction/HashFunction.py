
class Node:
    def __init__(self,key,value):
        self.key=key 
        self.value =value 
        self.next=None 

class HashTable:
    def __init__(self):
        self.size=10
        self.Table=[None]*self.size 
    def hashFunc(self,key):
        return key%self.size
    
    def insert(self,key,value):
        index=self.hashFunc(key)
        newNode=Node(key,value)
        if self.Table[index] is None:
            self.Table[index]=newNode
        else:
            curr=self.Table[index]
            while curr.next:
                curr=curr.next 
            curr.next=newNode 
        print(f"Inserted: ({key},{value})")
    
    def get(self,key):
        index=self.hashFunc(key)
        curr=self.Table[index]
        while curr:
            if curr.key==key:
                print(f"{key} -> {curr.value}")
                return 
            curr=curr.next 
        print(f" {key} not found")

    def display(self):
        for i in range(self.size):
            print(f"{i}:",end=" ")
            curr=self.Table[i]
            if not curr:
                print("Null")
            else:
                while curr:
                    print(f"({curr.key},{curr.value})->",end=" ")
                    curr=curr.next 
                print("NULL")

ht=HashTable() 
while True:
    op=int(input())
    if op==1:
        key,value=list(map(int,input().split()))
        ht.insert(key,value)
    elif op==2:
        key=int(input())
        ht.get(key)
    elif op==3:
        ht.display()
    elif op==4:
        print("Exit")
        break 
        
