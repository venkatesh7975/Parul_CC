list1=list(map(int,input().split()))

class Node:
    def __init__(self,value):
        self.data=value
        self.next=None
    
def create_list(values):

    head=None
    temp=head
    for i in values:
        if i==-1:
            break
        if head==None:
            head=Node(i)
            temp=head 
        else:
            temp.next=Node(i)
            temp=temp.next 
    return head 
h1=create_list(list1)

def swap_nodes(head):
    dummy=Node(0)
    dummy.next=head 
    prev=dummy
    while prev.next and prev.next.next:
        first=prev.next 
        second=first.next 
        first.next=second.next 
        second.next=first 
        prev.next=second 
        prev=first 
    return dummy.next 

res=swap_nodes(h1)

def display(res):
    temp=res 
    while(temp):
        print(temp.data,end=" ")
        temp=temp.next 

display(res)
