class MinStack {
    constructor(capacity) {
        this.capacity = capacity;
        this.stack = [];
        this.minStack = [];
    }
    
    isEmpty() {
        return this.stack.length === 0;
    }
    
    isFull() {
        return this.stack.length === this.capacity;
    }
    
    push(value) {
        if (this.isFull()) {
            console.log("Stack Overflow! Cannot push element.");
            return;
        }
        
        this.stack.push(value);
        
        // Update minStack
        if (this.minStack.length === 0 || value <= this.minStack[this.minStack.length - 1]) {
            this.minStack.push(value);
        }
        
        console.log(`Pushed ${value} to stack`);
    }
    
    pop() {
        if (this.isEmpty()) {
            console.log("Stack Underflow! Cannot pop element.");
            return null;
        }
        
        const popped = this.stack.pop();
        
        // Update minStack if we're popping the current minimum
        if (popped === this.minStack[this.minStack.length - 1]) {
            this.minStack.pop();
        }
        
        console.log(`Popped ${popped} from stack`);
        return popped;
    }
    
    top() {
        if (this.isEmpty()) {
            console.log("Stack is empty!");
            return null;
        }
        return this.stack[this.stack.length - 1];
    }
    
    getMin() {
        if (this.isEmpty()) {
            console.log("Stack is empty!");
            return null;
        }
        return this.minStack[this.minStack.length - 1];
    }
    
    display() {
        if (this.isEmpty()) {
            console.log("Stack is empty!");
            return;
        }
        
        console.log("Stack elements (top to bottom):", [...this.stack].reverse());
        console.log("Current minimum:", this.getMin());
    }
}

// Example usage
function testMinStack() {
    // Create a stack with capacity 5
    const stack = new MinStack(5);
    
    // Test operations
    console.log("Pushing elements...");
    stack.push(3);
    stack.push(5);
    stack.push(2);
    stack.push(1);
    
    console.log("\nDisplaying stack:");
    stack.display();
    
    console.log(`\nTop element: ${stack.top()}`);
    console.log(`Minimum element: ${stack.getMin()}`);
    
    console.log("\nPopping elements...");
    stack.pop();
    stack.pop();
    
    console.log("\nDisplaying stack after pops:");
    stack.display();
    
    // Test overflow
    console.log("\nTesting overflow...");
    stack.push(7);
    stack.push(8);
    stack.push(9);  // This should show overflow error
    
    // Test underflow
    console.log("\nTesting underflow...");
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();  // This should show underflow error
}

// Run the test
testMinStack();

