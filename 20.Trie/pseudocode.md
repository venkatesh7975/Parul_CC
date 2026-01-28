# Trie Data Structure - Pseudocode

## Problem Statement
Implement a Trie (prefix tree) for efficient string storage and retrieval.

## Data Structure
```
TrieNode:
  - children: Map of character to TrieNode
  - isEndOfWord: Boolean flag

Trie:
  - root: Root TrieNode
```

## Algorithm

### Initialize Trie
```
FUNCTION initializeTrie():
    root = new TrieNode
    root.children = empty map
    root.isEndOfWord = false
    RETURN Trie instance
END FUNCTION
```

### Insert Word
```
FUNCTION insert(word):
    node = root
    
    FOR each character in word:
        IF node.children does not contain character:
            node.children[character] = new TrieNode
        END IF
        node = node.children[character]
    END FOR
    
    node.isEndOfWord = true
    PRINT "Word inserted:", word
END FUNCTION
```

### Search Word
```
FUNCTION search(word):
    node = root
    
    FOR each character in word:
        IF node.children does not contain character:
            RETURN false
        END IF
        node = node.children[character]
    END FOR
    
    RETURN node.isEndOfWord
END FUNCTION
```

### Search Prefix
```
FUNCTION searchPrefix(prefix):
    node = root
    
    FOR each character in prefix:
        IF node.children does not contain character:
            RETURN false
        END IF
        node = node.children[character]
    END FOR
    
    RETURN true
END FUNCTION
```

### Delete Word
```
FUNCTION delete(word):
    RETURN deleteHelper(word, root, 0)
END FUNCTION
```

### Delete Helper
```
FUNCTION deleteHelper(word, node, index):
    IF index == length(word):
        IF NOT node.isEndOfWord:
            RETURN false  // Word doesn't exist
        END IF
        
        node.isEndOfWord = false
        // Return true if node has no children
        RETURN node.children.size() == 0
    END IF
    
    character = word[index]
    
    IF node.children does not contain character:
        RETURN false  // Word doesn't exist
    END IF
    
    childNode = node.children[character]
    shouldDeleteChild = deleteHelper(word, childNode, index + 1)
    
    IF shouldDeleteChild:
        node.children.remove(character)
        // Return true if current node has no children and is not end of another word
        RETURN node.children.size() == 0 AND NOT node.isEndOfWord
    END IF
    
    RETURN false
END FUNCTION
```

### Find All Words with Prefix
```
FUNCTION findWordsWithPrefix(prefix):
    node = root
    result = empty list
    
    FOR each character in prefix:
        IF node.children does not contain character:
            RETURN result
        END IF
        node = node.children[character]
    END FOR
    
    dfs(node, prefix, result)
    RETURN result
END FUNCTION
```

### DFS to Find All Words
```
FUNCTION dfs(node, word, result):
    IF node.isEndOfWord:
        result.add(word)
    END IF
    
    FOR each character in node.children.keys():
        dfs(node.children[character], word + character, result)
    END FOR
END FUNCTION
```

## Time Complexity
- Insert: O(m) - where m is length of word
- Search: O(m)
- Search prefix: O(m)
- Delete: O(m)
- Find all words: O(N) - where N is total characters in all words

## Space Complexity
O(ALPHABET_SIZE * N) - where N is total characters inserted

## Example
```
Insert: "apple", "app", "apricot", "apply"

Trie Structure:
         root
         |
         a
         |
         p
        / \
       p   r
      /|   |
     l e   i
     |     |
     e     c
    (end)  |
           o
           |
           t
           (end)

Search("app") -> true
Search("appl") -> false
SearchPrefix("ap") -> true
FindWordsWithPrefix("app") -> ["apple", "app", "apply"]
```
