class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None


class HashTable:
    def __init__(self):
        self.size = 10
        self.table = [None] * self.size

    def hashFunc(self, key):
        return key % self.size

    def insert(self, key, value):
        index = self.hashFunc(key)
        newNode = Node(key, value)

        newNode.next = self.table[index]   # insert at front
        self.table[index] = newNode

        print(f"Inserted: ({key},{value})")

    def deleteKey(self, key):
        index = self.hashFunc(key)
        curr = self.table[index]
        prev = None

        while curr:
            if curr.key == key:
                if prev:
                    prev.next = curr.next
                else:
                    self.table[index] = curr.next
                print(f"Key {key} deleted successfully.")
                return
            prev = curr
            curr = curr.next

        print(f"Key {key} not found.")

    def search(self, key):
        index = self.hashFunc(key)
        curr = self.table[index]

        while curr:
            if curr.key == key:
                print(f"{key} -> {curr.value}")
                return
            curr = curr.next

        print(f"Key {key} not found.")

    def display(self):
        for i in range(self.size):
            curr = self.table[i]
            if curr:
                print(f"Index {i}:", end=" ")
                while curr:
                    print(f"({curr.key},{curr.value})", end=" ")
                    curr = curr.next
                print()


ht = HashTable()

while True:
    try:
        choice = int(input())
    except:
        break

    if choice == 1:
        key, value = map(int, input().split())
        ht.insert(key, value)

    elif choice == 2:
        key = int(input())
        ht.deleteKey(key)

    elif choice == 3:
        key = int(input())
        ht.search(key)

    elif choice == 4:
        ht.display()

    elif choice == 5:
        print("Exit")
        break
