# Write your code here!!

n=int(input())
arr=list(map(int,input().split()))
stack=[]
nge=[-1]*n
for i in range(n-1,-1,-1):
    while stack and stack[-1]<=arr[i]:
        stack.pop()
    if stack:
        nge[i]=stack[-1]
    stack.append(arr[i])

for i in range(n):
    print(f"NGE of {arr[i]} is {nge[i]}")