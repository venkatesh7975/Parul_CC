class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEnd = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.isEnd = True
        print(f"Inserted: {word}")

    def search(self, word):
        node = self.root
        for ch in word:
            if ch not in node.children:
                return False
            node = node.children[ch]
        return node.isEnd

    def _remove_helper(self, node, word, depth):
        if not node:
            return False
        if depth == len(word):
            if not node.isEnd:
                return False
            node.isEnd = False
            return len(node.children) == 0
        ch = word[depth]
        if ch in node.children and self._remove_helper(node.children[ch], word, depth + 1):
            del node.children[ch]
            return not node.isEnd and len(node.children) == 0
        return False

    def remove(self, word):
        if not self.search(word):
            print(f"Not found: {word}")
        else:
            self._remove_helper(self.root, word, 0)
            print(f"Removed: {word}")


trie = Trie()
while True:
    try:
        choice = int(input())
        if choice == 4:
            break
        word = input().strip()
        if choice == 1:
            trie.insert(word)
        elif choice == 2:
            print(("Found: " if trie.search(word) else "Not found: ") + word)
        elif choice == 3:
            trie.remove(word)
    except EOFError:
        break
