class TrieNode:
    def __init__(self):
        self.children = {}

def count_distinct_substrings(s):
    root = TrieNode()
    count = 0

    for i in range(len(s)):
        node = root
        for ch in s[i:]:
            if ch not in node.children:
                node.children[ch] = TrieNode()
                count += 1
            node = node.children[ch]
    return count

s = input().strip()
print(count_distinct_substrings(s))
