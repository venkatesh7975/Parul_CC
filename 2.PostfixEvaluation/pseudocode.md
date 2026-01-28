# Postfix Expression Evaluation - Pseudocode

## Problem Statement
Evaluate a postfix (Reverse Polish Notation) expression and return the result.

## Algorithm

### Evaluate Postfix Expression
```
FUNCTION evaluatePostfix(expression):
    stack = empty stack
    tokens = split(expression)
    
    FOR each token in tokens:
        IF token is a number:
            stack.push(token)
        ELSE IF token is an operator:
            IF stack has less than 2 elements:
                PRINT "Invalid expression"
                RETURN error
            END IF
            
            operand2 = stack.pop()
            operand1 = stack.pop()
            
            result = performOperation(operand1, operand2, token)
            stack.push(result)
        ELSE:
            PRINT "Invalid token:", token
            RETURN error
        END IF
    END FOR
    
    IF stack.size() != 1:
        PRINT "Invalid expression"
        RETURN error
    END IF
    
    RETURN stack.pop()
END FUNCTION
```

### Perform Operation
```
FUNCTION performOperation(operand1, operand2, operator):
    SWITCH operator:
        CASE '+':
            RETURN operand1 + operand2
        CASE '-':
            RETURN operand1 - operand2
        CASE '*':
            RETURN operand1 * operand2
        CASE '/':
            IF operand2 == 0:
                PRINT "Division by zero error"
                RETURN error
            END IF
            RETURN operand1 / operand2
        CASE '^':
            RETURN operand1 ^ operand2
        DEFAULT:
            PRINT "Unknown operator:", operator
            RETURN error
    END SWITCH
END FUNCTION
```

## Time Complexity
O(n) - where n is the number of tokens

## Space Complexity
O(n) - for the stack

## Example
```
Expression: "5 3 +"
Stack operations:
1. Push 5: [5]
2. Push 3: [5, 3]
3. Read '+': pop 3 and 5, compute 5 + 3 = 8, push 8: [8]
Result: 8
```
