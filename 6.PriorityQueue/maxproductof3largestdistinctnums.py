n=int(input())
data=list(map(int,input().split()))

def maxproduct(data): 
        #remove the dupliccate
        hash_map={}
        for i in data:
            if i not in hash_map:
                hash_map[i]=i

        unique_values=list(hash_map.keys())
        if len(unique_values)<3:
            print(-1)
            return
        #find 3 max values from unique_values 
        max1=max2=max3=float("-inf")

        for i in unique_values:
            if i>max1:
                max3=max2
                max2=max1 
                max1=i 
            elif i>max2:
                max3=max2
                max2=i 
            elif i>max3:
                max3=i 
       
        print(max1*max2*max3)

maxproduct(data)


