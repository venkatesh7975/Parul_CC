expr=input().strip()#read the input

tokens=expr.split()

stack=[]
try:
    for token in tokens:
        if token.isdigit():
            stack.append(int(token))
        else:
            pop1=stack.pop()
            pop2=stack.pop()
            if (token=="+"):
                stack.append(pop1+pop2)
            elif (token=="-"):
                stack.append(pop2-pop1)
            elif(token=="*"):
                stack.append(pop2*pop1)
            elif (token=="/"):
                if (pop1==0):
                    print("Error: Division by zero.")
                    exit()
                stack.append(int(pop2/pop1))
            else:
                raise Exception

    if (len(stack)>1):
        raise Exception
    print(stack[-1])

except:
    print("Evaluation failed due to errors in the expression.")
