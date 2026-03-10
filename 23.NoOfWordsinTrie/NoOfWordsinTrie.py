class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEnd = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
        self.count = 0

    def insert(self, word):
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        if not node.isEnd:
            node.isEnd = True
            self.count += 1

    def totalWords(self):
        return self.count

# Main
n = int(input())
trie = Trie()
for _ in range(n):
    word = input().strip()
    trie.insert(word)
print(trie.totalWords())
