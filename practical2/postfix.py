expr = input().strip()   # read the input

tokens = expr.split()
stack = []

try:
    for token in tokens:

        # Check for operands (supports negative numbers)
        if token.isdigit() or (token.startswith('-') and token[1:].isdigit()):
            stack.append(int(token))

        else:
            # Need two operands
            pop1 = stack.pop()
            pop2 = stack.pop()

            if token == "+":
                stack.append(pop2 + pop1)

            elif token == "-":
                stack.append(pop2 - pop1)

            elif token == "*":
                stack.append(pop2 * pop1)

            elif token == "/":
                if pop1 == 0:
                    print("Error: Division by zero.")
                    exit()
                # integer division
                stack.append(pop2 // pop1)

            else:
                raise Exception  # invalid operator

    # After evaluation, there must be exactly ONE result
    if len(stack) != 1:
        raise Exception

    print(stack[-1])

except:
    print("Evaluation failed due to errors in the expression.")
