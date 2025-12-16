class CircularQueue:
    def __init__(self, size):
        self.k = size            # Size of the queue
        self.front = -1          # Front of the queue
        self.rear = -1           # Rear of the queue
        self.queue = [0] * size  # Array to store queue elements
    
    # Enqueue function
    def enqueue(self, x):
        # Check overflow
        if (self.rear + 1) % self.k == self.front:
            print("Queue Overflow")
            return
        if self.front == -1:
            self.front = 0
        self.rear = (self.rear + 1) % self.k
        self.queue[self.rear] = x
        print(f"Enqueued {x}")
    
    # Dequeue function
    def dequeue(self):
        # Check underflow
        if self.front == -1:
            print("Queue Underflow")
            return
        print(f"Dequeued {self.queue[self.front]}")
        if self.front == self.rear:
            self.front = -1
            self.rear = -1
        else:
            self.front = (self.front + 1) % self.k

# Reading the size of the queue
k = int(input())  # Read the size of the queue
queue = CircularQueue(k)

# Loop to handle input
while True:
    try:
        # Read the whole line of input
        input_line = input()
        
        # Split the input line into individual values
        values = list(map(int, input_line.split()))
        
        # Process each value
        for x in values:
            if x >= 0:
                queue.enqueue(x)
            elif x == -1:
                queue.dequeue()
    except EOFError:
        break
