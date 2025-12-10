def precedence(op):
    if op == '^':
        return 3
    if op == '*' or op == '/':
        return 2
    if op == '+' or op == '-':
        return 1
    return 0

def infix_to_postfix(expr):
    st = []
    result = []

    for ch in expr:
        if ch.isalnum():  # letter or digit
            result.append(ch)
        elif ch == '(':
            st.append(ch)
        elif ch == ')':
            while st and st[-1] != '(':
                result.append(st.pop())
            st.pop()  # remove '('
        else:
            # normal operator
            while (st and precedence(st[-1]) >= precedence(ch) and ch != '^'):
                result.append(st.pop())
            st.append(ch)

    while st:
        result.append(st.pop())

    return " ".join(result)


# main
expr = input().strip()
print(infix_to_postfix(expr))
