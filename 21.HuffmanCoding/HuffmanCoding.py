import heapq

class Node:
    def __init__(self, ch, freq):
        self.ch = ch
        self.freq = freq
        self.left = None
        self.right = None
        self.smallestChar = ch

    def __lt__(self, other):
        if self.freq == other.freq:
            return self.smallestChar < other.smallestChar
        return self.freq < other.freq


def buildCodes(root, code, mp):
    if root is None:
        return

    if root.left is None and root.right is None:
        mp[root.ch] = code
        return

    buildCodes(root.left, code + "0", mp)
    buildCodes(root.right, code + "1", mp)


n = int(input())

chars = input().split()
freq = list(map(int, input().split()))

pq = []

for i in range(n):
    heapq.heappush(pq, Node(chars[i], freq[i]))

while len(pq) > 1:
    left = heapq.heappop(pq)
    right = heapq.heappop(pq)

    merged = Node('$', left.freq + right.freq)
    merged.left = left
    merged.right = right
    merged.smallestChar = min(left.smallestChar, right.smallestChar)

    heapq.heappush(pq, merged)

codes = {}
buildCodes(pq[0], "", codes)

print("Huffman Codes:")
for c in chars:
    print(f"{c}: {codes[c]}")
