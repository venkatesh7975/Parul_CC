n=int(input())
data=list(map(int,input().split()))

class MaxHeap:
    def __init__(self):
        self.heap=[]

    def getPartentIndex(self,i):
        return (i-1)//2 
    
    def getLeftIndex(self,i):
        return 2*i+1 
    
    def getRightIndex(self,i):
        return 2*i+2 

    def insert(self,val):
        self.heap.append(val)
        self.heapifyUp(len(self.heap)-1)
    
    def heapifyUp(self,i):
    
        while i>0:      
            parentIndex=self.getPartentIndex(i)
            if self.heap[i]>self.heap[parentIndex]:
                self.heap[i],self.heap[parentIndex]=self.heap[parentIndex],self.heap[i]
                i=parentIndex 
            else:
                break 

    def extract(self):

        if len(self.heap) == 0:
            return None

        if len(self.heap) == 1:
            return self.heap.pop()

        maxvalue = self.heap[0]

        self.heap[0] = self.heap.pop()

        self.heapifyDown(0)

        return maxvalue
    
    def heapifyDown(self,i):
        n=len(self.heap)
        while True:
            largest=i
            left=self.getLeftIndex(i)
            right=self.getRightIndex(i)

            if left<n and self.heap[left]>self.heap[largest]:
                largest=left 
            if right<n and self.heap[right]>self.heap[largest]:
                largest=right
            if i==largest:
                break 
            self.heap[i], self.heap[largest] = self.heap[largest], self.heap[i]
            i=largest

        return largest

        


heap=MaxHeap()
data=list(set(data))
for i in data:
    heap.insert(i)

max1=heap.extract()
max2=heap.extract()
max3=heap.extract()
if len(data)<3:
    print(-1)
else:
    print(max1*max2*max3)


