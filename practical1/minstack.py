class MinStack:
    def __init__(self, capacity):
        self.capacity = capacity
        self.stack = []
        self.min_stack = []  # Auxiliary stack to track minimum elements
        
    def is_empty(self):
        return len(self.stack) == 0
        
    def is_full(self):
        return len(self.stack) == self.capacity
        
    def push(self, value):
        if self.is_full():
            print("Stack Overflow! Cannot push element.")
            return
            
        self.stack.append(value)
        
        # Update min_stack
        if not self.min_stack or value <= self.min_stack[-1]:
            self.min_stack.append(value)
        
        print(f"Pushed {value} to stack")
        
    def pop(self):
        if self.is_empty():
            print("Stack Underflow! Cannot pop element.")
            return None
            
        popped = self.stack.pop()
        
        # Update min_stack if we're popping the current minimum
        if popped == self.min_stack[-1]:
            self.min_stack.pop()
            
        print(f"Popped {popped} from stack")
        return popped
        
    def top(self):
        if self.is_empty():
            print("Stack is empty!")
            return None
        return self.stack[-1]
        
    def get_min(self):
        if self.is_empty():
            print("Stack is empty!")
            return None
        return self.min_stack[-1]
        
    def display(self):
        if self.is_empty():
            print("Stack is empty!")
            return
        print("Stack elements (top to bottom):", self.stack[::-1])
        print("Current minimum:", self.get_min())

# Example usage
if __name__ == "__main__":
    # Create a stack with capacity 5
    stack = MinStack(5)
    
    # Test operations
    print("Pushing elements...")
    stack.push(3)
    stack.push(5)
    stack.push(2)
    stack.push(1)
    
    print("\nDisplaying stack:")
    stack.display()
    
    print(f"\nTop element: {stack.top()}")
    print(f"Minimum element: {stack.get_min()}")
    
    print("\nPopping elements...")
    stack.pop()
    stack.pop()
    
    print("\nDisplaying stack after pops:")
    stack.display()
    
    # Test overflow
    print("\nTesting overflow...")
    stack.push(7)
    stack.push(8)
    stack.push(9)  # This should show overflow error
    
    # Test underflow
    print("\nTesting underflow...")
    stack.pop()
    stack.pop()
    stack.pop()
    stack.pop()
    stack.pop()  # This should show underflow error