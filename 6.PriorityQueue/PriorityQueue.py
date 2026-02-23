import heapq

def top_three_product(nums):
    unique_nums = list(set(nums))
    if len(unique_nums) < 3:
        return -1

    # Get 3 largest numbers efficiently
    largest_three = heapq.nlargest(3, unique_nums)
    return largest_three[0] * largest_three[1] * largest_three[2]

n = int(input())
nums = list(map(int, input().split()))
print(top_three_product(nums))
