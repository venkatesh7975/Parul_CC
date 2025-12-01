# Write your code here!!

# Initialization
N = int(input())
stack = []
minstack = []

top = -1
mintop = -1

def push(value):
    global top, mintop

    if top == N - 1:
        print("overflow")
        return
    
    stack.append(value)
    top += 1

    if mintop == -1 or value <= minstack[mintop]:
        minstack.append(value)
        mintop += 1

    print(f"Pushed {value}")

def pop():
    global top, mintop

    if top == -1:
        print("underflow")
        return

    if stack[top] == minstack[mintop]:
        minstack.pop()
        mintop -= 1

    stack.pop()
    top -= 1

def Top():
    if top == -1:
        print("stack is empty")
        return
    print(f"Top: {stack[top]}")

def getMin():
    if mintop == -1:
        print("Minstack empty")
        return
    print(f"Min: {minstack[mintop]}")

while True:
    line = input().strip()

    # If empty input, continue
    if not line:
        continue

    parts = list(map(int, line.split()))

    choice = parts[0]

    if choice == 1:
        # push command, value in the same line: "1 10"
        if len(parts) == 2:
            val = parts[1]
        else:
            val = int(input())   # if value comes in next line
        push(val)

    elif choice == 2:
        pop()

    elif choice == 3:
        Top()

    elif choice == 4:
        getMin()

    elif choice == 5:
        print("Exit")
        break
