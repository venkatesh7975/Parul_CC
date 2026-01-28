# Infix to Postfix Conversion - Pseudocode

## Problem Statement
Convert an infix expression to its postfix (Reverse Polish Notation) equivalent using the Shunting Yard algorithm.

## Algorithm - Shunting Yard

### Convert Infix to Postfix
```
FUNCTION infixToPostfix(infixExpression):
    stack = empty stack
    postfix = empty string
    tokens = tokenize(infixExpression)
    
    FOR each token in tokens:
        IF token is an operand:
            postfix = postfix + token + " "
        
        ELSE IF token is '(':
            stack.push(token)
        
        ELSE IF token is ')':
            WHILE stack is not empty AND stack.top() != '(':
                postfix = postfix + stack.pop() + " "
            END WHILE
            
            IF stack is empty:
                PRINT "Mismatched parentheses"
                RETURN error
            END IF
            
            stack.pop()  // Remove '('
        
        ELSE IF token is an operator:
            WHILE stack is not empty AND precedence(stack.top()) >= precedence(token):
                IF isRightAssociative(token) AND precedence(stack.top()) == precedence(token):
                    BREAK
                END IF
                postfix = postfix + stack.pop() + " "
            END WHILE
            
            stack.push(token)
        
        ELSE:
            PRINT "Invalid token:", token
            RETURN error
        END IF
    END FOR
    
    // Pop remaining operators
    WHILE stack is not empty:
        IF stack.top() == '(' OR stack.top() == ')':
            PRINT "Mismatched parentheses"
            RETURN error
        END IF
        postfix = postfix + stack.pop() + " "
    END WHILE
    
    RETURN postfix
END FUNCTION
```

### Get Operator Precedence
```
FUNCTION precedence(operator):
    IF operator == '+' OR operator == '-':
        RETURN 1
    ELSE IF operator == '*' OR operator == '/':
        RETURN 2
    ELSE IF operator == '^':
        RETURN 3
    ELSE:
        RETURN 0
    END IF
END FUNCTION
```

### Check Associativity
```
FUNCTION isRightAssociative(operator):
    IF operator == '^':
        RETURN true
    ELSE:
        RETURN false
    END IF
END FUNCTION
```

## Time Complexity
O(n) - where n is the number of tokens

## Space Complexity
O(n) - for the stack and output

## Example
```
Infix: "3 + 4 * 2 / ( 1 - 5 ) ^ 2"
Postfix: "3 4 2 * 1 5 - 2 ^ / +"
```

## Operator Precedence
| Operator | Precedence | Associativity |
|----------|-----------|---------------|
| + - | 1 | Left |
| * / | 2 | Left |
| ^ | 3 | Right |
