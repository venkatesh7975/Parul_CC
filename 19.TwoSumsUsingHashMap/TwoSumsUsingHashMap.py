SIZE = 100003

class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

hash_table = [None] * SIZE

def hash_func(key):
    return abs(key) % SIZE

def insert(key, value):
    index = hash_func(key)
    new_node = Node(key, value)
    new_node.next = hash_table[index]
    hash_table[index] = new_node

def search(key):
    index = hash_func(key)
    curr = hash_table[index]
    while curr:
        if curr.key == key:
            return curr.value
        curr = curr.next
    return -1


n = int(input())
arr = list(map(int, input().split()))
target = int(input())

print(f"Finding two indices whose values add up to {target}...")
for i in range(SIZE):
    hash_table[i] = None

found = False
for i in range(n):
    complement = target - arr[i]
    comp_index = search(complement)
    if comp_index != -1:
        print(f"Indices: {comp_index} {i}")
        found = True
        break
    insert(arr[i], i)

if not found:
    print("No solution found")

